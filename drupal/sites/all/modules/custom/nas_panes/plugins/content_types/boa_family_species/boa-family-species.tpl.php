<?php
/**
 * @file
 * Template to custom pane boa_family_species.
 *
 * Available variables:
 *  $genus - array of Genus data.
 */
?>

<?php foreach ($genera as $genus): ?>
<div class="boa-bird-card-set bg-boa-bejge">
  <div class="row section-header space-top">
    <div class="column">
      <h2 class="thin boa-family-set-title">Genus <?php print $genus['number']; ?> : <?php print $genus['title']; ?> <span><?php print $genus['scientific_name']; ?></span></h2>
    </div>
  </div>
  <div class="row boa-bird-card-container" data-equalizer>
    <?php foreach ($genus['species'] as $species): ?>
      <div class="columns tiny-6 medium-4 large-3" data-equalizer-watch>
        <?php print $species; ?>
      </div>
    <?php endforeach; ?>
  </div>
</div>
<?php endforeach; ?>
