<?php
/**
 * @file
 * Template for the Donate sticky bar form.
 */
?>
<div class="hide-for-tiny hide-for-small contextual-links-region" id="OptimizelyDonationBar">
  <?php print $contextual_links; ?>
  <p><?php print $text; ?></p>
  <form action="<?php print $form_link; ?>" onsubmit="return Drupal.donate_sticky_bar.setPennies();">
    <?php print $form_elements; ?>
    <input type="hidden" id="setValue" name="set.Value" value="">
    <input type="text" id="inputValue" placeholder="<?php print $form_placeholder; ?>">
    <input name="submitButton" value="<?php print $form_button_text; ?>" type="submit">
  </form>
</div>