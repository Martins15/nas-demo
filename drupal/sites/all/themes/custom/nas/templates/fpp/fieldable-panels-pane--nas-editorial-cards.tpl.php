<?php

/**
 * @file
 * Template implementation to display the FPP layout.
 *
 * Custom variables:
 * - $editorial_card_slug: Link from field_link field.
 * - $editorial_card_title: Title of FPP with lnk fron field_link.
 * - $editorial_card_links: Links from field_links field (multiple).
 * - $editorial_card_summary: vText from field_summary field.
 *
 * @see template_preprocess_fieldable_panels_pane()
 */
?>
<div class="columns <?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="editorial-card contextual-links-region">
    <?php print $contextual_links; ?>
    <div class="editorial-card-photo">
      <?php print render($editorial_card_photo); ?>
    </div>
    <div class="editorial-card-content">
    <?php print $editorial_card_slug; ?>
      <h3 class="editorial-card-title"><?php print $editorial_card_title; ?></h3>
      <?php foreach ($editorial_card_links as $link): ?>
        <p><em><?php print $link; ?></em></p>
      <?php endforeach; ?>
      <br>
      <?php print render($editorial_card_summary); ?>
    </div>
  </div>
</div>
