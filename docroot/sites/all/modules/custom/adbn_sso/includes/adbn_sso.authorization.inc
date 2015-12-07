<?php
/**
 * @file
 * Contains authorization hooks and functions.
 */

define('ADBN_SSO_AUTH_TYPE_ADMIN_PATH', ADBN_SSO_ADMIN_PATH . '/authorization-types');
define('ADBN_SSO_AUTH_ENTRIES_ADMIN_PATH', 'admin/structure/authorization-list');
define('ADBN_SSO_AUTH_ENTITY', 'sso_authorization');
define('ADBN_SSO_AUTH_ENTITY_VIEWS_TABLE', 'adbn_sso_authorization');
define('ADBN_SSO_AUTH_ENTITY_TYPE', 'sso_authorization_type');
define('ADBN_SSO_AUTH_ENTITY_TYPE_MAIN', 'main');

/**
 * Implements hook_entity_info().
 *
 * Define the authorization entity types.
 */
function adbn_sso_entity_info() {

  $return = array(
    ADBN_SSO_AUTH_ENTITY => array(
      'label' => t('SSO Authorization Entry'),
      'plural label' => t('SSO Authorization Entries'),
      'entity class' => 'AdbnSSOAuthorization',
      'controller class' => 'AdbnSSOAuthorizationController',
      'base table' => 'adbn_sso_authorization',
      'fieldable' => TRUE,
      'entity keys' => array(
        'id' => 'aid',
        'bundle' => 'type',
        'label' => 'email',
      ),
      'bundle keys' => array(
        'bundle' => 'type',
      ),
      'bundles' => array(),
      'label callback' => 'entity_class_label',
      'uri callback' => 'entity_class_uri',
      'module' => ADBN_SSO_MODULE_NAME,
      'admin ui' => array(
        'path' => ADBN_SSO_AUTH_ENTRIES_ADMIN_PATH,
        'file' => 'includes/adbn_sso.auth_admin.inc',
        'controller class' => 'AdbnSSOAuthorizationEntityBundleableUIController',
      ),
      'redirect' => FALSE,
      'access callback' => 'adbn_sso_authorization_access',
      'views controller class' => 'AdbnSSOAuthorizationViewsController',
    ),
  );

  // Add bundle info but bypass entity_load() as we cannot use it here.
  $types = db_select('adbn_sso_authorization_type', 'at')
    ->fields('at')
    ->execute()
    ->fetchAllAssoc('type');

  foreach ($types as $type => $info) {
    $path = ADBN_SSO_AUTH_TYPE_ADMIN_PATH . '/manage/%sso_authorization_type';
    $id_count = count(explode('/', $path)) - 1;
    $return[ADBN_SSO_AUTH_ENTITY]['bundles'][$type] = array(
      'label' => $info->label,
      'admin' => array(
        'path' => $path,
        'real path' => ADBN_SSO_AUTH_TYPE_ADMIN_PATH . '/manage/' . $type,
        'bundle argument' => $id_count,
        'access arguments' => array('administer profiles'),
      ),
    );
  }

  // Support entity cache module.
  if (module_exists('entitycache')) {
    $return[ADBN_SSO_AUTH_ENTITY]['field cache'] = FALSE;
    $return[ADBN_SSO_AUTH_ENTITY]['entity cache'] = TRUE;
  }

  $return[ADBN_SSO_AUTH_ENTITY_TYPE] = array(
    'label' => t('SSO Authorization Type'),
    'plural label' => t('SSO Authorization Types'),
    'description' => t('Authorization types.'),
    'entity class' => 'AdbnSSOAuthorizationType',
    'controller class' => 'AdbnSSOAuthorizationTypeController',
    'base table' => 'adbn_sso_authorization_type',
    'fieldable' => FALSE,
    'bundle of' => ADBN_SSO_AUTH_ENTITY,
    'exportable' => TRUE,
    'entity keys' => array(
      'id' => 'id',
      'name' => 'type',
      'label' => 'label',
    ),
    'module' => ADBN_SSO_MODULE_NAME,
    // Enable the entity API admin UI.
    'admin ui' => array(
      'path' => ADBN_SSO_AUTH_TYPE_ADMIN_PATH,
      'file' => 'includes/adbn_sso.auth_admin.inc',
      'controller class' => 'EntityDefaultUIController',
      'menu wildcard' => '%sso_authorization_type',
    ),
    'access callback' => 'adbn_sso_authorization_type_access',
  );
  return $return;
}

