<?php

/**
 * @file
 * Enables modules and site configuration for a pp site installation.
 */

define('EXPORT_NODE_LIST_NIDS_URL', 'http://audubon.wearepropeople.md/export/node-list/');
define('LOAD_NODE_JSON_OBJECT_URL', 'http://audubon.wearepropeople.md/export/node/');
define('EXPORT_USERS_LIST_UIDS_URL', 'http://audubon.wearepropeople.md/export/users-list/');
define('LOAD_USER_JSON_OBJECT_URL', 'http://audubon.wearepropeople.md/export/user/');

define('EXPORT_NODE_TYPE_CONTACT_LIST_NIDS_URL', 'http://audubon_roost:pr0pe0ple@audubon_roost.wearepropeople.md/export/node-list/');
define('LOAD_NODE_TYPE_CONTACT_JSON_OBJECT_URL', 'http://audubon_roost:pr0pe0ple@audubon_roost.wearepropeople.md/export/node/');

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function pp_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
}

/**
 * Implements hook_install_tasks().
 */
function pp_install_tasks(&$install_state) {
  $tasks = array();
  $tasks['default_pressrelease_contact'] = array(
    'display_name' => st('Provide default Press Release Contact'),
    'display' => TRUE,
    'type' => 'batch',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    'function' => 'pp_create_default_pressrelease_contact',
  );
  $tasks['content_import'] = array(
    'display_name' => st('Content import'),
    'display' => TRUE,
    'type' => 'batch',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    'function' => 'pp_import_nodes',
  );
  // @todo: to be removed on release.
  $tasks['create_test_flyway'] = array(
    'display_name' => st('Create Flyway CT nodes for testing purposes'),
    'display' => FALSE,
    'type' => 'normal',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    'function' => 'pp_create_test_flyway',
  );
  $tasks['content_after_import'] = array(
    'display_name' => st('Content after import'),
    'display' => FALSE,
    'type' => 'normal',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    'function' => 'pp_content_after_import',
  );
  $tasks['set_editor_pass'] = array(
    'display_name' => st('Set editor password'),
    'display' => FALSE,
    'type' => 'normal',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    'function' => 'pp_set_editor_pass',
  );
  $tasks['create_conservation_hero_image'] = array(
    'display_name' => st('Create conservation hero image'),
    'display' => FALSE,
    'type' => 'normal',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    'function' => 'pp_create_conservation_hero_image',
  );
  $tasks['frontpage_conservation_section_image'] = array(
    'display_name' => st('Create conservation hero image'),
    'display' => FALSE,
    'type' => 'normal',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    'function' => 'pp_create_frontpage_conservation_section_image',
  );

  return $tasks;
}

/**
 * Main function for import nodes.
 */
