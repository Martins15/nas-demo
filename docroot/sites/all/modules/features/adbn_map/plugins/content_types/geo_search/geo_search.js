(function ($) {

  Drupal.behaviors.adbnMapGeoSearch = {
    attach: function (context, settings) {

      $('#list-view').once('adbnMapGeoSearch', function(){

        // Check that required settings for Drupal have been sent.
        if (
          !settings.adbnMap.ajaxPath
            || !settings.adbnMap.area
            || !settings.adbnMap.birdDetailPath
            || !settings.adbnMap.descriptions
          ) {
          return;
        }

        var ajaxPath = settings.adbnMap.ajaxPath;
        var area = settings.adbnMap.area;
        var basePath = settings.basePath;
        var birdDetailPath = basePath + settings.adbnMap.birdDetailPath;
        var descriptions = settings.adbnMap.descriptions;

        //
        // Instantiate the view
        //
        var birdPageView = new STMN.audubonClimateModel.BirdPageView(
          {
            defaults : {
              title : Drupal.t('Climate Change & Bird Ranges')
            },
            paths : {
              data   : '/' + ajaxPath + '/data',
              giphy  : '/' + ajaxPath + '/giphy',
              states : '/' + ajaxPath + '/states/' + area + '/{countryCode}/{audubonId}',
              flywayPolygons : '/' + ajaxPath + '/topology'
            },
            selectors : { //Omit items in this object and they will not display on the page.
              flywayNavMap : '#flywaynavmap',
              flywayList   : '#flywaylist',
              searchBox    : '.microsite-bird-search'
            },
            templates : {
              title : '{AOU54_COMMON_NAME}<br><i>{AOU54_SPECIES}</i>',
              animationUrl      : 'http://cdn.climate.audubon.org/maps/animated{BBL_ABBREV}.gif',
              flywayNavMap      : '<img src="{imageUrl}" alt="" usemap="#{name}" width="100%"><map name="{name}">{areas}</map>',
              flywayNavMapArea  : '<area shape="poly" coords="{coords}" data-region="{id}">'
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

          }
        );

        Drupal.adbnMap.birdPageView = birdPageView;

        //
        // Bind to clicks on the flyway nav
        //
        var flywayListConfig = {
          listId : 'flywaylist',
          selector : '#flywaylist tbody',
          stateFilter : 'USA:CAL',
          template : '<tr> <td width="45%"> <a class="bird-list-link" href="' + birdDetailPath + '/{SPECIES_CODE}">{PRIMARY_COM_NAME}</a> <br><small class="scientific-name"><i>{SCI_NAME}</i></small> </td>  <td width="27.5%" style="text-align: center" class="bird-list-percent"><span class="CBCpercent">{percentageLost.BBS}</span></td> <td width="27.5%" style="text-align: center"class="bird-list-percent"><span class="BBSpercent">{percentageLost.CBC}</span></td> </tr>',
          columnFormatter : function(column) {
            column['percentageLost.BBS'] = column['percentageLost.BBS'] > -1 ? (100-parseInt(column['percentageLost.BBS']*100, 10)) + '%' : '';
            column['percentageLost.CBC'] = column['percentageLost.CBC'] > -1 ? (100-parseInt(column['percentageLost.CBC']*100, 10)) + '%' : '';
            return column;
          } //Array.map callback function
        };

        // Make initial sorting order be summer range lost, highest to lowest.
        flywayListConfig.reverseSort = true;
        flywayListConfig.sortColumn = 'percentageLost.BBS';

        // Add the active sort class to the selected sort list button.
        var sortClass = 'active-flyway-sort';
        JQ2('.flyway-list-button[data-sortcolumn="percentageLost.BBS"]').addClass(sortClass);

        function updateFlywayDescription(region) {
          var flywayDescription = descriptions[region];
          JQ2('#stateprovincelist').find('.flyway-description').html(flywayDescription);
        }

        function updateStateDescription(dataStateCode, dataCountryCode) {
          var drupalStateCode = dataCountryCode + '_' + dataStateCode;
          var stateDescription = descriptions[drupalStateCode];
          JQ2('#flywaylist').find('.flyway-list-more').html(stateDescription);
        }

        birdPageView.on('clickFlywayMapRegion', function(e) {
          hideLabels(e.caller.region);

          // A state was clicked on the map.
          if (e.caller.state) {
            popupInit(e.caller.clickEvent.id, e.caller.region, true);
            birdPageView.setFlywayMapUIState('flyway:' + e.caller.region + ',state:' + e.caller.state);

          }
          // A flyway was clicked on the map.
          else {
            // Add dynamic description sent from Drupal, when a region is
            // clicked in the geo search map.
            updateFlywayDescription(e.caller.region);

            // Create a new div in the html, and populate it with the list of states in the flyway.
            JQ2('#stateprovincelist span.flyway-name').text(e.caller.region);

            var states = birdPageView.getFlywayData().values.sort().filter(function(stateItem) {
              return (stateItem[2] === e.caller.region);
            });

            JQ2('#stateprovincelist ul').html(states.map(function(state) {
              return "<li data-country='" + state[1] + "' data-flyway='" + state[2] + "' data-state='" + state[3] + "' id=" + state[0].toLowerCase().replace(/\s/, "-") + ">" + state[0] + "</li>";
            }));

            JQ2("#stateprovincelist li").bind("click", function() {
              var JQ2this = JQ2(this),
                dataStateCode = JQ2this.attr("data-state"),
                dataState = JQ2this.text(),
                dataCountry = JQ2this.attr("data-country"),
                dataStateLong = JQ2this.attr("id"),
                dataFlyway = JQ2this.attr("data-flyway");

              flywayListConfig['stateFilter'] = (dataCountry === 'US' ? 'USA' : 'CAN') + ':' + dataStateCode;
              birdPageView.drawList(flywayListConfig);
              JQ2('#flywaylist span.flyway-name').text(dataState);

              JQ2('#flywaylist').show();

              JQ2('#stateprovincelist').hide();

              birdPageView.setFlywayMapUIState('flyway:' + dataFlyway + ',state:' + dataStateCode);

              // Add dynamic description sent from Drupal, when a state is
              // clicked in the geo search state list.
              updateStateDescription(dataStateCode, dataCountry);

              //Replace link
              urlReplace(dataStateLong);
            });

            JQ2("#stateprovincelist li").hover(function() {
              var theState = JQ2(this).attr("data-state"),
                JQ2statePath = JQ2("#" + theState),
                statePathClass = JQ2statePath.attr("class");

              JQ2statePath.attr("class", statePathClass + " hover");
            }, function() {
              var theState = JQ2(this).attr("data-state"),
                JQ2statePath = JQ2("#" + theState),
                statePathClass = JQ2statePath.attr("class").replace(" hover", "");

              JQ2statePath.attr("class", statePathClass);
            });

            JQ2("#stateprovincelist ul")
              .append("<h5 class='US'>United States</h5>")
              .append("<h5 class='CA'>Canada</h5>");
            JQ2("#stateprovincelist .US").after(JQ2("#stateprovincelist li[data-country='US']"));
            JQ2("#stateprovincelist .CA").after(JQ2("#stateprovincelist li[data-country='CA']"));


            JQ2('#stateprovincelist').show();

            JQ2('#flywaylist').hide();

            birdPageView.setFlywayMapUIState('flyway:' + e.caller.region);

          }

          if(e.caller.region == "Pacific" || e.caller.region == "Central") {
            JQ2("#stateprovincelist, #flywaylist").css({"float": "right"});
          }
          else {
            JQ2("#stateprovincelist, #flywaylist").css({"float": "left"});
          }

          //Wrapp states in two columns
          var states_container = $('.climate-flyway-overlay ul');
          var total_childs = states_container.children().length;
          var delimeter_position = Math.floor(total_childs/2);
          var wrapper = $('<div class="states-col"></div>');

          states_container.children().slice(0, delimeter_position).wrapAll(wrapper);
          states_container.children().slice(1, total_childs).wrapAll(wrapper);

        });

        birdPageView.on('listSelect', function(e) {

          if (e.caller.listConfig.listId === 'flywaylist' || e.caller.listConfig.listId === 'mostendangered') {
            // We don't need to redirect anywhere, because the clicked links
            // themselves have the proper bird code URLs.
            //location.href = birdDetailPath + '/' + e.caller.clickEvent.target.hash;
          }

        });

        JQ2(".climate-flyway-overlay .close").click(function(e) {
          e.preventDefault();
          JQ2(".climate-flyway-overlay").hide();
          JQ2(".flyway-label, .flyway-map-label").show();
          JQ2(".microsite-bird-search-lower").show();
          birdPageView.setFlywayMapUIState(true);
        });

        var listSortEvent = "click";
        if(JQ2("body").hasClass("touch")) {
          listSortEvent = "touchend";
        }

        JQ2('.flyway-list-button').on(listSortEvent, function(e) {
          e.preventDefault();


          // Remove active sort class from all sort links.
          JQ2('.flyway-list-button').removeClass(sortClass);

          // Add the sort class for the clicked link.
          JQ2(this).addClass(sortClass);

          flywayListConfig.reverseSort = (JQ2(this).attr('data-reverse') === "true");
          flywayListConfig.sortColumn = JQ2(this).attr('data-sortcolumn');

          birdPageView.drawList(flywayListConfig);

          JQ2(".flyway-list-button").not(JQ2(this)).attr('data-reverse', 'false');

          if(JQ2(this).attr('data-reverse') == 'false') {
            JQ2(this).attr('data-reverse', 'true');
          }
          else {
            JQ2(this).attr('data-reverse', 'false');
          }
        });

        birdPageView.on('search:selected', function(e) {
          $('.audubon-climate-model input[type=search]').attr('value');
          if (e.caller[0]['SPECIES_CODE']) {
            location.href = birdDetailPath + '/' + e.caller[0]['SPECIES_CODE'];
          }
        });

        // Initializes Backbone router, to listen to URL changes for geo search
        // page.
        function geoSearchDeepLinkHandler() {
          // Prepare the router factory.
          var geoSearchRouter = Backbone.Router.extend({
            routes: {
              ":stateName": "stateDeepHandler"
            },
            stateDeepHandler: function(stateName) {
              //Wait data to be loaded
              Drupal.adbnMap.birdPageView.on('dataUpdate', function () {
                //Get states info object
                var statesList = Drupal.adbnMap.birdPageView.getFlywayData();
                var stateId;
                var stateFlyWay;

                for (var key in statesList.values) {
                  if (statesList.values.hasOwnProperty(key)) {
                    if(statesList.values[key][0].toLowerCase().replace(' ','-') == stateName){
                      stateId = statesList.values[key][4];
                      stateFlyWay = statesList.values[key][2];
                    }
                  }
                }
                //Hide unnecessary labels
                hideLabels(stateFlyWay);
                //Show states popup
                popupInit(stateId, stateFlyWay);
                //Color the active region
                birdPageView.setFlywayMapUIState('flyway:'+stateFlyWay);
              });

            }
          });

          // Instantiate a new object using the factory.
          new geoSearchRouter();

          // Start routing.
          var initial = Backbone.history.start({pushState: true, root: '/geographical-search'});
        }

        //Hide unnecessary labels when popup appears
        function hideLabels(region){
          JQ2(".flyway-label, .flyway-map-label").hide();
          JQ2(".flyway-label:contains(" + region + ")").show();
          JQ2(".microsite-bird-search-lower").hide();
        }

        //Show popup with states and draws the
        // active map section
        function popupInit(id,flyway, mapRegionClicked){
          if (typeof mapRegionClicked === 'undefined'){
            mapRegionClicked = false;
          }

          var state = birdPageView.getFlywayData().values.filter(function(stateItem) {
            return (stateItem[4] === id);
          })[0];

          //Draw a state filtered
          flywayListConfig['stateFilter'] = (state[1] === 'US' ? 'USA' : 'CAN') + ':' + state[3];
          birdPageView.drawList(flywayListConfig);

          JQ2('#flywaylist span.flyway-name').text(state[0]);
          JQ2('#flywaylist').show();
          JQ2('#stateprovincelist').hide();

          // Add dynamic description sent from Drupal, when a state is
          // clicked in the geo search state list.
          var dataStateCode = state[3],
            dataCountryCode = state[1];
          updateStateDescription(dataStateCode, dataCountryCode);

          //Popup positioning
          if(flyway == "Pacific" || flyway == "Central") {
            JQ2("#stateprovincelist, #flywaylist").css({"float": "right"});
          }
          else {
            JQ2("#stateprovincelist, #flywaylist").css({"float": "left"});
          }

          if(mapRegionClicked){
            //Replace the link
            urlReplace(state[0]);
          }
        }

        //Change the link in the url field accordingly the selected state
        function urlReplace(state){
          var filtered_state = state.toLowerCase().replace(' ', '-');
          Backbone.history.navigate(filtered_state, {trigger: true});
        }

        // Start the geo search deep link handler.
        geoSearchDeepLinkHandler();

      });
    }
  };
})(jQuery);