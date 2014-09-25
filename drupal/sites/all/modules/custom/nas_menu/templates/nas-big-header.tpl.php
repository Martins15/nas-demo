<?php
/**
 * @file
 * Template for header with single menu.
 *
 * Available variables:
 * - $frontpage_link: link to frontpage.
 * - $items: menu items. Example
 *  $items = array(
 *    array(
 *      'li_class' => 'orange',
 *      'a_class' => 'nav',
 *      'link' => '<a href="">Donate</a>'
 *      'below' => array(),
 *    ),
 *    array(
 *      'li_class' => '',
 *      'link' => '<a href="">Donate</a>'
 *      'below' => array(
 *        array(
 *          'li_class' => '',
 *          'link' => '<a href="">Donate</a>'
 *        ),
 *      ),
 *    ),
 * );
 */
?>
<div class="row">
  <div class="columns">
    <?php print $frontpage_link; ?>
    <!-- Only visible on small and medium screens -->
    <a href="#" class="icon-menu header-btn header-btn-menu"></a>
    <a href="#" class="icon-magnifier header-btn header-btn-search"></a>
    <!-- / -->
    <div class="header-search clearfix">
      <input class="header-search-input radius" type="search" placeholder="Search the Audubon network">
      <button class="header-search-button button large pea-green">
        <i class="icon-magnifier"></i>
      </button>
      <a href="#" class="hide-for-tiny hide-for-small hide-for-medium header-search-close"><i class="icon-close"></i></a>
    </div>
    <div class="global-nav">
      <ul class="action-nav inline-list clearfix">
        <?php foreach ($items['secondary_ta'] as $item) : ?>
          <li class="<?php print $item['li_class']; ?>"><?php print $item['link']; ?></li>
        <?php endforeach; ?>
      </ul>
      <div class="mobile-nav">
        <ul class="primary-nav inline-list">
          <?php foreach ($items['main'] as $item) : ?>
            <li class="<?php print $item['li_class']; ?>">
              <?php print $item['link']; ?>
              <?php if ($item['below']) : ?>
                <ul class="primary-sub-nav">
                  <?php foreach ($item['below'] as $subitem) : ?>
                    <li class="<?php print $subitem['li_class']; ?>">
                      <?php print $subitem['link']; ?>
                    </li>
                  <?php endforeach; ?>
                </ul>
              <?php endif; ?>
            </li>
          <?php endforeach; ?>
        </ul>
        <ul class="secondary-nav inline-list">
          <?php foreach ($items['secondary'] as $item) : ?>
            <li class="<?php print $item['li_class']; ?>"><?php print $item['link']; ?></li>
          <?php endforeach; ?>
        </ul>
        <!-- @todo Add search bar -->
      </div>
    </div>
  </div>
</div>