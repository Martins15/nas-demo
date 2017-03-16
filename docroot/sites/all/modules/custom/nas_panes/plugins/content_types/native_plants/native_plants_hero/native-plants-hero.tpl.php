<?php

/**
 * @file
 * Native Plants hero template.
 */
?>
<div class="bg-respond hero small<?php print !empty($context_links) ? ' contextual-links-region' : ''; ?> <?php print $classes; ?>">
  <?php print $context_links; ?>
  <div class="hero-image">
    <img src="<?php print $image_path; ?>" alt="" >
  </div>
  <div class="row">
    <div class="hero-header hide-for-medium hide-for-small hide-for-tiny">
      <div class="columns large-9">
        <h1 class="hero-title"><?php print $title_desktop; ?></h1>
      </div>
    </div>
    <?php if (!$title_mobile_shift): ?>
      <div class="hero-header hide-for-large hide-for-xlarge">
        <div class="columns">
          <h1 class="hero-title"><?php print $title_mobile; ?></h1>
        </div>
      </div>
    <?php endif; ?>
  </div>
</div>
<div class="hero-attribution">
  <p class="column">
    <span class="hero-attribution-text"><?php print $image_attribution; ?></span>
  </p>
</div>
<?php if ($title_mobile_shift): ?>
  <header class="row hide-for-large hide-for-xlarge space-top">
    <div class="large-12 large-centered columns">
      <div class="clearfix">
        <h1 style="margin:0;"><?php print $title_mobile; ?></h1>
      </div>
    </div>
  </header>
<?php endif; ?>
