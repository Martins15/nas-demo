<?php
/**
 * @file
 * Custom view template to display Native Plants search results.
 */
?>
<div class="row">
  <div class="columns">
    <h2 class="thin">Try these first</h2>
    <p>These plants should be relatively easy to find and/or grow in your area. <a href="#">Read more.</a></p>
  </div>
</div>

<div class="row">
  <div class="view native-plants-search-results">
    <div class="view-content">
      <?php foreach ($view->result_tier1 as $result): ?>
        <div class="view-row columns">
          <h3><?php print $result->CommonName; ?> (<em><?php print $result->ScientificName; ?></em>)</h3>
          <div class="row">
            <div class="column medium-3">
              <div class="tier-1-plant-picture hide-for-tiny hide-for-small">
                <?php print theme('imagecache_external', array(
                  'path' => $result->PlantImg,
                  'style_name'=> 'native_plant_desktop',
                  'alt' => $result->CommonName,
                )); ?>
              </div>
              <div class="row tier-1-plant-picture-mobile hide-for-medium hide-for-large hide-for-xlarge">
                <?php print theme('imagecache_external', array(
                  'path' => $result->PlantImg,
                  'style_name'=> 'native_plant_mobile',
                  'alt' => $result->CommonName,
                )); ?>
              </div>
            </div>
            <div class="column medium-4 medium-push-5">
              <h4><?php print t('Types of birds attracted'); ?></h4>
              <div class="bird-card-carousel">
                <div class="row">
                  <div class="owl-carousel">
                    <?php foreach ($result->BirdTypes as $bird_type): ?>
                    <div class="node node-bird node-teaser clearfix">
                      <figure class="bird-card">
                        <div class="bird-card-illustration">
                          <a href="#"><img src="<?php print image_style_url('nas_bird_teaser_illustration', $bird_type['image']['uri']); ?>" alt=""></a></div>
                        <figcaption class="bird-card-caption">
                          <h4 class="common-name"><a href="#"><?php print $bird_type['name']; ?></a></h4>
                        </figcaption>
                      </figure>
                    </div>
                    <?php endforeach; ?>
                  </div>
                </div>
              </div>
            </div>
            <div class="column medium-5 medium-pull-4 tier-1-plant">
              <?php if (user_access('administer nodes')): ?>
                <span><a href="<?php print $result->LocalLink; ?>" target="_blank"><?php print t('Add/edit local info'); ?></a></span>
              <?php endif; ?>
              <div class="tier-1-plant--description"><?php print $result->Description; ?></div>
              <div class="tier-1-plant--source"><?php print t('Source'); ?>: <a href="#">Wikipedia</a></div>
              <ul class="clearfix plant-attributes-list">
                <?php foreach ($result->Attributes as $attribute): ?>
                  <li><span style="background-color: <?php print $attribute['color']; ?>;"><?php print $attribute['name']; ?></span></li>
                <?php endforeach; ?>
              </ul>
              <div class="tier-1-plant--add-to-list">
                <input type="checkbox" id="checkbox-<?php print $result->PlantID; ?>"class="np-checkbox"/>
                <label for="checkbox-<?php print $result->PlantID; ?>"><?php print t('Add to your plant list'); ?></label>
              </div>
            </div>
          </div>
        </div>
      <?php endforeach; ?>
    </div>
  </div>
</div>

<div class="row">
  <div class="mobile-results-total-wrapper hide-for-medium hide-for-large hide-for-xlarge">
    <div class="mobile-results-total columns">
      <strong><?php print t('Full results'); ?>:</strong> <?php print format_plural($view->query->pager->total_items, '1 plant', '@count plants'); ?>
    </div>
  </div>
  <div class="columns">
    <h2 class="thin hide-for-tiny hide-form-small"><?php print t('Full results'); ?></h2>
    <p class="hide-for-tiny hide-for-small"><?php print t('Filter'); ?></p>

    <form action="#" class="inner-filters-wrapper">
      <select name="" id="s1" placeholder="All types of plants">
        <option value="">option 1</option>
        <option value="">option 2</option>
        <option value="">option 3</option>
      </select>

      <select name="" id="s2" placeholder="Attracts: Any type of bird">
        <option value="">option 1</option>
        <option value="">option 2</option>
        <option value="">option 3</option>
      </select>
    </form>
  </div>

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
                <input type="checkbox" id="checkbox-f<?php print $result->PlantID; ?>" class="np-checkbox"/>
                <label for="checkbox-f<?php print $result->PlantID; ?>"><?php print $result->CommonName; ?></label>
                <?php if ($result->PlantImg): ?>
                  <a href="#" class="icon-camera" title="<?php print t('Preview'); ?>"></a>
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
                  <li><span style="background-color: <?php print $attribute['color']; ?>;"><?php print $attribute['name']; ?></span></li>
                <?php endforeach; ?>
              </ul>
            </td>
            <td>
              <?php $attracts = array();
              foreach ($result->BirdTypes as $bird_type):
                $attracts[] = '<a href="#">' . $bird_type['name'] . '</a>';
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
            <?php if ($result->PlantImg): ?>
              <a href="#" class="icon-camera" title="<?php print t('Preview'); ?>"></a>
            <?php endif; ?>
          </div>
          <div>
            <span class="mobile-search-full-results--label"><?php print t('Scientific name'); ?>:</span> <em><?php print $result->ScientificName; ?></em>
          </div>
          <div>
            <span class="mobile-search-full-results--label"><?php print t('Attributes'); ?>:</span>
            <?php
              $attributes = array();
              foreach ($result->Attributes as $attribute):
                $attributes[] = '<span style="color: ' . $attribute['color'] . '">' . $attribute['name'] . '</span>';
              endforeach;
              print implode(', ', $attributes);
              ?>
          </div>
          <div>
            <span class="mobile-search-full-results--label"><?php print t('Attracts'); ?>:</span>
            <?php $attracts = array();
            foreach ($result->BirdTypes as $bird_type):
              $attracts[] = '<a href="#">' . $bird_type['name'] . '</a>';
            endforeach;
            print implode(', ', $attracts); ?>
          </div>
          <div class="plant--add-to-list">
            <input type="checkbox" id="checkbox-f<?php print $result->PlantID; ?>-s" class="np-checkbox"/>
            <label for="checkbox-f<?php print $result->PlantID; ?>-s"><?php print t('Add to your plant list'); ?></label>
          </div>
        </div>
      </div>
    <?php endforeach; ?>
    </div>

    <div class="columns">
      <div class="search-results-total hide-for-tiny hide-for-small">
        <div class="column medium-4">
          <strong><?php print t('Results'); ?>:</strong> <?php print format_plural($view->query->pager->total_items, '1 plant', '@count plants'); ?>
        </div>
        <div class="column medium-8">
          <div class="pager">
            <span class="pager-prev">Previous page</span>
                <span class="pager-inner">
                  <span>1</span>
                  <a href="#">2</a>
                  <a href="#">3</a>
                  <a href="#">4</a>
                  <a href="#">5</a>
                  <a href="#">6</a>
                  <a href="#">7</a>
                  <a href="#">8</a>
                  <a href="#">9</a>
                  <span>...</span>
                  <a href="#">14</a>
                </span>
            <a href="#" class="pager-next">Next page</a>
          </div>
        </div>
      </div>
    </div>

    <div class="search-results-total hide-for-medium hide-for-large hide-for-xlarge row">
      <div class="pager">
        <span class="pager-prev">Previous page</span>
        <a href="#" class="pager-next">Next page</a>
      </div>
    </div>
  </div>
</div>
