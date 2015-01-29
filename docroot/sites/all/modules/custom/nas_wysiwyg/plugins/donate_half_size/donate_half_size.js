(function($) {
  Drupal.wysiwyg.plugins.donate_half_size = {
    attach: ''
  };

  donateHalfSizeAddPlugin = {
    requires: 'widget',
    icons: 'donate_half_size',

    init: function( editor ) {
      editor.ui.addButton('donate_half_size', {
        label: 'Create a donate button 1/2 box',
        command: 'donate_half_size',
        icon: Drupal.settings.wysiwyg.plugins.drupal.donate_half_size.module + '/icons/donate_half_size.png'
      });
      if (Drupal.settings.wysiwyg.plugins.drupal.donate.module) {
        editor.on('mode', function(ev) {
          if (ev.editor.mode == 'wysiwyg') {
            // Inject CSS files directly into the editing area head tag.
            var iframe = $('#cke_contents_' + ev.editor.name + ' iframe, #' + ev.editor.id + '_contents iframe');
            $('head', iframe.eq(0).contents()).append('<link rel="stylesheet" href="' + Drupal.settings.wysiwyg.plugins.drupal.donate.module + '/donate.css" type="text/css" >');
            $('head', iframe.eq(0).contents()).append('<link rel="stylesheet" href="' + Drupal.settings.wysiwyg.plugins.drupal.donate_half_size.module + '/donate_half_size.css" type="text/css" >');
          }
        });
      }
      editor.widgets.add('donate_half_size', {

        template:
          '<div class="donate-bar half-size">' +
            '<div class="donate-bar-caption">' +
              'Support our conservation work by contributing today.' +
            '</div>' +
            '<div class="donate-bar-button"><a href="donate" class="button tomato large">Donate</a></div>' +
          '</div>',

        editables: {
          caption: {
            selector: '.donate-bar-caption'
          }
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
