<?php
/**
 * @file
 * Template implementation to display the value of a field.
 */
?>

<?php foreach ($items as $delta => $item): ?>
  <div class="page-content nas-project-body-<?php print $delta; ?>">
    <?php print render($item); ?>
  </div>
<?php endforeach; ?>
