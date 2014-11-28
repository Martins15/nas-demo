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
<div class="bird-card-set boa-bird-card-set bg-boa-bejge">
  <div class="row section-header space-top">
    <div class="column">
      <h2 class="thin boa-family-set-title">Genus <?php print $genus['number']; ?> : <?php print $genus['title']; ?> <span><?php print $genus['scientific_name']; ?></span></h2>
    </div>
  </div>
  <div class="row bird-card-container boa-bird-card-container">
    <div class="bird-card-scroller">
      <?php foreach ($genus['species'] as $species): ?>
        <div class="columns tiny-3">
          <?php print $species; ?>
        </div>
      <?php endforeach; ?>
    </div>
  </div>
  <div class="row indicator">
    <div class="column">
      <p><i class="indicator-left icon-arrow-left"></i>&nbsp;&nbsp;&nbsp;<i class="indicator-right icon-arrow-right disabled"></i></p>
    </div>
  </div>
</div>
<?php endforeach; ?>
