(function ($) {

  Drupal.behaviors.parkSelectBar = {
    attach: function (context, settings) {
      var statesArray = Drupal.settings.parksMapTerms;
      var parkSelect = $('#parks-select');
      var stateSelect = $('#state-select');


      stateSelect.prop('disabled', 'disabled');

      $.each(statesArray, function(index, val) {
       var titleOption = val.title;
        parkSelect.append($('<option>', {
          value: titleOption,
          text : titleOption
        }));
      });

      parkSelect.on('change', function() {
        stateSelect.find('option').remove();
        stateSelect.prop('disabled', false);
        var currentState = this.value;
        var getAllChild = $.map(statesArray, function(state) {
          if (state.title === currentState) {return state;}
        });

        $.map(getAllChild, function(state) {
          $.each(state.nodes, function(index, val) {
            var titleOption = val.title;
            var aliasOption = val.alias;
            stateSelect.append($('<option>', {
              value: aliasOption,
              text : titleOption
            }));
          });
        });
      });

      stateSelect.on('change', function() {
       var getLink = $('option:selected', this ).attr('value');
      });

    }
  };

})(jQuery);
