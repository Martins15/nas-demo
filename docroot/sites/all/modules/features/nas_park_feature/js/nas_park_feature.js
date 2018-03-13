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
      }
    }
  }

  Drupal.behaviors.nasClimateParkMap = {
    attach: function (context, settings) {
      if (settings.nasClimateFeature.parkMap) {
        var chart = new StamenAudubonParks.ParkMap({
          element: '#' + settings.nasClimateFeature.elementId,
          dataUrl: settings.nasClimateFeature.dataUrl,
          season: 'summer',
          metric: 'colonization',
          shapeUrl: settings.nasClimateFeature.shapeUrl,
          onClick: parkOnClick
        });
        Drupal.settings.nasClimateFeature.chart = chart;
      }
    }
  }

  Drupal.behaviors.nasClimateParkMapSwitcher = {
    attach: function (context, settings) {

      var tabsItem = $('.tab-slider--tabs', context)
        , tabsNav = $('.tab-slider--nav li')
        , tabsBody = $('.tab-slider--body', context)
        , seasonSwitch = $('#edit-season')
        , trendsSwitch = $('#edit-park-trend');


      var seasonMap = {'1': 'season_summer', '2': 'season_winter'};

      $('.switch-wrap').once('tab-init', function () {
        var seasonCur = seasonMap[$(seasonSwitch).find('option:selected').val()];
        $('.tab-slider--trigger').removeClass('active').filter('[rel="' + seasonCur + '"]').addClass('active');
        if (seasonCur == 'season_winter') {
          tabsItem.addClass('slide');
        }
        $('.tabs-content__link').removeClass('current').filter('[data-tab="display-' + $(trendsSwitch).find('option:selected').val() + '"]').addClass('current');
        $('.tab-content').removeClass('current').filter('[data-content="display-' + $(trendsSwitch).find('option:selected').val() + '"]').addClass('current');
      });

      tabsNav.click(function () {
        var seasonSwitch = $('#edit-season')
          , formSubmit = $('#edit-submit-park-bird-trends');
        tabsBody.hide();
        var activeTab = $(this).attr("rel");
        if ($(this).attr("rel") === "season_winter") {
          tabsItem.addClass('slide');
          $(seasonSwitch).find('option[value=2]').prop('selected', true);
        }
        else {
          tabsItem.removeClass('slide');
          $(seasonSwitch).find('option[value=1]').prop('selected', true);
        }
        $(formSubmit).click();
        tabsNav.removeClass("active");
        $(this).addClass("active");
        $("#" + activeTab).fadeIn();
        $('.tabs-content__link').removeClass('current').filter('[data-tab="display-' + $(trendsSwitch).find('option:selected').val() + '"]').addClass('current');
        var season = activeTab.replace('season_', '');
        if (Drupal.settings.nasClimateFeature && Drupal.settings.nasClimateFeature.chart) {
          Drupal.settings.nasClimateFeature.chart.setSeason(season);
        }
      });

      // Logic for tabs.
      var tabWrap = $('ul.tabs-content', context);
      $('li', tabWrap).click(function () {
        var trendsSwitch = $('#edit-park-trend')
          , formSubmit = $('#edit-submit-park-bird-trends');
        var tabId = $(this).attr('data-tab');

        $('li', tabWrap).removeClass('current');
        $('.tab-content').removeClass('current');

        $(this).addClass('current');

        $(".container-data-tabs").find("[data-content='" + tabId + "']").addClass('current');

        $(trendsSwitch).find('option[value="' + tabId.replace('display-', '') + '"]').prop('selected', true);
        $(formSubmit).click();
      });
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