function pp_import_nodes() {

  // Clear static caches so ctools_export_load_object can load feeds_importer
  // from enabled feature.
  drupal_static_reset();

  $result = drupal_http_request(EXPORT_USERS_LIST_UIDS_URL);
  $user_uids = drupal_json_decode($result->data);

  $content_type = 'bird';
  $result = drupal_http_request(EXPORT_NODE_LIST_NIDS_URL . $content_type);
  $bird_node_nids = drupal_json_decode($result->data);

  $content_type = 'news';
  $result = drupal_http_request(EXPORT_NODE_LIST_NIDS_URL . $content_type);
  $news_node_nids = drupal_json_decode($result->data);

  $content_type = 'magazine_issue';
  $result = drupal_http_request(EXPORT_NODE_LIST_NIDS_URL . $content_type);
  $magazine_issue_node_nids = drupal_json_decode($result->data);

  $content_type = 'magazine_article';
  $result = drupal_http_request(EXPORT_NODE_LIST_NIDS_URL . $content_type);
  $magazine_article_node_nids = drupal_json_decode($result->data);

  $content_type = 'profile';
  $result = drupal_http_request(EXPORT_NODE_TYPE_CONTACT_LIST_NIDS_URL . $content_type);
  $contact_node_nids = drupal_json_decode($result->data);

  $content_type = 'author';
  $result = drupal_http_request(EXPORT_NODE_LIST_NIDS_URL . $content_type);
  $author_node_nids = drupal_json_decode($result->data);

  $content_type = 'media_gallery';
  $result = drupal_http_request(EXPORT_NODE_LIST_NIDS_URL . $content_type);
  $gallery_node_nids = drupal_json_decode($result->data);

  // No need to import whole set of data for local development.
  if (isset($_SERVER['APP_ENV']) && $_SERVER['APP_ENV'] == 'dev') {
    $user_uids = array_slice($user_uids, 0, 20);
    $author_node_nids = array_slice($author_node_nids, 0, 20);
    $bird_node_nids = array_slice($bird_node_nids, 0, 20);
    $news_node_nids = array_slice($news_node_nids, 0, 19);
    $gallery_node_nids = array_slice($gallery_node_nids, 0, 20);
    // To have a news node with embeded images.
    $news_node_nids[] = 158806;
    $news_node_nids[] = 156951;
    // News in unpublished status.
    $news_node_nids[] = 71496;

    $magazine_issue_node_nids = array(
      4918,
      157656,
      152231,
      133216,
      127951,
      // Magazine issue in unpublished status.
      5321,
    );
    $magazine_article_node_nids = array(
      159291,
      159301,
      160796,
      162181,
      161101,
      152241,
      145736,
      121561,
      146961,
      154856,
      189331,
      // Node with inline image that NOT FOUND.
      178166,
      // Node with inline image to test.
      189306,
      // Node with author relationship.
      9101,
    );
  }

  // Both are going to the one content type article.
  $news_node_nids = array_merge($news_node_nids, $magazine_article_node_nids);

  $operations = array();

  $node_callback = 'pp_import_nodes_batch';
  $user_callback = 'pp_import_users_batch';
  foreach (array_chunk($user_uids, 10) as $chunk) {
    $operations[] = array($user_callback, array($chunk, 'users_import'));
  }

  foreach (array_chunk($author_node_nids, 10) as $chunk) {
    $operations[] = array($node_callback, array($chunk, 'authors_import'));
  }

  foreach (array_chunk($bird_node_nids, 10) as $chunk) {
    $operations[] = array($node_callback, array($chunk, 'birds_import'));
  }

  foreach (array_chunk($news_node_nids, 10) as $chunk) {
    $operations[] = array($node_callback, array($chunk, 'news_import'));
  }

  foreach (array_chunk($magazine_issue_node_nids, 10) as $chunk) {
    $operations[] = array(
      $node_callback,
      array($chunk, 'magazine_issues_import'),
    );
  }

  foreach (array_chunk($contact_node_nids, 10) as $chunk) {
    $operations[] = array($node_callback, array($chunk, 'contacts_import'));
  }

  foreach (array_chunk($gallery_node_nids, 10) as $chunk) {
    $operations[] = array($node_callback, array($chunk, 'media_gallery_import'));
  }

  variable_set('pp_import_timer', time());

  $batch = array(
    'operations' => $operations,
    'title' => t('Content import'),
    'error_message' => t('The import process has encountered an error.'),
    'finished' => 'pp_import_finished',
  );

  batch_set($batch);

  return $batch;
}

/**
 * Batch operation for pp_import_nodes().
 */
function pp_import_nodes_batch($nids, $importer_id) {
  switch ($importer_id) {
    case 'contacts_import':
      $json_backend = LOAD_NODE_TYPE_CONTACT_JSON_OBJECT_URL;
      break;

    default:
      $json_backend = LOAD_NODE_JSON_OBJECT_URL;
      break;
  }
  foreach ($nids as $nid) {
    $config = array('NASFeedsHTTPFetcher' => array('source' => $json_backend . $nid));
    $source = feeds_source($importer_id);
    $source->addConfig($config);
    $source->save();
    $source->import();
  }
}

/**
 * Batch operation for users import to nodes.
 */
function pp_import_users_batch($uids, $importer_id) {
  foreach ($uids as $uid) {
    $config = array('NASFeedsHTTPFetcher' => array('source' => LOAD_USER_JSON_OBJECT_URL . $uid));
    $source = feeds_source($importer_id);
    $source->addConfig($config);
    $source->save();
    $source->import();
  }
}

