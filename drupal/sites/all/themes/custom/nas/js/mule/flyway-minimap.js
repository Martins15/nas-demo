(function($) {

$(function() {
  $(".flyway-minimap").each(function() {
    var $minimap = $(this),
        $hero = $(".hero"),
        $altImgs = $hero.find(".hero-alt-img"),
        $contents = $(".flyway-content"),
        $points = $minimap.find(".flyway-minimap-point");

    $points.bind("click", function() {
      var $this = $(this),
          pointId = $this.attr("data-point-id"),
          $content = $contents.filter("[data-point-id='" + pointId + "']");

      $points.removeClass("current");
      $this.addClass("current");

      $altImgs.removeClass("current");
      $altImgs.filter("[data-point-id='" + pointId + "']").addClass("current");

      $contents.css("display", "none");
      $content.removeAttr("style");
    });
  });
});

})(jQuery);
