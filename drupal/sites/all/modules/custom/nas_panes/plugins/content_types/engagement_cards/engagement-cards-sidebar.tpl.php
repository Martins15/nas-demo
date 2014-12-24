<?php
/**
 * @file
 * Template to custom pane engagement_cards_sidebar.
 *
 * Available variables:
 *  $contextual_links - contextual links.
 *  $teaser - rendered node.
 */
?>
<div class="sidebar-section contextual-links-region">
  <?php print $contextual_links; ?>
  <?php foreach ($teasers as $teaser): ?>
    <?php print $teaser; ?>
  <?php endforeach; ?>
  <?php if (empty($teasers)): ?>
    <p>&nbsp;</p>
  <?php endif; ?>
</div>
