<?php

/**
 * @file
 * Class FeedsECKprocessor.
 */

/**
 * Class to process ECK entities on Feeds import.
 */
class FeedsECKprocessor extends FeedsProcessor {
  /**
   * Define entity type.
   */
  public function entityType() {
    return $this->config['entity_type'];
  }

  /**
   * Implements parent::entityInfo().
   */
  protected function entityInfo() {
    $info = parent::entityInfo();
    $entities = eck_entity_info();
    $info['label plural'] = isset($entities[$this->entityType()]['label']) ?
      $entities[$this->entityType()]['label'] : NULL;
    return $info;
  }

  /**
   * Creates a new ECK entity in memory and returns it.
   */
  protected function newEntity(FeedsSource $source) {
    $properties = eck_entity_property_info();
    $properties = $properties[$this->entityType()]['properties'];

    $entity = new stdClass();
    $entity->type = $this->bundle();
    if (!empty($properties['created'])) {
      $entity->created = REQUEST_TIME;
    }
    if (!empty($properties['changed'])) {
      $entity->changed = REQUEST_TIME;
    }
    if (!empty($properties['language'])) {
      $entity->language = LANGUAGE_NONE;
    }
    if (!empty($properties['uid'])) {
      $entity->uid = $this->config['author'];
    }
    return $entity;
  }

  /**
   * Implements parent::entitySave().
   */
  public function entitySave($entity) {
    entity_save($this->entityType(), $entity);
  }

  /**
   * Implements parent::entityDeleteMultiple().
   */
  protected function entityDeleteMultiple($ids) {
    entity_delete_multiple($this->entityType(), $ids);
  }

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    return array(
      'entity_type' => NULL,
      'bundle' => NULL,
      'expire' => FEEDS_EXPIRE_NEVER,
      'author' => 0,
      'authorize' => TRUE,
    ) + parent::configDefaults();
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $entities = eck_entity_info();
    // If there is no created ECK, print message.
    if (empty($entities)) {
      $form = parent::configForm($form_state);
      $form['message'] = array(
        '#type' => 'markup',
        '#markup' => t('First, <a href="@eck-create-link">create</a> an entity type using ECK module.',
          array('@eck-create-link' => '/admin/structure/entity-type/add?destination=' . current_path())),
        '#weight' => -100,
      );
    }
    else {
      $entity_type = isset($form_state['values']['entity_type']) ? $form_state['values']['entity_type'] : $this->config['entity_type'];
      // Get first entity type if value is not initialised.
      if (empty($entity_type)) {
        $types = array_keys($entities);
        $entity_type = $types[0];
      }

      $properties = eck_entity_property_info();
      $properties = $properties[$entity_type]['properties'];
      $entity_label = $entities[$entity_type]['label'];

      $options = array();
      foreach ($entities as $id => $entity) {
        $options[$id] = $entity['label'];
      }
      // AJAX entity type selection.
      $form['entity_type'] = array(
        '#type' => 'select',
        '#title' => t('Select entity type'),
        '#options' => $options,
        '#default_value' => $entity_type,
        '#ajax' => array(
          'callback' => 'feeds_eck_processor_ajax_callback',
          'wrapper' => 'form-ajaxed-controls',
          'method' => 'replace',
          'effect' => 'fade',
        ),
      );
      // AJAX wrapper for inputs.
      $form['container'] = array(
        '#type' => 'container',
        '#attributes' => array(
          'id' => 'form-ajaxed-controls',
        ),
      );
      $form['container'] = array_merge($form['container'], parent::configForm($form_state));
      $settings = array();
      // Update $form_state values for ajax reload form elements work properly.
      foreach (element_children($form['container']) as $key) {
        $settings[$key] = isset($form_state['values'][$key])
          ? $form_state['values'][$key]
          : $this->config[$key];
      }

      $options = array();
      foreach ($entities[$entity_type]['bundles'] as $id => $bndl) {
        $options[$id] = $bndl['label'];
      }
      $form['container']['bundle']['#options'] = $options;
      $form['container']['bundle']['#default_value'] = in_array($settings['bundle'], array_keys($options)) ? $settings['bundle'] : NULL;


      if (!empty($properties['uid'])) {
        $form['container']['authorize'] = array(
          '#type' => 'checkbox',
          '#title' => t('Authorize'),
          '#description' => t('Check that the author has permission to create the entity.'),
          '#default_value' => $settings['authorize'],
        );
      }

      if (!empty($properties['created'])) {
        $period = drupal_map_assoc(array(
          FEEDS_EXPIRE_NEVER,
          3600,
          10800,
          21600,
          43200,
          86400,
          259200,
          604800,
          2592000,
          2592000 * 3,
          2592000 * 6,
          31536000,
        ), 'feeds_format_expire');
        $form['container']['expire'] = array(
          '#type' => 'select',
          '#title' => t('Expire entities'),
          '#options' => $period,
          '#description' => t("Select after how much time entities should be deleted. The entities's published date will be used for determining the entities's age, see Mapping settings."),
          '#default_value' => $settings['expire'],
        );
      }
      if (!empty($properties['uid'])) {
        $form['container']['author'] = array(
          '#type' => 'textfield',
          '#title' => t('Author'),
          '#description' => t('Select the author of the entities to be created - leave empty to assign "anonymous".'),
          '#autocomplete_path' => 'user/autocomplete',
          '#default_value' => empty($settings['author']) ? '' : $settings['author'],
        );
      }
      // Override default update_existing form element
      // to dynamically change entity label.
      $tokens = array('@entities' => $entity_label);
      $form['container']['update_existing'] = array(
        '#type' => 'radios',
        '#title' => t('Update existing @entities', $tokens),
        '#description' => t('Existing @entities will be determined using mappings that are a "unique target".', $tokens),
        '#options' => array(
          FEEDS_SKIP_EXISTING => t('Do not update existing @entities', $tokens),
          FEEDS_REPLACE_EXISTING => t('Replace existing @entities', $tokens),
          FEEDS_UPDATE_EXISTING => t('Update existing @entities', $tokens),
        ),
        '#default_value' => $settings['update_existing'],
      );
      if (isset($form['container']['update_non_existent'])) {
        $form['container']['update_non_existent'] = array(
          '#type' => 'radios',
          '#title' => t('Action to take when previously imported @entities are missing in the feed', $tokens),
          '#description' => t('Select how @entities previously imported and now missing in the feed should be updated.', $tokens),
          '#options' => array(
            FEEDS_SKIP_NON_EXISTENT => t('Skip non-existent @entities', $tokens),
            FEEDS_DELETE_NON_EXISTENT => t('Delete non-existent @entities', $tokens),
          ),
          '#default_value' => $settings['update_non_existent'],
        );
      }
    }

