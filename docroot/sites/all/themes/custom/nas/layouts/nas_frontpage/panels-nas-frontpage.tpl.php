<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<section class="curtain" style="background-color: #fff; background-image: url(<?php print !empty($frontpage_backgroundimage) ? $frontpage_backgroundimage : ''; ?>)">
  <header class="global-header transparent dark-text light-bg">
    <?php print $content['header']; ?>
  </header>
  <?php print $content['featured_top']; ?>
</section>
<div class="curtain-wrapper">
  <header class="global-header standard">
    <?php print $content['top']; ?>
  </header>
  <section class="global-content">
    <?php if (!empty($featured_frontpage_mobile_content)): ?>
      <?php print $featured_frontpage_mobile_content; ?>
    <?php endif; ?>
    <div class="homepage-first-row row space-top double" data-equalizer>
      <?php print $content['featured']; ?>
      <div class="columns large-4 medium-6">
        <?php print $content['more_headlines']; ?>
      </div>
    </div>
    <?php print $content['editorial_cards']; ?>
    <?php print $content['conservation_section']; ?>
    <?php print $content['bird_news']; ?>
    <?php print $content['main']; ?>
    <section class="card-set bg-1">
      <?php print $content['cards_set']; ?>
      <div class="row">
        <div class="card-set-social social-sharing">
          <span class="social-sharing-caption white">Spread the word. It&rsquo;s the least you can do.</span>
          <a class="social-sharing-icon white" href="#"><i class="icon-twitter"></i></a>
          <a class="social-sharing-icon white" href="#"><i class="icon-facebook"></i></a>
          <a class="social-sharing-icon white" href="#"><i class="icon-mail"></i></a>
        </div>
      </div>
    </section>
  </section>
</div>
