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
<?php print drupal_render_children($form); ?>
<div class="ngp-form"
     data-form-url="https://actions.everyaction.com/v1/Forms/S49LshHFBUKAejEkZAfw-g2"
     data-fastaction-endpoint="https://fastaction.ngpvan.com"
     data-inline-errors="true"
     data-fastaction-nologin="true"
     data-databag="everybody">
</div>