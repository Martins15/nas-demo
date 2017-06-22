<?php
/**
 * @file
 * Template for Full-width Body text.
 *
 * Available variables:
 * - $title: Title for text block.
 * - $body_text: Text for block.
 * - $margin: Add left and right margins.
 */
?>

<div class="<?php print ($margin > 0) ? 'article-text row' : ''; ?>">
  <?php if ($title['title']): ?>
    <<?php print $title['title_heading']; ?>>
      <?php print $title['title_text']; ?>
    </<?php print $title['title_heading']; ?>>
  <?php endif; ?>

  <?php print $body_text; ?>
</div>
