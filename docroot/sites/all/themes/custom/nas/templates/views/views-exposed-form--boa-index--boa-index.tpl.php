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
 * - $q: in case of disabled 'clean urls' contains hidden input <input type="hidden" name="q" />
 * 
 * @ingroup views_templates
 */
?>

<div class="row space-top">
  <div class="column">
    <div class="bird-guide-search-input">
      <?php print $widgets['filter-title']->widget; ?>
    </div>
    <?php print $button; ?>
    <div class="hide">
      <?php print $sort_by; ?>
      <?php print $sort_order; ?>
    </div>
    <div class="row">
      <?php
        // Remove fulltext search widget as it already shown
        unset($widgets['filter-title']);
      ?>
      <?php foreach ($widgets as $id => $widget): ?>
        <div id="<?php print $widget->id; ?>-wrapper" class="columns medium-4 views-widget-<?php print $id; ?>">
          <?php print $widget->widget; ?>
        </div>
      <?php endforeach; ?>
    </div>

    <?php if (!empty($reset_button)): ?>
      <div class="views-exposed-widget views-reset-button">
        <?php print $reset_button; ?>
      </div>
    <?php endif; ?>
  </div>
</div>