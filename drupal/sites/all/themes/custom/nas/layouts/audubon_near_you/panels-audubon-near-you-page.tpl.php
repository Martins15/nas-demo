<?php
/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<?php print $content['header']; ?>

<?php print $content['main']; ?>
<div class="audubon-near-you--global-content-wrapper">
  <section class="global-content no-padding blocks-events">
    <div class="row">
      <?php print $content['locations']; ?>
    </div>
  </div>
  </section>
  <!-- ******************************************************************* -->
  <div class="bird-card-set bg-bone-white">
    <div class="row section-header space-top">
      <div class="columns">
        <h2 class="thin">The Audubon Bird Guide</h2>
      </div>
      <div class="columns">
        <ul class="section-nav inline-list">
          <li class="hide-for-small hide-for-tiny"><a href="#">Explore Our Bird Guide</a></li>
          <li><a href="#">Identify a Bird</a></li>
          <li><a class="cta" href="#">Adopt a Bird</a></li>
        </ul>
      </div>
    </div>
    <div class="row bird-card-container">
      <div class="bird-card-scroller" style="transition: 0ms cubic-bezier(0.1, 0.57, 0.1, 1); -webkit-transition: 0ms cubic-bezier(0.1, 0.57, 0.1, 1); transform: translate(0px, 0px) translateZ(0px);">
        <div class="columns tiny-3">
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
        <div class="columns tiny-3">
          <figure class="bird-card">
            <div class="bird-card-illustration">
              <a href="#"><img src="../../img/bird-2.png" alt=""></a>
            </div>
            <figcaption class="bird-card-caption">
              <h4 class="common-name"><a href="#">Bullock's Oriole</a></h4>
              <p class="scientific-name">Icterus Bullocki</p>
            </figcaption>
            <a href="#" class="icon-sound-full bird-card-audio"></a>
          </figure>
        </div>
        <div class="columns tiny-3">
          <figure class="bird-card">
            <div class="bird-card-illustration">
              <a href="#"><img src="../../img/bird-3.png" alt=""></a>
            </div>
            <figcaption class="bird-card-caption">
              <h4 class="common-name"><a href="#">Pileated Woodpecker</a></h4>
              <p class="scientific-name">Dryocopus pileatus</p>
            </figcaption>
            <a href="#" class="icon-sound-full bird-card-audio"></a>
          </figure>
        </div>
        <div class="columns tiny-3">
          <figure class="bird-card">
            <div class="bird-card-illustration">
              <a href="#"><img src="../../img/bird-4.png" alt=""></a>
            </div>
            <figcaption class="bird-card-caption">
              <h4 class="common-name"><a href="#">Western Scrub‑Jay</a></h4>
              <p class="scientific-name">Aphelocoma californica</p>
            </figcaption>
            <a href="#" class="icon-sound-full bird-card-audio"></a>
          </figure>
        </div>
      </div>
      <div class="row indicator space-bottom">
        <div class="column">
          <p><i class="indicator-left icon-arrow-left disabled"></i>&nbsp;&nbsp;&nbsp;<i class="indicator-right icon-arrow-right"></i></p>
        </div>
      </div>
    </div>
  </div>
  <!-- ************************************************************** -->
  <div class="bg-gray">
    <div class="row section-header">
      <div class="column">
        <h2 class="thin">Birds in the News</h2>
      </div>
      <div class="column">
        <ul class="section-nav inline-list hide-for-small hide-for-tiny">
          <li><a href="#">More News »</a></li>
        </ul>
      </div>
    </div>
    <div class="row aid-class">
      <div class="columns large-4">
        <div class="editorial-card collapse-minimal">
          <div class="editorial-card-photo">
            <img src="../../img/editorial-card-14.jpg">
          </div>
          <div class="editorial-card-content short">
            <a href="" class="editorial-card-slug">In The News</a>
            <h4 class="editorial-card-title">Bird Death Toll Estimates from the BP Oil Spill</h4>
            <p><em><a class="editorial-card-link" href="#">Map of impacted areas</a></em></p>
          </div>
        </div>
      </div>
      <div class="columns large-4">
        <div class="editorial-card collapse-minimal">
          <div class="editorial-card-photo">
            <img src="../../img/editorial-card-2.jpg">
          </div>
          <div class="editorial-card-content short">
            <a href="" class="editorial-card-slug">Citizen Science</a>
            <h4 class="editorial-card-title">Latest Data from the 2014 Great Backyard Bird Count</h4>
            <p><em><a href="#" class="editorial-card-link">Exlpore the results</a></em></p>
          </div>
        </div>
      </div>
      <div class="columns large-4">
        <div class="editorial-card collapse-minimal">
          <div class="editorial-card-photo">
            <img src="../../img/editorial-card-3.jpg">
          </div>
          <div class="editorial-card-content short">
            <a href="" class="editorial-card-slug">Conservation</a>
            <h4 class="editorial-card-title">Clues to Conserving the Golden Eagle in Its DNA</h4>
            <p><em><a href="#" class="editorial-card-link">Genome sequencing yields new insights</a></em></p>
          </div>
        </div>
      </div>
    </div>
    <div class="row space-bottom double">
      <div class="columns">
        <ul class="section-nav inline-list hide-for-medium hide-for-large hide-for-xlarge">
          <li><a href="#">More News »</a></li>
        </ul>
      </div>
    </div>
  </div>
</div>
