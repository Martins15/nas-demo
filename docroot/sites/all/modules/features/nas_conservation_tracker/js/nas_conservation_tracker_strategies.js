/**
 * @file
 * NAS CT Custom JS.
 */
(function ($, Drupal) {
  var strategiesMap = {
    'coasts': 'coasts',
    'working-lands': 'working lands',
    'water': 'water',
    'bird-friendly-communities': '',
    'climate': ''
  };

  Drupal.behaviors.nasCtInitStrategies = {
    attach: function (context, settings) {
      $.get(
          '/conservation-tracker/ajax/landscapes',
          function (data) {
            Drupal.settings.nasConservationTracker = Drupal.settings.nasConservationTracker || {};
            Drupal.settings.nasConservationTracker.landscapes = data.data;
            Drupal.nasCtInitLandscapesMap([]);

            var link = window.location.pathname.split('/').slice(-1)[0];
            if (strategiesMap[link]) {
              var filters = {
                strategy: strategiesMap[link],
                status: 'all',
                flyways: 'all'
              };
            }
            else {
              var filters = {'strategy': null, 'status': [], 'flyways': []};
            }
            Drupal.nasConservationTracker.updateLandscapesFilters(filters);

          }
      );
    }
  };


  Drupal.behaviors.nasCtStrategies = {
    attach: function (context, settings) {
      //alert('fdgfdf');
      var app = angular.module('nasCtStrategies', ['ui.bootstrap'])
          .config(['$locationProvider', function ($locationProvider) {
            $locationProvider.hashPrefix('');
            $locationProvider.html5Mode({
              enabled: true,
              rewriteLinks: false
            });
          }]);
      var tabs = function ($scope, $http, $timeout, $location) {
        var links = [];
        var active = 0;
        $scope.tabs = [];
        for (var i in settings.nasConservationTracker.strategies) {
          var strategy = settings.nasConservationTracker.strategies[i];
          strategy.isLoaded = false;
          //strategy.content = [];
          links.push(strategy.link);
          $scope.tabs.push(strategy);
        }

        if (location.pathname !== settings.nasConservationTracker.basePath) {
          var link = window.location.pathname.split('/').slice(-1)[0];
          for (var j in settings.nasConservationTracker.strategies) {
            if (settings.nasConservationTracker.strategies[j].link == link) {
              active = j;
              break;
            }
          }
        }
        settings.nasConservationTracker.strategies[active].active = true;

        $scope.getClass = function (index) {

          return 'tab-' + $scope.tabs[index].link;
        };

        $scope.getContent = function (index) {

          /* see if we have data already */
          $location.path(settings.nasConservationTracker.basePath + '/' + $scope.tabs[index].link);
          if (!$scope.tabs[index].isLoaded) {
            /* or make request for data delayed to show Loading... */
            $timeout(function () {
              var jsonFile = '/conservation-tracker/ajax/strategy/' + $scope.tabs[index].id;


              $http.get(jsonFile).then(function (result) {
                //console.log('DATA', result);
                $scope.tabs[index].subTabs = result.data.data.tabs;
                $scope.tabs[index].tagline = result.data.data.tagline;
                $scope.tabs[index].isLoaded = true;
              });
            }, 100);
          }
          $scope.isActiveTab = $scope.tabs[index].name;
          $scope.isActiveTabLink = $scope.tabs[index].link;

          if (strategiesMap[$scope.tabs[index].link]) {
            var filters = {
              strategy: strategiesMap[$scope.tabs[index].link],
              status: 'all',
              flyways: 'all'
            };
          }
          else {
            var filters = {'strategy': null, 'status': [], 'flyways': []};
          }
          Drupal.nasConservationTracker.updateLandscapesFilters(filters);

          $scope.toggle = false;
          $scope.toggle_wrap = false;
        };

        $scope.tab = 1;

        $scope.setTab = function (newTab) {
          $scope.tab = newTab;
        };

        $scope.isSet = function (tabNum) {
          return $scope.tab === tabNum;
        };
      };


      app.controller('tabs', tabs);
    }
  };
})(jQuery, window.Drupal);