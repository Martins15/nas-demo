/*global Drupal: false, jQuery: false */
/*jslint devel: true, browser: true, maxerr: 50, indent: 2 */
(function ($) {
  "use strict";

  Drupal.behaviors.nas_language_message = {};
  Drupal.behaviors.nas_language_message.attach = function() {
    $('body').once('nas-language-message', function() {
      var show = $.cookie('nas_language_message');
      if (show == 1) {
        Drupal.CTools.Modal.show('naslanguagemessagemodal');
        $.cookie('nas_language_message', 0, {expires: 7, path: Drupal.settings.basePath});
      }
    });
  }

})(jQuery);
