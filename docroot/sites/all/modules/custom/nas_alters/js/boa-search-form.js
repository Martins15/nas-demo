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
          // Prevent input value changing to combined value that is used for
          // search.
          setTimeout(function () {
            $input.val(obj.title);
          }, 0);
          window.location.href = settings.basePath + obj.alias;
          return false;
        });
        $input.bind('typeahead:cursorchanged', function (e, obj, dataset) {
          // Prevent input value changing to combined value that is used for
          // search.
          $(this).val(obj.title);
        });
      });
    },
    suggestionTemplate: function (item, settings, element) {
      var title = item.title;
      if (item.title != item.new_title && item.new_title !== null) {
        title += ' &mdash; <em>' + item.new_title + '</em>';
      }

      return title;
    }
  };
})(jQuery);
