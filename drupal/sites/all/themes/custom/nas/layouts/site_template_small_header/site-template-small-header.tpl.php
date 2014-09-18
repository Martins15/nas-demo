<?php
/**
 * @file
 * Site template with small header.
 */
?>

<body>
  <header class="global-header alt standard">
    <?php print $content['header']; ?>
    <?php print $content['main']; ?>
  
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
  <footer class="global-footer">
    <?php print $content['footer']; ?>
    <section class="footer-site-map">
    <div class="row">
      <div class="medium-12 large-3 columns">
        <img class="footer-logo" src="../../../img/footer-logo.png" alt="">
        <h5>National Audubon Society</h5>
        <p>Our mission is to conserve and restore natural ecosystems, focusing on birds, other wildlife,  and their habitats for the benefit of humanity and the earth’s biological diversity.</p>
      </div>
      <div class="tiny-6 medium-4 large-3 columns">
        <ul class="footer-nav">
          <li><a href="#">Home</a></li>
          <li><a href="#">News</a></li>
          <li><a href="#">Features</a></li>
          <li><a href="#">Birds</a></li>
          <li><a href="#">Conservation</a></li>
          <li><a href="#">Get Outside</a></li>
          <li><a href="#">Magazine</a></li>
        </ul>
      </div>
      <div class="tiny-6 medium-4 large-3 columns">
        <ul class="footer-nav">
          <li><a href="#">About Us</a></li>
          <li><a href="#">Newsroom</a></li>
          <li><a href="#">Audubon Campus</a></li>
          <li><a href="#">Careers</a></li>
          <li><a href="#">Contact Us</a></li>
        </ul>
      </div>
      <div class="medium-4 large-3 columns">
        <ul class="footer-nav">
          <li><a href="#">Join the National Audubon Society</a></li>
          <li><a href="#">Update Your Information</a></li>
          <li><a href="#">Member Services</a></li>
          <li><a href="#">How to Help</a></li>
          <li><a href="#">Donate to Audubon</a></li>
          <li><a href="#">Online Store</a></li>
          <li><a href="#">Audubon Near You</a></li>
          <li><a href="#">Find a Local Chapter</a></li>
        </ul>
      </div>
    </div>
  </section>
  <section class="footer-copyright">
    <div class="row">
      <div class="column">
        <p>Copyright © 2014 National Audubon Society, Inc. <span class="footer-copyright-links"><a href="#">Legal Notices</a> <a href="#">Privacy Policy</a> <a href="#">Contact Us</a></span></p>
      </div>
    </div>
  </section>
</footer>

  <!-- DEMO SCRIPT -->
  <script>

    $(".load-more").bind("click", function(e) {
      e.preventDefault();
      var $this = $(this),
          $container = $(".bird-card-grid-container"),
          $cards = $container.contents(".columns").slice(0, 12).clone().addClass("invisible");

      $this.addClass("active");

      $(".bg-egg").css("display", "none");

      setTimeout(function() {
        $container.append($cards);
        $cards.removeClass("invisible");
        $this.removeClass("active");
      }, 1500);
    });

    $(".bird-guide-search select").bind("change", function(e) {
      var $this = $(this),
          $container = $(".bird-card-grid-container"),
          $cards = $container.contents(".columns").slice(0, 12).clone();

      $container.find(".bird-card").addClass("disappear");
      $(".bird-card.disappear").bind("animationend webkitAnimationEnd oanimationend MSAnimationEnd", function() {
        $(this).addClass("invisible");
      });
      setTimeout(function() {
        $(".bird-card-grid .section-header h2").text("Matching Birds");
        $container.children().remove();
        $container.append($cards);
      }, 1500);
    });

  </script>