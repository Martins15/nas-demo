
(function ($) {
  Drupal.behaviors.cta_tabs_angular = {};
  Drupal.behaviors.cta_tabs_angular.attach = function(context, settings) {

    if ($('body').hasClass('nas-cta-tabs-angular-processed')) {
      return;
    }
    $('body').addClass('nas-cta-tabs-angular-processed');

    var NativeCtaApp = angular.module('NativeCta', ['ngCookies', 'ngSanitize', 'ngAnimate', 'ui.router', 'ngStorage', 'duScroll'])
    .run(['$rootScope', '$state', '$stateParams',
      function ($rootScope, $state, $stateParams) {
        $rootScope.$state = $state;
        $rootScope.$stateParams = $stateParams;
      }]);

    NativeCtaApp.config(function($stateProvider,$locationProvider, $urlRouterProvider) {
      $locationProvider.hashPrefix('');
      $urlRouterProvider.otherwise("/");
      $stateProvider
        .state('threats', {
          url: "/threats"
        })
        .state('actions', {
          url: '/actions'
        })
        .state('responses', {
          url: "/responses"
        });
    });

    NativeCtaApp.controller('Tabs', ['$scope', '$stateParams', '$state',
      function($scope, $stateParams, $state) {

        $scope.active = function(route) {
          return $state.is(route);
        };

        $scope.tabs = [
          { heading: "Threats", route:"threats", active:false },
          { heading: "Actions", route:"actions", active:false },
          { heading: "Responses", route:"responses", active:false }
        ];

        $scope.$on("$stateChangeSuccess", function() { // Keep the right tab highlighted if the URL changes.
          $scope.tabs.forEach(function(tab) {
            tab.active = $scope.active(tab.route);
          });
        });

      }
    ]);


    angular.bootstrap(document.getElementsByTagName('body')[0], ['NativeCta']);
  };
})(jQuery);

