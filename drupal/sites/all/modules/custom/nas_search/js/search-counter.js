;(function($){
  Drupal.behaviors.viewLoadMoreCounterHandler = {
    attach: function (context, settings) {
      $('.view-display-id-birds').once('views-load-more-counter-handler', function () {
        $(this).bind('views_load_more.new_content', function (event, new_content) {
          var count = $(this).find('.bird-card').size();
          $(this).find('.search-counter').text(count);
        });
      });
    }
  };

  Drupal.behaviors.viewLoadMoreEditorialContentSearchCounterHandler = {
    attach: function (context, settings) {
      $('.global-content-search .view-display-id-other_results').once('views-load-more-editorial-content-search-counter-handler', function () {
        $(this).bind('views_load_more.new_content', function (event, new_content) {
          var count = $(this).find('.views-row').size();
          $('.global-content-search .search-counter').text(count);
        });
      });
    }
  };
})(jQuery);