/**
 * Function which executes on Content after import install task.
 */
function pp_content_after_import() {
  if (function_exists('nas_fpp_create_panes')) {
    if ($cache = page_manager_get_page_cache('page-birds_landing')) {
      page_manager_save_page_cache($cache);
    }
    if ($cache = page_manager_get_page_cache('page-frontpage2')) {
      page_manager_save_page_cache($cache);
    }
    if ($cache = page_manager_get_page_cache('page-news')) {
      page_manager_save_page_cache($cache);
    }
    nas_fpp_create_panes();
  }
  if (function_exists('nas_fpp_get_node_nid_by_type')) {
    variable_set('nas_random_bird_node_nid', nas_fpp_get_node_nid_by_type('bird'));
  }
  if (function_exists('nas_update_text_fields_format')) {
    nas_update_text_fields_format();
  }

  module_invoke_all('nas_after_import');
}

/**
 * Save timer function.
 */
function pp_import_save_timer() {
  $start = variable_get('pp_import_timer', time());
  $stop = time();
  // @codingStandardsIgnoreStart
  watchdog('pp_import_time', number_format(($stop - $start) / 60, 2) . 'm');
  // @codingStandardsIgnoreEnd
  variable_del('pp_import_timer');
}

/**
 * Finished function for import nodes.
 */
function pp_import_finished() {
  // Launch save timer function.
  pp_import_save_timer();
  // Check and launch nas_master_modify_references function for after import operations.
  if (function_exists('nas_import_modify_references')) {
    nas_import_modify_references();
  }
  // We have to clear all caches for ability to load all node's fields data.
  drupal_flush_all_caches();
  // Remove all messages.
  unset($_SESSION['messages']['status']);
}

/**
 * Set editor user password.
 */
function pp_set_editor_pass() {
  // Get user.
  $account = user_load_by_name('editor');

  // Set password for user.
  $edit['pass'] = 'propeople';
  user_save($account, $edit);
}

/**
 * Create node of type Flyway for testing purposes.
 */
