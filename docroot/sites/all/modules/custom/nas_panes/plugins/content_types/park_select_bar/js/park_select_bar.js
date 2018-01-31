(function ($) {

  Drupal.behaviors.parkSelectBar = {
    attach: function (context, settings) {
      var statesArray = Drupal.settings.parksMapTerms;
      var parkSelect = $('#parks-select');
      var stateSelect = $('#state-select');

      // Disable on load page second select.
      stateSelect.prop('disabled', 'disabled');

      // Print all options for first select.
      $.each(statesArray, function (index, val) {
        var titleOption = val.title;
        parkSelect.append($('<option>', {
          value: titleOption,
          text: titleOption
        }));
      });

      // If choose option in first select.
      // Print all options for second select.
      // Related first select.
      parkSelect.change(function () {
        // Clear all options but not first.
        stateSelect.find('option:gt(0)').remove();
        // Unable second select.
        stateSelect.prop('disabled', false);
        var currentState = this.value;
        // Find options related first select.
        var getAllChild = $.map(statesArray, function (state) {
          if (state.title === currentState) {
            return state;
          }
        });

        // Update second select.
        $.map(getAllChild, function (state) {
          $.each(state.nodes, function (index, val) {
            var titleOption = val.title;
            var aliasOption = val.alias;
            stateSelect.append($('<option>', {
              value: aliasOption,
              text: titleOption
            }));
          });
        });
      });

      // If choose option in second select.
      stateSelect.on('change', function () {
        // Get url form value.
        var getLink = $('option:selected', this).attr('value');
        // If we have some url.
        // Go to this url.
        if (getLink.length) {
          window.location.href = location.origin + '/' + getLink;
        }
      });

    }
  };

})(jQuery);
