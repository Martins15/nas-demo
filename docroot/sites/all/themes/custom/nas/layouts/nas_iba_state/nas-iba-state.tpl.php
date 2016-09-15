<?php
/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<section class="global-content">
  <div class="row section-header">
    <div class="column">
    <?php print l(t('Important Bird Areas'), 'iba', array('attributes' => array('class' => array('section-header-slug')))); ?>
      <?php print $content['title']; ?>
    </div>
    <?php print $content['top']; ?>
  </div>

  <div class="row space-bottom">
    <div class="inline-map small">
      <div class="columns medium-6 large-8">
          <?php print $content['map']; ?>
      </div>
    </div>
    <div class="columns medium-6 large-4">
      <?php print $content['sidebar']; ?>
    </div>
  </div>
  <div class="row space-bottom">
    <div class="column text-container">
      <?php print $content['main']; ?>
    </div>
  </div>
  <div class="row">
    <div class="column">
      <?php print $content['search']; ?>
    </div>
  </div>
  <?php print $content['more']; ?>
  <section class="card-set bg-1">
  	<?php print $content['cards_set']; ?>
  </section>
</section>
