<?php

/**
 * @file
 * Template implementation to display the FPP layout.
 *
 * Custom variables:
 * - $banner_slug: Link from field_link field.
 * - $banner_title: Title of FPP.
 * - $banner_links: Links from field_links field (multiple).
 * - $banner_summary: Text from field_summary field.
 *
 * @see template_preprocess_fieldable_panels_pane()
 */
?>
<div class="large-6 columns <?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="banner dark-bg bg-respond" style="background-image: url(<?php print $banner_image; ?>);" data-bg-small="<?php print $banner_image; ?>" data-bg-large="<?php print $banner_image; ?>">
    <div class="banner-text">
      <?php print $banner_slug; ?>
      <h2 class="banner-title"><?php print $banner_title; ?></h2>
      <p class="banner-blurb"><?php print $banner_summary; ?></p>
      <?php print $banner_links; ?>
    </div>
  </div>
</div>
