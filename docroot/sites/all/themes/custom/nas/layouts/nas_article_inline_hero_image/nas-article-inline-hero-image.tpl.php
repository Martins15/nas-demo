<?php
/**
 * @file
 * Template of Article layout with Big image.
 */
?>
<section class="global-content">
  <article class="article">
    <header class="article-header row">
      <div class="large-10 large-centered columns">
        <?php print $content['header']; ?>
        <div class="article-meta clearfix hide-for-large hide-for-xlarge">
          <?php print $content['mobile_author']; ?>
        </div>
      </div> 
    </header>
    <div class="article-body row">
      <div class="article-sidebar large-2 columns">
        <?php print $content['social']; ?>
        <section class="clearfix article-sidebar-section article-meta hide-for-tiny hide-for-small hide-for-medium">
          <?php print $content['author']; ?>
        </section>
        <section class="clearfix article-sidebar-section article-related-birds reflow reflow-into-body" data-reflow-class="article-aside half-width">
          <?php print $content['birds']; ?>
        </section>
        <?php print $content['left']; ?>
      </div>
      <div class="article-text large-10 columns reflow-body">
        <aside class="article-aside full-width">
          <figure class="article-image">
            <?php print $content['inline_image']; ?>
          </figure>
        </aside>
        <aside class="article-aside reflow reflow-into-body">
          <?php print $content['right']; ?>
        </aside>
        <?php print $content['main']; ?>
      </div>
    </div>
  </article>
  <section class="card-set">
    <?php print $content['card_set']; ?>
    <div class="row">
      <div class="card-set-social social-sharing">
        <span class="social-sharing-caption pea-green">Spread the word. It&rsquo;s the least you can do.</span>
        <a class="social-sharing-icon pea-green" href="#"><i class="icon-twitter"></i></a>&nbsp;<a class="social-sharing-icon pea-green" href="#"><i class="icon-facebook"></i></a>&nbsp;<a class="social-sharing-icon pea-green" href="#"><i class="icon-mail"></i></a>
      </div>
    </div>
  </section>
</section>