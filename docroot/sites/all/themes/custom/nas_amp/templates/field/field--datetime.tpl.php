<?php

/**
 * @file
 * Template implementation to display the value of a field.
 */
?>
<time class="hg-pubdate" datetime="<?php print $element['#items'][0]['value'] ?>">
  <?php print render($items); ?>
</time>
