<?php
/**
 * @file
 * Template for Native Plants Views exposed form.
 */
?>
<div class="row">
  <div class="columns">
    <h2 class="thin hide-for-tiny hide-for-small"><?php print t('Search'); ?></h2>
    <?php print render($form['zipcode']); ?>
    <div style="display: none;">
      <?php print render($form['attribute']); ?>
      <?php print render($form['bird_type']); ?>
    </div>
    <?php print render($form['submit']); ?>
  </div>
</div>
<?php print drupal_render_children($form); ?>
