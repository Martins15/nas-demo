<?php
/**
 * @file
 * Template implementation to display BOA layout.
 */
?>
<?php print $content['header']; ?>
</header>
<section class="global-content no-padding">
  <div class="bird-guide-container hero large">
    <?php print $content['hero']; ?>
    <div class="row">
      <div class="column">
        <div class="bird-guide-card">
          <section class="bird-guide-body">
            <div class="row">
              <div class="large-8 columns">
                <?php print $content['main']; ?>
              </div>
              <div class="large-4 columns">
                <?php print $content['sidebar']; ?>
              </div>
            </div>
          </section>
        </div>
      </div>
    </div>
  </div>
  <?php print $content['footer']; ?>
</section>
