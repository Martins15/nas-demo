<?php
/**
 * @file
 * Template for Native Plants initial form pane.
 */
?>
<div class="bg-respond hero small native-plants-hero<?php print !empty($context_links) ? ' contextual-links-region' : ''; ?> <?php print $classes; ?>">
  <?php print $context_links; ?>
  <div class="hero-image">
    <img src="<?php print $image_path; ?>" alt="" >
  </div>

  <div class="row">
    <div class="hero-header">
      <h1 class="native-plants-hero-title hero-title column hide-for-medium hide-for-small hide-for-tiny"><?php print $title_desktop; ?></h1>
      <h1 class="native-plants-hero-title hero-title column hide-for-large hide-for-xlarge"><?php print $title_mobile; ?></h1>
      <!-- search form-->
      <div class="columns">
        <?php print $form; ?>
      </div>
      <!-- /search form-->

      <div class="native-plants-hero-text columns large-9 large-centered hide-for-medium hide-for-small hide-for-tiny">
        <?php print $description; ?>
      </div>
    </div>
  </div>
</div>

<div class="native-plants-hero-text row column hide-for-large hide-for-xlarge">
  <?php print $description; ?>
</div>

<div class="hero-attribution">
  <p class="column">
    <span class="hero-attribution-text"><?php print $image_attribution; ?></span>
  </p>
</div>
