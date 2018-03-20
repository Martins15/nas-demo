(function(){function e(t,n,r){function s(o,u){if(!n[o]){if(!t[o]){var a=typeof require=="function"&&require;if(!u&&a)return a(o,!0);if(i)return i(o,!0);var f=new Error("Cannot find module '"+o+"'");throw f.code="MODULE_NOT_FOUND",f}var l=n[o]={exports:{}};t[o][0].call(l.exports,function(e){var n=t[o][1][e];return s(n?n:e)},l,l.exports,e,t,n,r)}return n[o].exports}var i=typeof require=="function"&&require;for(var o=0;o<r.length;o++)s(r[o]);return s}return e})()({1:[function(require,module,exports){
    "use strict";

    Object.defineProperty(exports, "__esModule", {
      value: true
    });
    exports.albersBigAlaska = albersBigAlaska;
// lots of stuff harvested from d3.js
// only real difference is rotation / scale / clippping and translation of
// the alaska portion of albersUsa

    var epsilon$2 = 1e-6;
    function noop$1() {}
    var x0$2 = Infinity;
    var y0$2 = x0$2;
    var x1 = -x0$2;
    var y1 = x1;

    var boundsStream$1 = {
      point: boundsPoint$1,
      lineStart: noop$1,
      lineEnd: noop$1,
      polygonStart: noop$1,
      polygonEnd: noop$1,
      result: function result() {
        var bounds = [[x0$2, y0$2], [x1, y1]];
        x1 = y1 = -(y0$2 = x0$2 = Infinity);
        return bounds;
      }
    };

    function boundsPoint$1(x, y) {
      if (x < x0$2) x0$2 = x;
      if (x > x1) x1 = x;
      if (y < y0$2) y0$2 = y;
      if (y > y1) y1 = y;
    }

    function fit(projection, fitBounds, object) {
      var clip = projection.clipExtent && projection.clipExtent();
      projection.scale(150).translate([0, 0]);
      if (clip != null) projection.clipExtent(null);
      d3.geoStream(object, projection.stream(boundsStream$1));
      fitBounds(boundsStream$1.result());
      if (clip != null) projection.clipExtent(clip);
      return projection;
    }

    function fitExtent(projection, extent, object) {
      return fit(projection, function (b) {
        var w = extent[1][0] - extent[0][0],
          h = extent[1][1] - extent[0][1],
          k = Math.min(w / (b[1][0] - b[0][0]), h / (b[1][1] - b[0][1])),
          x = +extent[0][0] + (w - k * (b[1][0] + b[0][0])) / 2,
          y = +extent[0][1] + (h - k * (b[1][1] + b[0][1])) / 2;
        projection.scale(150 * k).translate([x, y]);
      }, object);
    }

    function fitSize(projection, size, object) {
      return fitExtent(projection, [[0, 0], size], object);
    }

    function fitWidth(projection, width, object) {
      return fit(projection, function (b) {
        var w = +width,
          k = w / (b[1][0] - b[0][0]),
          x = (w - k * (b[1][0] + b[0][0])) / 2,
          y = -k * b[0][1];
        projection.scale(150 * k).translate([x, y]);
      }, object);
    }

    function fitHeight(projection, height, object) {
      return fit(projection, function (b) {
        var h = +height,
          k = h / (b[1][1] - b[0][1]),
          x = -k * b[0][0],
          y = (h - k * (b[1][1] + b[0][1])) / 2;
        projection.scale(150 * k).translate([x, y]);
      }, object);
    }

    function multiplex(streams) {
      var n = streams.length;
      return {
        point: function point(x, y) {
          var i = -1;while (++i < n) {
            streams[i].point(x, y);
          }
        },
        sphere: function sphere() {
          var i = -1;while (++i < n) {
            streams[i].sphere();
          }
        },
        lineStart: function lineStart() {
          var i = -1;while (++i < n) {
            streams[i].lineStart();
          }
        },
        lineEnd: function lineEnd() {
          var i = -1;while (++i < n) {
            streams[i].lineEnd();
          }
        },
        polygonStart: function polygonStart() {
          var i = -1;while (++i < n) {
            streams[i].polygonStart();
          }
        },
        polygonEnd: function polygonEnd() {
          var i = -1;while (++i < n) {
            streams[i].polygonEnd();
          }
        }
      };
    }

// A composite projection for the United States, configured by default for
// 960×500. The projection also works quite well at 960×600 if you change the
// scale to 1285 and adjust the translate accordingly. The set of standard
// parallels for each region comes from USGS, which is published here:
// http://egsc.usgs.gov/isb/pubs/MapProjections/projections.html#albers
    function albersBigAlaska() {
      var cache,
        cacheStream,
        lower48 = d3.geoAlbers(),
        lower48Point,
        alaska = d3.geoConicEqualArea().rotate([154, 0]).center([-2, 58.5]).parallels([55, 65]),
        alaskaPoint,
        // EPSG:3338
        hawaii = d3.geoConicEqualArea().rotate([157, 0]).center([-3, 19.9]).parallels([8, 18]),
        hawaiiPoint,
        // ESRI:102007
        _point,
        pointStream = { point: function point(x, y) {
            _point = [x, y];
          } };

      function albersUsa(coordinates) {
        var x = coordinates[0],
          y = coordinates[1];
        return _point = null, (lower48Point.point(x, y), _point) || (alaskaPoint.point(x, y), _point) || (hawaiiPoint.point(x, y), _point);
      }

      albersUsa.invert = function (coordinates) {
        var k = lower48.scale(),
          t = lower48.translate(),
          x = (coordinates[0] - t[0]) / k,
          y = (coordinates[1] - t[1]) / k;
        return (y >= 0.120 && y < 0.234 && x >= -0.425 && x < -0.214 ? alaska : y >= 0.166 && y < 0.234 && x >= -0.214 && x < -0.115 ? hawaii : lower48).invert(coordinates);
      };

      albersUsa.stream = function (stream) {
        return cache && cacheStream === stream ? cache : cache = multiplex([lower48.stream(cacheStream = stream), alaska.stream(stream), hawaii.stream(stream)]);
      };

      albersUsa.precision = function (_) {
        if (!arguments.length) return lower48.precision();
        lower48.precision(_), alaska.precision(_), hawaii.precision(_);
        return reset();
      };

      albersUsa.scale = function (_) {
        if (!arguments.length) return lower48.scale();
        lower48.scale(_), alaska.scale(_ * 0.52), hawaii.scale(_);
        return albersUsa.translate(lower48.translate());
      };

      albersUsa.translate = function (_) {
        if (!arguments.length) return lower48.translate();
        var k = lower48.scale(),
          x = +_[0],
          y = +_[1];

        lower48Point = lower48.translate(_).clipExtent([[x - 0.455 * k, y - 0.238 * k], [x + 0.455 * k, y + 0.238 * k]]).stream(pointStream);

        alaskaPoint = alaska.translate([x - 0.307 * k, y + 0.211 * k]).clipExtent([[x - 0.425 * k + epsilon$2, y + 0.020 * k + epsilon$2], [x - 0.184 * k - epsilon$2, y + 0.254 * k - epsilon$2]]).stream(pointStream);

        hawaiiPoint = hawaii.translate([x - 0.205 * k, y + 0.212 * k]).clipExtent([[x - 0.214 * k + epsilon$2, y + 0.166 * k + epsilon$2], [x - 0.115 * k - epsilon$2, y + 0.234 * k - epsilon$2]]).stream(pointStream);

        return reset();
      };

      albersUsa.fitExtent = function (extent, object) {
        return fitExtent(albersUsa, extent, object);
      };

      albersUsa.fitSize = function (size, object) {
        return fitSize(albersUsa, size, object);
      };

      albersUsa.fitWidth = function (width, object) {
        return fitWidth(albersUsa, width, object);
      };

      albersUsa.fitHeight = function (height, object) {
        return fitHeight(albersUsa, height, object);
      };

      function reset() {
        cache = cacheStream = null;
        return albersUsa;
      }

      return albersUsa.scale(1070);
    }

  },{}],2:[function(require,module,exports){
    'use strict';

    Object.defineProperty(exports, "__esModule", {
      value: true
    });
    exports.AllParks = undefined;

    var _slicedToArray = function () { function sliceIterator(arr, i) { var _arr = []; var _n = true; var _d = false; var _e = undefined; try { for (var _i = arr[Symbol.iterator](), _s; !(_n = (_s = _i.next()).done); _n = true) { _arr.push(_s.value); if (i && _arr.length === i) break; } } catch (err) { _d = true; _e = err; } finally { try { if (!_n && _i["return"]) _i["return"](); } finally { if (_d) throw _e; } } return _arr; } return function (arr, i) { if (Array.isArray(arr)) { return arr; } else if (Symbol.iterator in Object(arr)) { return sliceIterator(arr, i); } else { throw new TypeError("Invalid attempt to destructure non-iterable instance"); } }; }();

    var _birdDot = require('./birdDot');

    var regions = [['Alaska', 'Alaska', 'https://cdn.audubon.org/cdn/farfuture/fFGf-bOAIxRXDiimvPWD0aLHshc6VMFBdLu488zC8SE/mtime:1521225912/sites/default/files/0315-alaska-photo2x.jpg'], ['Intermountain', 'Intermountain', 'https://cdn.audubon.org/cdn/farfuture/0uMkGr8PaPD0alIdEsCNnQ0La4LbkyNeQfVLw4E2bpM/mtime:1521225946/sites/default/files/0315-intermountain-photo2x.jpg'], ['Midwest', 'Midwest', 'https://cdn.audubon.org/cdn/farfuture/KqQxCEPraMyZ483BR-MjSDovcrHuGsUkB7uRRNAQ-Xo/mtime:1521226022/sites/default/files/0315-midwest-photo2x.jpg'], ['Northeast', 'Northeast', 'https://cdn.audubon.org/cdn/farfuture/Lgsy-l3ccfiEppla48j0svjtBmtsnxpJX2mqOaYax-A/mtime:1521226061/sites/default/files/0315-northeast-photo2x.jpg'], ['Pacific', 'Pacific West', 'https://cdn.audubon.org/cdn/farfuture/EN3YygWNSvHs_eEZb50yh2F1AONZ97uuUZAbvoc7uUg/mtime:1521225823/sites/default/files/0315-pacific-photo2x.jpg'], ['Southeast', 'Southeast', 'https://cdn.audubon.org/cdn/farfuture/Y8-r-_RkKkWKxoMSMA-xHUdljbT3GjoUkB5tPr1EQoo/mtime:1521225864/sites/default/files/0315-southeast-photo2x.jpg']];

    function AllParks(params) {
      var element = params.element,
        dataUrl = params.dataUrl,
        onClick = params.onClick;


      var node = d3.select(element);

      function renderPark(container, parkData) {
        var c = container.append('div').classed('sd-park', true).html('\n        <h3>' + parkData.unit_name + '</h3>\n        <div>\n          <div class="season season-winter">\n            <p>winter</p>\n          </div>\n          <div class="season season-summer">\n            <p>summer</p>\n          </div>\n        </div>\n      ');

        if (onClick) {
          c.select('h3').on('click', function () {
            return onClick(c.select('h3').text());
          });
        }

        var numDots = Math.max(+parkData.no_colonizations_summer + +parkData.current_species_summer, +parkData.no_colonizations_winter + +parkData.current_species_winter);

        var summerParams = {
          element: c.select('.season-summer').node(),
          numCurrent: +parkData.current_species_summer,
          numColonized: +parkData.no_colonizations_summer,
          numExtirpated: +parkData.no_extirpations_summer,
          renderAll: true,
          numCols: 6,
          topAlign: true
        };

        var winterParams = {
          element: c.select('.season-winter').node(),
          numCurrent: +parkData.current_species_winter,
          numColonized: +parkData.no_colonizations_winter,
          numExtirpated: +parkData.no_extirpations_winter,
          renderAll: true,
          numCols: 6,
          topAlign: true
        };
        new _birdDot.BirdDotsBase(summerParams);
        new _birdDot.BirdDotsBase(winterParams);
      }

      d3.csv(dataUrl, function (error, rows) {

        if (error) {
          console.log(error);
          return;
        }

        var nested = d3.nest().key(function (d) {
          return d.nps_region;
        }).map(rows);

        regions.forEach(function (_ref) {
          var _ref2 = _slicedToArray(_ref, 3),
            region = _ref2[0],
            npsRegion = _ref2[1],
            regionImage = _ref2[2];

          var regionDiv = node.append('div').classed('sd-region', true).html('\n            <div class="region-header">\n              <a name="nps-region-' + region + '"></a>\n              <img class="background-image" src="' + regionImage + '">\n              <div class="row">\n                <h1>' + npsRegion + '</h1>\n              </div>\n            </div>\n            <div class="columns small-12">\n              <div class="dot-legend">\n                <div class="dot-legend-entry colonized">Potential colonization</div>\n                <div class="dot-legend-entry current">Stable population</div>\n                <div class="dot-legend-entry extirpated">Potential extirpation</div>\n              </div>\n              <div class="dot-area">\n              </div>\n            </div>\n        ');

          var parks = nested.get(npsRegion);
          if (parks) {
            parks.forEach(function (parkData) {
              renderPark(regionDiv.select('.dot-area'), parkData);
            });
          }
        });
      });
    }

    exports.AllParks = AllParks;

  },{"./birdDot":3}],3:[function(require,module,exports){
    'use strict';

    Object.defineProperty(exports, "__esModule", {
      value: true
    });
// Bird Dot animations


    function animateCount(element, start, end, duration) {
      // end is a number start is a number
      var interpolator = d3.interpolateNumber(start, end);
      var animationTimer = void 0;

      function animationFunc(elapsed) {
        var step = elapsed / duration;
        if (step >= 1) {
          animationTimer.stop();
          return;
        }
        var num = Math.round(interpolator(d3.easeQuadInOut(step)));
        element.text(num);
      }

      animationTimer = d3.timer(animationFunc);
    }

    function GridHelper(radius, spacing, numDots, numCols) {

      var _colScale = d3.scaleLinear().domain([80, 91, 109, 127]).range([5, 6, 7, 8]).clamp(true);

      function colScale(numDots) {
        return Math.floor(_colScale(numDots));
      }

      var cols = numCols || colScale(numDots);
      var numRows = Math.ceil(numDots / cols);
      var offset = numRows * cols - numDots;

      function gridPosition(idx) {
        idx += offset;
        var row = Math.floor(idx / cols);
        var col = idx - row * cols;

        return {
          x: col * spacing,
          y: row * spacing
        };
      }

      var width = cols * spacing;
      var height = numRows * spacing;

      return {
        gridPosition: gridPosition,
        height: height,
        width: width
      };
    }

    function randomBirdPos(scale) {
      return {
        x: (-100 + Math.random() * 200 + 20) * scale,
        y: -300 * scale
      };
    }

    var extirpatedGap = 10;

    function generatePoints(data, gridHelper, scale) {
      var numColonized = data.numColonized,
        numCurrent = data.numCurrent,
        numExtirpated = data.numExtirpated;

      var numRemaining = numCurrent - numExtirpated;

      var colors = {
        colonized: '#18a1ad',
        current: '#90d2d8',
        extirpated: '#e8c578'
      };

      var cc = d3.range(numColonized).map(function (i) {
        return {
          initPos: randomBirdPos(scale),
          finalPos: gridHelper.gridPosition(i),
          label: 'C',
          initFillOpacity: 0,
          initFill: colors.colonized,
          finalFillOpacity: 1,
          finalFill: colors.colonized
        };
      });

      var dd = d3.range(numRemaining).map(function (i) {
        return {
          initPos: gridHelper.gridPosition(i + numColonized),
          finalPos: gridHelper.gridPosition(i + numColonized),
          label: 'R',
          initFillOpacity: 1,
          initFill: colors.current,
          finalFillOpacity: 1,
          finalFill: colors.current
        };
      });

      var ee = d3.range(numExtirpated).map(function (i) {
        var finalPos = gridHelper.gridPosition(i + numColonized + numRemaining);
        finalPos.y += extirpatedGap * scale;

        return {
          initPos: gridHelper.gridPosition(i + numColonized + numRemaining),
          finalPos: finalPos,
          label: 'E',
          initFillOpacity: 1,
          initFill: colors.current,
          finalFillOpacity: 1,
          finalFill: colors.extirpated
        };
      });

      return cc.concat(dd).concat(ee);
    }

    function _BirdDots(params) {
      // attaches an svg to the element
      var element = params.element,
        numColonized = params.numColonized,
        numCurrent = params.numCurrent,
        numExtirpated = params.numExtirpated,
        colonizedCounter = params.colonizedCounter,
        extirpatedCounter = params.extirpatedCounter,
        onLoad = params.onLoad,
        scale = params.scale,
        numCols = params.numCols,
        renderAll = params.renderAll,
        topAlign = params.topAlign;


      var _scale = scale || 1;
      var radius = 3 * _scale;
      var spacing = 6 * _scale;

      var gridHelper = new GridHelper(radius, spacing, numCurrent + numColonized, numCols);

      var data = generatePoints(params, gridHelper, _scale);

      var svgWidth = 700;
      var svgHeight = 700;

      var divContainer = d3.select(element).append('div').classed('bird-dot-base-container', true);

      var svgContainer = divContainer.append('svg').attr('width', svgWidth).attr('height', svgHeight);

      var svg = svgContainer.append('g');

      function alignDots() {
        var _ref = [gridHelper.width, gridHelper.height],
          dotBoxWidth = _ref[0],
          dotBoxHeight = _ref[1];


        divContainer.style('width', dotBoxWidth + 'px');
        divContainer.style('height', dotBoxHeight + extirpatedGap * _scale + 'px');

        var divWidth = divContainer.node().offsetWidth;
        var divHeight = divContainer.node().offsetHeight;

        var offsetY = (topAlign ? 0 : (divHeight - dotBoxHeight) / 2) + radius;
        var offsetX = (divWidth - dotBoxWidth) / 2 + radius;

        // let svgOffsetY = Math.abs(parseInt(svgContainer.style('top')));
        // let svgOffsetX = Math.abs(parseInt(svgContainer.style('left')));
        var svgOffsetY = svgHeight / 2 - divHeight / 2;
        var svgOffsetX = svgWidth / 2 - divWidth / 2;
        svgContainer.style('top', -svgOffsetY + 'px');
        svgContainer.style('left', -svgOffsetX + 'px');

        var translateX = offsetX + svgOffsetX;
        var translateY = offsetY + svgOffsetY;

        svg.attr('transform', 'translate(' + translateX + ', ' + translateY + ')');
      }

      alignDots();

      var colonizedInView = false;
      var extirpatedInView = false;
      var disabledOpacity = 0.2;

      var dots = svg.selectAll('.dot').data(data);

      if (renderAll) {
        dots.enter().append('circle').attr('class', 'dot').classed('R', function (d) {
          return d.label == 'R';
        }).classed('E', function (d) {
          return d.label == 'E';
        }).classed('C', function (d) {
          return d.label == 'C';
        }).attr('cx', function (d) {
          return d.finalPos.x;
        }).attr('cy', function (d) {
          return d.finalPos.y;
        }).attr('r', radius).attr('fill-opacity', function (d) {
          return d.finalFillOpacity;
        }).attr('fill', function (d) {
          return d.finalFill;
        });
      } else {
        dots.enter().append('circle').attr('class', 'dot').classed('R', function (d) {
          return d.label == 'R';
        }).classed('E', function (d) {
          return d.label == 'E';
        }).classed('C', function (d) {
          return d.label == 'C';
        }).attr('cx', function (d) {
          return d.initPos.x;
        }).attr('cy', function (d) {
          return d.initPos.y;
        }).attr('r', radius).attr('fill-opacity', function (d) {
          return d.initFillOpacity;
        }).attr('fill', function (d) {
          return d.initFill;
        });
      }

      function enterColonized(onFinished) {
        var n = numColonized;
        svg.selectAll('.dot.C').classed('new-visible', true).transition().ease(d3.easeQuadInOut).duration(function (d, i) {
          return Math.random() * 300 + 950;
        }).delay(function (d, i) {
          return (numColonized - i) * 20;
        }).attr('cx', function (d) {
          return d.finalPos.x;
        }).attr('cy', function (d) {
          return d.finalPos.y;
        }).attr('fill-opacity', function (d) {
          return d.finalFillOpacity;
        }).attr('fill', function (d) {
          return d.finalFill;
        }).on('end', function (d, i) {
          n--;
          if (n == 0) {
            if (onFinished) {
              onFinished();
            }
          }
        });
        colonizedInView = true;
      }

      function exitColonized(onFinished) {
        var n = numColonized;
        svg.selectAll('.dot.C').classed('new-visible', false).transition().ease(d3.easeQuadInOut).duration(function (d, i) {
          return Math.random() * 300 + 950;
        }).delay(function (d, i) {
          return i * 20;
        }).attr('cx', function (d) {
          return d.initPos.x;
        }).attr('cy', function (d) {
          return d.initPos.y;
        }).attr('fill-opacity', function (d) {
          return d.initFillOpacity;
        }).attr('fill', function (d) {
          return d.initFill;
        }).on('end', function (d, i) {
          n--;
          if (n == 0) {
            if (onFinished) {
              onFinished();
            }
          }
        });
        colonizedInView = false;
      }

      function enterExtirpated(onFinished) {
        var n = numExtirpated;
        svg.selectAll('.dot.E').classed('extirpated-visible', true).transition().duration(function (d, i) {
          return Math.random() * 200 + 250;
        }).delay(function (d, i) {
          return (numExtirpated - i) * 20;
        }).attr('cx', function (d) {
          return d.finalPos.x;
        }).attr('cy', function (d) {
          return d.finalPos.y;
        }).attr('fill', function (d) {
          return d.finalFill;
        }).on('end', function (d, i) {
          n--;
          if (n == 0) {
            if (onFinished) {
              onFinished();
            }
          }
        });
        extirpatedInView = true;
      }

      function exitExtirpated(onFinished) {
        var n = numExtirpated;
        svg.selectAll('.dot.E').transition().duration(function (d, i) {
          return Math.random() * 200 + 250;
        }).delay(function (d, i) {
          return i * 20;
        }).attr('cx', function (d) {
          return d.initPos.x;
        }).attr('cy', function (d) {
          return d.initPos.y;
        }).attr('fill', function (d) {
          return d.initFill;
        }).on('end', function (d, i) {
          n--;
          if (n == 0) {
            if (onFinished) {
              onFinished();
            }
          }
        });
        extirpatedInView = false;
      }

      function jiggle(selection) {
        selection.transition().duration(function (d, i) {
          return Math.random() * 200 + 100;
        }).attr('cy', function (d) {
          return d.finalPos.y - 2;
        }).transition().duration(200).attr('cy', function (d) {
          return d.finalPos.y;
        });
      }

      function highlightExtirpated() {
        svg.selectAll('.dot.E').call(jiggle);
      }

      function highlightColonizations() {
        svg.selectAll('.dot.C').call(jiggle);
      }

      function animateIn() {
        animateCount(d3.select(colonizedCounter), 0, numColonized, 1200);
        enterColonized(function () {
          animateCount(d3.select(extirpatedCounter), 0, numExtirpated, 1200);
          enterExtirpated(function () {
            if (onLoad) {
              setTimeout(function () {
                return onLoad();
              }, 1000);
            }
          });
        });
      }
      function setCurrent() {
        if (colonizedInView || extirpatedInView) {
          // clearHighlight();
          exitColonized();
          exitExtirpated();
        }
      }

      function setColonized() {
        if (!colonizedInView) {
          enterColonized();
        } else {
          highlightColonizations();
        }
      }

      function setExtirpated() {
        if (!extirpatedInView) {
          enterExtirpated();
        } else {
          highlightExtirpated();
        }
      }

      return {
        animateIn: animateIn,
        svg: svgContainer.node(),
        numColonized: numColonized,
        numCurrent: numCurrent,
        numExtirpated: numExtirpated,
        enterExtirpated: enterExtirpated,
        enterColonized: enterColonized,
        setExtirpated: setExtirpated,
        setColonized: setColonized,
        setCurrent: setCurrent,
        data: data
      };
    }

    function BirdDots(params) {
      var element = params.element,
        dataUrl = params.dataUrl,
        season = params.season,
        park = params.park,
        currentCounter = params.currentCounter,
        colonizedCounter = params.colonizedCounter,
        extirpatedCounter = params.extirpatedCounter,
        onLoad = params.onLoad,
        initStats = params.initStats;


      var _season = season;
      var summerDots = void 0,
        winterDots = void 0;
      var ready = false;
      var node = d3.select(element).append('div').classed('bird-dot-container', true);

      d3.csv(dataUrl, function (error, data) {
        if (error) {
          console.log('error', error);
          return;
        }

        var parkRow = data.find(function (d) {
          return d.unit_name == park;
        });

        var summerParams = {
          element: node.node(),
          numCurrent: +parkRow.current_species_summer,
          numColonized: +parkRow.no_colonizations_summer,
          numExtirpated: +parkRow.no_extirpations_summer
        };

        var winterParams = {
          element: node.node(),
          numCurrent: +parkRow.current_species_winter,
          numColonized: +parkRow.no_colonizations_winter,
          numExtirpated: +parkRow.no_extirpations_winter
        };

        summerDots = new _BirdDots(summerParams);
        winterDots = new _BirdDots(winterParams);

        initChart(_season, initStats);
        ready = true;
        if (onLoad) {
          onLoad();
        }
      });

      function initChart(season, initStats) {
        var plot = void 0;
        if (season === 'summer') {
          d3.select(winterDots.svg).style('opacity', 0);
          d3.select(summerDots.svg).style('opacity', 1);
          plot = summerDots;
        } else {
          d3.select(winterDots.svg).style('opacity', 1);
          d3.select(summerDots.svg).style('opacity', 0);
          plot = winterDots;
        }
        if (initStats) {
          d3.select(colonizedCounter).text(plot.numColonized);
          d3.select(extirpatedCounter).text(plot.numExtirpated);
          d3.select(currentCounter).text(plot.numCurrent);
        }
      }

      function _animateIn(onFinished) {
        // should be called after ready to be inited
        var plot = void 0;
        if (_season === 'summer') {
          plot = summerDots;
        } else {
          plot = winterDots;
        }

        d3.select(currentCounter).text(plot.numCurrent);
        animateCount(d3.select(colonizedCounter), 0, plot.numColonized, 1200);
        plot.enterColonized(function () {
          animateCount(d3.select(extirpatedCounter), 0, plot.numExtirpated, 1200);
          plot.enterExtirpated(function () {
            if (onFinished) {
              setTimeout(function () {
                return onFinished();
              }, 1000);
            }
          });
        });
      }

      function animateIn(onFinished) {
        if (ready) {
          _animateIn(onFinished);
        }
      }

      function fadeOut(el) {
        el.transition().duration(200).ease(d3.easeQuadOut).style('opacity', 0);
      }

      function fadeIn(el) {
        el.transition().duration(200).delay(200).ease(d3.easeQuadOut).style('opacity', 1);
      }

      function setSeason(season) {
        if (season === _season) {
          return;
        }

        _season = season;

        if (!ready) {
          return;
        }

        if (season === 'summer') {
          d3.select(winterDots.svg).call(fadeOut);
          d3.select(summerDots.svg).call(fadeIn);

          d3.select(colonizedCounter).text(summerDots.numColonized);
          d3.select(extirpatedCounter).text(summerDots.numExtirpated);
          d3.select(currentCounter).text(summerDots.numCurrent);
        } else {
          d3.select(summerDots.svg).call(fadeOut);
          d3.select(winterDots.svg).call(fadeIn);

          d3.select(colonizedCounter).text(winterDots.numColonized);
          d3.select(extirpatedCounter).text(winterDots.numExtirpated);
          d3.select(currentCounter).text(winterDots.numCurrent);
        }
      }

      function setExtirpated() {
        if (!ready) {
          return;
        }

        summerDots.setExtirpated();
        winterDots.setExtirpated();
      }

      function setCurrent() {
        if (!ready) {
          return;
        }

        summerDots.setCurrent();
        winterDots.setCurrent();
      }

      function setColonized() {
        if (!ready) {
          return;
        }

        summerDots.setColonized();
        winterDots.setColonized();
      }

      return {
        animateIn: animateIn,
        setSeason: setSeason,
        setExtirpated: setExtirpated,
        setColonized: setColonized,
        setCurrent: setCurrent
      };
    }

    var BirdDotsBase = _BirdDots;
    exports.BirdDots = BirdDots;
    exports.BirdDotsBase = BirdDotsBase;
    exports.animateCount = animateCount;
    exports.GridHelper = GridHelper;

  },{}],4:[function(require,module,exports){
    'use strict';

    Object.defineProperty(exports, "__esModule", {
      value: true
    });
    exports.BirdDotLandingPage = undefined;

    var _birdDot = require('./birdDot.js');

    var IMAGES = {
      warbler: 'https://cdn.audubon.org/cdn/farfuture/QXLRxSQ0fsFVg21PtuqO6mIIvK95QgxoN_SjCvzIMoA/mtime:1521226106/sites/default/files/warbler2x.png',
      woodpecker: 'https://cdn.audubon.org/cdn/farfuture/tvgoJvfO0kde2YONgbDP9F0j3cT7tCLK6q1ls4gvU3Y/mtime:1521226140/sites/default/files/woodpecker2x.png',
      egret: 'https://cdn.audubon.org/cdn/farfuture/LtoTf_npOfC97ueXh_0hTMwkM00dnVqRMKgFbuq1n00/mtime:1521226174/sites/default/files/egret2x.png',
      grosbeak: 'https://cdn.audubon.org/cdn/farfuture/9DxKUfcw7ys35Gyo6y-SZ9xUd20M0e_2E5KyVrodNzk/mtime:1521226340/sites/default/files/grosbeak2x.png',
      robin: 'https://cdn.audubon.org/cdn/farfuture/wc3xlbflO97Iouy2ujzLGa6x5TsdvzxNv4sZOHzfIyU/mtime:1521226379/sites/default/files/robin2x.png'
    };

    function BirdDotLandingPage(params) {
      var element = params.element;

      var node = d3.select(element).append('div').classed('bird-dot-landing-page', true);

      var row = node.append('div').classed('counter-row', true);

      var birdDots = new _birdDot.BirdDotsBase({
        element: node.node(),
        scale: 2.5,
        numCurrent: 83,
        numColonized: 13,
        numExtirpated: 20,
        numCols: 5
      });

      // this is in the reference frame of the existing dots
      var svg = d3.select(birdDots.svg).select('g');

      var currentCounter = row.append('div').classed('counter', true).classed('current-counter', true).html('\n      <p>Species currently in the park</p>\n      <h2>83</h2>\n    ');

      var colonizedCounter = row.append('div').classed('counter', true).classed('colonized-counter', true).style('opacity', 0).html('\n      <p>Potential colonization</p>\n      <h2>0</h2>\n    ');

      var extirpatedCounter = row.append('div').classed('counter', true).classed('extirpated-counter', true).style('opacity', 0).html('\n      <p>Potential extirpation</p>\n      <h2>0</h2>\n    ');

      var calloutG = svg.append('g').attr('class', 'bird-callouts');

      var calloutDistance = 70;
      var calloutRadius = 47;

      function drawCallout(n, initial, name, image, classtype, leftOrRight) {
        var pos = initial ? birdDots.data[n - 1].initPos : birdDots.data[n - 1].finalPos;
        var target = svg.select('.dot:nth-child(' + n + ')');

        var side = leftOrRight == 'left' ? 1 : -1;

        var callout = calloutG.append('g').classed('bird-callout', true).classed(classtype, true).attr('transform', 'translate(' + (pos.x - side * calloutDistance) + ', ' + pos.y + ')').attr('opacity', 0);

        callout.append('circle').attr('cx', 0).attr('cy', 0).attr('r', calloutRadius);

        callout.append('clipPath').attr('id', 'bird-callout-clip-path').append('circle').attr('cx', 0).attr('cy', 0).attr('r', calloutRadius);

        callout.append('image').attr('class', 'bird-callout-image').attr('x', -47).attr('y', -47).attr('height', 95).attr('width', 95).attr('clip-path', function (d, i) {
          return 'url(#bird-callout-clip-path)';
        }).attr('xlink:href', image);

        callout.append('text').attr('x', 0).attr('y', calloutRadius + 16).attr('text-anchor', 'middle').text(name);

        callout.append('line').attr('x1', side * calloutRadius).attr('y1', 0).attr('x2', -side * target.attr('r') + side * calloutDistance).attr('y2', 0);

        return callout;
      }

      function fadeIn(element) {
        element.transition().duration(1000).attr('opacity', 1);
      }

      function fadeOut(element) {
        element.transition().duration(600).attr('opacity', 0);
      }

      drawCallout(32, true, 'Great Egret', IMAGES.egret, 'current', 'left').call(fadeIn);
      drawCallout(46, true, "Nutall's Woodpecker", IMAGES.woodpecker, 'current', 'right').call(fadeIn);
      drawCallout(72, true, "Wilson's Warbler", IMAGES.warbler, 'current', 'left').call(fadeIn);

      var robin = drawCallout(86, true, "American Robin", IMAGES.robin, 'current', 'right').call(fadeIn);

      // draw the grosbeak where it will be
      var birdPos = birdDots.data[6].finalPos;
      var grosbeak = drawCallout(6, false, "Blue Grosbeak", IMAGES.grosbeak, 'colonized', 'right').attr('opacity', 0);

      function showCurrent() {
        currentCounter.transition().delay(200).duration(400).style('opacity', 1);

        colonizedCounter.transition().duration(300).style('opacity', 0);

        extirpatedCounter.transition().duration(300).style('opacity', 0);

        birdDots.setCurrent();
        grosbeak.call(fadeOut);
        var birdPos = birdDots.data[85].initPos;
        robin.classed('current', true);
        robin.transition().duration(1000).attr('transform', 'translate(' + (birdPos.x + calloutDistance) + ', ' + birdPos.y + ')');
      }

      function showLater() {
        currentCounter.transition()
        // .delay(200)
          .duration(400).style('opacity', 0);

        colonizedCounter.select('h2').text(0);
        extirpatedCounter.select('h2').text(0);
        colonizedCounter.transition().duration(300).delay(100).style('opacity', 1);

        extirpatedCounter.transition().duration(300).delay(100).style('opacity', 1);

        (0, _birdDot.animateCount)(colonizedCounter.select('h2'), 0, 13, 1500);

        birdDots.enterColonized(function () {
          grosbeak.transition().duration(1000).attr('opacity', 1);

          setTimeout(function () {
            (0, _birdDot.animateCount)(extirpatedCounter.select('h2'), 0, 20, 1000);
            var birdPos = birdDots.data[85].finalPos;
            robin.classed('current', false);
            robin.transition().duration(1000).attr('transform', 'translate(' + (birdPos.x + calloutDistance) + ', ' + birdPos.y + ')');

            robin.select('line').attr('stroke', '#90d2d8').transition().duration(1000).attr('stroke', '#e8c578');
            // .attr('opacity', 1);

            robin.select('circle').attr('stroke', '#90d2d8').attr('fill', '#90d2d8').transition().duration(1000).attr('stroke', '#e8c578').attr('fill', '#e8c578');

            birdDots.enterExtirpated();
          }, 1000);
        });
      }

      return {
        showCurrent: showCurrent,
        showLater: showLater
      };
    }

    exports.BirdDotLandingPage = BirdDotLandingPage;

  },{"./birdDot.js":3}],5:[function(require,module,exports){
    'use strict';

    var _birdDot = require('./birdDot.js');

    var _birdDotLandingPage = require('./birdDotLandingPage.js');

    var _turnover = require('./turnover.js');

    var _parkMap = require('./parkMap.js');

    var _allParks = require('./allParks.js');

    window.StamenAudubonParks = {
      BirdDotsBase: _birdDot.BirdDotsBase,
      BirdDots: _birdDot.BirdDots,
      BirdDotLandingPage: _birdDotLandingPage.BirdDotLandingPage,
      ParkMap: _parkMap.ParkMap,
      TurnoverChart: _turnover.TurnoverChart,
      AllParks: _allParks.AllParks
    };

  },{"./allParks.js":2,"./birdDot.js":3,"./birdDotLandingPage.js":4,"./parkMap.js":6,"./turnover.js":7}],6:[function(require,module,exports){
    "use strict";

    Object.defineProperty(exports, "__esModule", {
      value: true
    });
    exports.ParkMap = undefined;

    var _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();

    var _albersBigAlaska = require("./albersBigAlaska");

    function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

    /*
      Park Map

      element
      season 'summer' or 'winter'
      metric
      shapeUrl: path to the us boundaries dataset
      dataUrl: path to the colonization / extirpation .csv

    */

// this can be brought into the class
    function drawParks(parks, g, colorScale, sizeScale, projection, selection) {

      var parkCircles = g.selectAll(".sd-parkcircle").data(parks, function (d) {
        return d.park;
      });

      parkCircles.exit().remove();
      parkCircles.enter().append("circle").classed("sd-parkcircle", true).merge(parkCircles).attr("transform", function (d) {
        return "translate(" + projection([+d.long, +d.lat]) + ")";
      }).classed('hover', function (d) {
        return d.unit_name === selection;
      }).on("mouseover", function (d) {}).on("mouseout", function (d) {}).transition().attr("r", sizeScale).style("fill", colorScale).style("mix-blend-mode", "normal").style('stroke', colorScale);
    }

    var Wand = function () {
      function Wand(svg, size) {
        _classCallCheck(this, Wand);

        var wand = svg.append('g').classed('wand', true);
        wand.append('circle').attr('cx', 0).attr('cy', -size).attr('r', 2);
        wand.append('line').attr('x1', 0).attr('y1', 0).attr('x2', 0).attr('y2', -size);

        this.wand = wand;
      }

      _createClass(Wand, [{
        key: "hide",
        value: function hide() {
          this.wand.classed('hidden', true);
        }
      }, {
        key: "move",
        value: function move(pt) {
          this.wand.classed('hidden', false);
          this.wand.attr('transform', "translate(" + pt[0] + ", " + pt[1] + ")");
        }
      }]);

      return Wand;
    }();

    function ParkMap(params) {
      var element = params.element,
        season = params.season,
        metric = params.metric,
        shapeUrl = params.shapeUrl,
        dataUrl = params.dataUrl,
        onClick = params.onClick;


      var _element = d3.select(element).append('div').classed('sd-map', true);

      var tooltip = _element.append('div').classed('sd-tooltip', true).classed('hidden', true).classed('down', false).html("\n                    <h2 class=\"title\">Name</h2>\n                    <div>\n                      <svg class=\"sd-arrow\" id=\"Layer_1\" width=\"18\" height=\"22.5\" data-name=\"Layer 1\" xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 18.7 22.5\"><polygon class=\"sd-arrow-icon\" points=\"6.34 14.26 6.34 22.5 6.97 22.5 11.72 22.5 12.36 22.5 12.36 14.26 18.7 14.26 9.35 0 0 14.26 6.34 14.26\"/></svg>\n                      <h2 class=\"number\">34</h2>\n                      <p class=\"label\">Extirpations</p>\n                    </div>\n                  ");

      tooltip.select('.title').on('click', function () {
        d3.event.preventDefault();
        if (onClick) {
          onClick(tooltip.select('.title').text());
        }
      });

      var width = d3.select(element).node().offsetWidth;
      var height = width * 703 / 1106;

      var svg = _element.append("svg").attr('width', width).attr('height', height);

      var background_g = svg.append("g").attr("id", "background_g");
      var foreground_g = svg.append("g").attr("id", "foreground_g");
      var parkGroup = foreground_g.append("g").attr("class", "parkCircles");

      var touchOffsetY = 50;
      var wand = new Wand(foreground_g, touchOffsetY);

      var projection = void 0;

      var tooltipNumber = void 0;
      var colonColor = d3.scaleLinear().range(['#18a1ad', '#18a1ad']);

      var colonSize = d3.scaleSqrt();

      var extirpColor = d3.scaleLinear().range(['#e8c578', '#e8c578']);

      var extirpSize = d3.scaleSqrt();

      var _season = season;
      var _metric = metric;
      var _parks = void 0;
      var _states = void 0;

      var selection = void 0;

      function render() {
        var colorScale = void 0,
          sizeScale = void 0;
        var tooltipLabel = "Potential " + _metric + "s in " + _season;
        tooltip.select('.label').text(tooltipLabel);

        if (_season == 'summer' && _metric == 'colonization') {

          colorScale = function colorScale(d) {
            return colonColor(d['no_colonizations_summer']);
          };
          sizeScale = function sizeScale(d) {
            return colonSize(d['no_colonizations_summer']);
          };
          tooltipNumber = function tooltipNumber(d) {
            return d['no_colonizations_summer'];
          };
          tooltip.classed('down', false);
        } else if (_season == 'summer' && _metric == 'extirpation') {

          colorScale = function colorScale(d) {
            return extirpColor(d['no_extirpations_summer']);
          };
          sizeScale = function sizeScale(d) {
            return extirpSize(d['no_extirpations_summer']);
          };
          tooltipNumber = function tooltipNumber(d) {
            return d['no_extirpations_summer'];
          };
          tooltip.classed('down', true);
        } else if (_season == 'winter' && _metric == 'colonization') {

          colorScale = function colorScale(d) {
            return colonColor(d['no_colonizations_winter']);
          };
          sizeScale = function sizeScale(d) {
            return colonSize(d['no_colonizations_winter']);
          };
          tooltipNumber = function tooltipNumber(d) {
            return d['no_colonizations_winter'];
          };
          tooltip.classed('down', false);
        } else if (_season == 'winter' && _metric == 'extirpation') {

          colorScale = function colorScale(d) {
            return extirpColor(d['no_extirpations_winter']);
          };
          sizeScale = function sizeScale(d) {
            return extirpSize(d['no_extirpations_winter']);
          };
          tooltipNumber = function tooltipNumber(d) {
            return d['no_extirpations_winter'];
          };
          tooltip.classed('down', true);
        }

        drawParks(_parks, parkGroup, colorScale, sizeScale, projection, selection);
      }

      function redraw() {

        var width = _element.node().offsetWidth;
        var height = width * 703 / 1106;

        svg.attr('width', width).attr('height', height);

        var mapPadding = 40 * width / 1106;;
        projection = (0, _albersBigAlaska.albersBigAlaska)().fitExtent([[0 + mapPadding, 0 + mapPadding], [width - mapPadding, height - mapPadding]], {
          type: 'FeatureCollection',
          features: _states
        });

        // draw base layer
        var statesPath = background_g.selectAll("path").data(_states);
        statesPath.enter().append("path").merge(statesPath).attr("d", d3.geoPath(projection)).style("fill", "#e5e5e5").style("stroke", function (d) {
          return d.properties.postal === 'AK' ? "#d8d8d8" : "white";
        });

        // compute the domains
        var colonRange = d3.extent(_parks.map(function (d) {
          return d['no_colonizations_summer'];
        }).concat(_parks.map(function (d) {
          return d['no_colonizations_winter'];
        })));

        var extirpRange = d3.extent(_parks.map(function (d) {
          return d['no_extirpations_summer'];
        }).concat(_parks.map(function (d) {
          return d['no_extirpations_winter'];
        })));

        var minRadius = 2 / 320 * width;
        var maxRadius = 13 / 320 * width;

        colonColor.domain(colonRange);
        colonSize.domain(colonRange).range([minRadius, maxRadius]);
        extirpColor.domain(extirpRange);
        extirpSize.domain(extirpRange).range([minRadius, maxRadius]);

        var points = _parks.map(function (p) {
          return projection([+p.long, +p.lat]);
        });

        var _v = d3.voronoi()
        //pixel space
          .x(function (d) {
            return projection([+d.long, +d.lat])[0];
          }).y(function (d) {
            return projection([+d.long, +d.lat])[1];
          })(_parks);

        function hitDetector(p, offsetY) {
          offsetY = offsetY || 0;
          var maxDistanceFromPoint = 20;
          return _v.find(p[0], p[1] - offsetY, maxDistanceFromPoint);
        }

        var focused = false;

        function highlight(parkNode) {
          if (parkNode) {

            selection = parkNode.data.unit_name;
            render();

            tooltip.classed('hidden', false);
            tooltip.select('.title').text(parkNode.data.unit_name);
            tooltip.select('.number').text(tooltipNumber(parkNode.data));

            var dx = tooltip.node().clientWidth / 2;
            var dy = parkNode[1] - tooltip.node().clientHeight - 5; // a bit off center
            dx = parkNode[0] - dx;

            tooltip.style('left', dx + 'px');
            tooltip.style('top', dy + 'px');

            // snap to the window
            var rect = tooltip.node().getBoundingClientRect();
            var maxWidth = window.innerWidth;

            if (rect.x < 0) {
              dx -= rect.x;
            } else if (rect.x + rect.width > maxWidth) {
              dx = maxWidth - rect.width;
            }

            tooltip.style('left', dx + 'px');
            tooltip.style('top', dy + 'px');
          } else {
            tooltip.classed('hidden', true);
            selection = null;
            render();
          }
        }

        svg.on('click', function () {
          var park = hitDetector(d3.mouse(this));
          highlight(park);
          focused = park != null;
        });

        svg.on('touchmove', function (e) {
          wand.move(d3.touches(this)[0]);
          var park = hitDetector(d3.touches(this)[0], touchOffsetY);
          highlight(park);
          d3.event.preventDefault();
        });
        svg.on('touchend', function (e) {
          wand.hide();
        });
        svg.on('mousemove', function () {
          if (!focused) {
            var park = hitDetector(d3.mouse(this));
            highlight(park);
          }
        });

        render();
      } //end init

      function setParams(season, metric) {
        _season = season;
        _metric = metric;
        render();
      }

      //load the data
      d3.queue().defer(d3.json, shapeUrl).defer(d3.csv, dataUrl).awaitAll(function (error, results) {

        var states = results[0];
        var parks = results[1];

        // typecast
        parks.forEach(function (park) {
          park.park = park.park;
          park.unit_name = park.unit_name;
          park.nps_region = park.nps_region;
          park.turnover_summer = +park.turnover_summer;
          park.turnover_winter = +park.turnover_winter;
          park.long = +park.long;
          park.lat = +park.lat;
          park.current_no_species_summer = +park.no_species_summer;
          park.current_no_species_winter = +park.no_species_winter;
          park.prop_colonizations_summer = +park.prop_colonizations_summer;
          park.prop_colonizations_winter = +park.prop_colonizations_winter;
          park.prop_extirpations_winter = +park.prop_extirpations_winter;
          park.prop_extirpations_summer = +park.prop_extirpations_summer;
          park.no_extirpations_summer = +park.no_extirpations_summer;
          park.no_extirpations_winter = +park.no_extirpations_winter;
          park.no_colonizations_summer = +park.no_colonizations_summer;
          park.no_colonizations_winter = +park.no_colonizations_winter;
        });

        // get rid of hawaii
        states = states.features.filter(function (d) {
          return d.properties.adm0_a3 == 'USA' && d.properties.postal != 'HI';
        });

        _parks = parks;
        _states = states;

        redraw();

        window.addEventListener("resize", redraw);
      });

      return {
        setParams: setParams
      };
    }

    exports.ParkMap = ParkMap;

  },{"./albersBigAlaska":1}],7:[function(require,module,exports){
    'use strict';

    Object.defineProperty(exports, "__esModule", {
      value: true
    });
    function formatTurnover(d) {
      return Math.round(d * 100) + '%';
    }

    function centerOnX(element, x) {
      // positions an element on x relative to its parent
      // snaps the element to the boundaries of the parent

      var width = element.node().offsetWidth;
      var maxWidth = element.node().parentNode.offsetWidth;

      x = x - width / 2;

      // snap to the window
      if (x < 0) {
        x = 0;
      } else if (x + width > maxWidth) {
        x = maxWidth - width;
      }

      element.style('left', x + 'px');
    }

    function DotChart(params) {
      var element = params.element,
        showName = params.showName,
        onHover = params.onHover,
        onClick = params.onClick,
        scale = params.scale;


      var _data = [];
      var hitDetector = void 0;
      var height = 90;

      var RADIUS = 6;
      var SELECTED_RADIUS = 13;
      var dotCenter = height - 6 - SELECTED_RADIUS;
      var margin = {
        top: 0,
        left: 20
      };
      var x = void 0;

      var svg = element.append('svg').append('g').attr('transform', 'translate(' + margin.left + ', ' + margin.top + ')');

      svg.append('rect').attr('class', 'overlay').attr('height', height).attr('x', 0).attr('y', 0).attr('fill-opacity', 0.0);

      var focus = element.append('div').classed('sd-turnover-tooltip', true).classed('hidden', true);
      var permaFocus = element.append('div').classed('sd-perma-tooltip', true);
      var field = void 0;

      function redraw(data, _field, selected) {
        // copy over the array
        field = _field;
        _data = data.slice();

        // sort in ascending value
        _data.sort(function (a, b) {
          return d3.ascending(a[field], b[field]);
        });

        // size the svg
        var width = element.node().offsetWidth;
        element.style('height', height + 'px');
        element.select('svg').attr('width', width).attr('height', height);

        // this scale is now independent

        var _x = void 0;
        if (scale == 'log') {
          _x = d3.scaleLog().range([0, width - 2 * margin.left]).clamp(true);
          var domain = d3.extent(data, function (d) {
            return d[field] * 100;
          });
          domain[0] = Math.max(1, domain[0]);
          _x.domain(domain);
        } else {
          _x = d3.scaleLinear().range([0, width - 2 * margin.left]).clamp(true);
          _x.domain(d3.extent(data, function (d) {
            return d[field] * 100;
          }));
        }

        x = function x(d) {
          return _x(d[field] * 100);
        };

        // console.log('x', _x.domain(), _x.range());

        var selectedData = _data.find(function (d) {
          return d.unit_name == selected;
        });

        // render the selection
        var selectedDots = svg.selectAll('.sd-selected-dot').data([selectedData]);
        selectedDots.enter().append('circle').classed('sd-selected-dot', true).merge(selectedDots).attr('cx', x).attr('cy', dotCenter).attr('r', SELECTED_RADIUS);

        // render the other parks
        var otherParks = _data.filter(function (d) {
          return d.unit_name != selected;
        });
        // console.log('otherparks', otherParks);
        var dots = svg.selectAll('.sd-dot').data(otherParks);
        dots.enter().append('circle').classed('sd-dot', true).merge(dots).classed('selected', function (d) {
          return d.unit_name === selected;
        }).attr('cx', x).attr('cy', dotCenter).attr('r', RADIUS);

        hitDetector = d3.voronoi().x(x).y(0)(otherParks);

        // hit detector overlay
        var overlay = svg.select('.overlay').attr('width', width).on('mouseover', mousemove).on('mouseout', function (d) {
          return onHover();
        }).on('mousemove', mousemove).on('touchmove', touchmove).on('click', mouseclick);

        // labels
        var permaLabel = '';
        if (showName) {
          permaLabel = selectedData.unit_name + ' ';
        }
        permaLabel += formatTurnover(selectedData[field]);
        permaFocus.text(permaLabel);

        var dy = dotCenter - SELECTED_RADIUS * 3 - 10 + margin.top;
        permaFocus.style('top', dy + 'px');

        centerOnX(permaFocus, x(selectedData) + margin.left);

        dy = dotCenter - RADIUS * 3 - 14 + margin.top;
        focus.style('top', dy + 'px');
      }

      function clearHover() {
        svg.selectAll(".sd-dot").classed("hovered", false);

        // clear focus
        focus.classed('hidden', true);
      }

      function renderHover(name) {
        // render hover state
        // console.log('renderHover for', element.node().id);
        var obj = _data.find(function (d) {
          return d.unit_name === name;
        });
        if (!obj) {
          // console.log("OH NO can't find", name);
          return;
        }
        svg.selectAll(".sd-dot").classed("hovered", function (d) {
          return d.unit_name === obj.unit_name;
        });

        // format the focus
        var text = '';
        if (showName) {
          text = obj.unit_name + ' ';
        }
        text += formatTurnover(obj[field]);
        focus.text(text);
        focus.classed('hidden', false);

        centerOnX(focus, x(obj) + margin.left);
        // move to top
        var hovered = svg.select('.hovered').node();
        hovered.parentElement.appendChild(hovered);
      }

      function touchmove() {
        var mouseX = d3.touches(this)[0][0];
        var found = hitDetector.find(mouseX, 0, 20);

        if (found) {
          found = found.data;
          // console.log('found hover', found);
          onHover(found.unit_name);
        } else {
          onHover();
        }
      }

      function mousemove() {
        var mouseX = d3.mouse(this)[0];
        var found = hitDetector.find(mouseX, 0, 20);

        if (found) {
          found = found.data;
          // console.log('found hover', found);
          onHover(found.unit_name);
        } else {
          onHover();
        }
      }

      function mouseclick() {
        var mouseX = d3.mouse(this)[0];
        var found = hitDetector.find(mouseX, 0, 20);

        if (found) {
          if (onClick) {
            onClick(found.data.unit_name);
          }
        }
      }

      return {
        redraw: redraw,
        highlight: renderHover,
        clearHighlight: clearHover
      };
    }

    function TurnoverChart(params) {
      var element = params.element,
        dataUrl = params.dataUrl,
        park = params.park,
        onClick = params.onClick,
        season = params.season;

      var _season = season || 'summer';

      element = d3.select(element);

      // create the template
      element.html('\n        <div class="sd-turnover-chart">\n            <div class="sd-dot-chart">\n                <div id="sd-mainchart"></div>\n                <div class="sd-line"></div>\n                <div class="sd-label-area">\n                    <h2 class="sd-axis-label">Potential Turnover</h2>\n                </div>\n            </div>\n            <div>\n                <div class="sd-subrow sd-left">\n                    <div class="sd-dot-chart">\n                        <div id="sd-subchart-1"></div>\n                        <div class="sd-line"></div>\n                        <div class="sd-label-area">\n                            <h2 class="sd-axis-label">Potential Colonization</h2>\n                        </div>\n                    </div>\n                </div>\n                <div class="sd-subrow sd-right">\n                    <div class="sd-dot-chart">\n                        <div id="sd-subchart-2"></div>\n                        <div class="sd-line"></div>\n                        <div class="sd-label-area">\n                            <h2 class="sd-axis-label">Potential Extirpation</h2>\n                        </div>\n                    </div>\n                </div>\n            </div>\n        </div>\n    ');

      var data = [];
      var mainChart = new DotChart({
        element: element.select('#sd-mainchart'),
        showName: true,
        onClick: onClick,
        onHover: onHover,
        scale: 'linear'
      });
      var subChart1 = new DotChart({
        element: element.select('#sd-subchart-1'),
        showName: false,
        onClick: onClick,
        onHover: onHover,
        scale: 'log'
      });
      var subChart2 = new DotChart({
        element: element.select('#sd-subchart-2'),
        showName: false,
        onClick: onClick,
        onHover: onHover,
        scale: 'log'
      });

      function onHover(name) {
        if (!name) {
          mainChart.clearHighlight();
          subChart1.clearHighlight();
          subChart2.clearHighlight();
          return;
        }

        mainChart.highlight(name);
        subChart1.highlight(name);
        subChart2.highlight(name);
      }

      function redraw() {
        mainChart.redraw(data, 'turnover_' + _season, park);
        subChart1.redraw(data, 'prop_colonizations_' + _season, park);
        subChart2.redraw(data, 'prop_extirpations_' + _season, park);
      }

      function setSeason(season) {
        if (season === 'summer' || season === 'winter') {
          _season = season;
          redraw();
        } else {
          console.log('ERROR: season must be summer or winter, received', season);
        }
      }

      d3.csv(dataUrl, function (error, rows) {
        console.log(error);

        // preprocess
        rows.forEach(function (r) {
          r.prop_colonizations_summer = +r.prop_colonizations_summer;
          r.prop_colonizations_winter = +r.prop_colonizations_winter;
          r.prop_extirpations_summer = +r.prop_extirpations_summer;
          r.prop_extirpations_winter = +r.prop_extirpations_winter;
          r.turnover_summer = +r.turnover_summer;
          r.turnover_winter = +r.turnover_winter;
        });

        // console.log(rows);
        data = rows;

        redraw();
        window.addEventListener("resize", redraw);
      });

      return {
        setSeason: setSeason
      };
    }

    exports.TurnoverChart = TurnoverChart;


  },{}]},{},[5]);
