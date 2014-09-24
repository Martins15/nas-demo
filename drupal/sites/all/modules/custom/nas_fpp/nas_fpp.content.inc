<?php

/**
 * @file
 * Adds test content.
 */

define('NAS_FPP_IMAGE_HERO', 'hero-img-3.jpg');
define('NAS_FPP_IMAGE_BANNER_1', 'banner-1.jpg');
define('NAS_FPP_IMAGE_BANNER_2', 'banner-2.jpg');
define('NAS_FPP_ED_CARD_1', 'editorial-card-5.jpg');
define('NAS_FPP_ED_CARD_2', 'editorial-card-6.jpg');
define('NAS_FPP_ED_CARD_3', 'editorial-card-7.jpg');

function nas_fpp_add_test_content() {
  $featured_fpp = new stdClass();
  $featured_fpp->reusable = 1;
  $featured_fpp->admin_title = 'Hero bird Audubon\'s Shearwater';
  $featured_fpp->category = 'NAS FPP';
  $featured_fpp->title = 'Hero bird Audubon\'s Shearwater';
  $featured_fpp->bundle = 'nas_hero_bird';
  $featured_fpp->field_related_bird[LANGUAGE_NONE][] = array('target_id' => 5);
  fieldable_panels_panes_save($featured_fpp);

  $featured_fpp = new stdClass();
  $featured_fpp->reusable = 1;
  $featured_fpp->admin_title = 'The Audubon Bird Guide';
  $featured_fpp->category = 'NAS FPP';
  $featured_fpp->title = 'The Audubon Bird Guide';
  $featured_fpp->bundle = 'nas_fpp_bird_guide';
  $featured_fpp->field_related_bird[LANGUAGE_NONE][] = array('target_id' => 2);
  $featured_fpp->field_related_bird[LANGUAGE_NONE][] = array('target_id' => 3);
  $featured_fpp->field_related_bird[LANGUAGE_NONE][] = array('target_id' => 9);
  $featured_fpp->field_related_bird[LANGUAGE_NONE][] = array('target_id' => 1);
  fieldable_panels_panes_save($featured_fpp);

  $featured_fpp = new stdClass();
  $featured_fpp->reusable = 1;
  $featured_fpp->admin_title = 'Join Our Hummingbirds at Home Program';
  $featured_fpp->category = 'NAS FPP';
  $featured_fpp->title = 'Join Our Hummingbirds at Home Program';
  $featured_fpp->bundle = 'nas_editorial_cards';
  $featured_fpp->field_link[LANGUAGE_NONE][] = array('url' => '<front>', 'title' => 'Audubon at Home');
  $featured_fpp->field_links[LANGUAGE_NONE][] = array('url' => '<front>', 'title' => 'Learn how to protect them');
  $featured_fpp->field_summary[LANGUAGE_NONE][] = array(
    'value' => '<p>The “feature” variant of the editorial card is a three-column/full-width version
      intended for use atop list index pages (e.g., News). It includes a wide, landscape-oriented
      feature image, as well as the standard category eyebrow, headline,
      and one sentence story excerpt.</p>',
    'format' => 'full_html',
    'safe_value' => '<p>The “feature” variant of the editorial card is a three-column/full-width
     version intended for use atop list index pages (e.g., News). It includes a wide,
     landscape-oriented feature image, as well as the standard category eyebrow,
     headline, and one sentence story excerpt.</p>',
  );
  $featured_fpp->field_image[LANGUAGE_NONE][] = array('fid' => nas_fpp_get_default_image(NAS_FPP_ED_CARD_1));
  $featured_fpp->field_column_count[LANGUAGE_NONE][] = array('value' => '4');
  fieldable_panels_panes_save($featured_fpp);

  $featured_fpp = new stdClass();
  $featured_fpp->reusable = 1;
  $featured_fpp->admin_title = 'It\'s Never Too Late, or Too Early, to Start Birding';
  $featured_fpp->category = 'NAS FPP';
  $featured_fpp->title = 'It\'s Never Too Late, or Too Early, to Start Birding';
  $featured_fpp->bundle = 'nas_editorial_cards';
  $featured_fpp->field_link[LANGUAGE_NONE][] = array('url' => '<front>', 'title' => 'Get into Birds');
  $featured_fpp->field_links[LANGUAGE_NONE][] = array('url' => '<front>', 'title' => 'Learn some helpful tips');
  $featured_fpp->field_summary[LANGUAGE_NONE][] = array(
    'value' => '<p>The “feature” variant of the editorial card is a three-column/full-width version
      intended for use atop list index pages (e.g., News). It includes a wide, landscape-oriented
      feature image, as well as the standard category eyebrow, headline,
      and one sentence story excerpt.</p>',
    'format' => 'full_html',
    'safe_value' => '<p>The “feature” variant of the editorial card is a three-column/full-width
     version intended for use atop list index pages (e.g., News). It includes a wide,
     landscape-oriented feature image.</p>',
  );
  $featured_fpp->field_image[LANGUAGE_NONE][] = array('fid' => nas_fpp_get_default_image(NAS_FPP_ED_CARD_2));
  $featured_fpp->field_column_count[LANGUAGE_NONE][] = array('value' => '4');
  fieldable_panels_panes_save($featured_fpp);

  $featured_fpp = new stdClass();
  $featured_fpp->reusable = 1;
  $featured_fpp->admin_title = 'John James Audubon\'s Birds of America';
  $featured_fpp->category = 'NAS FPP';
  $featured_fpp->title = 'John James Audubon\'s Birds of America';
  $featured_fpp->bundle = 'nas_editorial_cards';
  $featured_fpp->field_link[LANGUAGE_NONE][] = array('url' => '<front>', 'title' => 'History of Audubon');
  $featured_fpp->field_links[LANGUAGE_NONE][] = array('url' => '<front>', 'title' => 'Explore the classic illustrations');
  $featured_fpp->field_summary[LANGUAGE_NONE][] = array(
    'value' => '<p>The “feature” variant of the editorial card is a three-column/full-width version
      intended for use atop list index pages (e.g., News). It includes a wide, landscape-oriented
      feature image, as well as the standard category eyebrow, headline,
      and one sentence story excerpt.</p>',
    'format' => 'full_html',
    'safe_value' => '<p>The “feature” variant of the editorial card is a three-column/full-width
     version intended for use atop list index pages (e.g., News). It includes a wide,
     landscape-oriented feature image, as well as the standard category eyebrow,
     headline, and one sentence story excerpt.</p>',
  );
  $featured_fpp->field_image[LANGUAGE_NONE][] = array('fid' => nas_fpp_get_default_image(NAS_FPP_ED_CARD_3));
  $featured_fpp->field_column_count[LANGUAGE_NONE][] = array('value' => '4');
  fieldable_panels_panes_save($featured_fpp);

  $featured_fpp = new stdClass();
  $featured_fpp->reusable = 1;
  $featured_fpp->admin_title = 'Snowy Owls';
  $featured_fpp->category = 'NAS FPP';
  $featured_fpp->title = 'Snowy Owls';
  $featured_fpp->bundle = 'nas_featured_content_cards';
  $featured_fpp->field_link[LANGUAGE_NONE][] = array('url' => '<front>', 'title' => 'Live Webcams');
  $featured_fpp->field_links[LANGUAGE_NONE][] = array('url' => '<front>', 'title' => 'Watch Owls');
  $featured_fpp->field_links[LANGUAGE_NONE][] = array('url' => '<front>', 'title' => 'Other Cams');
  $featured_fpp->field_summary[LANGUAGE_NONE][] = array(
    'value' => '<p>In parnership with explore.org, you can watch owls, puffins,
     razorbills, terns, and more find mates, build nests, and socialize.</p>',
    'format' => 'full_html',
    'safe_value' => '<p>In parnership with explore.org, you can watch owls, puffins,
     razorbills, terns, and more find mates, build nests, and socialize.</p>',
  );
  $featured_fpp->field_image[LANGUAGE_NONE][] = array('fid' => nas_fpp_get_default_image(NAS_FPP_IMAGE_BANNER_1));
  $featured_fpp->field_column_count[LANGUAGE_NONE][] = array('value' => '4');
  $featured_fpp->field_color_mode[LANGUAGE_NONE][] = array('value' => 'dark');
  fieldable_panels_panes_save($featured_fpp);

  $featured_fpp = new stdClass();
  $featured_fpp->reusable = 1;
  $featured_fpp->admin_title = 'Mississippi Flyway';
  $featured_fpp->category = 'NAS FPP';
  $featured_fpp->title = 'Mississippi Flyway';
  $featured_fpp->bundle = 'nas_featured_content_cards';
  $featured_fpp->field_link[LANGUAGE_NONE][] = array('url' => '<front>', 'title' => 'The Flyways');
  $featured_fpp->field_links[LANGUAGE_NONE][] = array('url' => '<front>', 'title' => 'Explore the Flyways');
  $featured_fpp->field_summary[LANGUAGE_NONE][] = array(
    'value' => '<p>Nearly half of North America\'s bird species spend at least part
    of their lives in the Mississippi Flyway.</p>',
    'format' => 'full_html',
    'safe_value' => '<p>Nearly half of North America\'s bird species spend at least
     part of their lives in the Mississippi Flyway.</p>',
  );
  $featured_fpp->field_image[LANGUAGE_NONE][] = array('fid' => nas_fpp_get_default_image(NAS_FPP_IMAGE_BANNER_2));
  $featured_fpp->field_column_count[LANGUAGE_NONE][] = array('value' => '4');
  $featured_fpp->field_color_mode[LANGUAGE_NONE][] = array('value' => 'light');
  fieldable_panels_panes_save($featured_fpp);
  drupal_set_message(t('Test FPP content has been added.'));
}

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
