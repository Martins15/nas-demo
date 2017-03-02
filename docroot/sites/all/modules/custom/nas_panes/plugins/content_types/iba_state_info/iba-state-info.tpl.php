<?php

/**
 * @file
 * Template for custom pane IBA State Info.
 *
 * Available variables:
 *  $contact_name - (string) Contact Name.
 *  $contact_title - (string) Contact Title.
 *  $state_link - (string) Static link.
 *  $priorities_data - (array) Contains priorities fields.
 */
?>

<?php if ($contact_name || $state_link): ?>
<div class="iba-state-contacts">
  <?php if (!empty($contact_name)): ?>
    <h4><?php print $state_title . ' ' . t('IBA Contact'); ?></h4>
    <?php print $contact_name; ?>
  <?php endif; ?>
  <?php if (!empty($state_link)): ?>
    <h4><?php print t('More info'); ?></h4>
    <?php print $state_link; ?>
  <?php endif; ?>
</div>
<?php endif; ?>

<h4><?php print $state_title . ' ' . t('IBAs by Type'); ?></h4>
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
