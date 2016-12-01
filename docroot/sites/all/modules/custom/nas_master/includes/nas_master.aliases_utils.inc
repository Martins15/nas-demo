<?php
/**
 * @file
 * Helper functions for "bad" aliases.
 */

/**
 * Helper function; deletes orphan node aliases and logs to watchdog.
 */
function _nas_master_delete_orphan_node_aliases() {
  $orphan_aliases = _nas_master_get_orphan_node_aliases();

  foreach ($orphan_aliases as $alias) {
    path_delete($alias->pid);
    watchdog('alias_duplicates', 'Alias %alias for the absent node %path has been deleted', array(
      '%alias' => $alias->alias,
      '%path' => $alias->source,
    ));
  }
}

/**
 * Helper function; searches for orphan node aliases.
 */
function _nas_master_get_orphan_node_aliases() {
  $query = db_select('url_alias', 'ua');
  $query->fields('ua');
  $query->leftJoin('node', 'n', 'REPLACE(ua.source, :node_prefix, :empty_prefix) = n.nid', array(
    ':node_prefix' => 'node/',
    ':empty_prefix' => '',
    ));
  $query->addExpression('SUBSTRING(source, 1, 5)', 'node_path');
  $query->where('SUBSTRING(source, 1, 5) = :node_prefix', array(':node_prefix' => 'node/'));
  $query->isNull('n.nid');
  $orphan_aliases = $query->execute()->fetchAll();

  return $orphan_aliases;
}

/**
 * Helper function; searches for duplicated node aliases.
 */
function _nas_master_get_duplicated_node_aliases() {
  $query = db_select('url_alias', 'ua');
  $query->fields('ua', array('alias'));
  $query->addExpression('COUNT(*)', 'cnt');
  $query->addExpression('SUBSTRING(source, 1, 5)', 'node_path');
  $query->where('SUBSTRING(source, 1, 5) = :node_prefix', array(':node_prefix' => 'node/'));
  $query->groupBy('ua.alias');
  $query->having('cnt > :cnt', array(':cnt' => 1));
  $duplicated_aliases = $query->execute()->fetchAll();

  return $duplicated_aliases;
}
