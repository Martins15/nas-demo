<?php
/**
 * @file
 * Site template with small header.
 */
?>

<header class="global-header alt standard">
  <?php print $content['header']; ?>
<?php print $content['main']; ?>
<?php print $content['footer']; ?>

  <!-- DEMO SCRIPT -->
  <script>
(function($) {
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
})(jQuery);
  </script>