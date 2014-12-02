<?php
/**
 * @file
 * Conservation Strategy Projects template file.
 */
?>

<section class="card-set bg-gray">
  <div class="row space-top">
    <div class="column">
      <h2 class="thin"><?php print $title; ?></h2>
    </div>
  </div>
  <div class="row card-set-wrapper contextual-links-region">
    <?php print $contextual_links; ?>
    <div class="clearfix card-set-scroller">
      <div class="tiny-4 columns">
        <div class="editorial-card">
          <div class="editorial-card-photo">
            <a href="#"><img src="/<?php print drupal_get_path('theme', 'nas') . '/img/editorial-card-10.jpg'; ?>" alt=""></a>
          </div>
          <div class="editorial-card-content">
            <h3 class="editorial-card-title"><a href="#">Here’s the Name of a Conservation Project</a></h3>
            <p>Along with the title, we should include a short description of the project. </p>
          </div>
        </div>
      </div>
      <div class="tiny-4 columns">
        <div class="editorial-card">
          <div class="editorial-card-photo">
            <a href="#"><img src="/<?php print drupal_get_path('theme', 'nas') . '/img/editorial-card-11.jpg'; ?>" alt=""></a>
          </div>
          <div class="editorial-card-content">
            <h3 class="editorial-card-title"><a href="#">Another Current Seas &amp; Shores Project</a></h3>
            <p>Along with the title, we should include a short description of the project. </p>
          </div>
        </div>
      </div>
      <div class="tiny-4 columns">
        <div class="editorial-card">
          <div class="editorial-card-photo">
            <a href="#"><img src="/<?php print drupal_get_path('theme', 'nas') . '/img/editorial-card-12.jpg'; ?>" alt=""></a>
          </div>
          <div class="editorial-card-content">
            <h3 class="editorial-card-title"><a href="#">Another Current Seas &amp; Shores Project</a></h3>
            <p>Along with the title, we should include a short description of the project. </p>
          </div>
        </div>
      </div>
    </div>
  </div>
  <div class="row space-bottom double">
    <div class="card-set-dots">
      <div class="dot"></div>
      <div class="dot active"></div>
      <div class="dot"></div>
    </div>
  </div>
</section>
