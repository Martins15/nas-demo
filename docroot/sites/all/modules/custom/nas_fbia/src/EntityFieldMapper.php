<?php

/**
 * @file
 * Contains \Drupal\nas_fbia\EntityFieldMapper.
 */

namespace Drupal\nas_fbia;

use Drupal\fb_instant_articles_display\EntityFieldMapper as OriginEntityFieldMapper;
use Drupal\fb_instant_articles\TransformerExtender;
use Facebook\InstantArticles\Elements\Ad;
use Facebook\InstantArticles\Elements\Analytics;
use Facebook\InstantArticles\Elements\Author;
use Facebook\InstantArticles\Elements\Blockquote;
use Facebook\InstantArticles\Elements\Caption;
use Facebook\InstantArticles\Elements\Element;
use Facebook\InstantArticles\Elements\Footer;
use Facebook\InstantArticles\Elements\Header;
use Facebook\InstantArticles\Elements\Image;
use Facebook\InstantArticles\Elements\InstantArticle;
use Facebook\InstantArticles\Elements\Interactive;
use Facebook\InstantArticles\Elements\ListElement;
use Facebook\InstantArticles\Elements\ListItem;
use Facebook\InstantArticles\Elements\Pullquote;
use Facebook\InstantArticles\Elements\Slideshow;
use Facebook\InstantArticles\Elements\SocialEmbed;
use Facebook\InstantArticles\Elements\TextContainer;
use Facebook\InstantArticles\Elements\Video;

/**
 * Class EntityFieldMapper
 *
 * @package Drupal\nas_fbia
 */
class EntityFieldMapper extends OriginEntityFieldMapper {

  /**
   * {@inheritdoc}
   */
  protected function __construct(\stdClass $layoutSettings, InstantArticle $instantArticle) {
    parent::__construct($layoutSettings, $instantArticle);
  }

  /**
   * {@inheritdoc}
   */
  public static function create(\stdClass $layoutSettings, InstantArticle $instantArticle) {
    return new EntityFieldMapper($layoutSettings, $instantArticle);
  }

  /**
   * {@inheritdoc}
   */
  public function map($field, $instance, $langcode, $items, $display) {
    $settings = $display['settings'];
    $active_region = 'none';
    $header = $this->instantArticle->getHeader();
    $footer = $this->instantArticle->getFooter();

    // Determine which region this field belongs to.
    $regions = $this->layoutSettings->settings['regions'];
    foreach ($regions as $region => $fields) {
      if (in_array($field['field_name'], $fields)) {
        $active_region = $region;
        break;
      }
    }

    // We might not have added a footer. If the active region is a footer,
    // ensure it exists before continuing.
    if ($active_region === 'footer' && empty($footer)) {
      $footer = Footer::create();
      $this->instantArticle->withFooter($footer);
    }

    // For each FBIA formatter, place according to the set region, only if it
    // actually makes sense.  ie you can't put a Kicker into the footer.
    switch ($display['type']) {
      case 'fbia_media_formatter':
        // Images are only allowed in the header and body.
        $pass_region = NULL;
        if ($active_region === 'header') {
          $pass_region = $header;
        }
        elseif ($active_region === 'body') {
          $pass_region = $this->instantArticle;
        }
        if ($pass_region) {
          $this->fieldFormatMediaElement($items, $pass_region, $settings);
        }
        break;

      case 'fbia_media_slideshow_formatter':
        // Slideshows are only allowed in body.
        if ($active_region === 'body') {
          $this->fieldFormatMediaSlideshowElement($items, $this->instantArticle, $settings);
        }
        break;

      default:
        parent::map($field, $instance, $langcode, $items, $display);
        break;

    }
  }

