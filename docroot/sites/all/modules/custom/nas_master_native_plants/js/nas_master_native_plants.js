(function ($) {
  Drupal.behaviors.nas_master_native_plants_filters = {};
  Drupal.behaviors.nas_master_native_plants_filters.attach = function() {
    // Remove the clones.
    $('#edit-attribute-clone').remove();
    $('#edit-bird-type-clone').remove();

    // We can't use context here as pager links do not update the exposed form in block.
    var $attributes = $('#edit-attribute'),
      $bird_types = $('#edit-bird-type');
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

    // Update the source select values upon changes on the clones and submit the form.
    $attributes_clone.change(function() {
      $attributes.val($attributes_clone.val());
      $('#edit-submit-native-plants-search').click();
    });
    $bird_types_clone.change(function() {
      $bird_types.val($bird_types_clone.val());
      $('#edit-submit-native-plants-search').click();
    });
  };

  // Click on the attribute filters the view.
  Drupal.behaviors.nas_master_native_plants_attributes = {};
  Drupal.behaviors.nas_master_native_plants_attributes.attach = function(context, settings) {
    $('.native-plants-attribute', context).click(function(event) {
      event.preventDefault();
      $('#edit-attribute').val($(this).data('tid'));
      $('#edit-submit-native-plants-search').click();
    });
  };

  // Hide Tier1 results description if there are no Tier1 results.
  Drupal.behaviors.nas_master_native_plants_tier1 = {};
  Drupal.behaviors.nas_master_native_plants_tier1.attach = function() {
    if ($('.native-plants-search-results .view-row').length === 0) {
      $('.try-these-first').hide();
    }
    else {
      $('.try-these-first').show();
    }
  };

  // Hide view if there is no ZIP code value.
  Drupal.behaviors.nas_master_native_plants_hide_view = {};
  Drupal.behaviors.nas_master_native_plants_hide_view.attach = function() {
    if ($('.native-plants-search-form--zip-code').val() === '') {
      $('.view-native-plants-search').children().not('.view-empty').hide();
    }
    else {
      $('body').removeClass('page-native-plants-initial');
    }
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
      var $buttonWrapper = $('.js-native-plants-search-button'),
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
    }
  };

})(jQuery);
