<?php

/**
 * @file
 * Custom view template to display Birds Native to This Area block.
 */
?>

<section class="sidebar-section medium-6 large-12 columns">
  <h3><?php print $view->get_title(); ?></h3>
  <div class="row bird-card-set-sidebar">
    <div class="columns tiny-6 small-4 medium-6">
      <?php print $results[0]; ?>
    </div>
    <div class="columns tiny-6 small-4 medium-6 end">
      <?php if (!empty($results[1])): ?>
        <?php print $results[1]; ?>
      <?php endif; ?>
    </div>
  </div>
  <?php if (!empty($results[2])): ?>
  <div class="row">
    <div class="columns large-6">
      <ul class="no-bullets small-list">
        <?php for ($i = 2; $i < 5; $i++): ?>
          <?php if (!empty($results[$i])): ?>
            <li><?php print $results[$i]; ?></li>
          <?php endif; ?>
        <?php endfor; ?>
      </ul>
    </div>
    <div class="columns large-6">
      <?php if (!empty($results[5])): ?>
      <ul class="no-bullets small-list">
        <?php for ($i = 5; $i < 8; $i++): ?>
          <?php if (!empty($results[$i])): ?>
            <li><?php print $results[$i]; ?></li>
          <?php endif; ?>
        <?php endfor; ?>
      </ul>
      <?php endif; ?>
    </div>
  </div>
  <?php endif; ?>
  <?php if (!empty($results[8])): ?>
    <div class="see-all">
      <div class="see-all-show">
        <div class="row">
          <div class="columns large-6">
            <ul class="no-bullets small-list">
              <?php for ($i = 8; $i < $first_column_last; $i++): ?>
                <?php if (!empty($results[$i])): ?>
                  <li><?php print $results[$i]; ?></li>
                <?php endif; ?>
              <?php endfor; ?>
            </ul>
          </div>
          <div class="columns large-6">
            <ul class="no-bullets small-list">
              <?php for ($i = $first_column_last; $i < count($results); $i++): ?>
                <?php if (!empty($results[$i])): ?>
                  <li><?php print $results[$i]; ?></li>
                <?php endif; ?>
              <?php endfor; ?>
            </ul>
          </div>
        </div>
      </div>
      <hr class="see-all-hide">
      <a class="see-all-hide see-all-controller" href="#"><small>See all »</small></a>
    </div>
  <?php endif; ?>
</section>
