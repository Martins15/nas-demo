/**
 * @file
 * Javascript refinements for the BOA landing page.
 */

(function ($) {
  Drupal.behaviors.boaSearchFilters = {
    attach: function (context, settings) {
      $(".boa-search-form", context).once('boa-search-filters', function () {
        var form = this;
        var $input = $('.tt-enable', form).not('.tt-hint');
        // Suggestion was selected.
        $input.bind('typeahead:selected', function (e, obj, dataset) {
          window.location.href = settings.basePath + obj.alias;
        });
      });
    },
    suggestionTemplate: function (item, settings, element) {
      return item.title;
    }
  };
})(jQuery);
