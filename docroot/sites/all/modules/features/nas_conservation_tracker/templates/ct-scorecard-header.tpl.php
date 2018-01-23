<?php
/**
 * TPL file for CT content type.
 */
?>
<div class="ct-scorecard-header bg-respond hero small dark-gradient light-text">
  <div class="hero-image">
    <?php print $image; ?>
  </div>
  <div class="curtain-content">
    <div class="row">
      <div class="hero-header">
        <div class="columns large-12 large-centered">
          <h1 class="hero-title"><?php print $name; ?></h1>
          <p class="hero-blurb"><?php print $subtitle; ?></p>
        </div>
      </div>
      <div class="hero-attribution">
        <p class="column">
          <span class="hero-attribution-text"><?php print $credit; ?></span>
        </p>
      </div>
    </div>
    <div class="curtain-arrow storecard"></div>
  </div>
</div>
