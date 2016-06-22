<?php

/**
 * @file
 * Contains \Drupal\nas_fbia\SlideshowImageLikeRule.
 */

namespace Drupal\nas_fbia;

use Facebook\InstantArticles\Elements\Image;
use Facebook\InstantArticles\Elements\Caption;
use Facebook\InstantArticles\Elements\Slideshow;
use Facebook\InstantArticles\Transformer\Warnings\InvalidSelector;
use Facebook\InstantArticles\Transformer\Rules\SlideshowImageRule;

/**
 * Class SlideshowImageLikeRule
 *
 * @package Drupal\nas_fbia
 */
class SlideshowImageLikeRule extends SlideshowImageRule {

  /**
   * {@inheritdoc}
   */
  public function getContextClass() {
    return Slideshow::getClassName();
  }

  /**
   * {@inheritdoc}
   */
  public static function create() {
    return new SlideshowImageLikeRule();
  }

  /**
   * {@inheritdoc}
   */
  public static function createFrom($configuration) {
    $image_rule = self::create();
    $image_rule->withSelector($configuration['selector']);

    $image_rule->withProperties(
      [
        self::PROPERTY_IMAGE_URL,
        self::PROPERTY_CAPTION_TITLE,
        self::PROPERTY_CAPTION_CREDIT
      ],
      $configuration
    );

    return $image_rule;
  }

  /**
   * {@inheritdoc}
   */
  public function apply($transformer, $slideshow, $node) {
    $image = Image::create();

    // Builds the image
    $url = $this->getProperty(self::PROPERTY_IMAGE_URL, $node);
    if ($url) {
      $image->withURL($url);
      $image->enableLike();
      $slideshow->addImage($image);
    }
    else {
      $transformer->addWarning(
        new InvalidSelector(
          self::PROPERTY_IMAGE_URL,
          $slideshow,
          $node,
          $this
        )
      );
    }

    $caption = Caption::create();

    $caption_title = $this->getProperty(self::PROPERTY_CAPTION_TITLE, $node);
    if ($caption_title) {
      $caption->withTitle($caption_title);
      $image->withCaption($caption);
    }

    $caption_credit = $this->getProperty(self::PROPERTY_CAPTION_CREDIT, $node);
    if ($caption_credit) {
      $caption->withCredit($caption_credit);
    }

    return $slideshow;
  }

}
