(function ($) {

  Drupal.behaviors.tabParkPage = {
    attach: function (context, settings) {

      var tabsItem = $('.switch-wrap .tab-slider--tabs', context)
        , tabsNav = $('.switch-wrap .tab-slider--nav li')
        , tabsBody = $('.tab-slider--body', context)
        , seasonSwitch = $('#edit-season')
        , trendsSwitch = $('#edit-park-trend');


      var seasonMap = {'1': 'season_summer', '2': 'season_winter'};

      $('.switch-wrap').once('tab-init', function () {
        var seasonCur = seasonMap[$(seasonSwitch).find('option:selected').val()];

        var season = '';

        $('.switch-wrap .tab-slider--trigger').removeClass('active').filter('[rel="' + seasonCur + '"]').addClass('active');

        if (seasonCur == 'season_winter') {
          tabsItem.addClass('slide');
          season = 'winter';
        }
        else {
          season = 'summer';
        }

        $('.tabs-content__link').removeClass('current').filter('[data-tab="display-' + $(trendsSwitch).find('option:selected').val() + '"]').addClass('current');
        $('.tab-content').removeClass('current').filter('.tab-season-' + season + '[data-content="display-' + $(trendsSwitch).find('option:selected').val() + '"]').addClass('current');
        if (typeof StamenAudubonParks != 'undefined') {
          Drupal.settings.nasClimateFeature.birdDot = new StamenAudubonParks.BirdDots({
            element: '#chart',
            currentCounter: '.tabs-content__link.species .link__number',
            colonizedCounter: '.tabs-content__link.colonizations .link__number',
            extirpatedCounter: '.tabs-content__link.extirpations .link__number',
            dataUrl: Drupal.settings.nasClimateFeature.dataUrl,
            park: Drupal.settings.nasClimateFeature.parkTitle,
            season: season,
            initStats: false,
            onLoad: function () {
              initStamenUIWaypoint();
            }
          });
        }
        else {
          $('.tabs-content__link.species .link__number').text($(".container-data-tabs").find(".tab-season-" + season + "[data-content='display-species']").attr('data-amount'));
          $('.tabs-content__link.extirpations .link__number').text($(".container-data-tabs").find(".tab-season-" + season + "[data-content='display-extirpations']").attr('data-amount'));
          $('.tabs-content__link.colonizations .link__number').text($(".container-data-tabs").find(".tab-season-" + season + "[data-content='display-colonizations']").attr('data-amount'));
        }


      });

      /**
       * Helper function to make waypoint (delay in scroll) for dots animation.
       */
      function initStamenUIWaypoint() {
        var el = $('.parks_blog');
        var waypoint = new Waypoint({
          element: el[0],
          handler: function (direction) {
            Drupal.settings.nasClimateFeature.birdDot.animateIn(initStamenUI);
            this.destroy();
          },
          offset: '60%'
        });
      }

      function initStamenUI() {
        d3.select('.tabs-content__link.species').classed('selected', true);
        d3.select('.tabs-content__link.extirpations').classed('selected', false);
        d3.select('.tabs-content__link.colonizations').classed('selected', false);

        var trend = $(trendsSwitch).find('option:selected').val();
        if (trend == 'extirpations') {
          Drupal.settings.nasClimateFeature.birdDot.setExtirpated();
        }
        else if (trend == 'colonizations') {
          Drupal.settings.nasClimateFeature.birdDot.setColonized();
        }
        else {
          Drupal.settings.nasClimateFeature.birdDot.setCurrent();

        }

        d3.select('.tabs-content__link.species').on('click', function () {
          d3.select('.tabs-content__link.species').classed('selected', true);
          d3.select('.tabs-content__link.extirpations').classed('selected', false);
          d3.select('.tabs-content__link.colonizations').classed('selected', false);
          Drupal.settings.nasClimateFeature.birdDot.setCurrent();
        });

        d3.select('.tabs-content__link.extirpations').on('click', function () {
          d3.select('.tabs-content__link.species').classed('selected', false);
          d3.select('.tabs-content__link.extirpations').classed('selected', true);
          d3.select('.tabs-content__link.colonizations').classed('selected', false);
          Drupal.settings.nasClimateFeature.birdDot.setExtirpated();
        });

        d3.select('.tabs-content__link.colonizations').on('click', function () {
          d3.select('.tabs-content__link.species').classed('selected', false);
          d3.select('.tabs-content__link.extirpations').classed('selected', false);
          d3.select('.tabs-content__link.colonizations').classed('selected', true);
          Drupal.settings.nasClimateFeature.birdDot.setColonized();
        });

      }
      var tabWrap = $('ul.tabs-content', context);

      tabsNav.click(function () {
        var seasonSwitch = $('#edit-season')
          , formSubmit = $('#edit-submit-park-bird-trends');

        var activeTab = $(this).attr("rel");

        if ($(this).attr("rel") === "season_winter") {
          tabsItem.addClass('slide');
          $(seasonSwitch).find('option[value=2]').prop('selected', true);
          if (typeof StamenAudubonParks != 'undefined') {
            Drupal.settings.nasClimateFeature.birdDot.setSeason('winter');
          }
          var season = 'winter';
        }
        else {
          tabsItem.removeClass('slide');
          $(seasonSwitch).find('option[value=1]').prop('selected', true);
          if (typeof StamenAudubonParks != 'undefined') {
            Drupal.settings.nasClimateFeature.birdDot.setSeason('summer');
          }
          var season = 'summer';
        }

        if (typeof StamenAudubonParks == 'undefined') {
          $('.tabs-content__link.species .link__number').text($(".container-data-tabs").find(".tab-season-" + season + "[data-content='display-species']").attr('data-amount'));
          $('.tabs-content__link.extirpations .link__number').text($(".container-data-tabs").find(".tab-season-" + season + "[data-content='display-extirpations']").attr('data-amount'));
          $('.tabs-content__link.colonizations .link__number').text($(".container-data-tabs").find(".tab-season-" + season + "[data-content='display-colonizations']").attr('data-amount'));
        }

        tabsNav.removeClass("active");
        $(this).addClass("active");

        $('.tabs-content__link').removeClass('current').filter('[data-tab="display-' + $(trendsSwitch).find('option:selected').val() + '"]').addClass('current');

        var season = activeTab.replace('season_', '');
        if (Drupal.settings.nasClimateFeature && Drupal.settings.nasClimateFeature.chart) {
          Drupal.settings.nasClimateFeature.chart.setSeason(season);
        }

        $(formSubmit).click();
      });

      // Logic for tabs.
      $('li', tabWrap).click(function () {
        var trendsSwitch = $('#edit-park-trend')
          , formSubmit = $('#edit-submit-park-bird-trends');
        var tabId = $(this).attr('data-tab');

        var season = tabsNav.filter('.active').attr("rel").replace('season_', '');

        $('li', tabWrap).removeClass('current');
        $('.tab-content').removeClass('current');

        $(this).addClass('current');

        $(".container-data-tabs").find(".tab-season-" + season + "[data-content='" + tabId + "']").addClass('current');

        $(trendsSwitch).find('option[value="' + tabId.replace('display-', '') + '"]').prop('selected', true);
        $(formSubmit).click();
      });
    }
  };

  Drupal.behaviors.sliderScoreCard = {
    attach: function (context) {
      var $slierWrap = $('.switch-wrap .tabs-content', context);
      if ($slierWrap.length) {
        $(document).ready(function(){
          if ($(window).width() <= 767) {
            $slierWrap.owlCarousel({
              item: 1,
              loop: false,
              singleItem: true,
              center: true,
              pagination: true,
              navigation : true,
              afterAction: function(el){
                var current = this.currentItem;
                var active = el.find(".owl-item").eq(current).find('li');
                active.click();
              }
            });
          }
        });
      }
    }
  };

  Drupal.behaviors.cloneFieldpark = {
    attach: function (context) {
      var $nodeType = $('.node-type-park', context);
      var $imgPark = $('.field-name-field-park-map-image img', $nodeType);
      $('.field-name-field-state, .field-name-field-park-area, .field-name-field-link, .field-name-field-location-link', $nodeType)
        .wrapAll('<div class="help-wrap-field" />');
      var $helpWrap = $('.help-wrap-field');
      if ($imgPark.length) {
        var $cloneImg = $('.field-name-field-park-map-image', $nodeType).clone();
        $cloneImg.addClass('js-clone-img');
        $('.park_info', $nodeType).prepend($cloneImg);
        $helpWrap.addClass('js-img-in')
      }
    }
  };

  Drupal.behaviors.toogleTitle = {
    attach: function (context) {
      $('.node-type-park .list-of-park__current-page a', context).click(function (e) {
        e.preventDefault();
        $('.list-of-park__others-page', context).toggleClass('js-show');
      })
    }
  };

  Drupal.behaviors.throbbeViewsPark = {
    attach: function (context, settings) {
      var viewsWrap = $('.view-park-bird-trends.view-id-park_bird_trends'),
        itemsWrap = $('.view-content', viewsWrap),
        classPreload = 'js-preload';

      viewsWrap.ajaxStart(function () {
        itemsWrap.fadeTo(300, 0.5).addClass(classPreload);
      });
      viewsWrap.ajaxSuccess(function () {
        itemsWrap.fadeTo(300, 1.0).removeClass(classPreload);
      })
    }
  };

})(jQuery);
