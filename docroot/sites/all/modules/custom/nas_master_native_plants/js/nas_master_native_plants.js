(function ($) {
  Drupal.behaviors.nas_master_native_plants_filters = {};
  Drupal.behaviors.nas_master_native_plants_filters.attach = function(context, settings) {
    // Remove the clones.
    var wrappers = $('#edit-attribute-clone, #edit-bird-type-clone, #edit-attribute-tier1-clone, #edit-bird-type-tier1-clone').parent('.-wrap-select');
    $('#edit-attribute-clone').remove();
    $('#edit-bird-type-clone').remove();
    $('#edit-attribute-tier1-clone').remove();
    $('#edit-bird-type-tier1-clone').remove();
    wrappers.remove();

    // We can't use context here as pager links do not update the exposed form in block.
    var $attributes = $('#edit-attribute'), $bird_types = $('#edit-bird-type'),
      $attributes_tier1 = $('#edit-attribute-tier1'), $bird_types_tier1 = $('#edit-bird-type-tier1');
    if ($attributes.length === 0) {
      return;
    }

    // Clone the taxonomy filters and position the clones.
    var $attributes_clone = $attributes.clone()
      .attr({'id': $attributes.attr('id') + '-clone', 'name': $attributes.attr('name') + '-clone'})
      .val($attributes.val())
      .appendTo('.inner-filters-wrapper').show();
    var $bird_types_clone = $bird_types.clone()
      .attr({'id': $bird_types.attr('id') + '-clone', 'name': $bird_types.attr('name') + '-clone'})
      .val($bird_types.val())
      .appendTo('.inner-filters-wrapper').show();
    var $attributes_tier1_clone = $attributes_tier1.clone()
      .attr({'id': $attributes_tier1.attr('id') + '-clone', 'name': $attributes_tier1.attr('name') + '-clone'})
      .val($attributes_tier1.val())
      .appendTo('.inner-filters-wrapper-tier1').show();
    var $bird_types_tier1_clone = $bird_types_tier1.clone()
      .attr({'id': $bird_types_tier1.attr('id') + '-clone', 'name': $bird_types_tier1.attr('name') + '-clone'})
      .val($bird_types_tier1.val())
      .appendTo('.inner-filters-wrapper-tier1').show();

    // Update the source select values upon changes on the clones and submit the form.
    $attributes_clone.change(function() {
      $attributes.val($attributes_clone.val());
      $('#edit-submit-native-plants-search').click();
    });
    $bird_types_clone.change(function() {
      $bird_types.val($bird_types_clone.val());
      $('#edit-submit-native-plants-search').click();
    });
    $attributes_tier1_clone.change(function() {
      $attributes_tier1.val($attributes_tier1_clone.val());
      $('#edit-submit-native-plants-search-tier1').click();
    });
    $bird_types_tier1_clone.change(function() {
      $bird_types_tier1.val($bird_types_tier1_clone.val());
      $('#edit-submit-native-plants-search-tier1').click();
    });

    Drupal.behaviors.wrap_select.attach(context, settings);
  };

  // Click on the attribute filters the view.
  Drupal.behaviors.nas_master_native_plants_attributes = {};
  Drupal.behaviors.nas_master_native_plants_attributes.attach = function(context, settings) {
    $('.native-plants-full-search-results .native-plants-attribute', context).click(function(event) {
      event.preventDefault();
      $('#edit-attribute').val($(this).data('tid'));
      $('#edit-submit-native-plants-search').click();
    });
    $('.native-plants-search-results .native-plants-attribute', context).click(function(event) {
      event.preventDefault();
      $('#edit-attribute-tier1').val($(this).data('tid'));
      $('#edit-submit-native-plants-search-tier1').click();
    });
  };

  /**
   * Modified Views function to ajaxify our pager links.
   */
  Drupal.views.ajaxView.prototype.attachPagerAjax = function() {
    this.$view.find('ul.pager > li > a, th.views-field a, .attachment .views-summary a, .search-results-total .pager a')
      .each(jQuery.proxy(this.attachPagerLinkAjax, this));
  };

  /**
   * Birds Carousel on Native plants search results page.
   */
  Drupal.behaviors.npOwl = {
    attach: function(context, settings) {
      $(".bird-card-carousel .owl-carousel").once('np-owl', function () {
        var self = $(this);
        self.owlCarousel({
          items: 2,
          itemsDesktop: false,
          itemsDesktopSmall: false,
          itemsTablet: false,
          itemsMobile: false,
          paginationSpeed: 100,
          navigation: true,
          rewindNav: false,
          pagination: false,
          navigationText: ["<i class=\"indicator-left icon-arrow-left\"></i>", "<i class=\"indicator-right icon-arrow-right\"></i>"]
        });

        // Shift card title down if it gets split on several lines.
        $(window).bind('resize', function (e) {
          $(".bird-card-caption", self).each(function () {
            var $caption = $(this);
            var $header = $(this).find('h4');
            if ($header.height() > parseInt($header.css('line-height')) + 2) {
              $caption.addClass('bird-card-caption-long');
            }
            else {
              $caption.removeClass('bird-card-caption-long');
            }
          });
        });
      });
    }
  };

  /**
   * Bind camera icon to clearing thumbs.
   */
  Drupal.behaviors.npClearingFix = {
    attach: function(context, settings) {
      if (typeof Foundation === 'undefined') {
        return;
      }
      $(document).foundation({
        clearing: {
          close_selectors: '.clearing-close, div.clearing-blackout, div.visible-img, img'
        }
      });
      $('a.clearing-attach').once('np-clearing-fix', function () {
        var $self = $(this);
        $self.bind('click', function() {
          $self.parent().find('[data-clearing] a').trigger('click');
          return false;
        });
      });
    }
  };

  /**
   * Content search on native plants page.
   */
  Drupal.behaviors.nas_master_native_plants_contentSearch = {
    attach: function(context, settings) {
      var form_prefix = '<div class="row columns js-native-plants-search-button hide-for-medium hide-for-large hide-for-xlarge collapsed">' +
        '<div class="native-plants-search-icon icon-magnifier open js-open"></div>' +
        '<div class="native-plants-search-icon icon-delete close js-close"></div>' +
        '</div>';

      $('.js-search-collapsible').once('search-collapsible', function () {
        var prev = $(this).prev();
        if (prev.hasClass('js-native-plants-search-button')) {
          prev.remove();
        }
        var $buttonWrapper = $(form_prefix).insertBefore($(this)),
          $open = $buttonWrapper.find('.js-open'),
          $close = $buttonWrapper.find('.js-close'),
          $form = $buttonWrapper.next('.js-search-collapsible');

        $open.on('click', function () {
          $form.removeClass('collapsed');
          $buttonWrapper.removeClass('collapsed');
        });

        $close.on('click', function () {
          $form.addClass('collapsed');
          $buttonWrapper.delay(500).queue(function() {
            $(this).addClass('collapsed').dequeue();
          });
        });
      });
    }
  };

  /**
   * Update results after completing editing content via IPE.
   */
  Drupal.behaviors.nativePlantsEndIPE = {
    attach: function (context, settings) {
      $('body').once('np-endIPE', function () {
        $('body.panels-ipe').bind('endIPE', function () {
          if ($('.view-native-plants-search').length == 0) {
            return;
          }
          $('.view-filters .form-select:first', $('.view-native-plants-search')).trigger('change');
        });
      });
    }
  };

})(jQuery);
