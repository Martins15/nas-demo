<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<?php print render($content['top']); ?>
<?php print render($content['menu_bar']); ?>

<section class="global-content getoutside">
  <?php print render($content['main']); ?>

  <?php if (!empty($content['bird_guide'])): ?>
    <div class="bird-card-set bg-bone-white">
      <?php print render($content['bird_guide']); ?>
    </div>
  <?php endif; ?>

  <?php if (isset($asc_landing_page_sidebar_title) && $asc_landing_page_sidebar_title): ?>
    <div class="row space-top">
      <div class="column section-header">
        <h2 class="thin"><?php print $asc_landing_page_sidebar_title; ?></h2>
      </div>
    </div>
  <?php endif; ?>
  <?php if (!empty($content['sidebar_left'])): ?>
    <div class="row<?php print empty($asc_landing_page_sidebar_title) ? ' space-top' : ''; ?>">
      <div class="large-8 columns index-list">
        <?php print render($content['sidebar_left']); ?>
      </div>
      <div class="sidebar large-4 columns">
        <?php if (!empty($content['sidebar_right'])):
          print render($content['sidebar_right']);
        endif; ?>
      </div>
    </div>
  <?php endif; ?>

  <section class="card-set bg-1">
    <?php print render($content['cards']); ?>
  </section>
</section>
