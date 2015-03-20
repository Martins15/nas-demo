/**
 * @file
 * Drupal typeahead.js integration.
 */

(function ($) {
  Drupal.behaviors.typeahead = {
    attach: function(context, settings) {
      settings.typeahead = settings.typeahead || Drupal.settings.typeahead;

      // Prepare selector and add unwantend selectors.
      var selector = settings.typeahead.selector;

      // Function to prepare the options together typeahead() call.
      var getElementOptions = function (element) {
        var options = $.extend({}, settings.typeahead.options);
        return options;
      };

      var getElementDatasets = function (element) {
        var datasets = [];

        var id = $(element).attr('id');

        var field_settings = Drupal.settings.typeahead.settings[id];
        for (var i in field_settings) {
          var dataset, displayKey = 'value';
          if (field_settings[i].options.displayKey !== undefined) {
            displayKey = field_settings[i].options.displayKey;
          }
          var options = {
            datumTokenizer: Bloodhound.tokenizers.obj.whitespace(displayKey),
            queryTokenizer: Bloodhound.tokenizers.whitespace
          };
          if (field_settings[i].type == 'local values') {
            options.local = field_settings[i].values;
          }
          else if (field_settings[i].type == 'local callback') {
            var settings = field_settings[i];
            /*jshint -W083 */
            options.local = (function (settings) {
              return function() {
                return executeFunctionByName(settings.localCallback, window, element, settings);
              };
            })(settings);
          }
          else if (field_settings[i].type == 'prefetch') {
            options.prefetch = {
              url: field_settings[i].prefetch,
              // TODO: implement.
//              filter: birdGuideFilteredResults
//              ttl: 1
            };
          }
          Drupal.settings.typeahead.settings[id][i].Bloodhound = new Bloodhound(options);
          Drupal.settings.typeahead.settings[id][i].Bloodhound.initialize();

          dataset = {
            source: Drupal.settings.typeahead.settings[id][i].Bloodhound.ttAdapter()
          };

          if (field_settings[i].options !== undefined) {
            dataset = $.extend(dataset, field_settings[i].options);
          }
          datasets.push(dataset);
        }
        return datasets;
      };

      // Process elements that have opted-in for Chosen.
      $('.tt-enable', context).once('typeahead', function() {
        var options = getElementOptions(this);
        var datasets = getElementDatasets(this);
        $(this).typeahead(options, datasets);
      });
    }
  };

  function executeFunctionByName(functionName, context /*, args */) {
    var args = Array.prototype.slice.call(arguments, 2);
    var namespaces = functionName.split(".");
    var func = namespaces.pop();
    for (var i = 0; i < namespaces.length; i++) {
      context = context[namespaces[i]];
    }
    return context[func].apply(context, args);
  }

})(jQuery);
