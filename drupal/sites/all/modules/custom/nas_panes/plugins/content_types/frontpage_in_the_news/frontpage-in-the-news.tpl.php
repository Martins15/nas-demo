<?php
/**
 * @file
 * Custom view template to display Frontpage Bird in the News.
 *
 * Available variables:
 * - $contextual_links: contextual links.
 * - $background_image: url to background image.
 * - $bird_guide_link: url to Bird Guide.
 * - $bird_guide_title: title of the Bird Guide link.
 */
?>

<div class="row section-header">
  <div class="columns">
    <h2 class="thin"><?php print $title; ?></h2>
  </div>
  <div class="columns">
    <ul class="section-nav inline-list">
      <li class="hide-for-small hide-for-tiny"><a href="<?php print $bird_guide_link; ?>"><?php print $bird_guide_title; ?></a></li>
      <li><a class="cta" href="#">Adopt a Bird</a></li>
    </ul>
  </div>
</div>
<div class="row bird-card-container">
  <div class="bird-card-scroller">
    <?php for ($i = 0; $i < 4; $i++): ?>
    <?php if (!isset($teasers[$i])) { continue; } ?>
    <div class="columns tiny-3">
      <?php print $teasers[$i]['bird']; ?>
      <?php if (!empty($teasers[$i]['blue_link_url'])): ?>
      <a href="<?php print $teasers[$i]['blue_link_url']; ?>" class="editorial-card-slug"><?php print $teasers[$i]['blue_link_text']; ?></a>
      <?php endif; ?>
      <h4 class="editorial-card-title"><a href="<?php print $teasers[$i]['article_url']; ?>"><?php print $teasers[$i]['article_title']; ?></a></h4>
    </div>
    <?php endfor; ?>
  </div>
</div>


