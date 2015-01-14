<?php
/**
 * @file
 * About Page Map template file.
 */
?>

<div class="bird-guide-search show<?php print !empty($contextual_links) ? ' contextual-links-region' : ''; ?>">
  <?php print $contextual_links; ?>
  <div class="row">
    <div class="columns large-7 bird-guide-search-form">
      <div class="title-h1"><?php print $title; ?></div>
        <div class="content-bird">
          <?php print $description; ?>
        </div>
      </div>
      <div class="columns large-5 interactive-guide interactive-guide-aid">
        <p class="preamble">
          <span class="small"><?php print $form_title; ?></span>
        </p>
        <?php print $form; ?>
      </div>
    </div>
  </div>

