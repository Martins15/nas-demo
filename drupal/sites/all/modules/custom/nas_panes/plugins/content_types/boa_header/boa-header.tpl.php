<?php
/**
 * @file
 * Template to custom pane boa_header.
 *
 * Available variables:
 *  $plate_number - plate number.
 *  $title - node's title. Name of the bird.
 *  $scientific_name - scientific name of the bird.
 */
?>

<section class="bird-guide-header left-col">
  <h2 class="plate-name">Plate <?php print $plate_number; ?></h2>
  <h1 class="common-name"><?php print $title; ?></h1>
  <p class="scientific-name"><?php print $scientific_name; ?></p>
</section>
