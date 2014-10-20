<?php
/**
 * @file
 * Template for footer menu.
 * 
 * Available variables:
 * - $menu_tree: menu items. Example
 *  $menu_tree = array(
 * 'item 1' => array(
 *   'link' => array(
 *     'link_path' => '<front>',
 *     'link_title' => 'Item 1',
 *     'options' => array(
 *       'attributes' => array(
 *         'class' => array(
 *             'tiny-6',
 *             'medium-4',
 *             'large-3',
 *             'columns',
 *         )
 *       )
 *     )
 *   ),
 *   'below' => array(
 *     '49950 Home 259' => array(
 *       'link' => array(
 *         'link_path' => '<front>',
 *         'link_title' => 'Home',
 *         'options' => array(
 *           'attributes' => array()
 *         )
 *       )
 *     )
 *   )
 * )
 * );
 */
?>

<?php foreach ($menu_tree as $menu_item) : ?>
  <?php if ($menu_item['below']) : ?>
    <?php $item_attr = drupal_attributes(array('class' => $menu_item['link']['options']['attributes']['class'])); ?>
    <div <?php print $item_attr; ?>>
      <ul class="footer-nav">
        <?php foreach ($menu_item['below'] as $sub_menu_item) : ?>
          <li>
            <a href="<?php print url($sub_menu_item['link']['link_path']); ?>">
              <?php print check_plain($sub_menu_item['link']['link_title']); ?>
            </a>
          </li>
        <?php endforeach; ?>
      </ul>
    </div>
  <?php endif; ?>
<?php endforeach; ?>