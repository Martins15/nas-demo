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

<div class="flyway-slides">
  <div class="flyway-slides-container">
    <?php for ($i = 1; $i <= NAS_FLYWAYS_NUMBER; $i++): ?>
    <div id="<?php print $flyway[$i]['name_id']; ?>-slide" class="flyway-slide">
      <div class="row section-header">
        <div class="column">
          <h1><?php print $flyway[$i]['name']; ?></h1>
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
        <div class="columns large-4">
          <div class="editorial-card collapse-minimal">
            <div class="editorial-card-photo">
              <img src="../../img/editorial-card-1.jpg">
            </div>
            <div class="editorial-card-content short">
              <a href="#" class="editorial-card-slug">Priority Birds</a>
              <h4 class="editorial-card-title"><a href="#">Greater Sage Grouse</a></h4>
              <p>The flyway is home to 17 Priority Bird species, depend on a wide range of habitats.</p>
            </div>
          </div>
        </div>
        <div class="columns large-4">
          <div class="editorial-card collapse-minimal">
            <div class="editorial-card-photo">
              <img src="../../img/editorial-card-2.jpg">
            </div>
            <div class="editorial-card-content short">
              <a href="#" class="editorial-card-slug">Important Bird Areas</a>
              <h4 class="editorial-card-title"><a href="#">Aiken Canyon Preserve</a></h4>
              <p>The United States region of the Central Flyway is home to 65 global Important Bird Areas.</p>
            </div>
          </div>
        </div>
        <div class="columns large-4">
          <div class="editorial-card collapse-minimal">
            <div class="editorial-card-photo">
              <img src="../../img/editorial-card-3.jpg">
            </div>
            <div class="editorial-card-content short">
              <a href="#" class="editorial-card-slug">In The News</a>
              <h4 class="editorial-card-title"><a href="#">Improving the Health of Rivers in the Mid-Atlantic</a></h4>
              <p>April 23, 2014</p>
            </div>
          </div>
        </div>
      </div>
    </div>
    <?php endfor; ?>
  </div>
  <a href="#" class="flyway-slides-paddle prev"></a>
  <a href="#" class="flyway-slides-paddle next"></a>
</div>
