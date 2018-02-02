<?php
/**
 * @file
 * nas_file_entity.file_default_displays.inc
 */

/**
 * Implements hook_file_default_displays().
 */
function nas_file_entity_file_default_displays() {
  $export = array();

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_featured__file_field_deepzoom_file';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__article_featured__file_field_deepzoom_file'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_featured__file_field_deepzoom_image';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'deepzoom_processor' => 'batch',
    'deepzoom_image_style' => 'large',
  );
  $export['image__article_featured__file_field_deepzoom_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_featured__file_field_fbia_image_formatter';
  $file_display->weight = -43;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__article_featured__file_field_fbia_image_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_featured__file_field_fbia_media_slideshow_formatter';
  $file_display->weight = -40;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'credit' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__article_featured__file_field_fbia_media_slideshow_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_featured__file_field_fbia_video_formatter';
  $file_display->weight = -39;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__article_featured__file_field_fbia_video_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_featured__file_field_image_attributions';
  $file_display->weight = -38;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__article_featured__file_field_image_attributions'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_featured__file_field_soundmanager2_inline_player';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'text' => 'filename',
  );
  $export['image__article_featured__file_field_soundmanager2_inline_player'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_featured__file_field_soundmanager2_page_player';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'text' => 'filename',
  );
  $export['image__article_featured__file_field_soundmanager2_page_player'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_featured__file_field_soundmanager2_ui360';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'inline' => 0,
    'visualization' => 1,
    'waveform' => 1,
    'eq' => 1,
    'amplifier' => 1,
    'diameter' => '256',
    'text' => 'filename',
  );
  $export['image__article_featured__file_field_soundmanager2_ui360'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_featured__netx_audio';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__article_featured__netx_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_featured__netx_document';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__article_featured__netx_document'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_featured__netx_image';
  $file_display->weight = -32;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'article_featured',
    'image_link' => '',
    'attributes' => array(
      'Author' => 0,
      'Caption' => 0,
      'Collection' => 0,
      'Credit' => 0,
      'Date' => 0,
      'Species - Scientific' => 0,
      'Species - Common Name' => 0,
      'Family' => 0,
      'Order' => 0,
      'Gender' => 0,
      'Flyway' => 0,
      'Subject' => 0,
      'Color' => 0,
      'Location' => 0,
      'Medium' => 0,
      'File Family' => 0,
      'Search Terms' => 0,
      'Status' => 0,
    ),
  );
  $export['image__article_featured__netx_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_featured__netx_preview';
  $file_display->weight = -49;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__article_featured__netx_preview'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_featured__netx_video';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__article_featured__netx_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_teaser__file_field_deepzoom_file';
  $file_display->weight = -38;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__article_teaser__file_field_deepzoom_file'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_teaser__file_field_deepzoom_image';
  $file_display->weight = -37;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'deepzoom_processor' => 'batch',
    'deepzoom_image_style' => 'large',
  );
  $export['image__article_teaser__file_field_deepzoom_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_teaser__file_field_fbia_image_formatter';
  $file_display->weight = -40;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__article_teaser__file_field_fbia_image_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_teaser__file_field_fbia_media_slideshow_formatter';
  $file_display->weight = -36;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'credit' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__article_teaser__file_field_fbia_media_slideshow_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_teaser__file_field_fbia_video_formatter';
  $file_display->weight = -35;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__article_teaser__file_field_fbia_video_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_teaser__file_field_image_attributions';
  $file_display->weight = -34;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__article_teaser__file_field_image_attributions'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_teaser__file_field_soundmanager2_inline_player';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'text' => 'filename',
  );
  $export['image__article_teaser__file_field_soundmanager2_inline_player'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_teaser__file_field_soundmanager2_page_player';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'text' => 'filename',
  );
  $export['image__article_teaser__file_field_soundmanager2_page_player'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_teaser__file_field_soundmanager2_ui360';
  $file_display->weight = -43;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'inline' => 0,
    'visualization' => 1,
    'waveform' => 1,
    'eq' => 1,
    'amplifier' => 1,
    'diameter' => '256',
    'text' => 'filename',
  );
  $export['image__article_teaser__file_field_soundmanager2_ui360'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_teaser__netx_audio';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__article_teaser__netx_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_teaser__netx_document';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__article_teaser__netx_document'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_teaser__netx_image';
  $file_display->weight = -33;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'article_teaser',
    'image_link' => '',
    'attributes' => array(
      'Author' => 0,
      'Caption' => 0,
      'Collection' => 0,
      'Credit' => 0,
      'Date' => 0,
      'Species - Scientific' => 0,
      'Species - Common Name' => 0,
      'Family' => 0,
      'Order' => 0,
      'Gender' => 0,
      'Flyway' => 0,
      'Subject' => 0,
      'Color' => 0,
      'Location' => 0,
      'Medium' => 0,
      'File Family' => 0,
      'Search Terms' => 0,
      'Status' => 0,
    ),
  );
  $export['image__article_teaser__netx_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_teaser__netx_preview';
  $file_display->weight = -49;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__article_teaser__netx_preview'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__article_teaser__netx_video';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__article_teaser__netx_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__bird_teaser_illustration__file_field_deepzoom_file';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__bird_teaser_illustration__file_field_deepzoom_file'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__bird_teaser_illustration__file_field_deepzoom_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'deepzoom_processor' => 'batch',
    'deepzoom_image_style' => 'large',
  );
  $export['image__bird_teaser_illustration__file_field_deepzoom_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__bird_teaser_illustration__file_field_fbia_image_formatter';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__bird_teaser_illustration__file_field_fbia_image_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__bird_teaser_illustration__file_field_fbia_media_slideshow_formatter';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'credit' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__bird_teaser_illustration__file_field_fbia_media_slideshow_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__bird_teaser_illustration__file_field_fbia_video_formatter';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__bird_teaser_illustration__file_field_fbia_video_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__bird_teaser_illustration__file_field_image_attributions';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__bird_teaser_illustration__file_field_image_attributions'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__bird_teaser_illustration__file_field_soundmanager2_inline_player';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'text' => 'filename',
  );
  $export['image__bird_teaser_illustration__file_field_soundmanager2_inline_player'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__bird_teaser_illustration__file_field_soundmanager2_page_player';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'text' => 'filename',
  );
  $export['image__bird_teaser_illustration__file_field_soundmanager2_page_player'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__bird_teaser_illustration__file_field_soundmanager2_ui360';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'inline' => 0,
    'visualization' => 1,
    'waveform' => 1,
    'eq' => 1,
    'amplifier' => 1,
    'diameter' => '256',
    'text' => 'filename',
  );
  $export['image__bird_teaser_illustration__file_field_soundmanager2_ui360'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__bird_teaser_illustration__netx_audio';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__bird_teaser_illustration__netx_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__bird_teaser_illustration__netx_document';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__bird_teaser_illustration__netx_document'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__bird_teaser_illustration__netx_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'bird_teaser_illustration',
    'image_link' => '',
    'attributes' => array(
      'Author' => 0,
      'Caption' => 0,
      'Collection' => 0,
      'Credit' => 0,
      'Date' => 0,
      'Species - Scientific' => 0,
      'Species - Common Name' => 0,
      'Family' => 0,
      'Order' => 0,
      'Gender' => 0,
      'Flyway' => 0,
      'Subject' => 0,
      'Color' => 0,
      'Location' => 0,
      'Medium' => 0,
      'File Family' => 0,
      'Search Terms' => 0,
      'Status' => 0,
    ),
  );
  $export['image__bird_teaser_illustration__netx_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__bird_teaser_illustration__netx_preview';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__bird_teaser_illustration__netx_preview'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__bird_teaser_illustration__netx_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__bird_teaser_illustration__netx_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_colorbox';
  $file_display->weight = -32;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'colorbox_node_style' => '',
    'colorbox_node_style_first' => '',
    'colorbox_image_style' => '',
    'colorbox_gallery' => 'post',
    'colorbox_gallery_custom' => '',
    'colorbox_caption' => 'auto',
    'colorbox_caption_custom' => '',
  );
  $export['image__default__file_field_colorbox'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_deepzoom_file';
  $file_display->weight = -37;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__default__file_field_deepzoom_file'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_deepzoom_image';
  $file_display->weight = -36;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'deepzoom_processor' => 'batch',
    'deepzoom_image_style' => 'large',
  );
  $export['image__default__file_field_deepzoom_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_fbia_image_formatter';
  $file_display->weight = -39;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__default__file_field_fbia_image_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_fbia_media_slideshow_formatter';
  $file_display->weight = -35;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'credit' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__default__file_field_fbia_media_slideshow_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_fbia_video_formatter';
  $file_display->weight = -34;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__default__file_field_fbia_video_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_file_download_link';
  $file_display->weight = -38;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['image__default__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_file_table';
  $file_display->weight = -43;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__default__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_file_url_plain';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__default__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_image_attributions';
  $file_display->weight = -33;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__default__file_field_image_attributions'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_media_large_icon';
  $file_display->weight = -40;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__default__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_soundmanager2_inline_player';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'text' => 'filename',
  );
  $export['image__default__file_field_soundmanager2_inline_player'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_soundmanager2_page_player';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'text' => 'filename',
  );
  $export['image__default__file_field_soundmanager2_page_player'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_soundmanager2_ui360';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'inline' => 0,
    'visualization' => 1,
    'waveform' => 1,
    'eq' => 1,
    'amplifier' => 1,
    'diameter' => '256',
    'text' => 'filename',
  );
  $export['image__default__file_field_soundmanager2_ui360'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__netx_audio';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__default__netx_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__netx_document';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__default__netx_document'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__netx_preview';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__default__netx_preview'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__netx_video';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__default__netx_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default_teaser_image__file_field_deepzoom_file';
  $file_display->weight = -38;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__default_teaser_image__file_field_deepzoom_file'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default_teaser_image__file_field_deepzoom_image';
  $file_display->weight = -37;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'deepzoom_processor' => 'batch',
    'deepzoom_image_style' => 'large',
  );
  $export['image__default_teaser_image__file_field_deepzoom_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default_teaser_image__file_field_fbia_image_formatter';
  $file_display->weight = -40;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__default_teaser_image__file_field_fbia_image_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default_teaser_image__file_field_fbia_media_slideshow_formatter';
  $file_display->weight = -36;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'credit' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__default_teaser_image__file_field_fbia_media_slideshow_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default_teaser_image__file_field_fbia_video_formatter';
  $file_display->weight = -35;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__default_teaser_image__file_field_fbia_video_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default_teaser_image__file_field_image_attributions';
  $file_display->weight = -34;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__default_teaser_image__file_field_image_attributions'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default_teaser_image__file_field_soundmanager2_inline_player';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'text' => 'filename',
  );
  $export['image__default_teaser_image__file_field_soundmanager2_inline_player'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default_teaser_image__file_field_soundmanager2_page_player';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'text' => 'filename',
  );
  $export['image__default_teaser_image__file_field_soundmanager2_page_player'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default_teaser_image__file_field_soundmanager2_ui360';
  $file_display->weight = -43;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'inline' => 0,
    'visualization' => 1,
    'waveform' => 1,
    'eq' => 1,
    'amplifier' => 1,
    'diameter' => '256',
    'text' => 'filename',
  );
  $export['image__default_teaser_image__file_field_soundmanager2_ui360'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default_teaser_image__netx_audio';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__default_teaser_image__netx_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default_teaser_image__netx_document';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__default_teaser_image__netx_document'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default_teaser_image__netx_image';
  $file_display->weight = -33;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'default_teaser_image',
    'image_link' => '',
    'attributes' => array(
      'Author' => 0,
      'Caption' => 0,
      'Collection' => 0,
      'Credit' => 0,
      'Date' => 0,
      'Species - Scientific' => 0,
      'Species - Common Name' => 0,
      'Family' => 0,
      'Order' => 0,
      'Gender' => 0,
      'Flyway' => 0,
      'Subject' => 0,
      'Color' => 0,
      'Location' => 0,
      'Medium' => 0,
      'File Family' => 0,
      'Search Terms' => 0,
      'Status' => 0,
    ),
  );
  $export['image__default_teaser_image__netx_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default_teaser_image__netx_preview';
  $file_display->weight = -49;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__default_teaser_image__netx_preview'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default_teaser_image__netx_video';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__default_teaser_image__netx_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero__file_field_deepzoom_file';
  $file_display->weight = -38;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__hero__file_field_deepzoom_file'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero__file_field_deepzoom_image';
  $file_display->weight = -37;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'deepzoom_processor' => 'batch',
    'deepzoom_image_style' => 'large',
  );
  $export['image__hero__file_field_deepzoom_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero__file_field_fbia_image_formatter';
  $file_display->weight = -40;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__hero__file_field_fbia_image_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero__file_field_fbia_media_slideshow_formatter';
  $file_display->weight = -36;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'credit' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__hero__file_field_fbia_media_slideshow_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero__file_field_fbia_video_formatter';
  $file_display->weight = -35;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__hero__file_field_fbia_video_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero__file_field_image_attributions';
  $file_display->weight = -34;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__hero__file_field_image_attributions'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero__file_field_soundmanager2_inline_player';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'text' => 'filename',
  );
  $export['image__hero__file_field_soundmanager2_inline_player'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero__file_field_soundmanager2_page_player';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'text' => 'filename',
  );
  $export['image__hero__file_field_soundmanager2_page_player'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero__file_field_soundmanager2_ui360';
  $file_display->weight = -43;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'inline' => 0,
    'visualization' => 1,
    'waveform' => 1,
    'eq' => 1,
    'amplifier' => 1,
    'diameter' => '256',
    'text' => 'filename',
  );
  $export['image__hero__file_field_soundmanager2_ui360'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero__netx_audio';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__hero__netx_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero__netx_document';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__hero__netx_document'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero__netx_image';
  $file_display->weight = -33;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'hero_image',
    'image_link' => '',
    'attributes' => array(
      'Author' => 0,
      'Caption' => 0,
      'Collection' => 0,
      'Credit' => 0,
      'Date' => 0,
      'Species - Scientific' => 0,
      'Species - Common Name' => 0,
      'Family' => 0,
      'Order' => 0,
      'Gender' => 0,
      'Flyway' => 0,
      'Subject' => 0,
      'Color' => 0,
      'Location' => 0,
      'Medium' => 0,
      'File Family' => 0,
      'Search Terms' => 0,
      'Status' => 0,
    ),
  );
  $export['image__hero__netx_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero__netx_preview';
  $file_display->weight = -49;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__hero__netx_preview'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero__netx_video';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__hero__netx_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero_cover_bird_page__file_field_deepzoom_file';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__hero_cover_bird_page__file_field_deepzoom_file'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero_cover_bird_page__file_field_deepzoom_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'deepzoom_processor' => 'batch',
    'deepzoom_image_style' => 'large',
  );
  $export['image__hero_cover_bird_page__file_field_deepzoom_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero_cover_bird_page__file_field_fbia_image_formatter';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__hero_cover_bird_page__file_field_fbia_image_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero_cover_bird_page__file_field_fbia_media_slideshow_formatter';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'credit' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__hero_cover_bird_page__file_field_fbia_media_slideshow_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero_cover_bird_page__file_field_fbia_video_formatter';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__hero_cover_bird_page__file_field_fbia_video_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero_cover_bird_page__file_field_image_attributions';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__hero_cover_bird_page__file_field_image_attributions'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero_cover_bird_page__file_field_soundmanager2_inline_player';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'text' => 'filename',
  );
  $export['image__hero_cover_bird_page__file_field_soundmanager2_inline_player'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero_cover_bird_page__file_field_soundmanager2_page_player';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'text' => 'filename',
  );
  $export['image__hero_cover_bird_page__file_field_soundmanager2_page_player'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero_cover_bird_page__file_field_soundmanager2_ui360';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'inline' => 0,
    'visualization' => 1,
    'waveform' => 1,
    'eq' => 1,
    'amplifier' => 1,
    'diameter' => '256',
    'text' => 'filename',
  );
  $export['image__hero_cover_bird_page__file_field_soundmanager2_ui360'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero_cover_bird_page__netx_audio';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__hero_cover_bird_page__netx_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero_cover_bird_page__netx_document';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__hero_cover_bird_page__netx_document'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero_cover_bird_page__netx_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'hero_cover_bird_page',
    'image_link' => '',
    'attributes' => array(
      'Author' => 0,
      'Caption' => 0,
      'Collection' => 0,
      'Credit' => 0,
      'Date' => 0,
      'Species - Scientific' => 0,
      'Species - Common Name' => 0,
      'Family' => 0,
      'Order' => 0,
      'Gender' => 0,
      'Flyway' => 0,
      'Subject' => 0,
      'Color' => 0,
      'Location' => 0,
      'Medium' => 0,
      'File Family' => 0,
      'Search Terms' => 0,
      'Status' => 0,
    ),
  );
  $export['image__hero_cover_bird_page__netx_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero_cover_bird_page__netx_preview';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__hero_cover_bird_page__netx_preview'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__hero_cover_bird_page__netx_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__hero_cover_bird_page__netx_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_article_inline_hero__file_field_deepzoom_file';
  $file_display->weight = -37;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__nas_article_inline_hero__file_field_deepzoom_file'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_article_inline_hero__file_field_deepzoom_image';
  $file_display->weight = -36;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'deepzoom_processor' => 'batch',
    'deepzoom_image_style' => 'large',
  );
  $export['image__nas_article_inline_hero__file_field_deepzoom_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_article_inline_hero__file_field_fbia_image_formatter';
  $file_display->weight = -39;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__nas_article_inline_hero__file_field_fbia_image_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_article_inline_hero__file_field_fbia_media_slideshow_formatter';
  $file_display->weight = -35;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'credit' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__nas_article_inline_hero__file_field_fbia_media_slideshow_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_article_inline_hero__file_field_fbia_video_formatter';
  $file_display->weight = -34;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__nas_article_inline_hero__file_field_fbia_video_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_article_inline_hero__file_field_image_attributions';
  $file_display->weight = -33;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__nas_article_inline_hero__file_field_image_attributions'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_article_inline_hero__file_field_soundmanager2_inline_player';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'text' => 'filename',
  );
  $export['image__nas_article_inline_hero__file_field_soundmanager2_inline_player'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_article_inline_hero__file_field_soundmanager2_page_player';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'text' => 'filename',
  );
  $export['image__nas_article_inline_hero__file_field_soundmanager2_page_player'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_article_inline_hero__file_field_soundmanager2_ui360';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'inline' => 0,
    'visualization' => 1,
    'waveform' => 1,
    'eq' => 1,
    'amplifier' => 1,
    'diameter' => '256',
    'text' => 'filename',
  );
  $export['image__nas_article_inline_hero__file_field_soundmanager2_ui360'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_article_inline_hero__netx_audio';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__nas_article_inline_hero__netx_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_article_inline_hero__netx_document';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__nas_article_inline_hero__netx_document'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_article_inline_hero__netx_image';
  $file_display->weight = -49;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'article_hero_inline',
    'image_link' => '',
    'attributes' => array(
      'Author' => 0,
      'Caption' => 0,
      'Collection' => 0,
      'Credit' => 0,
      'Date' => 0,
      'Species - Scientific' => 0,
      'Species - Common Name' => 0,
      'Family' => 0,
      'Order' => 0,
      'Gender' => 0,
      'Flyway' => 0,
      'Subject' => 0,
      'Color' => 0,
      'Location' => 0,
      'Medium' => 0,
      'File Family' => 0,
      'Search Terms' => 0,
      'Status' => 0,
    ),
  );
  $export['image__nas_article_inline_hero__netx_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_article_inline_hero__netx_preview';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => 'article_hero_inline',
  );
  $export['image__nas_article_inline_hero__netx_preview'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_article_inline_hero__netx_video';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__nas_article_inline_hero__netx_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_bird_teaser_illustration__file_field_deepzoom_file';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__nas_bird_teaser_illustration__file_field_deepzoom_file'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_bird_teaser_illustration__file_field_deepzoom_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'deepzoom_processor' => 'batch',
    'deepzoom_image_style' => 'large',
  );
  $export['image__nas_bird_teaser_illustration__file_field_deepzoom_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_bird_teaser_illustration__file_field_fbia_image_formatter';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__nas_bird_teaser_illustration__file_field_fbia_image_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_bird_teaser_illustration__file_field_fbia_media_slideshow_formatter';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'credit' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__nas_bird_teaser_illustration__file_field_fbia_media_slideshow_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_bird_teaser_illustration__file_field_fbia_video_formatter';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__nas_bird_teaser_illustration__file_field_fbia_video_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_bird_teaser_illustration__file_field_image_attributions';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__nas_bird_teaser_illustration__file_field_image_attributions'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_bird_teaser_illustration__file_field_soundmanager2_inline_player';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'text' => 'filename',
  );
  $export['image__nas_bird_teaser_illustration__file_field_soundmanager2_inline_player'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_bird_teaser_illustration__file_field_soundmanager2_page_player';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'text' => 'filename',
  );
  $export['image__nas_bird_teaser_illustration__file_field_soundmanager2_page_player'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_bird_teaser_illustration__file_field_soundmanager2_ui360';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'inline' => 0,
    'visualization' => 1,
    'waveform' => 1,
    'eq' => 1,
    'amplifier' => 1,
    'diameter' => '256',
    'text' => 'filename',
  );
  $export['image__nas_bird_teaser_illustration__file_field_soundmanager2_ui360'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_bird_teaser_illustration__netx_audio';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__nas_bird_teaser_illustration__netx_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_bird_teaser_illustration__netx_document';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__nas_bird_teaser_illustration__netx_document'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_bird_teaser_illustration__netx_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'nas_bird_teaser_illustration',
    'image_link' => '',
    'attributes' => array(
      'Author' => 0,
      'Caption' => 0,
      'Collection' => 0,
      'Credit' => 0,
      'Date' => 0,
      'Species - Scientific' => 0,
      'Species - Common Name' => 0,
      'Family' => 0,
      'Order' => 0,
      'Gender' => 0,
      'Flyway' => 0,
      'Subject' => 0,
      'Color' => 0,
      'Location' => 0,
      'Medium' => 0,
      'File Family' => 0,
      'Search Terms' => 0,
      'Status' => 0,
    ),
  );
  $export['image__nas_bird_teaser_illustration__netx_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_bird_teaser_illustration__netx_preview';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__nas_bird_teaser_illustration__netx_preview'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_bird_teaser_illustration__netx_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__nas_bird_teaser_illustration__netx_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image__file_field_deepzoom_file';
  $file_display->weight = -38;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__nas_wysiwyg_image__file_field_deepzoom_file'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image__file_field_deepzoom_image';
  $file_display->weight = -37;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'deepzoom_processor' => 'batch',
    'deepzoom_image_style' => 'large',
  );
  $export['image__nas_wysiwyg_image__file_field_deepzoom_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image__file_field_fbia_image_formatter';
  $file_display->weight = -40;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__nas_wysiwyg_image__file_field_fbia_image_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image__file_field_fbia_media_slideshow_formatter';
  $file_display->weight = -36;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'credit' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__nas_wysiwyg_image__file_field_fbia_media_slideshow_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image__file_field_fbia_video_formatter';
  $file_display->weight = -35;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__nas_wysiwyg_image__file_field_fbia_video_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image__file_field_image_attributions';
  $file_display->weight = -34;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__nas_wysiwyg_image__file_field_image_attributions'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image__file_field_soundmanager2_inline_player';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'text' => 'filename',
  );
  $export['image__nas_wysiwyg_image__file_field_soundmanager2_inline_player'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image__file_field_soundmanager2_page_player';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'text' => 'filename',
  );
  $export['image__nas_wysiwyg_image__file_field_soundmanager2_page_player'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image__file_field_soundmanager2_ui360';
  $file_display->weight = -43;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'inline' => 0,
    'visualization' => 1,
    'waveform' => 1,
    'eq' => 1,
    'amplifier' => 1,
    'diameter' => '256',
    'text' => 'filename',
  );
  $export['image__nas_wysiwyg_image__file_field_soundmanager2_ui360'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image__netx_audio';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__nas_wysiwyg_image__netx_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image__netx_document';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__nas_wysiwyg_image__netx_document'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image__netx_image';
  $file_display->weight = -33;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => '',
    'image_link' => '',
    'attributes' => array(
      'Author' => 0,
      'Caption' => 0,
      'Collection' => 0,
      'Credit' => 0,
      'Date' => 0,
      'Species - Scientific' => 0,
      'Species - Common Name' => 0,
      'Family' => 0,
      'Order' => 0,
      'Gender' => 0,
      'Flyway' => 0,
      'Subject' => 0,
      'Color' => 0,
      'Location' => 0,
      'Medium' => 0,
      'File Family' => 0,
      'Search Terms' => 0,
      'Status' => 0,
    ),
  );
  $export['image__nas_wysiwyg_image__netx_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image__netx_preview';
  $file_display->weight = -49;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__nas_wysiwyg_image__netx_preview'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image__netx_video';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__nas_wysiwyg_image__netx_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image_without_colorbox__file_field_deepzoom_file';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__nas_wysiwyg_image_without_colorbox__file_field_deepzoom_file'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image_without_colorbox__file_field_deepzoom_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'deepzoom_processor' => 'batch',
    'deepzoom_image_style' => 'large',
  );
  $export['image__nas_wysiwyg_image_without_colorbox__file_field_deepzoom_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image_without_colorbox__file_field_fbia_image_formatter';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__nas_wysiwyg_image_without_colorbox__file_field_fbia_image_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image_without_colorbox__file_field_fbia_media_slideshow_formatter';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'credit' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__nas_wysiwyg_image_without_colorbox__file_field_fbia_media_slideshow_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image_without_colorbox__file_field_fbia_video_formatter';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__nas_wysiwyg_image_without_colorbox__file_field_fbia_video_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image_without_colorbox__file_field_image_attributions';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__nas_wysiwyg_image_without_colorbox__file_field_image_attributions'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image_without_colorbox__netx_audio';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__nas_wysiwyg_image_without_colorbox__netx_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image_without_colorbox__netx_document';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__nas_wysiwyg_image_without_colorbox__netx_document'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image_without_colorbox__netx_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => '',
    'image_link' => '',
    'attributes' => array(
      'Author' => 0,
      'Caption' => 0,
      'Collection' => 0,
      'Credit' => 0,
      'Date' => 0,
      'Species - Scientific' => 0,
      'Species - Common Name' => 0,
      'Family' => 0,
      'Order' => 0,
      'Gender' => 0,
      'Flyway' => 0,
      'Subject' => 0,
      'Color' => 0,
      'Location' => 0,
      'Medium' => 0,
      'File Family' => 0,
      'Search Terms' => 0,
      'Status' => 0,
    ),
  );
  $export['image__nas_wysiwyg_image_without_colorbox__netx_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image_without_colorbox__netx_preview';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__nas_wysiwyg_image_without_colorbox__netx_preview'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__nas_wysiwyg_image_without_colorbox__netx_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__nas_wysiwyg_image_without_colorbox__netx_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview__file_field_colorbox';
  $file_display->weight = -32;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'colorbox_node_style' => 'nas_bird_photo_thumbnnail',
    'colorbox_node_style_first' => '',
    'colorbox_image_style' => '',
    'colorbox_gallery' => 'post',
    'colorbox_gallery_custom' => '',
    'colorbox_caption' => 'custom',
    'colorbox_caption_custom' => '[file:field_file_caption] [file:field_file_credit]',
  );
  $export['image__preview__file_field_colorbox'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview__file_field_deepzoom_file';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__preview__file_field_deepzoom_file'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview__file_field_deepzoom_image';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'deepzoom_processor' => 'batch',
    'deepzoom_image_style' => 'large',
  );
  $export['image__preview__file_field_deepzoom_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview__file_field_fbia_image_formatter';
  $file_display->weight = -40;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__preview__file_field_fbia_image_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview__file_field_fbia_media_slideshow_formatter';
  $file_display->weight = -39;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'credit' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__preview__file_field_fbia_media_slideshow_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview__file_field_fbia_video_formatter';
  $file_display->weight = -37;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__preview__file_field_fbia_video_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview__file_field_file_default';
  $file_display->weight = -30;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['image__preview__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview__file_field_file_download_link';
  $file_display->weight = -43;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['image__preview__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview__file_field_file_table';
  $file_display->weight = -36;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__preview__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview__file_field_file_url_plain';
  $file_display->weight = -38;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__preview__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview__file_field_image';
  $file_display->weight = -33;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'media_thumbnail',
    'image_link' => '',
  );
  $export['image__preview__file_field_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview__file_field_image_attributions';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__preview__file_field_image_attributions'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview__file_field_media_large_icon';
  $file_display->weight = -31;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__preview__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview__file_field_soundmanager2_inline_player';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'text' => 'filename',
  );
  $export['image__preview__file_field_soundmanager2_inline_player'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview__file_field_soundmanager2_page_player';
  $file_display->weight = -47;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'text' => 'filename',
  );
  $export['image__preview__file_field_soundmanager2_page_player'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview__file_field_soundmanager2_ui360';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'pause' => 'pause',
    'inline' => 0,
    'visualization' => 1,
    'waveform' => 1,
    'eq' => 1,
    'amplifier' => 1,
    'diameter' => '256',
    'text' => 'filename',
  );
  $export['image__preview__file_field_soundmanager2_ui360'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview__netx_audio';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__preview__netx_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview__netx_document';
  $file_display->weight = -49;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__preview__netx_document'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview__netx_image';
  $file_display->weight = -34;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'media_thumbnail',
    'image_link' => '',
    'attributes' => array(
      'Author' => 0,
      'Caption' => 0,
      'Collection' => 0,
      'Credit' => 0,
      'Date' => 0,
      'Species - Scientific' => 0,
      'Species - Common Name' => 0,
      'Family' => 0,
      'Order' => 0,
      'Gender' => 0,
      'Flyway' => 0,
      'Subject' => 0,
      'Color' => 0,
      'Location' => 0,
      'Medium' => 0,
      'File Family' => 0,
      'Search Terms' => 0,
      'Status' => 0,
    ),
  );
  $export['image__preview__netx_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview__netx_preview';
  $file_display->weight = -35;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'media_thumbnail',
  );
  $export['image__preview__netx_preview'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview__netx_video';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__preview__netx_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__teaser__file_field_deepzoom_file';
  $file_display->weight = -38;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__teaser__file_field_deepzoom_file'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__teaser__file_field_deepzoom_image';
  $file_display->weight = -37;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'deepzoom_processor' => 'batch',
    'deepzoom_image_style' => 'large',
  );
  $export['image__teaser__file_field_deepzoom_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__teaser__file_field_fbia_image_formatter';
  $file_display->weight = -40;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__teaser__file_field_fbia_image_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__teaser__file_field_fbia_media_slideshow_formatter';
  $file_display->weight = -36;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'style' => 'medium',
    'caption' => 0,
    'credit' => 0,
    'likes' => 0,
    'comments' => 0,
    'fullscreen' => 0,
  );
  $export['image__teaser__file_field_fbia_media_slideshow_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__teaser__file_field_fbia_video_formatter';
  $file_display->weight = -35;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__teaser__file_field_fbia_video_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__teaser__file_field_image_attributions';
  $file_display->weight = -34;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__teaser__file_field_image_attributions'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__teaser__netx_audio';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__teaser__netx_audio'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__teaser__netx_document';
  $file_display->weight = -48;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__teaser__netx_document'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__teaser__netx_preview';
  $file_display->weight = -49;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__teaser__netx_preview'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__teaser__netx_video';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__teaser__netx_video'] = $file_display;

  return $export;
}
