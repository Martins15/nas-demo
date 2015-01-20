<?php
/**
 * @file
 * Magazine bar template.
 */
?>

<div class="guide-bar magazine">
  <div class="row">
    <div class="column">
      <h2 class="guide-bar-title">
        <span class="hide-for-small hide-for-tiny"><?php print t('From the'); ?> </span><?php print t('Magazine'); ?>
      </h2>
      <div class="guide-bar-date">
        <a href="<?php print $link; ?>"><?php print $first_month_part_1; ?><span class="hide-for-small hide-for-tiny"><?php print $first_month_part_2; ?></span>– <?php print $sec_month_part_1; ?><span class="hide-for-small hide-for-tiny"><?php print $sec_month_part_2; ?></span> <?php print $year; ?></a>
      </div>
    </div>
  </div>
</div>