/**
 * Implements hook_entity_property_info_alter().
 */
function adbn_sso_entity_property_info_alter(&$info) {
  $properties = &$info[ADBN_SSO_AUTH_ENTITY]['properties'];
  $properties['created'] = array(
    'label' => t('Date created'),
    'type' => 'date',
    'description' => t('The date the authentication entry was created.'),
    'schema field' => 'created',
  );
  $properties['changed'] = array(
    'label' => t('Date changed'),
    'type' => 'date',
    'schema field' => 'changed',
    'description' => t('The date the authentication entry was most recently updated.'),
  );
}

/**
 * Access callback for the entity API.
 */
function adbn_sso_authorization_type_access(/** @noinspection PhpUnusedParameterInspection */
  $op, $profile = NULL, $account = NULL) {
  return user_access('administer users', $account);
}

/**
 * Access callback for the entity API.
 */
function adbn_sso_authorization_access(/** @noinspection PhpUnusedParameterInspection */
  $op, $profile = NULL, $account = NULL) {
  return user_access('administer users', $account);
}

/**
 * Menu argument loader; Load a profile type by string.
 *
 * @param $type
 *   The machine-readable name of a profile type to load.
 * @return
 *   A profile type array or FALSE if $type does not exist.
 */
function sso_authorization_type_load($type) {
  return sso_authorization_get_types($type);
}

/**
 * Gets an array of all authorization types, keyed by the type name.
 *
 * @param $type_name
 *   If set, the type with the given name is returned.
 * @return AdbnSSOAuthorizationType[]
 *   Depending whether $type isset, an array of authorization types or a single one.
 */
function sso_authorization_get_types($type_name = NULL) {
  $types = entity_load_multiple_by_name(ADBN_SSO_AUTH_ENTITY_TYPE, isset($type_name) ? array($type_name) : FALSE);
  return isset($type_name) ? reset($types) : $types;
}

/**
 * Given an email, returns whether the account is authorized to use the site.
 *
 * @param $email
 * @return bool
 */
function adbn_sso_is_email_authorized($email) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', ADBN_SSO_AUTH_ENTITY)
    ->propertyCondition('email', $email);
  $result = $query->execute();
  $is_authorized = !empty($result);
  return $is_authorized;
}

/**
 * Adds email to authorized list.
 *
 * @param $email String The email to be added.
 * @param $skip_messages Bool Flag to skip showing message if already
 *   email is already authorized.
 */
function adbn_sso_add_email_to_authorized_list($email, $skip_messages = FALSE) {
  $is_authorized = adbn_sso_is_email_authorized($email);
  if ($is_authorized) {
    if (!$skip_messages) {
      drupal_set_message(t('Email @email is already authorized to use this site.', array('@email' => $email)));
    }
  }
  else {
    $entity = entity_create(ADBN_SSO_AUTH_ENTITY, array(
      'type' => ADBN_SSO_AUTH_ENTITY_TYPE_MAIN,
      'email' => $email,
    ));
    /* @var $entity AdbnSSOAuthorizationType */
    $entity->save();
    if (empty($entity)) {
      watchdog(ADBN_SSO_WATCHDOG_KEY, "Couldn't add authorization entry for email @mail.", array('@mail' => $email), WATCHDOG_ERROR);
    }
  }
}

/**
 * Given an email, removes the authorization entry for that email.
 */
function adbn_sso_delete_user_authorization($email) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', ADBN_SSO_AUTH_ENTITY)
    ->propertyCondition('email', $email);
  $result = $query->execute();
  if (isset($result[ADBN_SSO_AUTH_ENTITY])) {
    foreach ($result[ADBN_SSO_AUTH_ENTITY] as $entity) {
      entity_delete(ADBN_SSO_AUTH_ENTITY, $entity->aid);
    }
  }
}