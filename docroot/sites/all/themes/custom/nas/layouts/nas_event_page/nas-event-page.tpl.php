<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<section <?php print !empty($css_id) ? "id=\"$css_id\"" : ''; ?> class="global-content">
  <div class="row space-top">
    <article class="event">
      <div class="large-8 columns">
        <header class="event-header text-container">
          <?php print $content['header']; ?>
        </header>
        <div class="hide-for-large hide-for-xlarge hide-for-medium">
          <?php print $content['registration']; ?>
        </div>
        <!-- BEGIN MAIN COLUMN -->
        <?php print $content['location']; ?>
        <div class="row space-top">
          <div class="columns text-container">
            <?php print $content['description']; ?>
            <?php if (!empty($content['file_attachments'])): ?>
              <div class="file-attachments">
                <h3><?php print t('Downloadable Resources'); ?></h3>
                <div class="files-list">
                  <?php print $content['file_attachments']; ?>
                </div>
              </div>
            <?php endif; ?>
          </div>
        </div>
      </div>
      <!-- END MAIN COLUMN -->

      <!-- BEGIN SIDEBAR -->
      <div class="sidebar large-4 columns">
        <div class="hide-for-tiny hide-for-small">
          <?php print $content['registration']; ?>
        </div>
        <?php print $content['sidebar']; ?>
      </div>
      <!-- END SIDEBAR -->
    </article>
  </div>
  <?php if (!empty($content['other_upcoming_events'])): ?>
  <div class="other-upcoming-events clearfix">
    <div class="row section-header ">
      <div class="columns">
        <h2 class="thin"><?php print t('Other Upcoming Events'); ?></h2>
      </div>
    </div>
    <div class="row card-set space-bottom double">
      <?php print $content['other_upcoming_events']; ?>
    </div>
  </div>
  <?php endif;?>
  <section class="card-set bg-1">
    <?php print $content['cards_set']; ?>
  </section>
</section>
