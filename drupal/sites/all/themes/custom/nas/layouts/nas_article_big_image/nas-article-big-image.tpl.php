<?php
/**
 * @file
 * Template of NAS One Column. Used in Bird Guide.
 */
?>
<div class="hero dark-gradient">
  <div class="hero-image">
    <?php print $content['big_image']; ?>
  </div>
  <div class="hero-caption">
    <div class="row">
      <div class="caption large-10 large-centered columns">
        <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod
          tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,
          quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo
          consequat.</p>
      </div>
    </div>
  </div>
</div>
<section class="global-content">
  <article class="article">
    <header class="article-header row">
      <div class="large-10 large-centered columns">
        <?php print $content['header']; ?>
      </div>
    </header>
    <div class="article-body row">
      <div class="article-text large-push-2 large-10 columns reflow-body">
        
        <span data-reflow-placeholder="0"></span>
        <aside class="article-aside reflow reflow-into-body">
          <?php print $content['right']; ?>
          <div class="engagement-card">
            <div class="engagement-card-content no-min-height">
              <h3 class="engagement-card-headline">Help the Plight of the Albatross</h3>
              <p>These magnificent birds die tragic deaths, becoming entangled in fishing lines.</p>
              <div class="engagement-card-cta">
                <a href="#" class="button tomato xlarge">Endorse New Legislation</a>
              </div>
            </div>
            <div class="engagement-card-photo">
              <img src="../../img/engagement-card-1.jpg" alt="">
            </div>
          </div>
        </aside>
        <?php print $content['main']; ?>
      </div>
      <div class="article-sidebar large-pull-10 large-2 columns">
        <?php print $content['left']; ?>
        <section class="clearfix article-sidebar-section social-sharing no-caption hide-for-tiny hide-for-small hide-for-medium">
          <a class="social-sharing-icon" href="#"><i class="icon-twitter"></i></a>
          <a class="social-sharing-icon" href="#"><i class="icon-facebook"></i></a>
          <a class="social-sharing-icon" href="#"><i class="icon-mail"></i></a>
        </section>
        <section class="clearfix article-sidebar-section article-meta hide-for-tiny hide-for-small hide-for-medium">
          <a href="#"><img src="../../img/author-1.png" alt="" class="article-author-image"></a>
          <a href="#"><h5 class="article-author-name">Catherine MacMillanville</h5></a>
          <small class="article-date">Published Mar 27, 2014</small>
        </section>
        <section class="clearfix article-sidebar-section article-related-birds reflow reflow-into-body" data-reflow-class="article-aside half-width">
          <h5>Birds in This Story</h5>
          <div class="tiny-6 small-4 medium-6 large-12 columns">
            <figure class="bird-card small">
              <div class="bird-card-illustration">
                <a href="#"><img src="../../img/bird-1.png" alt=""></a>
              </div>
              <figcaption class="bird-card-caption">
                <h4 class="common-name"><a href="#">Cactus Wren</a></h4>
                <p class="scientific-name">Campylorhynchus brunneicapillus</p>
              </figcaption>
              <a href="#" class="icon-sound-full bird-card-audio"></a>
            </figure>
          </div>
          <div class="tiny-6 small-4 medium-6 large-12 columns end">
            <figure class="bird-card small">
              <div class="bird-card-illustration">
                <a href="#"><img src="../../img/bird-2.png" alt=""></a>
              </div>
              <figcaption class="bird-card-caption">
                <h4 class="common-name"><a href="#">Bullock's Oriole</a></h4>
                <p class="scientific-name">Icterus bullockii</p>
              </figcaption>
              <a href="#" class="icon-sound-full bird-card-audio"></a>
            </figure>
          </div>
        </section>
        <section class="clearfix article-sidebar-section popular-stories story-list small reflow reflow-into-bottom">
          <h5>Popular Stories</h5>
          <ul>
            <li><a href="#">With So Many Snowies to Study, Scientists are Discovering How Little We Know About This Bird</a></li>
            <li><a href="#">Photo of the Day: Lilac-Breasted Roller</a></li>
            <li><a href="#">Crows Understand Caw-se and Effect</a></li>
            <li><a href="#">Green Energy: Can We Save the Planet and Save Birds?</a></li>
            <li><a href="#">Nature Photography: Objectivitiy, Manipulation, and Ethics</a></li>
          </ul>
        </section>
      </div>
    </div>
  </article>
  <section class="card-set">
    <?php print $content['card_set']; ?>
    <div class="row">
      <div class="column">
        <h1 class="card-set-heading">Here&rsquo;s how you can make a difference</h1>
      </div>
    </div>
    <div class="row card-set-wrapper">
      <div class="clearfix card-set-scroller">
        <div class="tiny-4 columns">
          <div class="engagement-card">
            <div class="engagement-card-content">
              <h3 class="engagement-card-headline">Save the Brown Pelican</h3>
              <p>Numerous oil spills along the Gulf Coast have threatened thousands of native birds.</p>
              <div class="engagement-card-cta">
                <a href="#" class="button tomato large">Endorse New Legislation</a>
              </div>
            </div>
            <div class="engagement-card-photo">
              <img src="../../img/engagement-card-1.jpg" alt="">
            </div>
          </div>
        </div>
        <div class="tiny-4 columns">
          <div class="engagement-card">
            <div class="engagement-card-content">
              <h3 class="engagement-card-headline">Join Audubon’s Volunteers Days</h3>
              <p>Learn how you can make a real, lasting difference in your own community.</p>
              <div class="engagement-card-cta">
                <a href="#" class="button tomato large">Become a Volunteer</a>
              </div>
            </div>
            <div class="engagement-card-photo">
              <img src="../../img/engagement-card-2.jpg" alt="">
            </div>
          </div>
        </div>
        <div class="tiny-4 columns">
          <div class="engagement-card">
            <div class="engagement-card-content">
              <h3 class="engagement-card-headline">Adopt a Bird: Sandhill Crane</h3>
              <p>Online adoptions allow you to help Audubon protect birds and their habitats.</p>
              <div class="engagement-card-cta">
                <a href="#" class="button tomato large">Adopt a Bird</a>
              </div>
            </div>
            <div class="engagement-card-photo">
              <img src="../../img/engagement-card-3.jpg" alt="">
            </div>
          </div>
        </div>
      </div>
    </div>
    <div class="row">
      <div class="card-set-dots">
        <div class="dot active"></div>
        <div class="dot"></div>
        <div class="dot"></div>
      </div>
    </div>
    <div class="row">
      <div class="card-set-social social-sharing">
        <span class="social-sharing-caption pea-green">Spread the word. It&rsquo;s the least you can do.</span>
        <a class="social-sharing-icon pea-green" href="#"><i class="icon-twitter"></i></a>&nbsp;<a class="social-sharing-icon pea-green" href="#"><i class="icon-facebook"></i></a>&nbsp;<a class="social-sharing-icon pea-green" href="#"><i class="icon-mail"></i></a>
      </div>
    </div>
  </section>

</section>

<aside class="mailing-list">
  <div class="row">
    <div class="column">
      <div class="mailing-list-text">
        <h2 class="mailing-list-headline">Stay abreast of Audubon</h2>
        <p class="mailing-list-caption"><em>Our email newsletter shares the latest programs and initiatives.</em></p>
      </div><form class="mailing-list-form">
        <input class="mailing-list-input radius" placeholder="Enter your email address" type="text">
        <input class="button tomato large" type="submit" value="Sign Up">
      </form>
    </div>
  </div>
</aside>
