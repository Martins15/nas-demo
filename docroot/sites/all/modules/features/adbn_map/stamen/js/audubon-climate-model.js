//
// Audubon climate model
// Developed by Stamen in July 2014
//
'use strict';

(function(window, JQ2) {

/*
 * Natural Sort algorithm for Javascript - Version 0.7 - Released under MIT license
 * Author: Jim Palmer (based on chunking idea from Dave Koelle)
 */
 function naturalSort (a, b, column) {
    var re = /(^-?[0-9]+(\.?[0-9]*)[df]?e?[0-9]?$|^0x[0-9a-f]+$|[0-9]+)/gi,
        sre = /(^[ ]*|[ ]*$)/g,
        dre = /(^([\w ]+,?[\w ]+)?[\w ]+,?[\w ]+\d+:\d+(:\d+)?[\w ]?|^\d{1,4}[\/\-]\d{1,4}[\/\-]\d{1,4}|^\w+, \w+ \d+, \d{4})/,
        hre = /^0x[0-9a-f]+$/i,
        ore = /^0/,
        i = function(s) { return naturalSort.insensitive && (''+s).toLowerCase() || ''+s },
        // convert all to strings strip whitespace
        x = i(a[column]).replace(sre, '') || '',
        y = i(b[column]).replace(sre, '') || '',
        // chunk/tokenize
        xN = x.replace(re, '\0$1\0').replace(/\0$/,'').replace(/^\0/,'').split('\0'),
        yN = y.replace(re, '\0$1\0').replace(/\0$/,'').replace(/^\0/,'').split('\0'),
        // numeric, hex or date detection
        xD = parseInt(x.match(hre)) || (xN.length != 1 && x.match(dre) && Date.parse(x)),
        yD = parseInt(y.match(hre)) || xD && y.match(dre) && Date.parse(y) || null,
        oFxNcL, oFyNcL;
    // first try and sort Hex codes or Dates
    if (yD)
        if ( xD < yD ) return -1;
        else if ( xD > yD ) return 1;
    // natural sorting through split numeric strings and default strings
    for(var cLoc=0, numS=Math.max(xN.length, yN.length); cLoc < numS; cLoc++) {
        // find floats not starting with '0', string or 0 if not defined (Clint Priest)
        oFxNcL = !(xN[cLoc] || '').match(ore) && parseFloat(xN[cLoc]) || xN[cLoc] || 0;
        oFyNcL = !(yN[cLoc] || '').match(ore) && parseFloat(yN[cLoc]) || yN[cLoc] || 0;
        // handle numeric vs string comparison - number < string - (Kyle Adams)
        if (isNaN(oFxNcL) !== isNaN(oFyNcL)) { return (isNaN(oFxNcL)) ? 1 : -1; }
        // rely on string comparison if different types - i.e. '02' < 2 != '02' < '2'
        else if (typeof oFxNcL !== typeof oFyNcL) {
            oFxNcL += '';
            oFyNcL += '';
        }
        if (oFxNcL < oFyNcL) return -1;
        if (oFxNcL > oFyNcL) return 1;
    }
    return 0;
}

  window.STMN.audubonClimateModel = window.STMN.audubonClimateModel || {};

  function BirdPageView(options, callback) {

    STMN.StamenBase.apply( this, arguments );

    var data = {
          states : {}
        },
        endangerednessRank = [
          'ENDANGERED',
          'ENDANGERED_2',
          'ENDANGERED_1',
          'THREATENED',
          'THREATENED_2',
          'THREATENED_1',
          'STABLE',
          'OTHER_INTRODUCED',
          'OTHER_MARGINAL'
        ],
        self = this,
        states, scope, oldUIState, rootNode, superGif, searchBoxInstance, slideshow;

    window.data = data;

    //
    // Check a few requierments
    //

    if (!options || typeof options !== 'object') {
      return callback('Error: The second argument of this view should be an options object');
    }

    if (!options.paths || !options.paths.data) {
      return callback('Error: There is no path set for core data in the options object.');
    }

    if (!options.defaults) {
      options.defaults = {};
    }

    //
    // State data
    //

    states = {
      flywayList : null,
      flywayMap  : null,
      animation  : true //Play, pause is false
    }

    function updateCoreData(callback) {

      //
      // Fetch the core data
      //
      JQ2.ajax(options.paths.data, {
        success : function(r) {
          data['core'] = r;

          data['selected'] = {};
          for (var i = 0; data.core.values.length > i; i++) {
            if (data.core.values[i][2] === options.SPECIES_CODE) {
              for (var ii = 0; data.core.keys.length > ii; ii++) {
                data['selected'][data.core.keys[ii]] = data.core.values[i][ii];
              }
            }
          }

          //
          // Fetch the giphy data
          //
          JQ2.ajax(options.paths.giphy, {
            success : function(r) {
              data['giphy'] = r;

              window.data = data;
              callback(null, data);

              self.fire('dataUpdate', data);
            },
            error : function(r) {
              callback(r);
            }
          });
        },
        error : function(r) {
          callback(r);
        }
      });

    }

    function changeTitle() {

      var oldValue, title;

      if (JQ2(options.selectors.title).length) { //Check if there is a container to use

        oldValue = JQ2(options.selectors.title).html();

        if (Object.keys(data.selected).length) { //Check if a bird has been selected
          title = self.processTemplate(
            options.templates.title,
            data.selected
          );
        } else { //Show default title (if configured)

          if (options.defaults.title) {
            title =  options.defaults.title || '';
          } else {
            return false;
          }

        }

        self.fire('titleUpdated', {
          oldValue : oldValue,
          newValue : JQ2(options.selectors.title).html()
        });

        return JQ2(options.selectors.title).html(title);

      }
    }

    function _drawList(listConfig, stateData, rootNode) {

      //console.log(listConfig);

      var added = {},
          percentageLost, modifiedList, columnObject;

      var filteredList = data.core.values.filter(function(bird) {

        var pass = true,
            key, index;

        if (typeof listConfig.columnFilter === 'object' && listConfig.columnFilter.length) {
          listConfig.columnFilter.forEach(function(filter) {
            key   = Object.keys(filter)[0];
            index = data.core.keys.indexOf(key);

            if (bird[index] !== filter[key]) {
              pass = false;
            }
          });
        }

        if (stateData && !(stateData.indexOf(bird[2]) > -1)) {
          pass = false;
        }

        //
        // Filter out duplicates
        //
        if (!added[bird[2]]) {
          added[bird[2]] = true;
        } else {
          pass = false;
        }

        return pass;

      });

      //
      // Mix in percentage lost and column headers
      //
      filteredList = filteredList.map(function(bird) {

        columnObject = {};

        //
        // Add percentage lost to each bird object
        //
        bird.forEach(function(column, i) {
          return columnObject[data.core.keys[i]] = column;
        });

        percentageLost = getPercentageLostData(bird[2]);

        columnObject['percentageLost.BBS'] = percentageLost['BBS'];
        columnObject['percentageLost.CBC'] = percentageLost['CBC'];

        //
        // Format if there is a formatter
        //

        if (listConfig.columnFormatter) {
          columnObject = listConfig.columnFormatter(columnObject);
        }

        return columnObject;
      });

      //
      // Sort the list if sort column passed
      //
      if (listConfig.sortColumn) {
        filteredList = filteredList.sort(function(a,b) {
          return naturalSort(a,b,listConfig.sortColumn);
        });

        if (listConfig.reverseSort) {
          filteredList = filteredList.reverse();
        }
      }

      //
      // Limit array size
      //
      if (listConfig.limit) {
        filteredList.length = listConfig.limit;
      }

      //Draw list
      rootNode.html(filteredList.map(function(item) {
        //console.log(item);
        return self.processTemplate(listConfig.template, item);
      }));

      self.fire('listCreate', {list:listConfig});

      if (!states.listHasClick) {
        states.listHasClick = {};
      }

      if (!states.listHasClick[listConfig.listId]) {
        rootNode.bind('click', function(e) {

          self.fire('listSelect', {
            clickEvent : e,
            listConfig : listConfig
          });

        });
        states.listHasClick[listConfig.listId] = true;
      }

    }

    function drawList(listConfig) {

      var rootNode         = JQ2(listConfig.selector),
          stateFilterArray = listConfig.stateFilter.split(':');

      if (rootNode.length) {

        if (listConfig.stateFilter) {

          getStateData(stateFilterArray[0], stateFilterArray[1], function(err, stateData) {
            _drawList(listConfig, stateData['focal'], rootNode);
          });

        } else {
          _drawList(listConfig, null, rootNode);
        }

      }

    }

    function drawLists(listsConfig) {

      var config = listsConfig || options.lists;

      if (typeof config === 'object' && config.length) {

        return config.forEach(drawList);

      }

    }

    function changeMapAnimation(mapSize) {

      var rootNode = JQ2(options.selectors.animation);

      if (rootNode.length) {

          if (slideshow) {
            slideshow.destroy();
          }

          var imageSize;

          switch (true) {
              case mapSize == "full":
                  imageSize = "full";
                  break;
              case mapSize > 1280:
                  imageSize = "l";
                  break;
              case mapSize > 767:
                  imageSize = "m";
                  break;
              default:
                  imageSize = "l";
          }

          slideshow = new STMN.audubonClimateModel.Slideshow(options.selectors.animation, [
            {label:'2000',src:self.processTemplate(options.templates.animationImage, {SPECIES_CODE: options.SPECIES_CODE, year: '2000', size: imageSize})},
            {label:'2020',src:self.processTemplate(options.templates.animationImage, {SPECIES_CODE: options.SPECIES_CODE, year: '2020', size: imageSize})},
            {label:'2050',src:self.processTemplate(options.templates.animationImage, {SPECIES_CODE: options.SPECIES_CODE, year: '2050', size: imageSize})},
            {label:'2080',src:self.processTemplate(options.templates.animationImage, {SPECIES_CODE: options.SPECIES_CODE, year: '2080', size: imageSize})},
          ], {
            duration : options.animation.slideDuration,
            lastSlidePause : options.animation.lastSlidePause,
            templates : options.templates
          });

          slideshow.on('started', function(e) {
            self.fire('animation:started', {
              instance  : slideshow,
              eventArgs : e.caller
            });
          });
          slideshow.on('stopped', function(e) {
            self.fire('animation:stopped', {
              instance  : slideshow,
              eventArgs : e.caller
            });
          });
          slideshow.on('stepChanged', function(e) {
            self.fire('animation:stepChanged', {
              instance  : slideshow,
              eventArgs : e.caller
            });
          });

          self.fire('animation:ready', {
            instance  : slideshow
          });
      }

    }

    function changeNonGeoViz() {

      var rootNode = JQ2(options.selectors.nonGeoViz);

      if (rootNode.length) {

        var chart = vennOverVenn()
          .leftBuffer(30)  // x position of center of left circle (if circles overflow)
          .width(290)  // width of chart (midpoint of circles will be centered unless right side overflows)
          .height(200)  // height of chart (centerline of circles will be in the middle)
          .radius(20);  // radius of year 2000 circle

        var species_code = data.selected.SPECIES_CODE;

        var species_code_index = data.core.keys.indexOf('SPECIES_CODE');
        var range_relative_index = data.core.keys.indexOf('RANGE_SIZE_RELATIVE_TO_2000');
        var range_left_index = data.core.keys.indexOf('PROPORTION_2000_RANGE_LEFT');
        var season_index = data.core.keys.indexOf('SEASON');
        var extracted_data = { id: species_code };
        data.core.values.filter(function(v) {
          return v[species_code_index] === species_code;
        }).forEach(function(v) {
          extracted_data[v[season_index] + '_range_relative'] = v[range_relative_index];
          extracted_data[v[season_index] + '_range_left'] = v[range_left_index];
        });

        var notmap = d3.select(rootNode.get(0)).selectAll("div")
            .data([extracted_data], function(d) { return d.id; });

        notmap.enter().append("div")
          .call(chart);

        notmap.exit().remove();

      }

    }

    function changeShareMenu() {

      var rootNode = JQ2(options.selectors.shareMenu),
          giphy;

      if (rootNode.length) {

        giphy = getGiphyDataForBirdId(data.selected['SPECIES_CODE']);

        rootNode.html(self.processTemplate(
          options.templates.shareMenu,
          {
            urlTiny                : giphy.giphy_short_url_bitly_url,
            giphyUrlTiny           : 'http://gph.is/' + giphy.giphy_short_url_id,
            giphyUrlGif            : giphy.giphy_gif_permalink,
            giphyId                : giphy.giphy_gif_id,

            description            : giphy.description.split("'").join("&#92;&#39;"),
            url                    : giphy.url,
            SPECIES_CODE           : data.selected['SPECIES_CODE'],
            PRIMARY_COM_NAME       : data.selected['PRIMARY_COM_NAME'].split("'").join("&#92;&#39;"),
            PRIMARY_COM_NAME_EMAIL : encodeURI(data.selected['PRIMARY_COM_NAME'])
          }
        ));
      }

    }

    function getStatesByFlyway(flyway) {
      if (flyway) {
        return data.core.extras.flyways.values.filter(function(d) {
          return d[2].toLowerCase() === flyway.toLowerCase();
        });
      }
    }

    function getStateNameByAudubonId(audubonId) {

      var state = data.core.extras.flyways.values.filter(function(item) {
        return (item[3] === audubonId);
      });

      return state[0][0];
    }

    function getGiphyDataForBirdId(SPECIES_CODE) {

      for (var i=0; data.giphy.length > i; i++) {
        if (data.giphy[i].filename.substring(0,data.giphy[i].filename.length-4) === SPECIES_CODE) {
          return data.giphy[i];
        }
      }

    }

    function getStateData(countryCode, audubonId, callback) {

      if (data.states[countryCode + ':' + audubonId]) { //State data is already cached
        return callback(null, data.states[countryCode + ':' + audubonId]);
      } else { //Go get it
        JQ2.ajax(self.processTemplate(options.paths.states,{
          countryCode : countryCode,
          audubonId   : audubonId
        }),{
          success : function(d) {

            //
            // Cache the data
            //
            data.states[countryCode + ':' + audubonId] = d;

            return callback(null, d);

          }
        });
      }

    }

    function getPercentageLostData(SPECIES_CODE) {
      return data.core.extras.percentageLost[SPECIES_CODE];
    }

    self.sortFunction = function sortFunction(dataArray) {
      return dataArray;
    }

    function getCoreDataKeys() {

      return data.core.keys;
    }

    function getCoreDataValues(sortingFunction, deDup) {

      //
      // Initial default sort
      //

      var sortingObject = {},
          sortMethod    = sortingFunction || self.sortFunction,
          arrayOut      = [],
          dupeobject    = {},
          birds, scratchArray, valuesArray;

      endangerednessRank.forEach(function(item) {
        sortingObject[item] = [];
      });

      //
      // Is there a filter?
      //
      if (typeof options.filterTo === 'object' && options.filterTo.length > 0) {
        valuesArray = data.core.values.filter(function(bird) {
          return (options.filterTo.indexOf(bird[6]) > -1);
        });
      } else {
        valuesArray = data.core.values;
      }

      valuesArray.forEach(function(bird) {
        if (bird[6].length < 1) {
          bird[6] = '_norank_';
        }
        if (!sortingObject[bird[6]]) { //stack un-ordered ones at the end
          sortingObject[bird[6]] = [];
        }
        sortingObject[bird[6]].push(bird); //Put it in the sorting array by AUDUBON_CLIMATE_SENSITIVITY ordered by endangerednessRank
      });

      Object.keys(sortingObject).forEach(function(key) {
        birds = sortingObject[key].sort(function(a,b) {return a[13]-b[13];}); //Sort by RANGE_SIZE_RELATIVE_TO_2000
        arrayOut = arrayOut.concat(birds);
      });

      if (deDup) {
        scratchArray = arrayOut.filter(function(bird) {

          if (dupeobject[bird[2]]) {
            return false;
          } else {
            dupeobject[bird[2]] = true;
            return true;
          }
        });

        arrayOut = scratchArray;
      }

      //
      // Let the implementer sort if they need too
      //
      return sortMethod(arrayOut);
    }

    function getCoreData(sortingFunction, deDup) {

      var scratchObject = {};

      return getCoreDataValues(sortingFunction, deDup).map(function(bird) {
        scratchObject = {};
        return bird.map(function(column, i) {
          scratchObject[data.core.keys[i]] = column;
          return scratchObject
        })[0];
      });
    }

    function getFlywayData() {
      return data.core.extras.flyways;
    }

    function generateFlywayListUIState(options) {

      if (options.itemIdIndex && typeof options.itemIdIndex === 'number') {
        options.itemIdIndex = [options.itemIdIndex];
      }

      JQ2(options.root).html( //Puts the following in the rootNode
        self.processTemplate(options.wrapperTemplate, { //Fills out the outer list template
          //TODO: Make this listname configurable --  use JQuery map instead
          listname : options.listname,
          items : options.itemsArray.map(function(item){
            return self.processTemplate(options.itemTemplate, {
              name : (options.listtypeprefix === 'state') ? item[0] : item[1],
              description : (options.listtypeprefix === 'state') ? '' : item[0],
              id : (options.listtypeprefix === 'state') ? 'state' : item[2],
              listtype : options.listtypeprefix + ':' + (
                options.itemIdIndex.map(function(i) {
                  return item[i];
                }).join(':')
              )
            }) //This builds the items and adds them to the contents object for the outer template
          }).join(' ')
        })
      );
    }

    function setFlywayListUIState(uiState) {

      var uiStateSplit = (uiState) ? uiState.split(':') : uiState;

      oldUIState = states.flywayList;
      rootNode   = JQ2(options.selectors.flywayList);

      if (rootNode.length) { //If no node has been set, do not proceed

        if (uiState) { //If the value is truthy, it at least means to show

          rootNode.show();

          if (!states.flywayLitsDom) {

            rootNode.bind('click', function(e) {
              e.preventDefault();

              var action   = JQ2(e.target).attr('data-action'),
                  eUIState = JQ2(e.target).attr('data-listtype') ? JQ2(e.target).attr('data-listtype').split(':') : [];

              if (action === 'back') {
                self.fire('flywayListUIBackAction', {});
              } else if (eUIState[0]) {
                self.fire('listSelect', {
                  uiState : JQ2(e.target).attr('data-listtype')
                });
              }
            });
            states.flywayLitsDom = true;

          }

          if (uiStateSplit[0] === 'flyway') { //Flyway state lists

            generateFlywayListUIState({
              root            : options.selectors.flywayList,
              wrapperTemplate : options.templates.flywayNavList,
              listname        : 'The ' + uiStateSplit[1].substr(0,1).toUpperCase() + uiStateSplit[1].substr(1) + ' flyway',
              itemsArray      : getStatesByFlyway(uiStateSplit[1]),
              itemTemplate    : options.templates.listItem,
              itemIdIndex     : [1,3],
              listtypeprefix  : 'state'
            });

          } else if(uiStateSplit[0] = 'state') { //Individual States

            var country = (uiStateSplit[1] === 'US') ? 'USA' : 'CAN';

            getStateData(country, uiStateSplit[2], function(err, d) {

              generateFlywayListUIState({
                root            : options.selectors.flywayList,
                wrapperTemplate : options.templates.flywayNavList,
                listname        : 'Birds in ' + getStateNameByAudubonId(uiStateSplit[2]),
                itemsArray      : getCoreDataValues(null, true).filter(function(i) {
                  return d['rankings'][i[2]];
                }),
                itemTemplate    : options.templates.listItem,
                itemIdIndex     : 2,
                listtypeprefix  : 'bird'
              });

            });

          }
          states.flywayList = uiStateSplit;

        } else {
          if (uiState === null) {
            rootNode.hide();
          }
        }

        self.fire('flywayListUIStateChange', {
          newUIState : uiState,
          oldUIState : oldUIState
        });

      }

    }

    function setFlywayMapUIState(uiState) {

      oldUIState = states.flywayMap;
      rootNode   = JQ2(options.selectors.flywayNavMap);

      var g;

      if (rootNode.length) {
        if (uiState) { //If the value is truthy, it at least means to show

          var uiStateSplit = (uiState !== true) ? uiState.split(/:|,/) : uiState;

            //
            // Build FlywayMapAreas
            //

            d3.json(options.paths.flywayPolygons, function(error, us) {

              // figure out the flyway for each state/province

              var statePostalIndex = data.core.extras.flyways.keys.indexOf('postal');
              var stateFlywayIndex = data.core.extras.flyways.keys.indexOf('flyway');
              var threeLetterIndex = data.core.extras.flyways.keys.indexOf('code');
              var flywayLookup = {};
              var threeLetterLookup = {};
              data.core.extras.flyways.values.forEach(function(state) {
                flywayLookup[state[statePostalIndex]] = state[stateFlywayIndex];
                threeLetterLookup[state[statePostalIndex]] = state[threeLetterIndex];
              });

              var path = d3.geo.path()
                  .projection(null);  // topojson file is already projected

              var svg = d3.select(options.selectors.flywayNavMap).select("svg");

              if (svg.empty()) {  // If we haven't created it yet
                  svg = d3.select(options.selectors.flywayNavMap).append("svg")
                          .attr("width", "100%")
                          .attr("height", "100%");
                  g = svg.append("g")
                      .attr("class", "states_g")

                  // Draw the states and provinces
                  g.selectAll("path")
                      .data(topojson.feature(us, us.objects.usa_canada).features)
                    .enter()
                      .append("path")
                      .attr("id", function(d) {
                        return threeLetterLookup[d.id]
                      })
                      .attr("class", function(d) {
                        var flyway = flywayLookup[d.id],
                            state = threeLetterLookup[d.id];

                        if (uiStateSplit[0] != "flyway" || uiStateSplit[0] === "flyway" && uiStateSplit[1] == flyway) {
                          var newClass = flyway;
                          if(uiStateSplit[3]==state) {
                            newClass+=" active"
                          }
                          return newClass
                        }
                        else {
                          return "defaultMap"
                        }
                      })
                      .on('mouseover', function() { if (!STMN.classListPolyfill) {d3.select(this).classed("mapActive", true); } })
                      .on('mouseout', function() { if(!STMN.classListPolyfill) {d3.select(this).classed("mapActive", false); } } )
                      .on('click', function(d) {
                        var flyway = flywayLookup[d.id];
                        self.fire('clickFlywayMapRegion', { region: flyway, clickEvent: d });
                      })
                      .attr("d", path);

                  // Draw the lines between states
                  g = svg.append("g")
                      .attr("class", "boundaries_g")
                      .append("path")
                      .datum(topojson.mesh(us, us.objects.usa_canada, function(a, b) { return a !== b; }))
                      .attr("class", "state-boundary")
                      .attr("d", path);

              } else {  // We've already created the svg and populated it

                  svg.select("g.states_g").selectAll("path")
                    .attr("class", function(d) {
                      var flyway = flywayLookup[d.id];
                      if (uiStateSplit[0] != 'flyway' || (uiStateSplit[0] === 'flyway' && uiStateSplit[1] == flyway)) {
                        return flyway;
                      } else {
                        return "defaultMap";
                      }
                    })
                    .on('click', function(d) {
                      var flyway = flywayLookup[d.id];

                      // If we're in flyway mode, and this state is in the current flyway, then...
                      if (uiStateSplit[0] === 'flyway' && uiStateSplit[1] == flyway) {
                        // Fire the state selection event
                        self.fire('clickFlywayMapRegion', { state: threeLetterLookup[d.id], region: flyway, clickEvent: d });
                      } else {
                        // ...otherwise, fire the flyway click.
                        // This should always happen in the initial (continent) mode.
                        // It should also happen in flyway mode, when someone clicks a non-highlighted state/flyway
                        self.fire('clickFlywayMapRegion', { region: flyway, clickEvent: d });
                      }
                    });
              }

            });

            //
            // Set state
            //
            states.flywayMapDom = true;
          //}

          rootNode.show();

        } else {

          rootNode.hide();

        }

        states.flywayMap = uiState;

        self.fire('flywayMapUIStateChange', {
          newUIState : uiState,
          oldUIState : oldUIState
        });
      }

    }

    function substringMatcher(strs) {
      return function findMatches(q, cb) {
        var matches, substrRegex;

        // an array that will be populated with substring matches
        matches = [];

        // regex used to determine if a string contains the substring `q`
        substrRegex = new RegExp(q, 'i');

        // iterate through the pool of strings and for any string that
        // contains the substring `q`, add it to the `matches` array
        JQ2.each(strs, function(i, str) {
          if (substrRegex.test(str)) {
            // the typeahead jQuery plugin expects suggestions to a
            // JavaScript object, refer to typeahead docs for more info
            matches.push({ value: str });
          }
        });

        cb(matches);
      };
    };

    function initSearchMenu() {

      if (JQ2(options.selectors.searchBox).length) {

        searchBoxInstance = JQ2(options.selectors.searchBox).typeahead({
          hint: true,
          highlight: true,
          minLength: 1
        },
        {
          source: substringMatcher(
            getCoreData(null, true).map(function(v) {
              return v['PRIMARY_COM_NAME'];
            }))
        }).bind('typeahead:selected', function(tt, r) {
          self.fire('search:selected', getCoreData(null, true).filter(function(bird){
            return bird['PRIMARY_COM_NAME'] === r.value;
          }));
        });

      }

    }

    this.on('mapUpdate', function(e) {
      changeMapAnimation("full");
    });

    this.on('dataUpdate', function(e) {
      changeTitle();
      changeMapAnimation(JQ2(window).width());
      changeNonGeoViz();
      changeShareMenu();
      setFlywayMapUIState(true);
      setFlywayListUIState(false);
      drawLists();
    });

    this.once('dataUpdate',initSearchMenu);

    //
    // The public methods
    //
    scope = {
        name : 'BirdPageView',
        setBird : function(SPECIES_CODE) {
          options.SPECIES_CODE = SPECIES_CODE;
          updateCoreData(function() {});
        },
        on   : this.on,
        once : this.once,
        setFlywayListUIState  : setFlywayListUIState,
        setFlywayMapUIState   : setFlywayMapUIState,
        getCoreData           : getCoreData,
        getFlywayData         : getFlywayData,
        getStateData          : getStateData,
        getPercentageLostData : getPercentageLostData,
        getGiphyDataForBirdId : getGiphyDataForBirdId,
        changeMapAnimation    : changeMapAnimation,
        drawLists : drawLists,
        drawList : drawList,

        getGiphyData : function() {
          return data.giphy;
        },

        getAnimation : function() {
          return slideshow;
        },

        getSearchBoxInstance : function() {
          return searchBoxInstance;
        }
    }

    //
    // Initialize!
    //
    updateCoreData(function(err, data) {

      //
      // View is all loaded, call back.
      //

      if (callback) {
        return callback(null, scope);
      } else {
        return true;
      }

    });

    return scope;

  }

  STMN.audubonClimateModel.BirdPageView = BirdPageView;

}(window, JQ2));
