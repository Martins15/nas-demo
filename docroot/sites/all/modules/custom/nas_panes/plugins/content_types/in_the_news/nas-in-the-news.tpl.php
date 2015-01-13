<?php
/**
 * @file
 * Custom view template to display Bird in the News.
 *
 * @ingroup views_templates
 */
?>

<div class="bg-gray contextual-links-region">
  <?php print $contextual_links; ?>
  <div class="row section-header">
    <div class="columns">
      <h2 class="thin"><?php print $title; ?></h2>
    </div>
    <div class="columns">
      <ul class="section-nav inline-list hide-for-small hide-for-tiny">
        <li><?php print l(t('More News »'), ''); ?></li>
      </ul>
    </div>
  </div>
  <div class="row">
    <?php foreach ($teasers as $teaser): ?>
      <?php print $teaser; ?>
    <?php endforeach; ?>
  </div>
</div>


