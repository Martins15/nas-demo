<?php
/**
 * @file
 * About Page Map template file.
 */
?>

  <div class="near-you-form bird-guide-zip-input">
    <?php print drupal_render($form['zip_code']); ?>
  </div>
  <div class="near-you-form bird-guide-country">
    <?php print drupal_render($form['state']); ?>
  </div>
  <div class="btn-submint">
    <?php print drupal_render($form['submit']); ?>
  </div>
  <?php print drupal_render_children($form); ?>
