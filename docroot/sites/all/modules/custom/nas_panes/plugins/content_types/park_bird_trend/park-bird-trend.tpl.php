<?php

/**
 * @file
 * Template for Native Plants bar.
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
                    <li class="tabs-content__link link columns large-3"
                        data-tab="display-<?php print $tab ?>">
                      <p class="link__title"><?php print $data['title'] ?></p>
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
    </div>
  </div>
</div>