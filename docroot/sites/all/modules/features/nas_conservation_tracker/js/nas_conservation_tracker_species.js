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

  Drupal.behaviors.filterUppdate = {
    attach: function (context, settings) {
      // Insert block to another block.
      $('#views-exposed-form-ct-species-default').once(function () {
        var threatWrap = $('#edit-threat-status .fieldset-wrapper', context);
        $('.form-item', threatWrap).wrapAll('<div class="wrap-items"><div class="help-items"></div>');
        $('<div class="fieldset-title second">Audubon Climate<span class="fieldset-legend-prefix"></span></div>').prependTo('.wrap-items');
        $('#edit-iucn-wrapper',context).insertAfter('.wrap-items');
      });

      var wrapItems = $('.help-items');
      var wrapMainItems = $('.wrap-items');
      var classHide = 'js-close';

      // Hide block by default.
      wrapItems.addClass(classHide);
      $('.fieldset-title.second span').addClass('js-down');

      $('.fieldset-title.second').click(function (e) {
        e.preventDefault();
        if (wrapItems.hasClass(classHide)) {
          wrapItems.slideDown('fast').removeClass('js-close');
          $('span', this).removeClass('js-down');
        } else {
          wrapItems.slideUp('fast').addClass('js-close');
          $('span', this).addClass('js-down');
        }

      })
    }
  };

})(jQuery, window.Drupal);