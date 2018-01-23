/**
 * @file
 * NAS CT Custom JS.
 */

(function ($, Drupal) {
  Drupal.behaviors.nasCtStrategies = {
    attach: function (context, settings) {
      //alert('fdgfdf');
      var app = angular.module('nasCtStrategies', ['ui.bootstrap'])
        .config(['$locationProvider', function($locationProvider) {
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
          strategy.content = [];
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


        $scope.getContent = function(index) {
          //alert('ffefergrefwefwe');
          /* see if we have data already */
          $location.path(settings.nasConservationTracker.basePath + '/' + $scope.tabs[index].link);
          if (!$scope.tabs[index].isLoaded) {
            /* or make request for data delayed to show Loading... */
            $timeout(function () {

              //$http.get(jsonFile).then(function(res){
              $scope.tabs[index].content = 'content of' + index;
              console.log($scope.tabs[index]);
              $scope.tabs[index].isLoaded = true;
              //});

            }, 100);
          }
        }
      };


      app.controller('tabs', tabs);
    }
  };
})(jQuery, window.Drupal);