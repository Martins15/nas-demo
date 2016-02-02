(function($) {
  Drupal.wysiwyg.plugins.donate = {
    attach: '',
  };

  donateAddPlugin = {
    requires: 'widget',
    icons: 'donate',

    init: function( editor ) {
      editor.ui.addButton('donate', {
        label: 'Create a donate button box',
        command: 'donate',
        icon: Drupal.settings.wysiwyg.plugins.drupal.donate.module + '/icons/donate.png'
      });
      if (Drupal.settings.wysiwyg.plugins.drupal.donate.module) {
        editor.on('mode', function(ev) {
          if (ev.editor.mode == 'wysiwyg') {
            // Inject CSS files directly into the editing area head tag.
            var iframe = $('#cke_contents_' + ev.editor.name + ' iframe, #' + ev.editor.id + '_contents iframe');
            $('head', iframe.eq(0).contents()).append('<link rel="stylesheet" href="' + Drupal.settings.wysiwyg.plugins.drupal.donate.module + '/donate.css" type="text/css" >');
          }
        });
      }
      editor.widgets.add('donate', {

        template:
          '<div class="donate-bar">' +
            '<div class="donate-bar-caption">' +
          Drupal.t('Remember that Audubon depends on your support to do the conservation work that we do.') +
            '</div>' +
            '<div class="donate-bar-button"><a href="/donate" class="button tomato large">Donate</a></div>' +
          '</div>',

        editables: {
          caption: {
            selector: '.donate-bar-caption',
          },
        },

        allowedContent:
          'div(!donate-bar); div(!donate-bar-caption); div(!donate-bar-button); a(!button)',

        requiredContent: 'div(donate-bar)',

        upcast: function( element ) {
          return element.name == 'div' && element.hasClass( 'donate-bar' );
        }
      });
    }
  };
})(jQuery);
