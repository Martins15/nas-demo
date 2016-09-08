(function ($) {
  Drupal.behaviors.nas_master_native_plants_fields_sync = {};
  Drupal.behaviors.nas_master_native_plants_fields_sync.attach = function(context, settings) {
    var $inputs = $('input[data-native-plants-fields-sync]', context);

    // Update cookie and fields values on field update.
    $inputs.on('input', function() {
      var fields = Drupal.native_plants_fields_sync.get_fields(),
        key = $(this).data('native-plants-fields-sync'),
        value = $(this).val();
      fields[key] = value;
      Drupal.native_plants_fields_sync.set_fields(fields);
      $inputs.not(this).filter('[data-native-plants-fields-sync="' + key + '"]').val(value);
    });

    // Get fields values from cookie.
    var fields = Drupal.native_plants_fields_sync.get_fields();
    // Update fields values from overriding fields, update cookie.
    $inputs.each(function () {
      if ($(this).data('native-plants-fields-sync-override')) {
        var key = $(this).data('native-plants-fields-sync'),
          value = $(this).val();
        if (value != '') {
          fields[key] = $(this).val();
        }
      }
    });
    Drupal.native_plants_fields_sync.set_fields(fields);

    if ($.isEmptyObject(fields)) {
      return;
    }

    // Set fields values from cookie.
    $inputs.each(function () {
      var key = $(this).data('native-plants-fields-sync');
      $(this).val(fields[key]);
    });
  };

  Drupal.native_plants_fields_sync = Drupal.native_plants_fields_sync || {};
  Drupal.native_plants_fields_sync.set_fields = function(fields) {
    var storage = JSON.stringify(fields);
    $.cookie('native_plants_fields_sync', storage, {expires: 7, path: Drupal.settings.basePath});
  };
  Drupal.native_plants_fields_sync.get_fields = function() {
    var fields = {};
    var storage = $.cookie('native_plants_fields_sync');
    if (!storage) {
      return fields;
    }
    fields = JSON.parse(storage);
    return fields;
  };

})(jQuery);
