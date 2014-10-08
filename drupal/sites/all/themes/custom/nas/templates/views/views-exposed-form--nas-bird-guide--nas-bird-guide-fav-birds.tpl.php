<?php
/**
 * @file
 * This template handles the layout of the views exposed filter form.
 *
 * Variables available:
 * - $widgets: An array of exposed form widgets. Each widget contains:
 * - $widget->label: The visible label to print. May be optional.
 * - $widget->operator: The operator for the widget. May be optional.
 * - $widget->widget: The widget itself.
 * - $sort_by: The select box to sort the view using an exposed form.
 * - $sort_order: The select box with the ASC, DESC options to define order. May be optional.
 * - $items_per_page: The select box with the available items per page. May be optional.
 * - $offset: A textfield to define the offset of the view. May be optional.
 * - $reset_button: A button to reset the exposed filter applied. May be optional.
 * - $button: The submit button for the form.
 * - $q in case of disabled 'clean urls' contains hidden input <input type="hidden" name="q" />
 * @ingroup views_templates
 */
?>
<?php if (!empty($q)): ?>
  <?php
  // This ensures that, if clean URLs are off, the 'q' is added first so that
  // it shows up first in the URL.
  print $q;
  ?>
<?php endif; ?>

<div class="bird-guide-search-input">
  <input type="search" placeholder="Search for a bird in the guide..." class="bird-guide-search-input radius">
</div>
<?php print $button; ?>
<div class="row">
  <?php foreach ($widgets as $id => $widget): ?>
    <div id="<?php print $widget->id; ?>-wrapper" class="columns medium-4 views-widget-<?php print $id; ?>">
      <?php print $widget->widget; ?>
    </div>
  <?php endforeach; ?>
</div>
<?php if (!empty($sort_by)): ?>
  <div class="views-exposed-widget views-widget-sort-by">
    <?php print $sort_by; ?>
  </div>
  <div class="views-exposed-widget views-widget-sort-order">
    <?php print $sort_order; ?>
  </div>
<?php endif; ?>


<?php if (!empty($reset_button)): ?>
  <div class="views-exposed-widget views-reset-button">
    <?php print $reset_button; ?>
  </div>
<?php endif; ?>
