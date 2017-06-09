(function ($) {
  Drupal.behaviors.conservationNewsTabSwitcher = {
    attach: function (context, settings) {
      // if (context != document) {
      //   return;
      // }
      var $list = $('.view-conservation-news-filter .filter-item a', context);
      $list.on('click', function (e) {
        e.preventDefault();
        if (!$(this).hasClass('active')) {
          $('.view-conservation-news-views-list .view', context).addClass('hidden');
          $('.view-term-id-' + $(this)
              .parent('li')
              .attr('data-term-id'), context
          )
            .removeClass('hidden');
          $($list).removeClass('active');
          $(this).addClass('active');
        }
      });
      $list.first().click();
    }
  };
})(jQuery);
