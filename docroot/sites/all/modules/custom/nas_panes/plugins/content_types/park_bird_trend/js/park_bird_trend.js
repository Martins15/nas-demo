(function ($) {

  Drupal.behaviors.tabParkPage = {
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

  Drupal.behaviors.cloneImgPark = {
    attach: function (context) {
      var cloneImg = $('.node-type-park .field-name-field-park-map-image', context).clone();
      cloneImg.addClass('js-clone-img');
      $('.node-type-park .park_info', context).prepend(cloneImg);
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
