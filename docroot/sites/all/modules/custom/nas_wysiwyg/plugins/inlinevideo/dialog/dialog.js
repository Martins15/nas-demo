CKEDITOR.dialog.add( 'inlinevideoDialog', function( editor ) {
  return {
    title: 'Inline Video Properties',
    minWidth: 400,
    minHeight: 200,
    contents: [{
      id: 'inlinevideo-dialog',
      label: 'Basic Settings',
      elements: [{
          type: 'textarea',
          id: 'inlinevideo-code',
          label: Drupal.t('Embed code'),
          validate: CKEDITOR.dialog.validate.notEmpty('Embed code field cannot be empty.')
        },{
          type: 'text',
          id: 'inlinevideo-caption',
          label: Drupal.t('Caption'),
          validate: CKEDITOR.dialog.validate.notEmpty('Caption field cannot be empty.')
        }
      ]
    }],
    onOk: function() {
      var dialog = this,
          wrapper = editor.document.createElement('div'),
          caption = editor.document.createElement('div'),
          whitespace = editor.document.createText(' '),
          range = new CKEDITOR.dom.range(editor.document),
          id = 'video-'+Math.floor(Math.random()*1000),
          url = dialog.getValueOf('inlinevideo-dialog', 'inlinevideo-code');
      // Set Caption element
      caption.addClass('caption');
      caption.addClass('video-caption');
      caption.setText(dialog.getValueOf('inlinevideo-dialog', 'inlinevideo-caption'));
      caption.on
      // Set wrapper element
      wrapper.appendHtml('<div class="video-frame">'+url+'</div>'); // Add URL
      wrapper.addClass('video-wrapper');
      wrapper.addClass('group');
      wrapper.id = 'video-wrapper';
      // Insert elements
      wrapper.append(caption); // Add caption to wrapper
      editor.insertElement(wrapper); // Add wrapper to the editor
      whitespace.insertAfter(wrapper); // Add trailing whitespace
      // Reposition cursor after changes
      range.moveToElementEditablePosition(whitespace, true);
      editor.getSelection().selectRanges([range]);
    }
  };
});
