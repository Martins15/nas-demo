<?php
/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>

<?php print render($content['top']); ?>

<section class="global-content with-padding">
  <div class="row">
    <div class="column">
      <h1 class="centered">Audubon is committed to protecting the vital habitat along America’s coasts where people and birds intersect.</h1>
    </div>
  </div>
  <div class="row space-top">
    <div class="medium-3 medium-centered large-uncentered large-6 large-push-6 columns hide-for-tiny hide-for-small">
      <img src="<?php print base_path() . path_to_theme() . '/img/conservation-img-6.jpg'; ?>" alt="">
    </div>
    <div class="large-6 large-pull-6 columns text-container">
      <p>Booming coastal development and recreational use of beaches are rapidly eroding vital habitat for birds and other wildlife. Overfishing threatens the food supply for birds—and, in the long term, for people, too.</p>
      <div class="donate-bar">
        <div class="donate-bar-caption">Support our conservation work by contributing today.</div><div href="#" class="donate-bar-button"><a href="#" class="button tomato large">Donate</a></div>
      </div>
      <p>Sea level rise jeopardizes nesting habitat on beaches and islands at the same time that it puts coastal communities at risk. Beaches are critical nesting and migratory habitat for many species, including <a href="#">Piping Plovers</a>, <a href="#">Snowy Plovers</a>, <a href="#">Least Terns</a>, and <a href="#">American Oystercatchers</a>.</p>
      <blockquote class="pull-quote">Coastal areas have unique importance for many species of birds, offering breeding sites as well as rich sources of food for migratory stopovers.</blockquote>
    </div>
  </div>
  <div class="row space-top space-bottom double">
    <div class="medium-4 columns">
      <figure class="article-image">
        <a title="Caption for the photo here." href="<?php print base_path() . path_to_theme() . '/img/conservation-img-3.jpg'; ?>" class="lightbox cboxElement"><img src="<?php print base_path() . path_to_theme() . '/img/conservation-img-3.jpg'; ?>" alt=""></a>
        <figcaption class="caption">Caption for the photo here.</figcaption>
      </figure>
      <br />
    </div>
    <div class="medium-8 columns text-container">
      <h4 class="close-heading">Shores</h4>
      <p>Audubon’s beach stewardship program enlists local communities to steer beachgoers away from the most important nesting sites. We also empower members and friends to become a strong voice for sound coastal management practices. By using sound science, including predictive modeling, we can begin to explore potential habitat impacts from sea level rise. </p>
      <h4 class="close-heading">Seas</h4>
      <p>Marine Important Bird Areas hold great promise for stabilizing declining populations of seabirds, including Ashy Storm-Petrels, Kittlitz’s Murrelets, and Roseate Terns. Expanding the IBA program to encompass and study vital ocean sites will provide a foundation for Audubon’s development and promotion of much-needed regulation of overfishing and other threats to ocean birds and wildlife.</p>
    </div>
  </div>
  <section class="card-set bg-gray">
    <div class="row space-top">
      <div class="column">
        <h2 class="thin">Featured Seas &amp; Shores Projects</h2>
      </div>
    </div>
    <div class="row card-set-wrapper">
      <div class="clearfix card-set-scroller">
        <div class="tiny-4 columns">
          <div class="editorial-card">
            <div class="editorial-card-photo">
              <a href="#"><img src="<?php print base_path() . path_to_theme() . '/img/editorial-card-10.jpg'; ?>" alt=""></a>
            </div>
            <div class="editorial-card-content">
              <h3 class="editorial-card-title"><a href="#">Here’s the Name of a Conservation Project</a></h3>
              <p>Along with the title, we should include a short description of the project. </p>
            </div>
          </div>
        </div>
        <div class="tiny-4 columns">
          <div class="editorial-card">
            <div class="editorial-card-photo">
              <a href="#"><img src="<?php print base_path() . path_to_theme() . '/img/editorial-card-11.jpg'; ?>" alt=""></a>
            </div>
            <div class="editorial-card-content">
              <h3 class="editorial-card-title"><a href="#">Another Current Seas &amp; Shores Project</a></h3>
              <p>Along with the title, we should include a short description of the project. </p>
            </div>
          </div>
        </div>
        <div class="tiny-4 columns">
          <div class="editorial-card">
            <div class="editorial-card-photo">
              <a href="#"><img src="<?php print base_path() . path_to_theme() . '/img/editorial-card-12.jpg'; ?>" alt=""></a>
            </div>
            <div class="editorial-card-content">
              <h3 class="editorial-card-title"><a href="#">Another Current Seas &amp; Shores Project</a></h3>
              <p>Along with the title, we should include a short description of the project. </p>
            </div>
          </div>
        </div>
      </div>
    </div>
    <div class="row space-bottom double">
      <div class="card-set-dots">
        <div class="dot"></div>
        <div class="dot active"></div>
        <div class="dot"></div>
      </div>
    </div>
  </section>
  <div class="row section-header space-top double">
    <div class="column">
      <h2 class="thin">More On Seas &amp; Shores</h2>
    </div>
  </div>
  <div class="row">

    <!-- BEGIN SIDEBAR -->

    <div class="sidebar large-push-8 large-4 columns">
      <div class="editorial-card">
        <div class="editorial-card-photo">
          <img src="<?php print base_path() . path_to_theme() . '/img/editorial-card-12.jpg'; ?>" alt="">
        </div>
        <div class="editorial-card-content short">
          <h4 class="editorial-card-title"><a href="#">Seas &amp; Shores Related News Item</a></h4>
          <p>Along with the title, we should include a short description of the article.</p>
        </div>
      </div>
      <div class="editorial-card">
        <div class="editorial-card-photo">
          <img src="<?php print base_path() . path_to_theme() . '/img/editorial-card-11.jpg'; ?>" alt="">
        </div>
        <div class="editorial-card-content short">
          <h4 class="editorial-card-title"><a href="#">Another Seas &amp; Shores Related News Item</a></h4>
          <p>Along with the title, we should include a short description of the article.</p>
        </div>
      </div>
    </div>

    <!-- END SIDEBAR -->

    <!-- BEGIN MAIN COLUMN -->

    <div class="large-8 large-pull-4 columns index-list">
      <div class="editorial-card index">
        <div class="row">
          <div class="tiny-4 columns">
            <div class="editorial-card-photo">
              <img src="<?php print base_path() . path_to_theme() . '/img/editorial-card-index-6.jpg'; ?>" alt="">
            </div>
          </div>
          <div class="tiny-8 columns">
            <div class="editorial-card-content">
              <h4 class="editorial-card-title"><a href="#">This is Another Seas &amp; Shores Project That’s Not Featured Up Above</a></h4>
              <p>Along with the title, we should include a short description of the project.</p>
            </div>
          </div>
        </div>
      </div>
      <div class="editorial-card index">
        <div class="row">
          <div class="tiny-4 columns">
            <div class="editorial-card-photo">
              <img src="<?php print base_path() . path_to_theme() . '/img/editorial-card-index-1.jpg'; ?>" alt="">
            </div>
          </div>
          <div class="tiny-8 columns">
            <div class="editorial-card-content">
              <h4 class="editorial-card-title"><a href="#">The River-Style List of Projects Can Extend as Long as Needed (or Paginate)</a></h4>
              <p>Along with the title, we should include a short description of the project.</p>
            </div>
          </div>
        </div>
      </div>
      <div class="editorial-card index">
        <div class="row">
          <div class="tiny-4 columns">
            <div class="editorial-card-photo">
              <img src="<?php print base_path() . path_to_theme() . '/img/editorial-card-index-2.jpg'; ?>" alt="">
            </div>
          </div>
          <div class="tiny-8 columns">
            <div class="editorial-card-content">
              <h4 class="editorial-card-title"><a href="#">Another Conservation Project Teaser Goes Right Here</a></h4>
              <p>Along with the title, we should include a short description of the project.</p>
            </div>
          </div>
        </div>
      </div>
      <div class="editorial-card index">
        <div class="row">
          <div class="tiny-4 columns">
            <div class="editorial-card-photo">
              <img src="<?php print base_path() . path_to_theme() . '/img/editorial-card-index-3.jpg'; ?>" alt="">
            </div>
          </div>
          <div class="tiny-8 columns">
            <div class="editorial-card-content">
              <h4 class="editorial-card-title"><a href="#">The River-Style List of Projects Can Extend as Long as Needed (or Paginate)</a></h4>
              <p>Along with the title, we should include a short description of the project.</p>
            </div>
          </div>
        </div>
      </div>
      <div class="editorial-card index">
        <div class="row">
          <div class="tiny-4 columns">
            <div class="editorial-card-photo">
              <img src="<?php print base_path() . path_to_theme() . '/img/editorial-card-index-7.jpg'; ?>" alt="">
            </div>
          </div>
          <div class="tiny-8 columns">
            <div class="editorial-card-content">
              <h4 class="editorial-card-title"><a href="#">Another Conservation Project Teaser Goes Right Here</a></h4>
              <p>Along with the title, we should include a short description of the project.</p>
            </div>
          </div>
        </div>
      </div>
    </div>

    <!-- END MAIN COLUMN -->

  </div>

  <section class="card-set bg-1">
    <div class="row">
      <div class="column">
        <h1 class="card-set-heading pea-green">These birds need your help</h1>
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
              <img src="<?php print base_path() . path_to_theme() . '/img/engagement-card-1.jpg'; ?>" alt="">
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
              <img src="<?php print base_path() . path_to_theme() . '/img/engagement-card-2.jpg'; ?>" alt="">
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
              <img src="<?php print base_path() . path_to_theme() . '/img/engagement-card-3.jpg'; ?>" alt="">
            </div>
          </div>
        </div>
      </div>
    </div>
    <div class="row">
      <div class="card-set-dots light">
        <div class="dot"></div>
        <div class="dot active"></div>
        <div class="dot"></div>
      </div>
    </div>
    <div class="row">
      <div class="card-set-social social-sharing">
        <span class="social-sharing-caption white">Spread the word. It’s the least you can do.</span>
        <a class="social-sharing-icon white" href="#"><i class="icon-twitter"></i></a>
        <a class="social-sharing-icon white" href="#"><i class="icon-facebook"></i></a>
        <a class="social-sharing-icon white" href="#"><i class="icon-mail"></i></a>
      </div>
    </div>
  </section>
</section>
