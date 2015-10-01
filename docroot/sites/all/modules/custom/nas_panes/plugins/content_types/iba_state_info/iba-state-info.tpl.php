<?php
/**
 * @file
 * Template for custom pane IBA State Info.
 *
 * Available variables:
 *  $contact_name - (string) Contact Name.
 *  $contact_title - (string) Contact Title.
 *  $link - (string) Static link.
 *  $priorities_data - (array) Contains priorities fields.
 */
?>

<p>
<?php if (!empty($contact_name)): ?> 
  <strong><?php print $contact_name; ?></strong><br>
<?php endif; ?>
<?php if (!empty($contact_title)): ?> 
  <?php print $contact_title; ?><br>
<?php endif; ?>
  <?php print $link; ?><br>
</p>
<br>
<h4><?php print t('California IBAs by Type'); ?></h4>
<table class="data">
  <thead>
    <tr>
      <th><?php print t('IBA Priority'); ?></th>
      <th><?php print t('Number'); ?></th>
      <th><?php print t('Acres'); ?></th>
    </tr>
  </thead>
  <tbody>
    <?php foreach ($priorities_data['priorities'] as $priority): ?>
    <tr>
      <td><?php print $priority['pr']; ?></td>
      <td><?php print $priority['number']; ?></td>
      <td><?php print $priority['acres']; ?></td>
    </tr>
    <?php endforeach; ?>
  </tbody>
  <tfoot>
    <tr>
      <td><?php print t('Total'); ?></td>
      <td><?php print $priorities_data['total_number']; ?></td>
      <td><?php print $priorities_data['total_acres']; ?></td>
    </tr>
  </tfoot>
</table>
