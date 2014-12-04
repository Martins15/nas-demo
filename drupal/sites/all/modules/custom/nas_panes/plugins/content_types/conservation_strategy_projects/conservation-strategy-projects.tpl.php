<?php
/**
 * @file
 * Conservation Strategy Projects template file.
 */
?>

<section class="card-set bg-gray">
  <div class="row space-top">
    <div class="column">
      <h2 class="thin"><?php print $title; ?></h2>
    </div>
  </div>
  <div class="row clearfix conservation-strategy-projects-block <?php print !empty($contextual_links) ? 'contextual-links-region' : '' ?>">
    <?php print $contextual_links; ?>
    <div class="projects-list">
      <?php foreach ($teasers as $teaser) : ?>
        <?php print $teaser; ?>
      <?php endforeach; ?>
    </div>
</section>
