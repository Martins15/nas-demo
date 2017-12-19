(function ($) {
  Drupal.behaviors.cta_tabs_angular = {};
  Drupal.behaviors.cta_tabs_angular.attach = function (context, settings) {

    if ($('body').hasClass('nas-cta-tabs-angular-processed')) {
      return;
    }
    $('body').addClass('nas-cta-tabs-angular-processed');

    // Set constant for url page.
    const threats = 'threats',
      actions = 'actions',
      responses = 'responses';

    var NativeCtaApp = angular.module('NativeCta', [
      'ngCookies',
      'ngSanitize',
      'ngAnimate',
      'ui.router',
      'ngStorage',
      'duScroll'
    ]);


    NativeCtaApp.run([
      '$rootScope', '$state', '$stateParams',
      function ($rootScope, $state, $stateParams) {
        $rootScope.$state = $state;
        $rootScope.$stateParams = $stateParams;
      }
    ]);

    NativeCtaApp.config(function ($stateProvider, $locationProvider, $urlRouterProvider) {
      $locationProvider.hashPrefix('');
      $urlRouterProvider.otherwise("/");

      $stateProvider
        .state(threats, {
          url: '/' + threats
        })
        .state(actions, {
          url: '/' + actions
        })
        .state(responses, {
          url: '/' + responses
        });
    });

    NativeCtaApp.controller('Tabs', [
      '$scope', '$stateParams', '$state',
      function ($scope, $stateParams, $state) {

        $scope.active = function (route) {
          return $state.is(route);
        };

        $scope.tabs = [
          {heading: "threats", route: threats, active: false, class: 'threats'},
          {heading: "actions", route: actions, active: false, class: 'actions'},
          {heading: "responses", route: responses, active: false, class: 'responses'}
        ];

        $scope.$on("$stateChangeSuccess", function () { // Keep the right tab highlighted if the URL changes.
          $scope.tabs.forEach(function (tab) {
            tab.active = $scope.active(tab.route);
          });
        });

      }
    ]);

    NativeCtaApp.controller('Content', [
      '$scope', '$stateParams', '$state', '$rootScope', '$http',
      function ($scope, $stateParams, $state, $rootScope, $http) {
      // @todo update var.
       var idItem = 123;

        // Load json file.
        function getContent(currentName) {
          if (currentName === threats) {
            $http.get('http://nas.docksal/conservation-tracker/ajax/scorecard/' + idItem + '/threats')
              .then(function (response) {
                $scope.threats = response.data;
              });
          }
          if (currentName === actions) {
            $http.get('http://nas.docksal/conservation-tracker/ajax/scorecard/' + idItem + '/actions')
              .then(function (response) {
                $scope.actions = response.data;
              });
          }
          if (currentName === responses) {
            $http.get('http://nas.docksal/conservation-tracker/ajax/scorecard/' + idItem + '/responses')
              .then(function (response) {
                $scope.responses = response.data;
              });
          }
        }

        // On load.
        $rootScope.$on('$stateChangeSuccess', function (event, transition) {
          getContent($state['current']['name']);
        });

        // On change.
        $rootScope.$on("$locationChangeStart", function (event, next, current) {
        });
      }
    ]);


    angular.bootstrap(document.getElementsByTagName('body')[0], ['NativeCta']);
  };
})(jQuery);

