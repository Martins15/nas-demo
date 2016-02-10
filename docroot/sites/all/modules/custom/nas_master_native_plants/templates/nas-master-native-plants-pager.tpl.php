<?php
/**
 * @file
 * Template file for the NAS Master Native Plants pager.
 */
?>
<div class="columns">
  <div class="search-results-total hide-for-tiny hide-for-small">
    <div class="column medium-4">
      <strong><?php print t('Results'); ?>:</strong> <?php print format_plural($total_items, '1 plant', '@count plants'); ?>
    </div>
    <div class="column medium-8">
      <div class="pager">
        <?php print $items['previous']; ?>
        <span class="pager-inner">
          <?php print $items['first']; ?>
          <?php foreach ($items as $key => $item):
          if (is_int($key)):
            print $item;
          endif;
          endforeach; ?>
          <?php print $items['last']; ?>
        </span>
        <?php print $items['next']; ?>
      </div>
    </div>
  </div>
</div>

<div class="search-results-total hide-for-medium hide-for-large hide-for-xlarge row">
  <div class="pager">
    <?php print $items['previous']; ?>
    <?php print $items['next']; ?>
  </div>
</div>
