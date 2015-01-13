(function($) {
  Drupal.behaviors.file_entity_alt_title = {
    attach: function (context, settings) {
    $('#file-entity-add-upload .field-name-field-file-image-title-text').hide();
      $('#file-entity-add-upload .field-name-field-file-image-alt-text input').keyup(function() {
        $('#file-entity-add-upload .field-name-field-file-image-title-text input').val($(this).val());
      });
    }
  };
})(jQuery);
