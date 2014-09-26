<?php
/**
 * @file
 * Template for don't miss menu.
 *
 * Available variables:
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
<section class="dont-miss strip-nav small">
  <div class="row">
    <div class="columns">
      <ul class="inline-list" style="width: 1012px; transition: 0ms cubic-bezier(0.1, 0.57, 0.1, 1); -webkit-transition: 0ms cubic-bezier(0.1, 0.57, 0.1, 1); transform: translate(0px, 0px) translateZ(0px);">
        <li class="dont-miss-header strip-nav-header"><span><?php print t("Don't Miss"); ?></span></li>
        <?php foreach ($items as $item) : ?>
          <?php if ($item['li_class']) : ?>
            <li class="<?php print $item['li_class']; ?>"><?php print $item['link']; ?></li>
          <?php else : ?>
            <li><?php print $item['link']; ?></li>
          <?php endif; ?>
        <?php endforeach; ?>
      </ul>
    </div>
  </div>
</section>