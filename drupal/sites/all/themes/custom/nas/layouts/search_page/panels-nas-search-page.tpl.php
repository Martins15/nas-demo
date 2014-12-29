<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<?php print $content['header']; ?>
</header>
<section <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?> class="global-content">
<div class="top-search-form">
  <div class="row">
    <div class="columns">
      <?php print $content['search_form']; ?>
    </div>
  </div>
</div>

<?php print $content['birds_search_results']; ?>

  <section class="global-content global-content-search no-padding">
  <div class="row">
    <div class="section-header columns large-8 border-bottom">
      <div class="columns">
        <h2>Articles</h2>
        <p class="sub-heading">Showing 1–10 of 287 results</p>
      </div>
      <div class="columns">
        <div class="section-nav inline-list filter-list">
          <span>Sort by:</span>
          <li><a class="color-blue active" href="#">Relevance</a></li>
          <li><a class="color-blue" href="#">Date</a></li>
        </div>
      </div>
    </div>
  </div>
  <div class="row">
    <div class="sidebar columns large-push-8 large-4">
      <ul class="aid-filter">
        <li>
          <a class="primary-nav-toggler" href="#">Filter by Type</a>
          <ul class="primary-sub-nav">
            <li class="primary-sub-nav-item"><a href="#">News(27)</a></li>
            <li class="primary-sub-nav-item"><a href="#">Conservation(23)</a></li>
            <li class="primary-sub-nav-item"><a href="#">Science(18)</a></li>
            <li class="primary-sub-nav-item"><a href="#">Events(10)</a></li>
          </ul>
        </li>
        <li>
          <a class="primary-nav-toggler" href="#">Filter by Group</a>
          <ul class="primary-sub-nav">
            <li class="primary-sub-nav-item"><a href="#">Chapters(27)</a></li>
            <li class="primary-sub-nav-item"><a href="#">Centers & Sanctuaries(23)</a></li>
          </ul>
        </li>
      </ul>
    </div>
    <?php print $content['search_results']; ?>
  </div>
</section>
