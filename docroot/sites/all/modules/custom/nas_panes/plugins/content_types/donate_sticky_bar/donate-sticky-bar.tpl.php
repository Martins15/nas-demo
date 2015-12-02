<?php
/**
 * @file
 * Template for the Donate sticky bar.
 */
?>
<div class="hide-for-tiny hide-for-small contextual-links-region" id="OptimizelyDonationBar">
	<?php print $contextual_links; ?>
	<p><?php print $text; ?></p>
	<form action="https://secure.audubon.org/site/Donation2" onsubmit="return Drupal.donate_sticky_bar.setPennies();">
		<input type="hidden" name="df_id" value="6960">
		<input type="hidden" name="6960.donation" value="form1">
		<input type="hidden" name="s_src" value="2015_AUDHP_doantionbar-donate_test">
		<input type="hidden" name="s_subsrc" value="website">
		<input type="hidden" name="set.DonationLevel" value="9466">
		<input type="hidden" id="setValue" name="set.Value" value="">
		<input type="text" id="inputValue" placeholder="<?php print $placeholder; ?>">
		<input type="hidden" name="OptimizelyDonationBar" value="clicked">
		<input name="submitButton" value="<?php print $button_text; ?>" type="submit">
	</form>
</div>