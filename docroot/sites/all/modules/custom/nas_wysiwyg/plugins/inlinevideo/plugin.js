(function($) {
  CKEDITOR.plugins.add('inlinevideo', {
    init: function( editor ) {
      var path = this.path;
      
      editor.addContentsCss(path+'styles/inlinevideo.css');

      editor.addCommand('inlinevideo_command', new CKEDITOR.dialogCommand('inlinevideoDialog'));
      
      editor.ui.addButton('inlinevideo_button', {
        label: Drupal.t('Add an inline Video'), //this is the tooltip text for the button
        command: 'inlinevideo_command',
        icon: path + 'icons/inlinevideo.png'
      });
      
      CKEDITOR.dialog.add('inlinevideoDialog', path + 'dialog/dialog.js');
    }
  });
})(jQuery);
