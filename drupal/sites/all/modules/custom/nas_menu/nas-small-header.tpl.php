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
    <!-- / -->
    <div class="global-nav">
      <div class="mobile-nav">
        <ul class="primary-nav inline-list">
          <?php foreach ($items as $item): ?>
            <li class="primary-nav-item <?php print $item['li_class']; ?>">
              <a class="primary-nav-toggler <?php print $item['a_class']; ?>" href="<?php print $item['url']; ?>"><?php print $item['title']; ?></a>
              <?php if (!empty($item['#below'])): ?>
              <ul class="primary-sub-nav">
                <?php foreach ($item['#below'] as $sub_item): ?>
                <li class="primary-sub-nav-item' . $li_class . '">
                <a class="primary-nav-toggler <?php print $sub_item['a_class']; ?>" href="<?php print $sub_item['url']; ?>"><?php print $sub_item['title']; ?></a>
                </li>
                <?php endforeach; ?>
              </ul>
              <?php endif; ?>
            </li>
          <?php endforeach; ?>
          </ul>
      </div>
    </div>
  </div>
</div>
