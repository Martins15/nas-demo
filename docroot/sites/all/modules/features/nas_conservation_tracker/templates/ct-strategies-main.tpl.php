<?php
/**
 * TPL file for CT content type.
 */
?>
<section class="ct-landscapes-main">
  <div class="row">
    <ul>
      <!-- Tabs with imgs /-->
      <?php foreach ($strategies as $strategy): ?>
        <li class="<?php print $strategy['class'] ?>">
          <a href="<?php print $strategy['link'] ?>"><?php print $strategy['name'] ?></a>
        </li>
      <?php endforeach; ?>
    </ul>
    <div>
      <div><!-- Title and tagline /--></div>
    </div>
  </div>
  <div class="row">
    <div><!-- Main content of strategy /--></div>
  </div>
</section>
