(function ($) {
  Drupal.behaviors.nas_master_native_plants = {};
  Drupal.behaviors.nas_master_native_plants.attach = function(context, settings) {
    // Assign classes to the first and last pager items in pagers.
    $('.search-results-total .pager', context).each(function() {
      var $pager_items = $(this).children();
      $pager_items.first().addClass('pager-prev');
      $pager_items.last().addClass('pager-next');
    });
  };

  /**
   * Modified Views to ajaxify our pager links.
   */
  Drupal.views.ajaxView.prototype.attachPagerAjax = function() {
    this.$view.find('ul.pager > li > a, th.views-field a, .attachment .views-summary a, .search-results-total .pager a')
      .each(jQuery.proxy(this.attachPagerLinkAjax, this));
  };

})(jQuery);
