<?php
/**
 * @file
 * Frontpage Editorial Cards template file.
 *
 * Available variables:
 * - $teasers: rendered articles.
 * - $contextual_links: rendered contextual links.
 */
?>

<div class="row space-bottom double contextual-links-region">
  <?php print $contextual_links; ?>
  <?php foreach ($teasers as $teaser): ?>
    <?php print $teaser; ?>
  <?php endforeach; ?>
</div>
