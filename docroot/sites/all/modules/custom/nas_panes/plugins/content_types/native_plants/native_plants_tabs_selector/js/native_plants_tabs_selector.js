(function($) {
  Drupal.behaviors.native_plants_tabs_selector = {};
  Drupal.behaviors.native_plants_tabs_selector.attach = function(context, settings) {
    $('.js-native-plants-tabs').once('native-plants-tabs').responsiveTabs({
      startCollapsed: 'accordion',
      animation: 'slide',
      duration: 200,
      scrollToAccordion: true
    });

    // Re-compile dynamically injected DOM content.
    var content = $('.r-tabs-accordion-title');
    angular.element($('body')[0]).injector().invoke(function($compile) {
      var scope = angular.element(content).scope();
      $compile(content)(scope);
    });
  };

})(jQuery);
