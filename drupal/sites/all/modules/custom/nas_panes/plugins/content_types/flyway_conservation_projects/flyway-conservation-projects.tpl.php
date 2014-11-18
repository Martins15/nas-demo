<?php
/**
 * @file
 * Template to custom pane flyway_in_the_news.
 *
 * Available variables:
 *  $contextual_links - contextual links.
 *  $title - pane's title.
 *  $more_link - link to flyway news listing.
 *  $teasers - array of rendered news.
 */
?>

<div class="card-set contextual-links-region">
  <?php print $contextual_links; ?>
  <div class="row section-header">
    <div class="column">
      <h2 class="thin"><?php print $title; ?>Conservation Projects in the Atlantic Flyway</h2>
    </div>
    <div class="column">
      <ul class="section-nav inline-list">
        <li><?php print $more_link; ?> <a href="#">More Projects »</a></li>
      </ul>
    </div>
  </div>
  <div class="row card-set-wrapper">
    <div class="clearfix card-set-scroller">
      <?php foreach ($teasers as $teaser): ?>
      <div class="tiny-4 columns">
        <div class="editorial-card" style="min-height: 368px;">
          <div class="editorial-card-photo">
            <a href="#"><img src="../../img/editorial-card-10.jpg" alt=""></a>
          </div>
          <div class="editorial-card-content">
            <a href="#" class="editorial-card-slug">Seas &amp; Shores</a>
            <h4 class="editorial-card-title"><a href="#">Here’s the Name of a Conservation Project</a></h4>
            <p>Along with the title, we should include a short description of the project. </p>
          </div>
        </div>
      </div>
      <?php endforeach; ?>
    </div>
  </div>
  <div class="row space-bottom double">
    <div class="card-set-dots">
      <div class="dot active"></div>
      <div class="dot"></div>
      <div class="dot"></div>
    </div>
  </div>
</div>
