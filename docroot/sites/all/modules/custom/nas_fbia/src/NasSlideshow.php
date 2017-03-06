<?php

namespace Drupal\nas_fbia;

use Facebook\InstantArticles\Elements\Slideshow;
use Facebook\InstantArticles\Elements\Caption;
use Facebook\InstantArticles\Elements\Audio;
use Facebook\InstantArticles\Elements\Image;
use Facebook\InstantArticles\Elements\Container;
use Facebook\InstantArticles\Validators\Type;

// @codingStandardsIgnoreStart
/**
 * Class NasSlideshow.
 *
 * This element Class is the slideshow for the article.
 *
 * Example:
 *   <figure>
 *       <img src="http://mydomain.com/path/to/img1.jpg" />
 *   </figure>
 *   <figure>
 *       <img src="http://mydomain.com/path/to/img2.jpg" />
 *   </figure>
 *   <figure>
 *       <img src="http://mydomain.com/path/to/img3.jpg" />
 *   </figure>
 *
 * @see {link:https://developers.intern.facebook.com/docs/instant-articles/reference/image}
 */
class NasSlideshow extends Slideshow {

  /**
   * @var \Facebook\InstantArticles\Elements\Caption
   *   The caption for the NasSlideshow
   */
  private $caption;

  /**
   * @var \Facebook\InstantArticles\Elements\Image[]
   *   The images hosted on web that will be shown on the NasSlideshow
   */
  private $article_images = [];

  /**
   * @var \Facebook\InstantArticles\Elements\Audio
   *   The audio if the NasSlideshow uses audio
   */
  private $audio;

  /**
   * @var string
   *  The attribution citation text in the <cite>...</cite> tags.
   */
  private $attribution;

  /**
   * NasSlideshow constructor.
   */
  private function __construct() {
    // Intentionally empty.
  }

  /**
   * {@inheritdoc}
   */
  public static function create() {
    return new self();
  }

  /**
   * Sets the Image list of images for the NasSlideshow.
   *
   * It is REQUIRED.
   *
   * @param \Facebook\InstantArticles\Elements\Image[] $article_images
   *   The images. Ie: http://domain.com/img.png
   *
   * @return $this
   */
  public function withImages(Image $article_images) {
    Type::enforceArrayOf($article_images, Image::getClassName());
    $this->article_images = $article_images;

    return $this;
  }

  /**
   * Adds a new image to the NasSlideshow.
   *
   * It is REQUIRED.
   *
   * @param \Facebook\InstantArticles\Elements\Image $article_image
   *   The image.
   *
   * @return $this
   */
  public function addImage(Image $article_image) {
    Type::enforce($article_image, Image::getClassName());
    $this->article_images[] = $article_image;

    return $this;
  }

  /**
   * Returns Artcile images.
   *
   * @return \Facebook\InstantArticles\Elements\Image[]
   *  The ArticleImages content of the slideshow
   */
  public function getArticleImages() {
    return $this->article_images;
  }

  /**
   * Structure and create the full NasSlideshow in a XML format DOMElement.
   *
   * @param \DOMDocument $document
   *   Where this element will be appended. Optional.
   *
   * @return \DOMElement
   */
  public function toDOMElement(\DOMDocument $document = NULL) {
    if (!$document) {
      $document = new \DOMDocument();
    }

    if (!$this->isValid()) {
      return $this->emptyElement($document);
    }
    $element = $this->emptyElement($document);
    // URL markup required.
    if ($this->article_images) {
      foreach ($this->article_images as $article_image) {
        $article_image_element = $article_image->toDOMElement($document);
        $element->appendChild($article_image_element);
      }
    }

    return $element;
  }

  /**
   * Overrides the Element::isValid().
   *
   * @see Element::isValid()
   *
   * @return TRUE for valid NasSlideshow that contains at least one Image valid, FALSE otherwise.
   */
  public function isValid() {
    foreach ($this->article_images as $item) {
      if ($item->isValid()) {
        return TRUE;
      }
    }
    return FALSE;
  }

  /**
   * Implements the Container::getContainerChildren().
   *
   * @see Container::getContainerChildren()
   *
   * @return array
   *   Array of Elements contained by Image.
   */
  public function getContainerChildren() {
    $children = array();

    if ($this->article_images) {
      foreach ($this->article_images as $article_image) {
        $children[] = $article_image;
      }
    }

    if ($this->caption) {
      $children[] = $this->caption;
    }

    // Audio markup optional.
    if ($this->audio) {
      $children[] = $this->audio;
    }

    return $children;
  }

}
// @codingStandardsIgnoreEnd
