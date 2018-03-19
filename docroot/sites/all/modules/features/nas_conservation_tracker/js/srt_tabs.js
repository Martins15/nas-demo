(function ($) {
  Drupal.behaviors.srt_tabs_angular = {};
  Drupal.behaviors.srt_tabs_angular.attach = function (context, settings) {

    if ($('body').hasClass('nas-strategies-tabs-angular-processed')) {
      return;
    }
    $('body').addClass('nas-strategies-tabs-angular-processed');

    // @todo load from backend
    var linkArray = ['threats', 'actions', 'response', 'partners']
      , pathName = window.location.pathname
      , pathArray = window.location.pathname.split('/')
      , lastName = pathArray.slice(-1)[0]
      , activeUrl = '';

    $('head').append('<base href="' + settings.basePath + '">');


    if (linkArray.indexOf(lastName) > -1) {
      activeUrl = pathArray.slice(0, -1).join('/');
    }
    else {
      activeUrl = pathName;
    }

    var NativeStrApp = angular.module('NativeStr', [
      'ngCookies',
      'ngSanitize',
      'ngAnimate',
      'ui.router',
      'ngStorage',
      'duScroll'
    ]).directive('tabsRepeatDirective', function () {
      return function ($scope, element, attrs) {
        if ($scope.$last) {

          // Drupal.attachBehaviors($('.body-item '));
        }
      };
    });


    NativeStrApp.run([
      '$rootScope', '$state', '$stateParams', '$browser',
      function ($rootScope, $state, $stateParams) {
        $rootScope.$state = $state;
        $rootScope.$stateParams = $stateParams;
      }
    ]);

    NativeStrApp.config(function ($stateProvider, $locationProvider, $urlRouterProvider) {
      $locationProvider.hashPrefix('');

      $locationProvider.html5Mode({
        enabled: true,
        rewriteLinks: false
      });

      linkArray.forEach(function (item) {
        $stateProvider.state(item, {url: activeUrl + '/' + item});
      });

    });

    NativeStrApp.controller('Tabs', [
      '$scope', '$stateParams', '$state', '$http',
      function ($scope, $stateParams, $state, $http) {

        $scope.active = function (route) {
          return $state.is(route);
        };

        var tabsArray = [];
        linkArray.forEach(function (item) {
          tabsArray.push({
            heading: item,
            route: item,
            active: false,
            class: item
          });
        });

        $scope.tabs = tabsArray;

        $scope.$on("$stateChangeSuccess", function () { // Keep the right tab highlighted if the URL changes.
          $scope.tabs.forEach(function (tab) {
            tab.active = $scope.active(tab.route);
          });
          $scope.isActiveTab = $state.current.name;
        });


      }
    ]);


    angular.bootstrap(document.getElementsByTagName('body')[0], ['NativeStr']);
  };
})(jQuery);

