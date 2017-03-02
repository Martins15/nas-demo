<?php

/**
 * @file
 * Template for Native Plants pledge form.
 */
?>
<div class="row">
  <div class="columns medium-10">
    <div class="row">
      <div class="columns medium-6">
        <?php print render($form['quantity']); ?>
      </div>
      <div class="columns medium-6">
        <?php print render($form['zipcode']); ?>
      </div>
    </div>
  </div>
</div>
<div class="row">
  <div class="columns medium-10">
    <?php print render($form['email']); ?>
  </div>
  <div class="columns medium-10 large-2">
    <?php print render($form['submit']); ?>
  </div>
</div>
<?php print drupal_render_children($form); ?>
