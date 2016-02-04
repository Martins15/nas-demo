<?php
/**
 * @file
 * Custom view template to display Native Plants search results.
 */
?>
<h3>Tier1 results</h3>
<?php foreach ($view->result_tier1 as $result): ?>
  <div>
    <span><?php print $result->CommonName; ?></span>
    <span><?php print $result->ScientificName; ?></span>
    <span><?php print $result->Family; ?></span>
    <?php if ($result->Tier1): ?>
      <span><?php print $result->Description; ?></span>
    <?php endif; ?>
    <span><a href="<?php print $result->LocalLink; ?>" target="_blank"><?php print t('Add/edit local info'); ?></a></span>
  </div>
<?php endforeach; ?>
<h3>All results</h3>
<?php foreach ($view->result as $result): ?>
  <div>
    <span><?php print $result->CommonName; ?></span>
    <span><?php print $result->ScientificName; ?></span>
    <span><?php print $result->Family; ?></span>
    <?php if ($result->Tier1): ?>
      <span><strong>Tier1</strong></span>
    <?php endif; ?>
    <span><a href="<?php print $result->LocalLink; ?>" target="_blank"><?php print t('Add/edit local info'); ?></a></span>
  </div>
<?php endforeach; ?>