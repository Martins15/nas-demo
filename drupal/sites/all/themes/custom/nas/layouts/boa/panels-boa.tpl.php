<?php
/**
 * @file
 * Template implementation to display BOA layout.
 */
?>
<div class="guide-bar clearfix">
  <div class="row">
    <div class="column">
      <h2 class="guide-bar-title"><span class="hide-for-small hide-for-tiny"></span>John J Audubon’s Birds of America</h2>
      <a class="guide-bar-search toggle-bird-guide-search" href="#"><i class="icon-binoculars white"></i><i class="icon-binoculars black"></i> Find a Bird</a>
    </div>
  </div>
</div>
<div class="row">
  <div class="john-audubon-logo">
    <img src="../../img/john_audubon.png" />
  </div>
</div>
<ul class="hide-for-medium hide-for-large hide-for-xlarge action-nav inline-list clearfix">
  <li class="action-nav-item"><a class="by-family action-nav-link button small tomato" href="#">By family</a></li>
  <li class="action-nav-item"><a class="by-alphabetical action-nav-link button small tomato" href="#">Alphabetical</a></li>
  <li class="action-nav-item"><a class="by-state action-nav-link button small tomato" href="#">State birds</a></li>
</ul>
<div class="bird-guide-search">
  <div class="row">
    <div class="columns large-12 bird-guide-search-form">
      <form>
        <div class="bird-guide-search-input">
          <input type="search" placeholder="Search for a bird in the guide..." class="bird-guide-search-input radius">
        </div>
        <button class="bird-guide-search-submit button pea-green"><span class="hide-for-medium hide-for-large hide-for-xlarge"><i class="icon-magnifier"></i></span><span class="hide-for-tiny hide-for-small">Search</span></button>

        <div class="row">
          <div class="columns medium-4">
            <select name="" id="">
              <option value="">Type of Bird</option>
              <option value=""></option>
              <option value=""></option>
            </select>
          </div>
          <div class="columns medium-4">
            <select name="" id="">
              <option value="">Taxonomic Family</option>
              <option value=""></option>
              <option value=""></option>
            </select>
          </div>
          <div class="columns medium-4">
            <select name="" id="">
              <option value="">Region</option>
              <option value=""></option>
              <option value=""></option>
            </select>
          </div>
        </div>
      </form>
    </div>
  </div>
</div>
<?php print $content['header']; ?>
</header>
<section class="global-content no-padding">
  <div class="bird-guide-container hero large">
    <?php print $content['hero']; ?>
    <div class="row">
      <div class="column">
        <div class="bird-guide-card">
          <section class="bird-guide-body">
            <div class="row">
              <div class="large-8 columns">
                <?php print $content['main']; ?>
              </div>
              <div class="large-4 columns">
                <?php print $content['sidebar']; ?>
                <section class="social-sharing bird-guide-section right-col small center">
                  <span class="social-sharing-caption small">Share this plate</span>
                  <a class="social-sharing-icon blue small" href="#"><i class="icon-twitter"></i></a>&nbsp;<a class="social-sharing-icon blue small" href="#"><i class="icon-facebook"></i></a>&nbsp;<a class="social-sharing-icon blue small" href="#"><i class="icon-pinterest"></i></a>&nbsp;<a class="social-sharing-icon blue small" href="#"><i class="icon-mail"></i></a>
                </section>
                <section class="bird-guide-section boa-in-the-bird-guide">
                  <div class="columns">
                    <h2 class="thin">In the Bird Guide</h2>
                    <figure class="bird-card">
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
                </section>
                <section class="bird-guide-section boa-in-the-news">
                  <div class="columns">
                    <h2 class="thin">In the News</h2>
                    <div class="editorial-card collapse-minimal">
                      <div class="editorial-card-photo">
                        <a href="#"><img src="../../img/editorial-card-1.jpg" alt=""></a>
                      </div>
                      <div class="editorial-card-content">
                        <a href="#" class="editorial-card-slug">In the News</a>
                        <h3 class="editorial-card-title"><a href="#">The Galveston Bay Oil Spill Imperils Thousands of Birds</a></h3>
                        <p><em><a href="" class="editorial-card-link">Map of impacted areas</a></em></p>
                      </div>
                    </div>
                  </div>
                </section>
              </div>
            </div>
          </section>
        </div>
      </div>
    </div>
  </div>
  <div class="boa-family-block-pager plate">
    <div class="columns">
      <div class="inner">
        <a href="#" class="previous"></a>
        <span class="previous-text">Plate 69</span>
        <span class="previous-title">Brown Pelican</span>
        <span class="separator"></span>
        <span class="next-text">Plate 71</span>
        <span class="next-title">Red Knot</span>
        <a href="#" class="next"></a>
      </div>
    </div>
  </div>