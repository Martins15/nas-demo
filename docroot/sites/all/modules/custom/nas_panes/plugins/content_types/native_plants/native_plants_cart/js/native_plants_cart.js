(function($) {
  Drupal.behaviors.native_plants_cart = {};
  Drupal.behaviors.native_plants_cart.attach = function (context, settings) {
    Drupal.native_plants_cart.init();
    $('body').once('native-plants-cart').bind('checkbox_change.native_plants_cart', function(event) {
      Drupal.native_plants_cart.update_cart(event);
    });

    $('input:checkbox.np-checkbox', context).once('native-plants-cart').change(function() {
      var $checkbox = $(this), plant_id = $checkbox.data('plantId'), checked = this.checked;

      var event = $.Event('checkbox_change.native_plants_cart');
      event.plant_id = plant_id;
      event.plant_common_name = $checkbox.data('plantCommonName');
      event.plant_scientific_name = $checkbox.data('plantScientificName');
      event.plant_bird_types = $checkbox.data('plantBirdTypes');
      event.plant_checked = checked;
      $('body').trigger(event);

      $('input:checkbox.np-checkbox[data-plant-id="' + plant_id + '"]').not($checkbox).each(function() {
        this.checked = checked;
      });
    });
  };

  Drupal.native_plants_cart = Drupal.native_plants_cart || {};
  Drupal.native_plants_cart.init = function() {
    var plants = Drupal.native_plants_cart.get_plants();
    $.each(plants, function(plant_id, plant) {
      $('input:checkbox.np-checkbox[data-plant-id="' + plant_id + '"]').each(function() {
        this.checked = true;
      });
    });
    Drupal.native_plants_cart.update_cart_texts(plants);
  };
  Drupal.native_plants_cart.update_cart = function(event) {
    var plants = Drupal.native_plants_cart.get_plants();
    if (event.plant_checked) {
      plants[event.plant_id] = {
        'CommonName': event.plant_common_name,
        'ScientificName': event.plant_scientific_name,
        'BirdTypes': event.plant_bird_types
      };
    }
    else {
      delete plants[event.plant_id];
    }
    Drupal.native_plants_cart.set_plants(plants);
    Drupal.native_plants_cart.update_cart_texts(plants);
  };
  Drupal.native_plants_cart.update_cart_texts = function(plants) {
    var count = Object.keys(plants).length;
    var plants_string = '', limit = false;
    $.each(plants, function(plant_id, plant) {
      if (plants_string.length < 60) {
        plants_string += (plants_string ? ', ' + plant.CommonName : plant.CommonName);
      }
      else if (!limit) {
        limit = true;
        plants_string += '...';
      }
    });
    if (count > 0) {
      $('.native-plants-bottom--selected-count').html(Drupal.formatPlural(count, '1 plant selected', '@count plants selected'));
      $('.native-plants-bottom-plant-list-items').html(plants_string);
    }
    else {
      $('.native-plants-bottom--selected-count').html(Drupal.t('No plants selected'));
      $('.native-plants-bottom-plant-list-items').html(Drupal.t('No plants yet'));
    }
  };
  Drupal.native_plants_cart.set_plants = function(plants) {
    var cart = JSON.stringify(plants);
    $.cookie('native_plants_cart', cart, {expires: 7, path: Drupal.settings.basePath});
  };
  Drupal.native_plants_cart.get_plants = function() {
    var plants = {};
    var cart = $.cookie('native_plants_cart');
    if (!cart) {
      return plants;
    }
    plants = JSON.parse(cart);
    return plants;
  };
})(jQuery);
