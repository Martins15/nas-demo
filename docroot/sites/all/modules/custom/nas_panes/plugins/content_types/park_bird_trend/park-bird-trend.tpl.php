<?php

/**
 * @file
 * Template for Park Bird trend.
 */
?>
<div class="<?php print !empty($context_links) ? 'contextual-links-region' : ''; ?>">
  <?php print $context_links; ?>
  <div class="row">
    <div class="switch-wrap">
      <div class="container">

        <div class="tab-slider--nav">
          <ul class="tab-slider--tabs">
            <?php foreach ($content as $season => $item): ?>
              <li class="tab-slider--trigger"
                  rel="season_<?php print $season ?>"><?php print $season ?></li>
            <?php endforeach; ?>
          </ul>
        </div>
        <div class="tab-slider--container">

            <div id="season_summer" class="season-wrapper tab-slider--body">
              <div class="container-data-tabs">
                <ul class="tabs-content">
                  <?php foreach ($tabs as $tab => $title): ?>
                    <li class="tabs-content__link link columns large-4 <?php print $tab ?>"
                        data-tab="display-<?php print $tab ?>">
                      <p class="link__title"><?php print $title ?> <i class="tooltip">i<span class="tooltiptext">Tooltip text</span></i></p>
                      <p class="link__number">0</p>
                    </li>
                  <?php endforeach; ?>
                </ul>
                <?php foreach ($content as $season => $items): ?>
                  <?php foreach ($items['tabs'] as $tab => $data): ?>
                  <div data-content="display-<?php print $tab ?>" data-amount="<?php print $data['amount'] ?>"
                       class="tab-content tab-season-<?php print $season;?>">
                    <?php print $data['desc'] ?>
                  </div>
                  <?php endforeach; ?>
                <?php endforeach; ?>
              </div>
            </div>

          <?php print $view ?>
        </div>
      </div>
      <div class="parks_blog">
        <div class="cell" id="chart"></div>
      </div>
    </div>
  </div>
</div>