(function($) {

$(function() {
  $(".flyway-megamap").each(function() {
    var $megamap = $(this),
        $points = $megamap.find(".flyway-megamap-point"),
        $dots = $(".flyway-path-dots"),
        $maps = $(".flyway-path-map"),
        $descriptions = $(".flyway-path-description");

    console.log($descriptions);

    handleResize();

    function handleResize() {
      var windowWidth = $(window).width(),
          xlgPositions = [[90, 110], [340, 75], [540, 140], [740, 70]],
          lrgPositions = [[20, 110], [280, 75], [440, 140], [620, 70]];
          positions = [];

      if (windowWidth >= 900) { 
        positions = xlgPositions; 
        repositionPoints(positions);
      }
      else if (windowWidth >=768) { 
        positions = lrgPositions; 
        repositionPoints(positions);
      }
      else {
        $points.removeAttr("style");
      }
    }

    function handleFlywaySwitch(e) {
      e.preventDefault();

      $('html, body').animate({
        scrollTop: $("#flyway-map").offset().top
      }, 300);

      var $this = $(this),
          mapId = $this.attr("id").replace("point", "map"),
          descriptionId = $this.attr("id").replace("point", "path-description"),
          $description = $descriptions.filter("#" + descriptionId),
          $map = $maps.filter("#" + mapId);

      console.log(descriptionId);

      $maps.removeClass("current");
      $map.addClass("current");
      $descriptions.removeClass("current");
      $description.addClass("current");
    }

    function handleDotClick(e)  {
      e.preventDefault();

      var $this = $(this),
          $map = $maps.filter($this.attr("href")),
          $description = $maps.filter($this.attr("href"));

      console.log($this);

      $maps.removeClass("current");
      $map.addClass("current");
//      $descriptions.removeClass("current");
//      $description.addClass("current");
    }

    function repositionPoints(positions) {
      $points.each(function(i) {
        $(this).css({
          "left": positions[i][0],
          "top": positions[i][1]
        });
      });
    }

    // Reposition the points on resize
    $(window).bind("resize", handleResize);
    $points.bind("click", handleFlywaySwitch);
    $dots.find(".dot").bind("click", handleDotClick);

  });
});

})(jQuery);
