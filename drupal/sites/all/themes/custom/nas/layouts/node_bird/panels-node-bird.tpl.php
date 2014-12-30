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
  <div id="in-the-news">
    <?php print $content['in_the_news']; ?>
  </div>
  <div id="across-audubon">
    <?php print $content['across_audubon']; ?>
  </div>
</section>

<section class="card-set bg-1">
  <?php print $content['card_set']; ?>
  <div class="row">
    <div class="card-set-social social-sharing">
      <span class="social-sharing-caption white">Spread the word. It&rsquo;s the least you can do.</span>
      <a class="social-sharing-icon white" href="#"><i class="icon-twitter"></i></a>
      <a class="social-sharing-icon white" href="#"><i class="icon-facebook"></i></a>
      <a class="social-sharing-icon white" href="#"><i class="icon-mail"></i></a>
    </div>
  </div>
</section>
