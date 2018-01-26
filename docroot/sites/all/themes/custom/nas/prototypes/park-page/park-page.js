(function ($) {

  Drupal.behaviors.tabParkPage = {
    attach: function (context, settings) {
      var tabsItem = $('.tab-slider--tabs', context);
      var tabsNav = $('.tab-slider--nav li', context);
      var tabsBody = $('.tab-slider--body', context);

      $("document").ready(function () {
        tabsBody.hide();
        $(".tab-slider--body:first").show();
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
      })
    }
  };
})(jQuery);