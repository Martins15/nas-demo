<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<header class="global-header <?php print drupal_static('nas_header_class'); ?>">
  <?php print $content['top']; ?>
</header>
<?php print $content['featured_top']; ?>
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
  </section>
</section>
<?php print $content['footer']; ?>