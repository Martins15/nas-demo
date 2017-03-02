<?php

/**
 * @file
 * This template handles the layout of the NetX preview form.
 *
 * It displays results in a table view.
 *
 * Variables available:
 * - $element: Element form array.
 */
?>
<div class="audubon-netx-preview">
  <h2><?php print drupal_render($element['title']); ?></h2>
  <div class="form-radios netx-thumbnail">
    <table>
      <thead>
      <tr>
        <th><?php print t('Image'); ?></th>
        <th><?php print t('Filename'); ?></th>
        <th><?php print t('Dimensions'); ?></th>
      </tr>
      </thead>
      <tbody>
      <?php foreach ($element['image'] as $key => &$option): ?>
        <?php if (!is_array($option) || !isset($option['#type'])): ?>
          <?php continue; ?>
        <?php endif; ?>
        <tr>
          <td><?php print drupal_render($option); ?></td>
          <td><?php print drupal_render($element['filename'][$key]); ?></td>
          <td><?php print drupal_render($element['dimensions'][$key]); ?></td>
        </tr>
      <?php endforeach; ?>
      </tbody>
    </table>
  </div>
  <div class="view-pager"></div>
  <?php print drupal_render_children($element); ?>
</div>
