<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<div class="row card-set">
  <?php foreach ($view->result as $result): ?>
    <?php
      $image = '';
      if ($file = file_load($result->_entity_properties['image'])) {
        $image = theme('image', array(
            'path' => image_style_url('article_teaser', $file->uri),
            'alt' => $result->_entity_properties['hero_image_title'],
          ));
        $linked_image = l($image, $result->_entity_properties['path'], array(
            'html' => TRUE,
            'attributes' => array('title' => $result->_entity_properties['hero_image_title']),
          ));
      }
      $title = l($result->_entity_properties['title'], $result->_entity_properties['path']);
    ?>
  <div class="columns large-3">
    <div class="editorial-card feature collapse-minimal">
      <div class="editorial-card-photo">
        <?php print $linked_image; ?>
      </div>
      <div class="editorial-card-content short">
        <h4 class="editorial-card-title no-margin"><?php print $title; ?></h4>
      </div>
    </div>
  </div>
  <?php endforeach; ?>

</div>