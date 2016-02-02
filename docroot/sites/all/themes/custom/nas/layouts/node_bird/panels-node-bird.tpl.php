<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<?php print $content['header']; ?>
<section <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?> class="global-content no-padding">
  <div class="bird-guide-container hero large">
    <div class="bird-guide-image">
      <?php print $content['top']; ?>
    </div>
    <?php print $content['main']; ?>
  </div>
  <?php if (!empty($content['in_action_left'])): ?>
  <div id="in-action">
    <div class="row section-header">
      <?php print $content['in_action_top']; ?>
    </div>
    <div class="row">
      <div class="large-8 columns">
        <figure class="article-video">
          <div class="article-video-container">
            <?php print $content['in_action_left']; ?>
          </div>
        </figure>
      </div>
      <div class="large-4 columns">
        <?php print $content['in_action_right']; ?>
      </div>
      <div class="columns hide-for-medium hide-for-large hide-for-xlarge">
        <br>
        <hr class="hide-for-medium hide-for-large hide-for-xlarge">
      </div>
    </div>
  </div>
  <?php endif; ?>
  <?php if (!empty($content['focal_bird_map'])): ?>
    <div class="focal-bird-map">
      <?php print $content['focal_bird_map']; ?>
    </div>
  <?php endif; ?>
  <div id="in-the-news">
    <?php print $content['in_the_news']; ?>
  </div>

  <div id="across-audubon">
    <?php print $content['across_audubon']; ?>
  </div>
</section>
<?php print $content['similar_birds']; ?>
<section class="card-set bg-1">
  <?php print $content['card_set']; ?>
</section>
