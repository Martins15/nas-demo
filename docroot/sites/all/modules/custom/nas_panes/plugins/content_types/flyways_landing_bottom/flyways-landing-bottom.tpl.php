<?php
/**
 * @file
 * Featured Bird template file.
 *
 * Available variables:
 * - $hero_image: big image at the top.
 * - $title: title.
 * - $subtitle: subtitle under the title.
 * - $flyway[1-4]: array with values for the slide.
 */
?>
<section class="category-nav strip-nav">
  <div class="row">
    <div class="columns">
      <ul class="inline-list">
        <?php for ($i = 1; $i <= NAS_FLYWAYS_NUMBER; $i++): ?>
        <li><a class="flyway-slide-button<?php if ($i == 1 ): ?> current<?php endif; ?>" href="#<?php print $flyway[$i]['name_id']; ?>-slide"><?php print $flyway[$i]['name']; ?></a></li>
        <?php endfor; ?>
      </ul>
    </div>
  </div>
</section>

<div class="flyway-slides contextual-links-region">
  <?php print $contextual_links; ?>
  <div class="flyway-slides-container">
    <?php for ($i = 1; $i <= NAS_FLYWAYS_NUMBER; $i++): ?>
    <div id="<?php print $flyway[$i]['name_id']; ?>-slide" class="flyway-slide<?php if ($i == 1 ): ?> current<?php endif; ?>">
      <div class="row section-header">
        <div class="column">
          <h1><a href="<?php print $flyway[$i]['summary_more_link_uri']; ?>"><?php print $flyway[$i]['name']; ?></a></h1>
        </div>
        <div class="column">
          <ul class="inline-list section-nav">
            <li>
              <a href="<?php print $flyway[$i]['top_right_link_uri']; ?>"><?php print $flyway[$i]['top_right_link_title']; ?></a><br>
              <?php print $flyway[$i]['text_under_top_right_link']; ?>
            </li>
          </ul>
        </div>
      </div>
      <div class="row">
        <div class="column">
          <p><?php print $flyway[$i]['summary']; ?>
            <a href="<?php print $flyway[$i]['summary_more_link_uri']; ?>">Learn More »</a></p>
        </div>
      </div>
      <div class="row space-top space-bottom">
        <?php print $flyway[$i]['news_teasers']; ?>
      </div>
    </div>
    <?php endfor; ?>
  </div>
  <a href="#" class="flyway-slides-paddle prev"></a>
  <a href="#" class="flyway-slides-paddle next"></a>
</div>
