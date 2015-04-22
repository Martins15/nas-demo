(function($) {
  Drupal.behaviors.frontpage_featured_curtain_package = {
    attach: function(context, settings) {
      var $header = $(".curtain > .global-header");
      var $curtainFeaturedHeader = $(".curtain-package .curtain-featured");
      var $curtainWrapper = $(".curtain-wrapper:eq(0)");
      var $curtainFallback = $(".curtain-fallback:eq(0)");
      var $curtainFallbackContent = $(".curtain-fallback-content:eq(0)", $curtainFallback);

      $(window).resize(function() {
        var headerHeight = $header.height();
        var widths = ['medium-8', 'medium-9', 'medium-10', 'medium-11', 'medium-12']
        $curtainFeaturedHeader.removeClass(widths.join(' '));
        for (var i in widths) {
          if ($curtainFeaturedHeader.offset().top >= headerHeight) {
            break;
          }
          $curtainFeaturedHeader.addClass(widths[i]);
        }
        if ($curtainFallback.css('display') == 'block') {
          $curtainFallback.css('height', '');
          $curtainFallbackContentHeight = $curtainFallbackContent.height() + 25;
          if ($curtainFallback.height() < $curtainFallbackContentHeight) {
            $curtainFallback.css('height', $curtainFallbackContentHeight);
          }
          else {

          }
        }
      });
    }
  };
})(jQuery);
