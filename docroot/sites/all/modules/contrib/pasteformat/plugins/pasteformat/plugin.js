/**
 * @file Plugin to cleanup pasted text.
 */
CKEDITOR.plugins.add( 'pasteformat',
{
	init : function( editor ) {
    
    function removeStyles(el) {
      el.removeAttribute('style');
      if(el.childNodes.length > 0) {
        for(var child in el.childNodes) {
          if(el.childNodes[child].nodeType == 1)
            removeStyles(el.childNodes[child]);
        }
      }
    }
    
		function pasteformat_cleanup( ev ) {
      var element = document.createElement('div');
      element.innerHTML = ev.data.dataValue;
      removeStyles(element);
      ev.data.dataValue = element.innerHTML;
		}
		
		editor.on( 'paste', pasteformat_cleanup );
	}
});
