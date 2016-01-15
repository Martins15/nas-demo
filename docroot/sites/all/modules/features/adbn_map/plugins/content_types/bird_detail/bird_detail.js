(function ($) {

  Drupal.behaviors.adbnMapBirdDetail = {
    attach: function (context, settings) {

      var birdPageView;

      $('body').once('adbnMapBirdDetail', function(){

        // Check that required settings for Drupal have been sent.
        if (
          !settings.adbnMap.birdId
          || !settings.adbnMap.ajaxPath
          || !settings.adbnMap.area
          || !settings.adbnMap.birdDetailPath
          || !settings.adbnMap.imagesPath
          || !settings.adbnMap.birdShareMenu
        ) {
          return;
        }

        var birdId = settings.adbnMap.birdId;
        var ajaxPath = settings.adbnMap.ajaxPath;
        var area = settings.adbnMap.area;
        var basePath = settings.basePath;
        var birdDetailPath = basePath + settings.adbnMap.birdDetailPath;
        var imagesPath = settings.adbnMap.imagesPath;
        var birdShareMenu = settings.adbnMap.birdShareMenu;

        birdPageView = new STMN.audubonClimateModel.BirdPageView(
          {
            SPECIES_CODE : birdId,
            paths : {
              data   : basePath + ajaxPath + '/data',
              giphy  : basePath + ajaxPath + '/giphy',
              states : basePath + ajaxPath + '/states/' + area + '/{countryCode}/{audubonId}'
            },
            animation : {
              slideDuration : 500,
              lastSlidePause : 1000
            },
            selectors : {
              animation : '.focal-bird-map',
              nonGeoViz : '.venn-container',
              shareMenu : '.bird-share-menu',
              searchBox : '.microsite-bird-search'
            },
            templates        : {
              title          : '{PRIMARY_COM_NAME}',
              animationImage : 'http://cdn.climate.audubon.org/maps/{SPECIES_CODE}_{year}_{size}.png',
              nonGeoViz      : 'non-geo viz for {PRIMARY_COM_NAME}',
              animationControlStepButton      : '<button class="action-step" data-step="{step}">{label}</button>',
              animationControlPlayPauseButton : '<button class="action-play-pause">ll</button>',
              animationControlZoomButton      : '<button class="action-zoom">Zoom</button>',
              shareMenu      : birdShareMenu,
              listItem       : '<li><a href="' + birdDetailPath + '/#{id}" data-listtype="{listtype}">{name}</a><br><i>{description}</i></li>'
            },
            lists : [
              {
                listId : 'mostendangered',
                selector : '#mostendangered',
                stateFilter : 'USA:CAL',
                columnFilter : [{'AUDUBON_CLIMATE_SENSITIVITY':'THREATENED_1'}],
                limit : 6,
                template : '<li id="birdlist{SPECIES_CODE}"><a href="' + birdDetailPath + '/{SPECIES_CODE}">{PRIMARY_COM_NAME}</a><br><i>{SCI_NAME}</i></li>'
              }
            ],
            filterTo : ['ENDANGERED','ENDANGERED_1','ENDANGERED_2','THREATENED','THREATENED_1','THREATENED_2']
          },
          function(err, view) {
            // What happens when somebody clicks on a search option
            view.on('search:selected', function(e) {
              $('.audubon-climate-model input[type=search]').attr('value');
              location.href = '' + birdDetailPath + '/' + e.caller[0]['SPECIES_CODE'];
            });
          }
        );

        Drupal.adbnMap.birdPageView = birdPageView;
      });

      // Mule zoom and map dragging functionality.
      var dragging = false,
        dragStartX = 0,
        dragStartY = 0,
        posX = 0,
        posY = 0;

      $(".map-zoom").bind("click", function() {
        $(this).toggleClass("active");
        $(".map-canvas").toggleClass("zoom").removeAttr("style");
        $(".map-elements, .map-header").toggleClass("black-bg");

        dragStartX = 0;
        dragStartY = 0;
        posX = ($(window).width() - $(".map-image").width())/2;
        posY = -800;

        var $focal_bird_map = $(".focal-bird-map");

        if(JQ2(".map-canvas").hasClass("zoom")) {
          birdPageView.changeMapAnimation("full");
          JQ2(".map-canvas").css({"left": posX, "top": posY});

          // Map dragging!
          $focal_bird_map.bind("mousedown", function(e) {
            var $target = JQ2(e.target);

            if($target.hasClass("container") || $target.hasClass("map-canvas")) {
              if($(".map-canvas").hasClass("zoom")) {
                dragging = true;
                dragStartX = e.clientX;
                dragStartY = e.clientY;
              }
              else {
                return false;
              }
            }
            else {
              return false;
            }
          });

          $focal_bird_map.bind("mousemove", function(e) {
            if(dragging == false) {
              return false;
            }

            var deltaX = e.clientX - dragStartX,
              deltaY = e.clientY - dragStartY;


            dragStartX = e.clientX;
            dragStartY = e.clientY;

            posX = posX + deltaX;
            posY = posY + deltaY;

            $(".map-canvas").css({"left": posX, "top": posY});

          });

          $focal_bird_map.bind("mouseup", function(e) {
            if(dragging == false) {
              return false;
            }

            dragging = false;
          });

          // Now with touch
          $focal_bird_map.bind("touchstart", function(e) {
            var $target = JQ2(e.target);

            if (e.originalEvent.touches) {
              e = e.originalEvent.touches[0];
            }

            if($target.hasClass("container") || $target.hasClass("map-canvas")) {
              if($(".map-canvas").hasClass("zoom")) {
                dragging = true;
                dragStartX = e.clientX;
                dragStartY = e.clientY;
              }
            }
          });

          $focal_bird_map.bind("touchmove", function(e) {
            if(dragging == false) { return; }
            if (e.originalEvent.touches) {
              e = e.originalEvent.touches[0];
            }

            var deltaX = e.clientX - dragStartX,
              deltaY = e.clientY - dragStartY;


            dragStartX = e.clientX;
            dragStartY = e.clientY;

            posX = posX + deltaX;
            posY = posY + deltaY;

            $(".map-canvas").css({"left": posX, "top": posY});


            return false;
          });

          $focal_bird_map.bind("touchend", function(e) {
            var $target = JQ2(e.target);

            if(!$target.hasClass("container") || !$target.hasClass("map-canvas")) {
            }
            else if(dragging == false) {
              return false;
            }

            dragging = false;
          });
        }
        else {
          birdPageView.changeMapAnimation(JQ2(window).width());
          $focal_bird_map.unbind("mousedown mousemove mouseup touchstart touchmove touchend");
        }
      });

      var zoom = document.documentElement.clientWidth / window.innerWidth;
    }
  }

})(jQuery);
