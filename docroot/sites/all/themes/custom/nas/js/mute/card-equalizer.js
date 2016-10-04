(function ($) {
  Drupal.behaviors.card_equalizer = {
    attach: function (context, settings) {
      /**
       * Set same height for all blocks in variables.
       *
       * @param $cardsEd
       *   Editorial cards.
       * @param $cardsEng
       *   Engagement cards.
       */
      function equalizeCards($cardsEd, $cardsEng) {
        $cardsEd.not(".skip-nas-equalization").removeAttr("style");
        $cardsEng.not(".skip-nas-equalization").removeAttr("style");
        var $contentsEng = $cardsEng.find(".engagement-card-content"),
          cardEdHeights = [],
          contentsEngHeights = [];

        // Fix height for Editorial blocks.
        $cardsEd.each(function () {
          var $this = $(this);
          cardEdHeights.push($this.outerHeight());
        });
        var union_block = $cardsEd.length > 0 && $cardsEng.length > 0;
        if (union_block) {
          $cardsEng.each(function () {
            var height = 0;
            $(this).children().each(function () {
              height += $(this).outerHeight();
            });
            cardEdHeights.push(height);
          });
        }

        var maxHeightEd = Math.max.apply(null, cardEdHeights);

        if (union_block) {
          $cardsEd.css({"min-height": (maxHeightEd) + "px"});
          $cardsEng.css({"min-height": (maxHeightEd) + "px"});
          return;
        }
        $cardsEd.css({"min-height": maxHeightEd + 7 + "px"});
        // Fix height for Engagements blocks.
        if ($contentsEng.length == 0) {
          return;
        }
        $contentsEng.each(function () {
          var $this = $(this);
          contentsEngHeights.push($this.outerHeight());
        });

        var maxHeightEng = Math.max.apply(null, contentsEngHeights);
        var minHeightEng = Math.min.apply(null, contentsEngHeights);
        var deltaEng = maxHeightEng - minHeightEng;

        if (deltaEng < 120 && deltaEng > 0) {
          $contentsEng.css({"min-height": maxHeightEng + "px"});
        }
      }

      /**
       * Start equalizer and bind callback on image load.
       *
       * @param parent
       *   Parents of editorial cards.
       * @param $cardsEd
       *   Editorial cards.
       * @param $cardsEng
       *   Engagement cards.
       */
      function equalizeCardsStart(parent, $cardsEd, $cardsEng) {
        equalizeCards($cardsEd, $cardsEng);
        parent.find('img').bind('load', function () {
          equalizeCards($cardsEd, $cardsEng);
        });
      }

      /**
       * Initialize equalizer script.
       */
      function equalizeCardsInit() {
        // Define the selector for finding card rows.
        var SELECTOR_STRING = "" +
          ".large-4 + .large-4 > .editorial-card" +
          ", .large-3 + .large-3 > .editorial-card" +
          ", .large-6 + .large-6 > .editorial-card" +
          ", .large-8 + .large-4 > .editorial-card" +
          ", .large-4 + .large-4 > .engagement-card" +
          ", .tiny-4 + .tiny-4 > .engagement-card" +
          ", .tiny-4 > .editorial-card";
        // We want to wait for stuff to load and render before we get down to business.
        setTimeout(function () {
          // Do not work with outer rows.
          $('.row').has(SELECTOR_STRING).not($('.row').has('.row')).each(function () {
            equalizeCardsStart(
              $(this),
              $(".editorial-card", $(this)),
              $(".engagement-card", $(this))
            );
          });
          // 2x Editorial & 2x small blocks.
          var cards = $('.editorial-card-2x-small .columns > .editorial-card');
          equalizeCardsStart(cards, cards, $());
        }, 500);
      }

      // Initialize equalizer when document is ready.
      $(document).bind("ready", function (e) {
        equalizeCardsInit();
      });
      // Remove exist events and initialize equalizer when triggered endIPE event.
      $(document).unbind('endIPE');
      $(document).bind("endIPE", function (e) {
        equalizeCardsInit();
      });
    }
  };
})(jQuery);
