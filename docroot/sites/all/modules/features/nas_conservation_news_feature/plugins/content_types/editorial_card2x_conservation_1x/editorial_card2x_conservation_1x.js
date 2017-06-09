(function ($) {
  Drupal.behaviors.conservationNewsTabSwitcher = {
    attach: function (context, settings) {
      $('.editorial-card-2x-conservation-news-block', context)
        .once('editorial-card-2x-conservation-news-block')
        .each(function() {
          var block = this;
          var $list = $('.view-conservation-news-filter .filter-item a', block);
          $list.on('click', function (e) {
            e.preventDefault();
            if (!$(this).hasClass('active')) {
              $('.view-conservation-news-views-list .view', block).addClass('hidden');
              $('.view-term-id-' + $(this).attr('data-term-id'), block).removeClass('hidden');
              $($list).removeClass('active');
              $(this).addClass('active');
              setTimeout(function() { $(window).trigger('resize'); }, 0);
            }
          });
          $list.first().trigger('click');
        });

      $('.editorial-card-2x-conservation-news-block .view:not(hidden)').once().each(function() {
        if (context != document) {
          $(window).trigger('resize');
        }
      });
    }
  };
})(jQuery);
