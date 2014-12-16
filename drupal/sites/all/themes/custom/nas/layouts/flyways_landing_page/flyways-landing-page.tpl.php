<?php
/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>

</header>
<?php print $content['content']; ?>
<section class="global-content with-padding">
  <?php print $content['lower']; ?>
  <section class="card-set bg-1">
    <?php print $content['cards_set']; ?>
    <div class="row">
      <div class="card-set-social social-sharing">
        <span class="social-sharing-caption white">Spread the word. It&rsquo;s the least you can do.</span>
        <a class="social-sharing-icon white" href="#"><i class="icon-twitter"></i></a>
        <a class="social-sharing-icon white" href="#"><i class="icon-facebook"></i></a>
        <a class="social-sharing-icon white" href="#"><i class="icon-mail"></i></a>
      </div>
    </div>
  </section>
</section>
