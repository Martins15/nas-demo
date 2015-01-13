<?php
/**
 * @file
 * Frontpage conservation section. Full bg area template file.
 *
 * Available variables:
 * - $image_path: path to the hero image.
 * - $contextual_links: rendered contextual links.
 * - $content: array of titles, links, texts.
 * -
 */
?>
<section class="breakout-section <?php print $color_mode == 'dark' ? 'black-bg' : ''; ?> contextual-links-region">
  <?php print $contextual_links; ?>
  <div class="breakout-section-hero margin-bottom" style="background-image: url(<?php print $image_path; ?>)">
    <div class="row">
      <div class="column">
        <h1 class="breakout-section-headline"><?php print $title; ?></h1>
      </div>
    </div>
  </div>
  <div class="breakout-section-content <?php print $text_color; ?>-text">
    <div class="row">
      <?php foreach ($content as $item) : ?>
      <div class="columns medium-4">
        <div class="editorial-card <?php print $color_mode; ?> no-border">
          <div class="editorial-card-content">
            <a href="<?php print $item['top_link']['url']; ?>" class="editorial-card-slug"><?php print $item['top_link']['title']; ?></a>
            <a href="<?php print $item['node_url']; ?>">
              <h4 class="editorial-card-title"><?php print $item['title']; ?></h4>
            </a>
            <?php print $item['text']; ?>
            <?php if (!empty($item['bot_link']['url']) && !empty($item['bot_link']['title'])) : ?>
              <p><a href="<?php print $item['bot_link']['url']; ?>" class="editorial-card-link sans"><?php print $item['bot_link']['title']; ?></a></p>
            <?php endif; ?>
          </div>
        </div>
      </div>
      <?php endforeach; ?>
    </div>
  </div>
</section>