    return $form;
  }

  /**
   * Override parent::setTargetElement().
   */
  public function setTargetElement(FeedsSource $source, $target_entity, $target_element, $value) {
    switch ($target_element) {
      case 'created':
        $target_entity->created = feeds_to_unixtime($value, REQUEST_TIME);
        break;

      case 'changed':
        $target_entity->changed = feeds_to_unixtime($value, REQUEST_TIME);
        break;

      default:
        parent::setTargetElement($source, $target_entity, $target_element, $value);
        break;
    }
  }

  /**
   * Override parent::getMappingTargets().
   */
  public function getMappingTargets() {
    $entity_type = $this->entityType();
    $bundle = $this->bundle();

    $properties = eck_entity_property_info();
    $properties = $properties[$entity_type]['properties'];
    unset($properties['type']);

    $targets = parent::getMappingTargets();

    foreach ($properties as $id => $property) {
      $targets[$id] = array(
        'name' => $property['label'],
        'description' => $property['description'],
      );
    }

    if (!empty($targets['id'])) {
      $targets['id']['optional_unique'] = TRUE;
    }
    if (!empty($targets['title'])) {
      $targets['title']['optional_unique'] = TRUE;
    }

    // Let other modules expose mapping targets.
    self::loadMappers();
    drupal_alter('feeds_processor_targets', $targets, $entity_type, $bundle);

    return $targets;
  }

  /**
   * Override parent::existingEntityId().
   */
  protected function existingEntityId(FeedsSource $source, FeedsParserResult $result) {
    if ($id = parent::existingEntityId($source, $result)) {
      return $id;
    }

    // Try to find entity id by id or title in entity table.
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', $this->entityType())
      ->entityCondition('bundle', $this->bundle());
    $unique_condition = FALSE;
    foreach ($this->uniqueTargets($source, $result) as $target => $value) {
      switch ($target) {
        case 'id':
          $query->entityCondition('entity_id', $value);
          $unique_condition = TRUE;
          break;

        case 'title':
          $query->propertyCondition('title', $value);
          $unique_condition = TRUE;
          break;
      }
    }

    if ($unique_condition) {
      $result = $query->execute();
      // Return with the first id found.
      if (!empty($result[$this->entityType()])) {
        $id = key($result[$this->entityType()]);
        return $id;
      }
    }

    return 0;
  }

}

/**
 * AJAX callback to dynamically update plugin settings form elements.
 */
function feeds_eck_processor_ajax_callback($form, $form_state) {
  return $form['container'];
}
