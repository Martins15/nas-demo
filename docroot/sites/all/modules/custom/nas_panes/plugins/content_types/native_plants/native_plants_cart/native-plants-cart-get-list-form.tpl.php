<?php
/**
 * @file
 * Template for Native Plants get list form.
 */
?>
<div class="flexbox-container">
  <?php print render($form['email']); ?>
  <?php print render($form['submit']); ?>
</div>
<?php print drupal_render_children($form); ?>
