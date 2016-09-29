<?php

/**
 * @file
 * Template implementation to display the value of a field.
 */
?>
<div class="guide-bar magazine">
  <div class="row">
    <div class="column">
      <h2 class="guide-bar-title">
        <span class="hide-for-tiny hide-for-small"><?php print t('From the Magazine'); ?></span>
        <span class="hide-for-medium hide-for-large hide-for-xlarge"><?php print t('Magazine'); ?></span>
      </h2>
      <div class="guide-bar-date">
        <?php if ($first_month_part_1 && $sec_month_part_1 && $year): ?>
        <a href="<?php print $href; ?>"><?php print $first_month_part_1; ?><span class="hide-for-small hide-for-tiny"><?php print $first_month_part_2; ?></span>– <?php print $sec_month_part_1; ?><span class="hide-for-small hide-for-tiny"><?php print $sec_month_part_2; ?></span> <?php print $year; ?></a>
        <?php else: ?>
        <a href="<?php print $href; ?>"><?php print $origin; ?></a>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>