  /**
   * Formatter for the Media element.
   *
   * @param array $items
   *   The Field items.
   * @param Element $region
   *   The Layout Region.
   * @param array $settings
   *   Display (formatter) settings.
   */
  private function fieldFormatMediaElement($items, Element $region, $settings) {
    foreach ($items as $delta => $item) {
      if (empty($item['fid']) || !$file = file_load($item['fid'])) {
        continue;
      }
      $item['alt'] = '';
      $item['credit'] = '';
      if ($items = field_get_items('file', $file, 'field_file_caption')) {
        $item['alt'] = strip_tags(trim($items[0]['safe_value']));
      }
      if ($items = field_get_items('file', $file, 'field_file_credit')) {
        $item['credit'] = strip_tags(trim($items[0]['safe_value']));
      }

      if (!empty($settings['style'])) {
        if (empty($item['uri']) && !empty($item['fid'])) {
          // Ensure images work, without requiring a full entity load.
          $item['uri'] = $file->uri;
        }
        $image_url = image_style_url($settings['style'], $item['uri']);
      }
      else {
        $image_url = file_create_url($item['uri']);
      }

      $caption = FALSE;
      if (!empty($settings['caption']) && $item['alt']) {
        $caption = TRUE;
      }
      if (!empty($settings['credit']) && $item['credit']) {
        $caption = TRUE;
      }

      $image = Image::create()
        ->withURL($image_url);
      if ($caption) {
        $image->withCaption(
          Caption::create()
            ->appendText($item['alt'])
            ->withCredit($item['credit'])
        );
      }

      if (!empty($settings['likes'])) {
        $image->enableLike();
      }
      if (!empty($settings['comments'])) {
        $image->enableComments();
      }
      if (!empty($settings['fullscreen'])) {
        $image->withPresentation(Image::FULLSCREEN);
      }

      if ($region instanceof Header) {
        $region->withCover($image);
        // Header can only have one image, break after the first.
        break;
      }
      else if ($region instanceof InstantArticle) {
        $region->addChild($image);
      }
    }
  }

  /**
   * Formatter for the Media Slideshow element.
   *
   * @param array $items
   *   The Field items.
   * @param Element $region
   *   The Layout Region.
   * @param array $settings
   *   Display (formatter) settings.
   */
  private function fieldFormatMediaSlideshowElement($items, Element $region, $settings) {
    // Only allow embedding slideshows into body.
    if (!$region instanceof InstantArticle) {
      return;
    }

    $slideshow = Slideshow::create();
    foreach ($items as $delta => $item) {
      if (empty($item['fid']) || !$file = file_load($item['fid'])) {
        continue;
      }
      $item['alt'] = '';
      $item['credit'] = '';
      if ($items = field_get_items('file', $file, 'field_file_caption')) {
        $item['alt'] = strip_tags(trim($items[0]['safe_value']));
      }
      if ($items = field_get_items('file', $file, 'field_file_credit')) {
        $item['credit'] = strip_tags(trim($items[0]['safe_value']));
      }

      if (!empty($settings['style'])) {
        if (empty($item['uri']) && !empty($item['fid'])) {
          // Ensure images work, without requiring a full entity load.
          $item['uri'] = $file->uri;
        }
        $image_url = image_style_url($settings['style'], $item['uri']);
      }
      else {
        $image_url = file_create_url($item['uri']);
      }

      $caption = FALSE;
      if (!empty($settings['caption']) && $item['alt']) {
        $caption = TRUE;
      }
      if (!empty($settings['credit']) && $item['credit']) {
        $caption = TRUE;
      }

      $image = Image::create()
        ->withURL($image_url);
      if ($caption) {
        $image->withCaption(
          Caption::create()
            ->appendText($item['alt'])
            ->withCredit($item['credit'])
        );
      }

      if (!empty($settings['likes'])) {
        $image->enableLike();
      }
      if (!empty($settings['comments'])) {
        $image->enableComments();
      }
      if (!empty($settings['fullscreen'])) {
        $image->withPresentation(Image::FULLSCREEN);
      }

      $slideshow->addImage($image);
    }

    $region->addChild($slideshow);
  }

}
