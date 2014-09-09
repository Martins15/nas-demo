(function($) {

$(function() {
  if(!$(".bird-card-set").length == 0) {  

    function setUpBirds(shouldSnap) {
      $(".bird-card-set").each(function() {
        var $this = $(this),
            $wrapper = $this.find(".bird-card-container"),
            $indicator = $this.find(".indicator"),
            scroll;

        scroll = new IScroll($wrapper[0], {
          scrollX: true,
          scrollY: false,
          momentum: false,
          snap: shouldSnap,
          bounce: true,
          touch: true,
          eventPassthrough: true,
          snapSpeed: 600
        });

        scroll.on("scrollEnd", function() {
          $indicator.find("i").removeClass("disabled");

          if(this.x == 0) {
            $indicator.find(".indicator-left").addClass("disabled");
          }
          else if(this.x == (-1000 + $this.width())) {
            $indicator.find(".indicator-right").addClass("disabled");
          }
        });
      });
    }

    $(document).bind("respond", function(e) {
      if(e.size == "tiny") {
        setUpBirds(true);
      }
      else {
        setUpBirds(false);
      }
    });
  }
});

})(jQuery);
