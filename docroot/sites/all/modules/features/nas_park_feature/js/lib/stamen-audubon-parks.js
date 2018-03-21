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

var regions = [['Alaska', 'Alaska', 'https://cdn.audubon.org/cdn/farfuture/fFGf-bOAIxRXDiimvPWD0aLHshc6VMFBdLu488zC8SE/mtime:1521225912/sites/default/files/0315-alaska-photo2x.jpg'], ['Intermountain', 'Intermountain', 'https://cdn.audubon.org/cdn/farfuture/0uMkGr8PaPD0alIdEsCNnQ0La4LbkyNeQfVLw4E2bpM/mtime:1521225946/sites/default/files/0315-intermountain-photo2x.jpg'], ['Midwest', 'Midwest', 'https://cdn.audubon.org/cdn/farfuture/Txer_SOH0uWvlxEqJC3V85XwzMbA8SUtqsV83n-f4JA/mtime:1521651728/sites/default/files/0321-midwest-photo.jpg'], ['Northeast', 'Northeast', 'https://cdn.audubon.org/cdn/farfuture/Lgsy-l3ccfiEppla48j0svjtBmtsnxpJX2mqOaYax-A/mtime:1521226061/sites/default/files/0315-northeast-photo2x.jpg'], ['Pacific', 'Pacific West', 'https://cdn.audubon.org/cdn/farfuture/BglTnZ49xpBUWONDWdbiNCLj0TMoIT9xw8g3KzMFKkc/mtime:1521651765/sites/default/files/0321-pacific-photo.jpg'], ['Southeast', 'Southeast', 'https://cdn.audubon.org/cdn/farfuture/7sD_Rcq01-tYu5oDG8BzgRVdJ5GN1UyJ4h47Mt-24uE/mtime:1521651788/sites/default/files/0321-southeast-photo.jpg']];

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

      var regionDiv = node.append('div').classed('sd-region', true).html('\n            <div class="region-header">\n              <a name="nps-region-' + region + '"></a>\n              <img class="background-image" src="' + regionImage + '">\n              <h1>' + npsRegion + '</h1>\n            </div>\n            <div class="row">\n              <div class="columns small-12">\n                <div class="dot-legend">\n                  <div class="dot-legend-entry colonized">Potential colonization</div>\n                  <div class="dot-legend-entry current">Stable population</div>\n                  <div class="dot-legend-entry extirpated">Potential extirpation</div>\n                </div>\n                <div class="dot-area">\n                </div>\n              </div>\n            </div>\n        ');

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
        if (error) {
            console.log(error);
            return;
        }

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
