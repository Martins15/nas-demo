/**
 * @file Drupal behaviour 'see all' for Birds Native to This Area block.
 */
(function ($) {
  "use strict";

  Drupal.behaviors.seeall = {
    attach: function (context, settings) {
      $('.see-all', context).once('see-all', function () {
        var $this = $(this);
        $('.see-all-controller', $this).click(function () {
          $('.see-all-hide', $this).hide();
          $('.see-all-show', $this).show();
          return false;
        });
      });
    }
  };
})(jQuery);
