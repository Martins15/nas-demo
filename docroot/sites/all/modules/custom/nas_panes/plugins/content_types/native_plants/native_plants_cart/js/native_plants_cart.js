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

    $('.native-plants-bottom--clear-plants-list', context).once('native-plants-cart').click(function(event) {
      event.preventDefault();
      var plants = {};
      Drupal.native_plants_cart.set_plants(plants);
      Drupal.native_plants_cart.init();
    });
  };

  Drupal.native_plants_cart = Drupal.native_plants_cart || {};
  Drupal.native_plants_cart.init = function() {
    var plants = Drupal.native_plants_cart.get_plants();
    $('.np-checkbox').each(function() {
      this.checked = false;
    });
    $.each(plants, function(plant_id, plant) {
      $('.np-checkbox[data-plant-id="' + plant_id + '"]').each(function() {
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
      $('.native-plants-bottom--selected-count .plants-counter').html(Drupal.formatPlural(count, '1 plant', '@count plants'));
      $('.native-plants-bottom-plant-list-items').html(plants_string);
      // Show clear list link.
      $('.native-plants-bottom--selected-count .clear-plants-list').show();
    }
    else {
      $('.native-plants-bottom--selected-count .plants-counter').html(Drupal.t('No plants selected'));
      $('.native-plants-bottom-plant-list-items').html(Drupal.t('No plants yet'));
      // Hide clear list link.
      $('.native-plants-bottom--selected-count .clear-plants-list').hide();
    }
  };
  Drupal.native_plants_cart.set_plants = function(plants) {
    var cart = JSON.stringify(plants);
    $.cookie('native_plants_cart', cart, {expires: 7, path: Drupal.settings.basePath});
    $('body').trigger('plants_updated.native_plants_cart');
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

  /**
   * Sticky footer on Native plants search results page.
   */
  Drupal.behaviors.npStickyFooter = {};
  Drupal.behaviors.npStickyFooter.attach = function(context, settings) {
    $('.native-plants-bottom', context).once('np-sticky-footer', function () {
      var $self = $(this),
        $list = $('.native-plants-bottom-plant-list'),
        $list_info = $('.native-plants-bottom-plant-list-info'),
        $w = $(window),
        $anchor = '',
        $button = $('.native-plants-botton--get-list');

      // Hide cart if there are no plants selected.
      if ($.isEmptyObject(Drupal.native_plants_cart.get_plants())) {
        $list.hide();
      }
      $('body').bind('plants_updated.native_plants_cart', function(event) {
        if ($.isEmptyObject(Drupal.native_plants_cart.get_plants())) {
          $list.hide();
        }
        else {
          $list.show();
        }
      });

      // Find which is the next element to determine from where the scroll starts.
      if ($list.next().length == 1) {
        $anchor = $list.next();
      }
      else {
        $anchor = $list.parent().next();
      }

      $w.bind('scroll resize', function (e) {
        $self.removeClass('native-plants-bottom-fixed');
        var s = $w.scrollTop() + $w.height();
        var offset = $anchor.offset().top;
        if (s < offset) {
          $self.addClass('native-plants-bottom-fixed');
        }
        else {
          $self.removeClass('native-plants-bottom-fixed');
        }
      }).trigger('scroll');

      // Button click handler.
      $button.click(function () {
        $button.stop().animate({opacity: 0}, function () {
          $list.addClass('native-plants-bottom-plant-list-form-show');
          if (Foundation.utils.is_small_only()) {
            $list_info.hide();
          }
        });
      });
      $w.bind('resize', function () {
        if ($list.hasClass('native-plants-bottom-plant-list-form-show') && Foundation.utils.is_small_only()) {
          $list_info.hide();
        }
        else {
          $list_info.show();
        }
      });
    });
  };
})(jQuery);
