(function ($) {
  Drupal.behaviors.audubon_netx = {
    attach: function (context, settings) {
      $('.audubon-netx-preview .form-item input', context).once('audubon-netx-selected', function () {
        $(this).bind('change', function () {
          $('.audubon-netx-preview tr.netx-selected', context).removeClass('netx-selected');
          $(this).parents('tr').addClass('netx-selected');
        });
      });
    }
  };
})(jQuery);
