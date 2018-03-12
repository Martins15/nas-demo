/**
 * @file
 * Javascript refinements for the Article images per node field.
 */

(function ($) {
  function articleImagesPerNode(context) {
    $('#edit-field-assests-per-node tr.draggable', context).once('tr', function () {
      var fid = $(this).find('.media-item')[0]
        , element
        , $td = $(this).find('td:last');
      if ($('input.form-text-copy', $td).length) {
        return;
      }
      fid = $(fid).data('fid');
      if (fid in Drupal.settings.articleAssetsMapping) {
        element = '<input class="form-text form-text-copy" type="text" value="' + Drupal.settings.articleAssetsMapping[fid] + '"/>';
        $td.append(element);
      }
    });
  }

  Drupal.behaviors.articleImagesPerNode = {
    attach: function (context, settings) {
      if (!Drupal.settings.articleAssetsMapping) {
        return;
      }
      articleImagesPerNode(context);
      $('#article-node-form').ajaxComplete(function (event, xhr, settings) {
        if (event.target.id == 'article-node-form') {
          articleImagesPerNode(context);
        }
      });
    }
  };
})(jQuery);
