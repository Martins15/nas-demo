/*global Drupal: false, jQuery: false */
/*jslint devel: true, browser: true, maxerr: 50, indent: 2 */
(function ($) {
  "use strict";

  Drupal.behaviors.nas_language_message = {};
  Drupal.behaviors.nas_language_message.attach = function() {
    Drupal.CTools.Modal.show('naslanguagemessagemodal');
  }

})(jQuery);
