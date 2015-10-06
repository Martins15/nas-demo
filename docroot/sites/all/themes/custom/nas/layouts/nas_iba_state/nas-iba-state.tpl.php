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
    <?php print $content['map']; ?>
    <div class="inline-map small">
      <div class="columns medium-6 large-8">
        <div class="inline-map-canvas">
          <div class="inline-map-mask"></div>
          <iframe width="100%" height="100%" frameborder="0" scrolling="no" marginheight="0" marginwidth="0" src="//audubon.maps.arcgis.com/home/webmap/embedViewer.html?webmap=5b8624b080484d2e8b0ea6f6abb6d08e&amp;extent=-174.8584,47.7477,-133.418,73.1604&amp;zoom=true&amp;scale=true"></iframe>
        </div>
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
