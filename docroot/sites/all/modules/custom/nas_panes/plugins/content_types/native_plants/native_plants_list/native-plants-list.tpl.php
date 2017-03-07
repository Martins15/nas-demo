<?php

/**
 * @file
 * Native Plants List template.
 */
?>
<div class="row np-search-full-results">

  <div class="native-plants-full-search-results permalink-list">
    <div class="columns large-8 large-push-2">
      <table class="hide-for-tiny hide-for-small">
        <thead>
        <tr>
          <th><?php print t('Plant Name'); ?></th>
          <th><?php print t('Scientific Name'); ?></th>
          <th><?php print t('May attract'); ?></th>
        </tr>
        </thead>
        <tbody>
        <?php foreach ($plants as $plant): ?>
        <tr>
          <td><?php print $plant['CommonName']; ?></td>
          <td><em><?php print $plant['ScientificName']; ?></em></td>
          <td><?php print implode(', ', $plant['BirdTypesDesktop']); ?></td>
        </tr>
        <?php endforeach; ?>
        </tbody>
      </table>
    </div>

    <div class="mobile-search-full-results hide-for-medium hide-for-large hide-for-xlarge">
      <?php foreach ($plants as $plant): ?>
      <div class="clearfix view-row">
        <div class="columns">
          <div>
            <span class="mobile-search-full-results--label"><?php print t('Plant'); ?>:</span> <?php print $plant['CommonName']; ?>
          </div>
          <div>
            <span class="mobile-search-full-results--label"><?php print t('Scientific name'); ?>:</span> <em><?php print $plant['ScientificName']; ?></em>
          </div>
          <div>
            <span class="mobile-search-full-results--label"><?php print t('Attracts'); ?>:</span> <?php print implode(', ', $plant['BirdTypesMobile']); ?>
          </div>
        </div>
      </div>
      <?php endforeach; ?>
    </div>

  </div>
</div>
