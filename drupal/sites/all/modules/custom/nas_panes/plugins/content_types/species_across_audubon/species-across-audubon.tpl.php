<?php
/**
 * @file
 * Custom view template to display Bird in the News.
 *
 * @ingroup views_templates
 */
?>
<div class="row section-header contextual-links-region">
  <?php print $contextual_links; ?>
  <?php if (!empty($teasers)): ?>
  <div class="columns">
    <h2 class="thin"><?php print $title; ?></h2>
  </div>
  <div class="columns">
    <ul class="section-nav inline-list hide-for-small hide-for-tiny">
      <li><?php print l(t('More Conservation Projects »'), 'conservation'); ?></li>
    </ul>
  </div>
</div>
<div class="row space-bottom">
  <?php foreach ($teasers as $teaser): ?>
    <?php print $teaser; ?>
  <?php endforeach; ?>
  <ul class="section-nav inline-list hide-for-medium hide-for-large hide-for-xlarge">
    <li><?php print l(t('More Conservation Projects »'), 'conservation'); ?></li>
  </ul>
  <?php endif; ?>
</div>
