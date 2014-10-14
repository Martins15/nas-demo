<?php

/**
 * @file
 * Stores defines and helpers functions.
 */

define('NAS_FPP_IMAGE_HERO', 'hero-img-3.jpg');
define('NAS_FPP_IMAGE_BANNER_1', 'banner-1.jpg');
define('NAS_FPP_IMAGE_BANNER_2', 'banner-2.jpg');
define('NAS_FPP_ED_CARD_1', 'editorial-card-5.jpg');
define('NAS_FPP_ED_CARD_2', 'editorial-card-6.jpg');
define('NAS_FPP_ED_CARD_3', 'editorial-card-7.jpg');

/**
 * Load default image by URI, or save from module's folder if not exist.
 */
function nas_fpp_get_default_image($filename) {
  $default_uri = drupal_get_path('module', 'nas_fpp') . '/images/' . $filename;
  $public_uri = 'public://' . $filename;

  $files = file_load_multiple(array(), array('uri' => $public_uri));
  $file = reset($files);

  if ($file) {
    return $file->fid;
  }
  $filepath = file_unmanaged_copy($default_uri, NULL, FILE_EXISTS_REPLACE);
  $file = (object) array(
    'filename' => basename($filepath),
    'filepath' => $filepath,
    'filemime' => file_get_mimetype($filepath),
    'filesize' => filesize($filepath),
    'uid' => 1,
    'status' => FILE_STATUS_PERMANENT,
    'timestamp' => REQUEST_TIME,
    'uri' => $filepath,
    'type' => 'image',
  );
  drupal_write_record('file_managed', $file);
  $files = file_load_multiple(array(), array('uri' => $public_uri));
  $file = reset($files);

  return $file->fid;
}

/**
 * Return random node nid of given content type.
 */
function nas_fpp_get_node_nid_by_type($content_type) {
  $nid = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('n.type', $content_type, '=')
    ->range(0, 1)
    ->orderRandom()
    ->execute()
    ->fetchField();
  return $nid;
}

/**
 * Create FPPs test content.
 */
