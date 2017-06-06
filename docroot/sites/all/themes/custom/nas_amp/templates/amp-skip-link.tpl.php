<?php

/**
 * @file
 * Theme override of a skip link.
 *
 * Variables:
 * - $skiptext: Text for the skip link.
 *
 * @ingroup themeable
 */
?>

<div id="skip-link">
  <a href="#main-content" class="element-invisible element-focusable amp-skip-link"><?php print $skiptext; ?></a>
</div>

<button on='tap:sidebar'>Menu</button>
<button on='tap:sidebar.close'>x</button>

<amp-sidebar id='sidebar' layout='nodisplay'>
  <ul>
    <li> Nav item 1</li>
    <li> Nav item 2</li>
    <li> Nav item 3</li>
    <li> Nav item 4</li>
    <li> Nav item 5</li>
    <li> Nav item 6</li>
    <li> Nav item 7</li>
    <li> Nav item 8</li>
    <li> Nav item 9</li>
    <li on="tap:sidebar.close"> Close</li>
  </ul>
</amp-sidebar>
