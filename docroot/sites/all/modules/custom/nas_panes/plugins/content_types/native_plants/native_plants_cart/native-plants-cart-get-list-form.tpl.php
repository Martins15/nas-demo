<?php
/**
 * @file
 * Template for Native Plants get list form.
 */
?>
<div class="row">
  <div class="columns tiny-9">
    <?php print render($form['email']); ?>
  </div>
  <div class="columns tiny-3">
    <?php print render($form['submit']); ?>
  </div>
</div>
<?php print drupal_render_children($form); ?>
