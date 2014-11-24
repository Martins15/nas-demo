(function($) {
  Drupal.behaviors.card_equalizer = {
    attach: function(context, settings) {
      // Define the selector for finding card rows
      var SELECTOR_STRING = "" +
          ".large-4 + .large-4 > .editorial-card" +
          ", .large-6 + .large-6 > .editorial-card" +
          ", .large-8 + .large-4 > .editorial-card" +
          ", .large-4 + .large-4 > .engagement-card" +
          ", .tiny-4 + .tiny-4 > .engagement-card" +
          ", .tiny-4 + .tiny-4 > .editorial-card";

      var $cardRows = $(".row").has(SELECTOR_STRING);

      function equalizeCards() {
        $cardRows.each(function() {
          var $this = $(this),
              $cardsEd = $this.find(".editorial-card"),
              $contentsEd = $cardsEd.find(".editorial-card-content"),
              $cardsEng = $this.find(".engagement-card"),
              $contentsEng = $cardsEng.find(".engagement-card-content"),
              cardEdHeights = new Array(),
              contentsEngHeights = new Array(),
              maxHeight = 0,
              minHeight = 0;

          // Fix height for Edotiral blocks.
          $cardsEd.each(function() {
            var $this = $(this);
            cardEdHeights.push($this.outerHeight());
          });

          maxHeightEd = Math.max.apply(null, cardEdHeights);
          minHeightEd = Math.min.apply(null, cardEdHeights);
          deltaEd = maxHeightEd - minHeightEd;

          if (deltaEd < 120 && deltaEd > 0) {
            $cardsEd.css({"min-height": maxHeightEd + "px"});
          }

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
        $(".editorial-card-content, .engagement-card-content").removeAttr("style");

        // We want to wait for stuff to load and render before we get down to business
        setTimeout(function() {
          equalizeCards();
        }, 50);
      });
    }
  };
})(jQuery);
