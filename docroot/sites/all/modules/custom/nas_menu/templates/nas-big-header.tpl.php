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
<?php $cl_class = ($items['main_cl']) ? ' contextual-links-region' : ''; ?>
<div class="row">
  <div class="columns">
    <?php print $frontpage_link; ?>
    <!-- Only visible on small and medium screens -->
    <a href="#" class="icon-menu header-btn header-btn-menu"></a>
    <a href="#" class="icon-magnifier header-btn header-btn-search"></a>
    <!-- / -->
    <div class="header-search clearfix">
      <?php print $form; ?>
    </div>
    <div class="global-nav">
      <ul class="action-nav inline-list clearfix<?php print $cl_class; ?>">
        <?php print $items['secondary_ta_cl']; ?>
        <?php foreach ($items['secondary_ta'] as $item) : ?>
          <li class="<?php print $item['li_class']; ?>"><?php print $item['link']; ?></li>
        <?php endforeach; ?>
      </ul>
      <div class="mobile-nav">
        <ul class="primary-nav inline-list<?php print $cl_class; ?>">
          <?php print $items['main_cl']; ?>
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
          <li class="primary-nav-item primary-nav-search">
              <a href="<?php print $searchpage_url; ?>" class=""><i class="icon-magnifier"></i></a>
          </li>
        </ul>
        <ul class="secondary-nav inline-list<?php print $cl_class; ?>">
          <?php print $items['secondary_cl']; ?>
          <?php foreach ($items['secondary'] as $item) : ?>
            <li class="<?php print $item['li_class']; ?>"><?php print $item['link']; ?></li>
          <?php endforeach; ?>
        </ul>
        <!-- @todo Add search bar -->
      </div>
    </div>
  </div>
</div>
