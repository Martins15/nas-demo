/**
 * @file
 * NAS CT Custom JS.
 */

(function ($, Drupal) {

  Drupal.behaviors.nas_conservation_tracker = {
    attach:function (context, settings) {
      console.log(Drupal.settings.nas_conservation_tracker_states_data);
      console.log(Drupal.settings.leaflet['0'].lMap);
      L.geoJson(Drupal.settings.nas_conservation_tracker_states_data).addTo(Drupal.settings.leaflet['0'].lMap);
      //Drupal.leaflet.create_polygon(Drupal.settings.nas_conservation_tracker_states_data, Drupal.settings.leaflet['0'].lMap);
    }
  };

})(jQuery, window.Drupal);