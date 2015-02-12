(function($) {
  Drupal.behaviors.card_equalizer = {
    attach: function(context, settings) {
      // Define the selector for finding card rows
      var SELECTOR_STRING = "" +
          ".large-4 + .large-4 > .editorial-card" +
          ", .large-3 + .large-3 > .editorial-card" +
          ", .large-6 + .large-6 > .editorial-card" +
          ", .large-8 + .large-4 > .editorial-card" +
          ", .large-4 + .large-4 > .engagement-card" +
          ", .tiny-4 + .tiny-4 > .engagement-card" +
          ", .tiny-4 > .editorial-card";

      // Do not work with outer rows.
      var $cardRows = $(".row").has(SELECTOR_STRING).not($(".row").has('.row'));

      function equalizeCards(size) {
        $cardRows.each(function() {
          var $this = $(this),
              $cardsEd = $this.find(".editorial-card"),
              $cardsEng = $this.find(".engagement-card"),
              $contentsEng = $cardsEng.find(".engagement-card-content"),
              cardEdHeights = new Array(),
              contentsEngHeights = new Array();

          // Fix height for Editorial blocks.
          $cardsEd.each(function() {
            var $this = $(this);
            cardEdHeights.push($this.outerHeight());
          });

          maxHeightEd = Math.max.apply(null, cardEdHeights);
          minHeightEd = Math.min.apply(null, cardEdHeights);
          deltaEd = maxHeightEd - minHeightEd;

          $cardsEd.css({"min-height": (maxHeightEd + 7) + "px"});

          // Fix height for Engagements blocks.
          $contentsEng.each(function() {
            var $this = $(this);
            contentsEngHeights.push($this.outerHeight());
          });

          maxHeightEng = Math.max.apply(null, contentsEngHeights);
          minHeightEng = Math.min.apply(null, contentsEngHeights);
          deltaEng = maxHeightEng - minHeightEng;

          if (deltaEng < 120 && deltaEng > 0) {
            $contentsEng.css({"min-height": maxHeightEng + "px"});
          }

        });
      }

      $(document).bind("respond", function(e) {
        $(".editorial-card, .engagement-card-content")
          .not(".skip-nas-equalization")
          .removeAttr("style");
        // We want to wait for stuff to load and render before we get down to business
        setTimeout(function() {
          equalizeCards(e.size);
        }, 500);
      });
    }
  };
})(jQuery);
