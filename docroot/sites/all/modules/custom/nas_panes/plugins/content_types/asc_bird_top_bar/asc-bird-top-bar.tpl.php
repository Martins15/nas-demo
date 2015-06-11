<?php
/**
 * @file
 * S&C Field Guide Top bar template.
 *
 * Custom variables:
 * $url string - S&C absolute url.
 * $title string - S&C title.
 */
?>

<div class="national-strip back-to-center">
  <div class="row">
    <div class="columns">
      <a class="back" href="<?php print $url; ?>"><i class="icon-arrow-left"></i> <span class="optional">Back to </span><?php print $title; ?></a>
      <a class="close" onclick="jQuery('.back-to-center').slideUp(200)" href="#"><i class="icon-delete"></i><span class="optional"> close</span></a>
    </div>
  </div>
</div>
