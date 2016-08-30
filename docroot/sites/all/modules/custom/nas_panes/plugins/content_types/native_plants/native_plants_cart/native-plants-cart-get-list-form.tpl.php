<?php
/**
 * @file
 * Template for Native Plants get list form.
 */
?>
<div class="row">
  <div class="columns tiny-8 large-10">
    <?php print render($form['email']); ?>
  </div>
  <div class="columns tiny-4 large-2">
    <?php print render($form['submit']); ?>
  </div>
</div>
<?php print drupal_render_children($form); ?>
