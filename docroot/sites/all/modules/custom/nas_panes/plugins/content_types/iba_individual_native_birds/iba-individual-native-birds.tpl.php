<?php
/**
 * @file
 * Template to custom pane Birds Native to this area.
 *
 * Available variables:
 *  $contextual_links - contextual links.
 *  $title - pane's title.
 *  $teasers - array of rendered news.
 */
?>

<section class="sidebar-section medium-6 large-12 columns see-all">
  <h3><?php print $title; ?></h3>
  <div class="row bird-card-set-sidebar">
    <div class="columns tiny-6 small-4 medium-6">
      <?php print $teasers[0]; ?>
    </div>
    <div class="columns tiny-6 small-4 medium-6 end">
      <?php if (!empty($teasers[1])): ?>
        <?php print $teasers[1]; ?>
      <?php endif; ?>
    </div>
  </div>
  <?php if (!empty($teasers[2])): ?>
    <div class="row">
      <div class="columns large-6">
        <ul class="no-bullets small-list">
          <?php for ($i = 2; $i < 5; $i++): ?>
            <?php if (!empty($teasers[$i])): ?>
              <li><?php print $teasers[$i]; ?></li>
            <?php endif; ?>
          <?php endfor; ?>
          <?php if (!empty($teasers[8])): ?>
            <?php for ($i = 8; $i < $first_column_last; $i++): ?>
              <?php if (!empty($teasers[$i])): ?>
                <li class="see-all-show"><?php print $teasers[$i]; ?></li>
              <?php endif; ?>
            <?php endfor; ?>
          <?php endif; ?>
        </ul>
      </div>
      <div class="columns large-6">
        <?php if (!empty($teasers[5])): ?>
          <ul class="no-bullets small-list">
            <?php for ($i = 5; $i < 8; $i++): ?>
              <?php if (!empty($teasers[$i])): ?>
                <li><?php print $teasers[$i]; ?></li>
              <?php endif; ?>
            <?php endfor; ?>
            <?php if (!empty($teasers[8])): ?>
              <?php for ($i = $first_column_last; $i < count($teasers); $i++): ?>
                <?php if (!empty($teasers[$i])): ?>
                  <li class="see-all-show"><?php print $teasers[$i]; ?></li>
                <?php endif; ?>
              <?php endfor; ?>
           <?php endif; ?>
          </ul>
        <?php endif; ?>
      </div>
    </div>
  <?php endif; ?>
  <?php if (!empty($teasers[8])): ?>
    <hr class="see-all-hide">
    <a class="see-all-hide see-all-controller" href="#"><small>See all »</small></a>
  <?php endif; ?>
</section>
