<?php
/**
 * @file
 * Conservation landing. Full bg area template file.
 *
 * Available variables:
 * - $image_path: path to the hero image.
 * - $contextual_links: rendered contextual links.
 * - $text_array: array of titles, links, texts.
 */
?>
<section class="breakout-section black-bg contextual-links-region">
  <?php print $contextual_links; ?>
  <div class="breakout-section-hero margin-bottom" style="background-image: url(<?php print $image_path; ?>)">
    <div class="row">
      <div class="column">
        <h1 class="breakout-section-headline centered"><?php print $title; ?></h1>
      </div>
    </div>
  </div>
  <div class="breakout-section-content">
    <div class="row">
      <?php foreach ($text_array as $value) : ?>
      <div class="columns medium-4">
        <div class="editorial-card dark no-border">
          <div class="editorial-card-content">
            <a href="<?php print $value['top_link']['url']; ?>" class="editorial-card-slug"><?php print $value['top_link']['title']; ?></a>
            <a href="<?php print $value['bot_link']['url']; ?>">
              <h4 class="editorial-card-title"><?php print $value['title']; ?></h4>
            </a>
            <?php print $value['text']['value']; ?>
            <p><a href="<?php print $value['bot_link']['url']; ?>" class="editorial-card-link sans"><?php print $value['bot_link']['title']; ?></a></p>
          </div>
        </div>
      </div>
      <?php endforeach; ?>
    </div>
  </div>
</section>
