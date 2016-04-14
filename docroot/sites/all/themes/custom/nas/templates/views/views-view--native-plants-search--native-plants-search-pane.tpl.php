<?php
/**
 * @file
 * Custom view template to display Native Plants search results.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<div class="<?php print $classes; ?>">
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>

  <?php if ($exposed): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>

  <div class="row np-search-full-results">
    <div class="mobile-results-total-wrapper hide-for-medium hide-for-large hide-for-xlarge">
      <div class="mobile-results-total columns">
        <strong><?php print t('Full results'); ?>:</strong> <?php print format_plural($total_items, '1 plant', '@count plants'); ?>
      </div>
    </div>
    <div class="columns">
      <h2 class="thin hide-for-tiny hide-form-small"><?php print t('Full results'); ?></h2>
      <p class="hide-for-tiny hide-for-small filter-label"><?php print t('Filter'); ?></p>

      <form action="#" class="inner-filters-wrapper">
      </form>
    </div>

    <?php if ($rows): ?>
    <div class="native-plants-full-search-results">
      <div class="columns">
        <table class="hide-for-tiny hide-for-small">
          <thead>
          <tr>
            <th><?php print t('Plant name'); ?></th>
            <th><?php print t('Scientific name'); ?></th>
            <th><?php print t('Attributes'); ?></th>
            <th><?php print t('May attract'); ?></th>
          </tr>
          </thead>
          <tbody>
          <?php foreach ($view->result as $result): ?>
            <tr>
              <td>
                <div class="plant--add-to-list">
                  <input type="checkbox" id="checkbox-f<?php print $result->PlantID; ?>" class="np-checkbox" <?php print $result->PlantDataAttributes; ?>/>
                  <label for="checkbox-f<?php print $result->PlantID; ?>"><?php print $result->CommonName; ?></label>
                  <?php if ($result->PlantImgLightbox): ?>
                    <a href="<?php print $result->PlantImgLightbox; ?>" class="icon-camera clearing-attach" title="<?php print t('Preview'); ?>"></a>
                    <ul data-clearing class="clearing-thumbs"><li><a href="<?php print $result->PlantImgLightbox; ?>"></a></li></ul>
                  <?php endif; ?>
                  <?php if (user_access('administer nodes')): ?>
                    <br><span><a href="<?php print $result->LocalLink; ?>" target="_blank"><?php print t('Add/edit local info'); ?></a></span>
                  <?php endif; ?>
                </div>
              </td>
              <td><em><?php print $result->ScientificName; ?></em></td>
              <td>
                <ul class="clearfix plant-attributes-list plant-attributes-list-small">
                  <?php foreach ($result->Attributes as $attribute): ?>
                    <li><a href="#" class="native-plants-attribute" data-tid="<?php print $attribute['tid']; ?>" style="background-color: <?php print $attribute['color']; ?>;"><?php print $attribute['name']; ?></a></li>
                  <?php endforeach; ?>
                </ul>
              </td>
              <td>
                <?php $attracts = array();
                foreach ($result->BirdTypes as $bird_type):
                  $attracts[] = l($bird_type['name'], $bird_type['url']);
                endforeach;
                print implode(', ', $attracts); ?>
              </td>
            </tr>
          <?php endforeach; ?>
          </tbody>
        </table>
      </div>

      <div class="mobile-search-full-results hide-for-medium hide-for-large hide-for-xlarge">
        <?php foreach ($view->result as $result): ?>
          <div class="clearfix view-row">
            <div class="columns">
              <div>
                <span class="mobile-search-full-results--label"><?php print t('Plant'); ?>:</span> <?php print $result->CommonName; ?>
                <?php if ($result->PlantImgLightbox): ?>
                  <a href="<?php print $result->PlantImgLightbox; ?>" class="icon-camera clearing-attach" title="<?php print t('Preview'); ?>"></a>
                  <ul data-clearing><li><a href="<?php print $result->PlantImgLightbox; ?>"></a></li></ul>
                <?php endif; ?>
              </div>
              <div>
                <span class="mobile-search-full-results--label"><?php print t('Scientific name'); ?>:</span> <em><?php print $result->ScientificName; ?></em>
              </div>
              <div>
                <span class="mobile-search-full-results--label"><?php print t('Attributes'); ?>:</span>
                <?php
                  $attributes = array();
                  foreach ($result->Attributes as $attribute) {
                    $attributes[] = '<a href="#" class="native-plants-attribute" data-tid="' . $attribute['tid'] . '" style="color: ' . $attribute['color'] . '">' . $attribute['name'] . '</a>';
                  }
                  print implode(', ', $attributes);
                ?>
              </div>
              <div>
                <span class="mobile-search-full-results--label"><?php print t('Attracts'); ?>:</span>
                <?php $attracts = array();
                foreach ($result->BirdTypes as $bird_type):
                  $attracts[] = l($bird_type['name'], $bird_type['url']);
                endforeach;
                print implode(', ', $attracts); ?>
              </div>
              <div class="plant--add-to-list">
                <input type="checkbox" id="checkbox-f<?php print $result->PlantID; ?>-s" class="np-checkbox" <?php print $result->PlantDataAttributes; ?>/>
                <label for="checkbox-f<?php print $result->PlantID; ?>-s"><?php print t('Add to your plant list'); ?></label>
              </div>
            </div>
          </div>
        <?php endforeach; ?>
      </div>

      <?php if ($pager): ?>
        <?php print $pager; ?>
      <?php endif; ?>
    </div>
    <?php endif; ?>
  </div>

  <?php if (!$rows & isset($empty)): ?>
    <div class="view-empty row">
      <div class="columns">
        <?php print $empty; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <?php print $more; ?>
  <?php endif; ?>

  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>

</div><?php /* class view */ ?>
