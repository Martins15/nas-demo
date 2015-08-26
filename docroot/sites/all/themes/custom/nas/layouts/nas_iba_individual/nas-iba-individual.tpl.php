<?php
/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<section class="global-content with-padding static-page-content">
  <header class="row">
    <div class="large-10 columns">
    	<?php print $content['top']; ?>
    </div>
  </header>
  <div class="row">
    <div class="large-8 columns text-container">
    	<?php print $content['main']; ?>
    </div>
    <div class="large-4 columns sidebar">
    	<div class="row">
    		<?php print $content['sidebar']; ?>
    	</div>
    </div>
  </div>
  <?php print $content['featured']; ?>
  <section class="card-set bg-gray contextual-links-region">
    <div class="row space-top">
      <div class="column">
        <h2 class="thin">Featured Conservation Projects</h2>
      </div>
    </div>
    <div class="row">
      <div class="clearfix">

        <div class="columns large-4">
          <div class="editorial-card collapse-minimal" style="min-height: 381px;">
            <div class="editorial-card-photo">
              <a href="/conservation/project/sagebrush-ecosystem" title="Sagebrush Ecosystem"><img src="http://www.audubon.org/sites/default/files/styles/article_teaser/public/__NW_Gunnison_sage-grouses_GaryKramer_USFWS%20copy.jpg?itok=d_l0iBXX" alt="Sagebrush Ecosystem"></a>          </div>
            <div class="editorial-card-content">
              <a href="/conservation/working-lands" class="editorial-card-slug">Working Lands</a>            <h4 class="editorial-card-title"><a href="/conservation/project/sagebrush-ecosystem">Sagebrush Ecosystem</a></h4>
              <p>Balancing prairie-bird protection with our nation’s need for energy</p>
            </div>
          </div>
        </div>

        <div class="columns large-4">
          <div class="editorial-card collapse-minimal" style="min-height: 381px;">
            <div class="editorial-card-photo">
              <a href="/conservation/project/coastal-stewardship-gulf" title="Coastal Stewardship: Gulf"><img src="http://www.audubon.org/sites/default/files/styles/article_teaser/public/Gulf_314_Reddish_Egret_AndyMorffew_FlickrCC_0.jpg?itok=tkzr3ahw" alt="Coastal Stewardship: Gulf"></a>          </div>
            <div class="editorial-card-content">
              <a href="/content/sharing-our-seas-shores-1" class="editorial-card-slug">Sharing Our Seas &amp; Shores</a>            <h4 class="editorial-card-title"><a href="/conservation/project/coastal-stewardship-gulf">Coastal Stewardship: Gulf</a></h4>
              <p>Restoring vital coastal wetlands for colonial and beach-nesting birds</p>
            </div>
          </div>
        </div>

        <div class="columns large-4">
          <div class="editorial-card collapse-minimal" style="min-height: 381px;">
            <div class="editorial-card-photo">
              <a href="/conservation/project/lights-out" title="Lights Out"><img src="http://www.audubon.org/sites/default/files/styles/article_teaser/public/Light_Out_Hero__Credit_NASA-Earth-Observatory.jpg?itok=9Uses-o4" alt="Lights Out"></a>          </div>
            <div class="editorial-card-content">
              <a href="/conservation/creating-bird-friendly-communities" class="editorial-card-slug">Creating Bird-Friendly Communities</a>            <h4 class="editorial-card-title"><a href="/conservation/project/lights-out">Lights Out</a></h4>
              <p>Audubon is pioneering innovative approaches to make buildings safer for birds</p>
            </div>
          </div>
        </div>
      </div>
    </div>
  </section>
  <section class="card-set bg-1">
  	<?php print $content['cards_set']; ?>
  </section>
</section>
