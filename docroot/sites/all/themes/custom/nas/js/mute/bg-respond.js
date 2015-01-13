(function($) {
  $(document).bind("respond", function(e) {
    var size = "";
 
    if(e.size == "tiny" || e.size == "small") {
      size = "small";
      $(".hero-text-container .column").append($(".hero-text"));
    }
    if(e.size == "medium" || e.size == "large") {
      size = "large";
      $(".hero-header .column").append($(".hero-text"));
    }
 
    $(".bg-respond").each(function() {
      var newSrc = $(this).attr("data-bg-" + size);
      if(newSrc) {
        $(this).css("background-image", "url(" + newSrc + ")");
      }
    });
  });
})(jQuery);