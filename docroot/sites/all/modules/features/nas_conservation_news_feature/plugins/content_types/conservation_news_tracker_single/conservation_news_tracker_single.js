(function ($) {
  Drupal.behaviors.conservationNewsJumpMenu = {
    attach: function (context, settings) {
      if (context != document) {
        return;
      }
      var $titles = $('.conservation-news-title', context);
      var content = '<div class="conservation-menu-jump-menu"><div class="jump-to">Jump to:</div><ul class="jump-to-menu">';
      $titles.each(function (index, val) {
        content += '<li class="jump-to-item">';
        content += '<a href="#' + $(val).attr('id') + '">';
        content += $(val).text();
        content += '</a>';
        content += '</li>';
      });
      content += '</ul></div>';
      $('.conservation-news-block', context).first().before(content);
    }
  };
})(jQuery);
