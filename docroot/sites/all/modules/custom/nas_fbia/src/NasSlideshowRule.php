<?php

namespace Drupal\nas_fbia;

use Facebook\InstantArticles\Elements\InstantArticle;
use Facebook\InstantArticles\Transformer\Rules\SlideshowRule;

/**
 * Class NasSlideshowRule.
 *
 * @package Drupal\nas_fbia
 */
class NasSlideshowRule extends SlideshowRule {

  /**
   * {@inheritdoc}
   */
  public function getContextClass() {
    return InstantArticle::getClassName();
  }

  /**
   * {@inheritdoc}
   */
  public static function create() {
    return new NasSlideshowRule();
  }

  /**
   * {@inheritdoc}
   */
  public static function createFrom($configuration) {
    $slideshow_rule = self::create();
    $slideshow_rule->withSelector($configuration['selector']);

    return $slideshow_rule;
  }

  /**
   * {@inheritdoc}
   */
  public function apply($transformer, $instant_article, $node) {
    // Builds the slideshow.
    $slideshow = NasSlideshow::create();
    $instant_article->addChild($slideshow);

    $transformer->transform($slideshow, $node);

    return $instant_article;
  }

}
