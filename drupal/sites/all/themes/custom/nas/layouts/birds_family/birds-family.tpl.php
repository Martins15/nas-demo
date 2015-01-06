<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>

<div class="guide-bar">
  <div class="row">
    <div class="column">
      <h2 class="guide-bar-title"><span class="hide-for-small hide-for-tiny">Guide to </span>North American Birds</h2>
      <div class="guide-bar-attribution"><span class="preamble">Brought to you by</span><img class="canon-logo" src="<?php print base_path() . path_to_theme() . '/img/canon-logo.png'; ?>"></div>
    </div>
  </div>
</div>

<section class="global-content birds-family-section">
  <div class="row column">
    <div class="common-name">
      <?php print $content['title']; ?>
    </div>
    <div class="scientific-name">
      <?php print $content['scientific_name']; ?>
    </div>
    <div class="family-description">
      <?php print $content['description']; ?>
    </div>
  </div>
  <div class="bird-card-grid">
    <?php print $content['main']; ?>
    <div class="row space-bottom"></div>
  </div>

  <section class="card-set bg-1">
    <?php print $content['cards']; ?>
    <div class="row">
      <div class="card-set-dots light">
        <div class="dot active"></div>
        <div class="dot"></div>
        <div class="dot"></div>
      </div>
    </div>
  </section>
</section>
