<?php

/**
 * @file
 * Template implementation to display the value of a field.
 */
?>
<?php

  $item = array_shift($items);
  if(isset($item['file'])) {
    $item['file2'] = $item['file'];
    $item['file']['#image_style'] = 'hero_mobile';
    $item['file']['#item']['attributes']['class'] = array('hide-for-medium', 'hide-for-large', 'hide-for-xlarge');
    $item['file2']['#image_style'] = 'hero_image';
    $item['file2']['#item']['attributes']['class'] = array('hide-for-tiny', 'hide-for-small');
  }
  $caption = render($item['field_file_caption']);
  $credits = render($item['field_file_credit']);
?>

<div class="hero dark-gradient">
  <div class="hero-image">
    <?php print render($item); ?>
  </div>
  <?php if ($caption || $credits) : ?>
    <div class="hero-caption">
      <div class="row">
        <div class="caption large-10 large-centered columns">
          <p>
            <?php print $caption; ?>
            <?php print $credits; ?>
          </p>
        </div>
      </div>
    </div>
  <?php endif; ?>
</div>