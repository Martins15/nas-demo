<aside class="article-aside reflow reflow-into-body">
  <div class="welcome-card teal">
    <div class="welcome-card-illustration">
      <?php print ($image);?>
    </div>
    <div class="welcome-card-content">
      <div class="welcome-card-headline">
        Welcome to<br>
        <img class="logo" src="../../img/wordmark-black.png" alt="">
      </div>
      <div class="welcome-card-blurb">
        <?php print ($summary);?>
        <?php print ($link_more);?>
        <hr>
      </div>
      <a href="<?php print ($path_news);?>" class="editorial-card-slug">In the News</a>
      <h5 class="editorial-card-title"><?php print ($link_news);?></h5>
      <a href="<?php print ($path_most_popular);?>" class="editorial-card-slug">Most Popular</a>
      <h5 class="editorial-card-title"><?php print ($link_most_popular);?></h5>
    </div>
    <div class="welcome-card-banner">
      <div class="social-sharing">
        <span class="social-sharing-caption small">Follow us </span>
        <a class="social-sharing-icon small" href="<?php print ($social_link_fb);?>"><i class="icon-twitter"></i></a>
        <a class="social-sharing-icon small" href="<?php print ($social_link_tw);?>"><i class="icon-facebook"></i></a>
        <a class="social-sharing-icon small" href="<?php print ($social_link_yotube);?>"><i class="icon-youtube"></i></a>
        <a class="social-sharing-icon small" href="<?php print ($social_link_pi);?>"><i class="icon-pinterest"></i></a>
      </div>
    </div>
  </div>
</aside>