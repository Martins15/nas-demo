<?php foreach ($menu_tree as $menu_item) : ?>
  <?php if ($menu_item['below']) : ?>
    <?php $item_attr = drupal_attributes(array('class' => $menu_item['link']['options']['attributes']['class'])); ?>
    <div <?php print $item_attr; ?>>
      <ul class="footer-nav">
        <?php foreach ($menu_item['below'] as $sub_menu_item) : ?>
          <li><?php print l($sub_menu_item['link']['link_title'], $sub_menu_item['link']['link_path']); ?></li>
        <?php endforeach; ?>
      </ul>
    </div>
  <?php endif; ?>
<?php endforeach; ?>
