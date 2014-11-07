<?php

/**
 * @file
 * Custom view template to display Birds Prioroty.
 */
?>

<?php foreach ($rows as $id => $row): ?>
  <div class="columns tiny-6 medium-4 large-3">
  <?php print $row; ?>
  </div>
<?php endforeach; ?>
