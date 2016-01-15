
(function ($) {

  Drupal.behaviors.adbnBirdListSearchBox = {
    attach: function (context, settings) {

      $('body').once('adbnBirdListSearchBox', function() {
        // Check that required settings for Drupal have been sent.
        if (
          !settings.adbnMap.ajaxPath
          || !settings.adbnMap.area
          || !settings.adbnMap.birdDetailPath
        ) {
          return;
        }

        var ajaxPath = settings.adbnMap.ajaxPath;
        var area = settings.adbnMap.area;
        var basePath = settings.basePath;
        var birdDetailPath = basePath + settings.adbnMap.birdDetailPath;

        Drupal.adbnMap.birdPageView = new STMN.audubonClimateModel.BirdPageView(
          {
            paths : {
              data   : '/' + ajaxPath + '/data',
              giphy  : '/' + ajaxPath + '/giphy',
              states : '/' + ajaxPath + '/states/' + area + '/{countryCode}/{audubonId}'
            },
            selectors : {
              searchBox : '.microsite-bird-search'
            },
            filterTo : ['ENDANGERED','ENDANGERED_1','ENDANGERED_2','THREATENED','THREATENED_1','THREATENED_2']

          },
          function(err, view) {
            // What happens when somebody clicks on a search option
            view.on('search:selected', function(e) {
              $('.audubon-climate-model input[type=search]').attr('value');
              location.href = '' + birdDetailPath + '/' + e.caller[0]['SPECIES_CODE'];
            });
          }
        );
      });
    }
  }

})(jQuery);