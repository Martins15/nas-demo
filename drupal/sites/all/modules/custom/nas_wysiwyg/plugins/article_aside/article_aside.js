(function($) {
  Drupal.wysiwyg.plugins.article_aside = {
    attach : '',
  },

  article_asideAddPlugin = {
    requires: 'widget',
    icons: 'article_aside',

    init: function( editor ) {
      editor.ui.addButton('article_aside', {
        label: 'Create a article_aside button box',
        command: 'article_aside',
        icon: Drupal.settings.wysiwyg.plugins.drupal.article_aside.module + '/icons/article_aside.png'
      });
      if (Drupal.settings.wysiwyg.plugins.drupal.article_aside.module) {
        editor.on('mode', function(ev) {
          if (ev.editor.mode == 'wysiwyg') {
            // Inject CSS files directly into the editing area head tag.
            var iframe = $('#cke_contents_' + ev.editor.name + ' iframe, #' + ev.editor.id + '_contents iframe');
            $('head', iframe.eq(0).contents()).append('<link rel="stylesheet" href="' + Drupal.settings.wysiwyg.plugins.drupal.article_aside.module + '/article_aside.css" type="text/css" >');
          }
        });
      }
      editor.widgets.add('article_aside', {

        template:
          '<aside class="article-aside">' +
            '<div class="engagement-card side-note">' +
              '<div class="engagement-card-content">' +
                '<h4 class="engagement-card-headline">This is a Sidebar Example</h4>' +
                '<div class="engagement-card-text">Insert text here</div>' +
              '</div>' +
            '</div>' +
          '</aside>',

        editables: {
          title: {
            selector: '.engagement-card-headline',
          },
          text: {
            selector: '.engagement-card-text',
          },
        },

        allowedContent:
          'aside(!article-aside); div(!engagement-card-text);',

        requiredContent: 'aside(article-aside)',

        upcast: function( element ) {
          return element.name == 'aside' && element.hasClass( 'article-aside' );
        }
      });
    }
  }
})(jQuery);
