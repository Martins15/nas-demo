<?php
/**
 * @file
 * Template for custom pane Birds card set.
 *
 * Available variables:
 *  - $title: Pane's title.
 *  - $more_link: More link.
 *  - $teasers: List of rendered birds.
 *  - $pager: Indicate whether side-scrolling pager should be enabled.
 */
?>
<?php if (!empty($teasers)): ?>
  <?php if (!empty($title) || !empty($more_link)): ?>
    <div class="row section-header space-top">
      <?php if (!empty($title)): ?>
        <div class="column">
          <h2 class="thin"><?php print $title; ?></h2>
        </div>
      <?php endif; ?>
      <?php if (!empty($more_link)): ?>
        <div class="columns">
          <ul class="section-nav inline-list">
            <li>
              <?php print $more_link; ?>
            </li>
          </ul>
        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($pager)) : ?>
    <div class="row bird-card-container bird-card-set">
      <div class="owl-carousel">
        <?php foreach ($teasers as $teaser): ?>
          <?php print $teaser; ?>
        <?php endforeach; ?>
      </div>
    </div>
  <?php else : ?>
    <div class="bird-card-set">
      <div class="row bird-card-container<?php print empty($title) && empty($more_link) ? ' space-top' : ''; ?>">
        <div class="bird-card-scroller" style="transition: 0ms cubic-bezier(0.1, 0.57, 0.1, 1); -webkit-transition: 0ms cubic-bezier(0.1, 0.57, 0.1, 1); transform: translate(0px, 0px) translateZ(0px);">
          <?php foreach ($teasers as $teaser): ?>
            <div class="columns tiny-3">
              <?php print $teaser; ?>
            </div>
          <?php endforeach; ?>
        </div>
      </div>

      <div class="row indicator space-bottom double">
        <div class="column">
          <p><i class="indicator-left icon-arrow-left disabled"></i>&nbsp;&nbsp;&nbsp;<i class="indicator-right icon-arrow-right"></i>
          </p>
        </div>
      </div>
    </div>
  <?php endif; ?>

<?php endif; ?>
