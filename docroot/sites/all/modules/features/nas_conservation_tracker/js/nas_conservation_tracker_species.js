/**
 * @file
 * NAS CT Custom JS.
 */

(function ($, Drupal) {
  // Custom breadcrumbs for bird page.
  Drupal.behaviors.nasCtSpecies = {
    attach: function (context, settings) {
      var $a = $('#reset-filters a');
      if (location.search.length || location.pathname !== settings.nasConservationTracker.speciesPath) {
        $a.show();
      }
      else {
        $a.hide();
      }
      $('#species-aplphabet li a').click(function (e) {
        e.preventDefault();
        //alert($(this).data('letter'));
        //$(this).parent().addClass('active').siblings().removeClass('active');
        $('input[name="letter"]').val($(this).data('letter'));
        $('input#edit-submit-ct-species').click();
      })
    }
  };

  Drupal.behaviors.styleAjaxViews = {
    attach: function (context, settings) {

      var viewsWrap = $('.view-ct-species'),
        itemsWrap = $('.birds-wrap'),
        classPreload = 'js-preload';

      viewsWrap.ajaxStart(function(){
        itemsWrap.fadeTo(300, 0.5).addClass(classPreload);
      });
      viewsWrap.ajaxSuccess(function(){
        itemsWrap.fadeTo(300, 1.0).removeClass(classPreload);
      })
    }
  };
})(jQuery, window.Drupal);