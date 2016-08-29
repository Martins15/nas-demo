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
        $w = $(window),
        $formTitle = '',
        $button = $('.native-plants-botton--get-list'),
        $form = $('.native-plants-bottom-form');

      // Find which is the next element to determine from where the scroll starts.
      if ($list.next().length == 1) {
        $formTitle = $list.next();
      } else {
        $formTitle = $list.parent().next();
      }

      $(window).bind('scroll resize', function (e) {
        $self.removeClass('native-plants-bottom-fixed');
        var s = $w.scrollTop() + $w.height();
        var offset = $formTitle.offset().top;
        if (s < offset) {
          $self.addClass('native-plants-bottom-fixed');
        }
        else {
          $self.removeClass('native-plants-bottom-fixed');
        }

        // Form isn't fully visible.
        if (s < offset + $formTitle.outerHeight() + $form.outerHeight() - 10) {
          $button.removeClass('js-form-is-visible');
          // If form just became hidden, show button.
          if (!$button.hasClass('js-form-isnt-visible')) {
            $button.stop().css({display: 'block'}).animate({opacity: 1});
          }
          // Mark button as it knows that form isn't visible.
          $button.addClass('js-form-isnt-visible');
        }
        // Form is fully visible.
        else {
          $button.removeClass('js-form-isnt-visible');
          // Form just became visible, hide button.
          if (!$button.hasClass('js-form-is-visible')) {
            $button.stop().animate({opacity: 0}, function () {
              $(this).css({display: 'none'});
            });
          }
          // Mark button as it knows that form is visible.
          $button.addClass('js-form-is-visible');
        }

      }).trigger('scroll');

      // Button click handler.
      $button.click(function () {
        // Remove styles to properly calculate offsets.
        var style = $self.attr('style');
        $self.removeAttr('style');
        var offset = $formTitle.offset().top;
        var h = $formTitle.outerHeight() + $form.outerHeight();
        var s =  h + offset - $w.height();
        // Apply styles back in order to prevent blinking.
        $self.attr({ style: style });
        $('html, body').animate({ scrollTop: s });
      });
    });
  };
})(jQuery);
