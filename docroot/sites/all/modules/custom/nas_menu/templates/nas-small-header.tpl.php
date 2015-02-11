<?php
/**
 * @file
 * Template for header with single menu.
 *
 * Available variables:
 * - $frontpage_url: URL of the frontpage.
 * - $site_name: Site name variable,
 * - $items: menu items. Example
 *  $items = array(
 *    array(
 *      'li_class' => 'orange',
 *      'a_class' => 'nav',
 *      'url' => '/donate'
 *      'title' => 'Donate',
 *      '#below' => array(),
 *    ),
 *    array(
 *      'li_class' => '',
 *      'a_class' => 'nav',
 *      'url' => '/birds'
 *      'title' => 'Birds',
 *      '#below' => array(
 *        array(
 *          'li_class' => '',
 *          'a_class' => 'nav',
 *          'url' => '/birds/birds-guide'
 *          'title' => 'Birds Guide',
 *        ),
 *        array(
 *          'li_class' => '',
 *          'a_class' => 'nav',
 *          'url' => '/birds/featured-events'
 *          'title' => 'Featured Events',
 *        ),
 *      ),
 *    ),
 * );
 */
?>
<div class="row">
  <div class="columns">
    <a href="<?php print $frontpage_url; ?>" class="current-parent wordmark"><?php print $site_name; ?></a>
    <!-- Only visible on small and medium screens -->
    <a href="#" class="icon-menu header-btn header-btn-menu"></a>
    <a href="#" class="icon-binoculars header-btn-search-alt toggle-bird-guide-search bird-guide-search-species-page"></a>

    <!-- / -->
    <div class="header-search clearfix">
      <?php print $form; ?>
    </div>
    <div class="global-nav">
      <div class="mobile-nav">
        <ul class="primary-nav inline-list">
          <?php foreach ($items as $item): ?>
            <li class="primary-nav-item <?php print $item['li_class']; ?>">
              <a class="<?php if (!empty($item['#below'])): ?>primary-nav-toggler <?php endif; ?><?php print $item['a_class']; ?>" href="<?php print $item['url']; ?>"><?php print $item['title']; ?></a>
              <?php if (!empty($item['#below'])): ?>
              <ul class="primary-sub-nav">
                <?php foreach ($item['#below'] as $sub_item): ?>
                <li class="primary-sub-nav-item <?php print $sub_item['li_class']; ?>">
                <a class="primary-sub-nav-link <?php print $sub_item['a_class']; ?>" href="<?php print $sub_item['url']; ?>"><?php print $sub_item['title']; ?></a>
                </li>
                <?php endforeach; ?>
              </ul>
              <?php endif; ?>
            </li>
          <?php endforeach; ?>
          <li class="primary-nav-item">
            <a href="<?php print $searchpage_url; ?>" class="primary-nav-search"><i class="icon-magnifier"></i></a>
          </li>
        </ul>
      </div>
    </div>
  </div>
</div>
