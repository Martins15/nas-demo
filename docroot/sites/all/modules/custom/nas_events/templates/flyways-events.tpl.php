<?php
/**
 * @file
 * Audubon Near You. Offices & Chapters template file.
 */
?>

<h4 class="editorial-card-title blue"><a href="<?php print url('upcoming-events'); ?>"><?php print t('Upcoming Events'); ?></a></h4>
<?php foreach ($items as $item) : ?>
  <div class="editorial-card-list-item small <?php print 'state-' . strtolower($item['state']); ?>">
    <h5 class="editorial-card-title">
      <a href="<?php print url('node/'.$item['nid']); ?>">
        <?php print $item['title']; ?>
      </a>
      <br>
      <small class="serif">
        <em><?php print $item['start_date']; ?></em>
      </small>
    </h5>
    <?php print $item['body']; ?>
  </div>
<?php endforeach; ?>
