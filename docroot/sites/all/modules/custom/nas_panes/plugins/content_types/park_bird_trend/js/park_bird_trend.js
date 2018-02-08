(function ($) {

  Drupal.behaviors.tabParkPage = {
    attach: function (context, settings) {
      var tabsItem = $('.tab-slider--tabs', context);
      var tabsNav = $('.tab-slider--nav li', context);
      var tabsBody = $('.tab-slider--body', context);

      var seasonMap = {'1':'season_summer', '2':'season_winter'};
      var trendMap = {'species': 'display-current', 'extirpations': 'display-extirpation', 'colonizations': 'display-colonization'};

      $("document").ready(function () {
        tabsBody.hide();
        $(".tab-slider--body:first").show();
      });

      $('.switch-wrap').once('tab-init', function(){
        $('.tab-slider--trigger').removeClass('active').filter('[rel="' + seasonMap[$('#edit-season option:selected').val()] + '"]').addClass('active');
        $('.tabs-content__link').removeClass('active').filter('[data-tab="' + trendMap[$('#edit-park-trend option:selected').val()] + '"]').addClass('active');
      });

      tabsNav.click(function () {
        tabsBody.hide();
        var activeTab = $(this).attr("rel");

        $("#" + activeTab).fadeIn();

        if ($(this).attr("rel") === "tab2") {
          tabsItem.addClass('slide');
        }
        else {
          tabsItem.removeClass('slide');
        }
        tabsNav.removeClass("active");
        $(this).addClass("active");


        if (activeTab == 'season_winter') {
          $('#edit-season option[value=2]').prop('selected', true);
        }
        else {
          $('#edit-season option[value=1]').prop('selected', true);
        }
        $('#edit-submit-park-bird-trends').click();
      });


      // Logic for tabs.
      var tabWrap = $('ul.tabs-content', context);
      $('li', tabWrap).click(function(){
        var tab_id = $(this).attr('data-tab');

        $('li', tabWrap).removeClass('current');
        $('.tab-content').removeClass('current');

        $(this).addClass('current');
        //$("."+tab_id).addClass('current');
        $(".container-data-tabs").find("[data-content='" + tab_id + "']").addClass('current');

        if (tab_id == 'display-current') {
          $('#edit-park-trend option[value="species"]').prop('selected', true);
        }
        else if(tab_id == 'display-extirpation'){
          $('#edit-park-trend option[value="extirpations"]').prop('selected', true);
        }
        else {
          $('#edit-park-trend option[value="colonizations"]').prop('selected', true);
        }
        $('#edit-submit-park-bird-trends').click();
      });

      $('.node-type-park .hero-header h1').click(function (e) {
        e.preventDefault();
        $('.drop-down-list').slideToggle('fast');
      })
    }
  };
})(jQuery);