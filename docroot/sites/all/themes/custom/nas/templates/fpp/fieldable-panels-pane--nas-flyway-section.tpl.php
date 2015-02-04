<?php

/**
 * @file
 * Template implementation to display the FPP layout.
 *
 * Custom variables:
 * - $links: Top links.
 * @see template_preprocess_fieldable_panels_pane()
 */
?>
<div class="breakout-section no-hero contextual-links-region" style="background-image: none; background-color: #444444;" data-background="<?php print $hero_image; ?>">
  <?php print $contextual_links; ?>
  <div class="breakout-section-content light-text">
    <div class="row space-top space-bottom double">
      <div class="columns large-4">
        <h5 class="close-heading"><?php print t('You are a part of the'); ?></h5>
        <h1 class="thin"><?php print $title; ?></h1>
        <p><em><?php print $flyway_description; ?></em></p>
        <br>
        <div class="editorial-card dark no-border">
          <div class="editorial-card-content">
            <h4 class="editorial-card-title blue"><?php print $about_link; ?></h4>
            <p><?php print $about_the_flyways; ?></p>
            <br>
            <em><?php print $learn_more; ?></em>
          </div>
        </div>
      </div>
      <div class="columns large-4">
       &nbsp;
      </div>
      <div class="columns large-4">
        <div class="breakout-section-box">
          <?php print $image; ?>
          <br>
          <p class="serif"><em><?php print $flyway_includes; ?></em></p>
        </div>
      </div>
    </div>
  </div>
</div>
