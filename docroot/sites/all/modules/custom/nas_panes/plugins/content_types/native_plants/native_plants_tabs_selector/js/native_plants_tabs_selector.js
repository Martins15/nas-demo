(function($) {
  /**
   * Tabs.
   */
  Drupal.behaviors.native_plants_tabs_selector = {};
  Drupal.behaviors.native_plants_tabs_selector.attach = function(context, settings) {
    var $jsTabs = $('.js-tabs', context);

    // Generate a select box of tab items to display on mobile.
    var $select = $('<select class="js-tabs-select tab-select hide-for-large hide-for-xlarge"></select>');

    $jsTabs.each(function () {
      $(this).find('li a').each(function() {
        $select.append('<option>' + $(this).text() + '</option>');
      });

      $select.insertAfter('.js-tabs');
    });

    // Synchronise the tab elements on 'nav' click.
    $jsTabs.on('toggled', function (event, tab) {
      var $mobileMenu = $(this).closest($jsTabs).siblings('.js-tabs-select');

      $mobileMenu.find('option').removeAttr('selected')
        .siblings('option:contains(' + tab.find('a').text() + ')').attr('selected', 'selected');
    });

    // Synchronise the tab elements on 'select' change.
    $('.js-tabs-select').on('change', function() {
      $(this).siblings($jsTabs).find("li a:contains(" + $(this).val() + ")").click();
    });
  };
})(jQuery);
