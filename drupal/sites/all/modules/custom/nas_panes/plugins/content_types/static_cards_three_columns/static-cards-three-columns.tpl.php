<?php
/**
 * @file
 * Static cards three columns template file.
 */
?>

<div class="row space-bottom <?php print !empty($contextual_links) ? 'contextual-links-region' : ''; ?>">
  <?php print $contextual_links; ?>
  <?php foreach ($items as $item) : ?>
    <div class="large-4 columns">
      <div class="editorial-card">
        <div class="editorial-card-photo">
          <?php print l(theme('image', array('path' => $item['image_url'])), $item['image_link'], array('html' => TRUE)); ?>
        </div>
        <div class="editorial-card-content short">
          <?php if (!empty($item['top_link']['url']) && !empty($item['top_link']['title'])) : ?>
            <?php print l(check_plain($item['top_link']['title']), $item['top_link']['url'], array('attributes' => array('class' => array('editorial-card-slug')))); ?>
          <?php endif; ?>
          <h4 class="editorial-card-title"><a href="<?php print $item['title']['url']; ?>"><?php print $item['title']['title']; ?></a></h4>
          <?php if (!empty($item['bottom_link']['url']) && !empty($item['bottom_link']['title'])) : ?>
            <p>
              <em>
                <?php print l(check_plain($item['bottom_link']['title']), $item['bottom_link']['url'], array('attributes' => array('class' => array('editorial-card-link')))); ?>
              </em>
            </p>
          <?php endif; ?>
        </div>
      </div>
    </div>
  <?php endforeach; ?>
</div>
