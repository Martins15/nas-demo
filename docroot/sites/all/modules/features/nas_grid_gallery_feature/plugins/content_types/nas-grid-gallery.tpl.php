<?php

/**
 * @file
 * Template for custom pane progress bar.
 *
 * Available variables:
 * - $grid_size: Grid set size.
 * - $images: All images.
 * - $rows: Rows number.
 * - $columns: Columns number.
 * - $gallery_caption: Gallery caption.
 */
?>

<div class="grid-gallery <?php print 'grid-gallery-' . $grid_size; ?><?php print !empty($contextual_links) ? ' contextual-links-region' : ''; ?>">
  <?php print $contextual_links; ?>

  <?php foreach (array_chunk($images, $columns) as $row): ?>
    <div class="row">

      <?php foreach ($row as $image): ?>
        <div class="columns<?php print $class_column; ?>">
          <a class="grid-gallery__lightbox lightbox white colorbox" href="<?php print $image['lightbox_path']; ?>">
            <img class="grid-gallery__image" src="<?php print $image['thumbnail_path']; ?>" title="<?php print $image['thumbnail_title']; ?>">
          </a>
        </div>
      <?php endforeach; ?>

    </div>
  <?php endforeach; ?>

  <?php if ($gallery_caption): ?>
    <div class="row grid-gallery__caption">
      <div class="columns large-12">
        <?php print $gallery_caption; ?>
      </div>
    </div>
  <?php endif; ?>

</div>
