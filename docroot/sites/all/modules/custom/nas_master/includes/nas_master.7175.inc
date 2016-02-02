<?php
/**
 * @file
 * Helper functions for hook_update_7175.
 */

/**
 * Returns list of groups of duplicated contacts.
 *
 * @return array
 *   Array of objects representing groups of contact. Each element is object:
 *   - title - title of duplicated node.
 *   - nids - array of nodes' nid.
 *   - cnt - group's size.
 */
function _nas_master_get_duplicated_contacts() {
  $query = db_select('node', 'n');
  $query->leftJoin('panelizer_entity', 'pe', 'pe.revision_id = n.vid and pe.entity_type = :entity_type', array(':entity_type' => 'node'));
  $or = db_or()
    ->condition('pe.name', 'node:contact:default')
    ->isNull('pe.name');
  $query
    ->condition('n.type', 'contact')
    ->condition($or);
  $query->addField('n', 'title');
  $query->addExpression('COUNT(*)', 'cnt');
  $query->addExpression('GROUP_CONCAT(n.nid)', 'nids');
  $query->groupBy('n.title');
  $query->having('cnt > :count', array(':count' => 1));

  $duplicated_contacts = $query->execute()->fetchAll();
  foreach ($duplicated_contacts as &$dc) {
    $dc->nids = explode(',', $dc->nids);
  }

  // Process comma separated contacts (like 'OPAR, Alisa').
  $comma_separated_contacts = db_query("SELECT title, nid FROM {node} WHERE title LIKE '%,_%' AND type='contact'")->fetchAllKeyed(1, 0);

  foreach ($comma_separated_contacts as $nid => $title) {
    $p = explode(', ', $title);
    $p  = array_reverse($p);
    $name = implode(' ', $p);

    // Look for non-comma-separated contact.
    $contact = db_query("SELECT title, nid FROM {node} WHERE title=:like AND type=:type", array(
      ':like' => $name,
      ':type' => 'contact',
    ))->fetch();

    // If non-comma-separated contact exists add comma-separated contact to
    // group.
    if ($contact) {
      // Scan thru already found contacts and add to group.
      $found = FALSE;
      foreach ($duplicated_contacts as &$dc) {
        if ($dc->title == $contact->title) {
          $dc->nids[] = $nid;
          $dc->cnt++;
          $found = TRUE;
          break;
        }
      }
      // If such duplicated contact was not found before, then create group.
      if (!$found) {
        $duplicated_contacts[] = (object) array(
          'title' => $name,
          'cnt' => 2,
          'nids' => array($contact->nid, $nid),
        );
      }
    }
  }

  return $duplicated_contacts;
}

/**
 * Return back references to nodes with particular nids.
 *
 * @param array $nids
 *  Array of nids.
 *
 * @return array
 *  Associative array with reference stats:
 *    -
 */
function _nas_master_contact_group_stats($nids) {
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_author', 'fa', 'fa.field_author_target_id = n.nid');
  $query->leftJoin('field_data_field_pressrelease_contact', 'fprc', 'fprc.field_pressrelease_contact_target_id = n.nid');
  $query->condition('n.nid', $nids, 'IN');
  $query->addField('n', 'nid');
  $query->addExpression('GROUP_CONCAT(DISTINCT fa.entity_id)', 'nids1');
  $query->addExpression('GROUP_CONCAT(DISTINCT fprc.entity_id)', 'nids2');
  $query->groupBy('n.nid');
  $query->orderBy('n.nid');
  $group_stats = $query->execute()->fetchAll();

  $stats = array();
  foreach ($group_stats as $nodestat) {
    $nodestat->nids1 = array_filter(explode(',', $nodestat->nids1));
    $nodestat->nids2 = array_filter(explode(',', $nodestat->nids2));
    $nodestat->references = array_merge($nodestat->nids1, $nodestat->nids2);
    $nodestat->references = array_unique($nodestat->references);
    $nodestat->count = count($nodestat->references);
    unset($nodestat->nids1);
    unset($nodestat->nids2);
    $stats[$nodestat->nid] = $nodestat;
  }

  return $stats;
}