function nas_fpp_create_panes() {
  $text = '<p>The “feature” variant of the editorial card is a three-column/full-width version
      intended for use atop list index pages (e.g., News). It includes a wide, landscape-oriented
      feature image, as well as the standard category eyebrow, headline,
      and one sentence story excerpt.</p>';
  $did_query = db_query(
    'SELECT did FROM {panels_display} WHERE layout LIKE :layout',
    array(':layout' => 'birds_landing_page')
  )->fetchCol();
  $did = $did_query[0];

  $pane = new stdClass();
  $pane->did = $did;
  $pane->panel = 'hero';
  $pane->type = 'nas_panes_bird_landing_featured';
  $pane->subtype = 'nas_panes_bird_landing_featured';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'bird' => array(
      'entity_id' => db_query('SELECT nid FROM {node} WHERE title = :title', array(':title' => 'Great Shearwater'))->fetchField(),
      'entity_label' => 'Great Shearwater',
      'entity_type' => 'node',
      'entity_bundle' => 'bird',
    ),
    'image' => '7',
    'color' => '0',
    'summary' => 'Curabitur blandit mollis lacus. Aenean commodo ligula eget dolor. Nullam nulla eros, ultricies sit amet, nonummy id, imperdiet feugiat, pede. Pellentesque dapibus hendrerit tortor. Nam pretium turpis et arcu.',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  drupal_write_record('panels_pane', $pane);
  unset($pane);

  $fpp = new stdClass();
  $fpp->reusable = 1;
  $fpp->admin_title = 'The Audubon Bird Guide';
  $fpp->category = 'NAS FPP';
  $fpp->title = 'The Audubon Bird Guide';
  $fpp->bundle = 'nas_fpp_bird_guide';
  $fpp->field_related_bird[LANGUAGE_NONE][] = array('target_id' => nas_fpp_get_node_nid_by_type('bird'));
  $fpp->field_related_bird[LANGUAGE_NONE][] = array('target_id' => nas_fpp_get_node_nid_by_type('bird'));
  $fpp->field_related_bird[LANGUAGE_NONE][] = array('target_id' => nas_fpp_get_node_nid_by_type('bird'));
  $fpp->field_related_bird[LANGUAGE_NONE][] = array('target_id' => nas_fpp_get_node_nid_by_type('bird'));
  fieldable_panels_panes_save($fpp);
  $fpp_query = db_query(
    'SELECT title FROM {fieldable_panels_panes} WHERE title LIKE :title',
    array(':title' => $fpp->title)
  )->fetchCol();
  if (empty($fpp_query)) {
    fieldable_panels_panes_save($fpp);
    nas_fpp_create_panels_pane($did, $fpp->bundle, 'bird_card_set', 0);
  }
  unset($fpp_query);
  unset($fpp);

  $fpp = new stdClass();
  $fpp->reusable = 1;
  $fpp->admin_title = 'Join Our Hummingbirds at Home Program';
  $fpp->category = 'NAS FPP';
  $fpp->title = 'Join Our Hummingbirds at Home Program';
  $fpp->bundle = 'nas_editorial_cards';
  $fpp->field_link[LANGUAGE_NONE][] = array('url' => '<front>', 'title' => 'Audubon at Home');
  $fpp->field_links[LANGUAGE_NONE][] = array('url' => '<front>', 'title' => 'Learn how to protect them');
  $fpp->field_summary[LANGUAGE_NONE][] = array(
    'value' => $text,
    'format' => 'full_html',
    'safe_value' => $text,
  );
  $fpp->field_image[LANGUAGE_NONE][] = array('fid' => nas_fpp_get_default_image(NAS_FPP_ED_CARD_1));
  $fpp->field_column_count[LANGUAGE_NONE][] = array('value' => '4');
  $fpp_query = db_query(
    'SELECT title FROM {fieldable_panels_panes} WHERE title LIKE :title',
    array(':title' => $fpp->title)
  )->fetchCol();
  if (empty($fpp_query)) {
    fieldable_panels_panes_save($fpp);
    nas_fpp_create_panels_pane($did, $fpp->bundle, 'cards', 0);
  }
  unset($fpp_query);
  unset($fpp);

  $fpp = new stdClass();
  $fpp->reusable = 1;
  $fpp->admin_title = 'It\'s Never Too Late, or Too Early, to Start Birding';
  $fpp->category = 'NAS FPP';
  $fpp->title = 'It\'s Never Too Late, or Too Early, to Start Birding';
  $fpp->bundle = 'nas_editorial_cards';
  $fpp->field_link[LANGUAGE_NONE][] = array('url' => '<front>', 'title' => 'Get into Birds');
  $fpp->field_links[LANGUAGE_NONE][] = array('url' => '<front>', 'title' => 'Learn some helpful tips');
  $fpp->field_summary[LANGUAGE_NONE][] = array(
    'value' => $text,
    'format' => 'full_html',
    'safe_value' => $text,
  );
  $fpp->field_image[LANGUAGE_NONE][] = array('fid' => nas_fpp_get_default_image(NAS_FPP_ED_CARD_2));
  $fpp->field_column_count[LANGUAGE_NONE][] = array('value' => '4');
  $fpp_query = db_query(
    'SELECT title FROM {fieldable_panels_panes} WHERE title LIKE :title',
    array(':title' => $fpp->title)
  )->fetchCol();
  if (empty($fpp_query)) {
    fieldable_panels_panes_save($fpp);
    nas_fpp_create_panels_pane($did, $fpp->bundle, 'cards', 1);
  }
  unset($fpp_query);
  unset($fpp);

  $fpp = new stdClass();
  $fpp->reusable = 1;
  $fpp->admin_title = 'John James Audubon\'s Birds of America';
  $fpp->category = 'NAS FPP';
  $fpp->title = 'John James Audubon\'s Birds of America';
  $fpp->bundle = 'nas_editorial_cards';
  $fpp->field_link[LANGUAGE_NONE][] = array('url' => '<front>', 'title' => 'History of Audubon');
  $fpp->field_links[LANGUAGE_NONE][] = array('url' => '<front>', 'title' => 'Explore the classic illustrations');
  $fpp->field_summary[LANGUAGE_NONE][] = array(
    'value' => $text,
    'format' => 'full_html',
    'safe_value' => $text,
  );
  $fpp->field_image[LANGUAGE_NONE][] = array('fid' => nas_fpp_get_default_image(NAS_FPP_ED_CARD_3));
  $fpp->field_column_count[LANGUAGE_NONE][] = array('value' => '4');
  $fpp_query = db_query(
    'SELECT title FROM {fieldable_panels_panes} WHERE title LIKE :title',
    array(':title' => $fpp->title)
  )->fetchCol();
  if (empty($fpp_query)) {
    fieldable_panels_panes_save($fpp);
    nas_fpp_create_panels_pane($did, $fpp->bundle, 'cards', 2);
  }
  unset($fpp_query);
  unset($fpp);

  $fpp = new stdClass();
  $fpp->reusable = 1;
  $fpp->admin_title = 'Snowy Owls';
  $fpp->category = 'NAS FPP';
  $fpp->title = 'Snowy Owls';
  $fpp->bundle = 'nas_featured_content_cards';
  $fpp->field_link[LANGUAGE_NONE][] = array('url' => '<front>', 'title' => 'Live Webcams');
  $fpp->field_links[LANGUAGE_NONE][] = array('url' => '<front>', 'title' => 'Watch Owls');
  $fpp->field_links[LANGUAGE_NONE][] = array('url' => '<front>', 'title' => 'Other Cams');
  $fpp->field_summary[LANGUAGE_NONE][] = array(
    'value' => '<p>In parnership with explore.org, you can watch owls, puffins,
     razorbills, terns, and more find mates, build nests, and socialize.</p>',
    'format' => 'full_html',
    'safe_value' => '<p>In parnership with explore.org, you can watch owls, puffins,
     razorbills, terns, and more find mates, build nests, and socialize.</p>',
  );
  $fpp->field_image[LANGUAGE_NONE][] = array('fid' => nas_fpp_get_default_image(NAS_FPP_IMAGE_BANNER_1));
  $fpp->field_column_count[LANGUAGE_NONE][] = array('value' => '4');
  $fpp->field_color_mode[LANGUAGE_NONE][] = array('value' => 'dark');
  $fpp_query = db_query(
    'SELECT title FROM {fieldable_panels_panes} WHERE title LIKE :title',
    array(':title' => $fpp->title)
  )->fetchCol();
  if (empty($fpp_query)) {
    fieldable_panels_panes_save($fpp);
    nas_fpp_create_panels_pane($did, $fpp->bundle, 'banner_set');
  }
  unset($fpp_query);
  unset($fpp);

  $fpp = new stdClass();
  $fpp->reusable = 1;
  $fpp->admin_title = 'Mississippi Flyway';
  $fpp->category = 'NAS FPP';
  $fpp->title = 'Mississippi Flyway';
  $fpp->bundle = 'nas_featured_content_cards';
  $fpp->field_link[LANGUAGE_NONE][] = array('url' => '<front>', 'title' => 'The Flyways');
  $fpp->field_links[LANGUAGE_NONE][] = array('url' => '<front>', 'title' => 'Explore the Flyways');
  $fpp->field_summary[LANGUAGE_NONE][] = array(
    'value' => '<p>Nearly half of North America\'s bird species spend at least part
    of their lives in the Mississippi Flyway.</p>',
    'format' => 'full_html',
    'safe_value' => '<p>Nearly half of North America\'s bird species spend at least
     part of their lives in the Mississippi Flyway.</p>',
  );
  $fpp->field_image[LANGUAGE_NONE][] = array('fid' => nas_fpp_get_default_image(NAS_FPP_IMAGE_BANNER_2));
  $fpp->field_column_count[LANGUAGE_NONE][] = array('value' => '4');
  $fpp->field_color_mode[LANGUAGE_NONE][] = array('value' => 'light');
  $fpp_query = db_query(
    'SELECT title FROM {fieldable_panels_panes} WHERE title LIKE :title',
    array(':title' => $fpp->title)
  )->fetchCol();
  if (empty($fpp_query)) {
    fieldable_panels_panes_save($fpp);
    nas_fpp_create_panels_pane($did, $fpp->bundle, 'banner_set', 1);
  }
  unset($fpp_query);
  unset($fpp);
}

/**
 * Create FPP panel panes.
 */
function nas_fpp_create_panels_pane($did, $bundle, $region, $position = 0) {
  $fpp_uuid_query = db_query(
    'SELECT uuid FROM {fieldable_panels_panes} WHERE bundle LIKE :bundle',
    array(':bundle' => $bundle)
  )->fetchCol();
  $fpp_uuid = $fpp_uuid_query[$position];
  $panels_pane = array(
    'did' => $did,
    'panel' => $region,
    'type' => 'fieldable_panels_pane',
    'subtype' => 'uuid:' . $fpp_uuid,
    'shown' => 1,
    'access' => array(),
    'configuration' => array(
      'view_mode' => 'full',
    ),
    'cache' => array(),
    'style' => array(
      'settings' => NULL,
    ),
    'css' => array(),
    'extras' => array(),
    'position' => $position,
    'locks' => array(),
  );
  drupal_write_record('panels_pane', $panels_pane);
}
