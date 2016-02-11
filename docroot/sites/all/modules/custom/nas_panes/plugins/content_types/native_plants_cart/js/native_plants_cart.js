(function($) {
  Drupal.behaviors.native_plants_cart = {};
  Drupal.behaviors.native_plants_cart.attach = function (context, settings) {
    Drupal.native_plants_cart.init();
    $('body').once('native-plants-cart').bind('checkbox_change.native_plants_cart', function(event, plant_id, plant_name, checked) {
        Drupal.native_plants_cart.update_cart(plant_id, plant_name, checked);
      });

    $('input:checkbox.np-checkbox', context).once('native-plants-cart').change(function() {
      var $checkbox = $(this);
      var plant_id = $checkbox.data('plantId'), plant_name = $checkbox.data('plantName'), checked = this.checked;
      $('body').trigger('checkbox_change.native_plants_cart', [plant_id, plant_name, checked]);
      $('input:checkbox.np-checkbox[data-plant-id="' + plant_id + '"]').not($checkbox).each(function() {
        this.checked = checked;
      });
    });
  };

  Drupal.native_plants_cart = Drupal.native_plants_cart || {};
  Drupal.native_plants_cart.init = function() {
    var plants = Drupal.native_plants_cart.get_plants();
    plants.forEach(function(plant) {
      $('input:checkbox.np-checkbox[data-plant-id="' + plant[0] + '"]').each(function() {
        this.checked = true;
      });
    });
    Drupal.native_plants_cart.update_cart_texts(plants);
  };
  Drupal.native_plants_cart.update_cart = function(plant_id, plant_name, checked) {
    var plants = Drupal.native_plants_cart.get_plants();
    if (checked) {
      plants.push([plant_id, plant_name]);
    }
    else {
      plants.forEach(function(plant, i) {
        if (plant[0] === plant_id) {
          plants.splice(i, 1);
        }
      });
    }
    Drupal.native_plants_cart.set_plants(plants);
    Drupal.native_plants_cart.update_cart_texts(plants);
  };
  Drupal.native_plants_cart.update_cart_texts = function(plants) {
    var count = plants.length;
    var plants_string = '', limit = false;
    plants.forEach(function(plant) {
      if (plants_string.length < 60) {
        plants_string += (plants_string ? ', ' + plant[1] : plant[1]);
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
    var _plants = [];
    plants.forEach(function(plant) {
      _plants.push(plant.join(','));
    });
    var cart = _plants.join('|');
    $.cookie('native_plants_cart', cart, {expires: 7, path: Drupal.settings.basePath});
  };
  Drupal.native_plants_cart.get_plants = function() {
    var plants = [];
    var cart = $.cookie('native_plants_cart');
    if (!cart) {
      return plants;
    }

    var _plants = cart.split('|');
    _plants.forEach(function(_plant) {
      plants.push(_plant.split(','));
    });
    return plants;
  };
})(jQuery);
