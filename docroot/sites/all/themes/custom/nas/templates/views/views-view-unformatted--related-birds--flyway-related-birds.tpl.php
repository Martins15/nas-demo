<?php

/**
 * @file
 * Default view template to display Flyways Related Birds.
 *
 * @ingroup views_templates
 */
?>

<?php foreach ($rows as $row): ?>
  <div class="columns tiny-3">
    <?php print $row; ?>
  </div>
<?php endforeach; ?>
