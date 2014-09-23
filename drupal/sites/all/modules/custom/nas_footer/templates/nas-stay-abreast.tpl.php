<?php
/**
 * @file
 * Template for stay abreast footer section.
 *
 *  Variables:
 * - $headline: The Headline string.
 * - $caption: The caption string.
 * - $form: The rendered form.
 */
?>
<aside class="mailing-list">
  <div class="row">
    <div class="column">
      <div class="mailing-list-text">
        <h2 class="mailing-list-headline"><?php print $headline; ?></h2>
        <p class="mailing-list-caption"><em><?php print $caption; ?></em></p>
      </div><?php print $form; ?>
    </div>
  </div>
</aside>