<?php
/**
 * @file
 * Template for footer menu.
 */
?>

<?php foreach ($menu_tree as $menu_item) : ?>
  <?php if ($menu_item['below']) : ?>
    <?php $item_attr = drupal_attributes(array('class' => $menu_item['link']['options']['attributes']['class'])); ?>
    <div <?php print $item_attr; ?>>
      <ul class="footer-nav">
        <?php foreach ($menu_item['below'] as $sub_menu_item) : ?>
          <li>
            <a href="<?php print url($sub_menu_item['link']['link_path']);?>">
              <?php print check_plain($sub_menu_item['link']['link_title']); ?>
            </a>
          </li>
        <?php endforeach; ?>
      </ul>
    </div>
  <?php endif; ?>
<?php endforeach; ?>