(function($) {
  /**
   * Tabs.
   */
  Drupal.behaviors.native_plants_tabs_selector = {};
  Drupal.behaviors.native_plants_tabs_selector.attach = function(context, settings) {
    $(".js-tabs-select-wrapper", context).remove();
    $('.js-tabs', context).once('tabs-selector').each(function() {
      var $jsTabs = $(this);

      // Generate a select box of tab items to display on mobile.
      var $select = $('<select class="js-tabs-select tab-select"></select>');
      var $selectWrapper = $select
        .wrap('<div class="js-tabs-select-wrapper hide-for-large hide-for-xlarge"></div>')
        .parent();
      $selectWrapper.insertAfter('.js-tabs');

      $jsTabs.find('li a').each(function() {
        $select.append('<option>' + $(this).text() + '</option>');
      });

      // Synchronise the tab elements on 'nav' click.
      $jsTabs.on('toggled', function (event, tab) {
        $select.find('option').removeAttr('selected')
          .siblings('option:contains(' + tab.find('a').text() + ')').attr('selected', 'selected');
      });

      // Synchronise the tab elements on 'select' change.
      $select.on('change', function() {
        $jsTabs.find("li a:contains(" + $(this).val() + ")").click();
      });
    });
    Drupal.behaviors.wrap_select.attach(context, settings);
  };
})(jQuery);
