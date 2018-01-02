(function ($) {
  Drupal.behaviors.cta_tabs_angular = {};
  Drupal.behaviors.cta_tabs_angular.attach = function (context, settings) {

    if ($('body').hasClass('nas-cta-tabs-angular-processed')) {
      return;
    }
    $('body').addClass('nas-cta-tabs-angular-processed');

    // @todo load from backend
    var linkArray = ['threats', 'actions', 'responses', 'partners']
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

    var NativeCtaApp = angular.module('NativeCta', [
      'ngCookies',
      'ngSanitize',
      'ngAnimate',
      'ui.router',
      'ngStorage',
      'duScroll'
    ]).directive('tabsRepeatDirective', function() {
      return function($scope, element, attrs) {
        if ($scope.$last){
          // Drupal.attachBehaviors($('.body-item '));
        }
      };
    });


    NativeCtaApp.run([
      '$rootScope', '$state', '$stateParams', '$browser',
      function ($rootScope, $state, $stateParams) {
        $rootScope.$state = $state;
        $rootScope.$stateParams = $stateParams;
      }
    ]);

    NativeCtaApp.config(function ($stateProvider, $locationProvider, $urlRouterProvider) {
      $locationProvider.hashPrefix('');

      $locationProvider.html5Mode({
        enabled: true,
        rewriteLinks: false
      });

      linkArray.forEach(function(item) {
          $stateProvider.state(item, {url: activeUrl + '/' + item});
      });

    });

    NativeCtaApp.controller('Tabs', [
      '$scope', '$stateParams', '$state',
      function ($scope, $stateParams, $state) {

        $scope.active = function (route) {
          return $state.is(route);
        };

        var tabsArray = [];
        linkArray.forEach(function(item) {
          tabsArray.push({heading: item, route: item, active: false, class: item});
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

    NativeCtaApp.controller('Content', [
      '$scope', '$stateParams', '$state', '$rootScope', '$http',
      function ($scope, $stateParams, $state, $rootScope, $http) {
      // @todo update var.

       var idItem = Drupal.settings.nas_conservation_tracker.scorecardId;

        // Load json file.
        function getContent(currentName) {
          if (linkArray.indexOf(currentName) > -1) {
            Drupal.settings.nas_conservation_tracker.tabsOverview = Drupal.settings.nas_conservation_tracker.tabsOverview || {};
            Drupal.settings.nas_conservation_tracker.tabsData = Drupal.settings.nas_conservation_tracker.tabsData || {};

            // Load data via ajax only once.
            if (!angular.isDefined(Drupal.settings.nas_conservation_tracker.tabsOverview[currentName])) {
              // @todo take from backend
              $http.get('/conservation-tracker/ajax/scorecard/' + idItem + '/' + currentName)
                .then(function (response) {
                  var tabData = response.data.data;
                  tabData.settings.overview = tabData.settings[currentName];
                  tabData.settings.overview.preparedLink = {'target': '_self'};
                  if (angular.isDefined(tabData.settings.overview.image)) {
                    tabData.settings.overview.preparedLink.class = 'colorbox-load';
                    tabData.settings.overview.preparedLink.href = tabData.settings.overview.image + '?iframe=false';
                  }
                  else if (angular.isDefined(tabData.settings.overview.iframe)) {
                    tabData.settings.overview.preparedLink.class = 'colorbox-load';
                    var width = $(window).width() * 0.75;
                    var height = $(window).height() * 0.9;
                    tabData.settings.overview.preparedLink.href = tabData.settings.overview.iframe + '?width=' + width + '&height=' + height + '&iframe=true';
                  }
                  else if (angular.isDefined(tabData.settings.overview.link)) {
                    tabData.settings.overview.preparedLink.class = 'overview-link';
                    tabData.settings.overview.preparedLink.href = tabData.settings.overview.link;
                    tabData.settings.overview.preparedLink.target = '_blank';
                  }

                  // Add partners array to scope.
                  // If partners tabs.
                  if (currentName === 'partners') {
                      tabData.settings.overview.partners = tabData.partners;
                  }

                  tabData.settings.tabs = linkArray;
                  Drupal.settings.nas_conservation_tracker.tabsOverview[currentName] = tabData;
                  Drupal.settings.nas_conservation_tracker.tabsData[currentName] = response.data.data;
                  $scope['tab'] = tabData;
                  updateTabData(response.data.data);

                });
            }
            else {
              // Make sure url was changed.
              setTimeout(function(){
                  $scope['tab'] = Drupal.settings.nas_conservation_tracker.tabsOverview[currentName];
                  updateTabData(Drupal.settings.nas_conservation_tracker.tabsData[currentName]);
                  Drupal.attachBehaviors($('.' + currentName + '-tab-wrapper'));
                  $scope.$apply();

              }, 500);
            }

          }
        }
        function updateTabData(data) {
          if (angular.isDefined(data)) {
            Drupal.settings.nas_conservation_tracker.json_data = data;
            Drupal.nas_conservation_tracker_init_map();
            Drupal.nas_conservation_tracker_init_charts();
          }
        }

        // On load.
        $rootScope.$on('$stateChangeSuccess', function (event, transition) {
          getContent($state['current']['name']);
          $scope.isActive = transition.name;

          setTimeout(function(){
            Drupal.attachBehaviors($('.' + $state['current']['name'] + '-tab-wrapper'));
          }, 1000);

        });

        // On change.
        $rootScope.$on("$locationChangeStart", function (event, next, current) {
          // Placeholder.
        });

        // On change.
        $rootScope.$on("$locationChangeSuccess", function (event, next, current) {
          // Placeholder.
        });




      }
    ]);

    angular.bootstrap(document.getElementsByTagName('body')[0], ['NativeCta']);
  };
})(jQuery);

