<?php
/**
 * @file
 * Template for Email form.
 */
?>
<div class="row">
  <div class="columns medium-8">
    <?php $form['email']['#attributes']['class'] = array('native-plants-search-form--email'); print render($form['email']); ?>
  </div>
  <div class="columns medium-4">
    <?php $form['submit']['#attributes']['class'][] = 'native-plants-search-form--submit'; print render($form['submit']); ?>
  </div>
</div>
<?php print drupal_render_children($form); ?>
