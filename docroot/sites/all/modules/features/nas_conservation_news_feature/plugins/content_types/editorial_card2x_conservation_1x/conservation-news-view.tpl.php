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

<div class="columns large-4 conservation-news-column">
  <div class="editorial-card" data-equalizer-watch>
    <h4>Conservation News</h4>
    <?php if ($terms): ?>
      <div class="view-conservation-news-filter">
        <?php if ($filter_title): ?>
          <div class="filter-label"><?php print $filter_title; ?></div>
        <?php endif; ?>
        <ul class="filter-items">
          <?php foreach ($terms as $term): ?>
            <li class="filter-item">
              <?php print l($term['term_label'], 'taxonomy/term/' . $term['term_id'], array(
                'attributes' => array(
                  'title' => $term['term_label'],
                  'data-term-id' => $term['term_id'],
                ),
              )); ?>
            </li>
          <?php endforeach; ?>
          <?php if ($filter_more_link): ?>
            <li>
              <?php print $filter_more_link; ?>
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
