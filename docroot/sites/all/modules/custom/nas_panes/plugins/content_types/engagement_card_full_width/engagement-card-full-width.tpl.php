<?php
/**
 * @file
 * Engagement card full width template.
 *
 * Available variables:
 *  $context_links - contextual links.
 *  $engagement_card - rendered engagement card.
 */
?>
<div class="engagement-hero<?php print !empty($context_links) ? ' contextual-links-region' : ''; ?>">
  <?php print $context_links; ?>
  <div class="bg-respond hero native-plants-hero">
    <?php print $engagement_card; ?>
  </div>
</div>