function pp_create_test_flyway() {
  pp_create_flyway_navigation_menu_fpp();

  // Create node object.
  $node = new StdClass();
  $node->type = 'flyway';
  $node->language = LANGUAGE_NONE;
  node_object_prepare($node);
  $node->title = 'Atlantic Flyway';
  $node->field_flyway_body[LANGUAGE_NONE] = array(
    0 => array(
      'value' => '<p>From the northern Atlantic Coast and through the Caribbean to South America, Audubon is working to support this avian superhighway’s 500-plus bird species and millions of individual birds. Forty percent of the Atlantic Flyway’s bird species are species of conservation need.</p>',
      'format' => 'full_html',
    ),
    1 => array(
      'value' => '<p>With only one-tenth of the U.S. landmass, this flyway is home to one-third of the nation’s people. And dense population carries with it many challenges for birds and habitat: development and sprawl, incompatible agriculture, overfishing, and climate change.</p>',
      'format' => 'full_html',
    ),
  );
  $node->field_secondary_title[LANGUAGE_NONE][0]['value'] = 'On the wing from Labrador to Tierra del Fuego';
  $node->field_subtitle[LANGUAGE_NONE][0]['value'] = 'The Atlantic Flyway encompasses some of the hemisphere’s most productive ecosystems, inclusing forests, beaches, and coastal wetland.';

  $node->field_background_image[LANGUAGE_NONE][0]['fid'] = nas_import_get_default_image('default_flyway_section_background.jpg');

  $node->field_color_mode[LANGUAGE_NONE][0]['value'] = 'light';
  $term1 = taxonomy_get_term_by_name('District of Columbia');
  $term1 = reset($term1);
  $term2 = taxonomy_get_term_by_name('New York');
  $term2 = reset($term2);
  $node->field_flyway_states[LANGUAGE_NONE][0]['tid'] = $term1->tid;
  $node->field_flyway_states[LANGUAGE_NONE][1]['tid'] = $term2->tid;
  node_save($node);

  // Set default display for created flyway.
  $panelizer_entity_name = 'node:flyway:default';
  $panelizer_entity = array(
    'entity_type' => 'node',
    'entity_id' => $node->nid,
    'revision_id' => $node->vid,
    'name' => $panelizer_entity_name,
    'no_blocks' => 0,
    'css_id' => '',
    'css' => '',
    'pipeline' => 'standard',
    'contexts' => array(),
    'relationships' => array(),
    'did' => 0,
    'view_mode' => 'page_manager',
    'css_class' => '',
    'title_element' => 'H2',
    'link_to_entity' => 1,
    'extra' => array(),
  );
  drupal_write_record('panelizer_entity', $panelizer_entity);

  $node = node_load($node->nid, NULL, TRUE);
  $node->panelizer['page_manager']->display_is_modified = TRUE;
  node_save($node);

  if (function_exists('nas_fpp_flyway_create_test_content') || module_load_include('inc', 'nas_fpp', 'nas_fpp.content')) {
    nas_fpp_flyway_create_test_content($node);
  }
  unset($node);
  // Create node object.
  $node = new StdClass();
  $node->type = 'flyway';
  $node->language = LANGUAGE_NONE;
  node_object_prepare($node);
  $node->title = 'Pacific Flyway';
  $node->field_flyway_body[LANGUAGE_NONE] = array(
    0 => array(
      'value' => '<p>From the northern Pacific Coast and through the Caribbean to South America, Audubon is working to support this avian superhighway’s 500-plus bird species and millions of individual birds. Forty percent of the Pacific Flyway’s bird species are species of conservation need.</p>',
      'format' => 'full_html',
    ),
    1 => array(
      'value' => '<p>With only one-tenth of the U.S. landmass, this flyway is home to one-third of the nation’s people. And dense population carries with it many challenges for birds and habitat: development and sprawl, incompatible agriculture, overfishing, and climate change.</p>',
      'format' => 'full_html',
    ),
  );
  $node->field_secondary_title[LANGUAGE_NONE][0]['value'] = 'On the wing from Labrador to Tierra del Fuego';
  $node->field_subtitle[LANGUAGE_NONE][0]['value'] = 'The Pacific Flyway encompasses some of the hemisphere’s most productive ecosystems, inclusing forests, beaches, and coastal wetland.';

  $node->field_background_image[LANGUAGE_NONE][0]['fid'] = nas_import_get_default_image('default_flyway_section_background.jpg');

  $node->field_color_mode[LANGUAGE_NONE][0]['value'] = 'light';
  $term1 = taxonomy_get_term_by_name('California');
  $term1 = reset($term1);
  $term2 = taxonomy_get_term_by_name('Oregon');
  $term2 = reset($term2);
  $node->field_flyway_states[LANGUAGE_NONE][0]['tid'] = $term1->tid;
  $node->field_flyway_states[LANGUAGE_NONE][1]['tid'] = $term2->tid;
  node_save($node);

  // Set default display for created flyway.
  $panelizer_entity_name = 'node:flyway:default';
  $panelizer_entity = array(
    'entity_type' => 'node',
    'entity_id' => $node->nid,
    'revision_id' => $node->vid,
    'name' => $panelizer_entity_name,
    'no_blocks' => 0,
    'css_id' => '',
    'css' => '',
    'pipeline' => 'standard',
    'contexts' => array(),
    'relationships' => array(),
    'did' => 0,
    'view_mode' => 'page_manager',
    'css_class' => '',
    'title_element' => 'H2',
    'link_to_entity' => 1,
    'extra' => array(),
  );
  drupal_write_record('panelizer_entity', $panelizer_entity);

  $node = node_load($node->nid, NULL, TRUE);
  $node->panelizer['page_manager']->display_is_modified = TRUE;
  node_save($node);

  if (function_exists('nas_fpp_flyway_create_test_content') || module_load_include('inc', 'nas_fpp', 'nas_fpp.content')) {
    nas_fpp_flyway_create_test_content($node);
  }
}

/**
 * Puts flyway panelizer defaults in DB. Creates FPP and adds it to panel.
 */
