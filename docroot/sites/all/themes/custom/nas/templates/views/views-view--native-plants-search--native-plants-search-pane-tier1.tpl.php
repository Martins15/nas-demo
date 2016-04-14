<?php
/**
 * @file
 * Custom view template to display Native Plants Tier 1 search results.
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

  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>

  <div class="row">
    <div class="view native-plants-search-results">
      <div class="view-content">
        <?php if (isset($view->result_tier1)):
          foreach ($view->result as $result): ?>
            <div class="view-row columns">
              <div class="row" style="position: relative;">
                <div class="column medium-8">
                  <h3><?php print $result->CommonName; ?> (<em><?php print $result->ScientificName; ?></em>)</h3>
                </div>
                <div class="column medium-4 hide-for-tiny hide-for-small" style="position: absolute; bottom: 0; right: 0;">
                  <h4><?php print t('Types of birds attracted'); ?></h4>
                </div>
              </div>
              <div class="row">
                <div class="column medium-8">
                  <div class="row">
                    <?php if ($result->PlantImgDesktop): ?>
                      <div class="column medium-4 tier-1-plant-picture hide-for-tiny hide-for-small">
                        <a href="#" class="clearing-attach">
                          <?php print $result->PlantImgDesktop; ?>
                        </a>
                        <ul data-clearing><li><a href="<?php print $result->PlantImgLightbox; ?>"></a></li></ul>
                      </div>
                    <?php endif; ?>
                    <?php if ($result->PlantImgMobile): ?>
                      <div class="tier-1-plant-picture-mobile hide-for-medium hide-for-large hide-for-xlarge">
                        <?php print $result->PlantImgMobile; ?>
                      </div>
                    <?php endif; ?>
                    <div class="column medium-4 hide-for-medium hide-for-large hide-for-xlarge">
                      <h4><?php print t('Types of birds attracted'); ?></h4>
                      <div class="bird-card-carousel">
                        <div class="row">
                          <div class="owl-carousel">
                            <?php foreach ($result->BirdTypes as $bird_type): ?>
                              <div class="node node-bird node-teaser clearfix">
                                <figure class="bird-card">
                                  <div class="bird-card-illustration">
                                    <?php print l(theme('image_style', array(
                                      'path' => $bird_type['image']['uri'],
                                      'style_name'=> 'nas_bird_teaser_illustration',
                                      'alt' => $bird_type['name'],
                                    )), $bird_type['url'], array('html' => TRUE)); ?>
                                  </div>
                                  <figcaption class="bird-card-caption">
                                    <h4 class="common-name"><?php print l($bird_type['name'], $bird_type['url']); ?></h4>
                                  </figcaption>
                                </figure>
                              </div>
                            <?php endforeach; ?>
                          </div>
                        </div>
                      </div>
                    </div>
                    <div class="column medium-<?php print $result->PlantImgDesktop ? '8' : '12'; ?> tier-1-plant">
                      <?php if (user_access('administer nodes')): ?>
                        <span><a href="<?php print $result->LocalLink; ?>" target="_blank"><?php print t('Add/edit local info'); ?></a></span>
                      <?php endif; ?>
                      <?php if ($result->Description): ?>
                        <div class="tier-1-plant--description"><?php print $result->Description; ?></div>
                        <?php if ($result->Source): ?>
                          <div class="tier-1-plant--source"><?php print t('Source') . ': ' . $result->Source; ?></div>
                        <?php endif; ?>
                      <?php endif; ?>
                      <ul class="clearfix plant-attributes-list">
                        <?php foreach ($result->Attributes as $attribute): ?>
                          <li><a href="#" class="native-plants-attribute" data-tid="<?php print $attribute['tid']; ?>" style="background-color: <?php print $attribute['color']; ?>;"><?php print $attribute['name']; ?></a></li>
                        <?php endforeach; ?>
                      </ul>
                      <div class="tier-1-plant--add-to-list">
                        <input type="checkbox" id="checkbox-<?php print $result->PlantID; ?>" class="np-checkbox" <?php print $result->PlantDataAttributes; ?>/>
                        <label for="checkbox-<?php print $result->PlantID; ?>"><?php print t('Add to your plant list'); ?></label>
                      </div>
                    </div>
                  </div>
                </div>
                <div class="column medium-4 hide-for-tiny hide-for-small">
                  <div class="bird-card-carousel">
                    <div class="row">
                      <div class="owl-carousel">
                        <?php foreach ($result->BirdTypes as $bird_type): ?>
                          <div class="node node-bird node-teaser clearfix">
                            <figure class="bird-card">
                              <div class="bird-card-illustration">
                                <?php print l(theme('image_style', array(
                                  'path' => $bird_type['image']['uri'],
                                  'style_name'=> 'nas_bird_teaser_illustration',
                                  'alt' => $bird_type['name'],
                                )), $bird_type['url'], array('html' => TRUE)); ?>
                              </div>
                              <figcaption class="bird-card-caption">
                                <h4 class="common-name"><?php print l($bird_type['name'], $bird_type['url']); ?></h4>
                              </figcaption>
                            </figure>
                          </div>
                        <?php endforeach; ?>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
            </div>
          <?php endforeach; endif; ?>
      </div>

      <?php if ($pager): ?>
        <?php print $pager; ?>
      <?php endif; ?>
    </div>
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
