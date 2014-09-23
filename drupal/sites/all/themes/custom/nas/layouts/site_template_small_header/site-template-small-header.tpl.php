<?php
/**
 * @file
 * Site template with small header.
 */
?>

<header class="global-header alt standard">
  <?php print $content['header']; ?>
</header>
<section class="global-content">
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
<?php print $content['footer']; ?>

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