(function ($) {
  Drupal.behaviors.hide_comment_settings = {
    attach: function (context, settings) {
      $('#edit-panelizer-page-manager-name', context).once('hide-comments', function () {
        var page_manager_el = $(this);
        $(this).bind('change', function () {
            // Get index of comment settings group.
            var index = $('#edit-comment-settings').index();
            var vertical_tabs = $('#edit-comment-settings').parents('.vertical-tabs');
            // Hide comment settings vertical tab if press release layout
            // selected.
            if (page_manager_el.val() == 'node:article:press_release') {
              $('.vertical-tabs-list .vertical-tab-button:eq('+index+')', vertical_tabs).hide();
            }
            else {
              $('.vertical-tabs-list .vertical-tab-button:eq('+index+')', vertical_tabs).show();
            }
          })
          .trigger('change');
      });
    }
  };
})(jQuery);
