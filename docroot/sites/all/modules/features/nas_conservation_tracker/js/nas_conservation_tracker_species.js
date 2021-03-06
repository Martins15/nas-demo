/**
 * @file
 * NAS CT Custom JS.
 */

(function ($, Drupal) {
  // Custom breadcrumbs for bird page.
  Drupal.behaviors.nasCtSpecies = {
    attach: function (context, settings) {
      $('body').once('scrollonreset', function() {
        if (location.search.indexOf('reset') == 1) {
          $('html, body').animate({
            scrollTop: $("#species-list").offset().top + $(window).height()
          }, 200);
        };
      });
      var $a = $('#reset-filters a');
      if (location.search.length || location.pathname !== settings.nasConservationTracker.speciesPath) {
        $a.show();
      }
      else {
        $a.hide();
      }
      var $form = $('#views-exposed-form-ct-species-default');

      $('#species-aplphabet li a').click(function (e) {
        e.preventDefault();
        $('input[name="letter"]').val($(this).data('letter'));
        $form.find('input[type="radio"][value="All"]').prop("checked", true);
        $form.find('input[name="search"]').val('');
        $('input#edit-submit-ct-species').click();
      });

      $form.find('input[type="radio"]').change(function (e) {
        $form.find('input[type="radio"][name!="' + e.target.name + '"][value="All"]').prop("checked", true);
        $form.find('input[type="text"]').val('');
      });

      $form.find('input[type="text"]').on('input', function (e) {
        $form.find('input[type="radio"][value="All"]').prop("checked", true);
        $form.find('input[name="letter"]').val('');
      });


      $form.ajaxComplete(function(event, xhr, settings) {
        if (Drupal.curtain) {
          Drupal.curtain.reset();
          Drupal.curtain.setup();
        }
      });
    }
  };

  Drupal.behaviors.styleAjaxViews = {
    attach: function (context, settings) {

      var viewsWrap = $('.view-ct-species'),
        itemsWrap = $('.birds-wrap'),
        classPreload = 'js-preload';

      viewsWrap.ajaxStart(function () {
        itemsWrap.fadeTo(300, 0.5).addClass(classPreload);
      });
      viewsWrap.ajaxSuccess(function () {
        itemsWrap.fadeTo(300, 1.0).removeClass(classPreload);
      })
    }
  };

  Drupal.behaviors.filterUppdate = {
    attach: function (context, settings) {
      // Insert block to another block.
      $('#views-exposed-form-ct-species-default').once(function () {
        var $formWrap = $('#views-exposed-form-ct-species-default');
        var $linkWrap = $('> div:last-child', $formWrap);
        var threatWrap = $('#edit-threat-status .fieldset-wrapper', context);

        $('.form-item', threatWrap).wrapAll('<div class="wrap-items"><div class="help-items"></div>');
        $('<div class="fieldset-title second">Audubon Climate<span class="fieldset-legend-prefix"></span></div>').prependTo('.wrap-items');
        $('#edit-iucn-wrapper', context).insertAfter('.wrap-items');

        $('#edit-iucn .collapsible').addClass('collapsed').find('.fieldset-wrapper').hide();
        $linkWrap.addClass('js-link-wrap');
        $linkWrap.appendTo('#edit-search-wrapper', $formWrap);
      });

      var wrapItems = $('.help-items');
      var wrapMainItems = $('.wrap-items');
      var classHide = 'js-close';

      // Hide block by default.
      wrapItems.addClass(classHide);
      $('.fieldset-title.second span', context).addClass('js-down');

      $('.fieldset-title.second').once(function () {
        $('.fieldset-title.second', context).click(function (e) {
          e.preventDefault();
          if (wrapItems.hasClass(classHide)) {
            wrapItems.slideDown('fast').removeClass('js-close');
            $('span', this).removeClass('js-down');
          }
          else {
            wrapItems.slideUp('fast').addClass('js-close');
            $('span', this).addClass('js-down');
          }
        });
      })

    }
  };
  Drupal.behaviors.popUpSpecies = {
    attach: function (context, settings) {
      var $wrapCard = $('.species-filter', context);
      if ($wrapCard.length) {
        $wrapCard.once(function () {
          var titleText = Drupal.t('Interactive report in development.');
          var smallText = Drupal.t('Please check back later.');
          var popUpCard = $("<div class='overlay-popup'><div class='pop-up-species-filter'><i class='close-btn'></i>" +
            "<p class='pop-up-species-filter__title'>"+ titleText+ "</p>" +
            "<p class='pop-up-species-filter__small-text'>"+ smallText + "</p></div></div>");
          $('body').append(popUpCard);
        });

        var popupBlock = $('.overlay-popup');
        var classShow = 'js-show-popup';

        $('.bird-card-grid-container .no-scorecard-wrapper').click(function () {
          var birdCard = $(this).find('.views-view-fields .bird-card');
          popupBlock.addClass(classShow);
          $('.overlay-popup').css('position', 'absolute');
          $('.pop-up-species-filter').css({
            'left': birdCard.offset().left,
            'top': birdCard.offset().top - 2,
            'width': birdCard.width() + 3,
            'height': birdCard.height() + 8,
            'transform': 'translate(0, 0)',
            'position': 'absolute'
          });
        });

        $('i', popupBlock).click(function () {
          popupBlock.removeClass(classShow);
          $('.overlay-popup').css('position', 'fixed');
          $('.pop-up-species-filter').css({
            'left': '50%',
            'top': '50%',
            'transform': 'translate(-50%, -50%)',
            'position': 'fixed',
            'width': '70%',
            'height': 'auto'
          });
        });
      }
    }
  };


})(jQuery, window.Drupal);
