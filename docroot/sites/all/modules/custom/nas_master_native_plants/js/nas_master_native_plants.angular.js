(function ($) {

  Drupal.behaviors.nas_master_native_plants_angular = {};
  Drupal.behaviors.nas_master_native_plants_angular.attach = function(context, settings) {
    if ($('body').hasClass('nas-master-native-plants-angular-processed')) {
      return;
    }
    $('body').addClass('nas-master-native-plants-angular-processed');

    // Create base tag for Angular routing.
    $('head').append('<base href="' + settings.basePath + '">');

    var animation_duration = 500, scroll_duration = 500;
    var defaultStateParams = {
      active_tab: 'best_results',
      attribute: '',
      attribute_tier1: '',
      resource: '',
      resource_tier1: '',
      bird_type: '',
      bird_type_tier1: '',
      page: '1',
      page_tier1: '1',
      orderBy: 'CommonName',
      orderBy_tier1: 'CommonName',
      text_search: '',
      text_search_tier1: ''
    };
    var NativePlantsApp = angular.module('NativePlants', ['ngCookies', 'ngSanitize', 'ngAnimate', 'ui.router', 'ngStorage', 'duScroll']);

    NativePlantsApp.config(function($locationProvider, $stateProvider) {
      $locationProvider.html5Mode({
        enabled: true,
        rewriteLinks: false
      });

      var state = {
        name: 'main',
        url: '/native-plants/search?zipcode&active_tab&attribute&attribute_tier1&resource&resource_tier1&bird_type&bird_type_tier1&page&page_tier1',
        params: defaultStateParams,
        onEnter: function(storage, $stateParams) {
          var filters = [
            {key1: 'attribute', key2: 'native_plant_attributes'},
            {key1: 'attribute_tier1', key2: 'native_plant_attributes'},
            {key1: 'resource', key2: 'native_plant_resources'},
            {key1: 'resource_tier1', key2: 'native_plant_resources'},
            {key1: 'bird_type', key2: 'native_plant_bird_types'},
            {key1: 'bird_type_tier1', key2: 'native_plant_bird_types'}
          ];
          angular.forEach(filters, function(value) {
            storage[value.key1] = [];
            if (!$stateParams[value.key1]) {
              return;
            }
            var values = $stateParams[value.key1].split(',');
            angular.forEach(values, function(value2) {
              storage[value.key1].push(storage.data.terms[value.key2][value2]);
            });
          });
        },
        resolve: {
          data: function(storage, $stateParams) {
            storage.data_loaded = false;
            storage.stateParams = $stateParams;
            return storage.getData($stateParams.zipcode).then(function (data) {
              storage.data = data;
              storage.activateTab();
              storage.data_loaded = true;
              storage.closeMobileSearchForm();
            });
          }
        }
      };

      $stateProvider.state(state);
    });

    // Service to communicate with backend.
    NativePlantsApp.factory('courier', function($http, $q) {
      function getData(zipcode) {
        var deferred = $q.defer();
        if (typeof zipcode === 'undefined') {
          deferred.resolve(null);
        }
        else {
          $http.get(settings.basePath + settings.nas_master_native_plants.callback + zipcode).then(function(response) {
            if ($.isEmptyObject(response.data)) {
              deferred.resolve(null);
              return;
            }

            deferred.resolve(response.data);
          });
        }

        return deferred.promise;
      }
      return {
        getData: getData
      };
    });

    // Service to hold information shared between controllers.
    NativePlantsApp.service('storage', function ($rootScope, $q, $timeout, $cookies, $filter, $state, $localStorage, courier) {
      var self = this, cache = [];
      self.data_loaded = false;
      self.multiselect_reload = false;
      self.localStorage = $localStorage;
      self.stateParams = defaultStateParams;

      self.activate_tab = true;
      self.activateTab = function () {
        if (!self.activate_tab) {
          self.activate_tab = true;
          return;
        }

        var $tabs = $('.js-native-plants-tabs');
        var tabRef = null;
        switch (self.stateParams.active_tab) {
          case 'best_results':
            tabRef = 0;
            break;
          case 'full_results':
            tabRef = 1;
            break;
          case 'local_resources':
            tabRef = 2;
            break;
          case 'next_steps':
            tabRef = 3;
            break;
        }
        $tabs.responsiveTabs('activate', tabRef);
      };

      self.closeMobileSearchForm = function() {
        $timeout(function() {
          var $icon = angular.element('.native-plants-search-icon.close');
          if ($icon.is(':visible')) {
            $icon.triggerHandler('click');
          }
        });
      }

      // Run JS things when digest cycle has finished.
      // It is better to implement this Angular way in the future.
      var hasRegistered = false;
      $rootScope.$watch(function() {
        if (hasRegistered) return;
        hasRegistered = true;
        $rootScope.$$postDigest(function() {
          hasRegistered = false;
          Drupal.behaviors.npClearingFix.attached();
          Drupal.behaviors.npOwl.attached();
          if (self.multiselect_reload) {
            self.multiselect_reload = false;
            $('.search-select').multiselect('reload');
          }
        });
      });

      self.getData = function(zipcode) {
        if (typeof cache[zipcode] != 'undefined') {
          var deferred = $q.defer();
          deferred.resolve(cache[zipcode]);
          return deferred.promise;
        }
        return courier.getData(zipcode).then(function (data) {
          cache[zipcode] = data;
          return data;
        });
      };

      // Watch data received from server to recalculate results and pagers.
      $rootScope.$watch(
        function() {
          return self.data;
        },
        function(newVal, oldVal) {
          if (!angular.isObject(newVal)) {
            return;
          }
          self.calculateResults(0);
          self.calculateResultsTier1(0);
        });
      // Watch combined filter values and recalculate results.
      $rootScope.$watch(
        function() {
          return self.stateParams.attribute + self.stateParams.resource + self.stateParams.bird_type + self.stateParams.text_search;
        },
        function (newVal, oldVal) {
          if (!angular.isObject(self.data)) {
            return;
          }
          self.filtering_in_progress = true;
          self.calculateResults(animation_duration).then(function () {
            self.filtering_in_progress = false;
          });
        });
      $rootScope.$watch(
        function() {
          return self.stateParams.attribute_tier1 + self.stateParams.resource_tier1 + self.stateParams.bird_type_tier1 + self.stateParams.text_search_tier1;
        },
        function (newVal, oldVal) {
          if (!angular.isObject(self.data)) {
            return;
          }
          self.filtering_in_progress_tier1 = true;
          self.calculateResultsTier1(animation_duration).then(function () {
            self.filtering_in_progress_tier1 = false;
          });
        });

      self.calculateResults = function (timeout) {
        self.hide_results = true;
        return $timeout(function () {
          if (typeof self.data == 'undefined') {
            return;
          }
          self.results = $filter('filter')(self.data.plants, function (value, index, array) {
            var filters = [
              {key1: 'attribute', key2: 'Attributes'},
              {key1: 'resource', key2: 'Resources'},
              {key1: 'bird_type', key2: 'BirdTypes'}
            ];
            for (var i = 0; i < 3; i++) {
              if (self[filters[i].key1].length) {
                var exclude = true;
                angular.forEach(self[filters[i].key1], function (val) {
                  if (value[filters[i].key2].indexOf(val.tid) != -1) {
                    exclude = false;
                  }
                });

                if (exclude) {
                  return false;
                }
              }
            }

            return true;
          });
          self.results_filtered = $filter('filter')(self.results, self.stateParams.text_search);
          self.hide_results = false;
        }, timeout);
      };
      self.calculateResultsTier1 = function (timeout) {
        self.hide_results_tier1 = true;
        return $timeout(function () {
          if (typeof self.data == 'undefined') {
            return;
          }
          self.results_tier1 = $filter('filter')(self.data.plants, function (value, index, array) {
            if (value.Tier1 === false) {
              return false;
            }

            var filters = [
              {key1: 'attribute_tier1', key2: 'Attributes'},
              {key1: 'resource_tier1', key2: 'Resources'},
              {key1: 'bird_type_tier1', key2: 'BirdTypes'}
            ];
            for (var i = 0; i < 3; i++) {
              if (self[filters[i].key1].length) {
                var exclude = true;
                angular.forEach(self[filters[i].key1], function (val) {
                  if (value[filters[i].key2].indexOf(val.tid) != -1) {
                    exclude = false;
                  }
                });

                if (exclude) {
                  return false;
                }
              }
            }

            return true;
          });
          self.results_tier1_filtered = $filter('filter')(self.results_tier1, self.stateParams.text_search_tier1);
          self.hide_results_tier1 = false;
        }, timeout);
      };

      // Pager params.
      self.pager = {
        items_per_page: 10,
        quantity: 8,
        current_page_param: 'page'
      };
      self.pager_tier1 = {
        items_per_page: 10,
        quantity: 8,
        current_page_param: 'page_tier1'
      };
      // Watch current page state parameter and calculate pager items.
      $rootScope.$watch(
        function() {
          return self.stateParams.page;
        },
        function(newVal, oldVal) {
          if (typeof self.results_filtered == 'undefined') {
            return;
          }
          self.calculatePagerItems(self.results_filtered.length, 'pager');
        });
      $rootScope.$watch(
        function() {
          return self.stateParams.page_tier1;
        },
        function(newVal, oldVal) {
          if (typeof self.results_tier1_filtered == 'undefined') {
            return;
          }
          self.calculatePagerItems(self.results_tier1_filtered.length, 'pager_tier1');
        });
      // Watch filtered results arrays and calculate pager items.
      $rootScope.$watch(
        function() {
          if (angular.isUndefined(self.results_filtered)) {
            return null;
          }
          return self.results_filtered.length;
        },
        function(newVal, oldVal) {
          self.calculatePagerItems(newVal, 'pager');
        });
      $rootScope.$watch(
        function() {
          if (angular.isUndefined(self.results_tier1_filtered)) {
            return null;
          }
          return self.results_tier1_filtered.length;
        },
        function(newVal, oldVal) {
          self.calculatePagerItems(newVal, 'pager_tier1');
        });

      self.calculatePagerItems = function (count, pager) {
        if (count === null) {
          return;
        }
        var quantity = self[pager].quantity,
          pager_middle = Math.ceil(quantity / 2),
          pager_current = parseInt(self.stateParams[self[pager].current_page_param]),
          pager_first = pager_current - pager_middle,
          pager_last = pager_current + quantity - pager_middle,
          pager_max = Math.ceil(count / self[pager].items_per_page);

        var i = pager_first;
        if (pager_last > pager_max) {
          i = i + (pager_max - pager_last);
          pager_last = pager_max;
        }
        if (i <= 0) {
          pager_last = pager_last - i;
          i = 1;
        }

        self[pager].pager_items = {
          previous: {page: 0},
          first: {page: 0, link: false},
          separator_left: false,
          items_before: [],
          current: {page: pager_current, link: false},
          items_after: [],
          separator_right: false,
          last: {page: 0, link: false},
          next: {page: 0}
        };
        // Previous page.
        if (pager_current > 1) {
          self[pager].pager_items.previous = {page: pager_current - 1, link: true};
        }
        else {
          self[pager].pager_items.previous = {page: pager_current - 1, link: false};
        }
        // First page.
        if (i > 1) {
          self[pager].pager_items.first = {page: 1, link: true};
        }

        // When there is more than one page, create the pager list.
        if (i != pager_max) {
          if (i > 2) {
            self[pager].pager_items.separator_left = true;
          }
          // Now generate the actual pager piece.
          for (; i <= pager_last && i <= pager_max; i++) {
            if (i < pager_current) {
              self[pager].pager_items.items_before.push({page: i, link: true});
            }
            if (i > pager_current) {
              self[pager].pager_items.items_after.push({page: i, link: true});
            }
          }
          if (i < pager_max) {
            self[pager].pager_items.separator_right = true;
          }
          i--;
        }

        // Last page.
        if (i < pager_max) {
          self[pager].pager_items.last = {page: pager_max, link: true};
        }
        // Next page.
        if (pager_current < pager_max) {
          self[pager].pager_items.next = {page: pager_current + 1, link: true};
        }
        else {
          self[pager].pager_items.next = {page: pager_current + 1, link: false};
        }
      };

      self.setStateParam = function(param, value, page) {
        self.stateParams[param] = value;
        if (page) {
          self.stateParams[page] = 1;
        }
        $state.go('main', self.stateParams, {reload: true});
      };
      self.setZipcode = function () {
        if (defaultStateParams.zipcode === self.stateParams.zipcode) {
          return;
        }
        defaultStateParams.zipcode = self.stateParams.zipcode;
        self.clearFilters();
      };

      // Clear all the filters.
      self.clearFilters = function() {
        self.activate_tab = false;
        self.multiselect_reload = true;
        defaultStateParams.active_tab = self.stateParams.active_tab;
        $state.go('main', defaultStateParams, {reload: true});
      };

      // Plants cart functions.
      self.updateCart = function (plant) {
        if (!self.localStorage.cart[plant.PlantID].selected) {
          delete self.localStorage.cart[plant.PlantID];
          return;
        }

        self.localStorage.cart[plant.PlantID] = {
          selected: true,
          CommonName: plant.CommonName,
          ScientificName: plant.ScientificName,
          BirdTypes: plant.BirdTypes
        };
      };
      self.clearCart = function () {
        delete self.localStorage.cart;
      };
      self.selectAllTier1 = function () {
        angular.forEach(self.results_tier1_filtered, function(plant) {
          if (angular.isUndefined(self.localStorage.cart)) {
            self.localStorage.cart = {};
          }
          self.localStorage.cart[plant.PlantID] = {
            selected: true,
            CommonName: plant.CommonName,
            ScientificName: plant.ScientificName,
            BirdTypes: plant.BirdTypes
          };
        });
      };

      // Watch cart changes.
      $rootScope.$watch(
        function() {
          if (angular.isUndefined(self.localStorage.cart)) {
            return 0;
          }
          return $.map(self.localStorage.cart, function(n, i) { return i; }).length;
        },
        function(newVal, oldVal) {
          $('.native-plants-get-list-form').find('[name="native_plants_cart"]')
            .val(angular.toJson(self.localStorage.cart));
        });

    });

    NativePlantsApp.filter('trusted', ['$sce', function($sce){
      return function(text) {
        return $sce.trustAsHtml(text);
      };
    }]);

    NativePlantsApp.directive('nativePlantsMultiselect', function ($timeout, storage) {
      return {
        priority: 0,
        restrict: 'A',
        link: function (scope, element, attrs) {
          scope.$watch(function () {
            if (angular.isUndefined(storage.data)) {
              return null;
            }
            return storage.data.terms;
          }, function (newVal, oldVal) {
            if (!newVal) {
              return;
            }

            scope.$evalAsync(function() {
              var $element = $(element);
              if ($element.hasClass('native-plants-multiselect-processed')) {
                $element.multiselect('reload');
              }
              else {
                $element.addClass('native-plants-multiselect-processed');
                $element.multiselect({
                  placeholder: $element.data('placeholder')
                });
              }
            });
          });
        }
      };
    });

    NativePlantsApp.controller('NativePlantsController', function (storage) {
      var self = this;
      self.storage = storage;
    });

    NativePlantsApp.controller('NativePlantsTabsController', function ($sce, storage) {
      var self = this;
      self.storage = storage;

      self.activateTab = function (tab) {
        self.storage.activate_tab = false;
        self.storage.setStateParam('active_tab', tab);
      };

      self.tabResults = function (count) {
        if (angular.isUndefined(count)) {
          return '';
        }
        return $sce.trustAsHtml(Drupal.formatPlural(
          count,
          '<span class="quantity">1</span> <span class="text">plant</span>',
          '<span class="quantity">@count</span> <span class="text">plants</span>'
        ));
      };

      self.filterSearchProgressCheck = function (tier) {
        return (self.storage['filtering_in_progress' + tier]) ? 'form-filter--load' : '';
      }

    });

    NativePlantsApp.controller('NativePlantsZipcodeSearchController', function (storage) {
      var self = this;
      self.storage = storage;
    });

    NativePlantsApp.controller('NativePlantsResultsController', function ($sce, $document, $timeout, storage) {
      var self = this;
      self.storage = storage;

      self.setFilter = function (param, selected, page) {
        var values = [];
        angular.forEach(selected, function(value, key) {
          values.push(value.tid);
        });
        self.storage.activate_tab = false;
        self.storage.setStateParam(param, values.join(','), page);
      };
      self.setFilterLink = function (param, value, page) {
        var element;
        if (Foundation.utils.is_medium_up()) {
          element = angular.element(document.getElementById('native-plants-tabs-selector'));
        }
        else {
          element = angular.element(document.getElementById('pager-scroll-' + page));
        }
        $document.scrollToElement(element, 0, scroll_duration).then(
          function () {
            self.storage.activate_tab = false;
            self.storage.multiselect_reload = true;
            self.storage.setStateParam(param, value, page);
          },
          function () {
            self.storage.activate_tab = false;
            self.storage.multiselect_reload = true;
            self.storage.setStateParam(param, value, page);
          }
        );
      };
      self.setPage = function (page_key, value) {
        var results_key = (page_key == 'page' ? 'results' : 'results_tier1');
        var element = angular.element(document.getElementById('pager-scroll-' + page_key));
        $document.scrollToElement(element, 0, scroll_duration).then(
          function () {
            self.storage['hide_' + results_key] = true;
            $timeout(function () {
              self.storage['hide_' + results_key] = false;
              self.storage.activate_tab = false;
              self.storage.setStateParam(page_key, value);
            }, animation_duration);
          },
          function () {
            self.storage['hide_' + results_key] = true;
            $timeout(function () {
              self.storage['hide_' + results_key] = false;
              self.storage.activate_tab = false;
              self.storage.setStateParam(page_key, value);
            }, animation_duration);
          }
        );
      };

      self.orderByChange = function (results_key) {
        self.storage['hide_' + results_key] = true;
        if (angular.isObject(self.promise)) {
          $timeout.cancel(self.promise);
        }
        self.promise = $timeout(function () {
          self.storage['hide_' + results_key] = false;
        }, animation_duration);
      };

      self.plantDescriptionClass = function (plant) {
        var classes = [];
        if (plant.PlantImgDesktop) {
          classes.push('medium-8');
        }
        else {
          classes.push('medium-12');
        }
        return classes.join(' ');
      };

      self.pagerResults = function (count) {
        if (angular.isUndefined(count)) {
          return '';
        }
        return $sce.trustAsHtml(Drupal.formatPlural(
          count,
          '<strong>Results:</strong> 1 plant',
          '<strong>Results:</strong> @count plants'
        ));
      };

      self.textSearchProgressCheck = function (tier) {
        return (self.storage['filtering_in_progress' + tier]) ? 'form-filter--load' : '';
      };

      self.animationClass = function (results_key) {
        return (self.storage['hide_' + results_key]) ? 'hide-results' : '';
      };
    });

    NativePlantsApp.controller('NativePlantsCartController', function ($sce, storage) {
      var self = this;
      self.storage = storage;

      self.cartShow = function () {
        return (self.storage.localStorage.cart && !angular.equals({}, self.storage.localStorage.cart));
      };
      self.plantsCounter = function () {
        if (!self.cartShow()) {
          return $sce.trustAsHtml(Drupal.t('No plants selected'));
        }

        var count = $.map(self.storage.localStorage.cart, function(n, i) { return i; }).length;
        return $sce.trustAsHtml(Drupal.formatPlural(count, '1 plant', '@count plants'));
      };
      self.plantsList = function () {
        var plants_string = '', limit = false;
        angular.forEach(self.storage.localStorage.cart, function(plant, plant_id) {
          if (plants_string.length < 60) {
            plants_string += (plants_string ? ', ' + plant.CommonName : plant.CommonName);
          }
          else if (!limit) {
            limit = true;
            plants_string += '...';
          }
        });
        return plants_string;
      };
    });

    NativePlantsApp.controller('NativePlantsNurseriesController', function ($scope, $attrs, storage) {
      var self = this;
      self.storage = storage;
      self.rowsLimit = 3;
      self.status = $attrs.online;

      $scope.$watch(function() {
        return self.storage.data.nurseries;
      }, function(newVal, oldVal) {
        self.rows = [];
        if (typeof newVal == 'undefined') {
          return;
        }

        self.nurseries = self.storage.data.nurseries[self.status];
        var row = [];
        for ($i = 0; $i < Math.ceil(self.nurseries.length / 3); $i++) {
          for ($j = 0; $j < 3 && ($i * 3 + $j < self.nurseries.length); $j++) {
            row.push(self.nurseries[$i * 3 + $j]);
          }
          self.rows.push(row);
          row = [];
        }
      });

      self.limitToggle = function () {
        self.rowsLimit = self.rowsLimit ? null : 3;
      };
    });

    NativePlantsApp.controller('NativePlantsAdditionalResourcesController', function ($scope, $attrs, storage) {
      var self = this;
      self.storage = storage;
      self.rowsLimit = 1;

      $scope.$watch(function () {
        return self.storage.data.additional_resource;
      }, function (newVal, oldVal) {
        self.rows = [];
        if (typeof newVal == 'undefined') {
          return;
        }
        self.additional_resource = self.storage.data.additional_resource;
        var row = [];
        for ($i = 0; $i < Math.ceil(self.additional_resource.length / 2); $i++) {
          for ($j = 0; $j < 2 && ($i * 2 + $j < self.additional_resource.length); $j++) {
            row.push(self.additional_resource[$i * 2 + $j]);
          }
          self.rows.push(row);
          row = [];
        }
      });

      self.limitToggle = function () {
        self.rowsLimit = self.rowsLimit ? null : 1;
      };
    });

    NativePlantsApp.controller('NativePlantsResourcesController', function (storage) {
      var self = this;
      self.storage = storage;

      self.iconMap = '<i class="icon-map"></i>';

      self.activateLocalResources = function () {
        self.storage.activate_tab = true;
        self.storage.setStateParam('active_tab', 'local_resources');
      };
    });

    // Bootstrap AngularJS application.
    angular.bootstrap(document.getElementsByTagName('body')[0], ['NativePlants']);
  };

})(jQuery);
