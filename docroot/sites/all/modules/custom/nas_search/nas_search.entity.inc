<?php
/**
 * @file
 * Contains Page manager search Entity controller class without content loading.
 */

class PageManagerSearchEntityControllerWithoutContent extends PageManagerSearchEntityController {

  /**
   * Constructor: sets basic variables.
   */
  public function __construct($entityType) {
    parent::__construct($entityType);
  }

  /**
   * Implements DrupalEntityControllerInterface::load().
   */
  public function load($ids = array(), $conditions = array()) {
    $entities = array();

    // Get all IDs if no IDs are provided.
    if (empty($ids)) {
      $ids = array_keys(_nas_search_page_manager_search_get_pages_by_dec(NULL));
    }

    module_load_include('inc', 'page_manager', 'plugins/tasks/page');
    foreach ($ids as $id) {
      $subtask = _nas_search_page_manager_search_get_pages_by_dec($id);

      $entity = new stdClass();
      $entity->pid = $id;
      $entity->title = isset($subtask->menu['title']) ? $subtask->menu['title'] : $subtask->admin_title;
      $entity->content = '';
      $entity->path = $subtask->path;

      $entities[$id] = $entity;
    }

    return $entities;
  }

}
