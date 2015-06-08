/**
 * Provide the HTML to create the modal dialog.
 */
Drupal.theme.prototype.BOAPlateModal = function () {
  var html = '';

  html += '<div id="ctools-modal" class="popups-box boa-plate-popup">';
  html += '  <div class="ctools-modal-content">';
  html += '    <div class="popups-container">';
  html += '      <div class="modal-header popups-title">';
  html += '        <span id="modal-title" class="modal-title"></span>';
  html += '        <div class="clear-block"></div>';
  html += '      </div>';
  html += '      <div id="modal-content" class="modal-content popups-body"></div>';
  html += '    </div>';
  html += '  </div>';
  html += '  <div class="controls"><i class="lzoom_zoomin"></i><i class="lzoom_zoomout"></i><i class="lzoom_fullscreen"></i></div>';
  html += '  <span id="cboxClose" class="popups-close close">' + Drupal.CTools.Modal.currentSettings.closeText + '</span>';
  html += '</div>';

  return html;
};

jQuery.fn.extend({
  applySeadragon: function () {
    jQuery(window).trigger('resize');
    return this.each(function () {
      var $this = jQuery(this);
      var $deepzoom = $this.find('.deepzoom');
      var id = $deepzoom.attr('id').split('-');
      var viewer = new OpenSeadragon({
        id: id.join('-'),
        prefixUrl: Drupal.settings.deepZoom.library + '/images/',
        tileSources: Drupal.settings.boadeepzoom.path + '/' + id[1] + '.dzi',
        showNavigator: true,
        showNavigationControl: false
      });

      $this.find('.lzoom_fullscreen').bind('click', function () {
        viewer.setFullScreen(true);
      });
      $this.find('.lzoom_zoomin').bind('click', function () {
        var maxZoomFactor = Math.min(viewer.viewport.getMaxZoom() / viewer.viewport.getZoom(true), 1.5);
        viewer.viewport.zoomBy(maxZoomFactor);
      });
      $this.find('.lzoom_zoomout').bind('click', function () {
        var minZoomFactor = Math.min(viewer.viewport.getZoom(true) / viewer.viewport.getMinZoom(), 1.5);
        viewer.viewport.zoomBy(1/minZoomFactor);
      });
    });
  }
});