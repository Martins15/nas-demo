(function($) {
  Drupal.wysiwyg.plugins.bottom_line = {
    attach: '',
  };

  bottom_lineAddPlugin = {
    requires: 'widget',
    icons: 'bottom_line',

    init: function( editor ) {
      editor.ui.addButton('bottom_line', {
        label: 'Create a bottom line box',
        command: 'bottom_line',
        icon: Drupal.settings.wysiwyg.plugins.drupal.bottom_line.module + '/icons/bottom_line.png'
      });
      if (Drupal.settings.wysiwyg.plugins.drupal.bottom_line.module) {
        editor.on('mode', function(ev) {
          if (ev.editor.mode == 'wysiwyg') {
            // Inject CSS files directly into the editing area head tag.
            var iframe = $('#cke_contents_' + ev.editor.name + ' iframe, #' + ev.editor.id + '_contents iframe');
            $('head', iframe.eq(0).contents()).append('<link rel="stylesheet" href="' + Drupal.settings.wysiwyg.plugins.drupal.bottom_line.module + '/bottom_line.css" type="text/css" >');
          }
        });
      }
      editor.widgets.add('bottom_line', {

        template:
          '<div class="page-summary bottom-line">' +
            '<h4 class="page-summary-title">The Bottom Line</h4>' +
            '<p class="page-summary-body">This project has a conservation impact on 1.8 million acres of land and improved outcomes for four priority bird species.</p>' +
          '</div>',

        editables: {
          caption: {
            selector: '.page-summary-title',
          },
          text: {
            selector: '.page-summary-body',
          },
        },

        allowedContent:
          'div(!bottom-line); h4(!page-summary-title); p(!page-summary-body);',

        requiredContent: 'div(!bottom-line); h4(!page-summary-title); p(!page-summary-body);',

        upcast: function( element ) {
          return element.name == 'div' && element.hasClass( 'bottom-line' );
        }
      });
    }
  };
})(jQuery);
