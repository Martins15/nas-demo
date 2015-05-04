<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>

<section class="global-content">

  <div class="row video-header">
<!--    --><?php //print $content['header']; ?>
    <h1 class="thin">Live: Hogg Island Puffin Cam</h1>
  </div>

  <div class="video-wrapper">

    <div class="video row">
      <div class="flex-video">
        <?php print $content['video']; ?>
      </div>
    </div>
  </div>

  <div class="row space-top">
    <div class="video-summary row">
      <div class="columns large-10 text-container">
        <?php print isset($caption) ? $caption : ''; ?>
        <?php print $content['summary']; ?>
      </div>
      <div class="columns large-2 social-sharing hide-for-small hide-for-medium hide-for-tiny">
        <a href="<?php print isset($twitter_url) ? $twitter_url : '#'; ?>" class="social-sharing-icon white" target="_blank"><i class="icon-twitter"></i></a>
        <a href="<?php print isset($facebook_url) ? $facebook_url : '#'; ?>" class="social-sharing-icon white" target="_blank"><i class="icon-facebook"></i></a>
        <a href="<?php print isset($pinterest_url) ? $pinterest_url : '#'; ?>" class="social-sharing-icon white" target="_blank"><i class="icon-pinterest"></i></a>
        <a href="<?php print isset($mailto_url) ? $mailto_url : '#'; ?>" class="social-sharing-icon white" target="_blank"><i class="icon-mail"></i></a>
      </div>

    </div>
  </div>

  <?php print $content['bottom']; ?>

  <section class="card-set bg-dark-gray">
    <?php print $content['cards_set']; ?>
  </section>
</section>
