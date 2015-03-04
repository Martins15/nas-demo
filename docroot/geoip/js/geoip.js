/**
 * Define global geoip object.
 */
var geoip = {};

geoip.getState = function getState(callback){
  var query_data = {};

  // Check debug cookie with IP.
  if (typeof jQuery.cookie === 'function') {
    var debug_ip = jQuery.cookie('debug_ip');

    if (debug_ip !== null) {
      query_data.ip = debug_ip;
    }
  }

  jQuery.ajax({
    type: 'GET',
    url: Drupal.settings.basePath + 'geoip/geoip.php',
    data: query_data,
    dataType: 'text',
    success: function (data) {
      callback(data);
    }
  });
};
