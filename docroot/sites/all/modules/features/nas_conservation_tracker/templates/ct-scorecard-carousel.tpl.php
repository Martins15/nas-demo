<?php
/**
 * TPL file for CT content type.
 */
?>
<div class="slider-element bird-page">
  <div class="row">
    <div class="slider-element__title-wrap">
      <h4><?php print $title; ?></h4>
    </div>
    <div class="items-wrap" id="ct-scorecard-owl">
      <?php foreach ($items as $item): ?>
      <div class="item">
        <div class="item__pre-title"><?php print $item['category']; ?></div>
        <div class="item__title">
          <a href="<?php print $item['href']; ?>"><?php print $item['title']; ?></a>
        </div>
      </div>
      <?php endforeach; ?>
    </div>
  </div>
</div>