<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>

<?php print $content['header']; ?>
<div class="guide-bar">
  <div class="row">
    <div class="column">
      <h2 class="guide-bar-title"><span class="hide-for-small hide-for-tiny">Guide to </span>North American Birds</h2>
      <div class="guide-bar-attribution"><span class="preamble">Brought to you by</span><img class="canon-logo" src="<?php print base_path() . path_to_theme() . '/img/canon-logo.png'; ?>"></div>
    </div>
  </div>
</div>

<section class="global-content">
  <div class="bird-card-grid">
    <?php print $content['main']; ?>
    <div class="row space-bottom"></div>
  </div>

  <section class="card-set bg-1">
    <?php print render($content['cards']); ?>
    <div class="row">
      <div class="card-set-social social-sharing">
        <span class="social-sharing-caption white">Spread the word. It’s the least you can do.</span>
        <a class="social-sharing-icon white" href="#"><i class="icon-twitter"></i></a>
        <a class="social-sharing-icon white" href="#"><i class="icon-facebook"></i></a>
        <a class="social-sharing-icon white" href="#"><i class="icon-mail"></i></a>
      </div>
    </div>
  </section>
</section>
