(function($) {
  /**
   * Tabs.
   */
  Drupal.behaviors.you_near_audubon = {};
  Drupal.behaviors.you_near_audubon.attach = function(context, settings) {
    var $triggers = $('.native-plants-you-near-audubon .text--blue', context);

    $triggers.on('click', function() {
      $('ul.tabs li a[href="#local_resources"]').click();
    });
  };
})(jQuery);
