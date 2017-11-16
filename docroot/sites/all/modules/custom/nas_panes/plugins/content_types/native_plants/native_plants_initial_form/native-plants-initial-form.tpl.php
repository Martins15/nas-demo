<?php

/**
 * @file
 * Template for Native Plants initial form.
 */
?>
<div class="row element-hidden">
  <div class="columns">
    <?php print render($form['email']); ?>
  </div>
</div>
<div class="row element-hidden">
  <div class="columns medium-6">
    <?php print render($form['zipcode']); ?>
  </div>
  <div class="columns medium-6">
    <?php print render($form['submit']); ?>
  </div>
</div>
<div class="element-hidden">
  <?php print drupal_render_children($form); ?>
</div>