/**
 * Determinate primary node of group and update it setting empty fields value
 * if they were set in other nodes.
 *
 * Primary node is the most referenced node. If tied then most filled node is
 * used.
 *
 * @param $nids
 */
function _nas_master_get_primary_node_of_group($stats) {
  $nids = array_keys($stats);
  $fields = array(
    'field_contact_title',
    'field_image',
    'field_contact_twitter',
    'field_contact_bio',
    'field_contact_office',
    'field_contact_address',
    'field_contact_phone',
    'field_contact_email',
    'field_related_bird',
    'field_internal_tagging',
  );
  $nodestats = array();
  $nodes = node_load_multiple($nids);
  foreach ($nodes as $node) {
    $stats[$node->nid]->fieldsset = 0;
    $nodestats[$node->nid] = 0;
    foreach ($fields as $fieldname) {
      if (field_get_items('node', $node, $fieldname)) {
        $stats[$node->nid]->fieldsset++;
        $nodestats[$node->nid]++;
      }
    }
  }

  // @codingStandardsIgnoreStart
  uasort($stats, function ($a, $b) {
    if ($b->count - $a->count != 0) {
      return $b->count - $a->count;
    }
    return $b->fieldsset - $a->fieldsset;
  });
  // @codingStandardsIgnoreEnd

  $primary = reset($stats);
  $primary_node = _i18n_node_load($primary->nid);

  // Prevent empty nodes to be scanned for field values.
  $nodestats = array_filter($nodestats);

  // Do not scan primary node.
  unset($nodestats[$primary->nid]);
  if (!empty($nodestats)) {
    $updated = FALSE;
    foreach ($fields as $fieldname) {
      if (!field_get_items('node', $primary_node, $fieldname)) {
        foreach ($nodestats as $nid => $value) {
          $node = _i18n_node_load($nid);
          if (!$items = field_get_items('node', $node, $fieldname)) {
            continue;
          }
          $primary_node->{$fieldname}[LANGUAGE_NONE] = $items;
          $updated = TRUE;
          // Since field value set go to next primary node's empty field.
          break;
        }
      }
    }
    if ($updated) {
      $primary_node->revision = TRUE;
      $primary_node->log = t('Update author fields with data from duplicated nodes');
      // Prevent menu rebuild.
      variable_set('menu_rebuild_needed', FALSE);
      lock_acquire('menu_rebuild');
      node_save($primary_node);
      lock_release('menu_rebuild');
    }
  }

  return $primary_node;
}

/**
 * Update referencing articles to reference on primary node.
 *
 * @param array $references
 *   nids of referencing articles.
 * @param object $primary_node
 *   Node to be referenced by articles.
 * @param int $secondary_nid
 *   target nid of the reference to be replaced.
 */
function _nas_master_update_references_to_contact_nodes($references, $primary_node, $secondary_nid) {
  $chunk = 10;
  $processed = 0;
  while ($part = array_slice($references, $processed, $chunk)) {
    $nodes = node_load_multiple($part);
    foreach ($nodes as $node) {
      $updated = FALSE;

      if ($items = field_get_items('node', $node, 'field_author')) {
        $item = reset($items);
        if ($item['target_id'] == $secondary_nid) {
          unset($node->field_author[LANGUAGE_NONE]);
          $node->field_author[LANGUAGE_NONE][0]['target_id'] = $primary_node->nid;
          $node->log = t('Update author reference');
          $updated = TRUE;
        }
      }
      if ($items = field_get_items('node', $node, 'field_pressrelease_contact')) {
        $item = reset($items);
        if ($item['target_id'] == $secondary_nid) {
          unset($node->field_pressrelease_contact[LANGUAGE_NONE]);
          $node->field_pressrelease_contact[LANGUAGE_NONE][0]['target_id'] = $primary_node->nid;
          $node->log = t('Update press release contact reference');
          $updated = TRUE;
        }
      }

      if ($updated) {
        $node->revision = TRUE;
        // Prevent menu rebuild.
        variable_set('menu_rebuild_needed', FALSE);
        lock_acquire('menu_rebuild');
        node_save($node);
        lock_release('menu_rebuild');
      }
    }
    $processed += count($part);
  }
}
