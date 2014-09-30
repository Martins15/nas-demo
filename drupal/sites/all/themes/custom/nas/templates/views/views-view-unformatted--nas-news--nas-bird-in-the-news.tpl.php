<?php

/**
 * @file
 * Custom view template to display Bird in the News.
 *
 * @ingroup views_templates
 */
?>
<div class="row section-header">
  <div class="columns">
    <h2 class="thin"><?php print drupal_get_title() . '&nbsp;' . t('in the News'); ?></h2>
  </div>
  <div class="columns">
    <ul class="section-nav inline-list hide-for-small hide-for-tiny">
      <li><?php print l(t('More News »'), ''); ?></a></li>
    </ul>
  </div>
</div>
<div class="row">
  <?php foreach ($rows as $id => $row): ?>
  <div class="large-4 columns">
    <div class="editorial-card collapse-minimal">
      <?php print $row; ?>
    </div>
  </div>
  <?php endforeach; ?>
</div>
