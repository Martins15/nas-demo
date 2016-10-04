(function ($) {
  /**
   * Hide content when we are in edit mode for better visualization, and provide possibility display content
   * using a button.
   */
  Drupal.nasPanelsIPECustomization = function (key, ipe, context) {
    var show_text = Drupal.t('Show content');
    var hide_text = Drupal.t('Hide content');
    Drupal.PanelsIPE.editors[key].saveEditing = function () {
      $('div.panels-ipe-region', ipe.topParent).each(function () {
        // We don't want to process not visible regions.
        // This is needed cause we have the same region printed several times in our layouts.
        if (!$(this).is(':visible')) {
          return;
        }
        var val = '';
        var region = $(this).attr('id').split('panels-ipe-regionid-')[1];
        $(this).find('div.panels-ipe-portlet-wrapper').each(function () {
          var id = $(this).attr('id').split('panels-ipe-paneid-')[1];
          if (id) {
            if (val) {
              val += ',';
            }
            val += id;
          }
        });
        $('[name="panel[pane][' + region + ']"]', ipe.control).val(val);
      });
    };
    Drupal.PanelsIPE.editors[key].endEditing = function () {
      ipe.editing = false;
      ipe.lockPath = null;
      $('.panels-ipe-form-container').empty();
      // Re-show all the IPE non-editing meta-elements
      $('div.panels-ipe-off').show('fast');

      // Refresh the container and control jQuery objects.
      ipe.container = $(ipe.container.selector);
      ipe.control = $(ipe.control.selector);

      ipe.showButtons();
      // Re-hide all the IPE meta-elements
      $('div.panels-ipe-on').hide();

      $('.panels-ipe-editing').removeClass('panels-ipe-editing');
      $('div.panels-ipe-sort-container.ui-sortable', ipe.topParent).sortable("destroy");
      $('body.panels-ipe').trigger('endIPE');
    };
    if (Drupal.PanelsIPE.editors[key].editing) {
      // Disable the Leave Page dialog warning.
      // @see Drupal.behaviors.PanelizerIPE.
      window.onbeforeunload = null;

      var $wrap = $('.nas-panels-ipe-collapsible-wrapper:not(.processed)', context);
      if ($wrap.length > 0) {
        $wrap.addClass('processed').each(function () {
          var $content = $('.panels-ipe-portlet-content', $(this));
          $content.show();
          $('.nas-panels-ipe-button', $(this)).addClass('open').parent().show();
          $('.nas-panels-ipe-button', $(this)).click(function () {
            if ($(this).hasClass('open')) {
              $(this).removeClass('open');
              $(this).html(show_text);
              $content.slideUp();
            }
            else {
              $(this).addClass('open');
              $(this).html(hide_text);
              $content.slideDown();
            }
          });
        });
      }
    }
    // Show content and remove all events if editing is finished.
    if (!$('.panels-ipe-display-container').hasClass('panels-ipe-editing')) {
      var $btn_wrap = $('.nas-panels-ipe-collapsible-wrapper');
      if ($btn_wrap.length > 0) {
        $btn_wrap.each(function () {
          $('.panels-ipe-portlet-content', $(this)).show();
          var $button = $('.nas-panels-ipe-button', $(this));
          $button.parent().hide();
          $button.removeClass('open');
          $button.html(hide_text);
          $button.unbind('click');
          $(this).removeClass('processed');
        });
      }
    }
  };

  /**
   * IPE customizations.
   */
  Drupal.behaviors.nas_panels_ipe = {
    attach: function (context, settings) {
      for (var i in settings.PanelsIPECacheKeys) {
        var key = settings.PanelsIPECacheKeys[i];
        Drupal.nasPanelsIPECustomization(key, Drupal.PanelsIPE.editors[key], context);
      }
    }
  };
})(jQuery);
