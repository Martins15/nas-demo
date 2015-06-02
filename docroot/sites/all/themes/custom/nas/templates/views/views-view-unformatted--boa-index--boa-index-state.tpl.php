<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php foreach ($rows as $id => $row): ?>
  <div class="boa-item columns tiny-6 medium-4 large-3 bg-boa-bejge">
    <?php print $row; ?>
  </div>
<?php endforeach; ?>
