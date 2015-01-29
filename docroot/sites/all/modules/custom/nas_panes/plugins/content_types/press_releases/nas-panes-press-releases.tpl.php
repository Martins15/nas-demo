<?php
/**
 * @file
 * Press releases block.
 *
 * Available variables:
 * - $title: title of the block.
 * - $releases: array wit press releases titles and urls.
 */
?>
<div class="other-releases story-list small">
  <h5><?php print $title; ?></h5>
  <ul>
    <?php foreach ($releases as $release): ?>
      <li><a href="<?php print $release['url']; ?>"><?php print $release['title']; ?></a></li>
    <?php endforeach; ?>
    <li class="more"><?php print l(t('View all press releases') . ' »', 'menu/press-room'); ?></li>
  </ul>
</div>
