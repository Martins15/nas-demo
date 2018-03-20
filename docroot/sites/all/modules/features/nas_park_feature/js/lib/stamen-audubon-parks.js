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
//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbIm5vZGVfbW9kdWxlcy9icm93c2VyLXBhY2svX3ByZWx1ZGUuanMiLCJqcy9hbGJlcnNCaWdBbGFza2EuanMiLCJqcy9hbGxQYXJrcy5qcyIsImpzL2JpcmREb3QuanMiLCJqcy9iaXJkRG90TGFuZGluZ1BhZ2UuanMiLCJqcy9pbmRleC5qcyIsImpzL3BhcmtNYXAuanMiLCJqcy90dXJub3Zlci5qcyJdLCJuYW1lcyI6W10sIm1hcHBpbmdzIjoiQUFBQTs7Ozs7O1FDNkZnQixlLEdBQUEsZTtBQTdGaEI7QUFDQTtBQUNBOztBQUVBLElBQUksWUFBWSxJQUFoQjtBQUNBLFNBQVMsTUFBVCxHQUFrQixDQUFFO0FBQ3BCLElBQUksT0FBTyxRQUFYO0FBQ0EsSUFBSSxPQUFPLElBQVg7QUFDQSxJQUFJLEtBQUssQ0FBQyxJQUFWO0FBQ0EsSUFBSSxLQUFLLEVBQVQ7O0FBRUEsSUFBSSxpQkFBaUI7QUFDbkIsU0FBTyxhQURZO0FBRW5CLGFBQVcsTUFGUTtBQUduQixXQUFTLE1BSFU7QUFJbkIsZ0JBQWMsTUFKSztBQUtuQixjQUFZLE1BTE87QUFNbkIsVUFBUSxrQkFBVztBQUNqQixRQUFJLFNBQVMsQ0FBQyxDQUFDLElBQUQsRUFBTyxJQUFQLENBQUQsRUFBZSxDQUFDLEVBQUQsRUFBSyxFQUFMLENBQWYsQ0FBYjtBQUNBLFNBQUssS0FBSyxFQUFFLE9BQU8sT0FBTyxRQUFoQixDQUFWO0FBQ0EsV0FBTyxNQUFQO0FBQ0Q7QUFWa0IsQ0FBckI7O0FBYUEsU0FBUyxhQUFULENBQXVCLENBQXZCLEVBQTBCLENBQTFCLEVBQTZCO0FBQzNCLE1BQUksSUFBSSxJQUFSLEVBQWMsT0FBTyxDQUFQO0FBQ2QsTUFBSSxJQUFJLEVBQVIsRUFBWSxLQUFLLENBQUw7QUFDWixNQUFJLElBQUksSUFBUixFQUFjLE9BQU8sQ0FBUDtBQUNkLE1BQUksSUFBSSxFQUFSLEVBQVksS0FBSyxDQUFMO0FBQ2I7O0FBRUQsU0FBUyxHQUFULENBQWEsVUFBYixFQUF5QixTQUF6QixFQUFv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LFNBUEQ7O0FBU0E7QUFDQSxlQUFPLElBQVA7O0FBRUE7QUFDQSxlQUFPLGdCQUFQLENBQXdCLFFBQXhCLEVBQWtDLE1BQWxDO0FBQ0gsS0FsQkQ7O0FBb0JBLFdBQU87QUFDSCxtQkFBVztBQURSLEtBQVA7QUFHSDs7UUFFUSxhLEdBQUEsYSIsImZpbGUiOiJnZW5lcmF0ZWQuanMiLCJzb3VyY2VSb290IjoiIiwic291cmNlc0NvbnRlbnQiOlsiKGZ1bmN0aW9uKCl7ZnVuY3Rpb24gZSh0LG4scil7ZnVuY3Rpb24gcyhvLHUpe2lmKCFuW29dKXtpZighdFtvXSl7dmFyIGE9dHlwZW9mIHJlcXVpcmU9PVwiZnVuY3Rpb25cIiYmcmVxdWlyZTtpZighdSYmYSlyZXR1cm4gYShvLCEwKTtpZihpKXJldHVybiBpKG8sITApO3ZhciBmPW5ldyBFcnJvcihcIkNhbm5vdCBmaW5kIG1vZHVsZSAnXCIrbytcIidcIik7dGhyb3cgZi5jb2RlPVwiTU9EVUxFX05PVF9GT1VORFwiLGZ9dmFyIGw9bltvXT17ZXhwb3J0czp7fX07dFtvXVswXS5jYWxsKGwuZXhwb3J0cyxmdW5jdGlvbihlKXt2YXIgbj10W29dWzFdW2VdO3JldHVybiBzKG4/bjplKX0sbCxsLmV4cG9ydHMsZSx0LG4scil9cmV0dXJuIG5bb10uZXhwb3J0c312YXIgaT10eXBlb2YgcmVxdWlyZT09XCJmdW5jdGlvblwiJiZyZXF1aXJlO2Zvcih2YXIgbz0wO288ci5sZW5ndGg7bysrKXMocltvXSk7cmV0dXJuIHN9cmV0dXJuIGV9KSgpIiwiLy8gbG90cyBvZiBzdHVmZiBoYXJ2ZXN0ZWQgZnJvbSBkMy5qc1xuLy8gb25seSByZWFsIGRpZmZlcmVuY2UgaXMgcm90YXRpb24gLyBzY2FsZSAvIGNsaXBwcGluZyBhbmQgdHJhbnNsYXRpb24gb2Zcbi8vIHRoZSBhbGFza2EgcG9ydGlvbiBvZiBhbGJlcnNVc2FcblxudmFyIGVwc2lsb24kMiA9IDFlLTY7XG5mdW5jdGlvbiBub29wJDEoKSB7fVxudmFyIHgwJDIgPSBJbmZpbml0eTtcbnZhciB5MCQyID0geDAkMjtcbnZhciB4MSA9IC14MCQyO1xudmFyIHkxID0geDE7XG5cbnZhciBib3VuZHNTdHJlYW0kMSA9IHtcbiAgcG9pbnQ6IGJvdW5kc1BvaW50JDEsXG4gIGxpbmVTdGFydDogbm9vcCQxLFxuICBsaW5lRW5kOiBub29wJDEsXG4gIHBvbHlnb25TdGFydDogbm9vcCQxLFxuICBwb2x5Z29uRW5kOiBub29wJDEsXG4gIHJlc3VsdDogZnVuY3Rpb24oKSB7XG4gICAgdmFyIGJvdW5kcyA9IFtbeDAkMiwgeTAkMl0sIFt4MSwgeTFdXTtcbiAgICB4MSA9IHkxID0gLSh5MCQyID0geDAkMiA9IEluZmluaXR5KTtcbiAgICByZXR1cm4gYm91bmRzO1xuICB9XG59O1xuXG5mdW5jdGlvbiBib3VuZHNQb2ludCQxKHgsIHkpIHtcbiAgaWYgKHggPCB4MCQyKSB4MCQyID0geDtcbiAgaWYgKHggPiB4MSkgeDEgPSB4O1xuICBpZiAoeSA8IHkwJDIpIHkwJDIgPSB5O1xuICBpZiAoeSA+IHkxKSB5MSA9IHk7XG59XG5cbmZ1bmN0aW9uIGZpdChwcm9qZWN0aW9uLCBmaXRCb3VuZHMsIG9iamVjdCkge1xuICB2YXIgY2xpcCA9IHByb2plY3Rpb24uY2xpcEV4dGVudCAmJiBwcm9qZWN0aW9uLmNsaXBFeHRlbnQoKTtcbiAgcHJvamVjdGlvbi5zY2FsZSgxNTApLnRyYW5zbGF0ZShbMCwgMF0pO1xuICBpZiAoY2xpcCAhPSBudWxsKSBwcm9qZWN0aW9uLmNsaXBFeHRlbnQobnVsbCk7XG4gIGQzLmdlb1N0cmVhbShvYmplY3QsIHByb2plY3Rpb24uc3RyZWFtKGJvdW5kc1N0cmVhbSQxKSk7XG4gIGZpdEJvdW5kcyhib3VuZHNTdHJlYW0kMS5yZXN1bHQoKSk7XG4gIGlmIChjbGlwICE9IG51bGwpIHByb2plY3Rpb24uY2xpcEV4dGVudChjbGlwKTtcbiAgcmV0dXJuIHByb2plY3Rpb247XG59XG5cbmZ1bmN0aW9uIGZpdEV4dGVudChwcm9qZWN0aW9uLCBleHRlbnQsIG9iamVjdCkge1xuICByZXR1cm4gZml0KHByb2plY3Rpb24sIGZ1bmN0aW9uKGIpIHtcbiAgICB2YXIgdyA9IGV4dGVudFsxXVswXSAtIGV4dGVudFswXVswXSxcbiAgICAgICAgaCA9IGV4dGVudFsxXVsxXSAtIGV4dGVudFswXVsxXSxcbiAgICAgICAgayA9IE1hdGgubWluKHcgLyAoYlsxXVswXSAtIGJbMF1bMF0pLCBoIC8gKGJbMV1bMV0gLSBiWzBdWzFdKSksXG4gICAgICAgIHggPSArZXh0ZW50WzBdWzBdICsgKHcgLSBrICogKGJbMV1bMF0gKyBiWzBdWzBdKSkgLyAyLFxuICAgICAgICB5ID0gK2V4dGVudFswXVsxXSArIChoIC0gayAqIChiWzFdWzFdICsgYlswXVsxXSkpIC8gMjtcbiAgICBwcm9qZWN0aW9uLnNjYWxlKDE1MCAqIGspLnRyYW5zbGF0ZShbeCwgeV0pO1xuICB9LCBvYmplY3QpO1xufVxuXG5mdW5jdGlvbiBmaXRTaXplKHByb2plY3Rpb24sIHNpemUsIG9iamVjdCkge1xuICByZXR1cm4gZml0RXh0ZW50KHByb2plY3Rpb24sIFtbMCwgMF0sIHNpemVdLCBvYmplY3QpO1xufVxuXG5mdW5jdGlvbiBmaXRXaWR0aChwcm9qZWN0aW9uLCB3aWR0aCwgb2JqZWN0KSB7XG4gIHJldHVybiBmaXQocHJvamVjdGlvbiwgZnVuY3Rpb24oYikge1xuICAgIHZhciB3ID0gK3dpZHRoLFxuICAgICAgICBrID0gdyAvIChiWzFdWzBdIC0gYlswXVswXSksXG4gICAgICAgIHggPSAodyAtIGsgKiAoYlsxXVswXSArIGJbMF1bMF0pKSAvIDIsXG4gICAgICAgIHkgPSAtayAqIGJbMF1bMV07XG4gICAgcHJvamVjdGlvbi5zY2FsZSgxNTAgKiBrKS50cmFuc2xhdGUoW3gsIHldKTtcbiAgfSwgb2JqZWN0KTtcbn1cblxuZnVuY3Rpb24gZml0SGVpZ2h0KHByb2plY3Rpb24sIGhlaWdodCwgb2JqZWN0KSB7XG4gIHJldHVybiBmaXQocHJvamVjdGlvbiwgZnVuY3Rpb24oYikge1xuICAgIHZhciBoID0gK2hlaWdodCxcbiAgICAgICAgayA9IGggLyAoYlsxXVsxXSAtIGJbMF1bMV0pLFxuICAgICAgICB4ID0gLWsgKiBiWzBdWzBdLFxuICAgICAgICB5ID0gKGggLSBrICogKGJbMV1bMV0gKyBiWzBdWzFdKSkgLyAyO1xuICAgIHByb2plY3Rpb24uc2NhbGUoMTUwICogaykudHJhbnNsYXRlKFt4LCB5XSk7XG4gIH0sIG9iamVjdCk7XG59XG5cbmZ1bmN0aW9uIG11bHRpcGxleChzdHJlYW1zKSB7XG4gIHZhciBuID0gc3RyZWFtcy5sZW5ndGg7XG4gIHJldHVybiB7XG4gICAgcG9pbnQ6IGZ1bmN0aW9uKHgsIHkpIHsgdmFyIGkgPSAtMTsgd2hpbGUgKCsraSA8IG4pIHN0cmVhbXNbaV0ucG9pbnQoeCwgeSk7IH0sXG4gICAgc3BoZXJlOiBmdW5jdGlvbigpIHsgdmFyIGkgPSAtMTsgd2hpbGUgKCsraSA8IG4pIHN0cmVhbXNbaV0uc3BoZXJlKCk7IH0sXG4gICAgbGluZVN0YXJ0OiBmdW5jdGlvbigpIHsgdmFyIGkgPSAtMTsgd2hpbGUgKCsraSA8IG4pIHN0cmVhbXNbaV0ubGluZVN0YXJ0KCk7IH0sXG4gICAgbGluZUVuZDogZnVuY3Rpb24oKSB7IHZhciBpID0gLTE7IHdoaWxlICgrK2kgPCBuKSBzdHJlYW1zW2ldLmxpbmVFbmQoKTsgfSxcbiAgICBwb2x5Z29uU3RhcnQ6IGZ1bmN0aW9uKCkgeyB2YXIgaSA9IC0xOyB3aGlsZSAoKytpIDwgbikgc3RyZWFtc1tpXS5wb2x5Z29uU3RhcnQoKTsgfSxcbiAgICBwb2x5Z29uRW5kOiBmdW5jdGlvbigpIHsgdmFyIGkgPSAtMTsgd2hpbGUgKCsraSA8IG4pIHN0cmVhbXNbaV0ucG9seWdvbkVuZCgpOyB9XG4gIH07XG59XG5cbi8vIEEgY29tcG9zaXRlIHByb2plY3Rpb24gZm9yIHRoZSBVbml0ZWQgU3RhdGVzLCBjb25maWd1cmVkIGJ5IGRlZmF1bHQgZm9yXG4vLyA5NjDDlzUwMC4gVGhlIHByb2plY3Rpb24gYWxzbyB3b3JrcyBxdWl0ZSB3ZWxsIGF0IDk2MMOXNjAwIGlmIHlvdSBjaGFuZ2UgdGhlXG4vLyBzY2FsZSB0byAxMjg1IGFuZCBhZGp1c3QgdGhlIHRyYW5zbGF0ZSBhY2NvcmRpbmdseS4gVGhlIHNldCBvZiBzdGFuZGFyZFxuLy8gcGFyYWxsZWxzIGZvciBlYWNoIHJlZ2lvbiBjb21lcyBmcm9tIFVTR1MsIHdoaWNoIGlzIHB1Ymxpc2hlZCBoZXJlOlxuLy8gaHR0cDovL2Vnc2MudXNncy5nb3YvaXNiL3B1YnMvTWFwUHJvamVjdGlvbnMvcHJvamVjdGlvbnMuaHRtbCNhbGJlcnNcbmV4cG9ydCBmdW5jdGlvbiBhbGJlcnNCaWdBbGFza2EoKSB7XG4gIHZhciBjYWNoZSxcbiAgICAgIGNhY2hlU3RyZWFtLFxuICAgICAgbG93ZXI0OCA9IGQzLmdlb0FsYmVycygpLCBsb3dlcjQ4UG9pbnQsXG4gICAgICBhbGFza2EgPSBkMy5nZW9Db25pY0VxdWFsQXJlYSgpLnJvdGF0ZShbMTU0LCAwXSkuY2VudGVyKFstMiwgNTguNV0pLnBhcmFsbGVscyhbNTUsIDY1XSksIGFsYXNrYVBvaW50LCAvLyBFUFNHOjMzMzhcbiAgICAgIGhhd2FpaSA9IGQzLmdlb0NvbmljRXF1YWxBcmVhKCkucm90YXRlKFsxNTcsIDBdKS5jZW50ZXIoWy0zLCAxOS45XSkucGFyYWxsZWxzKFs4LCAxOF0pLCBoYXdhaWlQb2ludCwgLy8gRVNSSToxMDIwMDdcbiAgICAgIHBvaW50LCBwb2ludFN0cmVhbSA9IHtwb2ludDogZnVuY3Rpb24oeCwgeSkgeyBwb2ludCA9IFt4LCB5XTsgfX07XG5cbiAgZnVuY3Rpb24gYWxiZXJzVXNhKGNvb3JkaW5hdGVzKSB7XG4gICAgdmFyIHggPSBjb29yZGluYXRlc1swXSwgeSA9IGNvb3JkaW5hdGVzWzFdO1xuICAgIHJldHVybiBwb2ludCA9IG51bGwsIChsb3dlcjQ4UG9pbnQucG9pbnQoeCwgeSksIHBvaW50KVxuICAgICAgICB8fCAoYWxhc2thUG9pbnQucG9pbnQoeCwgeSksIHBvaW50KVxuICAgICAgICB8fCAoaGF3YWlpUG9pbnQucG9pbnQoeCwgeSksIHBvaW50KTtcbiAgfVxuXG4gIGFsYmVyc1VzYS5pbnZlcnQgPSBmdW5jdGlvbihjb29yZGluYXRlcykge1xuICAgIHZhciBrID0gbG93ZXI0OC5zY2FsZSgpLFxuICAgICAgICB0ID0gbG93ZXI0OC50cmFuc2xhdGUoKSxcbiAgICAgICAgeCA9IChjb29yZGluYXRlc1swXSAtIHRbMF0pIC8gayxcbiAgICAgICAgeSA9IChjb29yZGluYXRlc1sxXSAtIHRbMV0pIC8gaztcbiAgICByZXR1cm4gKHkgPj0gMC4xMjAgJiYgeSA8IDAuMjM0ICYmIHggPj0gLTAuNDI1ICYmIHggPCAtMC4yMTQgPyBhbGFza2FcbiAgICAgICAgOiB5ID49IDAuMTY2ICYmIHkgPCAwLjIzNCAmJiB4ID49IC0wLjIxNCAmJiB4IDwgLTAuMTE1ID8gaGF3YWlpXG4gICAgICAgIDogbG93ZXI0OCkuaW52ZXJ0KGNvb3JkaW5hdGVzKTtcbiAgfTtcblxuICBhbGJlcnNVc2Euc3RyZWFtID0gZnVuY3Rpb24oc3RyZWFtKSB7XG4gICAgcmV0dXJuIGNhY2hlICYmIGNhY2hlU3RyZWFtID09PSBzdHJlYW0gPyBjYWNoZSA6IGNhY2hlID0gbXVsdGlwbGV4KFtsb3dlcjQ4LnN0cmVhbShjYWNoZVN0cmVhbSA9IHN0cmVhbSksIGFsYXNrYS5zdHJlYW0oc3RyZWFtKSwgaGF3YWlpLnN0cmVhbShzdHJlYW0pXSk7XG4gIH07XG5cbiAgYWxiZXJzVXNhLnByZWNpc2lvbiA9IGZ1bmN0aW9uKF8pIHtcbiAgICBpZiAoIWFyZ3VtZW50cy5sZW5ndGgpIHJldHVybiBsb3dlcjQ4LnByZWNpc2lvbigpO1xuICAgIGxvd2VyNDgucHJlY2lzaW9uKF8pLCBhbGFza2EucHJlY2lzaW9uKF8pLCBoYXdhaWkucHJlY2lzaW9uKF8pO1xuICAgIHJldHVybiByZXNldCgpO1xuICB9O1xuXG4gIGFsYmVyc1VzYS5zY2FsZSA9IGZ1bmN0aW9uKF8pIHtcbiAgICBpZiAoIWFyZ3VtZW50cy5sZW5ndGgpIHJldHVybiBsb3dlcjQ4LnNjYWxlKCk7XG4gICAgbG93ZXI0OC5zY2FsZShfKSwgYWxhc2thLnNjYWxlKF8gKiAwLjUyKSwgaGF3YWlpLnNjYWxlKF8pO1xuICAgIHJldHVybiBhbGJlcnNVc2EudHJhbnNsYXRlKGxvd2VyNDgudHJhbnNsYXRlKCkpO1xuICB9O1xuXG4gIGFsYmVyc1VzYS50cmFuc2xhdGUgPSBmdW5jdGlvbihfKSB7XG4gICAgaWYgKCFhcmd1bWVudHMubGVuZ3RoKSByZXR1cm4gbG93ZXI0OC50cmFuc2xhdGUoKTtcbiAgICB2YXIgayA9IGxvd2VyNDguc2NhbGUoKSwgeCA9ICtfWzBdLCB5ID0gK19bMV07XG5cbiAgICBsb3dlcjQ4UG9pbnQgPSBsb3dlcjQ4XG4gICAgICAgIC50cmFuc2xhdGUoXylcbiAgICAgICAgLmNsaXBFeHRlbnQoW1t4IC0gMC40NTUgKiBrLCB5IC0gMC4yMzggKiBrXSwgW3ggKyAwLjQ1NSAqIGssIHkgKyAwLjIzOCAqIGtdXSlcbiAgICAgICAgLnN0cmVhbShwb2ludFN0cmVhbSk7XG5cbiAgICBhbGFza2FQb2ludCA9IGFsYXNrYVxuICAgICAgICAudHJhbnNsYXRlKFt4IC0gMC4zMDcgKiBrLCB5ICsgMC4yMTEgKiBrXSlcbiAgICAgICAgLmNsaXBFeHRlbnQoW1t4IC0gMC40MjUgKiBrICsgZXBzaWxvbiQyLCB5ICsgMC4wMjAgKiBrICsgZXBzaWxvbiQyXSwgW3ggLSAwLjE4NCAqIGsgLSBlcHNpbG9uJDIsIHkgKyAwLjI1NCAqIGsgLSBlcHNpbG9uJDJdXSlcbiAgICAgICAgLnN0cmVhbShwb2ludFN0cmVhbSk7XG5cbiAgICBoYXdhaWlQb2ludCA9IGhhd2FpaVxuICAgICAgICAudHJhbnNsYXRlKFt4IC0gMC4yMDUgKiBrLCB5ICsgMC4yMTIgKiBrXSlcbiAgICAgICAgLmNsaXBFeHRlbnQoW1t4IC0gMC4yMTQgKiBrICsgZXBzaWxvbiQyLCB5ICsgMC4xNjYgKiBrICsgZXBzaWxvbiQyXSwgW3ggLSAwLjExNSAqIGsgLSBlcHNpbG9uJDIsIHkgKyAwLjIzNCAqIGsgLSBlcHNpbG9uJDJdXSlcbiAgICAgICAgLnN0cmVhbShwb2ludFN0cmVhbSk7XG5cbiAgICByZXR1cm4gcmVzZXQoKTtcbiAgfTtcblxuICBhbGJlcnNVc2EuZml0RXh0ZW50ID0gZnVuY3Rpb24oZXh0ZW50LCBvYmplY3QpIHtcbiAgICByZXR1cm4gZml0RXh0ZW50KGFsYmVyc1VzYSwgZXh0ZW50LCBvYmplY3QpO1xuICB9O1xuXG4gIGFsYmVyc1VzYS5maXRTaXplID0gZnVuY3Rpb24oc2l6ZSwgb2JqZWN0KSB7XG4gICAgcmV0dXJuIGZpdFNpemUoYWxiZXJzVXNhLCBzaXplLCBvYmplY3QpO1xuICB9O1xuXG4gIGFsYmVyc1VzYS5maXRXaWR0aCA9IGZ1bmN0aW9uKHdpZHRoLCBvYmplY3QpIHtcbiAgICByZXR1cm4gZml0V2lkdGgoYWxiZXJzVXNhLCB3aWR0aCwgb2JqZWN0KTtcbiAgfTtcblxuICBhbGJlcnNVc2EuZml0SGVpZ2h0ID0gZnVuY3Rpb24oaGVpZ2h0LCBvYmplY3QpIHtcbiAgICByZXR1cm4gZml0SGVpZ2h0KGFsYmVyc1VzYSwgaGVpZ2h0LCBvYmplY3QpO1xuICB9O1xuXG4gIGZ1bmN0aW9uIHJlc2V0KCkge1xuICAgIGNhY2hlID0gY2FjaGVTdHJlYW0gPSBudWxsO1xuICAgIHJldHVybiBhbGJlcnNVc2E7XG4gIH1cblxuICByZXR1cm4gYWxiZXJzVXNhLnNjYWxlKDEwNzApO1xufVxuIiwiaW1wb3J0IHsgQmlyZERvdHNCYXNlIH0gZnJvbSAnLi9iaXJkRG90JztcblxubGV0IHJlZ2lvbnMgPSBbXG4gIFsnQWxhc2thJywgJ0FsYXNrYScsICdodHRwczovL2Nkbi5hdWR1Ym9uLm9yZy9jZG4vZmFyZnV0dXJlL2ZGR2YtYk9BSXhSWERpaW12UFdEMGFMSHNoYzZWTUZCZEx1NDg4ekM4U0UvbXRpbWU6MTUyMTIyNTkxMi9zaXRlcy9kZWZhdWx0L2ZpbGVzLzAzMTUtYWxhc2thLXBob3RvMnguanBnJ10sXG4gIFsnSW50ZXJtb3VudGFpbicsICdJbnRlcm1vdW50YWluJywgJ2h0dHBzOi8vY2RuLmF1ZHVib24ub3JnL2Nkbi9mYXJmdXR1cmUvMHVNa0dyOFBhUEQwYWxJZEVzQ05uUTBMYTRMYmt5TmVRZlZMdzRFMmJwTS9tdGltZToxNTIxMjI1OTQ2L3NpdGVzL2RlZmF1bHQvZmlsZXMvMDMxNS1pbnRlcm1vdW50YWluLXBob3RvMnguanBnJ10sXG4gIFsnTWlkd2VzdCcsICdNaWR3ZXN0JywgJ2h0dHBzOi8vY2RuLmF1ZHVib24ub3JnL2Nkbi9mYXJmdXR1cmUvS3FReENFUHJhTXlaNDgzQlItTWpTRG92Y3JIdUdzVWtCN3VSUk5BUS1Yby9tdGltZToxNTIxMjI2MDIyL3NpdGVzL2RlZmF1bHQvZmlsZXMvMDMxNS1taWR3ZXN0LXBob3RvMnguanBnJ10sXG4gIFsnTm9ydGhlYXN0JywgJ05vcnRoZWFzdCcsICdodHRwczovL2Nkbi5hdWR1Ym9uLm9yZy9jZG4vZmFyZnV0dXJlL0xnc3ktbDNjY2ZpRXBwbGE0OGowc3ZqdEJtdHNueHBKWDJtcU9hWWF4LUEvbXRpbWU6MTUyMTIyNjA2MS9zaXRlcy9kZWZhdWx0L2ZpbGVzLzAzMTUtbm9ydGhlYXN0LXBob3RvMnguanBnJ10sXG4gIFsnUGFjaWZpYycsICdQYWNpZmljIFdlc3QnLCAnaHR0cHM6Ly9jZG4uYXVkdWJvbi5vcmcvY2RuL2ZhcmZ1dHVyZS9FTjNZeWdXTlN2SHNfZUVaYjUweWgyRjFBT05aOTd1dVVaQWJ2b2M3dVVnL210aW1lOjE1MjEyMjU4MjMvc2l0ZXMvZGVmYXVsdC9maWxlcy8wMzE1LXBhY2lmaWMtcGhvdG8yeC5qcGcnXSxcbiAgWydTb3V0aGVhc3QnLCAnU291dGhlYXN0JywgJ2h0dHBzOi8vY2RuLmF1ZHVib24ub3JnL2Nkbi9mYXJmdXR1cmUvWTgtci1fUmtLa1dLeG9NU01BLXhIVWRsamJUM0dqb1VrQjV0UHIxRVFvby9tdGltZToxNTIxMjI1ODY0L3NpdGVzL2RlZmF1bHQvZmlsZXMvMDMxNS1zb3V0aGVhc3QtcGhvdG8yeC5qcGcnXVxuXTtcblxuZnVuY3Rpb24gQWxsUGFya3MocGFyYW1zKSB7XG4gIGNvbnN0IHsgZWxlbWVudCwgZGF0YVVybCwgb25DbGlja30gPSBwYXJhbXM7XG5cbiAgbGV0IG5vZGUgPSBkMy5zZWxlY3QoZWxlbWVudCk7XG5cbiAgZnVuY3Rpb24gcmVuZGVyUGFyayhjb250YWluZXIsIHBhcmtEYXRhKSB7XG4gICAgbGV0IGMgPSBjb250YWluZXIuYXBwZW5kKCdkaXYnKVxuICAgICAgLmNsYXNzZWQoJ3NkLXBhcmsnLCB0cnVlKVxuICAgICAgLmh0bWwoYFxuICAgICAgICA8aDM+JHtwYXJrRGF0YS51bml0X25hbWV9PC9oMz5cbiAgICAgICAgPGRpdj5cbiAgICAgICAgICA8ZGl2IGNsYXNzPVwic2Vhc29uIHNlYXNvbi13aW50ZXJcIj5cbiAgICAgICAgICAgIDxwPndpbnRlcjwvcD5cbiAgICAgICAgICA8L2Rpdj5cbiAgICAgICAgICA8ZGl2IGNsYXNzPVwic2Vhc29uIHNlYXNvbi1zdW1tZXJcIj5cbiAgICAgICAgICAgIDxwPnN1bW1lcjwvcD5cbiAgICAgICAgICA8L2Rpdj5cbiAgICAgICAgPC9kaXY+XG4gICAgICBgKVxuXG4gICAgaWYgKG9uQ2xpY2spIHtcbiAgICAgIGMuc2VsZWN0KCdoMycpLm9uKCdjbGljaycsICgpID0+IG9uQ2xpY2soYy5zZWxlY3QoJ2gzJykudGV4dCgpKSk7XG4gICAgfVxuXG4gICAgbGV0IG51bURvdHMgPSBNYXRoLm1heChcbiAgICAgICtwYXJrRGF0YS5ub19jb2xvbml6YXRpb25zX3N1bW1lciArICtwYXJrRGF0YS5jdXJyZW50X3NwZWNpZXNfc3VtbWVyLFxuICAgICAgK3BhcmtEYXRhLm5vX2NvbG9uaXphdGlvbnNfd2ludGVyICsgK3BhcmtEYXRhLmN1cnJlbnRfc3BlY2llc193aW50ZXIpXG5cbiAgICBsZXQgc3VtbWVyUGFyYW1zID0ge1xuICAgICAgICBlbGVtZW50OiBjLnNlbGVjdCgnLnNlYXNvbi1zdW1tZXInKS5ub2RlKCksXG4gICAgICAgIG51bUN1cnJlbnQ6ICtwYXJrRGF0YS5jdXJyZW50X3NwZWNpZXNfc3VtbWVyLFxuICAgICAgICBudW1Db2xvbml6ZWQ6ICtwYXJrRGF0YS5ub19jb2xvbml6YXRpb25zX3N1bW1lcixcbiAgICAgICAgbnVtRXh0aXJwYXRlZDogK3BhcmtEYXRhLm5vX2V4dGlycGF0aW9uc19zdW1tZXIsXG4gICAgICAgIHJlbmRlckFsbDogdHJ1ZSxcbiAgICAgICAgbnVtQ29sczogNixcbiAgICAgICAgdG9wQWxpZ246IHRydWVcbiAgICB9O1xuXG4gICAgbGV0IHdpbnRlclBhcmFtcyA9IHtcbiAgICAgICAgZWxlbWVudDogYy5zZWxlY3QoJy5zZWFzb24td2ludGVyJykubm9kZSgpLFxuICAgICAgICBudW1DdXJyZW50OiArcGFya0RhdGEuY3VycmVudF9zcGVjaWVzX3dpbnRlcixcbiAgICAgICAgbnVtQ29sb25pemVkOiArcGFya0RhdGEubm9fY29sb25pemF0aW9uc193aW50ZXIsXG4gICAgICAgIG51bUV4dGlycGF0ZWQ6ICtwYXJrRGF0YS5ub19leHRpcnBhdGlvbnNfd2ludGVyLFxuICAgICAgICByZW5kZXJBbGw6IHRydWUsXG4gICAgICAgIG51bUNvbHM6IDYsXG4gICAgICAgIHRvcEFsaWduOiB0cnVlXG4gICAgfTtcbiAgICBuZXcgQmlyZERvdHNCYXNlKHN1bW1lclBhcmFtcyk7XG4gICAgbmV3IEJpcmREb3RzQmFzZSh3aW50ZXJQYXJhbXMpO1xuICB9XG5cbiAgZDMuY3N2KGRhdGFVcmwsIChlcnJvciwgcm93cykgPT4ge1xuXG4gICAgaWYgKGVycm9yKSB7XG4gICAgICBjb25zb2xlLmxvZyhlcnJvcik7XG4gICAgICByZXR1cm47XG4gICAgfVxuXG4gICAgbGV0IG5lc3RlZCA9IGQzLm5lc3QoKS5rZXkoZCA9PiBkLm5wc19yZWdpb24pLm1hcChyb3dzKVxuXG4gICAgcmVnaW9ucy5mb3JFYWNoKChbcmVnaW9uLCBucHNSZWdpb24sIHJlZ2lvbkltYWdlXSkgPT4ge1xuICAgICAgbGV0IHJlZ2lvbkRpdiA9IG5vZGUuYXBwZW5kKCdkaXYnKVxuICAgICAgICAuY2xhc3NlZCgnc2QtcmVnaW9uJywgdHJ1ZSlcbiAgICAgICAgLmh0bWwoYFxuICAgICAgICAgICAgPGRpdiBjbGFzcz1cInJlZ2lvbi1oZWFkZXJcIj5cbiAgICAgICAgICAgICAgPGEgbmFtZT1cIm5wcy1yZWdpb24tJHtyZWdpb259XCI+PC9hPlxuICAgICAgICAgICAgICA8aW1nIGNsYXNzPVwiYmFja2dyb3VuZC1pbWFnZVwiIHNyYz1cIiR7cmVnaW9uSW1hZ2V9XCI+XG4gICAgICAgICAgICAgIDxoMT4ke25wc1JlZ2lvbn08L2gxPlxuICAgICAgICAgICAgPC9kaXY+XG4gICAgICAgICAgICA8ZGl2IGNsYXNzPVwicm93XCI+XG4gICAgICAgICAgICAgIDxkaXYgY2xhc3M9XCJjb2x1bW5zIHNtYWxsLTEyXCI+XG4gICAgICAgICAgICAgICAgPGRpdiBjbGFzcz1cImRvdC1sZWdlbmRcIj5cbiAgICAgICAgICAgICAgICAgIDxkaXYgY2xhc3M9XCJkb3QtbGVnZW5kLWVudHJ5IGNvbG9uaXplZFwiPlBvdGVudGlhbCBjb2xvbml6YXRpb248L2Rpdj5cbiAgICAgICAgICAgICAgICAgIDxkaXYgY2xhc3M9XCJkb3QtbGVnZW5kLWVudHJ5IGN1cnJlbnRcIj5TdGFibGUgcG9wdWxhdGlvbjwvZGl2PlxuICAgICAgICAgICAgICAgICAgPGRpdiBjbGFzcz1cImRvdC1sZWdlbmQtZW50cnkgZXh0aXJwYXRlZFwiPlBvdGVudGlhbCBleHRpcnBhdGlvbjwvZGl2PlxuICAgICAgICAgICAgICAgIDwvZGl2PlxuICAgICAgICAgICAgICAgIDxkaXYgY2xhc3M9XCJkb3QtYXJlYVwiPlxuICAgICAgICAgICAgICAgIDwvZGl2PlxuICAgICAgICAgICAgICA8L2Rpdj5cbiAgICAgICAgICAgIDwvZGl2PlxuICAgICAgICBgKVxuXG4gICAgICBsZXQgcGFya3MgPSBuZXN0ZWQuZ2V0KG5wc1JlZ2lvbik7XG4gICAgICBpZiAocGFya3MpIHtcbiAgICAgICAgcGFya3MuZm9yRWFjaChwYXJrRGF0YSA9PiB7XG4gICAgICAgICAgcmVuZGVyUGFyayhyZWdpb25EaXYuc2VsZWN0KCcuZG90LWFyZWEnKSwgcGFya0RhdGEpO1xuICAgICAgICB9KTtcbiAgICAgIH1cblxuICAgIH0pO1xuICB9KTtcbn1cblxuZXhwb3J0IHsgQWxsUGFya3MgfTtcbiIsIi8vIEJpcmQgRG90IGFuaW1hdGlvbnNcblxuXG5mdW5jdGlvbiBhbmltYXRlQ291bnQoZWxlbWVudCwgc3RhcnQsIGVuZCwgZHVyYXRpb24pIHtcbiAgICAvLyBlbmQgaXMgYSBudW1iZXIgc3RhcnQgaXMgYSBudW1iZXJcbiAgICBjb25zdCBpbnRlcnBvbGF0b3IgPSBkMy5pbnRlcnBvbGF0ZU51bWJlcihzdGFydCwgZW5kKTtcbiAgICBsZXQgYW5pbWF0aW9uVGltZXI7XG5cbiAgICBmdW5jdGlvbiBhbmltYXRpb25GdW5jKGVsYXBzZWQpIHtcbiAgICAgIGNvbnN0IHN0ZXAgPSBlbGFwc2VkIC8gZHVyYXRpb247XG4gICAgICBpZiAoc3RlcCA+PSAxKSB7XG4gICAgICAgIGFuaW1hdGlvblRpbWVyLnN0b3AoKTtcbiAgICAgICAgcmV0dXJuO1xuICAgICAgfVxuICAgICAgbGV0IG51bSA9IE1hdGgucm91bmQoaW50ZXJwb2xhdG9yKGQzLmVhc2VRdWFkSW5PdXQoc3RlcCkpKTtcbiAgICAgIGVsZW1lbnQudGV4dChudW0pO1xuICAgIH1cblxuICAgIGFuaW1hdGlvblRpbWVyID0gZDMudGltZXIoYW5pbWF0aW9uRnVuYyk7XG59XG5cblxuXG5mdW5jdGlvbiBHcmlkSGVscGVyKHJhZGl1cywgc3BhY2luZywgbnVtRG90cywgbnVtQ29scykge1xuXG5cbiAgICBsZXQgX2NvbFNjYWxlID0gZDMuc2NhbGVMaW5lYXIoKVxuICAgICAgICAuZG9tYWluKFs4MCwgOTEsIDEwOSwgMTI3XSlcbiAgICAgICAgLnJhbmdlKFs1LCA2LCA3LCA4XSlcbiAgICAgICAgLmNsYW1wKHRydWUpO1xuXG4gICAgZnVuY3Rpb24gY29sU2NhbGUobnVtRG90cykge1xuICAgICAgICByZXR1cm4gTWF0aC5mbG9vcihfY29sU2NhbGUobnVtRG90cykpO1xuICAgIH1cblxuICAgIGxldCBjb2xzID0gbnVtQ29scyB8fCBjb2xTY2FsZShudW1Eb3RzKTtcbiAgICBsZXQgbnVtUm93cyA9IE1hdGguY2VpbChudW1Eb3RzIC8gY29scyk7XG4gICAgbGV0IG9mZnNldCA9IG51bVJvd3MgKiBjb2xzIC0gbnVtRG90cztcblxuICAgIGZ1bmN0aW9uIGdyaWRQb3NpdGlvbihpZHgpIHtcbiAgICAgICAgaWR4ICs9IG9mZnNldDtcbiAgICAgICAgbGV0IHJvdyA9IE1hdGguZmxvb3IoaWR4IC8gY29scyk7XG4gICAgICAgIGxldCBjb2wgPSBpZHggLSAocm93ICogY29scyk7XG5cbiAgICAgICAgcmV0dXJuIHtcbiAgICAgICAgICAgIHg6IGNvbCAqIHNwYWNpbmcsXG4gICAgICAgICAgICB5OiByb3cgKiBzcGFjaW5nXG4gICAgICAgIH1cbiAgICB9XG5cbiAgICBsZXQgd2lkdGggPSBjb2xzICogc3BhY2luZztcbiAgICBsZXQgaGVpZ2h0ID0gbnVtUm93cyAqIHNwYWNpbmc7XG5cbiAgICByZXR1cm4ge1xuICAgICAgICBncmlkUG9zaXRpb246IGdyaWRQb3NpdGlvbixcbiAgICAgICAgaGVpZ2h0OiBoZWlnaHQsXG4gICAgICAgIHdpZHRoOiB3aWR0aFxuICAgIH1cbn1cblxuXG5mdW5jdGlvbiByYW5kb21CaXJkUG9zKHNjYWxlKSB7XG4gICAgcmV0dXJuIHtcbiAgICAgICAgeDogKC0xMDAgKyBNYXRoLnJhbmRvbSgpICogMjAwICsgMjApICogc2NhbGUsXG4gICAgICAgIHk6IC0zMDAgKiBzY2FsZVxuICAgIH1cbn1cblxubGV0IGV4dGlycGF0ZWRHYXAgPSAxMDtcblxuZnVuY3Rpb24gZ2VuZXJhdGVQb2ludHMoZGF0YSwgZ3JpZEhlbHBlciwgc2NhbGUpIHtcbiAgICBjb25zdCB7IG51bUNvbG9uaXplZCwgbnVtQ3VycmVudCwgbnVtRXh0aXJwYXRlZCB9ID0gZGF0YTtcbiAgICBsZXQgbnVtUmVtYWluaW5nID0gbnVtQ3VycmVudCAtIG51bUV4dGlycGF0ZWQ7XG5cbiAgICBsZXQgY29sb3JzID0ge1xuICAgICAgICBjb2xvbml6ZWQ6ICcjMThhMWFkJyxcbiAgICAgICAgY3VycmVudDogJyM5MGQyZDgnLFxuICAgICAgICBleHRpcnBhdGVkOiAnI2U4YzU3OCdcbiAgICB9XG5cbiAgICBsZXQgY2MgPSBkMy5yYW5nZShudW1Db2xvbml6ZWQpLm1hcChpID0+IHtcbiAgICAgICAgcmV0dXJuIHtcbiAgICAgICAgICAgIGluaXRQb3M6IHJhbmRvbUJpcmRQb3Moc2NhbGUpLFxuICAgICAgICAgICAgZmluYWxQb3M6IGdyaWRIZWxwZXIuZ3JpZFBvc2l0aW9uKGkpLFxuICAgICAgICAgICAgbGFiZWw6ICdDJyxcbiAgICAgICAgICAgIGluaXRGaWxsT3BhY2l0eTogMCxcbiAgICAgICAgICAgIGluaXRGaWxsOiBjb2xvcnMuY29sb25pemVkLFxuICAgICAgICAgICAgZmluYWxGaWxsT3BhY2l0eTogMSxcbiAgICAgICAgICAgIGZpbmFsRmlsbDogY29sb3JzLmNvbG9uaXplZFxuICAgICAgICB9XG4gICAgfSk7XG5cbiAgICBsZXQgZGQgPSBkMy5yYW5nZShudW1SZW1haW5pbmcpLm1hcChpID0+IHtcbiAgICAgICAgcmV0dXJuIHtcbiAgICAgICAgICAgIGluaXRQb3M6IGdyaWRIZWxwZXIuZ3JpZFBvc2l0aW9uKGkgKyBudW1Db2xvbml6ZWQpLFxuICAgICAgICAgICAgZmluYWxQb3M6IGdyaWRIZWxwZXIuZ3JpZFBvc2l0aW9uKGkgKyBudW1Db2xvbml6ZWQpLFxuICAgICAgICAgICAgbGFiZWw6ICdSJyxcbiAgICAgICAgICAgIGluaXRGaWxsT3BhY2l0eTogMSxcbiAgICAgICAgICAgIGluaXRGaWxsOiBjb2xvcnMuY3VycmVudCxcbiAgICAgICAgICAgIGZpbmFsRmlsbE9wYWNpdHk6IDEsXG4gICAgICAgICAgICBmaW5hbEZpbGw6IGNvbG9ycy5jdXJyZW50XG4gICAgICAgIH1cbiAgICB9KTtcblxuICAgIGxldCBlZSA9IGQzLnJhbmdlKG51bUV4dGlycGF0ZWQpLm1hcChpID0+IHtcbiAgICAgICAgbGV0IGZpbmFsUG9zID0gZ3JpZEhlbHBlci5ncmlkUG9zaXRpb24oaSArIG51bUNvbG9uaXplZCArIG51bVJlbWFpbmluZyk7XG4gICAgICAgIGZpbmFsUG9zLnkgKz0gZXh0aXJwYXRlZEdhcCAqIHNjYWxlO1xuXG4gICAgICAgIHJldHVybiB7XG4gICAgICAgICAgICBpbml0UG9zOiBncmlkSGVscGVyLmdyaWRQb3NpdGlvbihpICsgbnVtQ29sb25pemVkICsgbnVtUmVtYWluaW5nKSxcbiAgICAgICAgICAgIGZpbmFsUG9zOiBmaW5hbFBvcyxcbiAgICAgICAgICAgIGxhYmVsOiAnRScsXG4gICAgICAgICAgICBpbml0RmlsbE9wYWNpdHk6IDEsXG4gICAgICAgICAgICBpbml0RmlsbDogY29sb3JzLmN1cnJlbnQsXG4gICAgICAgICAgICBmaW5hbEZpbGxPcGFjaXR5OiAxLFxuICAgICAgICAgICAgZmluYWxGaWxsOiBjb2xvcnMuZXh0aXJwYXRlZFxuICAgICAgICB9XG4gICAgfSlcblxuICAgIHJldHVybiBjYy5jb25jYXQoZGQpLmNvbmNhdChlZSk7XG5cbn1cblxuZnVuY3Rpb24gX0JpcmREb3RzKHBhcmFtcykge1xuICAgIC8vIGF0dGFjaGVzIGFuIHN2ZyB0byB0aGUgZWxlbWVudFxuICAgIGNvbnN0IHsgZWxlbWVudCwgbnVtQ29sb25pemVkLCBudW1DdXJyZW50LCBudW1FeHRpcnBhdGVkLFxuICAgICAgICBjb2xvbml6ZWRDb3VudGVyLCBleHRpcnBhdGVkQ291bnRlciwgb25Mb2FkLCBzY2FsZSwgbnVtQ29scywgcmVuZGVyQWxsLCB0b3BBbGlnbn0gPSBwYXJhbXM7XG5cbiAgICBsZXQgX3NjYWxlID0gc2NhbGUgfHwgMTtcbiAgICBsZXQgcmFkaXVzID0gMyAqIF9zY2FsZTtcbiAgICBsZXQgc3BhY2luZyA9IDYgKiBfc2NhbGU7XG5cbiAgICBsZXQgZ3JpZEhlbHBlciA9IG5ldyBHcmlkSGVscGVyKFxuICAgICAgICByYWRpdXMsIHNwYWNpbmcsIG51bUN1cnJlbnQgKyBudW1Db2xvbml6ZWQsIG51bUNvbHMpO1xuXG4gICAgbGV0IGRhdGEgPSBnZW5lcmF0ZVBvaW50cyhwYXJhbXMsIGdyaWRIZWxwZXIsIF9zY2FsZSk7XG5cbiAgICBsZXQgc3ZnV2lkdGggPSA3MDA7XG4gICAgbGV0IHN2Z0hlaWdodCA9IDcwMDtcblxuICAgIGxldCBkaXZDb250YWluZXIgPSBkMy5zZWxlY3QoZWxlbWVudClcbiAgICAgICAgLmFwcGVuZCgnZGl2JylcbiAgICAgICAgLmNsYXNzZWQoJ2JpcmQtZG90LWJhc2UtY29udGFpbmVyJywgdHJ1ZSk7XG5cbiAgICBsZXQgc3ZnQ29udGFpbmVyID0gZGl2Q29udGFpbmVyLmFwcGVuZCgnc3ZnJylcbiAgICAgICAgICAgIC5hdHRyKCd3aWR0aCcsIHN2Z1dpZHRoKVxuICAgICAgICAgICAgLmF0dHIoJ2hlaWdodCcsIHN2Z0hlaWdodCk7XG5cbiAgICBsZXQgc3ZnID0gc3ZnQ29udGFpbmVyLmFwcGVuZCgnZycpO1xuXG4gICAgZnVuY3Rpb24gYWxpZ25Eb3RzKCkge1xuICAgICAgICBsZXQgW2RvdEJveFdpZHRoLCBkb3RCb3hIZWlnaHRdID0gW2dyaWRIZWxwZXIud2lkdGgsIGdyaWRIZWxwZXIuaGVpZ2h0XTtcblxuICAgICAgICBkaXZDb250YWluZXIuc3R5bGUoJ3dpZHRoJywgZG90Qm94V2lkdGggKyAncHgnKTtcbiAgICAgICAgZGl2Q29udGFpbmVyLnN0eWxlKCdoZWlnaHQnLCBkb3RCb3hIZWlnaHQgKyAoZXh0aXJwYXRlZEdhcCAqIF9zY2FsZSkgKyAncHgnKTtcblxuICAgICAgICBsZXQgZGl2V2lkdGggPSBkaXZDb250YWluZXIubm9kZSgpLm9mZnNldFdpZHRoO1xuICAgICAgICBsZXQgZGl2SGVpZ2h0ID0gZGl2Q29udGFpbmVyLm5vZGUoKS5vZmZzZXRIZWlnaHQ7XG5cbiAgICAgICAgbGV0IG9mZnNldFkgPSAoKHRvcEFsaWduKSA/IDAgOiAoZGl2SGVpZ2h0IC0gZG90Qm94SGVpZ2h0KSAvIDIpICsgcmFkaXVzO1xuICAgICAgICBsZXQgb2Zmc2V0WCA9IChkaXZXaWR0aCAtIGRvdEJveFdpZHRoKSAvIDIgKyByYWRpdXM7XG5cbiAgICAgICAgLy8gbGV0IHN2Z09mZnNldFkgPSBNYXRoLmFicyhwYXJzZUludChzdmdDb250YWluZXIuc3R5bGUoJ3RvcCcpKSk7XG4gICAgICAgIC8vIGxldCBzdmdPZmZzZXRYID0gTWF0aC5hYnMocGFyc2VJbnQoc3ZnQ29udGFpbmVyLnN0eWxlKCdsZWZ0JykpKTtcbiAgICAgICAgbGV0IHN2Z09mZnNldFkgPSBzdmdIZWlnaHQgLyAyIC0gZGl2SGVpZ2h0IC8gMjtcbiAgICAgICAgbGV0IHN2Z09mZnNldFggPSBzdmdXaWR0aCAvIDIgLSBkaXZXaWR0aCAvIDI7XG4gICAgICAgIHN2Z0NvbnRhaW5lci5zdHlsZSgndG9wJywgLXN2Z09mZnNldFkgKyAncHgnKVxuICAgICAgICBzdmdDb250YWluZXIuc3R5bGUoJ2xlZnQnLCAtc3ZnT2Zmc2V0WCArICdweCcpXG5cbiAgICAgICAgbGV0IHRyYW5zbGF0ZVggPSBvZmZzZXRYICsgc3ZnT2Zmc2V0WDtcbiAgICAgICAgbGV0IHRyYW5zbGF0ZVkgPSBvZmZzZXRZICsgc3ZnT2Zmc2V0WTtcblxuICAgICAgICBzdmcuYXR0cigndHJhbnNmb3JtJywgYHRyYW5zbGF0ZSgke3RyYW5zbGF0ZVh9LCAke3RyYW5zbGF0ZVl9KWApO1xuICAgIH1cblxuICAgIGFsaWduRG90cygpO1xuXG4gICAgbGV0IGNvbG9uaXplZEluVmlldyA9IGZhbHNlO1xuICAgIGxldCBleHRpcnBhdGVkSW5WaWV3ID0gZmFsc2U7XG4gICAgbGV0IGRpc2FibGVkT3BhY2l0eSA9IDAuMjtcblxuICAgIGxldCBkb3RzID0gc3ZnLnNlbGVjdEFsbCgnLmRvdCcpLmRhdGEoZGF0YSk7XG5cbiAgICBpZiAocmVuZGVyQWxsKSB7XG4gICAgICAgIGRvdHMuZW50ZXIoKVxuICAgICAgICAgICAgLmFwcGVuZCgnY2lyY2xlJylcbiAgICAgICAgICAgIC5hdHRyKCdjbGFzcycsICdkb3QnKVxuICAgICAgICAgICAgLmNsYXNzZWQoJ1InLGQgPT4gZC5sYWJlbCA9PSAnUicpXG4gICAgICAgICAgICAuY2xhc3NlZCgnRScsIGQgPT4gZC5sYWJlbCA9PSAnRScpXG4gICAgICAgICAgICAuY2xhc3NlZCgnQycsIGQgPT4gZC5sYWJlbCA9PSAnQycpXG4gICAgICAgICAgICAuYXR0cignY3gnLCBkID0+IGQuZmluYWxQb3MueClcbiAgICAgICAgICAgIC5hdHRyKCdjeScsIGQgPT4gZC5maW5hbFBvcy55KVxuICAgICAgICAgICAgLmF0dHIoJ3InLCByYWRpdXMpXG4gICAgICAgICAgICAuYXR0cignZmlsbC1vcGFjaXR5JywgZCA9PiBkLmZpbmFsRmlsbE9wYWNpdHkpXG4gICAgICAgICAgICAuYXR0cignZmlsbCcsIGQgPT4gZC5maW5hbEZpbGwpO1xuICAgIH0gZWxzZSB7XG4gICAgICAgIGRvdHMuZW50ZXIoKVxuICAgICAgICAgICAgLmFwcGVuZCgnY2lyY2xlJylcbiAgICAgICAgICAgIC5hdHRyKCdjbGFzcycsICdkb3QnKVxuICAgICAgICAgICAgLmNsYXNzZWQoJ1InLGQgPT4gZC5sYWJlbCA9PSAnUicpXG4gICAgICAgICAgICAuY2xhc3NlZCgnRScsIGQgPT4gZC5sYWJlbCA9PSAnRScpXG4gICAgICAgICAgICAuY2xhc3NlZCgnQycsIGQgPT4gZC5sYWJlbCA9PSAnQycpXG4gICAgICAgICAgICAuYXR0cignY3gnLCBkID0+IGQuaW5pdFBvcy54KVxuICAgICAgICAgICAgLmF0dHIoJ2N5JywgZCA9PiBkLmluaXRQb3MueSlcbiAgICAgICAgICAgIC5hdHRyKCdyJywgcmFkaXVzKVxuICAgICAgICAgICAgLmF0dHIoJ2ZpbGwtb3BhY2l0eScsIGQgPT4gZC5pbml0RmlsbE9wYWNpdHkpXG4gICAgICAgICAgICAuYXR0cignZmlsbCcsIGQgPT4gZC5pbml0RmlsbCk7XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gZW50ZXJDb2xvbml6ZWQob25GaW5pc2hlZCkge1xuICAgICAgICBsZXQgbiA9IG51bUNvbG9uaXplZDtcbiAgICAgICAgc3ZnLnNlbGVjdEFsbCgnLmRvdC5DJylcbiAgICAgICAgICAgIC5jbGFzc2VkKCduZXctdmlzaWJsZScsIHRydWUpXG4gICAgICAgICAgICAudHJhbnNpdGlvbigpXG4gICAgICAgICAgICAuZWFzZShkMy5lYXNlUXVhZEluT3V0KVxuICAgICAgICAgICAgLmR1cmF0aW9uKChkLCBpKSA9PiBNYXRoLnJhbmRvbSgpICogMzAwICsgOTUwKVxuICAgICAgICAgICAgLmRlbGF5KChkLCBpKSA9PiAobnVtQ29sb25pemVkIC0gaSkgKiAyMClcbiAgICAgICAgICAgIC5hdHRyKCdjeCcsIGQgPT4gZC5maW5hbFBvcy54KVxuICAgICAgICAgICAgLmF0dHIoJ2N5JywgZCA9PiBkLmZpbmFsUG9zLnkpXG4gICAgICAgICAgICAuYXR0cignZmlsbC1vcGFjaXR5JywgZCA9PiBkLmZpbmFsRmlsbE9wYWNpdHkpXG4gICAgICAgICAgICAuYXR0cignZmlsbCcsIGQgPT4gZC5maW5hbEZpbGwpXG4gICAgICAgICAgICAub24oJ2VuZCcsIChkLCBpKSA9PiB7XG4gICAgICAgICAgICAgICAgbi0tO1xuICAgICAgICAgICAgICAgIGlmIChuID09IDApIHtcbiAgICAgICAgICAgICAgICAgICAgaWYgKG9uRmluaXNoZWQpIHtcbiAgICAgICAgICAgICAgICAgICAgICAgIG9uRmluaXNoZWQoKTtcbiAgICAgICAgICAgICAgICAgICAgfVxuICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgIH0pO1xuICAgICAgICBjb2xvbml6ZWRJblZpZXcgPSB0cnVlO1xuICAgIH1cblxuICAgIGZ1bmN0aW9uIGV4aXRDb2xvbml6ZWQob25GaW5pc2hlZCkge1xuICAgICAgICBsZXQgbiA9IG51bUNvbG9uaXplZDtcbiAgICAgICAgc3ZnLnNlbGVjdEFsbCgnLmRvdC5DJylcbiAgICAgICAgICAgIC5jbGFzc2VkKCduZXctdmlzaWJsZScsIGZhbHNlKVxuICAgICAgICAgICAgLnRyYW5zaXRpb24oKVxuICAgICAgICAgICAgLmVhc2UoZDMuZWFzZVF1YWRJbk91dClcbiAgICAgICAgICAgIC5kdXJhdGlvbigoZCwgaSkgPT4gTWF0aC5yYW5kb20oKSAqIDMwMCArIDk1MClcbiAgICAgICAgICAgIC5kZWxheSgoZCwgaSkgPT4gaSAqIDIwKVxuICAgICAgICAgICAgLmF0dHIoJ2N4JywgZCA9PiBkLmluaXRQb3MueClcbiAgICAgICAgICAgIC5hdHRyKCdjeScsIGQgPT4gZC5pbml0UG9zLnkpXG4gICAgICAgICAgICAuYXR0cignZmlsbC1vcGFjaXR5JywgZCA9PiBkLmluaXRGaWxsT3BhY2l0eSlcbiAgICAgICAgICAgIC5hdHRyKCdmaWxsJywgZCA9PiBkLmluaXRGaWxsKVxuICAgICAgICAgICAgLm9uKCdlbmQnLCAoZCwgaSkgPT4ge1xuICAgICAgICAgICAgICAgIG4tLTtcbiAgICAgICAgICAgICAgICBpZiAobiA9PSAwKSB7XG4gICAgICAgICAgICAgICAgICAgIGlmIChvbkZpbmlzaGVkKSB7XG4gICAgICAgICAgICAgICAgICAgICAgICBvbkZpbmlzaGVkKCk7XG4gICAgICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgICAgICB9XG4gICAgICAgICAgICB9KTtcbiAgICAgICAgY29sb25pemVkSW5WaWV3ID0gZmFsc2U7XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gZW50ZXJFeHRpcnBhdGVkKG9uRmluaXNoZWQpIHtcbiAgICAgICAgbGV0IG4gPSBudW1FeHRpcnBhdGVkO1xuICAgICAgICBzdmcuc2VsZWN0QWxsKCcuZG90LkUnKVxuICAgICAgICAgICAgLmNsYXNzZWQoJ2V4dGlycGF0ZWQtdmlzaWJsZScsIHRydWUpXG4gICAgICAgICAgICAudHJhbnNpdGlvbigpXG4gICAgICAgICAgICAuZHVyYXRpb24oKGQsIGkpID0+IE1hdGgucmFuZG9tKCkgKiAyMDAgKyAyNTApXG4gICAgICAgICAgICAuZGVsYXkoKGQsIGkpID0+IChudW1FeHRpcnBhdGVkIC0gaSkgKiAyMClcbiAgICAgICAgICAgIC5hdHRyKCdjeCcsIGQgPT4gZC5maW5hbFBvcy54KVxuICAgICAgICAgICAgLmF0dHIoJ2N5JywgZCA9PiBkLmZpbmFsUG9zLnkpXG4gICAgICAgICAgICAuYXR0cignZmlsbCcsIGQgPT4gZC5maW5hbEZpbGwpXG4gICAgICAgICAgICAub24oJ2VuZCcsIChkLCBpKSA9PiB7XG4gICAgICAgICAgICAgICAgbi0tO1xuICAgICAgICAgICAgICAgIGlmIChuID09IDApIHtcbiAgICAgICAgICAgICAgICAgICAgaWYgKG9uRmluaXNoZWQpIHtcbiAgICAgICAgICAgICAgICAgICAgICAgIG9uRmluaXNoZWQoKTtcbiAgICAgICAgICAgICAgICAgICAgfVxuICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgIH0pO1xuICAgICAgICBleHRpcnBhdGVkSW5WaWV3ID0gdHJ1ZTtcbiAgICB9XG5cbiAgICBmdW5jdGlvbiBleGl0RXh0aXJwYXRlZChvbkZpbmlzaGVkKSB7XG4gICAgICAgIGxldCBuID0gbnVtRXh0aXJwYXRlZDtcbiAgICAgICAgc3ZnLnNlbGVjdEFsbCgnLmRvdC5FJylcbiAgICAgICAgICAgIC50cmFuc2l0aW9uKClcbiAgICAgICAgICAgIC5kdXJhdGlvbigoZCwgaSkgPT4gTWF0aC5yYW5kb20oKSAqIDIwMCArIDI1MClcbiAgICAgICAgICAgIC5kZWxheSgoZCwgaSkgPT4gaSAqIDIwKVxuICAgICAgICAgICAgLmF0dHIoJ2N4JywgZCA9PiBkLmluaXRQb3MueClcbiAgICAgICAgICAgIC5hdHRyKCdjeScsIGQgPT4gZC5pbml0UG9zLnkpXG4gICAgICAgICAgICAuYXR0cignZmlsbCcsIGQgPT4gZC5pbml0RmlsbClcbiAgICAgICAgICAgIC5vbignZW5kJywgKGQsIGkpID0+IHtcbiAgICAgICAgICAgICAgICBuLS07XG4gICAgICAgICAgICAgICAgaWYgKG4gPT0gMCkge1xuICAgICAgICAgICAgICAgICAgICBpZiAob25GaW5pc2hlZCkge1xuICAgICAgICAgICAgICAgICAgICAgICAgb25GaW5pc2hlZCgpO1xuICAgICAgICAgICAgICAgICAgICB9XG4gICAgICAgICAgICAgICAgfVxuICAgICAgICAgICAgfSk7XG4gICAgICAgIGV4dGlycGF0ZWRJblZpZXcgPSBmYWxzZTtcbiAgICB9XG5cbiAgICBmdW5jdGlvbiBqaWdnbGUoc2VsZWN0aW9uKSB7XG4gICAgICAgIHNlbGVjdGlvblxuICAgICAgICAgICAgLnRyYW5zaXRpb24oKVxuICAgICAgICAgICAgLmR1cmF0aW9uKChkLCBpKSA9PiBNYXRoLnJhbmRvbSgpICogMjAwICsgMTAwKVxuICAgICAgICAgICAgLmF0dHIoJ2N5JywgZCA9PiBkLmZpbmFsUG9zLnkgLSAyKVxuICAgICAgICAgICAgLnRyYW5zaXRpb24oKVxuICAgICAgICAgICAgLmR1cmF0aW9uKDIwMClcbiAgICAgICAgICAgIC5hdHRyKCdjeScsIGQgPT4gZC5maW5hbFBvcy55KTtcbiAgICB9XG5cbiAgICBmdW5jdGlvbiBoaWdobGlnaHRFeHRpcnBhdGVkKCkge1xuICAgICAgICBzdmcuc2VsZWN0QWxsKCcuZG90LkUnKS5jYWxsKGppZ2dsZSk7XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gaGlnaGxpZ2h0Q29sb25pemF0aW9ucygpIHtcbiAgICAgICAgc3ZnLnNlbGVjdEFsbCgnLmRvdC5DJykuY2FsbChqaWdnbGUpO1xuICAgIH1cblxuICAgIGZ1bmN0aW9uIGFuaW1hdGVJbigpIHtcbiAgICAgICAgYW5pbWF0ZUNvdW50KGQzLnNlbGVjdChjb2xvbml6ZWRDb3VudGVyKSwgMCwgbnVtQ29sb25pemVkLCAxMjAwKTtcbiAgICAgICAgZW50ZXJDb2xvbml6ZWQoKCkgPT4ge1xuICAgICAgICAgICAgYW5pbWF0ZUNvdW50KGQzLnNlbGVjdChleHRpcnBhdGVkQ291bnRlciksIDAsIG51bUV4dGlycGF0ZWQsIDEyMDApO1xuICAgICAgICAgICAgZW50ZXJFeHRpcnBhdGVkKCgpID0+IHtcbiAgICAgICAgICAgICAgICBpZiAob25Mb2FkKSB7XG4gICAgICAgICAgICAgICAgICAgIHNldFRpbWVvdXQoKCkgPT4gb25Mb2FkKCksIDEwMDApO1xuICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgIH0pO1xuICAgICAgICB9KTtcblxuICAgIH1cbiAgICBmdW5jdGlvbiBzZXRDdXJyZW50KCkge1xuICAgICAgICBpZiAoY29sb25pemVkSW5WaWV3IHx8IGV4dGlycGF0ZWRJblZpZXcpIHtcbiAgICAgICAgICAgIC8vIGNsZWFySGlnaGxpZ2h0KCk7XG4gICAgICAgICAgICBleGl0Q29sb25pemVkKCk7XG4gICAgICAgICAgICBleGl0RXh0aXJwYXRlZCgpO1xuICAgICAgICB9XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gc2V0Q29sb25pemVkKCkge1xuICAgICAgICBpZiAoIWNvbG9uaXplZEluVmlldykge1xuICAgICAgICAgICAgZW50ZXJDb2xvbml6ZWQoKTtcbiAgICAgICAgfSBlbHNlIHtcbiAgICAgICAgICAgIGhpZ2hsaWdodENvbG9uaXphdGlvbnMoKVxuICAgICAgICB9XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gc2V0RXh0aXJwYXRlZCgpIHtcbiAgICAgICAgaWYgKCFleHRpcnBhdGVkSW5WaWV3KSB7XG4gICAgICAgICAgICBlbnRlckV4dGlycGF0ZWQoKTtcbiAgICAgICAgfSBlbHNlIHtcbiAgICAgICAgICAgIGhpZ2hsaWdodEV4dGlycGF0ZWQoKTtcbiAgICAgICAgfVxuICAgIH1cblxuICAgIHJldHVybiB7XG4gICAgICAgIGFuaW1hdGVJbjogYW5pbWF0ZUluLFxuICAgICAgICBzdmc6IHN2Z0NvbnRhaW5lci5ub2RlKCksXG4gICAgICAgIG51bUNvbG9uaXplZDogbnVtQ29sb25pemVkLFxuICAgICAgICBudW1DdXJyZW50OiBudW1DdXJyZW50LFxuICAgICAgICBudW1FeHRpcnBhdGVkOiBudW1FeHRpcnBhdGVkLFxuICAgICAgICBlbnRlckV4dGlycGF0ZWQ6IGVudGVyRXh0aXJwYXRlZCxcbiAgICAgICAgZW50ZXJDb2xvbml6ZWQ6IGVudGVyQ29sb25pemVkLFxuICAgICAgICBzZXRFeHRpcnBhdGVkOiBzZXRFeHRpcnBhdGVkLFxuICAgICAgICBzZXRDb2xvbml6ZWQ6IHNldENvbG9uaXplZCxcbiAgICAgICAgc2V0Q3VycmVudDogc2V0Q3VycmVudCxcbiAgICAgICAgZGF0YTogZGF0YVxuICAgIH1cbn1cblxuZnVuY3Rpb24gQmlyZERvdHMocGFyYW1zKSB7XG4gICAgY29uc3Qge1xuICAgICAgICBlbGVtZW50LCBkYXRhVXJsLCBzZWFzb24sXG4gICAgICAgIHBhcmssIGN1cnJlbnRDb3VudGVyLCBjb2xvbml6ZWRDb3VudGVyLFxuICAgICAgICBleHRpcnBhdGVkQ291bnRlciwgb25Mb2FkLCBpbml0U3RhdHN9ID0gcGFyYW1zO1xuXG4gICAgbGV0IF9zZWFzb24gPSBzZWFzb247XG4gICAgbGV0IHN1bW1lckRvdHMsIHdpbnRlckRvdHM7XG4gICAgbGV0IHJlYWR5ID0gZmFsc2U7XG4gICAgbGV0IG5vZGUgPSBkMy5zZWxlY3QoZWxlbWVudCkuYXBwZW5kKCdkaXYnKVxuICAgICAgICAgICAgICAgIC5jbGFzc2VkKCdiaXJkLWRvdC1jb250YWluZXInLCB0cnVlKTtcblxuICAgIGQzLmNzdihkYXRhVXJsLCAoZXJyb3IsIGRhdGEpID0+IHtcbiAgICAgICAgaWYgKGVycm9yKSB7XG4gICAgICAgICAgICBjb25zb2xlLmxvZygnZXJyb3InLCBlcnJvcik7XG4gICAgICAgICAgICByZXR1cm47XG4gICAgICAgIH1cblxuICAgICAgICBsZXQgcGFya1JvdyA9IGRhdGEuZmluZChkID0+IGQudW5pdF9uYW1lID09IHBhcmspO1xuXG4gICAgICAgIGxldCBzdW1tZXJQYXJhbXMgPSB7XG4gICAgICAgICAgICBlbGVtZW50OiBub2RlLm5vZGUoKSxcbiAgICAgICAgICAgIG51bUN1cnJlbnQ6ICtwYXJrUm93LmN1cnJlbnRfc3BlY2llc19zdW1tZXIsXG4gICAgICAgICAgICBudW1Db2xvbml6ZWQ6ICtwYXJrUm93Lm5vX2NvbG9uaXphdGlvbnNfc3VtbWVyLFxuICAgICAgICAgICAgbnVtRXh0aXJwYXRlZDogK3BhcmtSb3cubm9fZXh0aXJwYXRpb25zX3N1bW1lclxuICAgICAgICB9O1xuXG4gICAgICAgIGxldCB3aW50ZXJQYXJhbXMgPSB7XG4gICAgICAgICAgICBlbGVtZW50OiBub2RlLm5vZGUoKSxcbiAgICAgICAgICAgIG51bUN1cnJlbnQ6ICtwYXJrUm93LmN1cnJlbnRfc3BlY2llc193aW50ZXIsXG4gICAgICAgICAgICBudW1Db2xvbml6ZWQ6ICtwYXJrUm93Lm5vX2NvbG9uaXphdGlvbnNfd2ludGVyLFxuICAgICAgICAgICAgbnVtRXh0aXJwYXRlZDogK3BhcmtSb3cubm9fZXh0aXJwYXRpb25zX3dpbnRlclxuICAgICAgICB9XG5cbiAgICAgICAgc3VtbWVyRG90cyA9IG5ldyBfQmlyZERvdHMoc3VtbWVyUGFyYW1zKTtcbiAgICAgICAgd2ludGVyRG90cyA9IG5ldyBfQmlyZERvdHMod2ludGVyUGFyYW1zKTtcblxuICAgICAgICBpbml0Q2hhcnQoX3NlYXNvbiwgaW5pdFN0YXRzKTtcbiAgICAgICAgcmVhZHkgPSB0cnVlO1xuICAgICAgICBpZiAob25Mb2FkKSB7XG4gICAgICAgICAgICBvbkxvYWQoKTtcbiAgICAgICAgfVxuICAgIH0pO1xuXG4gICAgZnVuY3Rpb24gaW5pdENoYXJ0KHNlYXNvbiwgaW5pdFN0YXRzKSB7XG4gICAgICAgIGxldCBwbG90O1xuICAgICAgICBpZiAoc2Vhc29uID09PSAnc3VtbWVyJykge1xuICAgICAgICAgICAgZDMuc2VsZWN0KHdpbnRlckRvdHMuc3ZnKS5zdHlsZSgnb3BhY2l0eScsIDApO1xuICAgICAgICAgICAgZDMuc2VsZWN0KHN1bW1lckRvdHMuc3ZnKS5zdHlsZSgnb3BhY2l0eScsIDEpO1xuICAgICAgICAgICAgcGxvdCA9IHN1bW1lckRvdHM7XG4gICAgICAgIH0gZWxzZSB7XG4gICAgICAgICAgICBkMy5zZWxlY3Qod2ludGVyRG90cy5zdmcpLnN0eWxlKCdvcGFjaXR5JywgMSk7XG4gICAgICAgICAgICBkMy5zZWxlY3Qoc3VtbWVyRG90cy5zdmcpLnN0eWxlKCdvcGFjaXR5JywgMCk7XG4gICAgICAgICAgICBwbG90ID0gd2ludGVyRG90cztcbiAgICAgICAgfVxuICAgICAgICBpZiAoaW5pdFN0YXRzKSB7XG4gICAgICAgICAgICBkMy5zZWxlY3QoY29sb25pemVkQ291bnRlcikudGV4dChwbG90Lm51bUNvbG9uaXplZCk7XG4gICAgICAgICAgICBkMy5zZWxlY3QoZXh0aXJwYXRlZENvdW50ZXIpLnRleHQocGxvdC5udW1FeHRpcnBhdGVkKTtcbiAgICAgICAgICAgIGQzLnNlbGVjdChjdXJyZW50Q291bnRlcikudGV4dChwbG90Lm51bUN1cnJlbnQpO1xuICAgICAgICB9XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gX2FuaW1hdGVJbihvbkZpbmlzaGVkKSB7XG4gICAgICAgIC8vIHNob3VsZCBiZSBjYWxsZWQgYWZ0ZXIgcmVhZHkgdG8gYmUgaW5pdGVkXG4gICAgICAgIGxldCBwbG90O1xuICAgICAgICBpZiAoX3NlYXNvbiA9PT0gJ3N1bW1lcicpIHtcbiAgICAgICAgICAgIHBsb3QgPSBzdW1tZXJEb3RzO1xuICAgICAgICB9IGVsc2Uge1xuICAgICAgICAgICAgcGxvdCA9IHdpbnRlckRvdHM7XG4gICAgICAgIH1cblxuICAgICAgICBkMy5zZWxlY3QoY3VycmVudENvdW50ZXIpLnRleHQocGxvdC5udW1DdXJyZW50KTtcbiAgICAgICAgYW5pbWF0ZUNvdW50KGQzLnNlbGVjdChjb2xvbml6ZWRDb3VudGVyKSwgMCwgcGxvdC5udW1Db2xvbml6ZWQsIDEyMDApO1xuICAgICAgICBwbG90LmVudGVyQ29sb25pemVkKCgpID0+IHtcbiAgICAgICAgICAgIGFuaW1hdGVDb3VudChkMy5zZWxlY3QoZXh0aXJwYXRlZENvdW50ZXIpLCAwLCBwbG90Lm51bUV4dGlycGF0ZWQsIDEyMDApO1xuICAgICAgICAgICAgcGxvdC5lbnRlckV4dGlycGF0ZWQoKCkgPT4ge1xuICAgICAgICAgICAgICAgIGlmIChvbkZpbmlzaGVkKSB7XG4gICAgICAgICAgICAgICAgICAgIHNldFRpbWVvdXQoKCkgPT4gb25GaW5pc2hlZCgpLCAxMDAwKTtcbiAgICAgICAgICAgICAgICB9XG4gICAgICAgICAgICB9KTtcbiAgICAgICAgfSk7XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gYW5pbWF0ZUluKG9uRmluaXNoZWQpIHtcbiAgICAgICAgaWYgKHJlYWR5KSB7XG4gICAgICAgICAgICBfYW5pbWF0ZUluKG9uRmluaXNoZWQpO1xuICAgICAgICB9XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gZmFkZU91dChlbCkge1xuICAgICAgICBlbC50cmFuc2l0aW9uKClcbiAgICAgICAgICAgIC5kdXJhdGlvbigyMDApXG4gICAgICAgICAgICAuZWFzZShkMy5lYXNlUXVhZE91dClcbiAgICAgICAgICAgIC5zdHlsZSgnb3BhY2l0eScsIDApO1xuICAgIH1cblxuICAgIGZ1bmN0aW9uIGZhZGVJbihlbCkge1xuICAgICAgICBlbC50cmFuc2l0aW9uKClcbiAgICAgICAgICAgIC5kdXJhdGlvbigyMDApXG4gICAgICAgICAgICAuZGVsYXkoMjAwKVxuICAgICAgICAgICAgLmVhc2UoZDMuZWFzZVF1YWRPdXQpXG4gICAgICAgICAgICAuc3R5bGUoJ29wYWNpdHknLCAxKTtcbiAgICB9XG5cbiAgICBmdW5jdGlvbiBzZXRTZWFzb24oc2Vhc29uKSB7XG4gICAgICAgIGlmIChzZWFzb24gPT09IF9zZWFzb24pIHtcbiAgICAgICAgICAgIHJldHVybjtcbiAgICAgICAgfVxuXG4gICAgICAgIF9zZWFzb24gPSBzZWFzb247XG5cbiAgICAgICAgaWYgKCFyZWFkeSkge1xuICAgICAgICAgICAgcmV0dXJuO1xuICAgICAgICB9XG5cbiAgICAgICAgaWYgKHNlYXNvbiA9PT0gJ3N1bW1lcicpIHtcbiAgICAgICAgICAgIGQzLnNlbGVjdCh3aW50ZXJEb3RzLnN2ZykuY2FsbChmYWRlT3V0KTtcbiAgICAgICAgICAgIGQzLnNlbGVjdChzdW1tZXJEb3RzLnN2ZykuY2FsbChmYWRlSW4pO1xuXG4gICAgICAgICAgICBkMy5zZWxlY3QoY29sb25pemVkQ291bnRlcikudGV4dChzdW1tZXJEb3RzLm51bUNvbG9uaXplZCk7XG4gICAgICAgICAgICBkMy5zZWxlY3QoZXh0aXJwYXRlZENvdW50ZXIpLnRleHQoc3VtbWVyRG90cy5udW1FeHRpcnBhdGVkKTtcbiAgICAgICAgICAgIGQzLnNlbGVjdChjdXJyZW50Q291bnRlcikudGV4dChzdW1tZXJEb3RzLm51bUN1cnJlbnQpO1xuICAgICAgICB9IGVsc2Uge1xuICAgICAgICAgICAgZDMuc2VsZWN0KHN1bW1lckRvdHMuc3ZnKS5jYWxsKGZhZGVPdXQpO1xuICAgICAgICAgICAgZDMuc2VsZWN0KHdpbnRlckRvdHMuc3ZnKS5jYWxsKGZhZGVJbik7XG5cbiAgICAgICAgICAgIGQzLnNlbGVjdChjb2xvbml6ZWRDb3VudGVyKS50ZXh0KHdpbnRlckRvdHMubnVtQ29sb25pemVkKTtcbiAgICAgICAgICAgIGQzLnNlbGVjdChleHRpcnBhdGVkQ291bnRlcikudGV4dCh3aW50ZXJEb3RzLm51bUV4dGlycGF0ZWQpO1xuICAgICAgICAgICAgZDMuc2VsZWN0KGN1cnJlbnRDb3VudGVyKS50ZXh0KHdpbnRlckRvdHMubnVtQ3VycmVudCk7XG4gICAgICAgIH1cbiAgICB9XG5cbiAgICBmdW5jdGlvbiBzZXRFeHRpcnBhdGVkKCkge1xuICAgICAgICBpZiAoIXJlYWR5KSB7XG4gICAgICAgICAgICByZXR1cm47XG4gICAgICAgIH1cblxuICAgICAgICBzdW1tZXJEb3RzLnNldEV4dGlycGF0ZWQoKTtcbiAgICAgICAgd2ludGVyRG90cy5zZXRFeHRpcnBhdGVkKCk7XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gc2V0Q3VycmVudCgpIHtcbiAgICAgICAgaWYgKCFyZWFkeSkge1xuICAgICAgICAgICAgcmV0dXJuO1xuICAgICAgICB9XG5cbiAgICAgICAgc3VtbWVyRG90cy5zZXRDdXJyZW50KCk7XG4gICAgICAgIHdpbnRlckRvdHMuc2V0Q3VycmVudCgpO1xuICAgIH1cblxuICAgIGZ1bmN0aW9uIHNldENvbG9uaXplZCgpIHtcbiAgICAgICAgaWYgKCFyZWFkeSkge1xuICAgICAgICAgICAgcmV0dXJuO1xuICAgICAgICB9XG5cbiAgICAgICAgc3VtbWVyRG90cy5zZXRDb2xvbml6ZWQoKTtcbiAgICAgICAgd2ludGVyRG90cy5zZXRDb2xvbml6ZWQoKTtcbiAgICB9XG5cbiAgICByZXR1cm4ge1xuICAgICAgICBhbmltYXRlSW46IGFuaW1hdGVJbixcbiAgICAgICAgc2V0U2Vhc29uOiBzZXRTZWFzb24sXG4gICAgICAgIHNldEV4dGlycGF0ZWQ6IHNldEV4dGlycGF0ZWQsXG4gICAgICAgIHNldENvbG9uaXplZDogc2V0Q29sb25pemVkLFxuICAgICAgICBzZXRDdXJyZW50OiBzZXRDdXJyZW50XG4gICAgfVxufVxuXG5sZXQgQmlyZERvdHNCYXNlID0gX0JpcmREb3RzO1xuZXhwb3J0IHsgQmlyZERvdHMsIEJpcmREb3RzQmFzZSwgYW5pbWF0ZUNvdW50LCBHcmlkSGVscGVyfTtcbiIsImltcG9ydCB7IEJpcmREb3RzQmFzZSwgYW5pbWF0ZUNvdW50fSBmcm9tICcuL2JpcmREb3QuanMnO1xuXG5sZXQgSU1BR0VTID0ge1xuICB3YXJibGVyOiAnaHR0cHM6Ly9jZG4uYXVkdWJvbi5vcmcvY2RuL2ZhcmZ1dHVyZS9RWExSeFNRMGZzRlZnMjFQdHVxTzZtSUl2Szk1UWd4b05fU2pDdnpJTW9BL210aW1lOjE1MjEyMjYxMDYvc2l0ZXMvZGVmYXVsdC9maWxlcy93YXJibGVyMngucG5nJyxcbiAgd29vZHBlY2tlcjogJ2h0dHBzOi8vY2RuLmF1ZHVib24ub3JnL2Nkbi9mYXJmdXR1cmUvdHZnb0p2Zk8wa2RlMllPTmdiRFA5RjBqM2NUN3RDTEs2cTFsczRndlUzWS9tdGltZToxNTIxMjI2MTQwL3NpdGVzL2RlZmF1bHQvZmlsZXMvd29vZHBlY2tlcjJ4LnBuZycsXG4gIGVncmV0OiAnaHR0cHM6Ly9jZG4uYXVkdWJvbi5vcmcvY2RuL2ZhcmZ1dHVyZS9MdG9UZl9ucE9mQzk3dWVYaF8waFRNd2tNMDBkblZxUk1LZ0ZidXExbjAwL210aW1lOjE1MjEyMjYxNzQvc2l0ZXMvZGVmYXVsdC9maWxlcy9lZ3JldDJ4LnBuZycsXG4gIGdyb3NiZWFrOiAnaHR0cHM6Ly9jZG4uYXVkdWJvbi5vcmcvY2RuL2ZhcmZ1dHVyZS85RHhLVWZjdzd5czM1R3lvNnktU1o5eFVkMjBNMGVfMkU1S3lWcm9kTnprL210aW1lOjE1MjEyMjYzNDAvc2l0ZXMvZGVmYXVsdC9maWxlcy9ncm9zYmVhazJ4LnBuZycsXG4gIHJvYmluOiAnaHR0cHM6Ly9jZG4uYXVkdWJvbi5vcmcvY2RuL2ZhcmZ1dHVyZS93YzN4bGJmbE85N0lvdXkydWp6TEdhNng1VHNkdnp4TnY0c1pPSHpmSXlVL210aW1lOjE1MjEyMjYzNzkvc2l0ZXMvZGVmYXVsdC9maWxlcy9yb2JpbjJ4LnBuZydcbn1cblxuXG5mdW5jdGlvbiBCaXJkRG90TGFuZGluZ1BhZ2UocGFyYW1zKSB7XG4gIGNvbnN0IHsgZWxlbWVudCB9ID0gcGFyYW1zO1xuICBsZXQgbm9kZSA9IGQzLnNlbGVjdChlbGVtZW50KS5hcHBlbmQoJ2RpdicpXG4gICAgICAgICAgICAgIC5jbGFzc2VkKCdiaXJkLWRvdC1sYW5kaW5nLXBhZ2UnLCB0cnVlKTtcblxuICBsZXQgcm93ID0gbm9kZS5hcHBlbmQoJ2RpdicpXG4gICAgLmNsYXNzZWQoJ2NvdW50ZXItcm93JywgdHJ1ZSk7XG5cbiAgbGV0IGJpcmREb3RzID0gbmV3IEJpcmREb3RzQmFzZSh7XG4gICAgICBlbGVtZW50OiBub2RlLm5vZGUoKSxcbiAgICAgIHNjYWxlOiAyLjUsXG4gICAgICBudW1DdXJyZW50OiA4MyxcbiAgICAgIG51bUNvbG9uaXplZDogMTMsXG4gICAgICBudW1FeHRpcnBhdGVkOiAyMCxcbiAgICAgIG51bUNvbHM6IDVcbiAgICB9XG4gICk7XG5cbiAgLy8gdGhpcyBpcyBpbiB0aGUgcmVmZXJlbmNlIGZyYW1lIG9mIHRoZSBleGlzdGluZyBkb3RzXG4gIGxldCBzdmcgPSBkMy5zZWxlY3QoYmlyZERvdHMuc3ZnKS5zZWxlY3QoJ2cnKTtcblxuICBsZXQgY3VycmVudENvdW50ZXIgPSByb3cuYXBwZW5kKCdkaXYnKVxuICAgIC5jbGFzc2VkKCdjb3VudGVyJywgdHJ1ZSlcbiAgICAuY2xhc3NlZCgnY3VycmVudC1jb3VudGVyJywgdHJ1ZSlcbiAgICAuaHRtbChgXG4gICAgICA8cD5TcGVjaWVzIGN1cnJlbnRseSBpbiB0aGUgcGFyazwvcD5cbiAgICAgIDxoMj44MzwvaDI+XG4gICAgYClcblxuICBsZXQgY29sb25pemVkQ291bnRlciA9IHJvdy5hcHBlbmQoJ2RpdicpXG4gICAgLmNsYXNzZWQoJ2NvdW50ZXInLCB0cnVlKVxuICAgIC5jbGFzc2VkKCdjb2xvbml6ZWQtY291bnRlcicsIHRydWUpXG4gICAgLnN0eWxlKCdvcGFjaXR5JywgMClcbiAgICAuaHRtbChgXG4gICAgICA8cD5Qb3RlbnRpYWwgY29sb25pemF0aW9uPC9wPlxuICAgICAgPGgyPjA8L2gyPlxuICAgIGApXG5cbiAgbGV0IGV4dGlycGF0ZWRDb3VudGVyID0gcm93LmFwcGVuZCgnZGl2JylcbiAgICAuY2xhc3NlZCgnY291bnRlcicsIHRydWUpXG4gICAgLmNsYXNzZWQoJ2V4dGlycGF0ZWQtY291bnRlcicsIHRydWUpXG4gICAgLnN0eWxlKCdvcGFjaXR5JywgMClcbiAgICAuaHRtbChgXG4gICAgICA8cD5Qb3RlbnRpYWwgZXh0aXJwYXRpb248L3A+XG4gICAgICA8aDI+MDwvaDI+XG4gICAgYClcblxuICBsZXQgY2FsbG91dEcgPSBzdmcuYXBwZW5kKCdnJylcbiAgICAuYXR0cignY2xhc3MnLCAnYmlyZC1jYWxsb3V0cycpO1xuXG4gIGxldCBjYWxsb3V0RGlzdGFuY2UgPSA3MDtcbiAgbGV0IGNhbGxvdXRSYWRpdXMgPSA0NztcblxuICBmdW5jdGlvbiBkcmF3Q2FsbG91dChuLCBpbml0aWFsLCBuYW1lLCBpbWFnZSwgY2xhc3N0eXBlLCBsZWZ0T3JSaWdodCkge1xuICAgIGxldCBwb3MgPSBpbml0aWFsID8gYmlyZERvdHMuZGF0YVtuIC0gMV0uaW5pdFBvcyA6IGJpcmREb3RzLmRhdGFbbiAtIDFdLmZpbmFsUG9zO1xuICAgIGxldCB0YXJnZXQgPSBzdmcuc2VsZWN0KGAuZG90Om50aC1jaGlsZCgke259KWApO1xuXG4gICAgbGV0IHNpZGUgPSAobGVmdE9yUmlnaHQgPT0gJ2xlZnQnKSA/IDE6IC0xO1xuXG4gICAgbGV0IGNhbGxvdXQgPSBjYWxsb3V0Ry5hcHBlbmQoJ2cnKVxuICAgICAgLmNsYXNzZWQoJ2JpcmQtY2FsbG91dCcsIHRydWUpXG4gICAgICAuY2xhc3NlZChjbGFzc3R5cGUsIHRydWUpXG4gICAgICAuYXR0cigndHJhbnNmb3JtJywgYHRyYW5zbGF0ZSgke3Bvcy54IC0gc2lkZSAqIGNhbGxvdXREaXN0YW5jZX0sICR7cG9zLnl9KWApXG4gICAgICAuYXR0cignb3BhY2l0eScsIDApO1xuXG4gICAgY2FsbG91dC5hcHBlbmQoJ2NpcmNsZScpXG4gICAgICAuYXR0cignY3gnLCAwKVxuICAgICAgLmF0dHIoJ2N5JywgMClcbiAgICAgIC5hdHRyKCdyJywgY2FsbG91dFJhZGl1cyk7XG5cbiAgICBjYWxsb3V0LmFwcGVuZCgnY2xpcFBhdGgnKVxuICAgICAgLmF0dHIoJ2lkJywgJ2JpcmQtY2FsbG91dC1jbGlwLXBhdGgnKVxuICAgICAgLmFwcGVuZCgnY2lyY2xlJylcbiAgICAgICAgLmF0dHIoJ2N4JywgMClcbiAgICAgICAgLmF0dHIoJ2N5JywgMClcbiAgICAgICAgLmF0dHIoJ3InLCBjYWxsb3V0UmFkaXVzKTtcblxuICAgIGNhbGxvdXQuYXBwZW5kKCdpbWFnZScpXG4gICAgICAuYXR0cignY2xhc3MnLCAnYmlyZC1jYWxsb3V0LWltYWdlJylcbiAgICAgIC5hdHRyKCd4JywgLTQ3KVxuICAgICAgLmF0dHIoJ3knLCAtNDcpXG4gICAgICAuYXR0cignaGVpZ2h0JywgOTUpXG4gICAgICAuYXR0cignd2lkdGgnLCA5NSlcbiAgICAgIC5hdHRyKCdjbGlwLXBhdGgnLCAoZCwgaSkgPT4gYHVybCgjYmlyZC1jYWxsb3V0LWNsaXAtcGF0aClgKVxuICAgICAgLmF0dHIoJ3hsaW5rOmhyZWYnLCBpbWFnZSk7XG5cbiAgICBjYWxsb3V0LmFwcGVuZCgndGV4dCcpXG4gICAgICAuYXR0cigneCcsIDApXG4gICAgICAuYXR0cigneScsIGNhbGxvdXRSYWRpdXMgKyAxNilcbiAgICAgIC5hdHRyKCd0ZXh0LWFuY2hvcicsICdtaWRkbGUnKVxuICAgICAgLnRleHQobmFtZSk7XG5cbiAgICBjYWxsb3V0LmFwcGVuZCgnbGluZScpXG4gICAgICAuYXR0cigneDEnLCBzaWRlICogY2FsbG91dFJhZGl1cylcbiAgICAgIC5hdHRyKCd5MScsIDApXG4gICAgICAuYXR0cigneDInLCAtIHNpZGUgKiB0YXJnZXQuYXR0cigncicpICsgc2lkZSAqIGNhbGxvdXREaXN0YW5jZSlcbiAgICAgIC5hdHRyKCd5MicsIDApO1xuXG4gICAgcmV0dXJuIGNhbGxvdXQ7XG4gIH1cblxuICBmdW5jdGlvbiBmYWRlSW4oZWxlbWVudCkge1xuICAgIGVsZW1lbnQudHJhbnNpdGlvbigpXG4gICAgICAuZHVyYXRpb24oMTAwMClcbiAgICAgIC5hdHRyKCdvcGFjaXR5JywgMSk7XG4gIH1cblxuICBmdW5jdGlvbiBmYWRlT3V0KGVsZW1lbnQpIHtcbiAgICBlbGVtZW50LnRyYW5zaXRpb24oKVxuICAgICAgLmR1cmF0aW9uKDYwMClcbiAgICAgIC5hdHRyKCdvcGFjaXR5JywgMCk7XG4gIH1cblxuICBkcmF3Q2FsbG91dCgzMiwgdHJ1ZSwgJ0dyZWF0IEVncmV0JywgSU1BR0VTLmVncmV0LCAnY3VycmVudCcsICdsZWZ0JykuY2FsbChmYWRlSW4pO1xuICBkcmF3Q2FsbG91dCg0NiwgdHJ1ZSwgXCJOdXRhbGwncyBXb29kcGVja2VyXCIsIElNQUdFUy53b29kcGVja2VyLCAnY3VycmVudCcsICdyaWdodCcpLmNhbGwoZmFkZUluKTtcbiAgZHJhd0NhbGxvdXQoNzIsIHRydWUsIFwiV2lsc29uJ3MgV2FyYmxlclwiLCBJTUFHRVMud2FyYmxlciwgJ2N1cnJlbnQnLCAnbGVmdCcpLmNhbGwoZmFkZUluKTtcblxuICBsZXQgcm9iaW4gPSBkcmF3Q2FsbG91dCg4NiwgdHJ1ZSwgXCJBbWVyaWNhbiBSb2JpblwiLCBJTUFHRVMucm9iaW4sICdjdXJyZW50JywgJ3JpZ2h0JykuY2FsbChmYWRlSW4pO1xuXG4gIC8vIGRyYXcgdGhlIGdyb3NiZWFrIHdoZXJlIGl0IHdpbGwgYmVcbiAgbGV0IGJpcmRQb3MgPSBiaXJkRG90cy5kYXRhWzZdLmZpbmFsUG9zO1xuICBsZXQgZ3Jvc2JlYWsgPSBkcmF3Q2FsbG91dCg2LCBmYWxzZSwgXCJCbHVlIEdyb3NiZWFrXCIsIElNQUdFUy5ncm9zYmVhaywgJ2NvbG9uaXplZCcsICdyaWdodCcpLmF0dHIoJ29wYWNpdHknLCAwKTtcblxuICBmdW5jdGlvbiBzaG93Q3VycmVudCgpIHtcbiAgICBjdXJyZW50Q291bnRlci50cmFuc2l0aW9uKClcbiAgICAgIC5kZWxheSgyMDApXG4gICAgICAuZHVyYXRpb24oNDAwKVxuICAgICAgLnN0eWxlKCdvcGFjaXR5JywgMSk7XG5cbiAgICBjb2xvbml6ZWRDb3VudGVyLnRyYW5zaXRpb24oKVxuICAgICAgLmR1cmF0aW9uKDMwMClcbiAgICAgIC5zdHlsZSgnb3BhY2l0eScsIDApO1xuXG4gICAgZXh0aXJwYXRlZENvdW50ZXIudHJhbnNpdGlvbigpXG4gICAgICAuZHVyYXRpb24oMzAwKVxuICAgICAgLnN0eWxlKCdvcGFjaXR5JywgMCk7XG5cbiAgICBiaXJkRG90cy5zZXRDdXJyZW50KCk7XG4gICAgZ3Jvc2JlYWsuY2FsbChmYWRlT3V0KTtcbiAgICBsZXQgYmlyZFBvcyA9IGJpcmREb3RzLmRhdGFbODVdLmluaXRQb3M7XG4gICAgcm9iaW4uY2xhc3NlZCgnY3VycmVudCcsIHRydWUpO1xuICAgIHJvYmluLnRyYW5zaXRpb24oKVxuICAgICAgLmR1cmF0aW9uKDEwMDApXG4gICAgICAuYXR0cigndHJhbnNmb3JtJywgYHRyYW5zbGF0ZSgke2JpcmRQb3MueCArIGNhbGxvdXREaXN0YW5jZX0sICR7YmlyZFBvcy55fSlgKTtcbiAgfVxuXG4gIGZ1bmN0aW9uIHNob3dMYXRlcigpIHtcbiAgICBjdXJyZW50Q291bnRlci50cmFuc2l0aW9uKClcbiAgICAgIC8vIC5kZWxheSgyMDApXG4gICAgICAuZHVyYXRpb24oNDAwKVxuICAgICAgLnN0eWxlKCdvcGFjaXR5JywgMCk7XG5cbiAgICBjb2xvbml6ZWRDb3VudGVyLnNlbGVjdCgnaDInKS50ZXh0KDApO1xuICAgIGV4dGlycGF0ZWRDb3VudGVyLnNlbGVjdCgnaDInKS50ZXh0KDApO1xuICAgIGNvbG9uaXplZENvdW50ZXIudHJhbnNpdGlvbigpXG4gICAgICAuZHVyYXRpb24oMzAwKVxuICAgICAgLmRlbGF5KDEwMClcbiAgICAgIC5zdHlsZSgnb3BhY2l0eScsIDEpO1xuXG4gICAgZXh0aXJwYXRlZENvdW50ZXIudHJhbnNpdGlvbigpXG4gICAgICAuZHVyYXRpb24oMzAwKVxuICAgICAgLmRlbGF5KDEwMClcbiAgICAgIC5zdHlsZSgnb3BhY2l0eScsIDEpO1xuXG4gICAgYW5pbWF0ZUNvdW50KGNvbG9uaXplZENvdW50ZXIuc2VsZWN0KCdoMicpLCAwLCAxMywgMTUwMCk7XG5cbiAgICBiaXJkRG90cy5lbnRlckNvbG9uaXplZCgoKSA9PiB7XG4gICAgICAgIGdyb3NiZWFrLnRyYW5zaXRpb24oKVxuICAgICAgICAgIC5kdXJhdGlvbigxMDAwKVxuICAgICAgICAgIC5hdHRyKCdvcGFjaXR5JywgMSk7XG5cbiAgICAgICAgc2V0VGltZW91dCgoKSA9PiB7XG4gICAgICAgICAgICAgIGFuaW1hdGVDb3VudChleHRpcnBhdGVkQ291bnRlci5zZWxlY3QoJ2gyJyksIDAsIDIwLCAxMDAwKTtcbiAgICAgICAgICAgICAgbGV0IGJpcmRQb3MgPSBiaXJkRG90cy5kYXRhWzg1XS5maW5hbFBvcztcbiAgICAgICAgICAgICAgcm9iaW4uY2xhc3NlZCgnY3VycmVudCcsIGZhbHNlKTtcbiAgICAgICAgICAgICAgcm9iaW4udHJhbnNpdGlvbigpXG4gICAgICAgICAgICAgICAgLmR1cmF0aW9uKDEwMDApXG4gICAgICAgICAgICAgICAgLmF0dHIoJ3RyYW5zZm9ybScsIGB0cmFuc2xhdGUoJHtiaXJkUG9zLnggKyBjYWxsb3V0RGlzdGFuY2V9LCAke2JpcmRQb3MueX0pYCk7XG5cbiAgICAgICAgICAgICAgcm9iaW4uc2VsZWN0KCdsaW5lJylcbiAgICAgICAgICAgICAgICAuYXR0cignc3Ryb2tlJywgJyM5MGQyZDgnKVxuICAgICAgICAgICAgICAgIC50cmFuc2l0aW9uKClcbiAgICAgICAgICAgICAgICAuZHVyYXRpb24oMTAwMClcbiAgICAgICAgICAgICAgICAgIC5hdHRyKCdzdHJva2UnLCAnI2U4YzU3OCcpO1xuICAgICAgICAgICAgICAgICAgLy8gLmF0dHIoJ29wYWNpdHknLCAxKTtcblxuICAgICAgICAgICAgICByb2Jpbi5zZWxlY3QoJ2NpcmNsZScpXG4gICAgICAgICAgICAgICAgLmF0dHIoJ3N0cm9rZScsICcjOTBkMmQ4JylcbiAgICAgICAgICAgICAgICAuYXR0cignZmlsbCcsICcjOTBkMmQ4JylcbiAgICAgICAgICAgICAgICAudHJhbnNpdGlvbigpXG4gICAgICAgICAgICAgICAgLmR1cmF0aW9uKDEwMDApXG4gICAgICAgICAgICAgICAgICAuYXR0cignc3Ryb2tlJywgJyNlOGM1NzgnKVxuICAgICAgICAgICAgICAgICAgLmF0dHIoJ2ZpbGwnLCAnI2U4YzU3OCcpO1xuXG4gICAgICAgICAgICAgIGJpcmREb3RzLmVudGVyRXh0aXJwYXRlZCgpO1xuICAgICAgICB9LCAxMDAwKTtcbiAgICB9KTtcbiAgfVxuXG4gIHJldHVybiB7XG4gICAgc2hvd0N1cnJlbnQ6IHNob3dDdXJyZW50LFxuICAgIHNob3dMYXRlcjogc2hvd0xhdGVyXG4gIH1cblxufVxuXG5leHBvcnQgeyBCaXJkRG90TGFuZGluZ1BhZ2UgfTtcbiIsImltcG9ydCB7IEJpcmREb3RzLCBCaXJkRG90c0Jhc2V9IGZyb20gJy4vYmlyZERvdC5qcyc7XG5pbXBvcnQgeyBCaXJkRG90TGFuZGluZ1BhZ2UgfSBmcm9tICcuL2JpcmREb3RMYW5kaW5nUGFnZS5qcyc7XG5pbXBvcnQgeyBUdXJub3ZlckNoYXJ0IH0gZnJvbSAnLi90dXJub3Zlci5qcyc7XG5pbXBvcnQgeyBQYXJrTWFwIH0gZnJvbSAnLi9wYXJrTWFwLmpzJztcbmltcG9ydCB7IEFsbFBhcmtzIH0gZnJvbSAnLi9hbGxQYXJrcy5qcyc7XG5cbndpbmRvdy5TdGFtZW5BdWR1Ym9uUGFya3MgPSB7XG4gIEJpcmREb3RzQmFzZTogQmlyZERvdHNCYXNlLFxuICBCaXJkRG90czogQmlyZERvdHMsXG4gIEJpcmREb3RMYW5kaW5nUGFnZTogQmlyZERvdExhbmRpbmdQYWdlLFxuICBQYXJrTWFwOiBQYXJrTWFwLFxuICBUdXJub3ZlckNoYXJ0OiBUdXJub3ZlckNoYXJ0LFxuICBBbGxQYXJrczogQWxsUGFya3Ncbn07XG4iLCJpbXBvcnQge2FsYmVyc0JpZ0FsYXNrYX0gZnJvbSAnLi9hbGJlcnNCaWdBbGFza2EnO1xuLypcbiAgUGFyayBNYXBcblxuICBlbGVtZW50XG4gIHNlYXNvbiAnc3VtbWVyJyBvciAnd2ludGVyJ1xuICBtZXRyaWNcbiAgc2hhcGVVcmw6IHBhdGggdG8gdGhlIHVzIGJvdW5kYXJpZXMgZGF0YXNldFxuICBkYXRhVXJsOiBwYXRoIHRvIHRoZSBjb2xvbml6YXRpb24gLyBleHRpcnBhdGlvbiAuY3N2XG5cbiovXG5cblxuXG4vLyB0aGlzIGNhbiBiZSBicm91Z2h0IGludG8gdGhlIGNsYXNzXG5mdW5jdGlvbiBkcmF3UGFya3MocGFya3MsIGcsIGNvbG9yU2NhbGUsIHNpemVTY2FsZSwgcHJvamVjdGlvbiwgc2VsZWN0aW9uKSB7XG5cbiAgdmFyIHBhcmtDaXJjbGVzID0gZy5zZWxlY3RBbGwoXCIuc2QtcGFya2NpcmNsZVwiKS5kYXRhKHBhcmtzLCBkID0+IGQucGFyayk7XG5cbiAgcGFya0NpcmNsZXMuZXhpdCgpLnJlbW92ZSgpO1xuICBwYXJrQ2lyY2xlcy5lbnRlcigpLmFwcGVuZChcImNpcmNsZVwiKVxuICAgICAgLmNsYXNzZWQoXCJzZC1wYXJrY2lyY2xlXCIsIHRydWUpXG4gICAgICAubWVyZ2UocGFya0NpcmNsZXMpXG4gICAgICAuYXR0cihcInRyYW5zZm9ybVwiLCBmdW5jdGlvbihkKSB7IHJldHVybiBcInRyYW5zbGF0ZShcIiArIHByb2plY3Rpb24oWytkLmxvbmcsK2QubGF0XSkgKyBcIilcIjsgfSlcbiAgICAgIC5jbGFzc2VkKCdob3ZlcicsIGQgPT4gZC51bml0X25hbWUgPT09IHNlbGVjdGlvbilcbiAgICAgIC5vbihcIm1vdXNlb3ZlclwiLCBmdW5jdGlvbihkKSB7XG4gICAgICB9KVxuICAgICAgLm9uKFwibW91c2VvdXRcIiwgZnVuY3Rpb24oZCkge1xuICAgICAgfSlcbiAgICAgIC50cmFuc2l0aW9uKClcbiAgICAgIC5hdHRyKFwiclwiLCBzaXplU2NhbGUpXG4gICAgICAuc3R5bGUoXCJmaWxsXCIsIGNvbG9yU2NhbGUpXG4gICAgICAuc3R5bGUoXCJtaXgtYmxlbmQtbW9kZVwiLCBcIm5vcm1hbFwiKVxuICAgICAgLnN0eWxlKCdzdHJva2UnLCBjb2xvclNjYWxlKTtcbn1cblxuY2xhc3MgV2FuZCB7XG4gIGNvbnN0cnVjdG9yKHN2Zywgc2l6ZSkge1xuICAgIGxldCB3YW5kID0gc3ZnLmFwcGVuZCgnZycpLmNsYXNzZWQoJ3dhbmQnLCB0cnVlKTtcbiAgICB3YW5kLmFwcGVuZCgnY2lyY2xlJylcbiAgICAgIC5hdHRyKCdjeCcsIDApXG4gICAgICAuYXR0cignY3knLCAtc2l6ZSlcbiAgICAgIC5hdHRyKCdyJywgMik7XG4gICAgd2FuZC5hcHBlbmQoJ2xpbmUnKVxuICAgICAgLmF0dHIoJ3gxJywgMClcbiAgICAgIC5hdHRyKCd5MScsIDApXG4gICAgICAuYXR0cigneDInLCAwKVxuICAgICAgLmF0dHIoJ3kyJywgLXNpemUpO1xuXG4gICAgdGhpcy53YW5kID0gd2FuZDtcbiAgfVxuXG4gIGhpZGUoKSB7XG4gICAgdGhpcy53YW5kLmNsYXNzZWQoJ2hpZGRlbicsIHRydWUpO1xuICB9XG5cbiAgbW92ZShwdCkge1xuICAgIHRoaXMud2FuZC5jbGFzc2VkKCdoaWRkZW4nLCBmYWxzZSk7XG4gICAgdGhpcy53YW5kLmF0dHIoJ3RyYW5zZm9ybScsIGB0cmFuc2xhdGUoJHtwdFswXX0sICR7cHRbMV19KWApO1xuICB9XG59XG5cbmZ1bmN0aW9uIFBhcmtNYXAocGFyYW1zKSB7XG4gIGNvbnN0IHtlbGVtZW50LCBzZWFzb24sIG1ldHJpYywgc2hhcGVVcmwsIGRhdGFVcmwsIG9uQ2xpY2t9ID0gcGFyYW1zO1xuXG4gIGxldCBfZWxlbWVudCA9IGQzLnNlbGVjdChlbGVtZW50KS5hcHBlbmQoJ2RpdicpXG4gICAgICAgICAgICAgICAgICAuY2xhc3NlZCgnc2QtbWFwJywgdHJ1ZSk7XG5cbiAgbGV0IHRvb2x0aXAgPSBfZWxlbWVudC5hcHBlbmQoJ2RpdicpXG4gICAgICAgICAgICAgICAgICAuY2xhc3NlZCgnc2QtdG9vbHRpcCcsIHRydWUpXG4gICAgICAgICAgICAgICAgICAuY2xhc3NlZCgnaGlkZGVuJywgdHJ1ZSlcbiAgICAgICAgICAgICAgICAgIC5jbGFzc2VkKCdkb3duJywgZmFsc2UpXG4gICAgICAgICAgICAgICAgICAuaHRtbChgXG4gICAgICAgICAgICAgICAgICAgIDxoMiBjbGFzcz1cInRpdGxlXCI+TmFtZTwvaDI+XG4gICAgICAgICAgICAgICAgICAgIDxkaXY+XG4gICAgICAgICAgICAgICAgICAgICAgPHN2ZyBjbGFzcz1cInNkLWFycm93XCIgaWQ9XCJMYXllcl8xXCIgd2lkdGg9XCIxOFwiIGhlaWdodD1cIjIyLjVcIiBkYXRhLW5hbWU9XCJMYXllciAxXCIgeG1sbnM9XCJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2Z1wiIHZpZXdCb3g9XCIwIDAgMTguNyAyMi41XCI+PHBvbHlnb24gY2xhc3M9XCJzZC1hcnJvdy1pY29uXCIgcG9pbnRzPVwiNi4zNCAxNC4yNiA2LjM0IDIyLjUgNi45NyAyMi41IDExLjcyIDIyLjUgMTIuMzYgMjIuNSAxMi4zNiAxNC4yNiAxOC43IDE0LjI2IDkuMzUgMCAwIDE0LjI2IDYuMzQgMTQuMjZcIi8+PC9zdmc+XG4gICAgICAgICAgICAgICAgICAgICAgPGgyIGNsYXNzPVwibnVtYmVyXCI+MzQ8L2gyPlxuICAgICAgICAgICAgICAgICAgICAgIDxwIGNsYXNzPVwibGFiZWxcIj5FeHRpcnBhdGlvbnM8L3A+XG4gICAgICAgICAgICAgICAgICAgIDwvZGl2PlxuICAgICAgICAgICAgICAgICAgYClcblxuICB0b29sdGlwLnNlbGVjdCgnLnRpdGxlJykub24oJ2NsaWNrJywgKCkgPT4ge1xuICAgIGQzLmV2ZW50LnByZXZlbnREZWZhdWx0KCk7XG4gICAgaWYgKG9uQ2xpY2spIHtcbiAgICAgIG9uQ2xpY2sodG9vbHRpcC5zZWxlY3QoJy50aXRsZScpLnRleHQoKSk7XG4gICAgfVxuICB9KTtcblxuICBsZXQgd2lkdGggPSBkMy5zZWxlY3QoZWxlbWVudCkubm9kZSgpLm9mZnNldFdpZHRoO1xuICBsZXQgaGVpZ2h0ID0gd2lkdGggKiA3MDMgLyAxMTA2O1xuXG4gIHZhciBzdmcgPSBfZWxlbWVudC5hcHBlbmQoXCJzdmdcIilcbiAgICAgICAgICAgICAgICAuYXR0cignd2lkdGgnLCB3aWR0aClcbiAgICAgICAgICAgICAgICAuYXR0cignaGVpZ2h0JywgaGVpZ2h0KTtcblxuICB2YXIgYmFja2dyb3VuZF9nID0gc3ZnLmFwcGVuZChcImdcIikuYXR0cihcImlkXCIsXCJiYWNrZ3JvdW5kX2dcIik7XG4gIHZhciBmb3JlZ3JvdW5kX2cgPSBzdmcuYXBwZW5kKFwiZ1wiKS5hdHRyKFwiaWRcIixcImZvcmVncm91bmRfZ1wiKTtcbiAgdmFyIHBhcmtHcm91cCA9IGZvcmVncm91bmRfZy5hcHBlbmQoXCJnXCIpLmF0dHIoXCJjbGFzc1wiLCBcInBhcmtDaXJjbGVzXCIpO1xuXG4gIHZhciB0b3VjaE9mZnNldFkgPSA1MDtcbiAgdmFyIHdhbmQgPSBuZXcgV2FuZChmb3JlZ3JvdW5kX2csIHRvdWNoT2Zmc2V0WSk7XG5cbiAgbGV0IHByb2plY3Rpb247XG5cbiAgbGV0IHRvb2x0aXBOdW1iZXI7XG4gIGxldCBjb2xvbkNvbG9yID0gZDMuc2NhbGVMaW5lYXIoKVxuICAgICAgICAgICAgICAgICAgICAucmFuZ2UoWycjMThhMWFkJywgJyMxOGExYWQnXSk7XG5cbiAgbGV0IGNvbG9uU2l6ZSA9IGQzLnNjYWxlU3FydCgpO1xuXG4gIGxldCBleHRpcnBDb2xvciA9IGQzLnNjYWxlTGluZWFyKClcbiAgICAgICAgICAgICAgICAgICAgLnJhbmdlKFsnI2U4YzU3OCcsICcjZThjNTc4J10pO1xuXG4gIGxldCBleHRpcnBTaXplID0gZDMuc2NhbGVTcXJ0KCk7XG5cbiAgbGV0IF9zZWFzb24gPSBzZWFzb247XG4gIGxldCBfbWV0cmljID0gbWV0cmljO1xuICBsZXQgX3BhcmtzO1xuICBsZXQgX3N0YXRlcztcblxuICBsZXQgc2VsZWN0aW9uO1xuXG4gIGZ1bmN0aW9uIHJlbmRlcigpIHtcbiAgICBsZXQgY29sb3JTY2FsZSwgc2l6ZVNjYWxlO1xuICAgIGxldCB0b29sdGlwTGFiZWwgPSBgUG90ZW50aWFsICR7X21ldHJpY31zIGluICR7X3NlYXNvbn1gO1xuICAgIHRvb2x0aXAuc2VsZWN0KCcubGFiZWwnKS50ZXh0KHRvb2x0aXBMYWJlbCk7XG5cbiAgICBpZiAoX3NlYXNvbiA9PSAnc3VtbWVyJyAmJiBfbWV0cmljID09ICdjb2xvbml6YXRpb24nKSB7XG5cbiAgICAgIGNvbG9yU2NhbGUgPSAoZCkgPT4gY29sb25Db2xvcihkWydub19jb2xvbml6YXRpb25zX3N1bW1lciddKTtcbiAgICAgIHNpemVTY2FsZSA9IChkKSA9PiBjb2xvblNpemUoZFsnbm9fY29sb25pemF0aW9uc19zdW1tZXInXSk7XG4gICAgICB0b29sdGlwTnVtYmVyID0gKGQpID0+IGRbJ25vX2NvbG9uaXphdGlvbnNfc3VtbWVyJ107XG4gICAgICB0b29sdGlwLmNsYXNzZWQoJ2Rvd24nLCBmYWxzZSk7XG5cbiAgICB9IGVsc2UgaWYgKF9zZWFzb24gPT0gJ3N1bW1lcicgJiYgX21ldHJpYyA9PSAnZXh0aXJwYXRpb24nKSB7XG5cbiAgICAgIGNvbG9yU2NhbGUgPSAoZCkgPT4gZXh0aXJwQ29sb3IoZFsnbm9fZXh0aXJwYXRpb25zX3N1bW1lciddKTtcbiAgICAgIHNpemVTY2FsZSA9IChkKSA9PiBleHRpcnBTaXplKGRbJ25vX2V4dGlycGF0aW9uc19zdW1tZXInXSk7XG4gICAgICB0b29sdGlwTnVtYmVyID0gKGQpID0+IGRbJ25vX2V4dGlycGF0aW9uc19zdW1tZXInXTtcbiAgICAgIHRvb2x0aXAuY2xhc3NlZCgnZG93bicsIHRydWUpO1xuXG4gICAgfSBlbHNlIGlmIChfc2Vhc29uID09ICd3aW50ZXInICYmIF9tZXRyaWMgPT0gJ2NvbG9uaXphdGlvbicpIHtcblxuICAgICAgY29sb3JTY2FsZSA9IChkKSA9PiBjb2xvbkNvbG9yKGRbJ25vX2NvbG9uaXphdGlvbnNfd2ludGVyJ10pO1xuICAgICAgc2l6ZVNjYWxlID0gKGQpID0+IGNvbG9uU2l6ZShkWydub19jb2xvbml6YXRpb25zX3dpbnRlciddKTtcbiAgICAgIHRvb2x0aXBOdW1iZXIgPSAoZCkgPT4gZFsnbm9fY29sb25pemF0aW9uc193aW50ZXInXTtcbiAgICAgIHRvb2x0aXAuY2xhc3NlZCgnZG93bicsIGZhbHNlKTtcblxuICAgIH0gZWxzZSBpZiAoX3NlYXNvbiA9PSAnd2ludGVyJyAmJiBfbWV0cmljID09ICdleHRpcnBhdGlvbicpIHtcblxuICAgICAgY29sb3JTY2FsZSA9IChkKSA9PiBleHRpcnBDb2xvcihkWydub19leHRpcnBhdGlvbnNfd2ludGVyJ10pO1xuICAgICAgc2l6ZVNjYWxlID0gKGQpID0+IGV4dGlycFNpemUoZFsnbm9fZXh0aXJwYXRpb25zX3dpbnRlciddKTtcbiAgICAgIHRvb2x0aXBOdW1iZXIgPSAoZCkgPT4gZFsnbm9fZXh0aXJwYXRpb25zX3dpbnRlciddO1xuICAgICAgdG9vbHRpcC5jbGFzc2VkKCdkb3duJywgdHJ1ZSk7XG5cbiAgICB9XG5cbiAgICBkcmF3UGFya3MoX3BhcmtzLCBwYXJrR3JvdXAsIGNvbG9yU2NhbGUsIHNpemVTY2FsZSwgcHJvamVjdGlvbiwgc2VsZWN0aW9uKTtcbiAgfVxuXG4gIGZ1bmN0aW9uIHJlZHJhdygpIHtcblxuICAgIGxldCB3aWR0aCA9IF9lbGVtZW50Lm5vZGUoKS5vZmZzZXRXaWR0aDtcbiAgICBsZXQgaGVpZ2h0ID0gd2lkdGggKiA3MDMgLyAxMTA2O1xuXG4gICAgc3ZnLmF0dHIoJ3dpZHRoJywgd2lkdGgpXG4gICAgICAgLmF0dHIoJ2hlaWdodCcsIGhlaWdodCk7XG5cbiAgICBsZXQgbWFwUGFkZGluZyA9IDQwICogd2lkdGggLyAxMTA2OztcbiAgICBwcm9qZWN0aW9uID0gYWxiZXJzQmlnQWxhc2thKClcbiAgICAgIC5maXRFeHRlbnQoW1swICsgbWFwUGFkZGluZywgMCArIG1hcFBhZGRpbmddLCBbd2lkdGggLSBtYXBQYWRkaW5nLCBoZWlnaHQgLSBtYXBQYWRkaW5nXV0sIHtcbiAgICAgICAgdHlwZTogJ0ZlYXR1cmVDb2xsZWN0aW9uJyxcbiAgICAgICAgZmVhdHVyZXM6IF9zdGF0ZXNcbiAgICAgIH0pO1xuXG4gICAgLy8gZHJhdyBiYXNlIGxheWVyXG4gICAgbGV0IHN0YXRlc1BhdGggPSBiYWNrZ3JvdW5kX2cuc2VsZWN0QWxsKFwicGF0aFwiKVxuICAgICAgICAuZGF0YShfc3RhdGVzKTtcbiAgICBzdGF0ZXNQYXRoLmVudGVyKClcbiAgICAgICAgLmFwcGVuZChcInBhdGhcIilcbiAgICAgIC5tZXJnZShzdGF0ZXNQYXRoKVxuICAgICAgICAuYXR0cihcImRcIiwgZDMuZ2VvUGF0aChwcm9qZWN0aW9uKSlcbiAgICAgICAgLnN0eWxlKFwiZmlsbFwiLCBcIiNlNWU1ZTVcIilcbiAgICAgICAgLnN0eWxlKFwic3Ryb2tlXCIsIGQgPT4gZC5wcm9wZXJ0aWVzLnBvc3RhbCA9PT0gJ0FLJyA/IFwiI2Q4ZDhkOFwiIDogXCJ3aGl0ZVwiKVxuXG4gICAgLy8gY29tcHV0ZSB0aGUgZG9tYWluc1xuICAgIGxldCBjb2xvblJhbmdlID0gZDMuZXh0ZW50KFxuICAgICAgICAgICAgICBfcGFya3MubWFwKGQgPT4gZFsnbm9fY29sb25pemF0aW9uc19zdW1tZXInXSlcbiAgICAgICAgICAgIC5jb25jYXQoX3BhcmtzLm1hcChkID0+IGRbJ25vX2NvbG9uaXphdGlvbnNfd2ludGVyJ10pKSk7XG5cbiAgICBsZXQgZXh0aXJwUmFuZ2UgPSBkMy5leHRlbnQoXG4gICAgICAgICAgICAgIF9wYXJrcy5tYXAoZCA9PiBkWydub19leHRpcnBhdGlvbnNfc3VtbWVyJ10pXG4gICAgICAgICAgICAuY29uY2F0KF9wYXJrcy5tYXAoZCA9PiBkWydub19leHRpcnBhdGlvbnNfd2ludGVyJ10pKSk7XG5cbiAgICBsZXQgbWluUmFkaXVzID0gMiAvIDMyMCAqIHdpZHRoO1xuICAgIGxldCBtYXhSYWRpdXMgPSAxMyAvIDMyMCAqIHdpZHRoXG5cbiAgICBjb2xvbkNvbG9yLmRvbWFpbihjb2xvblJhbmdlKTtcbiAgICBjb2xvblNpemUuZG9tYWluKGNvbG9uUmFuZ2UpXG4gICAgICAucmFuZ2UoW21pblJhZGl1cywgbWF4UmFkaXVzXSk7XG4gICAgZXh0aXJwQ29sb3IuZG9tYWluKGV4dGlycFJhbmdlKTtcbiAgICBleHRpcnBTaXplLmRvbWFpbihleHRpcnBSYW5nZSlcbiAgICAgIC5yYW5nZShbbWluUmFkaXVzLCBtYXhSYWRpdXNdKTtcblxuICAgIGxldCBwb2ludHMgPSBfcGFya3MubWFwKHAgPT4gcHJvamVjdGlvbihbK3AubG9uZywgK3AubGF0XSkpO1xuXG4gICAgbGV0IF92ID0gZDMudm9yb25vaSgpXG4gICAgICAvL3BpeGVsIHNwYWNlXG4gICAgICAueChkID0+IHsgcmV0dXJuIHByb2plY3Rpb24oIFsrZC5sb25nLCArZC5sYXRdKVswXTsgfSlcbiAgICAgIC55KGQgPT4geyByZXR1cm4gcHJvamVjdGlvbiggWytkLmxvbmcsICtkLmxhdF0pWzFdOyB9KVxuICAgICAgKF9wYXJrcyk7XG5cbiAgICBmdW5jdGlvbiBoaXREZXRlY3RvcihwLCBvZmZzZXRZKSB7XG4gICAgICBvZmZzZXRZID0gb2Zmc2V0WSB8fCAwO1xuICAgICAgbGV0IG1heERpc3RhbmNlRnJvbVBvaW50ID0gMjA7XG4gICAgICByZXR1cm4gX3YuZmluZChwWzBdLCBwWzFdIC0gb2Zmc2V0WSwgbWF4RGlzdGFuY2VGcm9tUG9pbnQpO1xuICAgIH1cblxuICAgIGxldCBmb2N1c2VkID0gZmFsc2U7XG5cbiAgICBmdW5jdGlvbiBoaWdobGlnaHQocGFya05vZGUpIHtcbiAgICAgIGlmIChwYXJrTm9kZSkge1xuXG4gICAgICAgIHNlbGVjdGlvbiA9IHBhcmtOb2RlLmRhdGEudW5pdF9uYW1lO1xuICAgICAgICByZW5kZXIoKTtcblxuICAgICAgICB0b29sdGlwLmNsYXNzZWQoJ2hpZGRlbicsIGZhbHNlKVxuICAgICAgICB0b29sdGlwLnNlbGVjdCgnLnRpdGxlJykudGV4dChwYXJrTm9kZS5kYXRhLnVuaXRfbmFtZSk7XG4gICAgICAgIHRvb2x0aXAuc2VsZWN0KCcubnVtYmVyJykudGV4dCh0b29sdGlwTnVtYmVyKHBhcmtOb2RlLmRhdGEpKTtcblxuICAgICAgICBsZXQgZHggPSB0b29sdGlwLm5vZGUoKS5jbGllbnRXaWR0aCAvIDI7XG4gICAgICAgIGxldCBkeSA9IHBhcmtOb2RlWzFdIC0gdG9vbHRpcC5ub2RlKCkuY2xpZW50SGVpZ2h0IC0gNTsgLy8gYSBiaXQgb2ZmIGNlbnRlclxuICAgICAgICBkeCA9IHBhcmtOb2RlWzBdIC0gZHg7XG5cbiAgICAgICAgdG9vbHRpcC5zdHlsZSgnbGVmdCcsIGR4ICsgJ3B4Jyk7XG4gICAgICAgIHRvb2x0aXAuc3R5bGUoJ3RvcCcsIGR5ICsgJ3B4Jyk7XG5cbiAgICAgICAgLy8gc25hcCB0byB0aGUgd2luZG93XG4gICAgICAgIGxldCByZWN0ID0gdG9vbHRpcC5ub2RlKCkuZ2V0Qm91bmRpbmdDbGllbnRSZWN0KCk7XG4gICAgICAgIGxldCBtYXhXaWR0aCA9IHdpbmRvdy5pbm5lcldpZHRoO1xuXG4gICAgICAgIGlmIChyZWN0LnggPCAwKSB7XG4gICAgICAgICAgZHggLT0gcmVjdC54O1xuICAgICAgICB9IGVsc2UgaWYgKHJlY3QueCArIHJlY3Qud2lkdGggPiBtYXhXaWR0aCkge1xuICAgICAgICAgIGR4ID0gbWF4V2lkdGggLSByZWN0LndpZHRoO1xuICAgICAgICB9XG5cbiAgICAgICAgdG9vbHRpcC5zdHlsZSgnbGVmdCcsIGR4ICsgJ3B4Jyk7XG4gICAgICAgIHRvb2x0aXAuc3R5bGUoJ3RvcCcsIGR5ICsgJ3B4Jyk7XG5cbiAgICAgIH0gZWxzZSB7XG4gICAgICAgIHRvb2x0aXAuY2xhc3NlZCgnaGlkZGVuJywgdHJ1ZSlcbiAgICAgICAgc2VsZWN0aW9uID0gbnVsbDtcbiAgICAgICAgcmVuZGVyKCk7XG4gICAgICB9XG4gICAgfVxuXG4gICAgc3ZnLm9uKCdjbGljaycsIGZ1bmN0aW9uKCkge1xuICAgICAgbGV0IHBhcmsgPSBoaXREZXRlY3RvcihkMy5tb3VzZSh0aGlzKSk7XG4gICAgICBoaWdobGlnaHQocGFyayk7XG4gICAgICBmb2N1c2VkID0gcGFyayAhPSBudWxsO1xuICAgIH0pO1xuXG4gICAgc3ZnLm9uKCd0b3VjaG1vdmUnLCBmdW5jdGlvbihlKSB7XG4gICAgICB3YW5kLm1vdmUoZDMudG91Y2hlcyh0aGlzKVswXSk7XG4gICAgICBsZXQgcGFyayA9IGhpdERldGVjdG9yKGQzLnRvdWNoZXModGhpcylbMF0sIHRvdWNoT2Zmc2V0WSk7XG4gICAgICBoaWdobGlnaHQocGFyayk7XG4gICAgICBkMy5ldmVudC5wcmV2ZW50RGVmYXVsdCgpO1xuICAgIH0pXG4gICAgc3ZnLm9uKCd0b3VjaGVuZCcsIGZ1bmN0aW9uKGUpIHtcbiAgICAgIHdhbmQuaGlkZSgpO1xuICAgIH0pO1xuICAgIHN2Zy5vbignbW91c2Vtb3ZlJywgZnVuY3Rpb24oKSB7XG4gICAgICBpZiAoIWZvY3VzZWQpIHtcbiAgICAgICAgbGV0IHBhcmsgPSBoaXREZXRlY3RvcihkMy5tb3VzZSh0aGlzKSk7XG4gICAgICAgIGhpZ2hsaWdodChwYXJrKTtcbiAgICAgIH1cbiAgICB9KTtcblxuICAgIHJlbmRlcigpO1xuXG4gIH0gLy9lbmQgaW5pdFxuXG4gIGZ1bmN0aW9uIHNldFBhcmFtcyhzZWFzb24sIG1ldHJpYykge1xuICAgIF9zZWFzb24gPSBzZWFzb247XG4gICAgX21ldHJpYyA9IG1ldHJpYztcbiAgICByZW5kZXIoKTtcbiAgfVxuXG4gIC8vbG9hZCB0aGUgZGF0YVxuICBkMy5xdWV1ZSgpXG4gICAgLmRlZmVyKGQzLmpzb24sIHNoYXBlVXJsKVxuICAgIC5kZWZlcihkMy5jc3YsIGRhdGFVcmwpXG4gICAgLmF3YWl0QWxsKGZ1bmN0aW9uKGVycm9yLCByZXN1bHRzKSB7XG5cbiAgICBsZXQgc3RhdGVzID0gcmVzdWx0c1swXTtcbiAgICBsZXQgcGFya3MgPSByZXN1bHRzWzFdO1xuXG4gICAgLy8gdHlwZWNhc3RcbiAgICBwYXJrcy5mb3JFYWNoKGZ1bmN0aW9uKHBhcmspIHtcbiAgICAgIHBhcmsucGFyayA9IHBhcmsucGFyaztcbiAgICAgIHBhcmsudW5pdF9uYW1lID0gcGFyay51bml0X25hbWU7XG4gICAgICBwYXJrLm5wc19yZWdpb24gPSBwYXJrLm5wc19yZWdpb247XG4gICAgICBwYXJrLnR1cm5vdmVyX3N1bW1lciA9ICtwYXJrLnR1cm5vdmVyX3N1bW1lcjtcbiAgICAgIHBhcmsudHVybm92ZXJfd2ludGVyID0gK3BhcmsudHVybm92ZXJfd2ludGVyO1xuICAgICAgcGFyay5sb25nID0gK3BhcmsubG9uZztcbiAgICAgIHBhcmsubGF0ID0gK3BhcmsubGF0O1xuICAgICAgcGFyay5jdXJyZW50X25vX3NwZWNpZXNfc3VtbWVyID0gK3Bhcmsubm9fc3BlY2llc19zdW1tZXI7XG4gICAgICBwYXJrLmN1cnJlbnRfbm9fc3BlY2llc193aW50ZXIgPSArcGFyay5ub19zcGVjaWVzX3dpbnRlcjtcbiAgICAgIHBhcmsucHJvcF9jb2xvbml6YXRpb25zX3N1bW1lciA9ICtwYXJrLnByb3BfY29sb25pemF0aW9uc19zdW1tZXI7XG4gICAgICBwYXJrLnByb3BfY29sb25pemF0aW9uc193aW50ZXIgPSArcGFyay5wcm9wX2NvbG9uaXphdGlvbnNfd2ludGVyO1xuICAgICAgcGFyay5wcm9wX2V4dGlycGF0aW9uc193aW50ZXIgPSArcGFyay5wcm9wX2V4dGlycGF0aW9uc193aW50ZXI7XG4gICAgICBwYXJrLnByb3BfZXh0aXJwYXRpb25zX3N1bW1lciA9ICtwYXJrLnByb3BfZXh0aXJwYXRpb25zX3N1bW1lcjtcbiAgICAgIHBhcmsubm9fZXh0aXJwYXRpb25zX3N1bW1lciA9ICtwYXJrLm5vX2V4dGlycGF0aW9uc19zdW1tZXI7XG4gICAgICBwYXJrLm5vX2V4dGlycGF0aW9uc193aW50ZXIgPSArcGFyay5ub19leHRpcnBhdGlvbnNfd2ludGVyO1xuICAgICAgcGFyay5ub19jb2xvbml6YXRpb25zX3N1bW1lciA9ICtwYXJrLm5vX2NvbG9uaXphdGlvbnNfc3VtbWVyO1xuICAgICAgcGFyay5ub19jb2xvbml6YXRpb25zX3dpbnRlciA9ICtwYXJrLm5vX2NvbG9uaXphdGlvbnNfd2ludGVyO1xuICAgIH0pO1xuXG4gICAgLy8gZ2V0IHJpZCBvZiBoYXdhaWlcbiAgICBzdGF0ZXMgPSBzdGF0ZXMuZmVhdHVyZXMuZmlsdGVyKGQgPT4ge1xuICAgICAgcmV0dXJuIGQucHJvcGVydGllcy5hZG0wX2EzID09ICdVU0EnICYmIGQucHJvcGVydGllcy5wb3N0YWwgIT0gJ0hJJztcbiAgICB9KVxuXG5cbiAgICBfcGFya3MgPSBwYXJrcztcbiAgICBfc3RhdGVzID0gc3RhdGVzO1xuXG4gICAgcmVkcmF3KCk7XG5cbiAgICB3aW5kb3cuYWRkRXZlbnRMaXN0ZW5lcihcInJlc2l6ZVwiLCByZWRyYXcpO1xuXG4gIH0pO1xuXG4gIHJldHVybiB7XG4gICAgc2V0UGFyYW1zOiBzZXRQYXJhbXNcbiAgfVxufVxuXG5leHBvcnQgeyBQYXJrTWFwIH07XG4iLCJmdW5jdGlvbiBmb3JtYXRUdXJub3ZlcihkKSB7XG4gICAgcmV0dXJuIE1hdGgucm91bmQoZCAqIDEwMCkgKyAnJSc7XG59XG5cbmZ1bmN0aW9uIGNlbnRlck9uWChlbGVtZW50LCB4KSB7XG4gICAgLy8gcG9zaXRpb25zIGFuIGVsZW1lbnQgb24geCByZWxhdGl2ZSB0byBpdHMgcGFyZW50XG4gICAgLy8gc25hcHMgdGhlIGVsZW1lbnQgdG8gdGhlIGJvdW5kYXJpZXMgb2YgdGhlIHBhcmVudFxuXG4gICAgbGV0IHdpZHRoID0gZWxlbWVudC5ub2RlKCkub2Zmc2V0V2lkdGg7XG4gICAgbGV0IG1heFdpZHRoID0gZWxlbWVudC5ub2RlKCkucGFyZW50Tm9kZS5vZmZzZXRXaWR0aDtcblxuICAgIHggPSB4IC0gd2lkdGggLyAyO1xuXG4gICAgLy8gc25hcCB0byB0aGUgd2luZG93XG4gICAgaWYgKHggPCAwKSB7XG4gICAgICAgIHggPSAwO1xuICAgIH0gZWxzZSBpZiAoeCArIHdpZHRoID4gbWF4V2lkdGgpIHtcbiAgICAgICAgeCA9IG1heFdpZHRoIC0gd2lkdGg7XG4gICAgfVxuXG4gICAgZWxlbWVudC5zdHlsZSgnbGVmdCcsIHggKyAncHgnKTtcbn1cblxuZnVuY3Rpb24gRG90Q2hhcnQocGFyYW1zKSB7XG4gICAgY29uc3Qge2VsZW1lbnQsIHNob3dOYW1lLCBvbkhvdmVyLCBvbkNsaWNrLCBzY2FsZX0gPSBwYXJhbXM7XG5cbiAgICBsZXQgX2RhdGEgPSBbXTtcbiAgICBsZXQgaGl0RGV0ZWN0b3I7XG4gICAgbGV0IGhlaWdodCA9IDkwO1xuXG4gICAgY29uc3QgUkFESVVTID0gNjtcbiAgICBjb25zdCBTRUxFQ1RFRF9SQURJVVMgPSAxMztcbiAgICBsZXQgZG90Q2VudGVyID0gaGVpZ2h0IC0gNiAtIFNFTEVDVEVEX1JBRElVUztcbiAgICBsZXQgbWFyZ2luID0ge1xuICAgICAgICB0b3A6IDAsXG4gICAgICAgIGxlZnQ6IDIwXG4gICAgfTtcbiAgICBsZXQgeDtcblxuXG4gICAgbGV0IHN2ZyA9IGVsZW1lbnQuYXBwZW5kKCdzdmcnKVxuICAgICAgICAgICAgICAgIC5hcHBlbmQoJ2cnKVxuICAgICAgICAgICAgICAgIC5hdHRyKCd0cmFuc2Zvcm0nLCBgdHJhbnNsYXRlKCR7bWFyZ2luLmxlZnR9LCAke21hcmdpbi50b3B9KWApO1xuXG4gICAgc3ZnLmFwcGVuZCgncmVjdCcpXG4gICAgICAgIC5hdHRyKCdjbGFzcycsICdvdmVybGF5JylcbiAgICAgICAgLmF0dHIoJ2hlaWdodCcsIGhlaWdodClcbiAgICAgICAgLmF0dHIoJ3gnLCAwKVxuICAgICAgICAuYXR0cigneScsIDApXG4gICAgICAgIC5hdHRyKCdmaWxsLW9wYWNpdHknLCAwLjApO1xuXG4gICAgbGV0IGZvY3VzID0gZWxlbWVudC5hcHBlbmQoJ2RpdicpLmNsYXNzZWQoJ3NkLXR1cm5vdmVyLXRvb2x0aXAnLCB0cnVlKS5jbGFzc2VkKCdoaWRkZW4nLCB0cnVlKTtcbiAgICBsZXQgcGVybWFGb2N1cyA9IGVsZW1lbnQuYXBwZW5kKCdkaXYnKS5jbGFzc2VkKCdzZC1wZXJtYS10b29sdGlwJywgdHJ1ZSlcbiAgICBsZXQgZmllbGQ7XG5cbiAgICBmdW5jdGlvbiByZWRyYXcoZGF0YSwgX2ZpZWxkLCBzZWxlY3RlZCkge1xuICAgICAgICAvLyBjb3B5IG92ZXIgdGhlIGFycmF5XG4gICAgICAgIGZpZWxkID0gX2ZpZWxkO1xuICAgICAgICBfZGF0YSA9IGRhdGEuc2xpY2UoKTtcblxuICAgICAgICAvLyBzb3J0IGluIGFzY2VuZGluZyB2YWx1ZVxuICAgICAgICBfZGF0YS5zb3J0KChhLCBiKSA9PiBkMy5hc2NlbmRpbmcoYVtmaWVsZF0sIGJbZmllbGRdKSk7XG5cbiAgICAgICAgLy8gc2l6ZSB0aGUgc3ZnXG4gICAgICAgIGxldCB3aWR0aCA9IGVsZW1lbnQubm9kZSgpLm9mZnNldFdpZHRoO1xuICAgICAgICBlbGVtZW50LnN0eWxlKCdoZWlnaHQnLCBoZWlnaHQgKyAncHgnKVxuICAgICAgICBlbGVtZW50LnNlbGVjdCgnc3ZnJylcbiAgICAgICAgICAgIC5hdHRyKCd3aWR0aCcsIHdpZHRoKVxuICAgICAgICAgICAgLmF0dHIoJ2hlaWdodCcsIGhlaWdodClcblxuXG4gICAgICAgIC8vIHRoaXMgc2NhbGUgaXMgbm93IGluZGVwZW5kZW50XG5cbiAgICAgICAgbGV0IF94O1xuICAgICAgICBpZiAoc2NhbGUgPT0gJ2xvZycpIHtcbiAgICAgICAgICAgIF94ID0gZDMuc2NhbGVMb2coKVxuICAgICAgICAgICAgICAgIC5yYW5nZShbMCwgd2lkdGggLSAyICogbWFyZ2luLmxlZnRdKVxuICAgICAgICAgICAgICAgIC5jbGFtcCh0cnVlKTtcbiAgICAgICAgICAgIGxldCBkb21haW4gPSBkMy5leHRlbnQoZGF0YSwgZCA9PiBkW2ZpZWxkXSAqIDEwMCk7XG4gICAgICAgICAgICBkb21haW5bMF0gPSBNYXRoLm1heCgxLCBkb21haW5bMF0pO1xuICAgICAgICAgICAgX3guZG9tYWluKGRvbWFpbik7XG4gICAgICAgIH0gZWxzZSB7XG4gICAgICAgICAgICBfeCA9IGQzLnNjYWxlTGluZWFyKClcbiAgICAgICAgICAgICAgICAucmFuZ2UoWzAsIHdpZHRoIC0gMiAqIG1hcmdpbi5sZWZ0XSlcbiAgICAgICAgICAgICAgICAuY2xhbXAodHJ1ZSk7XG4gICAgICAgICAgICBfeC5kb21haW4oZDMuZXh0ZW50KGRhdGEsIGQgPT4gZFtmaWVsZF0gKiAxMDApKTtcbiAgICAgICAgfVxuXG4gICAgICAgIHggPSAoZCkgPT4gX3goZFtmaWVsZF0gKiAxMDApO1xuXG4gICAgICAgIC8vIGNvbnNvbGUubG9nKCd4JywgX3guZG9tYWluKCksIF94LnJhbmdlKCkpO1xuXG4gICAgICAgIGxldCBzZWxlY3RlZERhdGEgPSBfZGF0YS5maW5kKGQgPT4gZC51bml0X25hbWUgPT0gc2VsZWN0ZWQpO1xuXG4gICAgICAgIC8vIHJlbmRlciB0aGUgc2VsZWN0aW9uXG4gICAgICAgIGxldCBzZWxlY3RlZERvdHMgPSBzdmcuc2VsZWN0QWxsKCcuc2Qtc2VsZWN0ZWQtZG90JykuZGF0YShbc2VsZWN0ZWREYXRhXSk7XG4gICAgICAgIHNlbGVjdGVkRG90cy5lbnRlcigpXG4gICAgICAgICAgICAuYXBwZW5kKCdjaXJjbGUnKVxuICAgICAgICAgICAgLmNsYXNzZWQoJ3NkLXNlbGVjdGVkLWRvdCcsIHRydWUpXG4gICAgICAgICAgICAubWVyZ2Uoc2VsZWN0ZWREb3RzKVxuICAgICAgICAgICAgICAgIC5hdHRyKCdjeCcsIHgpXG4gICAgICAgICAgICAgICAgLmF0dHIoJ2N5JywgZG90Q2VudGVyKVxuICAgICAgICAgICAgICAgIC5hdHRyKCdyJywgU0VMRUNURURfUkFESVVTKTtcblxuICAgICAgICAvLyByZW5kZXIgdGhlIG90aGVyIHBhcmtzXG4gICAgICAgIGxldCBvdGhlclBhcmtzID0gX2RhdGEuZmlsdGVyKGQgPT4gZC51bml0X25hbWUgIT0gc2VsZWN0ZWQpO1xuICAgICAgICAvLyBjb25zb2xlLmxvZygnb3RoZXJwYXJrcycsIG90aGVyUGFya3MpO1xuICAgICAgICBsZXQgZG90cyA9IHN2Zy5zZWxlY3RBbGwoJy5zZC1kb3QnKS5kYXRhKG90aGVyUGFya3MpO1xuICAgICAgICBkb3RzLmVudGVyKClcbiAgICAgICAgICAgIC5hcHBlbmQoJ2NpcmNsZScpXG4gICAgICAgICAgICAuY2xhc3NlZCgnc2QtZG90JywgdHJ1ZSlcbiAgICAgICAgICAgIC5tZXJnZShkb3RzKVxuICAgICAgICAgICAgICAgIC5jbGFzc2VkKCdzZWxlY3RlZCcsIGQgPT4gZC51bml0X25hbWUgPT09IHNlbGVjdGVkKVxuICAgICAgICAgICAgICAgIC5hdHRyKCdjeCcsIHgpXG4gICAgICAgICAgICAgICAgLmF0dHIoJ2N5JywgZG90Q2VudGVyKVxuICAgICAgICAgICAgICAgIC5hdHRyKCdyJywgUkFESVVTKTtcblxuICAgICAgICBoaXREZXRlY3RvciA9IGQzLnZvcm9ub2koKVxuICAgICAgICAgICAgLngoeClcbiAgICAgICAgICAgIC55KDApXG4gICAgICAgICAgICAob3RoZXJQYXJrcyk7XG5cbiAgICAgICAgLy8gaGl0IGRldGVjdG9yIG92ZXJsYXlcbiAgICAgICAgdmFyIG92ZXJsYXkgPSBzdmcuc2VsZWN0KCcub3ZlcmxheScpXG4gICAgICAgICAgICAuYXR0cignd2lkdGgnLCB3aWR0aClcbiAgICAgICAgICAgIC5vbignbW91c2VvdmVyJywgbW91c2Vtb3ZlKVxuICAgICAgICAgICAgLm9uKCdtb3VzZW91dCcsIGQgPT4gb25Ib3ZlcigpKVxuICAgICAgICAgICAgLm9uKCdtb3VzZW1vdmUnLCBtb3VzZW1vdmUpXG4gICAgICAgICAgICAub24oJ3RvdWNobW92ZScsIHRvdWNobW92ZSlcbiAgICAgICAgICAgIC5vbignY2xpY2snLCBtb3VzZWNsaWNrKTtcblxuICAgICAgICAvLyBsYWJlbHNcbiAgICAgICAgbGV0IHBlcm1hTGFiZWwgPSAnJztcbiAgICAgICAgaWYgKHNob3dOYW1lKSB7XG4gICAgICAgICAgICBwZXJtYUxhYmVsID0gc2VsZWN0ZWREYXRhLnVuaXRfbmFtZSArICcgJztcbiAgICAgICAgfVxuICAgICAgICBwZXJtYUxhYmVsICs9IGZvcm1hdFR1cm5vdmVyKHNlbGVjdGVkRGF0YVtmaWVsZF0pO1xuICAgICAgICBwZXJtYUZvY3VzLnRleHQocGVybWFMYWJlbCk7XG5cblxuICAgICAgICBsZXQgZHkgPSBkb3RDZW50ZXIgLSAoU0VMRUNURURfUkFESVVTICogMykgLSAxMCArIG1hcmdpbi50b3A7XG4gICAgICAgIHBlcm1hRm9jdXMuc3R5bGUoJ3RvcCcsIGR5ICsgJ3B4Jyk7XG5cbiAgICAgICAgY2VudGVyT25YKHBlcm1hRm9jdXMsIHgoc2VsZWN0ZWREYXRhKSArIG1hcmdpbi5sZWZ0KTtcblxuICAgICAgICBkeSA9IGRvdENlbnRlciAtIChSQURJVVMgKiAzKSAtIDE0ICsgbWFyZ2luLnRvcDtcbiAgICAgICAgZm9jdXMuc3R5bGUoJ3RvcCcsIGR5ICsgJ3B4Jyk7XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gY2xlYXJIb3ZlcigpIHtcbiAgICAgICAgc3ZnLnNlbGVjdEFsbChcIi5zZC1kb3RcIilcbiAgICAgICAgICAgIC5jbGFzc2VkKFwiaG92ZXJlZFwiLCBmYWxzZSk7XG5cbiAgICAgICAgLy8gY2xlYXIgZm9jdXNcbiAgICAgICAgZm9jdXMuY2xhc3NlZCgnaGlkZGVuJywgdHJ1ZSlcbiAgICB9XG5cbiAgICBmdW5jdGlvbiByZW5kZXJIb3ZlcihuYW1lKSB7XG4gICAgICAgIC8vIHJlbmRlciBob3ZlciBzdGF0ZVxuICAgICAgICAvLyBjb25zb2xlLmxvZygncmVuZGVySG92ZXIgZm9yJywgZWxlbWVudC5ub2RlKCkuaWQpO1xuICAgICAgICBsZXQgb2JqID0gX2RhdGEuZmluZChkID0+IGQudW5pdF9uYW1lID09PSBuYW1lKTtcbiAgICAgICAgaWYgKCFvYmopIHtcbiAgICAgICAgICAgIC8vIGNvbnNvbGUubG9nKFwiT0ggTk8gY2FuJ3QgZmluZFwiLCBuYW1lKTtcbiAgICAgICAgICAgIHJldHVybjtcbiAgICAgICAgfVxuICAgICAgICBzdmcuc2VsZWN0QWxsKFwiLnNkLWRvdFwiKVxuICAgICAgICAgICAgLmNsYXNzZWQoXCJob3ZlcmVkXCIsIGQgPT4gZC51bml0X25hbWUgPT09IG9iai51bml0X25hbWUpO1xuXG4gICAgICAgIC8vIGZvcm1hdCB0aGUgZm9jdXNcbiAgICAgICAgbGV0IHRleHQgPSAnJztcbiAgICAgICAgaWYgKHNob3dOYW1lKSB7XG4gICAgICAgICAgICB0ZXh0ID0gb2JqLnVuaXRfbmFtZSArICcgJztcbiAgICAgICAgfVxuICAgICAgICB0ZXh0ICs9IGZvcm1hdFR1cm5vdmVyKG9ialtmaWVsZF0pO1xuICAgICAgICBmb2N1cy50ZXh0KHRleHQpO1xuICAgICAgICBmb2N1cy5jbGFzc2VkKCdoaWRkZW4nLCBmYWxzZSlcblxuICAgICAgICBjZW50ZXJPblgoZm9jdXMsIHgob2JqKSArIG1hcmdpbi5sZWZ0KTtcbiAgICAgICAgLy8gbW92ZSB0byB0b3BcbiAgICAgICAgbGV0IGhvdmVyZWQgPSBzdmcuc2VsZWN0KCcuaG92ZXJlZCcpLm5vZGUoKTtcbiAgICAgICAgaG92ZXJlZC5wYXJlbnRFbGVtZW50LmFwcGVuZENoaWxkKGhvdmVyZWQpO1xuICAgIH1cblxuICAgIGZ1bmN0aW9uIHRvdWNobW92ZSgpIHtcbiAgICAgICAgdmFyIG1vdXNlWCA9IGQzLnRvdWNoZXModGhpcylbMF1bMF07XG4gICAgICAgIHZhciBmb3VuZCA9IGhpdERldGVjdG9yLmZpbmQobW91c2VYLCAwLCAyMCk7XG5cbiAgICAgICAgaWYgKGZvdW5kKSB7XG4gICAgICAgICAgICBmb3VuZCA9IGZvdW5kLmRhdGE7XG4gICAgICAgICAgICAvLyBjb25zb2xlLmxvZygnZm91bmQgaG92ZXInLCBmb3VuZCk7XG4gICAgICAgICAgICBvbkhvdmVyKGZvdW5kLnVuaXRfbmFtZSk7XG4gICAgICAgIH0gZWxzZSB7XG4gICAgICAgICAgICBvbkhvdmVyKCk7XG4gICAgICAgIH1cbiAgICB9XG5cbiAgICBmdW5jdGlvbiBtb3VzZW1vdmUoKSB7XG4gICAgICAgIHZhciBtb3VzZVggPSBkMy5tb3VzZSh0aGlzKVswXTtcbiAgICAgICAgdmFyIGZvdW5kID0gaGl0RGV0ZWN0b3IuZmluZChtb3VzZVgsIDAsIDIwKTtcblxuICAgICAgICBpZiAoZm91bmQpIHtcbiAgICAgICAgICAgIGZvdW5kID0gZm91bmQuZGF0YTtcbiAgICAgICAgICAgIC8vIGNvbnNvbGUubG9nKCdmb3VuZCBob3ZlcicsIGZvdW5kKTtcbiAgICAgICAgICAgIG9uSG92ZXIoZm91bmQudW5pdF9uYW1lKTtcbiAgICAgICAgfSBlbHNlIHtcbiAgICAgICAgICAgIG9uSG92ZXIoKTtcbiAgICAgICAgfVxuICAgIH1cblxuICAgIGZ1bmN0aW9uIG1vdXNlY2xpY2soKSB7XG4gICAgICAgIHZhciBtb3VzZVggPSBkMy5tb3VzZSh0aGlzKVswXTtcbiAgICAgICAgdmFyIGZvdW5kID0gaGl0RGV0ZWN0b3IuZmluZChtb3VzZVgsIDAsIDIwKTtcblxuICAgICAgICBpZiAoZm91bmQpIHtcbiAgICAgICAgICAgIGlmIChvbkNsaWNrKSB7XG4gICAgICAgICAgICAgICAgb25DbGljayhmb3VuZC5kYXRhLnVuaXRfbmFtZSk7XG4gICAgICAgICAgICB9XG4gICAgICAgIH1cbiAgICB9XG5cbiAgICByZXR1cm4ge1xuICAgICAgICByZWRyYXc6IHJlZHJhdyxcbiAgICAgICAgaGlnaGxpZ2h0OiByZW5kZXJIb3ZlcixcbiAgICAgICAgY2xlYXJIaWdobGlnaHQ6IGNsZWFySG92ZXJcbiAgICB9XG59XG5cbmZ1bmN0aW9uIFR1cm5vdmVyQ2hhcnQocGFyYW1zKSB7XG4gICAgbGV0IHtlbGVtZW50LCBkYXRhVXJsLCBwYXJrLCBvbkNsaWNrLCBzZWFzb259ID0gcGFyYW1zO1xuICAgIGxldCBfc2Vhc29uID0gc2Vhc29uIHx8ICdzdW1tZXInO1xuXG4gICAgZWxlbWVudCA9IGQzLnNlbGVjdChlbGVtZW50KTtcblxuICAgIC8vIGNyZWF0ZSB0aGUgdGVtcGxhdGVcbiAgICBlbGVtZW50Lmh0bWwoYFxuICAgICAgICA8ZGl2IGNsYXNzPVwic2QtdHVybm92ZXItY2hhcnRcIj5cbiAgICAgICAgICAgIDxkaXYgY2xhc3M9XCJzZC1kb3QtY2hhcnRcIj5cbiAgICAgICAgICAgICAgICA8ZGl2IGlkPVwic2QtbWFpbmNoYXJ0XCI+PC9kaXY+XG4gICAgICAgICAgICAgICAgPGRpdiBjbGFzcz1cInNkLWxpbmVcIj48L2Rpdj5cbiAgICAgICAgICAgICAgICA8ZGl2IGNsYXNzPVwic2QtbGFiZWwtYXJlYVwiPlxuICAgICAgICAgICAgICAgICAgICA8aDIgY2xhc3M9XCJzZC1heGlzLWxhYmVsXCI+UG90ZW50aWFsIFR1cm5vdmVyPC9oMj5cbiAgICAgICAgICAgICAgICA8L2Rpdj5cbiAgICAgICAgICAgIDwvZGl2PlxuICAgICAgICAgICAgPGRpdj5cbiAgICAgICAgICAgICAgICA8ZGl2IGNsYXNzPVwic2Qtc3Vicm93IHNkLWxlZnRcIj5cbiAgICAgICAgICAgICAgICAgICAgPGRpdiBjbGFzcz1cInNkLWRvdC1jaGFydFwiPlxuICAgICAgICAgICAgICAgICAgICAgICAgPGRpdiBpZD1cInNkLXN1YmNoYXJ0LTFcIj48L2Rpdj5cbiAgICAgICAgICAgICAgICAgICAgICAgIDxkaXYgY2xhc3M9XCJzZC1saW5lXCI+PC9kaXY+XG4gICAgICAgICAgICAgICAgICAgICAgICA8ZGl2IGNsYXNzPVwic2QtbGFiZWwtYXJlYVwiPlxuICAgICAgICAgICAgICAgICAgICAgICAgICAgIDxoMiBjbGFzcz1cInNkLWF4aXMtbGFiZWxcIj5Qb3RlbnRpYWwgQ29sb25pemF0aW9uPC9oMj5cbiAgICAgICAgICAgICAgICAgICAgICAgIDwvZGl2PlxuICAgICAgICAgICAgICAgICAgICA8L2Rpdj5cbiAgICAgICAgICAgICAgICA8L2Rpdj5cbiAgICAgICAgICAgICAgICA8ZGl2IGNsYXNzPVwic2Qtc3Vicm93IHNkLXJpZ2h0XCI+XG4gICAgICAgICAgICAgICAgICAgIDxkaXYgY2xhc3M9XCJzZC1kb3QtY2hhcnRcIj5cbiAgICAgICAgICAgICAgICAgICAgICAgIDxkaXYgaWQ9XCJzZC1zdWJjaGFydC0yXCI+PC9kaXY+XG4gICAgICAgICAgICAgICAgICAgICAgICA8ZGl2IGNsYXNzPVwic2QtbGluZVwiPjwvZGl2PlxuICAgICAgICAgICAgICAgICAgICAgICAgPGRpdiBjbGFzcz1cInNkLWxhYmVsLWFyZWFcIj5cbiAgICAgICAgICAgICAgICAgICAgICAgICAgICA8aDIgY2xhc3M9XCJzZC1heGlzLWxhYmVsXCI+UG90ZW50aWFsIEV4dGlycGF0aW9uPC9oMj5cbiAgICAgICAgICAgICAgICAgICAgICAgIDwvZGl2PlxuICAgICAgICAgICAgICAgICAgICA8L2Rpdj5cbiAgICAgICAgICAgICAgICA8L2Rpdj5cbiAgICAgICAgICAgIDwvZGl2PlxuICAgICAgICA8L2Rpdj5cbiAgICBgKTtcblxuICAgIGxldCBkYXRhID0gW107XG4gICAgbGV0IG1haW5DaGFydCA9IG5ldyBEb3RDaGFydCh7XG4gICAgICAgIGVsZW1lbnQ6IGVsZW1lbnQuc2VsZWN0KCcjc2QtbWFpbmNoYXJ0JyksXG4gICAgICAgIHNob3dOYW1lOiB0cnVlLFxuICAgICAgICBvbkNsaWNrOiBvbkNsaWNrLFxuICAgICAgICBvbkhvdmVyOiBvbkhvdmVyLFxuICAgICAgICBzY2FsZTogJ2xpbmVhcidcbiAgICB9KTtcbiAgICBsZXQgc3ViQ2hhcnQxID0gbmV3IERvdENoYXJ0KHtcbiAgICAgICAgZWxlbWVudDogZWxlbWVudC5zZWxlY3QoJyNzZC1zdWJjaGFydC0xJyksXG4gICAgICAgIHNob3dOYW1lOiBmYWxzZSxcbiAgICAgICAgb25DbGljazogb25DbGljayxcbiAgICAgICAgb25Ib3Zlcjogb25Ib3ZlcixcbiAgICAgICAgc2NhbGU6ICdsb2cnXG4gICAgfSk7XG4gICAgbGV0IHN1YkNoYXJ0MiA9IG5ldyBEb3RDaGFydCh7XG4gICAgICAgIGVsZW1lbnQ6IGVsZW1lbnQuc2VsZWN0KCcjc2Qtc3ViY2hhcnQtMicpLFxuICAgICAgICBzaG93TmFtZTogZmFsc2UsXG4gICAgICAgIG9uQ2xpY2s6IG9uQ2xpY2ssXG4gICAgICAgIG9uSG92ZXI6IG9uSG92ZXIsXG4gICAgICAgIHNjYWxlOiAnbG9nJ1xuICAgIH0pO1xuXG4gICAgZnVuY3Rpb24gb25Ib3ZlcihuYW1lKSB7XG4gICAgICAgIGlmICghbmFtZSkge1xuICAgICAgICAgICAgbWFpbkNoYXJ0LmNsZWFySGlnaGxpZ2h0KCk7XG4gICAgICAgICAgICBzdWJDaGFydDEuY2xlYXJIaWdobGlnaHQoKTtcbiAgICAgICAgICAgIHN1YkNoYXJ0Mi5jbGVhckhpZ2hsaWdodCgpO1xuICAgICAgICAgICAgcmV0dXJuO1xuICAgICAgICB9XG5cbiAgICAgICAgbWFpbkNoYXJ0LmhpZ2hsaWdodChuYW1lKTtcbiAgICAgICAgc3ViQ2hhcnQxLmhpZ2hsaWdodChuYW1lKTtcbiAgICAgICAgc3ViQ2hhcnQyLmhpZ2hsaWdodChuYW1lKTtcbiAgICB9XG5cbiAgICBmdW5jdGlvbiByZWRyYXcoKSB7XG4gICAgICAgIG1haW5DaGFydC5yZWRyYXcoZGF0YSwgJ3R1cm5vdmVyXycgKyBfc2Vhc29uLCBwYXJrKTtcbiAgICAgICAgc3ViQ2hhcnQxLnJlZHJhdyhkYXRhLCAncHJvcF9jb2xvbml6YXRpb25zXycgKyBfc2Vhc29uLCBwYXJrKTtcbiAgICAgICAgc3ViQ2hhcnQyLnJlZHJhdyhkYXRhLCAncHJvcF9leHRpcnBhdGlvbnNfJyArIF9zZWFzb24sIHBhcmspO1xuICAgIH1cblxuICAgIGZ1bmN0aW9uIHNldFNlYXNvbihzZWFzb24pIHtcbiAgICAgICAgaWYgKHNlYXNvbiA9PT0gJ3N1bW1lcicgfHwgc2Vhc29uID09PSAnd2ludGVyJykge1xuICAgICAgICAgICAgX3NlYXNvbiA9IHNlYXNvbjtcbiAgICAgICAgICAgIHJlZHJhdygpO1xuICAgICAgICB9IGVsc2Uge1xuICAgICAgICAgICAgY29uc29sZS5sb2coJ0VSUk9SOiBzZWFzb24gbXVzdCBiZSBzdW1tZXIgb3Igd2ludGVyLCByZWNlaXZlZCcsIHNlYXNvbik7XG4gICAgICAgIH1cbiAgICB9XG5cbiAgICBkMy5jc3YoZGF0YVVybCwgKGVycm9yLCByb3dzKSA9PiB7XG4gICAgICAgIGNvbnNvbGUubG9nKGVycm9yKTtcblxuICAgICAgICAvLyBwcmVwcm9jZXNzXG4gICAgICAgIHJvd3MuZm9yRWFjaChyID0+IHtcbiAgICAgICAgICAgIHIucHJvcF9jb2xvbml6YXRpb25zX3N1bW1lciA9ICtyLnByb3BfY29sb25pemF0aW9uc19zdW1tZXI7XG4gICAgICAgICAgICByLnByb3BfY29sb25pemF0aW9uc193aW50ZXIgPSArci5wcm9wX2NvbG9uaXphdGlvbnNfd2ludGVyO1xuICAgICAgICAgICAgci5wcm9wX2V4dGlycGF0aW9uc19zdW1tZXIgPSArci5wcm9wX2V4dGlycGF0aW9uc19zdW1tZXI7XG4gICAgICAgICAgICByLnByb3BfZXh0aXJwYXRpb25zX3dpbnRlciA9ICtyLnByb3BfZXh0aXJwYXRpb25zX3dpbnRlcjtcbiAgICAgICAgICAgIHIudHVybm92ZXJfc3VtbWVyID0gK3IudHVybm92ZXJfc3VtbWVyO1xuICAgICAgICAgICAgci50dXJub3Zlcl93aW50ZXIgPSArci50dXJub3Zlcl93aW50ZXI7XG4gICAgICAgIH0pXG5cbiAgICAgICAgLy8gY29uc29sZS5sb2cocm93cyk7XG4gICAgICAgIGRhdGEgPSByb3dzO1xuXG4gICAgICAgIHJlZHJhdygpO1xuICAgICAgICB3aW5kb3cuYWRkRXZlbnRMaXN0ZW5lcihcInJlc2l6ZVwiLCByZWRyYXcpO1xuICAgIH0pO1xuXG4gICAgcmV0dXJuIHtcbiAgICAgICAgc2V0U2Vhc29uOiBzZXRTZWFzb25cbiAgICB9XG59XG5cbmV4cG9ydCB7IFR1cm5vdmVyQ2hhcnQgfTtcbiJdfQ==
