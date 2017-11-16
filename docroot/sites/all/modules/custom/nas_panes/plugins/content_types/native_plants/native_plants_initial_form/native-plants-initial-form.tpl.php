<?php

/**
 * @file
 * Template for Native Plants initial form.
 */
?>
<div class="row">
  <div class="columns">
    <?php print render($form['email']); ?>
  </div>
</div>
<div class="row">
  <div class="columns medium-6">
    <?php print render($form['zipcode']); ?>
  </div>
  <div class="columns medium-6">
    <?php print render($form['submit']); ?>
  </div>
</div>
<?php print drupal_render_children($form); ?>

