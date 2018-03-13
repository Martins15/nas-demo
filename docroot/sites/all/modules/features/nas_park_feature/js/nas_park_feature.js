/**
 * @file
 * NAS Climate Custom JS.
 */

(function ($, Drupal) {
  Drupal.behaviors.nasClimateTurnover = {
    attach: function (context, settings) {
      if (settings.nasClimateFeature.turnoverChart) {
        var chart = new StamenAudubonParks.TurnoverChart({
          element: '#' + settings.nasClimateFeature.elementId,
          dataUrl: settings.nasClimateFeature.dataUrl,
          park: settings.nasClimateFeature.parkTitle,
          onClick: parkOnClick,
          season: 'summer'
        });
        Drupal.settings.nasClimateFeature.chart = chart;

        var tabsSwitcherNav = $('.tab-slider--dots .tab-slider--tabs');
        tabsSwitcherNav.find('li').click(function () {
          if (!$(tabsSwitcherNav).hasClass('slide')) {
            var season = 'winter';
          }
          else {
            var season = 'summer';
          }
          Drupal.settings.nasClimateFeature.chart.setSeason(season);

        });
      }
    }
  }

  Drupal.behaviors.nasClimateParkMap = {
    attach: function (context, settings) {
      if (settings.nasClimateFeature.parkMap) {
        var $charts = $('.' + settings.nasClimateFeature.elementId);
        $charts.each(function(index, element){
          var trend = $(element).attr('data-trend');
          var chart = new StamenAudubonParks.ParkMap({
            element: '.' + settings.nasClimateFeature.elementId + '.' + trend,
            dataUrl: settings.nasClimateFeature.dataUrl,
            season: 'summer',
            metric: trend,
            shapeUrl: settings.nasClimateFeature.shapeUrl,
            onClick: parkOnClick
          });

          var tabsSwitcherNav = $(element).parent().find('.tab-slider--tabs');
          tabsSwitcherNav.find('li').click(function () {

            if (!$(tabsSwitcherNav).hasClass('slide')) {
              var season = 'winter';
            }
            else {
              var season = 'summer';
            }
            chart.setParams(season, trend);
            $(this).parent().toggleClass('slide');

          });
        });



      }
    }
  }

  function parkOnClick(parkName) {
    location = location.origin + '/' + Drupal.settings.nasClimateFeature.parkLinks[parkName];
  }

  Drupal.behaviors.nasClimateTabs = {
    attach: function (context, settings) {
      var tabsItem = $('.tab-slider--dots .tab-slider--tabs');
      var tabsNav = $('li', tabsItem);
      tabsNav.click(function () {
        tabsNav.removeClass("active");
        $(this).addClass("active");
        if ($(this).attr("rel") === "season_winter") {
          tabsItem.addClass('slide');
        }
        else {
          tabsItem.removeClass('slide');
        }
      });

    }
  }

})(jQuery, window.Drupal);
