<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 */
?>

<header class="<?php print $header_classes; ?>">
  <div class="row">
    <div class="columns">
      <?php print l(t('Audubon'), '<front>', array('attributes' => array('class' => array('current-parent', 'wordmark')))); ?>
      <!-- Only visible on small and medium screens -->
      <a href="#" class="icon-menu header-btn header-btn-menu"></a>
      <a href="#" class="icon-binoculars header-btn header-btn-search-alt toggle-bird-guide-search"></a>
      <!-- / -->
      <?php print render($page['header']); ?>
    </div>
  </div>
</header>

<div class="row">
  <div class="columns">
    <?php print $breadcrumb; ?>
    <?php if ($title): ?>
      <?php print $title; ?>
    <?php endif; ?>
    <?php if ($tabs): ?>
      <div class="tabs"><?php print render($tabs); ?></div>
    <?php endif; ?>
    <?php print $messages; ?>
    <?php print render($page['help']); ?>
  </div>
</div>
<?php print render($page['content']); ?>
<?php if ($page['footer']): ?>
  <footer class="global-footer">
    <?php print render($page['footer']); ?>
  </footer>
<?php endif; ?>
