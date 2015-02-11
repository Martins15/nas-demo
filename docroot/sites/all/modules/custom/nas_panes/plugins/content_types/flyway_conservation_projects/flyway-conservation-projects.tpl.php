<?php
/**
 * @file
 * Template to custom pane flyway_cons_projects.
 *
 * Available variables:
 *  $contextual_links - contextual links.
 *  $title - pane's title.
 *  $more_link - link to Conservation Landing.
 *  $teasers - array of rendered Conservation Projects.
 */
?>

<div class="card-set contextual-links-region">
  <?php print $contextual_links; ?>
  <div class="row section-header">
    <div class="column">
      <h2 class="thin"><?php print $title; ?></h2>
    </div>
    <div class="column">
      <ul class="section-nav inline-list">
        <li><?php print $more_link; ?></li>
      </ul>
    </div>
  </div>
  <div class="row">
    <?php foreach ($teasers as $teaser): ?>
      <?php print $teaser; ?>
    <?php endforeach; ?>
  </div>
</div>
