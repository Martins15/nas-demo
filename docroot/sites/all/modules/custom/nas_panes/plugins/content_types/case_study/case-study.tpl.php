<?php

/**
 * @file
 * Case study block template file.
 */
?>


<div class="text-container">
  <div class="item-case-studies">
    <h2><?php print $title; ?></h2>
    <div class="wrap-help park-item">
      <div class="park-item__image">
        <?php print $case_study_image; ?>
        <p class="image-first__text-after text-after"><?php print $case_study_image_caption; ?></p>
      </div>
      <div class="park-item__help-wrap columns">
        <div class="park-item__info">
          <div class="info__bird-card bird">
            <div class="bird__img">
              <?php print $box_image; ?>
            </div>
            <div class="bird__text">
              <?php foreach ($box as $item): ?>
                <div class="item">
                  <p class="name"><?php print $item['box_title']; ?></p>
                  <p class="value"><?php print $item['box_description']; ?></p>
                </div>
              <?php endforeach; ?>
            </div>
          </div>
        </div>
        <div class="park-item__text-after">
          <?php print $case_study_description['value']; ?>
          <p><?php print $article_reference; ?></p>
        </div>
      </div>
    </div>
  </div>
</div>
