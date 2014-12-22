<?php
/**
 * @file
 * Local Chapters & Centers template file.
 */
?>

<section class="sidebar-section medium-6 large-12 columns">
  <div class="sidebar-section editorial-card <?php print !empty($contextual_links) ? 'contextual-links-region' : ''; ?>">
    <?php print $contextual_links; ?>

    <div class="editorial-card-photo">
      <a href="#"><img src="<?php print base_path() . drupal_get_path('theme', 'nas') . '/img/'; ?>editorial-card-13.jpg" alt=""></a>
    </div>
    <div class="editorial-card-banner green"><i class="icon-map"></i> <?php print $title; ?></div>
    <div class="editorial-card-content">
      <ul class="no-bullets item-margin">
        <li>
          <h5 class="editorial-card-title blue close-heading"><a href="#">Anchorage Audubon Society</a></h5>
          <small>(Anchorage, AK)</small>
        </li>
        <li>
          <h5 class="editorial-card-title blue close-heading"><a href="#">Arctic Audubon Society</a></h5>
          <small>(Fairbanks, AK)</small>
        </li>
        <li>
          <h5 class="editorial-card-title blue close-heading"><a href="#">Kodiak Audubon Society</a></h5>
          <small>(Kodiak, AK)</small>
        </li>
      </ul>
      <hr />
      <a href="#" class="editorial-card-link sans">See all</a>
    </div>
  </div>
</section>
