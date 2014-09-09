(function($) {

$(function() {
  // Define the selector for finding card rows
  var SELECTOR_STRING = "" +
      ".large-4 + .large-4 > .editorial-card" +
      ", .large-8 + .large-4 > .editorial-card" +
      ", .large-4 + .large-4 > .engagement-card" +
      ", .tiny-4 + .tiny-4 > .engagement-card" + 
      ", .tiny-4 + .tiny-4 > .editorial-card"; 

  var $cardRows = $(".row").has(SELECTOR_STRING);

  function equalizeCards() {
    $cardRows.each(function() {
      var $this = $(this),
          $cards = $this.find(".editorial-card, .engagement-card"),
          $contents = $cards.find(".editorial-card-content, .engagement-card-content");
          cardHeights = new Array(),
          maxHeight = 0,
          minHeight = 0;

      $cards.each(function() {
        var $this = $(this);

        cardHeights.push($this.outerHeight());
      });

      maxHeight = Math.max.apply(null, cardHeights);
      minHeight = Math.min.apply(null, cardHeights);
      delta = maxHeight - minHeight;

      if(delta < 120 && delta > 0) {
        $cards.css({"min-height": maxHeight + "px"});
      }
    });
  }

  $(document).bind("respond", function(e) {
    $(".editorial-card-content, .engagement-card-content").removeAttr("style");

    // We want to wait for stuff to load and render before we get down to business
    setTimeout(function() {
      equalizeCards();
    }, 50);
  });
});

})(jQuery);
