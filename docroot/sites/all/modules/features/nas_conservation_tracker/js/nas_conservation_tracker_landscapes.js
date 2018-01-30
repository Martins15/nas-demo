/**
 * @file
 * NAS CT Custom JS.
 */

(function ($, Drupal) {


  Drupal.behaviors.nasCtInitLandscapes = {
    attach: function (context, settings) {
      $.get(
          '/conservation-tracker/ajax/landscapes',
          function (data) {
            Drupal.settings.nasConservationTracker = Drupal.settings.nasConservationTracker || {};
            Drupal.settings.nasConservationTracker.landscapes = data.data;
            Drupal.nasCtInitLandscapesMap([]);

            var $filterElement = $('#nas-conservation-tracker-landscapes-map-form input');

            $filterElement.on('change', updateFilters);

            updateFilters();

            function updateFilters() {
              var filters = {'strategy': null, 'status': [], 'flyways': []};
              $filterElement.filter(':checked').each(function (index, el) {

                if ($(el).attr('type') == 'radio') {
                  filters.strategy = $(el).val();
                }
                else if ($(el).attr('name').indexOf('status') === 0) {
                  filters.status.push($(el).val());
                }
                else if ($(el).attr('name').indexOf('flyways') === 0) {
                  filters.flyways.push($(el).val());
                }
              });
              Drupal.nasConservationTracker.updateLandscapesFilters(filters);
            }

          }
      );
    }
  }
  ;

  Drupal.behaviors.nasCtAccordion = {
    attach: function (context) {
      // Create accordion for form items.
      $('#nas-conservation-tracker-landscapes-map-form > div > .form-item', context).each(function () {
        var labelBlock = $('> label', this);
        labelBlock.append('<i class="plus"></i>');
        labelBlock.click(function (e) {
          e.preventDefault();
          $(this).toggleClass('js-open');
          $('i', this).toggleClass('js-open');
        })
      });
      $('.form-item-strategies label', context).click().parent().find('input[value="coasts"]').click();
    }
  };

})
(jQuery, window.Drupal);