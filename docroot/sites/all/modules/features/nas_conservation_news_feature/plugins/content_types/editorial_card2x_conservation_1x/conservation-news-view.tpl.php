<?php

/**
 * @file
 * Template for Conservation News block.
 *
 * Available variables:
 * - $terms: Array with structure term_id => term_label.
 * - $views: array of rendered views.
 * - $more_link: link and title for More link in filter
 * - $filter_title: Output text that will be shown before filter.
 */
?>

<div class="columns large-4">
  <div data-equalizer-watch>
    <?php if ($terms): ?>
      <div class="view-conservation-news-filter">
        <?php if ($filter_title): ?>
          <div class="filter-label"><?php print $filter_title; ?></div>
        <?php endif; ?>
        <ul class="filter-items">
          <?php foreach ($terms as $term): ?>
            <li data-term-id="<?php print $term['term_id']; ?>"
                class="filter-item">
              <a href="taxonomy/term/<?php print $term['term_id']; ?>"
                 title="<?php print $term['term_label']; ?>">
                <?php print $term['term_label']; ?>
              </a>
            </li>
          <?php endforeach; ?>
          <?php if ($more_link): ?>
            <li>
              <?php print $more_link; ?>
            </li>
          <?php endif; ?>
        </ul>
      </div>
    <?php endif; ?>
    <div class="view-conservation-news-views-list">
      <?php if ($views): ?>
        <?php foreach ($views as $view): ?>
          <?php print $view; ?>
        <?php endforeach; ?>
      <?php endif; ?>
    </div>
  </div>
</div>
