<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<section <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?> class="global-content no-padding">
  <div class="bird-guide-container hero large">
    <div class="bird-guide-image">
      <?php print $content['top']; ?>
    </div>
    <?php print $content['main']; ?>
  </div>
  <?php print $content['similar_birds']; ?>
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
</section>
