(function ($) {

  Drupal.behaviors.tabParkPage = {
    attach: function (context, settings) {
      var tabsItem = $('.tab-slider--tabs', context)
        , tabsNav = $('.tab-slider--nav li', context)
        , tabsBody = $('.tab-slider--body', context)
        , seasonSwitch = $('#edit-field-park-season-value')
        , formSubmit = $('#edit-submit-park-bird-trends');

      $("document").ready(function () {
        tabsBody.hide();
        $(".tab-slider--body:first").show();
        tabsItem.find('li:first').addClass('active');
      });

      tabsNav.click(function () {
        tabsBody.hide();
        var activeTab = $(this).attr("rel");
        $("#" + activeTab).fadeIn();
        if ($(this).attr("rel") === "season_winter") {
          tabsItem.addClass('slide');
          $(seasonSwitch).val(2);
        }
        else {
          tabsItem.removeClass('slide');
          $(seasonSwitch).val(1);
        }
        $(formSubmit).click();
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
      });

      $('.node-type-park .hero-header h1').click(function (e) {
        e.preventDefault();
        $('.drop-down-list').slideToggle('fast');
      })
    }
  };

})(jQuery);