//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbIm5vZGVfbW9kdWxlcy9icm93c2VyLXBhY2svX3ByZWx1ZGUuanMiLCJqcy9hbGJlcnNCaWdBbGFza2EuanMiLCJqcy9hbGxQYXJrcy5qcyIsImpzL2JpcmREb3QuanMiLCJqcy9iaXJkRG90TGFuZGluZ1BhZ2UuanMiLCJqcy9pbmRleC5qcyIsImpzL3BhcmtNYXAuanMiLCJqcy90dXJub3Zlci5qcyJdLCJuYW1lcyI6W10sIm1hcHBpbmdzIjoiQUFBQTs7Ozs7O1FDNkZnQixlLEdBQUEsZTtBQTdGaEI7QUFDQTtBQUNBOztBQUVBLElBQUksWUFBWSxJQUFoQjtBQUNBLFNBQVMsTUFBVCxHQUFrQixDQUFFO0FBQ3BCLElBQUksT0FBTyxRQUFYO0FBQ0EsSUFBSSxPQUFPLElBQVg7QUFDQSxJQUFJLEtBQUssQ0FBQyxJQUFWO0FBQ0EsSUFBSSxLQUFLLEVBQVQ7O0FBRUEsSUFBSSxpQkFBaUI7QUFDbkIsU0FBTyxhQURZO0FBRW5CLGFBQVcsTUFGUTtBQUduQixXQUFTLE1BSFU7QUFJbkIsZ0JBQWMsTUFKSztBQUtuQixjQUFZLE1BTE87QUFNbkIsVUFBUSxrQkFBVztBQUNqQixRQUFJLFNBQVMsQ0FBQyxDQUFDLElBQUQsRUFBTyxJQUFQLENBQUQsRUFBZSxDQUFDLEVBQUQsRUFBSyxFQUFMLENBQWYsQ0FBYjtBQUNBLFNBQUssS0FBSyxFQUFFLE9BQU8sT0FBTyxRQUFoQixDQUFWO0FBQ0EsV0FBTyxNQUFQO0FBQ0Q7QUFWa0IsQ0FBckI7O0FBYUEsU0FBUyxhQUFULENBQXVCLENBQXZCLEVBQTBCLENBQTFCLEVBQTZCO0FBQzNCLE1BQUksSUFBSSxJQUFSLEVBQWMsT0FBTyxDQUFQO0FBQ2QsTUFBSSxJQUFJLEVBQVIsRUFBWSxLQUFLLENBQUw7QUFDWixNQUFJLElBQUksSUFBUixFQUFjLE9BQU8sQ0FBUDtBQUNkLE1BQUksSUFBSSxFQUFSLEVBQVksS0FBSyxDQUFMO0FBQ2I7O0FBRUQsU0FBUyxHQUFULENBQWEsVUFBYixFQUF5QixTQUF6QixFQUFv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U0FQRDs7QUFTQTtBQUNBLGVBQU8sSUFBUDs7QUFFQTtBQUNBLGVBQU8sZ0JBQVAsQ0FBd0IsUUFBeEIsRUFBa0MsTUFBbEM7QUFDSCxLQWxCRDs7QUFvQkEsV0FBTztBQUNILG1CQUFXO0FBRFIsS0FBUDtBQUdIOztRQUVRLGEsR0FBQSxhIiwiZmlsZSI6ImdlbmVyYXRlZC5qcyIsInNvdXJjZVJvb3QiOiIiLCJzb3VyY2VzQ29udGVudCI6WyIoZnVuY3Rpb24oKXtmdW5jdGlvbiBlKHQsbixyKXtmdW5jdGlvbiBzKG8sdSl7aWYoIW5bb10pe2lmKCF0W29dKXt2YXIgYT10eXBlb2YgcmVxdWlyZT09XCJmdW5jdGlvblwiJiZyZXF1aXJlO2lmKCF1JiZhKXJldHVybiBhKG8sITApO2lmKGkpcmV0dXJuIGkobywhMCk7dmFyIGY9bmV3IEVycm9yKFwiQ2Fubm90IGZpbmQgbW9kdWxlICdcIitvK1wiJ1wiKTt0aHJvdyBmLmNvZGU9XCJNT0RVTEVfTk9UX0ZPVU5EXCIsZn12YXIgbD1uW29dPXtleHBvcnRzOnt9fTt0W29dWzBdLmNhbGwobC5leHBvcnRzLGZ1bmN0aW9uKGUpe3ZhciBuPXRbb11bMV1bZV07cmV0dXJuIHMobj9uOmUpfSxsLGwuZXhwb3J0cyxlLHQsbixyKX1yZXR1cm4gbltvXS5leHBvcnRzfXZhciBpPXR5cGVvZiByZXF1aXJlPT1cImZ1bmN0aW9uXCImJnJlcXVpcmU7Zm9yKHZhciBvPTA7bzxyLmxlbmd0aDtvKyspcyhyW29dKTtyZXR1cm4gc31yZXR1cm4gZX0pKCkiLCIvLyBsb3RzIG9mIHN0dWZmIGhhcnZlc3RlZCBmcm9tIGQzLmpzXG4vLyBvbmx5IHJlYWwgZGlmZmVyZW5jZSBpcyByb3RhdGlvbiAvIHNjYWxlIC8gY2xpcHBwaW5nIGFuZCB0cmFuc2xhdGlvbiBvZlxuLy8gdGhlIGFsYXNrYSBwb3J0aW9uIG9mIGFsYmVyc1VzYVxuXG52YXIgZXBzaWxvbiQyID0gMWUtNjtcbmZ1bmN0aW9uIG5vb3AkMSgpIHt9XG52YXIgeDAkMiA9IEluZmluaXR5O1xudmFyIHkwJDIgPSB4MCQyO1xudmFyIHgxID0gLXgwJDI7XG52YXIgeTEgPSB4MTtcblxudmFyIGJvdW5kc1N0cmVhbSQxID0ge1xuICBwb2ludDogYm91bmRzUG9pbnQkMSxcbiAgbGluZVN0YXJ0OiBub29wJDEsXG4gIGxpbmVFbmQ6IG5vb3AkMSxcbiAgcG9seWdvblN0YXJ0OiBub29wJDEsXG4gIHBvbHlnb25FbmQ6IG5vb3AkMSxcbiAgcmVzdWx0OiBmdW5jdGlvbigpIHtcbiAgICB2YXIgYm91bmRzID0gW1t4MCQyLCB5MCQyXSwgW3gxLCB5MV1dO1xuICAgIHgxID0geTEgPSAtKHkwJDIgPSB4MCQyID0gSW5maW5pdHkpO1xuICAgIHJldHVybiBib3VuZHM7XG4gIH1cbn07XG5cbmZ1bmN0aW9uIGJvdW5kc1BvaW50JDEoeCwgeSkge1xuICBpZiAoeCA8IHgwJDIpIHgwJDIgPSB4O1xuICBpZiAoeCA+IHgxKSB4MSA9IHg7XG4gIGlmICh5IDwgeTAkMikgeTAkMiA9IHk7XG4gIGlmICh5ID4geTEpIHkxID0geTtcbn1cblxuZnVuY3Rpb24gZml0KHByb2plY3Rpb24sIGZpdEJvdW5kcywgb2JqZWN0KSB7XG4gIHZhciBjbGlwID0gcHJvamVjdGlvbi5jbGlwRXh0ZW50ICYmIHByb2plY3Rpb24uY2xpcEV4dGVudCgpO1xuICBwcm9qZWN0aW9uLnNjYWxlKDE1MCkudHJhbnNsYXRlKFswLCAwXSk7XG4gIGlmIChjbGlwICE9IG51bGwpIHByb2plY3Rpb24uY2xpcEV4dGVudChudWxsKTtcbiAgZDMuZ2VvU3RyZWFtKG9iamVjdCwgcHJvamVjdGlvbi5zdHJlYW0oYm91bmRzU3RyZWFtJDEpKTtcbiAgZml0Qm91bmRzKGJvdW5kc1N0cmVhbSQxLnJlc3VsdCgpKTtcbiAgaWYgKGNsaXAgIT0gbnVsbCkgcHJvamVjdGlvbi5jbGlwRXh0ZW50KGNsaXApO1xuICByZXR1cm4gcHJvamVjdGlvbjtcbn1cblxuZnVuY3Rpb24gZml0RXh0ZW50KHByb2plY3Rpb24sIGV4dGVudCwgb2JqZWN0KSB7XG4gIHJldHVybiBmaXQocHJvamVjdGlvbiwgZnVuY3Rpb24oYikge1xuICAgIHZhciB3ID0gZXh0ZW50WzFdWzBdIC0gZXh0ZW50WzBdWzBdLFxuICAgICAgICBoID0gZXh0ZW50WzFdWzFdIC0gZXh0ZW50WzBdWzFdLFxuICAgICAgICBrID0gTWF0aC5taW4odyAvIChiWzFdWzBdIC0gYlswXVswXSksIGggLyAoYlsxXVsxXSAtIGJbMF1bMV0pKSxcbiAgICAgICAgeCA9ICtleHRlbnRbMF1bMF0gKyAodyAtIGsgKiAoYlsxXVswXSArIGJbMF1bMF0pKSAvIDIsXG4gICAgICAgIHkgPSArZXh0ZW50WzBdWzFdICsgKGggLSBrICogKGJbMV1bMV0gKyBiWzBdWzFdKSkgLyAyO1xuICAgIHByb2plY3Rpb24uc2NhbGUoMTUwICogaykudHJhbnNsYXRlKFt4LCB5XSk7XG4gIH0sIG9iamVjdCk7XG59XG5cbmZ1bmN0aW9uIGZpdFNpemUocHJvamVjdGlvbiwgc2l6ZSwgb2JqZWN0KSB7XG4gIHJldHVybiBmaXRFeHRlbnQocHJvamVjdGlvbiwgW1swLCAwXSwgc2l6ZV0sIG9iamVjdCk7XG59XG5cbmZ1bmN0aW9uIGZpdFdpZHRoKHByb2plY3Rpb24sIHdpZHRoLCBvYmplY3QpIHtcbiAgcmV0dXJuIGZpdChwcm9qZWN0aW9uLCBmdW5jdGlvbihiKSB7XG4gICAgdmFyIHcgPSArd2lkdGgsXG4gICAgICAgIGsgPSB3IC8gKGJbMV1bMF0gLSBiWzBdWzBdKSxcbiAgICAgICAgeCA9ICh3IC0gayAqIChiWzFdWzBdICsgYlswXVswXSkpIC8gMixcbiAgICAgICAgeSA9IC1rICogYlswXVsxXTtcbiAgICBwcm9qZWN0aW9uLnNjYWxlKDE1MCAqIGspLnRyYW5zbGF0ZShbeCwgeV0pO1xuICB9LCBvYmplY3QpO1xufVxuXG5mdW5jdGlvbiBmaXRIZWlnaHQocHJvamVjdGlvbiwgaGVpZ2h0LCBvYmplY3QpIHtcbiAgcmV0dXJuIGZpdChwcm9qZWN0aW9uLCBmdW5jdGlvbihiKSB7XG4gICAgdmFyIGggPSAraGVpZ2h0LFxuICAgICAgICBrID0gaCAvIChiWzFdWzFdIC0gYlswXVsxXSksXG4gICAgICAgIHggPSAtayAqIGJbMF1bMF0sXG4gICAgICAgIHkgPSAoaCAtIGsgKiAoYlsxXVsxXSArIGJbMF1bMV0pKSAvIDI7XG4gICAgcHJvamVjdGlvbi5zY2FsZSgxNTAgKiBrKS50cmFuc2xhdGUoW3gsIHldKTtcbiAgfSwgb2JqZWN0KTtcbn1cblxuZnVuY3Rpb24gbXVsdGlwbGV4KHN0cmVhbXMpIHtcbiAgdmFyIG4gPSBzdHJlYW1zLmxlbmd0aDtcbiAgcmV0dXJuIHtcbiAgICBwb2ludDogZnVuY3Rpb24oeCwgeSkgeyB2YXIgaSA9IC0xOyB3aGlsZSAoKytpIDwgbikgc3RyZWFtc1tpXS5wb2ludCh4LCB5KTsgfSxcbiAgICBzcGhlcmU6IGZ1bmN0aW9uKCkgeyB2YXIgaSA9IC0xOyB3aGlsZSAoKytpIDwgbikgc3RyZWFtc1tpXS5zcGhlcmUoKTsgfSxcbiAgICBsaW5lU3RhcnQ6IGZ1bmN0aW9uKCkgeyB2YXIgaSA9IC0xOyB3aGlsZSAoKytpIDwgbikgc3RyZWFtc1tpXS5saW5lU3RhcnQoKTsgfSxcbiAgICBsaW5lRW5kOiBmdW5jdGlvbigpIHsgdmFyIGkgPSAtMTsgd2hpbGUgKCsraSA8IG4pIHN0cmVhbXNbaV0ubGluZUVuZCgpOyB9LFxuICAgIHBvbHlnb25TdGFydDogZnVuY3Rpb24oKSB7IHZhciBpID0gLTE7IHdoaWxlICgrK2kgPCBuKSBzdHJlYW1zW2ldLnBvbHlnb25TdGFydCgpOyB9LFxuICAgIHBvbHlnb25FbmQ6IGZ1bmN0aW9uKCkgeyB2YXIgaSA9IC0xOyB3aGlsZSAoKytpIDwgbikgc3RyZWFtc1tpXS5wb2x5Z29uRW5kKCk7IH1cbiAgfTtcbn1cblxuLy8gQSBjb21wb3NpdGUgcHJvamVjdGlvbiBmb3IgdGhlIFVuaXRlZCBTdGF0ZXMsIGNvbmZpZ3VyZWQgYnkgZGVmYXVsdCBmb3Jcbi8vIDk2MMOXNTAwLiBUaGUgcHJvamVjdGlvbiBhbHNvIHdvcmtzIHF1aXRlIHdlbGwgYXQgOTYww5c2MDAgaWYgeW91IGNoYW5nZSB0aGVcbi8vIHNjYWxlIHRvIDEyODUgYW5kIGFkanVzdCB0aGUgdHJhbnNsYXRlIGFjY29yZGluZ2x5LiBUaGUgc2V0IG9mIHN0YW5kYXJkXG4vLyBwYXJhbGxlbHMgZm9yIGVhY2ggcmVnaW9uIGNvbWVzIGZyb20gVVNHUywgd2hpY2ggaXMgcHVibGlzaGVkIGhlcmU6XG4vLyBodHRwOi8vZWdzYy51c2dzLmdvdi9pc2IvcHVicy9NYXBQcm9qZWN0aW9ucy9wcm9qZWN0aW9ucy5odG1sI2FsYmVyc1xuZXhwb3J0IGZ1bmN0aW9uIGFsYmVyc0JpZ0FsYXNrYSgpIHtcbiAgdmFyIGNhY2hlLFxuICAgICAgY2FjaGVTdHJlYW0sXG4gICAgICBsb3dlcjQ4ID0gZDMuZ2VvQWxiZXJzKCksIGxvd2VyNDhQb2ludCxcbiAgICAgIGFsYXNrYSA9IGQzLmdlb0NvbmljRXF1YWxBcmVhKCkucm90YXRlKFsxNTQsIDBdKS5jZW50ZXIoWy0yLCA1OC41XSkucGFyYWxsZWxzKFs1NSwgNjVdKSwgYWxhc2thUG9pbnQsIC8vIEVQU0c6MzMzOFxuICAgICAgaGF3YWlpID0gZDMuZ2VvQ29uaWNFcXVhbEFyZWEoKS5yb3RhdGUoWzE1NywgMF0pLmNlbnRlcihbLTMsIDE5LjldKS5wYXJhbGxlbHMoWzgsIDE4XSksIGhhd2FpaVBvaW50LCAvLyBFU1JJOjEwMjAwN1xuICAgICAgcG9pbnQsIHBvaW50U3RyZWFtID0ge3BvaW50OiBmdW5jdGlvbih4LCB5KSB7IHBvaW50ID0gW3gsIHldOyB9fTtcblxuICBmdW5jdGlvbiBhbGJlcnNVc2EoY29vcmRpbmF0ZXMpIHtcbiAgICB2YXIgeCA9IGNvb3JkaW5hdGVzWzBdLCB5ID0gY29vcmRpbmF0ZXNbMV07XG4gICAgcmV0dXJuIHBvaW50ID0gbnVsbCwgKGxvd2VyNDhQb2ludC5wb2ludCh4LCB5KSwgcG9pbnQpXG4gICAgICAgIHx8IChhbGFza2FQb2ludC5wb2ludCh4LCB5KSwgcG9pbnQpXG4gICAgICAgIHx8IChoYXdhaWlQb2ludC5wb2ludCh4LCB5KSwgcG9pbnQpO1xuICB9XG5cbiAgYWxiZXJzVXNhLmludmVydCA9IGZ1bmN0aW9uKGNvb3JkaW5hdGVzKSB7XG4gICAgdmFyIGsgPSBsb3dlcjQ4LnNjYWxlKCksXG4gICAgICAgIHQgPSBsb3dlcjQ4LnRyYW5zbGF0ZSgpLFxuICAgICAgICB4ID0gKGNvb3JkaW5hdGVzWzBdIC0gdFswXSkgLyBrLFxuICAgICAgICB5ID0gKGNvb3JkaW5hdGVzWzFdIC0gdFsxXSkgLyBrO1xuICAgIHJldHVybiAoeSA+PSAwLjEyMCAmJiB5IDwgMC4yMzQgJiYgeCA+PSAtMC40MjUgJiYgeCA8IC0wLjIxNCA/IGFsYXNrYVxuICAgICAgICA6IHkgPj0gMC4xNjYgJiYgeSA8IDAuMjM0ICYmIHggPj0gLTAuMjE0ICYmIHggPCAtMC4xMTUgPyBoYXdhaWlcbiAgICAgICAgOiBsb3dlcjQ4KS5pbnZlcnQoY29vcmRpbmF0ZXMpO1xuICB9O1xuXG4gIGFsYmVyc1VzYS5zdHJlYW0gPSBmdW5jdGlvbihzdHJlYW0pIHtcbiAgICByZXR1cm4gY2FjaGUgJiYgY2FjaGVTdHJlYW0gPT09IHN0cmVhbSA/IGNhY2hlIDogY2FjaGUgPSBtdWx0aXBsZXgoW2xvd2VyNDguc3RyZWFtKGNhY2hlU3RyZWFtID0gc3RyZWFtKSwgYWxhc2thLnN0cmVhbShzdHJlYW0pLCBoYXdhaWkuc3RyZWFtKHN0cmVhbSldKTtcbiAgfTtcblxuICBhbGJlcnNVc2EucHJlY2lzaW9uID0gZnVuY3Rpb24oXykge1xuICAgIGlmICghYXJndW1lbnRzLmxlbmd0aCkgcmV0dXJuIGxvd2VyNDgucHJlY2lzaW9uKCk7XG4gICAgbG93ZXI0OC5wcmVjaXNpb24oXyksIGFsYXNrYS5wcmVjaXNpb24oXyksIGhhd2FpaS5wcmVjaXNpb24oXyk7XG4gICAgcmV0dXJuIHJlc2V0KCk7XG4gIH07XG5cbiAgYWxiZXJzVXNhLnNjYWxlID0gZnVuY3Rpb24oXykge1xuICAgIGlmICghYXJndW1lbnRzLmxlbmd0aCkgcmV0dXJuIGxvd2VyNDguc2NhbGUoKTtcbiAgICBsb3dlcjQ4LnNjYWxlKF8pLCBhbGFza2Euc2NhbGUoXyAqIDAuNTIpLCBoYXdhaWkuc2NhbGUoXyk7XG4gICAgcmV0dXJuIGFsYmVyc1VzYS50cmFuc2xhdGUobG93ZXI0OC50cmFuc2xhdGUoKSk7XG4gIH07XG5cbiAgYWxiZXJzVXNhLnRyYW5zbGF0ZSA9IGZ1bmN0aW9uKF8pIHtcbiAgICBpZiAoIWFyZ3VtZW50cy5sZW5ndGgpIHJldHVybiBsb3dlcjQ4LnRyYW5zbGF0ZSgpO1xuICAgIHZhciBrID0gbG93ZXI0OC5zY2FsZSgpLCB4ID0gK19bMF0sIHkgPSArX1sxXTtcblxuICAgIGxvd2VyNDhQb2ludCA9IGxvd2VyNDhcbiAgICAgICAgLnRyYW5zbGF0ZShfKVxuICAgICAgICAuY2xpcEV4dGVudChbW3ggLSAwLjQ1NSAqIGssIHkgLSAwLjIzOCAqIGtdLCBbeCArIDAuNDU1ICogaywgeSArIDAuMjM4ICoga11dKVxuICAgICAgICAuc3RyZWFtKHBvaW50U3RyZWFtKTtcblxuICAgIGFsYXNrYVBvaW50ID0gYWxhc2thXG4gICAgICAgIC50cmFuc2xhdGUoW3ggLSAwLjMwNyAqIGssIHkgKyAwLjIxMSAqIGtdKVxuICAgICAgICAuY2xpcEV4dGVudChbW3ggLSAwLjQyNSAqIGsgKyBlcHNpbG9uJDIsIHkgKyAwLjAyMCAqIGsgKyBlcHNpbG9uJDJdLCBbeCAtIDAuMTg0ICogayAtIGVwc2lsb24kMiwgeSArIDAuMjU0ICogayAtIGVwc2lsb24kMl1dKVxuICAgICAgICAuc3RyZWFtKHBvaW50U3RyZWFtKTtcblxuICAgIGhhd2FpaVBvaW50ID0gaGF3YWlpXG4gICAgICAgIC50cmFuc2xhdGUoW3ggLSAwLjIwNSAqIGssIHkgKyAwLjIxMiAqIGtdKVxuICAgICAgICAuY2xpcEV4dGVudChbW3ggLSAwLjIxNCAqIGsgKyBlcHNpbG9uJDIsIHkgKyAwLjE2NiAqIGsgKyBlcHNpbG9uJDJdLCBbeCAtIDAuMTE1ICogayAtIGVwc2lsb24kMiwgeSArIDAuMjM0ICogayAtIGVwc2lsb24kMl1dKVxuICAgICAgICAuc3RyZWFtKHBvaW50U3RyZWFtKTtcblxuICAgIHJldHVybiByZXNldCgpO1xuICB9O1xuXG4gIGFsYmVyc1VzYS5maXRFeHRlbnQgPSBmdW5jdGlvbihleHRlbnQsIG9iamVjdCkge1xuICAgIHJldHVybiBmaXRFeHRlbnQoYWxiZXJzVXNhLCBleHRlbnQsIG9iamVjdCk7XG4gIH07XG5cbiAgYWxiZXJzVXNhLmZpdFNpemUgPSBmdW5jdGlvbihzaXplLCBvYmplY3QpIHtcbiAgICByZXR1cm4gZml0U2l6ZShhbGJlcnNVc2EsIHNpemUsIG9iamVjdCk7XG4gIH07XG5cbiAgYWxiZXJzVXNhLmZpdFdpZHRoID0gZnVuY3Rpb24od2lkdGgsIG9iamVjdCkge1xuICAgIHJldHVybiBmaXRXaWR0aChhbGJlcnNVc2EsIHdpZHRoLCBvYmplY3QpO1xuICB9O1xuXG4gIGFsYmVyc1VzYS5maXRIZWlnaHQgPSBmdW5jdGlvbihoZWlnaHQsIG9iamVjdCkge1xuICAgIHJldHVybiBmaXRIZWlnaHQoYWxiZXJzVXNhLCBoZWlnaHQsIG9iamVjdCk7XG4gIH07XG5cbiAgZnVuY3Rpb24gcmVzZXQoKSB7XG4gICAgY2FjaGUgPSBjYWNoZVN0cmVhbSA9IG51bGw7XG4gICAgcmV0dXJuIGFsYmVyc1VzYTtcbiAgfVxuXG4gIHJldHVybiBhbGJlcnNVc2Euc2NhbGUoMTA3MCk7XG59XG4iLCJpbXBvcnQgeyBCaXJkRG90c0Jhc2UgfSBmcm9tICcuL2JpcmREb3QnO1xuXG5sZXQgcmVnaW9ucyA9IFtcbiAgWydBbGFza2EnLCAnQWxhc2thJywgJ2h0dHBzOi8vY2RuLmF1ZHVib24ub3JnL2Nkbi9mYXJmdXR1cmUvZkZHZi1iT0FJeFJYRGlpbXZQV0QwYUxIc2hjNlZNRkJkTHU0ODh6QzhTRS9tdGltZToxNTIxMjI1OTEyL3NpdGVzL2RlZmF1bHQvZmlsZXMvMDMxNS1hbGFza2EtcGhvdG8yeC5qcGcnXSxcbiAgWydJbnRlcm1vdW50YWluJywgJ0ludGVybW91bnRhaW4nLCAnaHR0cHM6Ly9jZG4uYXVkdWJvbi5vcmcvY2RuL2ZhcmZ1dHVyZS8wdU1rR3I4UGFQRDBhbElkRXNDTm5RMExhNExia3lOZVFmVkx3NEUyYnBNL210aW1lOjE1MjEyMjU5NDYvc2l0ZXMvZGVmYXVsdC9maWxlcy8wMzE1LWludGVybW91bnRhaW4tcGhvdG8yeC5qcGcnXSxcbiAgWydNaWR3ZXN0JywgJ01pZHdlc3QnLCAnaHR0cHM6Ly9jZG4uYXVkdWJvbi5vcmcvY2RuL2ZhcmZ1dHVyZS9LcVF4Q0VQcmFNeVo0ODNCUi1NalNEb3Zjckh1R3NVa0I3dVJSTkFRLVhvL210aW1lOjE1MjEyMjYwMjIvc2l0ZXMvZGVmYXVsdC9maWxlcy8wMzE1LW1pZHdlc3QtcGhvdG8yeC5qcGcnXSxcbiAgWydOb3J0aGVhc3QnLCAnTm9ydGhlYXN0JywgJ2h0dHBzOi8vY2RuLmF1ZHVib24ub3JnL2Nkbi9mYXJmdXR1cmUvTGdzeS1sM2NjZmlFcHBsYTQ4ajBzdmp0Qm10c254cEpYMm1xT2FZYXgtQS9tdGltZToxNTIxMjI2MDYxL3NpdGVzL2RlZmF1bHQvZmlsZXMvMDMxNS1ub3J0aGVhc3QtcGhvdG8yeC5qcGcnXSxcbiAgWydQYWNpZmljJywgJ1BhY2lmaWMgV2VzdCcsICdodHRwczovL2Nkbi5hdWR1Ym9uLm9yZy9jZG4vZmFyZnV0dXJlL0VOM1l5Z1dOU3ZIc19lRVpiNTB5aDJGMUFPTlo5N3V1VVpBYnZvYzd1VWcvbXRpbWU6MTUyMTIyNTgyMy9zaXRlcy9kZWZhdWx0L2ZpbGVzLzAzMTUtcGFjaWZpYy1waG90bzJ4LmpwZyddLFxuICBbJ1NvdXRoZWFzdCcsICdTb3V0aGVhc3QnLCAnaHR0cHM6Ly9jZG4uYXVkdWJvbi5vcmcvY2RuL2ZhcmZ1dHVyZS9ZOC1yLV9Sa0trV0t4b01TTUEteEhVZGxqYlQzR2pvVWtCNXRQcjFFUW9vL210aW1lOjE1MjEyMjU4NjQvc2l0ZXMvZGVmYXVsdC9maWxlcy8wMzE1LXNvdXRoZWFzdC1waG90bzJ4LmpwZyddXG5dO1xuXG5mdW5jdGlvbiBBbGxQYXJrcyhwYXJhbXMpIHtcbiAgY29uc3QgeyBlbGVtZW50LCBkYXRhVXJsLCBvbkNsaWNrfSA9IHBhcmFtcztcblxuICBsZXQgbm9kZSA9IGQzLnNlbGVjdChlbGVtZW50KTtcblxuICBmdW5jdGlvbiByZW5kZXJQYXJrKGNvbnRhaW5lciwgcGFya0RhdGEpIHtcbiAgICBsZXQgYyA9IGNvbnRhaW5lci5hcHBlbmQoJ2RpdicpXG4gICAgICAuY2xhc3NlZCgnc2QtcGFyaycsIHRydWUpXG4gICAgICAuaHRtbChgXG4gICAgICAgIDxoMz4ke3BhcmtEYXRhLnVuaXRfbmFtZX08L2gzPlxuICAgICAgICA8ZGl2PlxuICAgICAgICAgIDxkaXYgY2xhc3M9XCJzZWFzb24gc2Vhc29uLXdpbnRlclwiPlxuICAgICAgICAgICAgPHA+d2ludGVyPC9wPlxuICAgICAgICAgIDwvZGl2PlxuICAgICAgICAgIDxkaXYgY2xhc3M9XCJzZWFzb24gc2Vhc29uLXN1bW1lclwiPlxuICAgICAgICAgICAgPHA+c3VtbWVyPC9wPlxuICAgICAgICAgIDwvZGl2PlxuICAgICAgICA8L2Rpdj5cbiAgICAgIGApXG5cbiAgICBpZiAob25DbGljaykge1xuICAgICAgYy5zZWxlY3QoJ2gzJykub24oJ2NsaWNrJywgKCkgPT4gb25DbGljayhjLnNlbGVjdCgnaDMnKS50ZXh0KCkpKTtcbiAgICB9XG5cbiAgICBsZXQgbnVtRG90cyA9IE1hdGgubWF4KFxuICAgICAgK3BhcmtEYXRhLm5vX2NvbG9uaXphdGlvbnNfc3VtbWVyICsgK3BhcmtEYXRhLmN1cnJlbnRfc3BlY2llc19zdW1tZXIsXG4gICAgICArcGFya0RhdGEubm9fY29sb25pemF0aW9uc193aW50ZXIgKyArcGFya0RhdGEuY3VycmVudF9zcGVjaWVzX3dpbnRlcilcblxuICAgIGxldCBzdW1tZXJQYXJhbXMgPSB7XG4gICAgICAgIGVsZW1lbnQ6IGMuc2VsZWN0KCcuc2Vhc29uLXN1bW1lcicpLm5vZGUoKSxcbiAgICAgICAgbnVtQ3VycmVudDogK3BhcmtEYXRhLmN1cnJlbnRfc3BlY2llc19zdW1tZXIsXG4gICAgICAgIG51bUNvbG9uaXplZDogK3BhcmtEYXRhLm5vX2NvbG9uaXphdGlvbnNfc3VtbWVyLFxuICAgICAgICBudW1FeHRpcnBhdGVkOiArcGFya0RhdGEubm9fZXh0aXJwYXRpb25zX3N1bW1lcixcbiAgICAgICAgcmVuZGVyQWxsOiB0cnVlLFxuICAgICAgICBudW1Db2xzOiA2LFxuICAgICAgICB0b3BBbGlnbjogdHJ1ZVxuICAgIH07XG5cbiAgICBsZXQgd2ludGVyUGFyYW1zID0ge1xuICAgICAgICBlbGVtZW50OiBjLnNlbGVjdCgnLnNlYXNvbi13aW50ZXInKS5ub2RlKCksXG4gICAgICAgIG51bUN1cnJlbnQ6ICtwYXJrRGF0YS5jdXJyZW50X3NwZWNpZXNfd2ludGVyLFxuICAgICAgICBudW1Db2xvbml6ZWQ6ICtwYXJrRGF0YS5ub19jb2xvbml6YXRpb25zX3dpbnRlcixcbiAgICAgICAgbnVtRXh0aXJwYXRlZDogK3BhcmtEYXRhLm5vX2V4dGlycGF0aW9uc193aW50ZXIsXG4gICAgICAgIHJlbmRlckFsbDogdHJ1ZSxcbiAgICAgICAgbnVtQ29sczogNixcbiAgICAgICAgdG9wQWxpZ246IHRydWVcbiAgICB9O1xuICAgIG5ldyBCaXJkRG90c0Jhc2Uoc3VtbWVyUGFyYW1zKTtcbiAgICBuZXcgQmlyZERvdHNCYXNlKHdpbnRlclBhcmFtcyk7XG4gIH1cblxuICBkMy5jc3YoZGF0YVVybCwgKGVycm9yLCByb3dzKSA9PiB7XG5cbiAgICBpZiAoZXJyb3IpIHtcbiAgICAgIGNvbnNvbGUubG9nKGVycm9yKTtcbiAgICAgIHJldHVybjtcbiAgICB9XG5cbiAgICBsZXQgbmVzdGVkID0gZDMubmVzdCgpLmtleShkID0+IGQubnBzX3JlZ2lvbikubWFwKHJvd3MpXG5cbiAgICByZWdpb25zLmZvckVhY2goKFtyZWdpb24sIG5wc1JlZ2lvbiwgcmVnaW9uSW1hZ2VdKSA9PiB7XG4gICAgICBsZXQgcmVnaW9uRGl2ID0gbm9kZS5hcHBlbmQoJ2RpdicpXG4gICAgICAgIC5jbGFzc2VkKCdzZC1yZWdpb24nLCB0cnVlKVxuICAgICAgICAuaHRtbChgXG4gICAgICAgICAgICA8ZGl2IGNsYXNzPVwicmVnaW9uLWhlYWRlclwiPlxuICAgICAgICAgICAgICA8YSBuYW1lPVwibnBzLXJlZ2lvbi0ke3JlZ2lvbn1cIj48L2E+XG4gICAgICAgICAgICAgIDxpbWcgY2xhc3M9XCJiYWNrZ3JvdW5kLWltYWdlXCIgc3JjPVwiJHtyZWdpb25JbWFnZX1cIj5cbiAgICAgICAgICAgICAgPGRpdiBjbGFzcz1cInJvd1wiPlxuICAgICAgICAgICAgICAgIDxoMT4ke25wc1JlZ2lvbn08L2gxPlxuICAgICAgICAgICAgICA8L2Rpdj5cbiAgICAgICAgICAgIDwvZGl2PlxuICAgICAgICAgICAgPGRpdiBjbGFzcz1cImNvbHVtbnMgc21hbGwtMTJcIj5cbiAgICAgICAgICAgICAgPGRpdiBjbGFzcz1cImRvdC1sZWdlbmRcIj5cbiAgICAgICAgICAgICAgICA8ZGl2IGNsYXNzPVwiZG90LWxlZ2VuZC1lbnRyeSBjb2xvbml6ZWRcIj5Qb3RlbnRpYWwgY29sb25pemF0aW9uPC9kaXY+XG4gICAgICAgICAgICAgICAgPGRpdiBjbGFzcz1cImRvdC1sZWdlbmQtZW50cnkgY3VycmVudFwiPlN0YWJsZSBwb3B1bGF0aW9uPC9kaXY+XG4gICAgICAgICAgICAgICAgPGRpdiBjbGFzcz1cImRvdC1sZWdlbmQtZW50cnkgZXh0aXJwYXRlZFwiPlBvdGVudGlhbCBleHRpcnBhdGlvbjwvZGl2PlxuICAgICAgICAgICAgICA8L2Rpdj5cbiAgICAgICAgICAgICAgPGRpdiBjbGFzcz1cImRvdC1hcmVhXCI+XG4gICAgICAgICAgICAgIDwvZGl2PlxuICAgICAgICAgICAgPC9kaXY+XG4gICAgICAgIGApXG5cbiAgICAgIGxldCBwYXJrcyA9IG5lc3RlZC5nZXQobnBzUmVnaW9uKTtcbiAgICAgIGlmIChwYXJrcykge1xuICAgICAgICBwYXJrcy5mb3JFYWNoKHBhcmtEYXRhID0+IHtcbiAgICAgICAgICByZW5kZXJQYXJrKHJlZ2lvbkRpdi5zZWxlY3QoJy5kb3QtYXJlYScpLCBwYXJrRGF0YSk7XG4gICAgICAgIH0pO1xuICAgICAgfVxuXG4gICAgfSk7XG4gIH0pO1xufVxuXG5leHBvcnQgeyBBbGxQYXJrcyB9O1xuIiwiLy8gQmlyZCBEb3QgYW5pbWF0aW9uc1xuXG5cbmZ1bmN0aW9uIGFuaW1hdGVDb3VudChlbGVtZW50LCBzdGFydCwgZW5kLCBkdXJhdGlvbikge1xuICAgIC8vIGVuZCBpcyBhIG51bWJlciBzdGFydCBpcyBhIG51bWJlclxuICAgIGNvbnN0IGludGVycG9sYXRvciA9IGQzLmludGVycG9sYXRlTnVtYmVyKHN0YXJ0LCBlbmQpO1xuICAgIGxldCBhbmltYXRpb25UaW1lcjtcblxuICAgIGZ1bmN0aW9uIGFuaW1hdGlvbkZ1bmMoZWxhcHNlZCkge1xuICAgICAgY29uc3Qgc3RlcCA9IGVsYXBzZWQgLyBkdXJhdGlvbjtcbiAgICAgIGlmIChzdGVwID49IDEpIHtcbiAgICAgICAgYW5pbWF0aW9uVGltZXIuc3RvcCgpO1xuICAgICAgICByZXR1cm47XG4gICAgICB9XG4gICAgICBsZXQgbnVtID0gTWF0aC5yb3VuZChpbnRlcnBvbGF0b3IoZDMuZWFzZVF1YWRJbk91dChzdGVwKSkpO1xuICAgICAgZWxlbWVudC50ZXh0KG51bSk7XG4gICAgfVxuXG4gICAgYW5pbWF0aW9uVGltZXIgPSBkMy50aW1lcihhbmltYXRpb25GdW5jKTtcbn1cblxuXG5cbmZ1bmN0aW9uIEdyaWRIZWxwZXIocmFkaXVzLCBzcGFjaW5nLCBudW1Eb3RzLCBudW1Db2xzKSB7XG5cblxuICAgIGxldCBfY29sU2NhbGUgPSBkMy5zY2FsZUxpbmVhcigpXG4gICAgICAgIC5kb21haW4oWzgwLCA5MSwgMTA5LCAxMjddKVxuICAgICAgICAucmFuZ2UoWzUsIDYsIDcsIDhdKVxuICAgICAgICAuY2xhbXAodHJ1ZSk7XG5cbiAgICBmdW5jdGlvbiBjb2xTY2FsZShudW1Eb3RzKSB7XG4gICAgICAgIHJldHVybiBNYXRoLmZsb29yKF9jb2xTY2FsZShudW1Eb3RzKSk7XG4gICAgfVxuXG4gICAgbGV0IGNvbHMgPSBudW1Db2xzIHx8IGNvbFNjYWxlKG51bURvdHMpO1xuICAgIGxldCBudW1Sb3dzID0gTWF0aC5jZWlsKG51bURvdHMgLyBjb2xzKTtcbiAgICBsZXQgb2Zmc2V0ID0gbnVtUm93cyAqIGNvbHMgLSBudW1Eb3RzO1xuXG4gICAgZnVuY3Rpb24gZ3JpZFBvc2l0aW9uKGlkeCkge1xuICAgICAgICBpZHggKz0gb2Zmc2V0O1xuICAgICAgICBsZXQgcm93ID0gTWF0aC5mbG9vcihpZHggLyBjb2xzKTtcbiAgICAgICAgbGV0IGNvbCA9IGlkeCAtIChyb3cgKiBjb2xzKTtcblxuICAgICAgICByZXR1cm4ge1xuICAgICAgICAgICAgeDogY29sICogc3BhY2luZyxcbiAgICAgICAgICAgIHk6IHJvdyAqIHNwYWNpbmdcbiAgICAgICAgfVxuICAgIH1cblxuICAgIGxldCB3aWR0aCA9IGNvbHMgKiBzcGFjaW5nO1xuICAgIGxldCBoZWlnaHQgPSBudW1Sb3dzICogc3BhY2luZztcblxuICAgIHJldHVybiB7XG4gICAgICAgIGdyaWRQb3NpdGlvbjogZ3JpZFBvc2l0aW9uLFxuICAgICAgICBoZWlnaHQ6IGhlaWdodCxcbiAgICAgICAgd2lkdGg6IHdpZHRoXG4gICAgfVxufVxuXG5cbmZ1bmN0aW9uIHJhbmRvbUJpcmRQb3Moc2NhbGUpIHtcbiAgICByZXR1cm4ge1xuICAgICAgICB4OiAoLTEwMCArIE1hdGgucmFuZG9tKCkgKiAyMDAgKyAyMCkgKiBzY2FsZSxcbiAgICAgICAgeTogLTMwMCAqIHNjYWxlXG4gICAgfVxufVxuXG5sZXQgZXh0aXJwYXRlZEdhcCA9IDEwO1xuXG5mdW5jdGlvbiBnZW5lcmF0ZVBvaW50cyhkYXRhLCBncmlkSGVscGVyLCBzY2FsZSkge1xuICAgIGNvbnN0IHsgbnVtQ29sb25pemVkLCBudW1DdXJyZW50LCBudW1FeHRpcnBhdGVkIH0gPSBkYXRhO1xuICAgIGxldCBudW1SZW1haW5pbmcgPSBudW1DdXJyZW50IC0gbnVtRXh0aXJwYXRlZDtcblxuICAgIGxldCBjb2xvcnMgPSB7XG4gICAgICAgIGNvbG9uaXplZDogJyMxOGExYWQnLFxuICAgICAgICBjdXJyZW50OiAnIzkwZDJkOCcsXG4gICAgICAgIGV4dGlycGF0ZWQ6ICcjZThjNTc4J1xuICAgIH1cblxuICAgIGxldCBjYyA9IGQzLnJhbmdlKG51bUNvbG9uaXplZCkubWFwKGkgPT4ge1xuICAgICAgICByZXR1cm4ge1xuICAgICAgICAgICAgaW5pdFBvczogcmFuZG9tQmlyZFBvcyhzY2FsZSksXG4gICAgICAgICAgICBmaW5hbFBvczogZ3JpZEhlbHBlci5ncmlkUG9zaXRpb24oaSksXG4gICAgICAgICAgICBsYWJlbDogJ0MnLFxuICAgICAgICAgICAgaW5pdEZpbGxPcGFjaXR5OiAwLFxuICAgICAgICAgICAgaW5pdEZpbGw6IGNvbG9ycy5jb2xvbml6ZWQsXG4gICAgICAgICAgICBmaW5hbEZpbGxPcGFjaXR5OiAxLFxuICAgICAgICAgICAgZmluYWxGaWxsOiBjb2xvcnMuY29sb25pemVkXG4gICAgICAgIH1cbiAgICB9KTtcblxuICAgIGxldCBkZCA9IGQzLnJhbmdlKG51bVJlbWFpbmluZykubWFwKGkgPT4ge1xuICAgICAgICByZXR1cm4ge1xuICAgICAgICAgICAgaW5pdFBvczogZ3JpZEhlbHBlci5ncmlkUG9zaXRpb24oaSArIG51bUNvbG9uaXplZCksXG4gICAgICAgICAgICBmaW5hbFBvczogZ3JpZEhlbHBlci5ncmlkUG9zaXRpb24oaSArIG51bUNvbG9uaXplZCksXG4gICAgICAgICAgICBsYWJlbDogJ1InLFxuICAgICAgICAgICAgaW5pdEZpbGxPcGFjaXR5OiAxLFxuICAgICAgICAgICAgaW5pdEZpbGw6IGNvbG9ycy5jdXJyZW50LFxuICAgICAgICAgICAgZmluYWxGaWxsT3BhY2l0eTogMSxcbiAgICAgICAgICAgIGZpbmFsRmlsbDogY29sb3JzLmN1cnJlbnRcbiAgICAgICAgfVxuICAgIH0pO1xuXG4gICAgbGV0IGVlID0gZDMucmFuZ2UobnVtRXh0aXJwYXRlZCkubWFwKGkgPT4ge1xuICAgICAgICBsZXQgZmluYWxQb3MgPSBncmlkSGVscGVyLmdyaWRQb3NpdGlvbihpICsgbnVtQ29sb25pemVkICsgbnVtUmVtYWluaW5nKTtcbiAgICAgICAgZmluYWxQb3MueSArPSBleHRpcnBhdGVkR2FwICogc2NhbGU7XG5cbiAgICAgICAgcmV0dXJuIHtcbiAgICAgICAgICAgIGluaXRQb3M6IGdyaWRIZWxwZXIuZ3JpZFBvc2l0aW9uKGkgKyBudW1Db2xvbml6ZWQgKyBudW1SZW1haW5pbmcpLFxuICAgICAgICAgICAgZmluYWxQb3M6IGZpbmFsUG9zLFxuICAgICAgICAgICAgbGFiZWw6ICdFJyxcbiAgICAgICAgICAgIGluaXRGaWxsT3BhY2l0eTogMSxcbiAgICAgICAgICAgIGluaXRGaWxsOiBjb2xvcnMuY3VycmVudCxcbiAgICAgICAgICAgIGZpbmFsRmlsbE9wYWNpdHk6IDEsXG4gICAgICAgICAgICBmaW5hbEZpbGw6IGNvbG9ycy5leHRpcnBhdGVkXG4gICAgICAgIH1cbiAgICB9KVxuXG4gICAgcmV0dXJuIGNjLmNvbmNhdChkZCkuY29uY2F0KGVlKTtcblxufVxuXG5mdW5jdGlvbiBfQmlyZERvdHMocGFyYW1zKSB7XG4gICAgLy8gYXR0YWNoZXMgYW4gc3ZnIHRvIHRoZSBlbGVtZW50XG4gICAgY29uc3QgeyBlbGVtZW50LCBudW1Db2xvbml6ZWQsIG51bUN1cnJlbnQsIG51bUV4dGlycGF0ZWQsXG4gICAgICAgIGNvbG9uaXplZENvdW50ZXIsIGV4dGlycGF0ZWRDb3VudGVyLCBvbkxvYWQsIHNjYWxlLCBudW1Db2xzLCByZW5kZXJBbGwsIHRvcEFsaWdufSA9IHBhcmFtcztcblxuICAgIGxldCBfc2NhbGUgPSBzY2FsZSB8fCAxO1xuICAgIGxldCByYWRpdXMgPSAzICogX3NjYWxlO1xuICAgIGxldCBzcGFjaW5nID0gNiAqIF9zY2FsZTtcblxuICAgIGxldCBncmlkSGVscGVyID0gbmV3IEdyaWRIZWxwZXIoXG4gICAgICAgIHJhZGl1cywgc3BhY2luZywgbnVtQ3VycmVudCArIG51bUNvbG9uaXplZCwgbnVtQ29scyk7XG5cbiAgICBsZXQgZGF0YSA9IGdlbmVyYXRlUG9pbnRzKHBhcmFtcywgZ3JpZEhlbHBlciwgX3NjYWxlKTtcblxuICAgIGxldCBzdmdXaWR0aCA9IDcwMDtcbiAgICBsZXQgc3ZnSGVpZ2h0ID0gNzAwO1xuXG4gICAgbGV0IGRpdkNvbnRhaW5lciA9IGQzLnNlbGVjdChlbGVtZW50KVxuICAgICAgICAuYXBwZW5kKCdkaXYnKVxuICAgICAgICAuY2xhc3NlZCgnYmlyZC1kb3QtYmFzZS1jb250YWluZXInLCB0cnVlKTtcblxuICAgIGxldCBzdmdDb250YWluZXIgPSBkaXZDb250YWluZXIuYXBwZW5kKCdzdmcnKVxuICAgICAgICAgICAgLmF0dHIoJ3dpZHRoJywgc3ZnV2lkdGgpXG4gICAgICAgICAgICAuYXR0cignaGVpZ2h0Jywgc3ZnSGVpZ2h0KTtcblxuICAgIGxldCBzdmcgPSBzdmdDb250YWluZXIuYXBwZW5kKCdnJyk7XG5cbiAgICBmdW5jdGlvbiBhbGlnbkRvdHMoKSB7XG4gICAgICAgIGxldCBbZG90Qm94V2lkdGgsIGRvdEJveEhlaWdodF0gPSBbZ3JpZEhlbHBlci53aWR0aCwgZ3JpZEhlbHBlci5oZWlnaHRdO1xuXG4gICAgICAgIGRpdkNvbnRhaW5lci5zdHlsZSgnd2lkdGgnLCBkb3RCb3hXaWR0aCArICdweCcpO1xuICAgICAgICBkaXZDb250YWluZXIuc3R5bGUoJ2hlaWdodCcsIGRvdEJveEhlaWdodCArIChleHRpcnBhdGVkR2FwICogX3NjYWxlKSArICdweCcpO1xuXG4gICAgICAgIGxldCBkaXZXaWR0aCA9IGRpdkNvbnRhaW5lci5ub2RlKCkub2Zmc2V0V2lkdGg7XG4gICAgICAgIGxldCBkaXZIZWlnaHQgPSBkaXZDb250YWluZXIubm9kZSgpLm9mZnNldEhlaWdodDtcblxuICAgICAgICBsZXQgb2Zmc2V0WSA9ICgodG9wQWxpZ24pID8gMCA6IChkaXZIZWlnaHQgLSBkb3RCb3hIZWlnaHQpIC8gMikgKyByYWRpdXM7XG4gICAgICAgIGxldCBvZmZzZXRYID0gKGRpdldpZHRoIC0gZG90Qm94V2lkdGgpIC8gMiArIHJhZGl1cztcblxuICAgICAgICAvLyBsZXQgc3ZnT2Zmc2V0WSA9IE1hdGguYWJzKHBhcnNlSW50KHN2Z0NvbnRhaW5lci5zdHlsZSgndG9wJykpKTtcbiAgICAgICAgLy8gbGV0IHN2Z09mZnNldFggPSBNYXRoLmFicyhwYXJzZUludChzdmdDb250YWluZXIuc3R5bGUoJ2xlZnQnKSkpO1xuICAgICAgICBsZXQgc3ZnT2Zmc2V0WSA9IHN2Z0hlaWdodCAvIDIgLSBkaXZIZWlnaHQgLyAyO1xuICAgICAgICBsZXQgc3ZnT2Zmc2V0WCA9IHN2Z1dpZHRoIC8gMiAtIGRpdldpZHRoIC8gMjtcbiAgICAgICAgc3ZnQ29udGFpbmVyLnN0eWxlKCd0b3AnLCAtc3ZnT2Zmc2V0WSArICdweCcpXG4gICAgICAgIHN2Z0NvbnRhaW5lci5zdHlsZSgnbGVmdCcsIC1zdmdPZmZzZXRYICsgJ3B4JylcblxuICAgICAgICBsZXQgdHJhbnNsYXRlWCA9IG9mZnNldFggKyBzdmdPZmZzZXRYO1xuICAgICAgICBsZXQgdHJhbnNsYXRlWSA9IG9mZnNldFkgKyBzdmdPZmZzZXRZO1xuXG4gICAgICAgIHN2Zy5hdHRyKCd0cmFuc2Zvcm0nLCBgdHJhbnNsYXRlKCR7dHJhbnNsYXRlWH0sICR7dHJhbnNsYXRlWX0pYCk7XG4gICAgfVxuXG4gICAgYWxpZ25Eb3RzKCk7XG5cbiAgICBsZXQgY29sb25pemVkSW5WaWV3ID0gZmFsc2U7XG4gICAgbGV0IGV4dGlycGF0ZWRJblZpZXcgPSBmYWxzZTtcbiAgICBsZXQgZGlzYWJsZWRPcGFjaXR5ID0gMC4yO1xuXG4gICAgbGV0IGRvdHMgPSBzdmcuc2VsZWN0QWxsKCcuZG90JykuZGF0YShkYXRhKTtcblxuICAgIGlmIChyZW5kZXJBbGwpIHtcbiAgICAgICAgZG90cy5lbnRlcigpXG4gICAgICAgICAgICAuYXBwZW5kKCdjaXJjbGUnKVxuICAgICAgICAgICAgLmF0dHIoJ2NsYXNzJywgJ2RvdCcpXG4gICAgICAgICAgICAuY2xhc3NlZCgnUicsZCA9PiBkLmxhYmVsID09ICdSJylcbiAgICAgICAgICAgIC5jbGFzc2VkKCdFJywgZCA9PiBkLmxhYmVsID09ICdFJylcbiAgICAgICAgICAgIC5jbGFzc2VkKCdDJywgZCA9PiBkLmxhYmVsID09ICdDJylcbiAgICAgICAgICAgIC5hdHRyKCdjeCcsIGQgPT4gZC5maW5hbFBvcy54KVxuICAgICAgICAgICAgLmF0dHIoJ2N5JywgZCA9PiBkLmZpbmFsUG9zLnkpXG4gICAgICAgICAgICAuYXR0cigncicsIHJhZGl1cylcbiAgICAgICAgICAgIC5hdHRyKCdmaWxsLW9wYWNpdHknLCBkID0+IGQuZmluYWxGaWxsT3BhY2l0eSlcbiAgICAgICAgICAgIC5hdHRyKCdmaWxsJywgZCA9PiBkLmZpbmFsRmlsbCk7XG4gICAgfSBlbHNlIHtcbiAgICAgICAgZG90cy5lbnRlcigpXG4gICAgICAgICAgICAuYXBwZW5kKCdjaXJjbGUnKVxuICAgICAgICAgICAgLmF0dHIoJ2NsYXNzJywgJ2RvdCcpXG4gICAgICAgICAgICAuY2xhc3NlZCgnUicsZCA9PiBkLmxhYmVsID09ICdSJylcbiAgICAgICAgICAgIC5jbGFzc2VkKCdFJywgZCA9PiBkLmxhYmVsID09ICdFJylcbiAgICAgICAgICAgIC5jbGFzc2VkKCdDJywgZCA9PiBkLmxhYmVsID09ICdDJylcbiAgICAgICAgICAgIC5hdHRyKCdjeCcsIGQgPT4gZC5pbml0UG9zLngpXG4gICAgICAgICAgICAuYXR0cignY3knLCBkID0+IGQuaW5pdFBvcy55KVxuICAgICAgICAgICAgLmF0dHIoJ3InLCByYWRpdXMpXG4gICAgICAgICAgICAuYXR0cignZmlsbC1vcGFjaXR5JywgZCA9PiBkLmluaXRGaWxsT3BhY2l0eSlcbiAgICAgICAgICAgIC5hdHRyKCdmaWxsJywgZCA9PiBkLmluaXRGaWxsKTtcbiAgICB9XG5cbiAgICBmdW5jdGlvbiBlbnRlckNvbG9uaXplZChvbkZpbmlzaGVkKSB7XG4gICAgICAgIGxldCBuID0gbnVtQ29sb25pemVkO1xuICAgICAgICBzdmcuc2VsZWN0QWxsKCcuZG90LkMnKVxuICAgICAgICAgICAgLmNsYXNzZWQoJ25ldy12aXNpYmxlJywgdHJ1ZSlcbiAgICAgICAgICAgIC50cmFuc2l0aW9uKClcbiAgICAgICAgICAgIC5lYXNlKGQzLmVhc2VRdWFkSW5PdXQpXG4gICAgICAgICAgICAuZHVyYXRpb24oKGQsIGkpID0+IE1hdGgucmFuZG9tKCkgKiAzMDAgKyA5NTApXG4gICAgICAgICAgICAuZGVsYXkoKGQsIGkpID0+IChudW1Db2xvbml6ZWQgLSBpKSAqIDIwKVxuICAgICAgICAgICAgLmF0dHIoJ2N4JywgZCA9PiBkLmZpbmFsUG9zLngpXG4gICAgICAgICAgICAuYXR0cignY3knLCBkID0+IGQuZmluYWxQb3MueSlcbiAgICAgICAgICAgIC5hdHRyKCdmaWxsLW9wYWNpdHknLCBkID0+IGQuZmluYWxGaWxsT3BhY2l0eSlcbiAgICAgICAgICAgIC5hdHRyKCdmaWxsJywgZCA9PiBkLmZpbmFsRmlsbClcbiAgICAgICAgICAgIC5vbignZW5kJywgKGQsIGkpID0+IHtcbiAgICAgICAgICAgICAgICBuLS07XG4gICAgICAgICAgICAgICAgaWYgKG4gPT0gMCkge1xuICAgICAgICAgICAgICAgICAgICBpZiAob25GaW5pc2hlZCkge1xuICAgICAgICAgICAgICAgICAgICAgICAgb25GaW5pc2hlZCgpO1xuICAgICAgICAgICAgICAgICAgICB9XG4gICAgICAgICAgICAgICAgfVxuICAgICAgICAgICAgfSk7XG4gICAgICAgIGNvbG9uaXplZEluVmlldyA9IHRydWU7XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gZXhpdENvbG9uaXplZChvbkZpbmlzaGVkKSB7XG4gICAgICAgIGxldCBuID0gbnVtQ29sb25pemVkO1xuICAgICAgICBzdmcuc2VsZWN0QWxsKCcuZG90LkMnKVxuICAgICAgICAgICAgLmNsYXNzZWQoJ25ldy12aXNpYmxlJywgZmFsc2UpXG4gICAgICAgICAgICAudHJhbnNpdGlvbigpXG4gICAgICAgICAgICAuZWFzZShkMy5lYXNlUXVhZEluT3V0KVxuICAgICAgICAgICAgLmR1cmF0aW9uKChkLCBpKSA9PiBNYXRoLnJhbmRvbSgpICogMzAwICsgOTUwKVxuICAgICAgICAgICAgLmRlbGF5KChkLCBpKSA9PiBpICogMjApXG4gICAgICAgICAgICAuYXR0cignY3gnLCBkID0+IGQuaW5pdFBvcy54KVxuICAgICAgICAgICAgLmF0dHIoJ2N5JywgZCA9PiBkLmluaXRQb3MueSlcbiAgICAgICAgICAgIC5hdHRyKCdmaWxsLW9wYWNpdHknLCBkID0+IGQuaW5pdEZpbGxPcGFjaXR5KVxuICAgICAgICAgICAgLmF0dHIoJ2ZpbGwnLCBkID0+IGQuaW5pdEZpbGwpXG4gICAgICAgICAgICAub24oJ2VuZCcsIChkLCBpKSA9PiB7XG4gICAgICAgICAgICAgICAgbi0tO1xuICAgICAgICAgICAgICAgIGlmIChuID09IDApIHtcbiAgICAgICAgICAgICAgICAgICAgaWYgKG9uRmluaXNoZWQpIHtcbiAgICAgICAgICAgICAgICAgICAgICAgIG9uRmluaXNoZWQoKTtcbiAgICAgICAgICAgICAgICAgICAgfVxuICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgIH0pO1xuICAgICAgICBjb2xvbml6ZWRJblZpZXcgPSBmYWxzZTtcbiAgICB9XG5cbiAgICBmdW5jdGlvbiBlbnRlckV4dGlycGF0ZWQob25GaW5pc2hlZCkge1xuICAgICAgICBsZXQgbiA9IG51bUV4dGlycGF0ZWQ7XG4gICAgICAgIHN2Zy5zZWxlY3RBbGwoJy5kb3QuRScpXG4gICAgICAgICAgICAuY2xhc3NlZCgnZXh0aXJwYXRlZC12aXNpYmxlJywgdHJ1ZSlcbiAgICAgICAgICAgIC50cmFuc2l0aW9uKClcbiAgICAgICAgICAgIC5kdXJhdGlvbigoZCwgaSkgPT4gTWF0aC5yYW5kb20oKSAqIDIwMCArIDI1MClcbiAgICAgICAgICAgIC5kZWxheSgoZCwgaSkgPT4gKG51bUV4dGlycGF0ZWQgLSBpKSAqIDIwKVxuICAgICAgICAgICAgLmF0dHIoJ2N4JywgZCA9PiBkLmZpbmFsUG9zLngpXG4gICAgICAgICAgICAuYXR0cignY3knLCBkID0+IGQuZmluYWxQb3MueSlcbiAgICAgICAgICAgIC5hdHRyKCdmaWxsJywgZCA9PiBkLmZpbmFsRmlsbClcbiAgICAgICAgICAgIC5vbignZW5kJywgKGQsIGkpID0+IHtcbiAgICAgICAgICAgICAgICBuLS07XG4gICAgICAgICAgICAgICAgaWYgKG4gPT0gMCkge1xuICAgICAgICAgICAgICAgICAgICBpZiAob25GaW5pc2hlZCkge1xuICAgICAgICAgICAgICAgICAgICAgICAgb25GaW5pc2hlZCgpO1xuICAgICAgICAgICAgICAgICAgICB9XG4gICAgICAgICAgICAgICAgfVxuICAgICAgICAgICAgfSk7XG4gICAgICAgIGV4dGlycGF0ZWRJblZpZXcgPSB0cnVlO1xuICAgIH1cblxuICAgIGZ1bmN0aW9uIGV4aXRFeHRpcnBhdGVkKG9uRmluaXNoZWQpIHtcbiAgICAgICAgbGV0IG4gPSBudW1FeHRpcnBhdGVkO1xuICAgICAgICBzdmcuc2VsZWN0QWxsKCcuZG90LkUnKVxuICAgICAgICAgICAgLnRyYW5zaXRpb24oKVxuICAgICAgICAgICAgLmR1cmF0aW9uKChkLCBpKSA9PiBNYXRoLnJhbmRvbSgpICogMjAwICsgMjUwKVxuICAgICAgICAgICAgLmRlbGF5KChkLCBpKSA9PiBpICogMjApXG4gICAgICAgICAgICAuYXR0cignY3gnLCBkID0+IGQuaW5pdFBvcy54KVxuICAgICAgICAgICAgLmF0dHIoJ2N5JywgZCA9PiBkLmluaXRQb3MueSlcbiAgICAgICAgICAgIC5hdHRyKCdmaWxsJywgZCA9PiBkLmluaXRGaWxsKVxuICAgICAgICAgICAgLm9uKCdlbmQnLCAoZCwgaSkgPT4ge1xuICAgICAgICAgICAgICAgIG4tLTtcbiAgICAgICAgICAgICAgICBpZiAobiA9PSAwKSB7XG4gICAgICAgICAgICAgICAgICAgIGlmIChvbkZpbmlzaGVkKSB7XG4gICAgICAgICAgICAgICAgICAgICAgICBvbkZpbmlzaGVkKCk7XG4gICAgICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgICAgICB9XG4gICAgICAgICAgICB9KTtcbiAgICAgICAgZXh0aXJwYXRlZEluVmlldyA9IGZhbHNlO1xuICAgIH1cblxuICAgIGZ1bmN0aW9uIGppZ2dsZShzZWxlY3Rpb24pIHtcbiAgICAgICAgc2VsZWN0aW9uXG4gICAgICAgICAgICAudHJhbnNpdGlvbigpXG4gICAgICAgICAgICAuZHVyYXRpb24oKGQsIGkpID0+IE1hdGgucmFuZG9tKCkgKiAyMDAgKyAxMDApXG4gICAgICAgICAgICAuYXR0cignY3knLCBkID0+IGQuZmluYWxQb3MueSAtIDIpXG4gICAgICAgICAgICAudHJhbnNpdGlvbigpXG4gICAgICAgICAgICAuZHVyYXRpb24oMjAwKVxuICAgICAgICAgICAgLmF0dHIoJ2N5JywgZCA9PiBkLmZpbmFsUG9zLnkpO1xuICAgIH1cblxuICAgIGZ1bmN0aW9uIGhpZ2hsaWdodEV4dGlycGF0ZWQoKSB7XG4gICAgICAgIHN2Zy5zZWxlY3RBbGwoJy5kb3QuRScpLmNhbGwoamlnZ2xlKTtcbiAgICB9XG5cbiAgICBmdW5jdGlvbiBoaWdobGlnaHRDb2xvbml6YXRpb25zKCkge1xuICAgICAgICBzdmcuc2VsZWN0QWxsKCcuZG90LkMnKS5jYWxsKGppZ2dsZSk7XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gYW5pbWF0ZUluKCkge1xuICAgICAgICBhbmltYXRlQ291bnQoZDMuc2VsZWN0KGNvbG9uaXplZENvdW50ZXIpLCAwLCBudW1Db2xvbml6ZWQsIDEyMDApO1xuICAgICAgICBlbnRlckNvbG9uaXplZCgoKSA9PiB7XG4gICAgICAgICAgICBhbmltYXRlQ291bnQoZDMuc2VsZWN0KGV4dGlycGF0ZWRDb3VudGVyKSwgMCwgbnVtRXh0aXJwYXRlZCwgMTIwMCk7XG4gICAgICAgICAgICBlbnRlckV4dGlycGF0ZWQoKCkgPT4ge1xuICAgICAgICAgICAgICAgIGlmIChvbkxvYWQpIHtcbiAgICAgICAgICAgICAgICAgICAgc2V0VGltZW91dCgoKSA9PiBvbkxvYWQoKSwgMTAwMCk7XG4gICAgICAgICAgICAgICAgfVxuICAgICAgICAgICAgfSk7XG4gICAgICAgIH0pO1xuXG4gICAgfVxuICAgIGZ1bmN0aW9uIHNldEN1cnJlbnQoKSB7XG4gICAgICAgIGlmIChjb2xvbml6ZWRJblZpZXcgfHwgZXh0aXJwYXRlZEluVmlldykge1xuICAgICAgICAgICAgLy8gY2xlYXJIaWdobGlnaHQoKTtcbiAgICAgICAgICAgIGV4aXRDb2xvbml6ZWQoKTtcbiAgICAgICAgICAgIGV4aXRFeHRpcnBhdGVkKCk7XG4gICAgICAgIH1cbiAgICB9XG5cbiAgICBmdW5jdGlvbiBzZXRDb2xvbml6ZWQoKSB7XG4gICAgICAgIGlmICghY29sb25pemVkSW5WaWV3KSB7XG4gICAgICAgICAgICBlbnRlckNvbG9uaXplZCgpO1xuICAgICAgICB9IGVsc2Uge1xuICAgICAgICAgICAgaGlnaGxpZ2h0Q29sb25pemF0aW9ucygpXG4gICAgICAgIH1cbiAgICB9XG5cbiAgICBmdW5jdGlvbiBzZXRFeHRpcnBhdGVkKCkge1xuICAgICAgICBpZiAoIWV4dGlycGF0ZWRJblZpZXcpIHtcbiAgICAgICAgICAgIGVudGVyRXh0aXJwYXRlZCgpO1xuICAgICAgICB9IGVsc2Uge1xuICAgICAgICAgICAgaGlnaGxpZ2h0RXh0aXJwYXRlZCgpO1xuICAgICAgICB9XG4gICAgfVxuXG4gICAgcmV0dXJuIHtcbiAgICAgICAgYW5pbWF0ZUluOiBhbmltYXRlSW4sXG4gICAgICAgIHN2Zzogc3ZnQ29udGFpbmVyLm5vZGUoKSxcbiAgICAgICAgbnVtQ29sb25pemVkOiBudW1Db2xvbml6ZWQsXG4gICAgICAgIG51bUN1cnJlbnQ6IG51bUN1cnJlbnQsXG4gICAgICAgIG51bUV4dGlycGF0ZWQ6IG51bUV4dGlycGF0ZWQsXG4gICAgICAgIGVudGVyRXh0aXJwYXRlZDogZW50ZXJFeHRpcnBhdGVkLFxuICAgICAgICBlbnRlckNvbG9uaXplZDogZW50ZXJDb2xvbml6ZWQsXG4gICAgICAgIHNldEV4dGlycGF0ZWQ6IHNldEV4dGlycGF0ZWQsXG4gICAgICAgIHNldENvbG9uaXplZDogc2V0Q29sb25pemVkLFxuICAgICAgICBzZXRDdXJyZW50OiBzZXRDdXJyZW50LFxuICAgICAgICBkYXRhOiBkYXRhXG4gICAgfVxufVxuXG5mdW5jdGlvbiBCaXJkRG90cyhwYXJhbXMpIHtcbiAgICBjb25zdCB7XG4gICAgICAgIGVsZW1lbnQsIGRhdGFVcmwsIHNlYXNvbixcbiAgICAgICAgcGFyaywgY3VycmVudENvdW50ZXIsIGNvbG9uaXplZENvdW50ZXIsXG4gICAgICAgIGV4dGlycGF0ZWRDb3VudGVyLCBvbkxvYWQsIGluaXRTdGF0c30gPSBwYXJhbXM7XG5cbiAgICBsZXQgX3NlYXNvbiA9IHNlYXNvbjtcbiAgICBsZXQgc3VtbWVyRG90cywgd2ludGVyRG90cztcbiAgICBsZXQgcmVhZHkgPSBmYWxzZTtcbiAgICBsZXQgbm9kZSA9IGQzLnNlbGVjdChlbGVtZW50KS5hcHBlbmQoJ2RpdicpXG4gICAgICAgICAgICAgICAgLmNsYXNzZWQoJ2JpcmQtZG90LWNvbnRhaW5lcicsIHRydWUpO1xuXG4gICAgZDMuY3N2KGRhdGFVcmwsIChlcnJvciwgZGF0YSkgPT4ge1xuICAgICAgICBpZiAoZXJyb3IpIHtcbiAgICAgICAgICAgIGNvbnNvbGUubG9nKCdlcnJvcicsIGVycm9yKTtcbiAgICAgICAgICAgIHJldHVybjtcbiAgICAgICAgfVxuXG4gICAgICAgIGxldCBwYXJrUm93ID0gZGF0YS5maW5kKGQgPT4gZC51bml0X25hbWUgPT0gcGFyayk7XG5cbiAgICAgICAgbGV0IHN1bW1lclBhcmFtcyA9IHtcbiAgICAgICAgICAgIGVsZW1lbnQ6IG5vZGUubm9kZSgpLFxuICAgICAgICAgICAgbnVtQ3VycmVudDogK3BhcmtSb3cuY3VycmVudF9zcGVjaWVzX3N1bW1lcixcbiAgICAgICAgICAgIG51bUNvbG9uaXplZDogK3BhcmtSb3cubm9fY29sb25pemF0aW9uc19zdW1tZXIsXG4gICAgICAgICAgICBudW1FeHRpcnBhdGVkOiArcGFya1Jvdy5ub19leHRpcnBhdGlvbnNfc3VtbWVyXG4gICAgICAgIH07XG5cbiAgICAgICAgbGV0IHdpbnRlclBhcmFtcyA9IHtcbiAgICAgICAgICAgIGVsZW1lbnQ6IG5vZGUubm9kZSgpLFxuICAgICAgICAgICAgbnVtQ3VycmVudDogK3BhcmtSb3cuY3VycmVudF9zcGVjaWVzX3dpbnRlcixcbiAgICAgICAgICAgIG51bUNvbG9uaXplZDogK3BhcmtSb3cubm9fY29sb25pemF0aW9uc193aW50ZXIsXG4gICAgICAgICAgICBudW1FeHRpcnBhdGVkOiArcGFya1Jvdy5ub19leHRpcnBhdGlvbnNfd2ludGVyXG4gICAgICAgIH1cblxuICAgICAgICBzdW1tZXJEb3RzID0gbmV3IF9CaXJkRG90cyhzdW1tZXJQYXJhbXMpO1xuICAgICAgICB3aW50ZXJEb3RzID0gbmV3IF9CaXJkRG90cyh3aW50ZXJQYXJhbXMpO1xuXG4gICAgICAgIGluaXRDaGFydChfc2Vhc29uLCBpbml0U3RhdHMpO1xuICAgICAgICByZWFkeSA9IHRydWU7XG4gICAgICAgIGlmIChvbkxvYWQpIHtcbiAgICAgICAgICAgIG9uTG9hZCgpO1xuICAgICAgICB9XG4gICAgfSk7XG5cbiAgICBmdW5jdGlvbiBpbml0Q2hhcnQoc2Vhc29uLCBpbml0U3RhdHMpIHtcbiAgICAgICAgbGV0IHBsb3Q7XG4gICAgICAgIGlmIChzZWFzb24gPT09ICdzdW1tZXInKSB7XG4gICAgICAgICAgICBkMy5zZWxlY3Qod2ludGVyRG90cy5zdmcpLnN0eWxlKCdvcGFjaXR5JywgMCk7XG4gICAgICAgICAgICBkMy5zZWxlY3Qoc3VtbWVyRG90cy5zdmcpLnN0eWxlKCdvcGFjaXR5JywgMSk7XG4gICAgICAgICAgICBwbG90ID0gc3VtbWVyRG90cztcbiAgICAgICAgfSBlbHNlIHtcbiAgICAgICAgICAgIGQzLnNlbGVjdCh3aW50ZXJEb3RzLnN2Zykuc3R5bGUoJ29wYWNpdHknLCAxKTtcbiAgICAgICAgICAgIGQzLnNlbGVjdChzdW1tZXJEb3RzLnN2Zykuc3R5bGUoJ29wYWNpdHknLCAwKTtcbiAgICAgICAgICAgIHBsb3QgPSB3aW50ZXJEb3RzO1xuICAgICAgICB9XG4gICAgICAgIGlmIChpbml0U3RhdHMpIHtcbiAgICAgICAgICAgIGQzLnNlbGVjdChjb2xvbml6ZWRDb3VudGVyKS50ZXh0KHBsb3QubnVtQ29sb25pemVkKTtcbiAgICAgICAgICAgIGQzLnNlbGVjdChleHRpcnBhdGVkQ291bnRlcikudGV4dChwbG90Lm51bUV4dGlycGF0ZWQpO1xuICAgICAgICAgICAgZDMuc2VsZWN0KGN1cnJlbnRDb3VudGVyKS50ZXh0KHBsb3QubnVtQ3VycmVudCk7XG4gICAgICAgIH1cbiAgICB9XG5cbiAgICBmdW5jdGlvbiBfYW5pbWF0ZUluKG9uRmluaXNoZWQpIHtcbiAgICAgICAgLy8gc2hvdWxkIGJlIGNhbGxlZCBhZnRlciByZWFkeSB0byBiZSBpbml0ZWRcbiAgICAgICAgbGV0IHBsb3Q7XG4gICAgICAgIGlmIChfc2Vhc29uID09PSAnc3VtbWVyJykge1xuICAgICAgICAgICAgcGxvdCA9IHN1bW1lckRvdHM7XG4gICAgICAgIH0gZWxzZSB7XG4gICAgICAgICAgICBwbG90ID0gd2ludGVyRG90cztcbiAgICAgICAgfVxuXG4gICAgICAgIGQzLnNlbGVjdChjdXJyZW50Q291bnRlcikudGV4dChwbG90Lm51bUN1cnJlbnQpO1xuICAgICAgICBhbmltYXRlQ291bnQoZDMuc2VsZWN0KGNvbG9uaXplZENvdW50ZXIpLCAwLCBwbG90Lm51bUNvbG9uaXplZCwgMTIwMCk7XG4gICAgICAgIHBsb3QuZW50ZXJDb2xvbml6ZWQoKCkgPT4ge1xuICAgICAgICAgICAgYW5pbWF0ZUNvdW50KGQzLnNlbGVjdChleHRpcnBhdGVkQ291bnRlciksIDAsIHBsb3QubnVtRXh0aXJwYXRlZCwgMTIwMCk7XG4gICAgICAgICAgICBwbG90LmVudGVyRXh0aXJwYXRlZCgoKSA9PiB7XG4gICAgICAgICAgICAgICAgaWYgKG9uRmluaXNoZWQpIHtcbiAgICAgICAgICAgICAgICAgICAgc2V0VGltZW91dCgoKSA9PiBvbkZpbmlzaGVkKCksIDEwMDApO1xuICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgIH0pO1xuICAgICAgICB9KTtcbiAgICB9XG5cbiAgICBmdW5jdGlvbiBhbmltYXRlSW4ob25GaW5pc2hlZCkge1xuICAgICAgICBpZiAocmVhZHkpIHtcbiAgICAgICAgICAgIF9hbmltYXRlSW4ob25GaW5pc2hlZCk7XG4gICAgICAgIH1cbiAgICB9XG5cbiAgICBmdW5jdGlvbiBmYWRlT3V0KGVsKSB7XG4gICAgICAgIGVsLnRyYW5zaXRpb24oKVxuICAgICAgICAgICAgLmR1cmF0aW9uKDIwMClcbiAgICAgICAgICAgIC5lYXNlKGQzLmVhc2VRdWFkT3V0KVxuICAgICAgICAgICAgLnN0eWxlKCdvcGFjaXR5JywgMCk7XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gZmFkZUluKGVsKSB7XG4gICAgICAgIGVsLnRyYW5zaXRpb24oKVxuICAgICAgICAgICAgLmR1cmF0aW9uKDIwMClcbiAgICAgICAgICAgIC5kZWxheSgyMDApXG4gICAgICAgICAgICAuZWFzZShkMy5lYXNlUXVhZE91dClcbiAgICAgICAgICAgIC5zdHlsZSgnb3BhY2l0eScsIDEpO1xuICAgIH1cblxuICAgIGZ1bmN0aW9uIHNldFNlYXNvbihzZWFzb24pIHtcbiAgICAgICAgaWYgKHNlYXNvbiA9PT0gX3NlYXNvbikge1xuICAgICAgICAgICAgcmV0dXJuO1xuICAgICAgICB9XG5cbiAgICAgICAgX3NlYXNvbiA9IHNlYXNvbjtcblxuICAgICAgICBpZiAoIXJlYWR5KSB7XG4gICAgICAgICAgICByZXR1cm47XG4gICAgICAgIH1cblxuICAgICAgICBpZiAoc2Vhc29uID09PSAnc3VtbWVyJykge1xuICAgICAgICAgICAgZDMuc2VsZWN0KHdpbnRlckRvdHMuc3ZnKS5jYWxsKGZhZGVPdXQpO1xuICAgICAgICAgICAgZDMuc2VsZWN0KHN1bW1lckRvdHMuc3ZnKS5jYWxsKGZhZGVJbik7XG5cbiAgICAgICAgICAgIGQzLnNlbGVjdChjb2xvbml6ZWRDb3VudGVyKS50ZXh0KHN1bW1lckRvdHMubnVtQ29sb25pemVkKTtcbiAgICAgICAgICAgIGQzLnNlbGVjdChleHRpcnBhdGVkQ291bnRlcikudGV4dChzdW1tZXJEb3RzLm51bUV4dGlycGF0ZWQpO1xuICAgICAgICAgICAgZDMuc2VsZWN0KGN1cnJlbnRDb3VudGVyKS50ZXh0KHN1bW1lckRvdHMubnVtQ3VycmVudCk7XG4gICAgICAgIH0gZWxzZSB7XG4gICAgICAgICAgICBkMy5zZWxlY3Qoc3VtbWVyRG90cy5zdmcpLmNhbGwoZmFkZU91dCk7XG4gICAgICAgICAgICBkMy5zZWxlY3Qod2ludGVyRG90cy5zdmcpLmNhbGwoZmFkZUluKTtcblxuICAgICAgICAgICAgZDMuc2VsZWN0KGNvbG9uaXplZENvdW50ZXIpLnRleHQod2ludGVyRG90cy5udW1Db2xvbml6ZWQpO1xuICAgICAgICAgICAgZDMuc2VsZWN0KGV4dGlycGF0ZWRDb3VudGVyKS50ZXh0KHdpbnRlckRvdHMubnVtRXh0aXJwYXRlZCk7XG4gICAgICAgICAgICBkMy5zZWxlY3QoY3VycmVudENvdW50ZXIpLnRleHQod2ludGVyRG90cy5udW1DdXJyZW50KTtcbiAgICAgICAgfVxuICAgIH1cblxuICAgIGZ1bmN0aW9uIHNldEV4dGlycGF0ZWQoKSB7XG4gICAgICAgIGlmICghcmVhZHkpIHtcbiAgICAgICAgICAgIHJldHVybjtcbiAgICAgICAgfVxuXG4gICAgICAgIHN1bW1lckRvdHMuc2V0RXh0aXJwYXRlZCgpO1xuICAgICAgICB3aW50ZXJEb3RzLnNldEV4dGlycGF0ZWQoKTtcbiAgICB9XG5cbiAgICBmdW5jdGlvbiBzZXRDdXJyZW50KCkge1xuICAgICAgICBpZiAoIXJlYWR5KSB7XG4gICAgICAgICAgICByZXR1cm47XG4gICAgICAgIH1cblxuICAgICAgICBzdW1tZXJEb3RzLnNldEN1cnJlbnQoKTtcbiAgICAgICAgd2ludGVyRG90cy5zZXRDdXJyZW50KCk7XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gc2V0Q29sb25pemVkKCkge1xuICAgICAgICBpZiAoIXJlYWR5KSB7XG4gICAgICAgICAgICByZXR1cm47XG4gICAgICAgIH1cblxuICAgICAgICBzdW1tZXJEb3RzLnNldENvbG9uaXplZCgpO1xuICAgICAgICB3aW50ZXJEb3RzLnNldENvbG9uaXplZCgpO1xuICAgIH1cblxuICAgIHJldHVybiB7XG4gICAgICAgIGFuaW1hdGVJbjogYW5pbWF0ZUluLFxuICAgICAgICBzZXRTZWFzb246IHNldFNlYXNvbixcbiAgICAgICAgc2V0RXh0aXJwYXRlZDogc2V0RXh0aXJwYXRlZCxcbiAgICAgICAgc2V0Q29sb25pemVkOiBzZXRDb2xvbml6ZWQsXG4gICAgICAgIHNldEN1cnJlbnQ6IHNldEN1cnJlbnRcbiAgICB9XG59XG5cbmxldCBCaXJkRG90c0Jhc2UgPSBfQmlyZERvdHM7XG5leHBvcnQgeyBCaXJkRG90cywgQmlyZERvdHNCYXNlLCBhbmltYXRlQ291bnQsIEdyaWRIZWxwZXJ9O1xuIiwiaW1wb3J0IHsgQmlyZERvdHNCYXNlLCBhbmltYXRlQ291bnR9IGZyb20gJy4vYmlyZERvdC5qcyc7XG5cbmxldCBJTUFHRVMgPSB7XG4gIHdhcmJsZXI6ICdodHRwczovL2Nkbi5hdWR1Ym9uLm9yZy9jZG4vZmFyZnV0dXJlL1FYTFJ4U1EwZnNGVmcyMVB0dXFPNm1JSXZLOTVRZ3hvTl9TakN2eklNb0EvbXRpbWU6MTUyMTIyNjEwNi9zaXRlcy9kZWZhdWx0L2ZpbGVzL3dhcmJsZXIyeC5wbmcnLFxuICB3b29kcGVja2VyOiAnaHR0cHM6Ly9jZG4uYXVkdWJvbi5vcmcvY2RuL2ZhcmZ1dHVyZS90dmdvSnZmTzBrZGUyWU9OZ2JEUDlGMGozY1Q3dENMSzZxMWxzNGd2VTNZL210aW1lOjE1MjEyMjYxNDAvc2l0ZXMvZGVmYXVsdC9maWxlcy93b29kcGVja2VyMngucG5nJyxcbiAgZWdyZXQ6ICdodHRwczovL2Nkbi5hdWR1Ym9uLm9yZy9jZG4vZmFyZnV0dXJlL0x0b1RmX25wT2ZDOTd1ZVhoXzBoVE13a00wMGRuVnFSTUtnRmJ1cTFuMDAvbXRpbWU6MTUyMTIyNjE3NC9zaXRlcy9kZWZhdWx0L2ZpbGVzL2VncmV0MngucG5nJyxcbiAgZ3Jvc2JlYWs6ICdodHRwczovL2Nkbi5hdWR1Ym9uLm9yZy9jZG4vZmFyZnV0dXJlLzlEeEtVZmN3N3lzMzVHeW82eS1TWjl4VWQyME0wZV8yRTVLeVZyb2ROemsvbXRpbWU6MTUyMTIyNjM0MC9zaXRlcy9kZWZhdWx0L2ZpbGVzL2dyb3NiZWFrMngucG5nJyxcbiAgcm9iaW46ICdodHRwczovL2Nkbi5hdWR1Ym9uLm9yZy9jZG4vZmFyZnV0dXJlL3djM3hsYmZsTzk3SW91eTJ1anpMR2E2eDVUc2R2enhOdjRzWk9IemZJeVUvbXRpbWU6MTUyMTIyNjM3OS9zaXRlcy9kZWZhdWx0L2ZpbGVzL3JvYmluMngucG5nJ1xufVxuXG5cbmZ1bmN0aW9uIEJpcmREb3RMYW5kaW5nUGFnZShwYXJhbXMpIHtcbiAgY29uc3QgeyBlbGVtZW50IH0gPSBwYXJhbXM7XG4gIGxldCBub2RlID0gZDMuc2VsZWN0KGVsZW1lbnQpLmFwcGVuZCgnZGl2JylcbiAgICAgICAgICAgICAgLmNsYXNzZWQoJ2JpcmQtZG90LWxhbmRpbmctcGFnZScsIHRydWUpO1xuXG4gIGxldCByb3cgPSBub2RlLmFwcGVuZCgnZGl2JylcbiAgICAuY2xhc3NlZCgnY291bnRlci1yb3cnLCB0cnVlKTtcblxuICBsZXQgYmlyZERvdHMgPSBuZXcgQmlyZERvdHNCYXNlKHtcbiAgICAgIGVsZW1lbnQ6IG5vZGUubm9kZSgpLFxuICAgICAgc2NhbGU6IDIuNSxcbiAgICAgIG51bUN1cnJlbnQ6IDgzLFxuICAgICAgbnVtQ29sb25pemVkOiAxMyxcbiAgICAgIG51bUV4dGlycGF0ZWQ6IDIwLFxuICAgICAgbnVtQ29sczogNVxuICAgIH1cbiAgKTtcblxuICAvLyB0aGlzIGlzIGluIHRoZSByZWZlcmVuY2UgZnJhbWUgb2YgdGhlIGV4aXN0aW5nIGRvdHNcbiAgbGV0IHN2ZyA9IGQzLnNlbGVjdChiaXJkRG90cy5zdmcpLnNlbGVjdCgnZycpO1xuXG4gIGxldCBjdXJyZW50Q291bnRlciA9IHJvdy5hcHBlbmQoJ2RpdicpXG4gICAgLmNsYXNzZWQoJ2NvdW50ZXInLCB0cnVlKVxuICAgIC5jbGFzc2VkKCdjdXJyZW50LWNvdW50ZXInLCB0cnVlKVxuICAgIC5odG1sKGBcbiAgICAgIDxwPlNwZWNpZXMgY3VycmVudGx5IGluIHRoZSBwYXJrPC9wPlxuICAgICAgPGgyPjgzPC9oMj5cbiAgICBgKVxuXG4gIGxldCBjb2xvbml6ZWRDb3VudGVyID0gcm93LmFwcGVuZCgnZGl2JylcbiAgICAuY2xhc3NlZCgnY291bnRlcicsIHRydWUpXG4gICAgLmNsYXNzZWQoJ2NvbG9uaXplZC1jb3VudGVyJywgdHJ1ZSlcbiAgICAuc3R5bGUoJ29wYWNpdHknLCAwKVxuICAgIC5odG1sKGBcbiAgICAgIDxwPlBvdGVudGlhbCBjb2xvbml6YXRpb248L3A+XG4gICAgICA8aDI+MDwvaDI+XG4gICAgYClcblxuICBsZXQgZXh0aXJwYXRlZENvdW50ZXIgPSByb3cuYXBwZW5kKCdkaXYnKVxuICAgIC5jbGFzc2VkKCdjb3VudGVyJywgdHJ1ZSlcbiAgICAuY2xhc3NlZCgnZXh0aXJwYXRlZC1jb3VudGVyJywgdHJ1ZSlcbiAgICAuc3R5bGUoJ29wYWNpdHknLCAwKVxuICAgIC5odG1sKGBcbiAgICAgIDxwPlBvdGVudGlhbCBleHRpcnBhdGlvbjwvcD5cbiAgICAgIDxoMj4wPC9oMj5cbiAgICBgKVxuXG4gIGxldCBjYWxsb3V0RyA9IHN2Zy5hcHBlbmQoJ2cnKVxuICAgIC5hdHRyKCdjbGFzcycsICdiaXJkLWNhbGxvdXRzJyk7XG5cbiAgbGV0IGNhbGxvdXREaXN0YW5jZSA9IDcwO1xuICBsZXQgY2FsbG91dFJhZGl1cyA9IDQ3O1xuXG4gIGZ1bmN0aW9uIGRyYXdDYWxsb3V0KG4sIGluaXRpYWwsIG5hbWUsIGltYWdlLCBjbGFzc3R5cGUsIGxlZnRPclJpZ2h0KSB7XG4gICAgbGV0IHBvcyA9IGluaXRpYWwgPyBiaXJkRG90cy5kYXRhW24gLSAxXS5pbml0UG9zIDogYmlyZERvdHMuZGF0YVtuIC0gMV0uZmluYWxQb3M7XG4gICAgbGV0IHRhcmdldCA9IHN2Zy5zZWxlY3QoYC5kb3Q6bnRoLWNoaWxkKCR7bn0pYCk7XG5cbiAgICBsZXQgc2lkZSA9IChsZWZ0T3JSaWdodCA9PSAnbGVmdCcpID8gMTogLTE7XG5cbiAgICBsZXQgY2FsbG91dCA9IGNhbGxvdXRHLmFwcGVuZCgnZycpXG4gICAgICAuY2xhc3NlZCgnYmlyZC1jYWxsb3V0JywgdHJ1ZSlcbiAgICAgIC5jbGFzc2VkKGNsYXNzdHlwZSwgdHJ1ZSlcbiAgICAgIC5hdHRyKCd0cmFuc2Zvcm0nLCBgdHJhbnNsYXRlKCR7cG9zLnggLSBzaWRlICogY2FsbG91dERpc3RhbmNlfSwgJHtwb3MueX0pYClcbiAgICAgIC5hdHRyKCdvcGFjaXR5JywgMCk7XG5cbiAgICBjYWxsb3V0LmFwcGVuZCgnY2lyY2xlJylcbiAgICAgIC5hdHRyKCdjeCcsIDApXG4gICAgICAuYXR0cignY3knLCAwKVxuICAgICAgLmF0dHIoJ3InLCBjYWxsb3V0UmFkaXVzKTtcblxuICAgIGNhbGxvdXQuYXBwZW5kKCdjbGlwUGF0aCcpXG4gICAgICAuYXR0cignaWQnLCAnYmlyZC1jYWxsb3V0LWNsaXAtcGF0aCcpXG4gICAgICAuYXBwZW5kKCdjaXJjbGUnKVxuICAgICAgICAuYXR0cignY3gnLCAwKVxuICAgICAgICAuYXR0cignY3knLCAwKVxuICAgICAgICAuYXR0cigncicsIGNhbGxvdXRSYWRpdXMpO1xuXG4gICAgY2FsbG91dC5hcHBlbmQoJ2ltYWdlJylcbiAgICAgIC5hdHRyKCdjbGFzcycsICdiaXJkLWNhbGxvdXQtaW1hZ2UnKVxuICAgICAgLmF0dHIoJ3gnLCAtNDcpXG4gICAgICAuYXR0cigneScsIC00NylcbiAgICAgIC5hdHRyKCdoZWlnaHQnLCA5NSlcbiAgICAgIC5hdHRyKCd3aWR0aCcsIDk1KVxuICAgICAgLmF0dHIoJ2NsaXAtcGF0aCcsIChkLCBpKSA9PiBgdXJsKCNiaXJkLWNhbGxvdXQtY2xpcC1wYXRoKWApXG4gICAgICAuYXR0cigneGxpbms6aHJlZicsIGltYWdlKTtcblxuICAgIGNhbGxvdXQuYXBwZW5kKCd0ZXh0JylcbiAgICAgIC5hdHRyKCd4JywgMClcbiAgICAgIC5hdHRyKCd5JywgY2FsbG91dFJhZGl1cyArIDE2KVxuICAgICAgLmF0dHIoJ3RleHQtYW5jaG9yJywgJ21pZGRsZScpXG4gICAgICAudGV4dChuYW1lKTtcblxuICAgIGNhbGxvdXQuYXBwZW5kKCdsaW5lJylcbiAgICAgIC5hdHRyKCd4MScsIHNpZGUgKiBjYWxsb3V0UmFkaXVzKVxuICAgICAgLmF0dHIoJ3kxJywgMClcbiAgICAgIC5hdHRyKCd4MicsIC0gc2lkZSAqIHRhcmdldC5hdHRyKCdyJykgKyBzaWRlICogY2FsbG91dERpc3RhbmNlKVxuICAgICAgLmF0dHIoJ3kyJywgMCk7XG5cbiAgICByZXR1cm4gY2FsbG91dDtcbiAgfVxuXG4gIGZ1bmN0aW9uIGZhZGVJbihlbGVtZW50KSB7XG4gICAgZWxlbWVudC50cmFuc2l0aW9uKClcbiAgICAgIC5kdXJhdGlvbigxMDAwKVxuICAgICAgLmF0dHIoJ29wYWNpdHknLCAxKTtcbiAgfVxuXG4gIGZ1bmN0aW9uIGZhZGVPdXQoZWxlbWVudCkge1xuICAgIGVsZW1lbnQudHJhbnNpdGlvbigpXG4gICAgICAuZHVyYXRpb24oNjAwKVxuICAgICAgLmF0dHIoJ29wYWNpdHknLCAwKTtcbiAgfVxuXG4gIGRyYXdDYWxsb3V0KDMyLCB0cnVlLCAnR3JlYXQgRWdyZXQnLCBJTUFHRVMuZWdyZXQsICdjdXJyZW50JywgJ2xlZnQnKS5jYWxsKGZhZGVJbik7XG4gIGRyYXdDYWxsb3V0KDQ2LCB0cnVlLCBcIk51dGFsbCdzIFdvb2RwZWNrZXJcIiwgSU1BR0VTLndvb2RwZWNrZXIsICdjdXJyZW50JywgJ3JpZ2h0JykuY2FsbChmYWRlSW4pO1xuICBkcmF3Q2FsbG91dCg3MiwgdHJ1ZSwgXCJXaWxzb24ncyBXYXJibGVyXCIsIElNQUdFUy53YXJibGVyLCAnY3VycmVudCcsICdsZWZ0JykuY2FsbChmYWRlSW4pO1xuXG4gIGxldCByb2JpbiA9IGRyYXdDYWxsb3V0KDg2LCB0cnVlLCBcIkFtZXJpY2FuIFJvYmluXCIsIElNQUdFUy5yb2JpbiwgJ2N1cnJlbnQnLCAncmlnaHQnKS5jYWxsKGZhZGVJbik7XG5cbiAgLy8gZHJhdyB0aGUgZ3Jvc2JlYWsgd2hlcmUgaXQgd2lsbCBiZVxuICBsZXQgYmlyZFBvcyA9IGJpcmREb3RzLmRhdGFbNl0uZmluYWxQb3M7XG4gIGxldCBncm9zYmVhayA9IGRyYXdDYWxsb3V0KDYsIGZhbHNlLCBcIkJsdWUgR3Jvc2JlYWtcIiwgSU1BR0VTLmdyb3NiZWFrLCAnY29sb25pemVkJywgJ3JpZ2h0JykuYXR0cignb3BhY2l0eScsIDApO1xuXG4gIGZ1bmN0aW9uIHNob3dDdXJyZW50KCkge1xuICAgIGN1cnJlbnRDb3VudGVyLnRyYW5zaXRpb24oKVxuICAgICAgLmRlbGF5KDIwMClcbiAgICAgIC5kdXJhdGlvbig0MDApXG4gICAgICAuc3R5bGUoJ29wYWNpdHknLCAxKTtcblxuICAgIGNvbG9uaXplZENvdW50ZXIudHJhbnNpdGlvbigpXG4gICAgICAuZHVyYXRpb24oMzAwKVxuICAgICAgLnN0eWxlKCdvcGFjaXR5JywgMCk7XG5cbiAgICBleHRpcnBhdGVkQ291bnRlci50cmFuc2l0aW9uKClcbiAgICAgIC5kdXJhdGlvbigzMDApXG4gICAgICAuc3R5bGUoJ29wYWNpdHknLCAwKTtcblxuICAgIGJpcmREb3RzLnNldEN1cnJlbnQoKTtcbiAgICBncm9zYmVhay5jYWxsKGZhZGVPdXQpO1xuICAgIGxldCBiaXJkUG9zID0gYmlyZERvdHMuZGF0YVs4NV0uaW5pdFBvcztcbiAgICByb2Jpbi5jbGFzc2VkKCdjdXJyZW50JywgdHJ1ZSk7XG4gICAgcm9iaW4udHJhbnNpdGlvbigpXG4gICAgICAuZHVyYXRpb24oMTAwMClcbiAgICAgIC5hdHRyKCd0cmFuc2Zvcm0nLCBgdHJhbnNsYXRlKCR7YmlyZFBvcy54ICsgY2FsbG91dERpc3RhbmNlfSwgJHtiaXJkUG9zLnl9KWApO1xuICB9XG5cbiAgZnVuY3Rpb24gc2hvd0xhdGVyKCkge1xuICAgIGN1cnJlbnRDb3VudGVyLnRyYW5zaXRpb24oKVxuICAgICAgLy8gLmRlbGF5KDIwMClcbiAgICAgIC5kdXJhdGlvbig0MDApXG4gICAgICAuc3R5bGUoJ29wYWNpdHknLCAwKTtcblxuICAgIGNvbG9uaXplZENvdW50ZXIuc2VsZWN0KCdoMicpLnRleHQoMCk7XG4gICAgZXh0aXJwYXRlZENvdW50ZXIuc2VsZWN0KCdoMicpLnRleHQoMCk7XG4gICAgY29sb25pemVkQ291bnRlci50cmFuc2l0aW9uKClcbiAgICAgIC5kdXJhdGlvbigzMDApXG4gICAgICAuZGVsYXkoMTAwKVxuICAgICAgLnN0eWxlKCdvcGFjaXR5JywgMSk7XG5cbiAgICBleHRpcnBhdGVkQ291bnRlci50cmFuc2l0aW9uKClcbiAgICAgIC5kdXJhdGlvbigzMDApXG4gICAgICAuZGVsYXkoMTAwKVxuICAgICAgLnN0eWxlKCdvcGFjaXR5JywgMSk7XG5cbiAgICBhbmltYXRlQ291bnQoY29sb25pemVkQ291bnRlci5zZWxlY3QoJ2gyJyksIDAsIDEzLCAxNTAwKTtcblxuICAgIGJpcmREb3RzLmVudGVyQ29sb25pemVkKCgpID0+IHtcbiAgICAgICAgZ3Jvc2JlYWsudHJhbnNpdGlvbigpXG4gICAgICAgICAgLmR1cmF0aW9uKDEwMDApXG4gICAgICAgICAgLmF0dHIoJ29wYWNpdHknLCAxKTtcblxuICAgICAgICBzZXRUaW1lb3V0KCgpID0+IHtcbiAgICAgICAgICAgICAgYW5pbWF0ZUNvdW50KGV4dGlycGF0ZWRDb3VudGVyLnNlbGVjdCgnaDInKSwgMCwgMjAsIDEwMDApO1xuICAgICAgICAgICAgICBsZXQgYmlyZFBvcyA9IGJpcmREb3RzLmRhdGFbODVdLmZpbmFsUG9zO1xuICAgICAgICAgICAgICByb2Jpbi5jbGFzc2VkKCdjdXJyZW50JywgZmFsc2UpO1xuICAgICAgICAgICAgICByb2Jpbi50cmFuc2l0aW9uKClcbiAgICAgICAgICAgICAgICAuZHVyYXRpb24oMTAwMClcbiAgICAgICAgICAgICAgICAuYXR0cigndHJhbnNmb3JtJywgYHRyYW5zbGF0ZSgke2JpcmRQb3MueCArIGNhbGxvdXREaXN0YW5jZX0sICR7YmlyZFBvcy55fSlgKTtcblxuICAgICAgICAgICAgICByb2Jpbi5zZWxlY3QoJ2xpbmUnKVxuICAgICAgICAgICAgICAgIC5hdHRyKCdzdHJva2UnLCAnIzkwZDJkOCcpXG4gICAgICAgICAgICAgICAgLnRyYW5zaXRpb24oKVxuICAgICAgICAgICAgICAgIC5kdXJhdGlvbigxMDAwKVxuICAgICAgICAgICAgICAgICAgLmF0dHIoJ3N0cm9rZScsICcjZThjNTc4Jyk7XG4gICAgICAgICAgICAgICAgICAvLyAuYXR0cignb3BhY2l0eScsIDEpO1xuXG4gICAgICAgICAgICAgIHJvYmluLnNlbGVjdCgnY2lyY2xlJylcbiAgICAgICAgICAgICAgICAuYXR0cignc3Ryb2tlJywgJyM5MGQyZDgnKVxuICAgICAgICAgICAgICAgIC5hdHRyKCdmaWxsJywgJyM5MGQyZDgnKVxuICAgICAgICAgICAgICAgIC50cmFuc2l0aW9uKClcbiAgICAgICAgICAgICAgICAuZHVyYXRpb24oMTAwMClcbiAgICAgICAgICAgICAgICAgIC5hdHRyKCdzdHJva2UnLCAnI2U4YzU3OCcpXG4gICAgICAgICAgICAgICAgICAuYXR0cignZmlsbCcsICcjZThjNTc4Jyk7XG5cbiAgICAgICAgICAgICAgYmlyZERvdHMuZW50ZXJFeHRpcnBhdGVkKCk7XG4gICAgICAgIH0sIDEwMDApO1xuICAgIH0pO1xuICB9XG5cbiAgcmV0dXJuIHtcbiAgICBzaG93Q3VycmVudDogc2hvd0N1cnJlbnQsXG4gICAgc2hvd0xhdGVyOiBzaG93TGF0ZXJcbiAgfVxuXG59XG5cbmV4cG9ydCB7IEJpcmREb3RMYW5kaW5nUGFnZSB9O1xuIiwiaW1wb3J0IHsgQmlyZERvdHMsIEJpcmREb3RzQmFzZX0gZnJvbSAnLi9iaXJkRG90LmpzJztcbmltcG9ydCB7IEJpcmREb3RMYW5kaW5nUGFnZSB9IGZyb20gJy4vYmlyZERvdExhbmRpbmdQYWdlLmpzJztcbmltcG9ydCB7IFR1cm5vdmVyQ2hhcnQgfSBmcm9tICcuL3R1cm5vdmVyLmpzJztcbmltcG9ydCB7IFBhcmtNYXAgfSBmcm9tICcuL3BhcmtNYXAuanMnO1xuaW1wb3J0IHsgQWxsUGFya3MgfSBmcm9tICcuL2FsbFBhcmtzLmpzJztcblxud2luZG93LlN0YW1lbkF1ZHVib25QYXJrcyA9IHtcbiAgQmlyZERvdHNCYXNlOiBCaXJkRG90c0Jhc2UsXG4gIEJpcmREb3RzOiBCaXJkRG90cyxcbiAgQmlyZERvdExhbmRpbmdQYWdlOiBCaXJkRG90TGFuZGluZ1BhZ2UsXG4gIFBhcmtNYXA6IFBhcmtNYXAsXG4gIFR1cm5vdmVyQ2hhcnQ6IFR1cm5vdmVyQ2hhcnQsXG4gIEFsbFBhcmtzOiBBbGxQYXJrc1xufTtcbiIsImltcG9ydCB7YWxiZXJzQmlnQWxhc2thfSBmcm9tICcuL2FsYmVyc0JpZ0FsYXNrYSc7XG4vKlxuICBQYXJrIE1hcFxuXG4gIGVsZW1lbnRcbiAgc2Vhc29uICdzdW1tZXInIG9yICd3aW50ZXInXG4gIG1ldHJpY1xuICBzaGFwZVVybDogcGF0aCB0byB0aGUgdXMgYm91bmRhcmllcyBkYXRhc2V0XG4gIGRhdGFVcmw6IHBhdGggdG8gdGhlIGNvbG9uaXphdGlvbiAvIGV4dGlycGF0aW9uIC5jc3ZcblxuKi9cblxuXG5cbi8vIHRoaXMgY2FuIGJlIGJyb3VnaHQgaW50byB0aGUgY2xhc3NcbmZ1bmN0aW9uIGRyYXdQYXJrcyhwYXJrcywgZywgY29sb3JTY2FsZSwgc2l6ZVNjYWxlLCBwcm9qZWN0aW9uLCBzZWxlY3Rpb24pIHtcblxuICB2YXIgcGFya0NpcmNsZXMgPSBnLnNlbGVjdEFsbChcIi5zZC1wYXJrY2lyY2xlXCIpLmRhdGEocGFya3MsIGQgPT4gZC5wYXJrKTtcblxuICBwYXJrQ2lyY2xlcy5leGl0KCkucmVtb3ZlKCk7XG4gIHBhcmtDaXJjbGVzLmVudGVyKCkuYXBwZW5kKFwiY2lyY2xlXCIpXG4gICAgICAuY2xhc3NlZChcInNkLXBhcmtjaXJjbGVcIiwgdHJ1ZSlcbiAgICAgIC5tZXJnZShwYXJrQ2lyY2xlcylcbiAgICAgIC5hdHRyKFwidHJhbnNmb3JtXCIsIGZ1bmN0aW9uKGQpIHsgcmV0dXJuIFwidHJhbnNsYXRlKFwiICsgcHJvamVjdGlvbihbK2QubG9uZywrZC5sYXRdKSArIFwiKVwiOyB9KVxuICAgICAgLmNsYXNzZWQoJ2hvdmVyJywgZCA9PiBkLnVuaXRfbmFtZSA9PT0gc2VsZWN0aW9uKVxuICAgICAgLm9uKFwibW91c2VvdmVyXCIsIGZ1bmN0aW9uKGQpIHtcbiAgICAgIH0pXG4gICAgICAub24oXCJtb3VzZW91dFwiLCBmdW5jdGlvbihkKSB7XG4gICAgICB9KVxuICAgICAgLnRyYW5zaXRpb24oKVxuICAgICAgLmF0dHIoXCJyXCIsIHNpemVTY2FsZSlcbiAgICAgIC5zdHlsZShcImZpbGxcIiwgY29sb3JTY2FsZSlcbiAgICAgIC5zdHlsZShcIm1peC1ibGVuZC1tb2RlXCIsIFwibm9ybWFsXCIpXG4gICAgICAuc3R5bGUoJ3N0cm9rZScsIGNvbG9yU2NhbGUpO1xufVxuXG5jbGFzcyBXYW5kIHtcbiAgY29uc3RydWN0b3Ioc3ZnLCBzaXplKSB7XG4gICAgbGV0IHdhbmQgPSBzdmcuYXBwZW5kKCdnJykuY2xhc3NlZCgnd2FuZCcsIHRydWUpO1xuICAgIHdhbmQuYXBwZW5kKCdjaXJjbGUnKVxuICAgICAgLmF0dHIoJ2N4JywgMClcbiAgICAgIC5hdHRyKCdjeScsIC1zaXplKVxuICAgICAgLmF0dHIoJ3InLCAyKTtcbiAgICB3YW5kLmFwcGVuZCgnbGluZScpXG4gICAgICAuYXR0cigneDEnLCAwKVxuICAgICAgLmF0dHIoJ3kxJywgMClcbiAgICAgIC5hdHRyKCd4MicsIDApXG4gICAgICAuYXR0cigneTInLCAtc2l6ZSk7XG5cbiAgICB0aGlzLndhbmQgPSB3YW5kO1xuICB9XG5cbiAgaGlkZSgpIHtcbiAgICB0aGlzLndhbmQuY2xhc3NlZCgnaGlkZGVuJywgdHJ1ZSk7XG4gIH1cblxuICBtb3ZlKHB0KSB7XG4gICAgdGhpcy53YW5kLmNsYXNzZWQoJ2hpZGRlbicsIGZhbHNlKTtcbiAgICB0aGlzLndhbmQuYXR0cigndHJhbnNmb3JtJywgYHRyYW5zbGF0ZSgke3B0WzBdfSwgJHtwdFsxXX0pYCk7XG4gIH1cbn1cblxuZnVuY3Rpb24gUGFya01hcChwYXJhbXMpIHtcbiAgY29uc3Qge2VsZW1lbnQsIHNlYXNvbiwgbWV0cmljLCBzaGFwZVVybCwgZGF0YVVybCwgb25DbGlja30gPSBwYXJhbXM7XG5cbiAgbGV0IF9lbGVtZW50ID0gZDMuc2VsZWN0KGVsZW1lbnQpLmFwcGVuZCgnZGl2JylcbiAgICAgICAgICAgICAgICAgIC5jbGFzc2VkKCdzZC1tYXAnLCB0cnVlKTtcblxuICBsZXQgdG9vbHRpcCA9IF9lbGVtZW50LmFwcGVuZCgnZGl2JylcbiAgICAgICAgICAgICAgICAgIC5jbGFzc2VkKCdzZC10b29sdGlwJywgdHJ1ZSlcbiAgICAgICAgICAgICAgICAgIC5jbGFzc2VkKCdoaWRkZW4nLCB0cnVlKVxuICAgICAgICAgICAgICAgICAgLmNsYXNzZWQoJ2Rvd24nLCBmYWxzZSlcbiAgICAgICAgICAgICAgICAgIC5odG1sKGBcbiAgICAgICAgICAgICAgICAgICAgPGgyIGNsYXNzPVwidGl0bGVcIj5OYW1lPC9oMj5cbiAgICAgICAgICAgICAgICAgICAgPGRpdj5cbiAgICAgICAgICAgICAgICAgICAgICA8c3ZnIGNsYXNzPVwic2QtYXJyb3dcIiBpZD1cIkxheWVyXzFcIiB3aWR0aD1cIjE4XCIgaGVpZ2h0PVwiMjIuNVwiIGRhdGEtbmFtZT1cIkxheWVyIDFcIiB4bWxucz1cImh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnXCIgdmlld0JveD1cIjAgMCAxOC43IDIyLjVcIj48cG9seWdvbiBjbGFzcz1cInNkLWFycm93LWljb25cIiBwb2ludHM9XCI2LjM0IDE0LjI2IDYuMzQgMjIuNSA2Ljk3IDIyLjUgMTEuNzIgMjIuNSAxMi4zNiAyMi41IDEyLjM2IDE0LjI2IDE4LjcgMTQuMjYgOS4zNSAwIDAgMTQuMjYgNi4zNCAxNC4yNlwiLz48L3N2Zz5cbiAgICAgICAgICAgICAgICAgICAgICA8aDIgY2xhc3M9XCJudW1iZXJcIj4zNDwvaDI+XG4gICAgICAgICAgICAgICAgICAgICAgPHAgY2xhc3M9XCJsYWJlbFwiPkV4dGlycGF0aW9uczwvcD5cbiAgICAgICAgICAgICAgICAgICAgPC9kaXY+XG4gICAgICAgICAgICAgICAgICBgKVxuXG4gIHRvb2x0aXAuc2VsZWN0KCcudGl0bGUnKS5vbignY2xpY2snLCAoKSA9PiB7XG4gICAgZDMuZXZlbnQucHJldmVudERlZmF1bHQoKTtcbiAgICBpZiAob25DbGljaykge1xuICAgICAgb25DbGljayh0b29sdGlwLnNlbGVjdCgnLnRpdGxlJykudGV4dCgpKTtcbiAgICB9XG4gIH0pO1xuXG4gIGxldCB3aWR0aCA9IGQzLnNlbGVjdChlbGVtZW50KS5ub2RlKCkub2Zmc2V0V2lkdGg7XG4gIGxldCBoZWlnaHQgPSB3aWR0aCAqIDcwMyAvIDExMDY7XG5cbiAgdmFyIHN2ZyA9IF9lbGVtZW50LmFwcGVuZChcInN2Z1wiKVxuICAgICAgICAgICAgICAgIC5hdHRyKCd3aWR0aCcsIHdpZHRoKVxuICAgICAgICAgICAgICAgIC5hdHRyKCdoZWlnaHQnLCBoZWlnaHQpO1xuXG4gIHZhciBiYWNrZ3JvdW5kX2cgPSBzdmcuYXBwZW5kKFwiZ1wiKS5hdHRyKFwiaWRcIixcImJhY2tncm91bmRfZ1wiKTtcbiAgdmFyIGZvcmVncm91bmRfZyA9IHN2Zy5hcHBlbmQoXCJnXCIpLmF0dHIoXCJpZFwiLFwiZm9yZWdyb3VuZF9nXCIpO1xuICB2YXIgcGFya0dyb3VwID0gZm9yZWdyb3VuZF9nLmFwcGVuZChcImdcIikuYXR0cihcImNsYXNzXCIsIFwicGFya0NpcmNsZXNcIik7XG5cbiAgdmFyIHRvdWNoT2Zmc2V0WSA9IDUwO1xuICB2YXIgd2FuZCA9IG5ldyBXYW5kKGZvcmVncm91bmRfZywgdG91Y2hPZmZzZXRZKTtcblxuICBsZXQgcHJvamVjdGlvbjtcblxuICBsZXQgdG9vbHRpcE51bWJlcjtcbiAgbGV0IGNvbG9uQ29sb3IgPSBkMy5zY2FsZUxpbmVhcigpXG4gICAgICAgICAgICAgICAgICAgIC5yYW5nZShbJyMxOGExYWQnLCAnIzE4YTFhZCddKTtcblxuICBsZXQgY29sb25TaXplID0gZDMuc2NhbGVTcXJ0KCk7XG5cbiAgbGV0IGV4dGlycENvbG9yID0gZDMuc2NhbGVMaW5lYXIoKVxuICAgICAgICAgICAgICAgICAgICAucmFuZ2UoWycjZThjNTc4JywgJyNlOGM1NzgnXSk7XG5cbiAgbGV0IGV4dGlycFNpemUgPSBkMy5zY2FsZVNxcnQoKTtcblxuICBsZXQgX3NlYXNvbiA9IHNlYXNvbjtcbiAgbGV0IF9tZXRyaWMgPSBtZXRyaWM7XG4gIGxldCBfcGFya3M7XG4gIGxldCBfc3RhdGVzO1xuXG4gIGxldCBzZWxlY3Rpb247XG5cbiAgZnVuY3Rpb24gcmVuZGVyKCkge1xuICAgIGxldCBjb2xvclNjYWxlLCBzaXplU2NhbGU7XG4gICAgbGV0IHRvb2x0aXBMYWJlbCA9IGBQb3RlbnRpYWwgJHtfbWV0cmljfXMgaW4gJHtfc2Vhc29ufWA7XG4gICAgdG9vbHRpcC5zZWxlY3QoJy5sYWJlbCcpLnRleHQodG9vbHRpcExhYmVsKTtcblxuICAgIGlmIChfc2Vhc29uID09ICdzdW1tZXInICYmIF9tZXRyaWMgPT0gJ2NvbG9uaXphdGlvbicpIHtcblxuICAgICAgY29sb3JTY2FsZSA9IChkKSA9PiBjb2xvbkNvbG9yKGRbJ25vX2NvbG9uaXphdGlvbnNfc3VtbWVyJ10pO1xuICAgICAgc2l6ZVNjYWxlID0gKGQpID0+IGNvbG9uU2l6ZShkWydub19jb2xvbml6YXRpb25zX3N1bW1lciddKTtcbiAgICAgIHRvb2x0aXBOdW1iZXIgPSAoZCkgPT4gZFsnbm9fY29sb25pemF0aW9uc19zdW1tZXInXTtcbiAgICAgIHRvb2x0aXAuY2xhc3NlZCgnZG93bicsIGZhbHNlKTtcblxuICAgIH0gZWxzZSBpZiAoX3NlYXNvbiA9PSAnc3VtbWVyJyAmJiBfbWV0cmljID09ICdleHRpcnBhdGlvbicpIHtcblxuICAgICAgY29sb3JTY2FsZSA9IChkKSA9PiBleHRpcnBDb2xvcihkWydub19leHRpcnBhdGlvbnNfc3VtbWVyJ10pO1xuICAgICAgc2l6ZVNjYWxlID0gKGQpID0+IGV4dGlycFNpemUoZFsnbm9fZXh0aXJwYXRpb25zX3N1bW1lciddKTtcbiAgICAgIHRvb2x0aXBOdW1iZXIgPSAoZCkgPT4gZFsnbm9fZXh0aXJwYXRpb25zX3N1bW1lciddO1xuICAgICAgdG9vbHRpcC5jbGFzc2VkKCdkb3duJywgdHJ1ZSk7XG5cbiAgICB9IGVsc2UgaWYgKF9zZWFzb24gPT0gJ3dpbnRlcicgJiYgX21ldHJpYyA9PSAnY29sb25pemF0aW9uJykge1xuXG4gICAgICBjb2xvclNjYWxlID0gKGQpID0+IGNvbG9uQ29sb3IoZFsnbm9fY29sb25pemF0aW9uc193aW50ZXInXSk7XG4gICAgICBzaXplU2NhbGUgPSAoZCkgPT4gY29sb25TaXplKGRbJ25vX2NvbG9uaXphdGlvbnNfd2ludGVyJ10pO1xuICAgICAgdG9vbHRpcE51bWJlciA9IChkKSA9PiBkWydub19jb2xvbml6YXRpb25zX3dpbnRlciddO1xuICAgICAgdG9vbHRpcC5jbGFzc2VkKCdkb3duJywgZmFsc2UpO1xuXG4gICAgfSBlbHNlIGlmIChfc2Vhc29uID09ICd3aW50ZXInICYmIF9tZXRyaWMgPT0gJ2V4dGlycGF0aW9uJykge1xuXG4gICAgICBjb2xvclNjYWxlID0gKGQpID0+IGV4dGlycENvbG9yKGRbJ25vX2V4dGlycGF0aW9uc193aW50ZXInXSk7XG4gICAgICBzaXplU2NhbGUgPSAoZCkgPT4gZXh0aXJwU2l6ZShkWydub19leHRpcnBhdGlvbnNfd2ludGVyJ10pO1xuICAgICAgdG9vbHRpcE51bWJlciA9IChkKSA9PiBkWydub19leHRpcnBhdGlvbnNfd2ludGVyJ107XG4gICAgICB0b29sdGlwLmNsYXNzZWQoJ2Rvd24nLCB0cnVlKTtcblxuICAgIH1cblxuICAgIGRyYXdQYXJrcyhfcGFya3MsIHBhcmtHcm91cCwgY29sb3JTY2FsZSwgc2l6ZVNjYWxlLCBwcm9qZWN0aW9uLCBzZWxlY3Rpb24pO1xuICB9XG5cbiAgZnVuY3Rpb24gcmVkcmF3KCkge1xuXG4gICAgbGV0IHdpZHRoID0gX2VsZW1lbnQubm9kZSgpLm9mZnNldFdpZHRoO1xuICAgIGxldCBoZWlnaHQgPSB3aWR0aCAqIDcwMyAvIDExMDY7XG5cbiAgICBzdmcuYXR0cignd2lkdGgnLCB3aWR0aClcbiAgICAgICAuYXR0cignaGVpZ2h0JywgaGVpZ2h0KTtcblxuICAgIGxldCBtYXBQYWRkaW5nID0gNDAgKiB3aWR0aCAvIDExMDY7O1xuICAgIHByb2plY3Rpb24gPSBhbGJlcnNCaWdBbGFza2EoKVxuICAgICAgLmZpdEV4dGVudChbWzAgKyBtYXBQYWRkaW5nLCAwICsgbWFwUGFkZGluZ10sIFt3aWR0aCAtIG1hcFBhZGRpbmcsIGhlaWdodCAtIG1hcFBhZGRpbmddXSwge1xuICAgICAgICB0eXBlOiAnRmVhdHVyZUNvbGxlY3Rpb24nLFxuICAgICAgICBmZWF0dXJlczogX3N0YXRlc1xuICAgICAgfSk7XG5cbiAgICAvLyBkcmF3IGJhc2UgbGF5ZXJcbiAgICBsZXQgc3RhdGVzUGF0aCA9IGJhY2tncm91bmRfZy5zZWxlY3RBbGwoXCJwYXRoXCIpXG4gICAgICAgIC5kYXRhKF9zdGF0ZXMpO1xuICAgIHN0YXRlc1BhdGguZW50ZXIoKVxuICAgICAgICAuYXBwZW5kKFwicGF0aFwiKVxuICAgICAgLm1lcmdlKHN0YXRlc1BhdGgpXG4gICAgICAgIC5hdHRyKFwiZFwiLCBkMy5nZW9QYXRoKHByb2plY3Rpb24pKVxuICAgICAgICAuc3R5bGUoXCJmaWxsXCIsIFwiI2U1ZTVlNVwiKVxuICAgICAgICAuc3R5bGUoXCJzdHJva2VcIiwgZCA9PiBkLnByb3BlcnRpZXMucG9zdGFsID09PSAnQUsnID8gXCIjZDhkOGQ4XCIgOiBcIndoaXRlXCIpXG5cbiAgICAvLyBjb21wdXRlIHRoZSBkb21haW5zXG4gICAgbGV0IGNvbG9uUmFuZ2UgPSBkMy5leHRlbnQoXG4gICAgICAgICAgICAgIF9wYXJrcy5tYXAoZCA9PiBkWydub19jb2xvbml6YXRpb25zX3N1bW1lciddKVxuICAgICAgICAgICAgLmNvbmNhdChfcGFya3MubWFwKGQgPT4gZFsnbm9fY29sb25pemF0aW9uc193aW50ZXInXSkpKTtcblxuICAgIGxldCBleHRpcnBSYW5nZSA9IGQzLmV4dGVudChcbiAgICAgICAgICAgICAgX3BhcmtzLm1hcChkID0+IGRbJ25vX2V4dGlycGF0aW9uc19zdW1tZXInXSlcbiAgICAgICAgICAgIC5jb25jYXQoX3BhcmtzLm1hcChkID0+IGRbJ25vX2V4dGlycGF0aW9uc193aW50ZXInXSkpKTtcblxuICAgIGxldCBtaW5SYWRpdXMgPSAyIC8gMzIwICogd2lkdGg7XG4gICAgbGV0IG1heFJhZGl1cyA9IDEzIC8gMzIwICogd2lkdGhcblxuICAgIGNvbG9uQ29sb3IuZG9tYWluKGNvbG9uUmFuZ2UpO1xuICAgIGNvbG9uU2l6ZS5kb21haW4oY29sb25SYW5nZSlcbiAgICAgIC5yYW5nZShbbWluUmFkaXVzLCBtYXhSYWRpdXNdKTtcbiAgICBleHRpcnBDb2xvci5kb21haW4oZXh0aXJwUmFuZ2UpO1xuICAgIGV4dGlycFNpemUuZG9tYWluKGV4dGlycFJhbmdlKVxuICAgICAgLnJhbmdlKFttaW5SYWRpdXMsIG1heFJhZGl1c10pO1xuXG4gICAgbGV0IHBvaW50cyA9IF9wYXJrcy5tYXAocCA9PiBwcm9qZWN0aW9uKFsrcC5sb25nLCArcC5sYXRdKSk7XG5cbiAgICBsZXQgX3YgPSBkMy52b3Jvbm9pKClcbiAgICAgIC8vcGl4ZWwgc3BhY2VcbiAgICAgIC54KGQgPT4geyByZXR1cm4gcHJvamVjdGlvbiggWytkLmxvbmcsICtkLmxhdF0pWzBdOyB9KVxuICAgICAgLnkoZCA9PiB7IHJldHVybiBwcm9qZWN0aW9uKCBbK2QubG9uZywgK2QubGF0XSlbMV07IH0pXG4gICAgICAoX3BhcmtzKTtcblxuICAgIGZ1bmN0aW9uIGhpdERldGVjdG9yKHAsIG9mZnNldFkpIHtcbiAgICAgIG9mZnNldFkgPSBvZmZzZXRZIHx8IDA7XG4gICAgICBsZXQgbWF4RGlzdGFuY2VGcm9tUG9pbnQgPSAyMDtcbiAgICAgIHJldHVybiBfdi5maW5kKHBbMF0sIHBbMV0gLSBvZmZzZXRZLCBtYXhEaXN0YW5jZUZyb21Qb2ludCk7XG4gICAgfVxuXG4gICAgbGV0IGZvY3VzZWQgPSBmYWxzZTtcblxuICAgIGZ1bmN0aW9uIGhpZ2hsaWdodChwYXJrTm9kZSkge1xuICAgICAgaWYgKHBhcmtOb2RlKSB7XG5cbiAgICAgICAgc2VsZWN0aW9uID0gcGFya05vZGUuZGF0YS51bml0X25hbWU7XG4gICAgICAgIHJlbmRlcigpO1xuXG4gICAgICAgIHRvb2x0aXAuY2xhc3NlZCgnaGlkZGVuJywgZmFsc2UpXG4gICAgICAgIHRvb2x0aXAuc2VsZWN0KCcudGl0bGUnKS50ZXh0KHBhcmtOb2RlLmRhdGEudW5pdF9uYW1lKTtcbiAgICAgICAgdG9vbHRpcC5zZWxlY3QoJy5udW1iZXInKS50ZXh0KHRvb2x0aXBOdW1iZXIocGFya05vZGUuZGF0YSkpO1xuXG4gICAgICAgIGxldCBkeCA9IHRvb2x0aXAubm9kZSgpLmNsaWVudFdpZHRoIC8gMjtcbiAgICAgICAgbGV0IGR5ID0gcGFya05vZGVbMV0gLSB0b29sdGlwLm5vZGUoKS5jbGllbnRIZWlnaHQgLSA1OyAvLyBhIGJpdCBvZmYgY2VudGVyXG4gICAgICAgIGR4ID0gcGFya05vZGVbMF0gLSBkeDtcblxuICAgICAgICB0b29sdGlwLnN0eWxlKCdsZWZ0JywgZHggKyAncHgnKTtcbiAgICAgICAgdG9vbHRpcC5zdHlsZSgndG9wJywgZHkgKyAncHgnKTtcblxuICAgICAgICAvLyBzbmFwIHRvIHRoZSB3aW5kb3dcbiAgICAgICAgbGV0IHJlY3QgPSB0b29sdGlwLm5vZGUoKS5nZXRCb3VuZGluZ0NsaWVudFJlY3QoKTtcbiAgICAgICAgbGV0IG1heFdpZHRoID0gd2luZG93LmlubmVyV2lkdGg7XG5cbiAgICAgICAgaWYgKHJlY3QueCA8IDApIHtcbiAgICAgICAgICBkeCAtPSByZWN0Lng7XG4gICAgICAgIH0gZWxzZSBpZiAocmVjdC54ICsgcmVjdC53aWR0aCA+IG1heFdpZHRoKSB7XG4gICAgICAgICAgZHggPSBtYXhXaWR0aCAtIHJlY3Qud2lkdGg7XG4gICAgICAgIH1cblxuICAgICAgICB0b29sdGlwLnN0eWxlKCdsZWZ0JywgZHggKyAncHgnKTtcbiAgICAgICAgdG9vbHRpcC5zdHlsZSgndG9wJywgZHkgKyAncHgnKTtcblxuICAgICAgfSBlbHNlIHtcbiAgICAgICAgdG9vbHRpcC5jbGFzc2VkKCdoaWRkZW4nLCB0cnVlKVxuICAgICAgICBzZWxlY3Rpb24gPSBudWxsO1xuICAgICAgICByZW5kZXIoKTtcbiAgICAgIH1cbiAgICB9XG5cbiAgICBzdmcub24oJ2NsaWNrJywgZnVuY3Rpb24oKSB7XG4gICAgICBsZXQgcGFyayA9IGhpdERldGVjdG9yKGQzLm1vdXNlKHRoaXMpKTtcbiAgICAgIGhpZ2hsaWdodChwYXJrKTtcbiAgICAgIGZvY3VzZWQgPSBwYXJrICE9IG51bGw7XG4gICAgfSk7XG5cbiAgICBzdmcub24oJ3RvdWNobW92ZScsIGZ1bmN0aW9uKGUpIHtcbiAgICAgIHdhbmQubW92ZShkMy50b3VjaGVzKHRoaXMpWzBdKTtcbiAgICAgIGxldCBwYXJrID0gaGl0RGV0ZWN0b3IoZDMudG91Y2hlcyh0aGlzKVswXSwgdG91Y2hPZmZzZXRZKTtcbiAgICAgIGhpZ2hsaWdodChwYXJrKTtcbiAgICAgIGQzLmV2ZW50LnByZXZlbnREZWZhdWx0KCk7XG4gICAgfSlcbiAgICBzdmcub24oJ3RvdWNoZW5kJywgZnVuY3Rpb24oZSkge1xuICAgICAgd2FuZC5oaWRlKCk7XG4gICAgfSk7XG4gICAgc3ZnLm9uKCdtb3VzZW1vdmUnLCBmdW5jdGlvbigpIHtcbiAgICAgIGlmICghZm9jdXNlZCkge1xuICAgICAgICBsZXQgcGFyayA9IGhpdERldGVjdG9yKGQzLm1vdXNlKHRoaXMpKTtcbiAgICAgICAgaGlnaGxpZ2h0KHBhcmspO1xuICAgICAgfVxuICAgIH0pO1xuXG4gICAgcmVuZGVyKCk7XG5cbiAgfSAvL2VuZCBpbml0XG5cbiAgZnVuY3Rpb24gc2V0UGFyYW1zKHNlYXNvbiwgbWV0cmljKSB7XG4gICAgX3NlYXNvbiA9IHNlYXNvbjtcbiAgICBfbWV0cmljID0gbWV0cmljO1xuICAgIHJlbmRlcigpO1xuICB9XG5cbiAgLy9sb2FkIHRoZSBkYXRhXG4gIGQzLnF1ZXVlKClcbiAgICAuZGVmZXIoZDMuanNvbiwgc2hhcGVVcmwpXG4gICAgLmRlZmVyKGQzLmNzdiwgZGF0YVVybClcbiAgICAuYXdhaXRBbGwoZnVuY3Rpb24oZXJyb3IsIHJlc3VsdHMpIHtcblxuICAgIGxldCBzdGF0ZXMgPSByZXN1bHRzWzBdO1xuICAgIGxldCBwYXJrcyA9IHJlc3VsdHNbMV07XG5cbiAgICAvLyB0eXBlY2FzdFxuICAgIHBhcmtzLmZvckVhY2goZnVuY3Rpb24ocGFyaykge1xuICAgICAgcGFyay5wYXJrID0gcGFyay5wYXJrO1xuICAgICAgcGFyay51bml0X25hbWUgPSBwYXJrLnVuaXRfbmFtZTtcbiAgICAgIHBhcmsubnBzX3JlZ2lvbiA9IHBhcmsubnBzX3JlZ2lvbjtcbiAgICAgIHBhcmsudHVybm92ZXJfc3VtbWVyID0gK3BhcmsudHVybm92ZXJfc3VtbWVyO1xuICAgICAgcGFyay50dXJub3Zlcl93aW50ZXIgPSArcGFyay50dXJub3Zlcl93aW50ZXI7XG4gICAgICBwYXJrLmxvbmcgPSArcGFyay5sb25nO1xuICAgICAgcGFyay5sYXQgPSArcGFyay5sYXQ7XG4gICAgICBwYXJrLmN1cnJlbnRfbm9fc3BlY2llc19zdW1tZXIgPSArcGFyay5ub19zcGVjaWVzX3N1bW1lcjtcbiAgICAgIHBhcmsuY3VycmVudF9ub19zcGVjaWVzX3dpbnRlciA9ICtwYXJrLm5vX3NwZWNpZXNfd2ludGVyO1xuICAgICAgcGFyay5wcm9wX2NvbG9uaXphdGlvbnNfc3VtbWVyID0gK3BhcmsucHJvcF9jb2xvbml6YXRpb25zX3N1bW1lcjtcbiAgICAgIHBhcmsucHJvcF9jb2xvbml6YXRpb25zX3dpbnRlciA9ICtwYXJrLnByb3BfY29sb25pemF0aW9uc193aW50ZXI7XG4gICAgICBwYXJrLnByb3BfZXh0aXJwYXRpb25zX3dpbnRlciA9ICtwYXJrLnByb3BfZXh0aXJwYXRpb25zX3dpbnRlcjtcbiAgICAgIHBhcmsucHJvcF9leHRpcnBhdGlvbnNfc3VtbWVyID0gK3BhcmsucHJvcF9leHRpcnBhdGlvbnNfc3VtbWVyO1xuICAgICAgcGFyay5ub19leHRpcnBhdGlvbnNfc3VtbWVyID0gK3Bhcmsubm9fZXh0aXJwYXRpb25zX3N1bW1lcjtcbiAgICAgIHBhcmsubm9fZXh0aXJwYXRpb25zX3dpbnRlciA9ICtwYXJrLm5vX2V4dGlycGF0aW9uc193aW50ZXI7XG4gICAgICBwYXJrLm5vX2NvbG9uaXphdGlvbnNfc3VtbWVyID0gK3Bhcmsubm9fY29sb25pemF0aW9uc19zdW1tZXI7XG4gICAgICBwYXJrLm5vX2NvbG9uaXphdGlvbnNfd2ludGVyID0gK3Bhcmsubm9fY29sb25pemF0aW9uc193aW50ZXI7XG4gICAgfSk7XG5cbiAgICAvLyBnZXQgcmlkIG9mIGhhd2FpaVxuICAgIHN0YXRlcyA9IHN0YXRlcy5mZWF0dXJlcy5maWx0ZXIoZCA9PiB7XG4gICAgICByZXR1cm4gZC5wcm9wZXJ0aWVzLmFkbTBfYTMgPT0gJ1VTQScgJiYgZC5wcm9wZXJ0aWVzLnBvc3RhbCAhPSAnSEknO1xuICAgIH0pXG5cblxuICAgIF9wYXJrcyA9IHBhcmtzO1xuICAgIF9zdGF0ZXMgPSBzdGF0ZXM7XG5cbiAgICByZWRyYXcoKTtcblxuICAgIHdpbmRvdy5hZGRFdmVudExpc3RlbmVyKFwicmVzaXplXCIsIHJlZHJhdyk7XG5cbiAgfSk7XG5cbiAgcmV0dXJuIHtcbiAgICBzZXRQYXJhbXM6IHNldFBhcmFtc1xuICB9XG59XG5cbmV4cG9ydCB7IFBhcmtNYXAgfTtcbiIsImZ1bmN0aW9uIGZvcm1hdFR1cm5vdmVyKGQpIHtcbiAgICByZXR1cm4gTWF0aC5yb3VuZChkICogMTAwKSArICclJztcbn1cblxuZnVuY3Rpb24gY2VudGVyT25YKGVsZW1lbnQsIHgpIHtcbiAgICAvLyBwb3NpdGlvbnMgYW4gZWxlbWVudCBvbiB4IHJlbGF0aXZlIHRvIGl0cyBwYXJlbnRcbiAgICAvLyBzbmFwcyB0aGUgZWxlbWVudCB0byB0aGUgYm91bmRhcmllcyBvZiB0aGUgcGFyZW50XG5cbiAgICBsZXQgd2lkdGggPSBlbGVtZW50Lm5vZGUoKS5vZmZzZXRXaWR0aDtcbiAgICBsZXQgbWF4V2lkdGggPSBlbGVtZW50Lm5vZGUoKS5wYXJlbnROb2RlLm9mZnNldFdpZHRoO1xuXG4gICAgeCA9IHggLSB3aWR0aCAvIDI7XG5cbiAgICAvLyBzbmFwIHRvIHRoZSB3aW5kb3dcbiAgICBpZiAoeCA8IDApIHtcbiAgICAgICAgeCA9IDA7XG4gICAgfSBlbHNlIGlmICh4ICsgd2lkdGggPiBtYXhXaWR0aCkge1xuICAgICAgICB4ID0gbWF4V2lkdGggLSB3aWR0aDtcbiAgICB9XG5cbiAgICBlbGVtZW50LnN0eWxlKCdsZWZ0JywgeCArICdweCcpO1xufVxuXG5mdW5jdGlvbiBEb3RDaGFydChwYXJhbXMpIHtcbiAgICBjb25zdCB7ZWxlbWVudCwgc2hvd05hbWUsIG9uSG92ZXIsIG9uQ2xpY2ssIHNjYWxlfSA9IHBhcmFtcztcblxuICAgIGxldCBfZGF0YSA9IFtdO1xuICAgIGxldCBoaXREZXRlY3RvcjtcbiAgICBsZXQgaGVpZ2h0ID0gOTA7XG5cbiAgICBjb25zdCBSQURJVVMgPSA2O1xuICAgIGNvbnN0IFNFTEVDVEVEX1JBRElVUyA9IDEzO1xuICAgIGxldCBkb3RDZW50ZXIgPSBoZWlnaHQgLSA2IC0gU0VMRUNURURfUkFESVVTO1xuICAgIGxldCBtYXJnaW4gPSB7XG4gICAgICAgIHRvcDogMCxcbiAgICAgICAgbGVmdDogMjBcbiAgICB9O1xuICAgIGxldCB4O1xuXG5cbiAgICBsZXQgc3ZnID0gZWxlbWVudC5hcHBlbmQoJ3N2ZycpXG4gICAgICAgICAgICAgICAgLmFwcGVuZCgnZycpXG4gICAgICAgICAgICAgICAgLmF0dHIoJ3RyYW5zZm9ybScsIGB0cmFuc2xhdGUoJHttYXJnaW4ubGVmdH0sICR7bWFyZ2luLnRvcH0pYCk7XG5cbiAgICBzdmcuYXBwZW5kKCdyZWN0JylcbiAgICAgICAgLmF0dHIoJ2NsYXNzJywgJ292ZXJsYXknKVxuICAgICAgICAuYXR0cignaGVpZ2h0JywgaGVpZ2h0KVxuICAgICAgICAuYXR0cigneCcsIDApXG4gICAgICAgIC5hdHRyKCd5JywgMClcbiAgICAgICAgLmF0dHIoJ2ZpbGwtb3BhY2l0eScsIDAuMCk7XG5cbiAgICBsZXQgZm9jdXMgPSBlbGVtZW50LmFwcGVuZCgnZGl2JykuY2xhc3NlZCgnc2QtdHVybm92ZXItdG9vbHRpcCcsIHRydWUpLmNsYXNzZWQoJ2hpZGRlbicsIHRydWUpO1xuICAgIGxldCBwZXJtYUZvY3VzID0gZWxlbWVudC5hcHBlbmQoJ2RpdicpLmNsYXNzZWQoJ3NkLXBlcm1hLXRvb2x0aXAnLCB0cnVlKVxuICAgIGxldCBmaWVsZDtcblxuICAgIGZ1bmN0aW9uIHJlZHJhdyhkYXRhLCBfZmllbGQsIHNlbGVjdGVkKSB7XG4gICAgICAgIC8vIGNvcHkgb3ZlciB0aGUgYXJyYXlcbiAgICAgICAgZmllbGQgPSBfZmllbGQ7XG4gICAgICAgIF9kYXRhID0gZGF0YS5zbGljZSgpO1xuXG4gICAgICAgIC8vIHNvcnQgaW4gYXNjZW5kaW5nIHZhbHVlXG4gICAgICAgIF9kYXRhLnNvcnQoKGEsIGIpID0+IGQzLmFzY2VuZGluZyhhW2ZpZWxkXSwgYltmaWVsZF0pKTtcblxuICAgICAgICAvLyBzaXplIHRoZSBzdmdcbiAgICAgICAgbGV0IHdpZHRoID0gZWxlbWVudC5ub2RlKCkub2Zmc2V0V2lkdGg7XG4gICAgICAgIGVsZW1lbnQuc3R5bGUoJ2hlaWdodCcsIGhlaWdodCArICdweCcpXG4gICAgICAgIGVsZW1lbnQuc2VsZWN0KCdzdmcnKVxuICAgICAgICAgICAgLmF0dHIoJ3dpZHRoJywgd2lkdGgpXG4gICAgICAgICAgICAuYXR0cignaGVpZ2h0JywgaGVpZ2h0KVxuXG5cbiAgICAgICAgLy8gdGhpcyBzY2FsZSBpcyBub3cgaW5kZXBlbmRlbnRcblxuICAgICAgICBsZXQgX3g7XG4gICAgICAgIGlmIChzY2FsZSA9PSAnbG9nJykge1xuICAgICAgICAgICAgX3ggPSBkMy5zY2FsZUxvZygpXG4gICAgICAgICAgICAgICAgLnJhbmdlKFswLCB3aWR0aCAtIDIgKiBtYXJnaW4ubGVmdF0pXG4gICAgICAgICAgICAgICAgLmNsYW1wKHRydWUpO1xuICAgICAgICAgICAgbGV0IGRvbWFpbiA9IGQzLmV4dGVudChkYXRhLCBkID0+IGRbZmllbGRdICogMTAwKTtcbiAgICAgICAgICAgIGRvbWFpblswXSA9IE1hdGgubWF4KDEsIGRvbWFpblswXSk7XG4gICAgICAgICAgICBfeC5kb21haW4oZG9tYWluKTtcbiAgICAgICAgfSBlbHNlIHtcbiAgICAgICAgICAgIF94ID0gZDMuc2NhbGVMaW5lYXIoKVxuICAgICAgICAgICAgICAgIC5yYW5nZShbMCwgd2lkdGggLSAyICogbWFyZ2luLmxlZnRdKVxuICAgICAgICAgICAgICAgIC5jbGFtcCh0cnVlKTtcbiAgICAgICAgICAgIF94LmRvbWFpbihkMy5leHRlbnQoZGF0YSwgZCA9PiBkW2ZpZWxkXSAqIDEwMCkpO1xuICAgICAgICB9XG5cbiAgICAgICAgeCA9IChkKSA9PiBfeChkW2ZpZWxkXSAqIDEwMCk7XG5cbiAgICAgICAgLy8gY29uc29sZS5sb2coJ3gnLCBfeC5kb21haW4oKSwgX3gucmFuZ2UoKSk7XG5cbiAgICAgICAgbGV0IHNlbGVjdGVkRGF0YSA9IF9kYXRhLmZpbmQoZCA9PiBkLnVuaXRfbmFtZSA9PSBzZWxlY3RlZCk7XG5cbiAgICAgICAgLy8gcmVuZGVyIHRoZSBzZWxlY3Rpb25cbiAgICAgICAgbGV0IHNlbGVjdGVkRG90cyA9IHN2Zy5zZWxlY3RBbGwoJy5zZC1zZWxlY3RlZC1kb3QnKS5kYXRhKFtzZWxlY3RlZERhdGFdKTtcbiAgICAgICAgc2VsZWN0ZWREb3RzLmVudGVyKClcbiAgICAgICAgICAgIC5hcHBlbmQoJ2NpcmNsZScpXG4gICAgICAgICAgICAuY2xhc3NlZCgnc2Qtc2VsZWN0ZWQtZG90JywgdHJ1ZSlcbiAgICAgICAgICAgIC5tZXJnZShzZWxlY3RlZERvdHMpXG4gICAgICAgICAgICAgICAgLmF0dHIoJ2N4JywgeClcbiAgICAgICAgICAgICAgICAuYXR0cignY3knLCBkb3RDZW50ZXIpXG4gICAgICAgICAgICAgICAgLmF0dHIoJ3InLCBTRUxFQ1RFRF9SQURJVVMpO1xuXG4gICAgICAgIC8vIHJlbmRlciB0aGUgb3RoZXIgcGFya3NcbiAgICAgICAgbGV0IG90aGVyUGFya3MgPSBfZGF0YS5maWx0ZXIoZCA9PiBkLnVuaXRfbmFtZSAhPSBzZWxlY3RlZCk7XG4gICAgICAgIC8vIGNvbnNvbGUubG9nKCdvdGhlcnBhcmtzJywgb3RoZXJQYXJrcyk7XG4gICAgICAgIGxldCBkb3RzID0gc3ZnLnNlbGVjdEFsbCgnLnNkLWRvdCcpLmRhdGEob3RoZXJQYXJrcyk7XG4gICAgICAgIGRvdHMuZW50ZXIoKVxuICAgICAgICAgICAgLmFwcGVuZCgnY2lyY2xlJylcbiAgICAgICAgICAgIC5jbGFzc2VkKCdzZC1kb3QnLCB0cnVlKVxuICAgICAgICAgICAgLm1lcmdlKGRvdHMpXG4gICAgICAgICAgICAgICAgLmNsYXNzZWQoJ3NlbGVjdGVkJywgZCA9PiBkLnVuaXRfbmFtZSA9PT0gc2VsZWN0ZWQpXG4gICAgICAgICAgICAgICAgLmF0dHIoJ2N4JywgeClcbiAgICAgICAgICAgICAgICAuYXR0cignY3knLCBkb3RDZW50ZXIpXG4gICAgICAgICAgICAgICAgLmF0dHIoJ3InLCBSQURJVVMpO1xuXG4gICAgICAgIGhpdERldGVjdG9yID0gZDMudm9yb25vaSgpXG4gICAgICAgICAgICAueCh4KVxuICAgICAgICAgICAgLnkoMClcbiAgICAgICAgICAgIChvdGhlclBhcmtzKTtcblxuICAgICAgICAvLyBoaXQgZGV0ZWN0b3Igb3ZlcmxheVxuICAgICAgICB2YXIgb3ZlcmxheSA9IHN2Zy5zZWxlY3QoJy5vdmVybGF5JylcbiAgICAgICAgICAgIC5hdHRyKCd3aWR0aCcsIHdpZHRoKVxuICAgICAgICAgICAgLm9uKCdtb3VzZW92ZXInLCBtb3VzZW1vdmUpXG4gICAgICAgICAgICAub24oJ21vdXNlb3V0JywgZCA9PiBvbkhvdmVyKCkpXG4gICAgICAgICAgICAub24oJ21vdXNlbW92ZScsIG1vdXNlbW92ZSlcbiAgICAgICAgICAgIC5vbigndG91Y2htb3ZlJywgdG91Y2htb3ZlKVxuICAgICAgICAgICAgLm9uKCdjbGljaycsIG1vdXNlY2xpY2spO1xuXG4gICAgICAgIC8vIGxhYmVsc1xuICAgICAgICBsZXQgcGVybWFMYWJlbCA9ICcnO1xuICAgICAgICBpZiAoc2hvd05hbWUpIHtcbiAgICAgICAgICAgIHBlcm1hTGFiZWwgPSBzZWxlY3RlZERhdGEudW5pdF9uYW1lICsgJyAnO1xuICAgICAgICB9XG4gICAgICAgIHBlcm1hTGFiZWwgKz0gZm9ybWF0VHVybm92ZXIoc2VsZWN0ZWREYXRhW2ZpZWxkXSk7XG4gICAgICAgIHBlcm1hRm9jdXMudGV4dChwZXJtYUxhYmVsKTtcblxuXG4gICAgICAgIGxldCBkeSA9IGRvdENlbnRlciAtIChTRUxFQ1RFRF9SQURJVVMgKiAzKSAtIDEwICsgbWFyZ2luLnRvcDtcbiAgICAgICAgcGVybWFGb2N1cy5zdHlsZSgndG9wJywgZHkgKyAncHgnKTtcblxuICAgICAgICBjZW50ZXJPblgocGVybWFGb2N1cywgeChzZWxlY3RlZERhdGEpICsgbWFyZ2luLmxlZnQpO1xuXG4gICAgICAgIGR5ID0gZG90Q2VudGVyIC0gKFJBRElVUyAqIDMpIC0gMTQgKyBtYXJnaW4udG9wO1xuICAgICAgICBmb2N1cy5zdHlsZSgndG9wJywgZHkgKyAncHgnKTtcbiAgICB9XG5cbiAgICBmdW5jdGlvbiBjbGVhckhvdmVyKCkge1xuICAgICAgICBzdmcuc2VsZWN0QWxsKFwiLnNkLWRvdFwiKVxuICAgICAgICAgICAgLmNsYXNzZWQoXCJob3ZlcmVkXCIsIGZhbHNlKTtcblxuICAgICAgICAvLyBjbGVhciBmb2N1c1xuICAgICAgICBmb2N1cy5jbGFzc2VkKCdoaWRkZW4nLCB0cnVlKVxuICAgIH1cblxuICAgIGZ1bmN0aW9uIHJlbmRlckhvdmVyKG5hbWUpIHtcbiAgICAgICAgLy8gcmVuZGVyIGhvdmVyIHN0YXRlXG4gICAgICAgIC8vIGNvbnNvbGUubG9nKCdyZW5kZXJIb3ZlciBmb3InLCBlbGVtZW50Lm5vZGUoKS5pZCk7XG4gICAgICAgIGxldCBvYmogPSBfZGF0YS5maW5kKGQgPT4gZC51bml0X25hbWUgPT09IG5hbWUpO1xuICAgICAgICBpZiAoIW9iaikge1xuICAgICAgICAgICAgLy8gY29uc29sZS5sb2coXCJPSCBOTyBjYW4ndCBmaW5kXCIsIG5hbWUpO1xuICAgICAgICAgICAgcmV0dXJuO1xuICAgICAgICB9XG4gICAgICAgIHN2Zy5zZWxlY3RBbGwoXCIuc2QtZG90XCIpXG4gICAgICAgICAgICAuY2xhc3NlZChcImhvdmVyZWRcIiwgZCA9PiBkLnVuaXRfbmFtZSA9PT0gb2JqLnVuaXRfbmFtZSk7XG5cbiAgICAgICAgLy8gZm9ybWF0IHRoZSBmb2N1c1xuICAgICAgICBsZXQgdGV4dCA9ICcnO1xuICAgICAgICBpZiAoc2hvd05hbWUpIHtcbiAgICAgICAgICAgIHRleHQgPSBvYmoudW5pdF9uYW1lICsgJyAnO1xuICAgICAgICB9XG4gICAgICAgIHRleHQgKz0gZm9ybWF0VHVybm92ZXIob2JqW2ZpZWxkXSk7XG4gICAgICAgIGZvY3VzLnRleHQodGV4dCk7XG4gICAgICAgIGZvY3VzLmNsYXNzZWQoJ2hpZGRlbicsIGZhbHNlKVxuXG4gICAgICAgIGNlbnRlck9uWChmb2N1cywgeChvYmopICsgbWFyZ2luLmxlZnQpO1xuICAgICAgICAvLyBtb3ZlIHRvIHRvcFxuICAgICAgICBsZXQgaG92ZXJlZCA9IHN2Zy5zZWxlY3QoJy5ob3ZlcmVkJykubm9kZSgpO1xuICAgICAgICBob3ZlcmVkLnBhcmVudEVsZW1lbnQuYXBwZW5kQ2hpbGQoaG92ZXJlZCk7XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gdG91Y2htb3ZlKCkge1xuICAgICAgICB2YXIgbW91c2VYID0gZDMudG91Y2hlcyh0aGlzKVswXVswXTtcbiAgICAgICAgdmFyIGZvdW5kID0gaGl0RGV0ZWN0b3IuZmluZChtb3VzZVgsIDAsIDIwKTtcblxuICAgICAgICBpZiAoZm91bmQpIHtcbiAgICAgICAgICAgIGZvdW5kID0gZm91bmQuZGF0YTtcbiAgICAgICAgICAgIC8vIGNvbnNvbGUubG9nKCdmb3VuZCBob3ZlcicsIGZvdW5kKTtcbiAgICAgICAgICAgIG9uSG92ZXIoZm91bmQudW5pdF9uYW1lKTtcbiAgICAgICAgfSBlbHNlIHtcbiAgICAgICAgICAgIG9uSG92ZXIoKTtcbiAgICAgICAgfVxuICAgIH1cblxuICAgIGZ1bmN0aW9uIG1vdXNlbW92ZSgpIHtcbiAgICAgICAgdmFyIG1vdXNlWCA9IGQzLm1vdXNlKHRoaXMpWzBdO1xuICAgICAgICB2YXIgZm91bmQgPSBoaXREZXRlY3Rvci5maW5kKG1vdXNlWCwgMCwgMjApO1xuXG4gICAgICAgIGlmIChmb3VuZCkge1xuICAgICAgICAgICAgZm91bmQgPSBmb3VuZC5kYXRhO1xuICAgICAgICAgICAgLy8gY29uc29sZS5sb2coJ2ZvdW5kIGhvdmVyJywgZm91bmQpO1xuICAgICAgICAgICAgb25Ib3Zlcihmb3VuZC51bml0X25hbWUpO1xuICAgICAgICB9IGVsc2Uge1xuICAgICAgICAgICAgb25Ib3ZlcigpO1xuICAgICAgICB9XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gbW91c2VjbGljaygpIHtcbiAgICAgICAgdmFyIG1vdXNlWCA9IGQzLm1vdXNlKHRoaXMpWzBdO1xuICAgICAgICB2YXIgZm91bmQgPSBoaXREZXRlY3Rvci5maW5kKG1vdXNlWCwgMCwgMjApO1xuXG4gICAgICAgIGlmIChmb3VuZCkge1xuICAgICAgICAgICAgaWYgKG9uQ2xpY2spIHtcbiAgICAgICAgICAgICAgICBvbkNsaWNrKGZvdW5kLmRhdGEudW5pdF9uYW1lKTtcbiAgICAgICAgICAgIH1cbiAgICAgICAgfVxuICAgIH1cblxuICAgIHJldHVybiB7XG4gICAgICAgIHJlZHJhdzogcmVkcmF3LFxuICAgICAgICBoaWdobGlnaHQ6IHJlbmRlckhvdmVyLFxuICAgICAgICBjbGVhckhpZ2hsaWdodDogY2xlYXJIb3ZlclxuICAgIH1cbn1cblxuZnVuY3Rpb24gVHVybm92ZXJDaGFydChwYXJhbXMpIHtcbiAgICBsZXQge2VsZW1lbnQsIGRhdGFVcmwsIHBhcmssIG9uQ2xpY2ssIHNlYXNvbn0gPSBwYXJhbXM7XG4gICAgbGV0IF9zZWFzb24gPSBzZWFzb24gfHwgJ3N1bW1lcic7XG5cbiAgICBlbGVtZW50ID0gZDMuc2VsZWN0KGVsZW1lbnQpO1xuXG4gICAgLy8gY3JlYXRlIHRoZSB0ZW1wbGF0ZVxuICAgIGVsZW1lbnQuaHRtbChgXG4gICAgICAgIDxkaXYgY2xhc3M9XCJzZC10dXJub3Zlci1jaGFydFwiPlxuICAgICAgICAgICAgPGRpdiBjbGFzcz1cInNkLWRvdC1jaGFydFwiPlxuICAgICAgICAgICAgICAgIDxkaXYgaWQ9XCJzZC1tYWluY2hhcnRcIj48L2Rpdj5cbiAgICAgICAgICAgICAgICA8ZGl2IGNsYXNzPVwic2QtbGluZVwiPjwvZGl2PlxuICAgICAgICAgICAgICAgIDxkaXYgY2xhc3M9XCJzZC1sYWJlbC1hcmVhXCI+XG4gICAgICAgICAgICAgICAgICAgIDxoMiBjbGFzcz1cInNkLWF4aXMtbGFiZWxcIj5Qb3RlbnRpYWwgVHVybm92ZXI8L2gyPlxuICAgICAgICAgICAgICAgIDwvZGl2PlxuICAgICAgICAgICAgPC9kaXY+XG4gICAgICAgICAgICA8ZGl2PlxuICAgICAgICAgICAgICAgIDxkaXYgY2xhc3M9XCJzZC1zdWJyb3cgc2QtbGVmdFwiPlxuICAgICAgICAgICAgICAgICAgICA8ZGl2IGNsYXNzPVwic2QtZG90LWNoYXJ0XCI+XG4gICAgICAgICAgICAgICAgICAgICAgICA8ZGl2IGlkPVwic2Qtc3ViY2hhcnQtMVwiPjwvZGl2PlxuICAgICAgICAgICAgICAgICAgICAgICAgPGRpdiBjbGFzcz1cInNkLWxpbmVcIj48L2Rpdj5cbiAgICAgICAgICAgICAgICAgICAgICAgIDxkaXYgY2xhc3M9XCJzZC1sYWJlbC1hcmVhXCI+XG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgPGgyIGNsYXNzPVwic2QtYXhpcy1sYWJlbFwiPlBvdGVudGlhbCBDb2xvbml6YXRpb248L2gyPlxuICAgICAgICAgICAgICAgICAgICAgICAgPC9kaXY+XG4gICAgICAgICAgICAgICAgICAgIDwvZGl2PlxuICAgICAgICAgICAgICAgIDwvZGl2PlxuICAgICAgICAgICAgICAgIDxkaXYgY2xhc3M9XCJzZC1zdWJyb3cgc2QtcmlnaHRcIj5cbiAgICAgICAgICAgICAgICAgICAgPGRpdiBjbGFzcz1cInNkLWRvdC1jaGFydFwiPlxuICAgICAgICAgICAgICAgICAgICAgICAgPGRpdiBpZD1cInNkLXN1YmNoYXJ0LTJcIj48L2Rpdj5cbiAgICAgICAgICAgICAgICAgICAgICAgIDxkaXYgY2xhc3M9XCJzZC1saW5lXCI+PC9kaXY+XG4gICAgICAgICAgICAgICAgICAgICAgICA8ZGl2IGNsYXNzPVwic2QtbGFiZWwtYXJlYVwiPlxuICAgICAgICAgICAgICAgICAgICAgICAgICAgIDxoMiBjbGFzcz1cInNkLWF4aXMtbGFiZWxcIj5Qb3RlbnRpYWwgRXh0aXJwYXRpb248L2gyPlxuICAgICAgICAgICAgICAgICAgICAgICAgPC9kaXY+XG4gICAgICAgICAgICAgICAgICAgIDwvZGl2PlxuICAgICAgICAgICAgICAgIDwvZGl2PlxuICAgICAgICAgICAgPC9kaXY+XG4gICAgICAgIDwvZGl2PlxuICAgIGApO1xuXG4gICAgbGV0IGRhdGEgPSBbXTtcbiAgICBsZXQgbWFpbkNoYXJ0ID0gbmV3IERvdENoYXJ0KHtcbiAgICAgICAgZWxlbWVudDogZWxlbWVudC5zZWxlY3QoJyNzZC1tYWluY2hhcnQnKSxcbiAgICAgICAgc2hvd05hbWU6IHRydWUsXG4gICAgICAgIG9uQ2xpY2s6IG9uQ2xpY2ssXG4gICAgICAgIG9uSG92ZXI6IG9uSG92ZXIsXG4gICAgICAgIHNjYWxlOiAnbGluZWFyJ1xuICAgIH0pO1xuICAgIGxldCBzdWJDaGFydDEgPSBuZXcgRG90Q2hhcnQoe1xuICAgICAgICBlbGVtZW50OiBlbGVtZW50LnNlbGVjdCgnI3NkLXN1YmNoYXJ0LTEnKSxcbiAgICAgICAgc2hvd05hbWU6IGZhbHNlLFxuICAgICAgICBvbkNsaWNrOiBvbkNsaWNrLFxuICAgICAgICBvbkhvdmVyOiBvbkhvdmVyLFxuICAgICAgICBzY2FsZTogJ2xvZydcbiAgICB9KTtcbiAgICBsZXQgc3ViQ2hhcnQyID0gbmV3IERvdENoYXJ0KHtcbiAgICAgICAgZWxlbWVudDogZWxlbWVudC5zZWxlY3QoJyNzZC1zdWJjaGFydC0yJyksXG4gICAgICAgIHNob3dOYW1lOiBmYWxzZSxcbiAgICAgICAgb25DbGljazogb25DbGljayxcbiAgICAgICAgb25Ib3Zlcjogb25Ib3ZlcixcbiAgICAgICAgc2NhbGU6ICdsb2cnXG4gICAgfSk7XG5cbiAgICBmdW5jdGlvbiBvbkhvdmVyKG5hbWUpIHtcbiAgICAgICAgaWYgKCFuYW1lKSB7XG4gICAgICAgICAgICBtYWluQ2hhcnQuY2xlYXJIaWdobGlnaHQoKTtcbiAgICAgICAgICAgIHN1YkNoYXJ0MS5jbGVhckhpZ2hsaWdodCgpO1xuICAgICAgICAgICAgc3ViQ2hhcnQyLmNsZWFySGlnaGxpZ2h0KCk7XG4gICAgICAgICAgICByZXR1cm47XG4gICAgICAgIH1cblxuICAgICAgICBtYWluQ2hhcnQuaGlnaGxpZ2h0KG5hbWUpO1xuICAgICAgICBzdWJDaGFydDEuaGlnaGxpZ2h0KG5hbWUpO1xuICAgICAgICBzdWJDaGFydDIuaGlnaGxpZ2h0KG5hbWUpO1xuICAgIH1cblxuICAgIGZ1bmN0aW9uIHJlZHJhdygpIHtcbiAgICAgICAgbWFpbkNoYXJ0LnJlZHJhdyhkYXRhLCAndHVybm92ZXJfJyArIF9zZWFzb24sIHBhcmspO1xuICAgICAgICBzdWJDaGFydDEucmVkcmF3KGRhdGEsICdwcm9wX2NvbG9uaXphdGlvbnNfJyArIF9zZWFzb24sIHBhcmspO1xuICAgICAgICBzdWJDaGFydDIucmVkcmF3KGRhdGEsICdwcm9wX2V4dGlycGF0aW9uc18nICsgX3NlYXNvbiwgcGFyayk7XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gc2V0U2Vhc29uKHNlYXNvbikge1xuICAgICAgICBpZiAoc2Vhc29uID09PSAnc3VtbWVyJyB8fCBzZWFzb24gPT09ICd3aW50ZXInKSB7XG4gICAgICAgICAgICBfc2Vhc29uID0gc2Vhc29uO1xuICAgICAgICAgICAgcmVkcmF3KCk7XG4gICAgICAgIH0gZWxzZSB7XG4gICAgICAgICAgICBjb25zb2xlLmxvZygnRVJST1I6IHNlYXNvbiBtdXN0IGJlIHN1bW1lciBvciB3aW50ZXIsIHJlY2VpdmVkJywgc2Vhc29uKTtcbiAgICAgICAgfVxuICAgIH1cblxuICAgIGQzLmNzdihkYXRhVXJsLCAoZXJyb3IsIHJvd3MpID0+IHtcbiAgICAgICAgY29uc29sZS5sb2coZXJyb3IpO1xuXG4gICAgICAgIC8vIHByZXByb2Nlc3NcbiAgICAgICAgcm93cy5mb3JFYWNoKHIgPT4ge1xuICAgICAgICAgICAgci5wcm9wX2NvbG9uaXphdGlvbnNfc3VtbWVyID0gK3IucHJvcF9jb2xvbml6YXRpb25zX3N1bW1lcjtcbiAgICAgICAgICAgIHIucHJvcF9jb2xvbml6YXRpb25zX3dpbnRlciA9ICtyLnByb3BfY29sb25pemF0aW9uc193aW50ZXI7XG4gICAgICAgICAgICByLnByb3BfZXh0aXJwYXRpb25zX3N1bW1lciA9ICtyLnByb3BfZXh0aXJwYXRpb25zX3N1bW1lcjtcbiAgICAgICAgICAgIHIucHJvcF9leHRpcnBhdGlvbnNfd2ludGVyID0gK3IucHJvcF9leHRpcnBhdGlvbnNfd2ludGVyO1xuICAgICAgICAgICAgci50dXJub3Zlcl9zdW1tZXIgPSArci50dXJub3Zlcl9zdW1tZXI7XG4gICAgICAgICAgICByLnR1cm5vdmVyX3dpbnRlciA9ICtyLnR1cm5vdmVyX3dpbnRlcjtcbiAgICAgICAgfSlcblxuICAgICAgICAvLyBjb25zb2xlLmxvZyhyb3dzKTtcbiAgICAgICAgZGF0YSA9IHJvd3M7XG5cbiAgICAgICAgcmVkcmF3KCk7XG4gICAgICAgIHdpbmRvdy5hZGRFdmVudExpc3RlbmVyKFwicmVzaXplXCIsIHJlZHJhdyk7XG4gICAgfSk7XG5cbiAgICByZXR1cm4ge1xuICAgICAgICBzZXRTZWFzb246IHNldFNlYXNvblxuICAgIH1cbn1cblxuZXhwb3J0IHsgVHVybm92ZXJDaGFydCB9O1xuIl19