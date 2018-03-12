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
            <?php foreach ($content as $season => $tabs): ?>
              <li class="tab-slider--trigger"
                  rel="season_<?php print $season ?>"><?php print $season ?></li>
            <?php endforeach; ?>
          </ul>
        </div>
        <div class="tab-slider--container">
          <?php foreach ($content as $season => $tabs): ?>
            <div id="season_<?php print $season ?>"
                 class="tab-slider--body <?php print $season ?>-tab">
              <div class="container-data-tabs">
                <ul class="tabs-content">
                  <?php foreach ($tabs['tabs'] as $tab => $data): ?>
                    <li class="tabs-content__link link columns large-4 <?php print $tab ?>"
                        data-tab="display-<?php print $tab ?>">
                      <p class="link__title"><?php print $data['title'] ?> <i class="tooltip">i<span class="tooltiptext">Tooltip text</span></i></p>
                      <p class="link__number"><?php print $data['amount'] ?></p>
                    </li>
                  <?php endforeach; ?>
                </ul>

                <?php foreach ($tabs['tabs'] as $tab => $data): ?>
                  <div data-content="display-<?php print $tab ?>"
                       class="tab-content">
                    <?php print $data['desc'] ?>
                  </div>
                <?php endforeach; ?>
              </div>
            </div>
          <?php endforeach; ?>
          <?php print $view ?>
        </div>
      </div>
        <div class="parks_blog">
            <div class="cell" id="chart"></div>
        </div>
        <script>

          let birdDot = new StamenAudubonParks.BirdDots({
            element: '#chart',
            currentCounter: '#season_summer .current .link__number',
            colonizedCounter: '#season_summer .extirpations .link__number',
            extirpatedCounter: '#season_summer .colonizations .link__number',
            dataUrl: 'sites/all/modules/features/nas_park_feature/csv/filtered_turnover_counts_53parks.csv',
            park: 'Everglades National Park',
            season: 'summer',
            initStats: false,
            onLoad: () => {
            birdDot.animateIn(initUI)
          }
          });

          function initUI() {
            d3.select('.tabs-content__link.current').classed('selected', true);
            d3.select('.tabs-content__link.extirpations').classed('selected', false);
            d3.select('.tabs-content__link.colonizations').classed('selected', false);
            birdDot.setCurrent();
            //d3.select('.content').text('current birds');

            //   d3.select('#stats-1').on('click', () => {
            //     d3.select('#stats-1').classed('selected', true);
            //   d3.select('#stats-2').classed('selected', false);
            //   d3.select('#stats-3').classed('selected', false);
            //   birdDot.setCurrent();
            //   d3.select('.content').text('current birds');
            // });
            //
            //   d3.select('#stats-2').on('click', () => {
            //     d3.select('#stats-1').classed('selected', false);
            //   d3.select('#stats-2').classed('selected', true);
            //   d3.select('#stats-3').classed('selected', false);
            //   birdDot.setColonized();
            //   d3.select('.content').text('colonized birds');
            // });
            //
            //   d3.select('#stats-3').on('click', () => {
            //     d3.select('#stats-1').classed('selected', false);
            //   d3.select('#stats-2').classed('selected', false);
            //   d3.select('#stats-3').classed('selected', true);
            //   birdDot.setExtirpated();
            //   d3.select('.content').text('extirpated birds');
            // });

            //   d3.selectAll("input").on("change", () => {
            //     let season = d3.select('input[name=season]:checked').attr('value')
            //     birdDot.setSeason(season);
            // });
          }

          //
        </script>
    </div>
  </div>
</div>
