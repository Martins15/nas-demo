<?php

/**
 * @file
 * Template for Native Plants pledge form.
 */
?>
<div class="row">
  <div class="columns medium-6">
    <div class="flexbox-container">
      <?php print render($form['quantity']); ?>
    </div>
  </div>
  <div class="columns medium-6">
    <div class="flexbox-container">
      <?php print render($form['zipcode']); ?>
    </div>
  </div>
</div>
<div class="row">
  <div class="columns tiny-10 medium-6">
    <?php print render($form['email']); ?>
  </div>
  <div class="columns tiny-2 medium-2">
    <?php print render($form['submit']); ?>
  </div>
</div>
<?php print drupal_render_children($form); ?>
