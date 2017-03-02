<?php

/**
 * @file
 * Contains authorization classes.
 */

/**
 * Class AdbnSSOAuthorization
 */
class AdbnSSOAuthorization extends Entity {

  /**
   * Make the default URI link to the administration edit page.
   *
   * @return array
   */
  public function defaultUri() {
    return array('path' => ADBN_SSO_AUTH_ENTRIES_ADMIN_PATH . '/manage/' . $this->identifier());
  }

  /**
   * Make sure the label exists.
   *
   * @return array|bool|null|string
   */
  public function defaultLabel() {
    if (isset($this->is_new) && $this->is_new == TRUE) {
      $label = t('New authorization entry');
    }
    else {
      $label = $this->getTranslation($this->entityInfo['entity keys']['label']);
    }
    return $label;
  }
}

/**
 * Class AdbnSSOAuthorizationController
 */
class AdbnSSOAuthorizationController extends EntityAPIController {
  public function create(array $values = array()) {
    // Provide default created and changed values.
    $values += array(
      'created' => REQUEST_TIME,
      'changed' => REQUEST_TIME,
    );
    return parent::create($values);
  }
}

/**
 * Class AdbnSSOAuthorizationType
 */
class AdbnSSOAuthorizationType extends Entity {}

/**
 * Class AdbnSSOAuthorizationTypeController
 */
class AdbnSSOAuthorizationTypeController extends EntityAPIControllerExportable {}

/**
 * Class AdbnSSOAuthorizationEntityBundleableUIController
 */
class AdbnSSOAuthorizationEntityBundleableUIController extends EntityBundleableUIController {
  /**
   * Implements hook_menu().
   *
   * Add changes to the default menu provided by the plugin.
   *
   * @return array
   */
  public function hook_menu() {
    $items = parent::hook_menu();

    $defaults = array(
      'file' => $this->entityInfo['admin ui']['file'],
      'file path' =>  isset($this->entityInfo['admin ui']['file path']) ? $this->entityInfo['admin ui']['file path'] : drupal_get_path('module', $this->entityInfo['module']),
    );

    // Restore the default list menu item, that gets removed by
    // EntityContentUIController.
    $items[$this->path] = array(
      'title' => $this->entityInfo['plural label'],
      'page callback' => 'drupal_get_form',
      'page arguments' => array($this->entityType . '_overview_form', $this->entityType),
      'description' => 'Manage ' . $this->entityInfo['plural label'] . '.',
      'access callback' => 'entity_access',
      'access arguments' => array('view', $this->entityType),
    ) + $defaults;

    // Change some titles.
    $items[$this->path . '/add']['title'] = 'Add authorization email';
    unset($items[$this->path . '/add']['title callback']);

    unset($items[$this->path . '/add']);

    $items[$this->path . '/add'] = array(
      'title' => 'Add email entry',
      'page callback' => 'entity_ui_get_bundle_add_form',
      'page arguments' => array($this->entityType, 'main'),
      'access callback' => 'entity_access',
      'access arguments' => array('create', $this->entityType),
      'type' => MENU_LOCAL_ACTION,
    ) + $defaults;

    // Add email list import menu item.
    $items[$this->path . '/import'] = array(
      'title' => 'Import email list',
      'page callback' => 'drupal_get_form',
      'page arguments' => array('adbn_sso_import_emails_to_authorize_form'),
      'access callback' => 'entity_access',
      'access arguments' => array('create', $this->entityType),
      'type' => MENU_LOCAL_ACTION,
    ) + $defaults;

    // Add file import menu item.
    $items[$this->path . '/import-file'] = array(
      'title' => 'Import file with emails',
      'page callback' => 'drupal_get_form',
      'page arguments' => array('adbn_sso_import_emails_file_to_authorize_form'),
      'access callback' => 'entity_access',
      'access arguments' => array('create', $this->entityType),
      'type' => MENU_LOCAL_ACTION,
    ) + $defaults;

    return $items;
  }

  /**
   * Generates the table headers for the overview table.
   */
  protected function overviewTableHeaders($conditions, $rows, $additional_header = array()) {
    $header = $additional_header;
    array_unshift($header, t('Authorized Emails'));
    if (!empty($this->entityInfo['exportable'])) {
      $header[] = t('Status');
    }
    // Add operations with the right colspan.
    $header[] = array('data' => t('Operations'), 'colspan' => $this->operationCount());
    return $header;
  }

  /**
   * Generates the render array for a overview table for arbitrary entities
   * matching the given conditions.
   *
   * @param $conditions
   *   An array of conditions as needed by entity_load().

   * @return Array
   *   A renderable array.
   */
  public function overviewTable($conditions = array()) {

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', $this->entityType);

    // Add all conditions to query.
    foreach ($conditions as $key => $value) {
      $query->propertyCondition($key, $value);
    }

    if ($this->overviewPagerLimit) {
      $query->pager($this->overviewPagerLimit);
    }

    // Add sorting by email.
    $query->propertyOrderBy('email');
    //$query->entityOrderBy('email');

    $results = $query->execute();

    $ids = isset($results[$this->entityType]) ? array_keys($results[$this->entityType]) : array();
    $entities = $ids ? entity_load($this->entityType, $ids) : array();

    $rows = array();
    foreach ($entities as $entity) {
      $rows[] = $this->overviewTableRow($conditions, entity_id($this->entityType, $entity), $entity);
    }

    $render = array(
      '#theme' => 'table',
      '#header' => $this->overviewTableHeaders($conditions, $rows),
      '#rows' => $rows,
      '#empty' => t('None.'),
    );
    return $render;
  }

  /**
   * Operation form submit callback.
   */
  public function operationFormSubmit($form, &$form_state) {
    parent::operationFormSubmit($form, $form_state);
    // Redirect to manage entities path, instead of front page.
    $form_state['redirect'] = $this->path;
  }
}

/**
 * EntityTest Views Controller class.
 */
class AdbnSSOAuthorizationViewsController extends EntityDefaultViewsController {
  /**
   * Edit or add extra fields to views_data().
   */
  public function views_data() {
    $data = parent::views_data();

    // Make the created and changed fields use the date handler.
    if (isset($data[ADBN_SSO_AUTH_ENTITY_VIEWS_TABLE]['created'])) {
      $data[ADBN_SSO_AUTH_ENTITY_VIEWS_TABLE]['created']['field']['handler'] = 'views_handler_field_date';
    }

    if (isset($data[ADBN_SSO_AUTH_ENTITY_VIEWS_TABLE]['changed'])) {
      $data[ADBN_SSO_AUTH_ENTITY_VIEWS_TABLE]['changed']['field']['handler'] = 'views_handler_field_date';
    }

    return $data;
  }
}