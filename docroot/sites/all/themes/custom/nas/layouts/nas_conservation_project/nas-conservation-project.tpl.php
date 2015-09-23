<?php
/**
 * @file
 * Template implementation to display the panel's layout.
 *
 * Custom variables:
 * $color_mode_gradient string - Used as class for hero tag.
 * $color_mode_text string - Used as class for hero tag.
 */
?>

<div class="hero <?php print !empty($color_mode_gradient) ? $color_mode_gradient : 'dark'; ?>-gradient <?php print !empty($color_mode_text) ? $color_mode_text : 'light'; ?>-text">
  <div class="hero-image">
    <?php print $content['hero_image']; ?>
  </div>
  <div class="row">
    <div class="hero-header">
      <div class="column">
        <?php print $content['strategy_icon']; ?>
        <h4 class="hero-slug"><?php print $content['strategy']; ?></h4>
        <h2 class="hero-title big<?php if ($content['strategy_icon']): ?> with-icon<?php endif; ?>"><?php print $content['title']; ?></h2>
        <p class="hero-blurb<?php if ($content['strategy_icon']): ?> with-icon<?php endif; ?>"><?php print $content['subtitle']; ?></p>
      </div>
    </div>
  </div>
</div>
<div class="hero-attribution row">
  <?php if (trim($content['hero_attribution'])): ?>
    <p class="column"><span class="hero-attribution-text extra"><?php print $content['hero_attribution']; ?></span></p>
  <?php endif; ?>
</div>
<section class="global-content with-padding">
  <div class="row">
    <div class="large-8 columns text-container">
      <?php print $content['body']; ?>
    </div>
    <div class="large-4 columns sidebar">
      <section class="sidebar-section">
        <?php if (!empty($page_link)): ?>
        <div class="social-sharing align-right">
          <span class="social-sharing-caption small"><?php print t('Share this project'); ?></span>
            <a target="_blank" href="<?php print $twitter_url; ?>" class="social-sharing-icon blue small"><i class="icon-twitter"></i></a>
            <a target="_blank" href="http://www.facebook.com/sharer/sharer.php?u=<?php print $page_link; ?>" class="social-sharing-icon blue small"><i class="icon-facebook"></i></a>
            <a href="mailto:?subject=<?php print $page_title; ?>&body=<?php print $page_link; ?>" class="social-sharing-icon blue small"><i class="icon-mail"></i></a>
        </div>
        <?php endif; ?>
      </section>
      <div class="row">
        <?php print $content['right']; ?>
      </div>
    </div>
  </div>
  <?php print $content['bottom']; ?>

  <section class="card-set bg-1">
    <?php print $content['cards_set']; ?>
  </section>
</section>
