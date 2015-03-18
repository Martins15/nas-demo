(function($) {
  CKEDITOR.plugins.add( 'inlinevideo', {
    init: function( editor ) {

      var path = this.path;
      editor.addContentsCss(path+'styles/inlinevideo.css');

      editor.addCommand('inlinevideo_command', new CKEDITOR.dialogCommand('inlinevideoDialog'));
      
      editor.ui.addButton('inlinevideo_button', {
        label: 'Add an inline Video', //this is the tooltip text for the button
        command: 'inlinevideo_command',
        icon: path + 'icons/inlinevideo.png'
      });
      
      CKEDITOR.dialog.add('inlinevideoDialog', path + 'dialog/dialog.js');
      
      // Widget add
      editor.widgets.add('inlinevideo', {
        editables: {
          video: {
            selector: '.video-frame',
          },
          caption: {
            selector: '.video-caption',
          },
        },
        allowedContent:
          'aside(!article-aside); div(!engagement-card-text);',
        upcast: function( element ) {
          return element.name == 'aside' && element.hasClass( 'article-aside' );
        }
      });
    }
  });
})(jQuery);