function pp_create_flyway_navigation_menu_fpp() {
  $name = 'node:flyway:default';
  // Move node panelizer to DB if is not there.
  if (!$did = db_query('SELECT did FROM {panelizer_defaults} WHERE name = :name', array(':name' => $name))->fetchField()) {
    $handler = panelizer_entity_plugin_get_handler('node');
    $bundle = 'flyway.page_manager';
    $panelizer = $handler->get_default_panelizer_object($bundle, $name);
    $cache_key = implode(':', array(
      'panelizer',
      'default',
      $handler->entity_type,
      $bundle,
      $name
    ));
    $panelizer->display = panels_edit_cache_get($cache_key)->display;
    ctools_export_crud_save('panelizer_defaults', $panelizer);
    // Get display id for future usage.
    $did = db_query('SELECT did FROM {panelizer_defaults} WHERE name = :name', array(':name' => $name))->fetchField();
  }

  $nav_fpp = new stdClass();
  $nav_fpp->reusable = 1;
  $nav_fpp->admin_title = 'Flyway Navigation Menu';
  $nav_fpp->category = 'NAS FPP';
  $nav_fpp->title = 'Flyway Navigation Menu';
  $nav_fpp->bundle = 'nas_fpp_flyway_nav';
  fieldable_panels_panes_save($nav_fpp);

  // If FPP is just created put it in default panel.
  nas_fpp_create_panels_pane($did, $nav_fpp->bundle, 'header', 0);
  panelizer_panels_cache_clear('default:node:flyway.page_manager:node:flyway:default', NULL);
  // We have to reset static cache, because this defaults will be cloned on node
  // creation and changes have to be there.
  drupal_static_reset('ctools_export_load_object');
}

/**
 * Helper function.
 *
 * Creates default Press Release contact node and initialize variable
 * nas_default_pressrelease_contact used in features to provide default field
 * value and in import process with the same purpose.
 */
function pp_create_default_pressrelease_contact() {
  // Create node object.
  $node = new StdClass();
  $node->type = 'contact';
  $node->language = LANGUAGE_NONE;
  node_object_prepare($node);
  $node->title = 'Audubon Media Relations';
  $node->field_contact_phone[LANGUAGE_NONE][]['value'] = '212-979-3100';
  $node->field_contact_email[LANGUAGE_NONE][]['value'] = 'media@audubon.org';
  $node = node_submit($node);
  node_save($node);

  $value = array(array('target_id' => $node->nid));
  variable_set('nas_default_pressrelease_contact', $value);
}

/**
 * Return Flyway node's nid by node's title.
 *
 * @param string $title
 *   Node title.
 *
 * @return mixed
 *   int if node exists.
 *   FALSE if node doesn't exist.
 */
function pp_get_flyway_node_nid_by_title($title) {
  return db_query("SELECT nid FROM {node} WHERE title = :title AND type = :type", array(
    ':title' => $title,
    ':type' => 'flyway',
  ))->fetchField();
}

/**
 * Create conservation hero image.
 */
function pp_create_conservation_hero_image() {
  $source = DRUPAL_ROOT . '/sites/all/themes/custom/nas/img/hero-img-5.jpg';
  $destination = 'public://hero-img-5.jpg';
  pp_create_image($source, $destination, 'nas_conservation_landing_hero_image_fid');
}

/**
 * Create frontpage conservation section image.
 */
function pp_create_frontpage_conservation_section_image() {
  $source = DRUPAL_ROOT . '/sites/all/themes/custom/nas/img/breakout-section-3.jpg';
  $destination = 'public://breakout-section-3.jpg';
  pp_create_image($source, $destination, 'nas_frontpage_conservation_section_image_fid');
}

/**
 * Create image.
 */
function pp_create_image($source, $destination, $variable_name) {
  file_unmanaged_copy($source, $destination, FILE_EXISTS_REPLACE);
  $files = file_load_multiple(array(), array('uri' => $destination));
  $file = reset($files);

  if ($file) {
    variable_set($variable_name, $file->fid);
    return NULL;
  }

  $file = (object) array(
    'filename' => basename($destination),
    'filepath' => $destination,
    'filemime' => file_get_mimetype($destination),
    'filesize' => filesize($destination),
    'status' => 1,
    'timestamp' => REQUEST_TIME,
    'uri' => $destination,
    'type' => 'image',
  );

  $file = file_save($file);
  variable_set($variable_name, $file->fid);
}
