(function ($) {

  Drupal.behaviors.tabParkPage = {
    attach: function (context, settings) {

      var tabsItem = $('.tab-slider--tabs', context)
        , tabsNav = $('.tab-slider--nav li', context)
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
        $('.tabs-content__link').removeClass('active').filter('[data-tab="display-' + $(trendsSwitch).find('option:selected').val() + '"]').addClass('current');
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

      $('.node-type-park .hero-header h1').click(function (e) {
        e.preventDefault();
        $('.drop-down-list').slideToggle('fast');
      })
    }
  };

})(jQuery);
