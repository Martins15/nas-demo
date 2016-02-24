(function ($) {
  Drupal.behaviors.nas_master_native_plants_filters = {};
  Drupal.behaviors.nas_master_native_plants_filters.attach = function() {
    // Do not do anything if there is already cloned select.
    if ($('#edit-attribute-clone').length) {
      return;
    }

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

})(jQuery);
