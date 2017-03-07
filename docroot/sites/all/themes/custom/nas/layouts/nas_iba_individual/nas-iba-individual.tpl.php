<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<section class="global-content with-padding static-page-content">
  <header class="row">
    <div class="large-10 columns">
    <?php print l(t('Important Bird Areas'), 'iba', array('attributes' => array('class' => array('article-slug')))); ?>
    <?php print $content['top']; ?>
    </div>
  </header>
  <div class="row space-bottom double">
    <div class="large-8 columns text-container">
      <?php print $content['main']; ?>
    </div>
    <div class="large-4 columns sidebar">
      <div class="row">
        <?php print $content['sidebar']; ?>
      </div>
    </div>
  </div>
  <?php print $content['featured']; ?>
  <section class="card-set bg-1">
    <?php print $content['cards_set']; ?>
  </section>
</section>
