(function ($) {
  Drupal.behaviors.cta_tabs_angular = {};
  Drupal.behaviors.cta_tabs_angular.attach = function (context, settings) {

    if ($('body').hasClass('nas-cta-tabs-angular-processed')) {
      return;
    }
    $('body').addClass('nas-cta-tabs-angular-processed');

    // @todo load from backend
    var linkArray = ['threats', 'actions', 'response', 'partners']
      , pathName = window.location.pathname
      , pathArray = window.location.pathname.split('/')
      , lastName = pathArray.slice(-1)[0]
      , activeUrl = '';

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
    ]).directive('tabsRepeatDirective', function () {
      return function ($scope, element, attrs) {
        if ($scope.$last) {

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

      linkArray.forEach(function (item) {
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

    NativeCtaApp.controller('Content', [
      '$scope', '$stateParams', '$state', '$rootScope', '$http',
      function ($scope, $stateParams, $state, $rootScope, $http) {
        // @todo update var.
        var idItem = Drupal.settings.nasConservationTracker.scorecardId;
        $scope.tabLoaded = function () {
          if (Drupal.settings.nasConservationTracker.currentTab == 'response') {
            $('.trigger').show();
          }
          else {
            $('.trigger').hide();
          }

          if (Drupal.settings.nasConservationTracker.currentTab == 'partners') {
            $('.no-data-overlay').remove();
            $('.leaflet-container').hide();
            $('#nas-conservation-tracker-map-form').hide();
            $('.partners-wrap:not(.ng-hide)').prependTo('.wrap-map-diagram');
          }
          else {
            $('.leaflet-container').show();
            $('#nas-conservation-tracker-map-form').show();
          }
          setTimeout(function () {
            Drupal.attachBehaviors($('.' + Drupal.settings.nasConservationTracker.currentTab + '-tab-wrapper'));
            // Fix for conflict with GTM, where event handler was executed
            // earlier then colorbox.
            $('.video-wrap a').click(function (e) {
              if ($(e.currentTarget).hasClass('colorbox-load')) {
                e.preventDefault();
              }
            });
            if (Drupal.curtain) {
              Drupal.curtain.reset();
              Drupal.curtain.setup();
            }
          }, 500);

        }

        $scope.downloadPdf = function() {
          $('body').append('<div id="pdf-render-container"></div>');
          $scope.pdfLoading = true;

          var doc = new jsPDF();
          var lMap = Drupal.settings.leaflet['0'].lMap;
          leafletImage(lMap, function(err, canvas) {
            Drupal.settings.nasConservationTracker.leafletImage = canvas.toDataURL();
          });
          var dimensions = lMap.getSize();
          var imgRatio = dimensions.x / dimensions.y;
          var w = 210;
          var h = parseInt((w / imgRatio).toFixed());
          var overview = document.querySelector("#scorecard-overview");
          var w2 = 195;
          var h2 = parseInt((w2 / overview.offsetWidth * overview.offsetHeight).toFixed());
          var offset = 20;
          var offset1 = h2 + 60;
          var size2 = calcSize('#charts-actions');
          var offset3 = size2.y + 20;
          var size3 = calcSize('#charts-objectives');
          var size4 = calcSize('#scorecard-footnotes');
          var offset4 = size3.y + offset3 + 20;

          doc.setFontSize(18);
          doc.setTextColor(38,38,38);
          doc.text(12, offset, $scope.tab.name);
          offset += 10;
          doc.setFontSize(12);
          if ($scope.tab.subtitle) {
            doc.text(12, 30, $scope.tab.subtitle);
            offset += 10;
          }
          doc.text(12, offset, $scope.isActive);

          html2canvas(document.querySelector("#scorecard-overview")).then(canvas => {
            doc.addImage(canvas.toDataURL(), 'PNG', 10, 50, w2, h2);
          });

          setTimeout(function() {
            var overviewHref = $scope.tab.settings[$scope.isActive].preparedLink.href;
            if (typeof(overviewHref) == 'string') {
              var ext = ['jpeg', 'jpg', 'gif', 'png'];
              for (var e in ext) {
                if (overviewHref.indexOf('.' + ext[e]) > 0) {
                  var imgOverview = new Image;
                  imgOverview.onload = function () {
                    doc.addImage(this, 'PNG', 0, offset1, w, h);
                    doc.addPage();
                    offset1 = 0;
                  };
                  imgOverview.crossOrigin = '';
                  imgOverview.src = overviewHref;
                  break;
                }
              }
            }
          }, 5000);

          setTimeout(function() {
            doc.addImage(Drupal.settings.nasConservationTracker.leafletImage, 'PNG', 0, offset1, w, h);
          }, 9000);

          setTimeout(function() {
            html2canvas(document.querySelector("#charts-actions")).then(canvas => {
              doc.addPage();
              doc.addImage(canvas.toDataURL(), 'PNG', 5, 10, size2.x, size2.y);
            });
          }, 12000);

          setTimeout(function() {
            html2canvas(document.querySelector("#charts-objectives")).then(canvas => {
              doc.addImage(canvas.toDataURL(), 'PNG', 5, offset3, size3.x, size3.y);
            });
          }, 17000);

          setTimeout(function() {
            if ($scope.tab.settings[$scope.isActive].footnotes) {
              html2canvas(document.querySelector("#scorecard-footnotes")).then(canvas => {
                doc.addImage(canvas.toDataURL(), 'PNG', 15, offset4, size4.x, size4.y);
              });
            }
          }, 19000);

          setTimeout(function() {
            $scope.pdfLoading = false;
            doc.save($scope.tab.name + '.pdf');
            $scope.$apply();
          }, 25000);

          function calcSize(selector) {
            var e = 0.264583;
            var element = document.querySelector(selector);
            return {
              x: parseInt((element.offsetWidth * e).toFixed()),
              y: parseInt((element.offsetHeight * e).toFixed())
            }
          }
        }

        // Load json file.
        function getContent(currentName) {
          if (linkArray.indexOf(currentName) > -1) {
            Drupal.settings.nasConservationTracker.tabsOverview = Drupal.settings.nasConservationTracker.tabsOverview || {};
            Drupal.settings.nasConservationTracker.tabsData = Drupal.settings.nasConservationTracker.tabsData || {};
            // Load data via ajax only once.
            if (!angular.isDefined(Drupal.settings.nasConservationTracker.tabsOverview[currentName])) {
              // @todo take from backend
              $scope.startLoad = true;
              $http.get('/conservation-tracker/ajax/scorecard/' + idItem + '/' + currentName)
                .then(function (response) {
                  var tabData = response.data.data;
                  tabData.settings.overview = tabData.settings[currentName];
                  tabData.settings.overview.preparedLink = {'target': '_self'};

                  if (angular.isDefined(tabData.settings.overview.image)) {
                    tabData.settings.overview.preparedLink.class = 'colorbox-load';
                    var sign = '?';
                    if (tabData.settings.overview.image.indexOf('?') > -1) {
                      sign = '&';
                    }
                    tabData.settings.overview.preparedLink.href = tabData.settings.overview.image + sign + 'iframe=false';
                  }
                  else {
                    if (angular.isDefined(tabData.settings.overview.iframe)) {
                      tabData.settings.overview.preparedLink.class = 'colorbox-load';
                      var width = $(window).width() * 0.75;
                      var height = $(window).height() * 0.9;
                      var sign = '?';
                      if (tabData.settings.overview.iframe.indexOf('?') > -1) {
                        sign = '&';
                      }
                      tabData.settings.overview.preparedLink.href = tabData.settings.overview.iframe + sign + 'width=' + width + '&height=' + height + '&iframe=true';
                    }
                    else {
                      if (angular.isDefined(tabData.settings.overview.link)) {
                        tabData.settings.overview.preparedLink.class = 'overview-link';
                        tabData.settings.overview.preparedLink.href = tabData.settings.overview.link;
                        tabData.settings.overview.preparedLink.target = '_blank';
                      }
                      else {
                        if (angular.isDefined(tabData.settings.overview.youtube)) {
                          var width = $(window).width() * 0.75;
                          var height = $(window).height() * 0.9;
                          var regExp = /^.*((youtu.be\/)|(v\/)|(\/u\/\w\/)|(embed\/)|(watch\?))\??v?=?([^#\&\?]*).*/;
                          var match = tabData.settings.overview.youtube.match(regExp);
                          var yid = (match && match[7].length == 11) ? match[7] : false;
                          if (yid) {
                            var youtube = '//www.youtube.com/embed/' + yid;
                            tabData.settings.overview.preparedLink.class = 'colorbox-load youtube';
                            var sign = '?';
                            if (youtube.indexOf('?') > -1) {
                              sign = '&';
                            }
                            tabData.settings.overview.preparedLink.href = youtube + sign + 'iframe=true&width=' + width + '&height=' + height;
                          }
                        }
                      }
                    }
                  }

                  $('.video-wrap a').attr('class', tabData.settings.overview.preparedLink.class).unbind('click');

                  // Add partners array to scope.
                  // If partners tabs.
                  if (currentName === 'partners') {
                    tabData.settings.overview.partners = tabData.partners;
                  }

                  tabData.settings.tabs = linkArray;
                  Drupal.settings.nasConservationTracker.tabsOverview[currentName] = tabData;
                  Drupal.settings.nasConservationTracker.tabsData[currentName] = response.data.data;
                  $scope['tab'] = tabData;
                  updateTabData(response.data.data);
                }).finally(function () {
                $scope.startLoad = false;
              });
            }
            else {
              $scope['tab'] = Drupal.settings.nasConservationTracker.tabsOverview[currentName];
              updateTabData(Drupal.settings.nasConservationTracker.tabsData[currentName]);
            }

          }
        }

        function updateTabData(data) {
          if (angular.isDefined(data)) {
            Drupal.settings.nasConservationTracker.jsonData = data;
            Drupal.nasCtInitMap();
            Drupal.nasCtInitCharts();
          }
        }


        // On load.
        $rootScope.$on('$stateChangeSuccess', function (event, transition) {
          Drupal.settings.nasConservationTracker.currentTab = $state['current']['name'];
          getContent($state['current']['name']);
          $scope.isActive = transition.name;
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

