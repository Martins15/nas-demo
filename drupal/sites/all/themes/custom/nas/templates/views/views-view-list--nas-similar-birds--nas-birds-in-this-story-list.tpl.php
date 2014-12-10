<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */
?>
<?php print $wrapper_prefix; ?>
  <?php if (!empty($title)) : ?>
    <h3><?php print $title; ?></h3>
  <?php endif; ?>
  <?php print $list_type_prefix; ?>
    <?php foreach ($rows as $id => $row): ?>
      <?php if ($id < 3): ?>
      <li><?php print $row; ?></li>
      <?php else: ?>
      <li class="see-all-show bits-see-all-show"><?php print $row; ?></li>
      <?php endif; ?>
    <?php endforeach; ?>
  <?php print $list_type_suffix; ?>
<?php print $wrapper_suffix; ?>
<?php if (count($rows) > 3): ?>
  <hr class="bits-see-all-hide">
  <a class="bits-see-all bits-see-all-hide bits-see-all-controller" href="#"><small><?php print t('See all »'); ?></small></a>
<?php endif; ?>
