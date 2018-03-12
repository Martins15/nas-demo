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

function GridHelper(radius, spacing, numDots) {

    var _colScale = d3.scaleLinear().domain([80, 91, 109, 127]).range([5, 6, 7, 8]).clamp(true);

    function colScale(numDots) {
        return Math.floor(_colScale(numDots));
    }

    var cols = colScale(numDots);
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

function randomBirdPos() {
    return {
        x: -100 + Math.random() * 200 + 20,
        y: -300
    };
}

function generatePoints(data, gridHelper) {
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
            initPos: randomBirdPos(),
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
        finalPos.y += 10;

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
        onLoad = params.onLoad;


    var radius = 3;
    var spacing = 6;
    var gridHelper = new GridHelper(radius, spacing, numCurrent + numColonized);

    var data = generatePoints(params, gridHelper);

    var svgContainer = d3.select(element).append('svg').attr('width', 400).attr('height', 400);

    var svg = svgContainer.append('g');

    function alignDots() {
        var _ref = [gridHelper.width, gridHelper.height],
            dotBoxWidth = _ref[0],
            dotBoxHeight = _ref[1];


        var divContainer = d3.select(element);

        var divWidth = divContainer.node().offsetWidth;
        var divHeight = divContainer.node().offsetHeight;

        var offsetY = (divHeight - dotBoxHeight) / 2;
        var offsetX = (divWidth - dotBoxWidth) / 2;

        var svgOffsetY = Math.abs(parseInt(svgContainer.style('top')));
        var svgOffsetX = Math.abs(parseInt(svgContainer.style('left')));

        var translateX = offsetX + svgOffsetX;
        var translateY = offsetY + svgOffsetY;

        svg.attr('transform', 'translate(' + translateX + ', ' + translateY + ')');
    }

    alignDots();

    var colonizedInView = false;
    var extirpatedInView = false;
    var disabledOpacity = 0.2;

    var dots = svg.selectAll('.dot').data(data);
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

    // // just the separation
    // // we want to stager the movement of the

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
        setCurrent: setCurrent
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

    // none of these sholud be called until the component is ready
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

exports.BirdDots = BirdDots;

},{}],3:[function(require,module,exports){
'use strict';

var _birdDot = require('./birdDot.js');

var _turnover = require('./turnover.js');

var _parkMap = require('./parkMap.js');

window.StamenAudubonParks = {
  BirdDots: _birdDot.BirdDots,
  ParkMap: _parkMap.ParkMap,
  TurnoverChart: _turnover.TurnoverChart
};

},{"./birdDot.js":2,"./parkMap.js":4,"./turnover.js":5}],4:[function(require,module,exports){
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

    var mapPadding = 40;
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

},{"./albersBigAlaska":1}],5:[function(require,module,exports){
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

},{}]},{},[3])
//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbIm5vZGVfbW9kdWxlcy9icm93c2VyLXBhY2svX3ByZWx1ZGUuanMiLCJqcy9hbGJlcnNCaWdBbGFza2EuanMiLCJqcy9iaXJkRG90LmpzIiwianMvaW5kZXguanMiLCJqcy9wYXJrTWFwLmpzIiwianMvdHVybm92ZXIuanMiXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6IkFBQUE7Ozs7OztRQzZGZ0IsZSxHQUFBLGU7QUE3RmhCO0FBQ0E7QUFDQTs7QUFFQSxJQUFJLFlBQVksSUFBaEI7QUFDQSxTQUFTLE1BQVQsR0FBa0IsQ0FBRTtBQUNwQixJQUFJLE9BQU8sUUFBWDtBQUNBLElBQUksT0FBTyxJQUFYO0FBQ0EsSUFBSSxLQUFLLENBQUMsSUFBVjtBQUNBLElBQUksS0FBSyxFQUFUOztBQUVBLElBQUksaUJBQWlCO0FBQ25CLFNBQU8sYUFEWTtBQUVuQixhQUFXLE1BRlE7QUFHbkIsV0FBUyxNQUhVO0FBSW5CLGdCQUFjLE1BSks7QUFLbkIsY0FBWSxNQUxPO0FBTW5CLFVBQVEsa0JBQVc7QUFDakIsUUFBSSxTQUFTLENBQUMsQ0FBQyxJQUFELEVBQU8sSUFBUCxDQUFELEVBQWUsQ0FBQyxFQUFELEVBQUssRUFBTCxDQUFmLENBQWI7QUFDQSxTQUFLLEtBQUssRUFBRSxPQUFPLE9BQU8sUUFBaEIsQ0FBVjtBQUNBLFdBQU8sTUFBUDtBQUNEO0FBVmtCLENBQXJCOztBQWFBLFNBQVMsYUFBVCxDQUF1QixDQUF2QixFQUEwQixDQUExQixFQUE2QjtBQUMzQixNQUFJLElBQUksSUFBUixFQUFjLE9BQU8sQ0FBUDtBQUNkLE1BQUksSUFBSSxFQUFSLEVBQVksS0FBSyxDQUFMO0FBQ1osTUFBSSxJQUFJLElBQVIsRUFBYyxPQUFPLENBQVA7QUFDZCxNQUFJLElBQUksRUFBUixFQUFZLEtBQUssQ0FBTDtBQUNiOztBQUVELFNBQVMsR0FBVCxDQUFhLFVBQWIsRUFBeUIsU0FBekIsRUFBb0MsTUFBcEMsRUFBNEM7QUFDMUMsTUFBSSxPQUFPLFdBQVcsVUFBWCxJQUF5QixXQUFXLFVBQVgsRUFBcEM7QUFDQSxhQUFXLEtBQVgsQ0FBaUIsR0FBakIsRUFBc0IsU0FBdEIsQ0FBZ0MsQ0FBQyxDQUFELEVBQUksQ0FBSixDQUFoQztBQUNBLE1BQUksUUFBUSxJQUFaLEVBQWtCLFdBQVcsVUFBWCxDQUFzQixJQUF0QjtBQUNsQixLQUFHLFNBQUgsQ0FBYSxNQUFiLEVBQXFCLFdBQVcsTUFBWCxDQUFrQixjQUFsQixDQUFyQjtBQUNBLFlBQVUsZUFBZSxNQUFmLEVBQVY7QUFDQSxNQUFJLFFBQVEsSUFBWixFQUFrQixXQUFXLFVBQVgsQ0FBc0IsSUFBdEI7QUFDbEIsU0FBTyxVQUFQO0FBQ0Q7O0FBRUQsU0FBUyxTQUFULENBQW1CLFVBQW5CLEVBQStCLE1BQS9CLEVBQXVDLE1BQXZDLEVBQStDO0FBQzdDLFNBQU8sSUFBSSxVQUFKLEVBQWdCLFVBQVMsQ0FBVCxFQUFZO0FBQ2pDLFFBQUksSUFBSSxPQUFPLENBQVAsRUFBVSxDQUFWLElBQWUsT0FBTyxDQUFQLEVBQVUsQ0FBVixDQUF2QjtBQUFBLFFBQ0ksSUFBSSxPQUFPLENBQVAsRUFBVSxDQUFWLElBQWUsT0FBTyxDQUFQLEVBQVUsQ0FBVixDQUR2QjtBQUFBLFFBRUksSUFBSSxLQUFLLEdBQUwsQ0FBUyxLQUFLLEVBQUUsQ0FBRixFQUFLLENBQUwsSUFBVSxFQUFFLENBQUYsRUFBSyxDQUFMLENBQWYsQ0FBVCxFQUFrQyxLQUFLLEVBQUUsQ0FBRixFQUFLLENBQUwsSUFBVSxFQUFFLENBQUYsRUFBSyxDQUFMLENBQWYsQ0FBbEMsQ0FGUjtBQUFBLFFBR0ksSUFBSSxDQUFDLE9BQU8sQ0FBUCxFQUFVLENBQVYsQ0FBRCxHQUFnQixDQUFDLElBQUksS0FBSyxFQUFFLENBQUYsRUFBSyxDQUFMLElBQVUsRUFBRSxDQUFGLEVBQUssQ0FBTCxDQUFmLENBQUwsSUFBZ0MsQ0FIeEQ7QUFBQSxRQUlJLElBQUksQ0FBQyxPQUFPLENBQVAsRUFBVSxDQUFWLENBQUQsR0FBZ0IsQ0FBQyxJQUFJLEtBQUssRUFBRSxDQUFGLEVBQUssQ0FBTCxJQUFVLEVBQUUsQ0FBRixFQUFLLENBQUwsQ0FBZixDQUFMLElBQWdDLENBSnhEO0FBS0EsZUFBVyxLQUFYLENBQWlCLE1BQU0sQ0FBdkIsRUFBMEIsU0FBMUIsQ0FBb0MsQ0FBQyxDQUFELEVBQUksQ0FBSixDQUFwQztBQUNELEdBUE0sRUFPSixNQVBJLENBQVA7QUFRRDs7QUFFRCxTQUFTLE9BQVQsQ0FBaUIsVUFBakIsRUFBNkIsSUFBN0IsRUFBbUMsTUFBbkMsRUFBMkM7QUFDekMsU0FBTyxVQUFVLFVBQVYsRUFBc0IsQ0FBQyxDQUFDLENBQUQsRUFBSSxDQUFKLENBQUQsRUFBUyxJQUFULENBQXRCLEVBQXNDLE1BQXRDLENBQVA7QUFDRDs7QUFFRCxTQUFTLFFBQVQsQ0FBa0IsVUFBbEIsRUFBOEIsS0FBOUIsRUFBcUMsTUFBckMsRUFBNkM7QUFDM0MsU0FBTyxJQUFJLFVBQUosRUFBZ0IsVUFBUyxDQUFULEVBQVk7QUFDakMsUUFBSSxJQUFJLENBQUMsS0FBVDtBQUFBLFFBQ0ksSUFBSSxLQUFLLEVBQUUsQ0FBRixFQUFLLENBQUwsSUFBVSxFQUFFLENBQUYsRUFBSyxDQUFMLENBQWYsQ0FEUjtBQUFBLFFBRUksSUFBSSxDQUFDLElBQUksS0FBSyxFQUFFLENBQUYsRUFBSyxDQUFMLElBQVUsRUFBRSxDQUFGLEVBQUssQ0FBTCxDQUFmLENBQUwsSUFBZ0MsQ0FGeEM7QUFBQSxRQUdJLElBQUksQ0FBQyxDQUFELEdBQUssRUFBRSxDQUFGLEVBQUssQ0FBTCxDQUhiO0FBSUEsZUFBVyxLQUFYLENBQWlCLE1BQU0sQ0FBdkIsRUFBMEIsU0FBMUIsQ0FBb0MsQ0FBQyxDQUFELEVBQUksQ0FBSixDQUFwQztBQUNELEdBTk0sRUFNSixNQU5JLENBQVA7QUFPRDs7QUFFRCxTQUFTLFNBQVQsQ0FBbUIsVUFBbkIsRUFBK0IsTUFBL0IsRUFBdUMsTUFBdkMsRUFBK0M7QUFDN0MsU0FBTyxJQUFJLFVBQUosRUFBZ0IsVUFBUyxDQUFULEVBQVk7QUFDakMsUUFBSSxJQUFJLENBQUMsTUFBVDtBQUFBLFFBQ0ksSUFBSSxLQUFLLEVBQUUsQ0FBRixFQUFLLENBQUwsSUFBVSxFQUFFLENBQUYsRUFBSyxDQUFMLENBQWYsQ0FEUjtBQUFBLFFBRUksSUFBSSxDQUFDLENBQUQsR0FBSyxFQUFFLENBQUYsRUFBSyxDQUFMLENBRmI7QUFBQSxRQUdJLElBQUksQ0FBQyxJQUFJLEtBQUssRUFBRSxDQUFGLEVBQUssQ0FBTCxJQUFVLEVBQUUsQ0FBRixFQUFLLENBQUwsQ0FBZixDQUFMLElBQWdDLENBSHhDO0FBSUEsZUFBVyxLQUFYLENBQWlCLE1BQU0sQ0FBdkIsRUFBMEIsU0FBMUIsQ0FBb0MsQ0FBQyxDQUFELEVBQUksQ0FBSixDQUFwQztBQUNELEdBTk0sRUFNSixNQU5JLENBQVA7QUFPRDs7QUFFRCxTQUFTLFNBQVQsQ0FBbUIsT0FBbkIsRUFBNEI7QUFDMUIsTUFBSSxJQUFJLFFBQVEsTUFBaEI7QUFDQSxTQUFPO0FBQ0wsV0FBTyxlQUFTLENBQVQsRUFBWSxDQUFaLEVBQWU7QUFBRSxVQUFJLElBQUksQ0FBQyxDQUFULENBQVksT0FBTyxFQUFFLENBQUYsR0FBTSxDQUFiO0FBQWdCLGdCQUFRLENBQVIsRUFBVyxLQUFYLENBQWlCLENBQWpCLEVBQW9CLENBQXBCO0FBQWhCO0FBQXlDLEtBRHhFO0FBRUwsWUFBUSxrQkFBVztBQUFFLFVBQUksSUFBSSxDQUFDLENBQVQsQ0FBWSxPQUFPLEVBQUUsQ0FBRixHQUFNLENBQWI7QUFBZ0IsZ0JBQVEsQ0FBUixFQUFXLE1BQVg7QUFBaEI7QUFBc0MsS0FGbEU7QUFHTCxlQUFXLHFCQUFXO0FBQUUsVUFBSSxJQUFJLENBQUMsQ0FBVCxDQUFZLE9BQU8sRUFBRSxDQUFGLEdBQU0sQ0FBYjtBQUFnQixnQkFBUSxDQUFSLEVBQVcsU0FBWDtBQUFoQjtBQUF5QyxLQUh4RTtBQUlMLGFBQVMsbUJBQVc7QUFBRSxVQUFJLElBQUksQ0FBQyxDQUFULENBQVksT0FBTyxFQUFFLENBQUYsR0FBTSxDQUFiO0FBQWdCLGdCQUFRLENBQVIsRUFBVyxPQUFYO0FBQWhCO0FBQXVDLEtBSnBFO0FBS0wsa0JBQWMsd0JBQVc7QUFBRSxVQUFJLElBQUksQ0FBQyxDQUFULENBQVksT0FBTyxFQUFFLENBQUYsR0FBTSxDQUFiO0FBQWdCLGdCQUFRLENBQVIsRUFBVyxZQUFYO0FBQWhCO0FBQTRDLEtBTDlFO0FBTUwsZ0JBQVksc0JBQVc7QUFBRSxVQUFJLElBQUksQ0FBQyxDQUFULENBQVksT0FBTyxFQUFFLENBQUYsR0FBTSxDQUFiO0FBQWdCLGdCQUFRLENBQVIsRUFBVyxVQUFYO0FBQWhCO0FBQTBDO0FBTjFFLEdBQVA7QUFRRDs7QUFFRDtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ08sU0FBUyxlQUFULEdBQTJCO0FBQ2hDLE1BQUksS0FBSjtBQUFBLE1BQ0ksV0FESjtBQUFBLE1BRUksVUFBVSxHQUFHLFNBQUgsRUFGZDtBQUFBLE1BRThCLFlBRjlCO0FBQUEsTUFHSSxTQUFTLEdBQUcsaUJBQUgsR0FBdUIsTUFBdkIsQ0FBOEIsQ0FBQyxHQUFELEVBQU0sQ0FBTixDQUE5QixFQUF3QyxNQUF4QyxDQUErQyxDQUFDLENBQUMsQ0FBRixFQUFLLElBQUwsQ0FBL0MsRUFBMkQsU0FBM0QsQ0FBcUUsQ0FBQyxFQUFELEVBQUssRUFBTCxDQUFyRSxDQUhiO0FBQUEsTUFHNkYsV0FIN0Y7QUFBQSxNQUcwRztBQUN0RyxXQUFTLEdBQUcsaUJBQUgsR0FBdUIsTUFBdkIsQ0FBOEIsQ0FBQyxHQUFELEVBQU0sQ0FBTixDQUE5QixFQUF3QyxNQUF4QyxDQUErQyxDQUFDLENBQUMsQ0FBRixFQUFLLElBQUwsQ0FBL0MsRUFBMkQsU0FBM0QsQ0FBcUUsQ0FBQyxDQUFELEVBQUksRUFBSixDQUFyRSxDQUpiO0FBQUEsTUFJNEYsV0FKNUY7QUFBQSxNQUl5RztBQUNyRyxRQUxKO0FBQUEsTUFLVyxjQUFjLEVBQUMsT0FBTyxlQUFTLENBQVQsRUFBWSxDQUFaLEVBQWU7QUFBRSxlQUFRLENBQUMsQ0FBRCxFQUFJLENBQUosQ0FBUjtBQUFpQixLQUExQyxFQUx6Qjs7QUFPQSxXQUFTLFNBQVQsQ0FBbUIsV0FBbkIsRUFBZ0M7QUFDOUIsUUFBSSxJQUFJLFlBQVksQ0FBWixDQUFSO0FBQUEsUUFBd0IsSUFBSSxZQUFZLENBQVosQ0FBNUI7QUFDQSxXQUFPLFNBQVEsSUFBUixFQUFjLENBQUMsYUFBYSxLQUFiLENBQW1CLENBQW5CLEVBQXNCLENBQXRCLEdBQTBCLE1BQTNCLE1BQ2IsWUFBWSxLQUFaLENBQWtCLENBQWxCLEVBQXFCLENBQXJCLEdBQXlCLE1BRFosTUFFYixZQUFZLEtBQVosQ0FBa0IsQ0FBbEIsRUFBcUIsQ0FBckIsR0FBeUIsTUFGWixDQUFyQjtBQUdEOztBQUVELFlBQVUsTUFBVixHQUFtQixVQUFTLFdBQVQsRUFBc0I7QUFDdkMsUUFBSSxJQUFJLFFBQVEsS0FBUixFQUFSO0FBQUEsUUFDSSxJQUFJLFFBQVEsU0FBUixFQURSO0FBQUEsUUFFSSxJQUFJLENBQUMsWUFBWSxDQUFaLElBQWlCLEVBQUUsQ0FBRixDQUFsQixJQUEwQixDQUZsQztBQUFBLFFBR0ksSUFBSSxDQUFDLFlBQVksQ0FBWixJQUFpQixFQUFFLENBQUYsQ0FBbEIsSUFBMEIsQ0FIbEM7QUFJQSxXQUFPLENBQUMsS0FBSyxLQUFMLElBQWMsSUFBSSxLQUFsQixJQUEyQixLQUFLLENBQUMsS0FBakMsSUFBMEMsSUFBSSxDQUFDLEtBQS9DLEdBQXVELE1BQXZELEdBQ0YsS0FBSyxLQUFMLElBQWMsSUFBSSxLQUFsQixJQUEyQixLQUFLLENBQUMsS0FBakMsSUFBMEMsSUFBSSxDQUFDLEtBQS9DLEdBQXVELE1BQXZELEdBQ0EsT0FGQyxFQUVRLE1BRlIsQ0FFZSxXQUZmLENBQVA7QUFHRCxHQVJEOztBQVVBLFlBQVUsTUFBVixHQUFtQixVQUFTLE1BQVQsRUFBaUI7QUFDbEMsV0FBTyxTQUFTLGdCQUFnQixNQUF6QixHQUFrQyxLQUFsQyxHQUEwQyxRQUFRLFVBQVUsQ0FBQyxRQUFRLE1BQVIsQ0FBZSxjQUFjLE1BQTdCLENBQUQsRUFBdUMsT0FBTyxNQUFQLENBQWMsTUFBZCxDQUF2QyxFQUE4RCxPQUFPLE1BQVAsQ0FBYyxNQUFkLENBQTlELENBQVYsQ0FBekQ7QUFDRCxHQUZEOztBQUlBLFlBQVUsU0FBVixHQUFzQixVQUFTLENBQVQsRUFBWTtBQUNoQyxRQUFJLENBQUMsVUFBVSxNQUFmLEVBQXVCLE9BQU8sUUFBUSxTQUFSLEVBQVA7QUFDdkIsWUFBUSxTQUFSLENBQWtCLENBQWxCLEdBQXNCLE9BQU8sU0FBUCxDQUFpQixDQUFqQixDQUF0QixFQUEyQyxPQUFPLFNBQVAsQ0FBaUIsQ0FBakIsQ0FBM0M7QUFDQSxXQUFPLE9BQVA7QUFDRCxHQUpEOztBQU1BLFlBQVUsS0FBVixHQUFrQixVQUFTLENBQVQsRUFBWTtBQUM1QixRQUFJLENBQUMsVUFBVSxNQUFmLEVBQXVCLE9BQU8sUUFBUSxLQUFSLEVBQVA7QUFDdkIsWUFBUSxLQUFSLENBQWMsQ0FBZCxHQUFrQixPQUFPLEtBQVAsQ0FBYSxJQUFJLElBQWpCLENBQWxCLEVBQTBDLE9BQU8sS0FBUCxDQUFhLENBQWIsQ0FBMUM7QUFDQSxXQUFPLFVBQVUsU0FBVixDQUFvQixRQUFRLFNBQVIsRUFBcEIsQ0FBUDtBQUNELEdBSkQ7O0FBTUEsWUFBVSxTQUFWLEdBQXNCLFVBQVMsQ0FBVCxFQUFZO0FBQ2hDLFFBQUksQ0FBQyxVQUFVLE1BQWYsRUFBdUIsT0FBTyxRQUFRLFNBQVIsRUFBUDtBQUN2QixRQUFJLElBQUksUUFBUSxLQUFSLEVBQVI7QUFBQSxRQUF5QixJQUFJLENBQUMsRUFBRSxDQUFGLENBQTlCO0FBQUEsUUFBb0MsSUFBSSxDQUFDLEVBQUUsQ0FBRixDQUF6Qzs7QUFFQSxtQkFBZSxRQUNWLFNBRFUsQ0FDQSxDQURBLEVBRVYsVUFGVSxDQUVDLENBQUMsQ0FBQyxJQUFJLFFBQVEsQ0FBYixFQUFnQixJQUFJLFFBQVEsQ0FBNUIsQ0FBRCxFQUFpQyxDQUFDLElBQUksUUFBUSxDQUFiLEVBQWdCLElBQUksUUFBUSxDQUE1QixDQUFqQyxDQUZELEVBR1YsTUFIVSxDQUdILFdBSEcsQ0FBZjs7QUFLQSxrQkFBYyxPQUNULFNBRFMsQ0FDQyxDQUFDLElBQUksUUFBUSxDQUFiLEVBQWdCLElBQUksUUFBUSxDQUE1QixDQURELEVBRVQsVUFGUyxDQUVFLENBQUMsQ0FBQyxJQUFJLFFBQVEsQ0FBWixHQUFnQixTQUFqQixFQUE0QixJQUFJLFFBQVEsQ0FBWixHQUFnQixTQUE1QyxDQUFELEVBQXlELENBQUMsSUFBSSxRQUFRLENBQVosR0FBZ0IsU0FBakIsRUFBNEIsSUFBSSxRQUFRLENBQVosR0FBZ0IsU0FBNUMsQ0FBekQsQ0FGRixFQUdULE1BSFMsQ0FHRixXQUhFLENBQWQ7O0FBS0Esa0JBQWMsT0FDVCxTQURTLENBQ0MsQ0FBQyxJQUFJLFFBQVEsQ0FBYixFQUFnQixJQUFJLFFBQVEsQ0FBNUIsQ0FERCxFQUVULFVBRlMsQ0FFRSxDQUFDLENBQUMsSUFBSSxRQUFRLENBQVosR0FBZ0IsU0FBakIsRUFBNEIsSUFBSSxRQUFRLENBQVosR0FBZ0IsU0FBNUMsQ0FBRCxFQUF5RCxDQUFDLElBQUksUUFBUSxDQUFaLEdBQWdCLFNBQWpCLEVBQTRCLElBQUksUUFBUSxDQUFaLEdBQWdCLFNBQTVDLENBQXpELENBRkYsRUFHVCxNQUhTLENBR0YsV0FIRSxDQUFkOztBQUtBLFdBQU8sT0FBUDtBQUNELEdBcEJEOztBQXNCQSxZQUFVLFNBQVYsR0FBc0IsVUFBUyxNQUFULEVBQWlCLE1BQWpCLEVBQXlCO0FBQzdDLFdBQU8sVUFBVSxTQUFWLEVBQXFCLE1BQXJCLEVBQTZCLE1BQTdCLENBQVA7QUFDRCxHQUZEOztBQUlBLFlBQVUsT0FBVixHQUFvQixVQUFTLElBQVQsRUFBZSxNQUFmLEVBQXVCO0FBQ3pDLFdBQU8sUUFBUSxTQUFSLEVBQW1CLElBQW5CLEVBQXlCLE1BQXpCLENBQVA7QUFDRCxHQUZEOztBQUlBLFlBQVUsUUFBVixHQUFxQixVQUFTLEtBQVQsRUFBZ0IsTUFBaEIsRUFBd0I7QUFDM0MsV0FBTyxTQUFTLFNBQVQsRUFBb0IsS0FBcEIsRUFBMkIsTUFBM0IsQ0FBUDtBQUNELEdBRkQ7O0FBSUEsWUFBVSxTQUFWLEdBQXNCLFVBQVMsTUFBVCxFQUFpQixNQUFqQixFQUF5QjtBQUM3QyxXQUFPLFVBQVUsU0FBVixFQUFxQixNQUFyQixFQUE2QixNQUE3QixDQUFQO0FBQ0QsR0FGRDs7QUFJQSxXQUFTLEtBQVQsR0FBaUI7QUFDZixZQUFRLGNBQWMsSUFBdEI7QUFDQSxXQUFPLFNBQVA7QUFDRDs7QUFFRCxTQUFPLFVBQVUsS0FBVixDQUFnQixJQUFoQixDQUFQO0FBQ0Q7Ozs7Ozs7O0FDbExEOzs7QUFHQSxTQUFTLFlBQVQsQ0FBc0IsT0FBdEIsRUFBK0IsS0FBL0IsRUFBc0MsR0FBdEMsRUFBMkMsUUFBM0MsRUFBcUQ7QUFDakQ7QUFDQSxRQUFNLGVBQWUsR0FBRyxpQkFBSCxDQUFxQixLQUFyQixFQUE0QixHQUE1QixDQUFyQjtBQUNBLFFBQUksdUJBQUo7O0FBRUEsYUFBUyxhQUFULENBQXVCLE9BQXZCLEVBQWdDO0FBQzlCLFlBQU0sT0FBTyxVQUFVLFFBQXZCO0FBQ0EsWUFBSSxRQUFRLENBQVosRUFBZTtBQUNiLDJCQUFlLElBQWY7QUFDQTtBQUNEO0FBQ0QsWUFBSSxNQUFNLEtBQUssS0FBTCxDQUFXLGFBQWEsR0FBRyxhQUFILENBQWlCLElBQWpCLENBQWIsQ0FBWCxDQUFWO0FBQ0EsZ0JBQVEsSUFBUixDQUFhLEdBQWI7QUFDRDs7QUFFRCxxQkFBaUIsR0FBRyxLQUFILENBQVMsYUFBVCxDQUFqQjtBQUNIOztBQUlELFNBQVMsVUFBVCxDQUFvQixNQUFwQixFQUE0QixPQUE1QixFQUFxQyxPQUFyQyxFQUE4Qzs7QUFHMUMsUUFBSSxZQUFZLEdBQUcsV0FBSCxHQUNYLE1BRFcsQ0FDSixDQUFDLEVBQUQsRUFBSyxFQUFMLEVBQVMsR0FBVCxFQUFjLEdBQWQsQ0FESSxFQUVYLEtBRlcsQ0FFTCxDQUFDLENBQUQsRUFBSSxDQUFKLEVBQU8sQ0FBUCxFQUFVLENBQVYsQ0FGSyxFQUdYLEtBSFcsQ0FHTCxJQUhLLENBQWhCOztBQUtBLGFBQVMsUUFBVCxDQUFrQixPQUFsQixFQUEyQjtBQUN2QixlQUFPLEtBQUssS0FBTCxDQUFXLFVBQVUsT0FBVixDQUFYLENBQVA7QUFDSDs7QUFFRCxRQUFJLE9BQU8sU0FBUyxPQUFULENBQVg7QUFDQSxRQUFJLFVBQVUsS0FBSyxJQUFMLENBQVUsVUFBVSxJQUFwQixDQUFkO0FBQ0EsUUFBSSxTQUFTLFVBQVUsSUFBVixHQUFpQixPQUE5Qjs7QUFFQSxhQUFTLFlBQVQsQ0FBc0IsR0FBdEIsRUFBMkI7QUFDdkIsZUFBTyxNQUFQO0FBQ0EsWUFBSSxNQUFNLEtBQUssS0FBTCxDQUFXLE1BQU0sSUFBakIsQ0FBVjtBQUNBLFlBQUksTUFBTSxNQUFPLE1BQU0sSUFBdkI7O0FBRUEsZUFBTztBQUNILGVBQUcsTUFBTSxPQUROO0FBRUgsZUFBRyxNQUFNO0FBRk4sU0FBUDtBQUlIOztBQUVELFFBQUksUUFBUSxPQUFPLE9BQW5CO0FBQ0EsUUFBSSxTQUFTLFVBQVUsT0FBdkI7O0FBRUEsV0FBTztBQUNILHNCQUFjLFlBRFg7QUFFSCxnQkFBUSxNQUZMO0FBR0gsZUFBTztBQUhKLEtBQVA7QUFLSDs7QUFHRCxTQUFTLGFBQVQsR0FBeUI7QUFDckIsV0FBTztBQUNILFdBQUcsQ0FBQyxHQUFELEdBQU8sS0FBSyxNQUFMLEtBQWdCLEdBQXZCLEdBQTZCLEVBRDdCO0FBRUgsV0FBRyxDQUFDO0FBRkQsS0FBUDtBQUlIOztBQUVELFNBQVMsY0FBVCxDQUF3QixJQUF4QixFQUE4QixVQUE5QixFQUEwQztBQUFBLFFBQzlCLFlBRDhCLEdBQ2MsSUFEZCxDQUM5QixZQUQ4QjtBQUFBLFFBQ2hCLFVBRGdCLEdBQ2MsSUFEZCxDQUNoQixVQURnQjtBQUFBLFFBQ0osYUFESSxHQUNjLElBRGQsQ0FDSixhQURJOztBQUV0QyxRQUFJLGVBQWUsYUFBYSxhQUFoQzs7QUFFQSxRQUFJLFNBQVM7QUFDVCxtQkFBVyxTQURGO0FBRVQsaUJBQVMsU0FGQTtBQUdULG9CQUFZO0FBSEgsS0FBYjs7QUFNQSxRQUFJLEtBQUssR0FBRyxLQUFILENBQVMsWUFBVCxFQUF1QixHQUF2QixDQUEyQixhQUFLO0FBQ3JDLGVBQU87QUFDSCxxQkFBUyxlQUROO0FBRUgsc0JBQVUsV0FBVyxZQUFYLENBQXdCLENBQXhCLENBRlA7QUFHSCxtQkFBTyxHQUhKO0FBSUgsNkJBQWlCLENBSmQ7QUFLSCxzQkFBVSxPQUFPLFNBTGQ7QUFNSCw4QkFBa0IsQ0FOZjtBQU9ILHVCQUFXLE9BQU87QUFQZixTQUFQO0FBU0gsS0FWUSxDQUFUOztBQVlBLFFBQUksS0FBSyxHQUFHLEtBQUgsQ0FBUyxZQUFULEVBQXVCLEdBQXZCLENBQTJCLGFBQUs7QUFDckMsZUFBTztBQUNILHFCQUFTLFdBQVcsWUFBWCxDQUF3QixJQUFJLFlBQTVCLENBRE47QUFFSCxzQkFBVSxXQUFXLFlBQVgsQ0FBd0IsSUFBSSxZQUE1QixDQUZQO0FBR0gsbUJBQU8sR0FISjtBQUlILDZCQUFpQixDQUpkO0FBS0gsc0JBQVUsT0FBTyxPQUxkO0FBTUgsOEJBQWtCLENBTmY7QUFPSCx1QkFBVyxPQUFPO0FBUGYsU0FBUDtBQVNILEtBVlEsQ0FBVDs7QUFZQSxRQUFJLEtBQUssR0FBRyxLQUFILENBQVMsYUFBVCxFQUF3QixHQUF4QixDQUE0QixhQUFLO0FBQ3RDLFlBQUksV0FBVyxXQUFXLFlBQVgsQ0FBd0IsSUFBSSxZQUFKLEdBQW1CLFlBQTNDLENBQWY7QUFDQSxpQkFBUyxDQUFULElBQWMsRUFBZDs7QUFFQSxlQUFPO0FBQ0gscUJBQVMsV0FBVyxZQUFYLENBQXdCLElBQUksWUFBSixHQUFtQixZQUEzQyxDQUROO0FBRUgsc0JBQVUsUUFGUDtBQUdILG1CQUFPLEdBSEo7QUFJSCw2QkFBaUIsQ0FKZDtBQUtILHNCQUFVLE9BQU8sT0FMZDtBQU1ILDhCQUFrQixDQU5mO0FBT0gsdUJBQVcsT0FBTztBQVBmLFNBQVA7QUFTSCxLQWJRLENBQVQ7O0FBZUEsV0FBTyxHQUFHLE1BQUgsQ0FBVSxFQUFWLEVBQWMsTUFBZCxDQUFxQixFQUFyQixDQUFQO0FBRUg7O0FBRUQsU0FBUyxTQUFULENBQW1CLE1BQW5CLEVBQTJCO0FBQ3ZCO0FBRHVCLFFBRWYsT0FGZSxHQUc0QixNQUg1QixDQUVmLE9BRmU7QUFBQSxRQUVOLFlBRk0sR0FHNEIsTUFINUIsQ0FFTixZQUZNO0FBQUEsUUFFUSxVQUZSLEdBRzRCLE1BSDVCLENBRVEsVUFGUjtBQUFBLFFBRW9CLGFBRnBCLEdBRzRCLE1BSDVCLENBRW9CLGFBRnBCO0FBQUEsUUFHbkIsZ0JBSG1CLEdBRzRCLE1BSDVCLENBR25CLGdCQUhtQjtBQUFBLFFBR0QsaUJBSEMsR0FHNEIsTUFINUIsQ0FHRCxpQkFIQztBQUFBLFFBR2tCLE1BSGxCLEdBRzRCLE1BSDVCLENBR2tCLE1BSGxCOzs7QUFLdkIsUUFBSSxTQUFTLENBQWI7QUFDQSxRQUFJLFVBQVUsQ0FBZDtBQUNBLFFBQUksYUFBYSxJQUFJLFVBQUosQ0FBZSxNQUFmLEVBQXVCLE9BQXZCLEVBQWdDLGFBQWEsWUFBN0MsQ0FBakI7O0FBRUEsUUFBSSxPQUFPLGVBQWUsTUFBZixFQUF1QixVQUF2QixDQUFYOztBQUVBLFFBQUksZUFBZSxHQUFHLE1BQUgsQ0FBVSxPQUFWLEVBQ2QsTUFEYyxDQUNQLEtBRE8sRUFFVixJQUZVLENBRUwsT0FGSyxFQUVJLEdBRkosRUFHVixJQUhVLENBR0wsUUFISyxFQUdLLEdBSEwsQ0FBbkI7O0FBS0EsUUFBSSxNQUFNLGFBQWEsTUFBYixDQUFvQixHQUFwQixDQUFWOztBQUVBLGFBQVMsU0FBVCxHQUFxQjtBQUFBLG1CQUNpQixDQUFDLFdBQVcsS0FBWixFQUFtQixXQUFXLE1BQTlCLENBRGpCO0FBQUEsWUFDWixXQURZO0FBQUEsWUFDQyxZQUREOzs7QUFHakIsWUFBSSxlQUFlLEdBQUcsTUFBSCxDQUFVLE9BQVYsQ0FBbkI7O0FBRUEsWUFBSSxXQUFXLGFBQWEsSUFBYixHQUFvQixXQUFuQztBQUNBLFlBQUksWUFBWSxhQUFhLElBQWIsR0FBb0IsWUFBcEM7O0FBRUEsWUFBSSxVQUFVLENBQUMsWUFBWSxZQUFiLElBQTZCLENBQTNDO0FBQ0EsWUFBSSxVQUFVLENBQUMsV0FBVyxXQUFaLElBQTJCLENBQXpDOztBQUVBLFlBQUksYUFBYSxLQUFLLEdBQUwsQ0FBUyxTQUFTLGFBQWEsS0FBYixDQUFtQixLQUFuQixDQUFULENBQVQsQ0FBakI7QUFDQSxZQUFJLGFBQWEsS0FBSyxHQUFMLENBQVMsU0FBUyxhQUFhLEtBQWIsQ0FBbUIsTUFBbkIsQ0FBVCxDQUFULENBQWpCOztBQUVBLFlBQUksYUFBYSxVQUFVLFVBQTNCO0FBQ0EsWUFBSSxhQUFhLFVBQVUsVUFBM0I7O0FBRUEsWUFBSSxJQUFKLENBQVMsV0FBVCxpQkFBbUMsVUFBbkMsVUFBa0QsVUFBbEQ7QUFDSDs7QUFFRDs7QUFFQSxRQUFJLGtCQUFrQixLQUF0QjtBQUNBLFFBQUksbUJBQW1CLEtBQXZCO0FBQ0EsUUFBSSxrQkFBa0IsR0FBdEI7O0FBRUEsUUFBSSxPQUFPLElBQUksU0FBSixDQUFjLE1BQWQsRUFBc0IsSUFBdEIsQ0FBMkIsSUFBM0IsQ0FBWDtBQUNBLFNBQUssS0FBTCxHQUNLLE1BREwsQ0FDWSxRQURaLEVBRUssSUFGTCxDQUVVLE9BRlYsRUFFbUIsS0FGbkIsRUFHSyxPQUhMLENBR2EsR0FIYixFQUdpQjtBQUFBLGVBQUssRUFBRSxLQUFGLElBQVcsR0FBaEI7QUFBQSxLQUhqQixFQUlLLE9BSkwsQ0FJYSxHQUpiLEVBSWtCO0FBQUEsZUFBSyxFQUFFLEtBQUYsSUFBVyxHQUFoQjtBQUFBLEtBSmxCLEVBS0ssT0FMTCxDQUthLEdBTGIsRUFLa0I7QUFBQSxlQUFLLEVBQUUsS0FBRixJQUFXLEdBQWhCO0FBQUEsS0FMbEIsRUFNSyxJQU5MLENBTVUsSUFOVixFQU1nQjtBQUFBLGVBQUssRUFBRSxPQUFGLENBQVUsQ0FBZjtBQUFBLEtBTmhCLEVBT0ssSUFQTCxDQU9VLElBUFYsRUFPZ0I7QUFBQSxlQUFLLEVBQUUsT0FBRixDQUFVLENBQWY7QUFBQSxLQVBoQixFQVFLLElBUkwsQ0FRVSxHQVJWLEVBUWUsTUFSZixFQVNLLElBVEwsQ0FTVSxjQVRWLEVBUzBCO0FBQUEsZUFBSyxFQUFFLGVBQVA7QUFBQSxLQVQxQixFQVVLLElBVkwsQ0FVVSxNQVZWLEVBVWtCO0FBQUEsZUFBSyxFQUFFLFFBQVA7QUFBQSxLQVZsQjs7QUFZQTtBQUNBOztBQUVBLGFBQVMsY0FBVCxDQUF3QixVQUF4QixFQUFvQztBQUNoQyxZQUFJLElBQUksWUFBUjtBQUNBLFlBQUksU0FBSixDQUFjLFFBQWQsRUFDSyxPQURMLENBQ2EsYUFEYixFQUM0QixJQUQ1QixFQUVLLFVBRkwsR0FHSyxJQUhMLENBR1UsR0FBRyxhQUhiLEVBSUssUUFKTCxDQUljLFVBQUMsQ0FBRCxFQUFJLENBQUo7QUFBQSxtQkFBVSxLQUFLLE1BQUwsS0FBZ0IsR0FBaEIsR0FBc0IsR0FBaEM7QUFBQSxTQUpkLEVBS0ssS0FMTCxDQUtXLFVBQUMsQ0FBRCxFQUFJLENBQUo7QUFBQSxtQkFBVSxDQUFDLGVBQWUsQ0FBaEIsSUFBcUIsRUFBL0I7QUFBQSxTQUxYLEVBTUssSUFOTCxDQU1VLElBTlYsRUFNZ0I7QUFBQSxtQkFBSyxFQUFFLFFBQUYsQ0FBVyxDQUFoQjtBQUFBLFNBTmhCLEVBT0ssSUFQTCxDQU9VLElBUFYsRUFPZ0I7QUFBQSxtQkFBSyxFQUFFLFFBQUYsQ0FBVyxDQUFoQjtBQUFBLFNBUGhCLEVBUUssSUFSTCxDQVFVLGNBUlYsRUFRMEI7QUFBQSxtQkFBSyxFQUFFLGdCQUFQO0FBQUEsU0FSMUIsRUFTSyxJQVRMLENBU1UsTUFUVixFQVNrQjtBQUFBLG1CQUFLLEVBQUUsU0FBUDtBQUFBLFNBVGxCLEVBVUssRUFWTCxDQVVRLEtBVlIsRUFVZSxVQUFDLENBQUQsRUFBSSxDQUFKLEVBQVU7QUFDakI7QUFDQSxnQkFBSSxLQUFLLENBQVQsRUFBWTtBQUNSLG9CQUFJLFVBQUosRUFBZ0I7QUFDWjtBQUNIO0FBQ0o7QUFDSixTQWpCTDtBQWtCQSwwQkFBa0IsSUFBbEI7QUFDSDs7QUFFRCxhQUFTLGFBQVQsQ0FBdUIsVUFBdkIsRUFBbUM7QUFDL0IsWUFBSSxJQUFJLFlBQVI7QUFDQSxZQUFJLFNBQUosQ0FBYyxRQUFkLEVBQ0ssT0FETCxDQUNhLGFBRGIsRUFDNEIsS0FENUIsRUFFSyxVQUZMLEdBR0ssSUFITCxDQUdVLEdBQUcsYUFIYixFQUlLLFFBSkwsQ0FJYyxVQUFDLENBQUQsRUFBSSxDQUFKO0FBQUEsbUJBQVUsS0FBSyxNQUFMLEtBQWdCLEdBQWhCLEdBQXNCLEdBQWhDO0FBQUEsU0FKZCxFQUtLLEtBTEwsQ0FLVyxVQUFDLENBQUQsRUFBSSxDQUFKO0FBQUEsbUJBQVUsSUFBSSxFQUFkO0FBQUEsU0FMWCxFQU1LLElBTkwsQ0FNVSxJQU5WLEVBTWdCO0FBQUEsbUJBQUssRUFBRSxPQUFGLENBQVUsQ0FBZjtBQUFBLFNBTmhCLEVBT0ssSUFQTCxDQU9VLElBUFYsRUFPZ0I7QUFBQSxtQkFBSyxFQUFFLE9BQUYsQ0FBVSxDQUFmO0FBQUEsU0FQaEIsRUFRSyxJQVJMLENBUVUsY0FSVixFQVEwQjtBQUFBLG1CQUFLLEVBQUUsZUFBUDtBQUFBLFNBUjFCLEVBU0ssSUFUTCxDQVNVLE1BVFYsRUFTa0I7QUFBQSxtQkFBSyxFQUFFLFFBQVA7QUFBQSxTQVRsQixFQVVLLEVBVkwsQ0FVUSxLQVZSLEVBVWUsVUFBQyxDQUFELEVBQUksQ0FBSixFQUFVO0FBQ2pCO0FBQ0EsZ0JBQUksS0FBSyxDQUFULEVBQVk7QUFDUixvQkFBSSxVQUFKLEVBQWdCO0FBQ1o7QUFDSDtBQUNKO0FBQ0osU0FqQkw7QUFrQkEsMEJBQWtCLEtBQWxCO0FBQ0g7O0FBRUQsYUFBUyxlQUFULENBQXlCLFVBQXpCLEVBQXFDO0FBQ2pDLFlBQUksSUFBSSxhQUFSO0FBQ0EsWUFBSSxTQUFKLENBQWMsUUFBZCxFQUNLLE9BREwsQ0FDYSxvQkFEYixFQUNtQyxJQURuQyxFQUVLLFVBRkwsR0FHSyxRQUhMLENBR2MsVUFBQyxDQUFELEVBQUksQ0FBSjtBQUFBLG1CQUFVLEtBQUssTUFBTCxLQUFnQixHQUFoQixHQUFzQixHQUFoQztBQUFBLFNBSGQsRUFJSyxLQUpMLENBSVcsVUFBQyxDQUFELEVBQUksQ0FBSjtBQUFBLG1CQUFVLENBQUMsZ0JBQWdCLENBQWpCLElBQXNCLEVBQWhDO0FBQUEsU0FKWCxFQUtLLElBTEwsQ0FLVSxJQUxWLEVBS2dCO0FBQUEsbUJBQUssRUFBRSxRQUFGLENBQVcsQ0FBaEI7QUFBQSxTQUxoQixFQU1LLElBTkwsQ0FNVSxJQU5WLEVBTWdCO0FBQUEsbUJBQUssRUFBRSxRQUFGLENBQVcsQ0FBaEI7QUFBQSxTQU5oQixFQU9LLElBUEwsQ0FPVSxNQVBWLEVBT2tCO0FBQUEsbUJBQUssRUFBRSxTQUFQO0FBQUEsU0FQbEIsRUFRSyxFQVJMLENBUVEsS0FSUixFQVFlLFVBQUMsQ0FBRCxFQUFJLENBQUosRUFBVTtBQUNqQjtBQUNBLGdCQUFJLEtBQUssQ0FBVCxFQUFZO0FBQ1Isb0JBQUksVUFBSixFQUFnQjtBQUNaO0FBQ0g7QUFDSjtBQUNKLFNBZkw7QUFnQkEsMkJBQW1CLElBQW5CO0FBQ0g7O0FBRUQsYUFBUyxjQUFULENBQXdCLFVBQXhCLEVBQW9DO0FBQ2hDLFlBQUksSUFBSSxhQUFSO0FBQ0EsWUFBSSxTQUFKLENBQWMsUUFBZCxFQUNLLFVBREwsR0FFSyxRQUZMLENBRWMsVUFBQyxDQUFELEVBQUksQ0FBSjtBQUFBLG1CQUFVLEtBQUssTUFBTCxLQUFnQixHQUFoQixHQUFzQixHQUFoQztBQUFBLFNBRmQsRUFHSyxLQUhMLENBR1csVUFBQyxDQUFELEVBQUksQ0FBSjtBQUFBLG1CQUFVLElBQUksRUFBZDtBQUFBLFNBSFgsRUFJSyxJQUpMLENBSVUsSUFKVixFQUlnQjtBQUFBLG1CQUFLLEVBQUUsT0FBRixDQUFVLENBQWY7QUFBQSxTQUpoQixFQUtLLElBTEwsQ0FLVSxJQUxWLEVBS2dCO0FBQUEsbUJBQUssRUFBRSxPQUFGLENBQVUsQ0FBZjtBQUFBLFNBTGhCLEVBTUssSUFOTCxDQU1VLE1BTlYsRUFNa0I7QUFBQSxtQkFBSyxFQUFFLFFBQVA7QUFBQSxTQU5sQixFQU9LLEVBUEwsQ0FPUSxLQVBSLEVBT2UsVUFBQyxDQUFELEVBQUksQ0FBSixFQUFVO0FBQ2pCO0FBQ0EsZ0JBQUksS0FBSyxDQUFULEVBQVk7QUFDUixvQkFBSSxVQUFKLEVBQWdCO0FBQ1o7QUFDSDtBQUNKO0FBQ0osU0FkTDtBQWVBLDJCQUFtQixLQUFuQjtBQUNIOztBQUVELGFBQVMsTUFBVCxDQUFnQixTQUFoQixFQUEyQjtBQUN2QixrQkFDSyxVQURMLEdBRUssUUFGTCxDQUVjLFVBQUMsQ0FBRCxFQUFJLENBQUo7QUFBQSxtQkFBVSxLQUFLLE1BQUwsS0FBZ0IsR0FBaEIsR0FBc0IsR0FBaEM7QUFBQSxTQUZkLEVBR0ssSUFITCxDQUdVLElBSFYsRUFHZ0I7QUFBQSxtQkFBSyxFQUFFLFFBQUYsQ0FBVyxDQUFYLEdBQWUsQ0FBcEI7QUFBQSxTQUhoQixFQUlLLFVBSkwsR0FLSyxRQUxMLENBS2MsR0FMZCxFQU1LLElBTkwsQ0FNVSxJQU5WLEVBTWdCO0FBQUEsbUJBQUssRUFBRSxRQUFGLENBQVcsQ0FBaEI7QUFBQSxTQU5oQjtBQU9IOztBQUVELGFBQVMsbUJBQVQsR0FBK0I7QUFDM0IsWUFBSSxTQUFKLENBQWMsUUFBZCxFQUF3QixJQUF4QixDQUE2QixNQUE3QjtBQUNIOztBQUVELGFBQVMsc0JBQVQsR0FBa0M7QUFDOUIsWUFBSSxTQUFKLENBQWMsUUFBZCxFQUF3QixJQUF4QixDQUE2QixNQUE3QjtBQUNIOztBQUVELGFBQVMsU0FBVCxHQUFxQjtBQUNqQixxQkFBYSxHQUFHLE1BQUgsQ0FBVSxnQkFBVixDQUFiLEVBQTBDLENBQTFDLEVBQTZDLFlBQTdDLEVBQTJELElBQTNEO0FBQ0EsdUJBQWUsWUFBTTtBQUNqQix5QkFBYSxHQUFHLE1BQUgsQ0FBVSxpQkFBVixDQUFiLEVBQTJDLENBQTNDLEVBQThDLGFBQTlDLEVBQTZELElBQTdEO0FBQ0EsNEJBQWdCLFlBQU07QUFDbEIsb0JBQUksTUFBSixFQUFZO0FBQ1IsK0JBQVc7QUFBQSwrQkFBTSxRQUFOO0FBQUEscUJBQVgsRUFBMkIsSUFBM0I7QUFDSDtBQUNKLGFBSkQ7QUFLSCxTQVBEO0FBU0g7QUFDRCxhQUFTLFVBQVQsR0FBc0I7QUFDbEIsWUFBSSxtQkFBbUIsZ0JBQXZCLEVBQXlDO0FBQ3JDO0FBQ0E7QUFDQTtBQUNIO0FBQ0o7O0FBRUQsYUFBUyxZQUFULEdBQXdCO0FBQ3BCLFlBQUksQ0FBQyxlQUFMLEVBQXNCO0FBQ2xCO0FBQ0gsU0FGRCxNQUVPO0FBQ0g7QUFDSDtBQUNKOztBQUVELGFBQVMsYUFBVCxHQUF5QjtBQUNyQixZQUFJLENBQUMsZ0JBQUwsRUFBdUI7QUFDbkI7QUFDSCxTQUZELE1BRU87QUFDSDtBQUNIO0FBQ0o7O0FBRUQsV0FBTztBQUNILG1CQUFXLFNBRFI7QUFFSCxhQUFLLGFBQWEsSUFBYixFQUZGO0FBR0gsc0JBQWMsWUFIWDtBQUlILG9CQUFZLFVBSlQ7QUFLSCx1QkFBZSxhQUxaO0FBTUgseUJBQWlCLGVBTmQ7QUFPSCx3QkFBZ0IsY0FQYjtBQVFILHVCQUFlLGFBUlo7QUFTSCxzQkFBYyxZQVRYO0FBVUgsb0JBQVk7QUFWVCxLQUFQO0FBWUg7O0FBRUQsU0FBUyxRQUFULENBQWtCLE1BQWxCLEVBQTBCO0FBQUEsUUFFbEIsT0FGa0IsR0FJc0IsTUFKdEIsQ0FFbEIsT0FGa0I7QUFBQSxRQUVULE9BRlMsR0FJc0IsTUFKdEIsQ0FFVCxPQUZTO0FBQUEsUUFFQSxNQUZBLEdBSXNCLE1BSnRCLENBRUEsTUFGQTtBQUFBLFFBR2xCLElBSGtCLEdBSXNCLE1BSnRCLENBR2xCLElBSGtCO0FBQUEsUUFHWixjQUhZLEdBSXNCLE1BSnRCLENBR1osY0FIWTtBQUFBLFFBR0ksZ0JBSEosR0FJc0IsTUFKdEIsQ0FHSSxnQkFISjtBQUFBLFFBSWxCLGlCQUprQixHQUlzQixNQUp0QixDQUlsQixpQkFKa0I7QUFBQSxRQUlDLE1BSkQsR0FJc0IsTUFKdEIsQ0FJQyxNQUpEO0FBQUEsUUFJUyxTQUpULEdBSXNCLE1BSnRCLENBSVMsU0FKVDs7O0FBTXRCLFFBQUksVUFBVSxNQUFkO0FBQ0EsUUFBSSxtQkFBSjtBQUFBLFFBQWdCLG1CQUFoQjtBQUNBLFFBQUksUUFBUSxLQUFaO0FBQ0EsUUFBSSxPQUFPLEdBQUcsTUFBSCxDQUFVLE9BQVYsRUFBbUIsTUFBbkIsQ0FBMEIsS0FBMUIsRUFDRSxPQURGLENBQ1Usb0JBRFYsRUFDZ0MsSUFEaEMsQ0FBWDs7QUFHQSxPQUFHLEdBQUgsQ0FBTyxPQUFQLEVBQWdCLFVBQUMsS0FBRCxFQUFRLElBQVIsRUFBaUI7QUFDN0IsWUFBSSxLQUFKLEVBQVc7QUFDUCxvQkFBUSxHQUFSLENBQVksT0FBWixFQUFxQixLQUFyQjtBQUNBO0FBQ0g7O0FBRUQsWUFBSSxVQUFVLEtBQUssSUFBTCxDQUFVO0FBQUEsbUJBQUssRUFBRSxTQUFGLElBQWUsSUFBcEI7QUFBQSxTQUFWLENBQWQ7O0FBRUEsWUFBSSxlQUFlO0FBQ2YscUJBQVMsS0FBSyxJQUFMLEVBRE07QUFFZix3QkFBWSxDQUFDLFFBQVEsc0JBRk47QUFHZiwwQkFBYyxDQUFDLFFBQVEsdUJBSFI7QUFJZiwyQkFBZSxDQUFDLFFBQVE7QUFKVCxTQUFuQjs7QUFPQSxZQUFJLGVBQWU7QUFDZixxQkFBUyxLQUFLLElBQUwsRUFETTtBQUVmLHdCQUFZLENBQUMsUUFBUSxzQkFGTjtBQUdmLDBCQUFjLENBQUMsUUFBUSx1QkFIUjtBQUlmLDJCQUFlLENBQUMsUUFBUTtBQUpULFNBQW5COztBQU9BLHFCQUFhLElBQUksU0FBSixDQUFjLFlBQWQsQ0FBYjtBQUNBLHFCQUFhLElBQUksU0FBSixDQUFjLFlBQWQsQ0FBYjs7QUFFQSxrQkFBVSxPQUFWLEVBQW1CLFNBQW5CO0FBQ0EsZ0JBQVEsSUFBUjtBQUNBLFlBQUksTUFBSixFQUFZO0FBQ1I7QUFDSDtBQUNKLEtBOUJEOztBQWdDQSxhQUFTLFNBQVQsQ0FBbUIsTUFBbkIsRUFBMkIsU0FBM0IsRUFBc0M7QUFDbEMsWUFBSSxhQUFKO0FBQ0EsWUFBSSxXQUFXLFFBQWYsRUFBeUI7QUFDckIsZUFBRyxNQUFILENBQVUsV0FBVyxHQUFyQixFQUEwQixLQUExQixDQUFnQyxTQUFoQyxFQUEyQyxDQUEzQztBQUNBLGVBQUcsTUFBSCxDQUFVLFdBQVcsR0FBckIsRUFBMEIsS0FBMUIsQ0FBZ0MsU0FBaEMsRUFBMkMsQ0FBM0M7QUFDQSxtQkFBTyxVQUFQO0FBQ0gsU0FKRCxNQUlPO0FBQ0gsZUFBRyxNQUFILENBQVUsV0FBVyxHQUFyQixFQUEwQixLQUExQixDQUFnQyxTQUFoQyxFQUEyQyxDQUEzQztBQUNBLGVBQUcsTUFBSCxDQUFVLFdBQVcsR0FBckIsRUFBMEIsS0FBMUIsQ0FBZ0MsU0FBaEMsRUFBMkMsQ0FBM0M7QUFDQSxtQkFBTyxVQUFQO0FBQ0g7QUFDRCxZQUFJLFNBQUosRUFBZTtBQUNYLGVBQUcsTUFBSCxDQUFVLGdCQUFWLEVBQTRCLElBQTVCLENBQWlDLEtBQUssWUFBdEM7QUFDQSxlQUFHLE1BQUgsQ0FBVSxpQkFBVixFQUE2QixJQUE3QixDQUFrQyxLQUFLLGFBQXZDO0FBQ0EsZUFBRyxNQUFILENBQVUsY0FBVixFQUEwQixJQUExQixDQUErQixLQUFLLFVBQXBDO0FBQ0g7QUFDSjs7QUFFRCxhQUFTLFVBQVQsQ0FBb0IsVUFBcEIsRUFBZ0M7QUFDNUI7QUFDQSxZQUFJLGFBQUo7QUFDQSxZQUFJLFlBQVksUUFBaEIsRUFBMEI7QUFDdEIsbUJBQU8sVUFBUDtBQUNILFNBRkQsTUFFTztBQUNILG1CQUFPLFVBQVA7QUFDSDs7QUFFRCxXQUFHLE1BQUgsQ0FBVSxjQUFWLEVBQTBCLElBQTFCLENBQStCLEtBQUssVUFBcEM7QUFDQSxxQkFBYSxHQUFHLE1BQUgsQ0FBVSxnQkFBVixDQUFiLEVBQTBDLENBQTFDLEVBQTZDLEtBQUssWUFBbEQsRUFBZ0UsSUFBaEU7QUFDQSxhQUFLLGNBQUwsQ0FBb0IsWUFBTTtBQUN0Qix5QkFBYSxHQUFHLE1BQUgsQ0FBVSxpQkFBVixDQUFiLEVBQTJDLENBQTNDLEVBQThDLEtBQUssYUFBbkQsRUFBa0UsSUFBbEU7QUFDQSxpQkFBSyxlQUFMLENBQXFCLFlBQU07QUFDdkIsb0JBQUksVUFBSixFQUFnQjtBQUNaLCtCQUFXO0FBQUEsK0JBQU0sWUFBTjtBQUFBLHFCQUFYLEVBQStCLElBQS9CO0FBQ0g7QUFDSixhQUpEO0FBS0gsU0FQRDtBQVFIOztBQUVELGFBQVMsU0FBVCxDQUFtQixVQUFuQixFQUErQjtBQUMzQixZQUFJLEtBQUosRUFBVztBQUNQLHVCQUFXLFVBQVg7QUFDSDtBQUNKOztBQUVELGFBQVMsT0FBVCxDQUFpQixFQUFqQixFQUFxQjtBQUNqQixXQUFHLFVBQUgsR0FDSyxRQURMLENBQ2MsR0FEZCxFQUVLLElBRkwsQ0FFVSxHQUFHLFdBRmIsRUFHSyxLQUhMLENBR1csU0FIWCxFQUdzQixDQUh0QjtBQUlIOztBQUVELGFBQVMsTUFBVCxDQUFnQixFQUFoQixFQUFvQjtBQUNoQixXQUFHLFVBQUgsR0FDSyxRQURMLENBQ2MsR0FEZCxFQUVLLEtBRkwsQ0FFVyxHQUZYLEVBR0ssSUFITCxDQUdVLEdBQUcsV0FIYixFQUlLLEtBSkwsQ0FJVyxTQUpYLEVBSXNCLENBSnRCO0FBS0g7O0FBRUQsYUFBUyxTQUFULENBQW1CLE1BQW5CLEVBQTJCO0FBQ3ZCLFlBQUksV0FBVyxPQUFmLEVBQXdCO0FBQ3BCO0FBQ0g7O0FBRUQsa0JBQVUsTUFBVjs7QUFFQSxZQUFJLENBQUMsS0FBTCxFQUFZO0FBQ1I7QUFDSDs7QUFFRCxZQUFJLFdBQVcsUUFBZixFQUF5QjtBQUNyQixlQUFHLE1BQUgsQ0FBVSxXQUFXLEdBQXJCLEVBQTBCLElBQTFCLENBQStCLE9BQS9CO0FBQ0EsZUFBRyxNQUFILENBQVUsV0FBVyxHQUFyQixFQUEwQixJQUExQixDQUErQixNQUEvQjs7QUFFQSxlQUFHLE1BQUgsQ0FBVSxnQkFBVixFQUE0QixJQUE1QixDQUFpQyxXQUFXLFlBQTVDO0FBQ0EsZUFBRyxNQUFILENBQVUsaUJBQVYsRUFBNkIsSUFBN0IsQ0FBa0MsV0FBVyxhQUE3QztBQUNBLGVBQUcsTUFBSCxDQUFVLGNBQVYsRUFBMEIsSUFBMUIsQ0FBK0IsV0FBVyxVQUExQztBQUNILFNBUEQsTUFPTztBQUNILGVBQUcsTUFBSCxDQUFVLFdBQVcsR0FBckIsRUFBMEIsSUFBMUIsQ0FBK0IsT0FBL0I7QUFDQSxlQUFHLE1BQUgsQ0FBVSxXQUFXLEdBQXJCLEVBQTBCLElBQTFCLENBQStCLE1BQS9COztBQUVBLGVBQUcsTUFBSCxDQUFVLGdCQUFWLEVBQTRCLElBQTVCLENBQWlDLFdBQVcsWUFBNUM7QUFDQSxlQUFHLE1BQUgsQ0FBVSxpQkFBVixFQUE2QixJQUE3QixDQUFrQyxXQUFXLGFBQTdDO0FBQ0EsZUFBRyxNQUFILENBQVUsY0FBVixFQUEwQixJQUExQixDQUErQixXQUFXLFVBQTFDO0FBQ0g7QUFDSjs7QUFFRDtBQUNBLGFBQVMsYUFBVCxHQUF5QjtBQUNyQixZQUFJLENBQUMsS0FBTCxFQUFZO0FBQ1I7QUFDSDs7QUFFRCxtQkFBVyxhQUFYO0FBQ0EsbUJBQVcsYUFBWDtBQUNIOztBQUVELGFBQVMsVUFBVCxHQUFzQjtBQUNsQixZQUFJLENBQUMsS0FBTCxFQUFZO0FBQ1I7QUFDSDs7QUFFRCxtQkFBVyxVQUFYO0FBQ0EsbUJBQVcsVUFBWDtBQUNIOztBQUVELGFBQVMsWUFBVCxHQUF3QjtBQUNwQixZQUFJLENBQUMsS0FBTCxFQUFZO0FBQ1I7QUFDSDs7QUFFRCxtQkFBVyxZQUFYO0FBQ0EsbUJBQVcsWUFBWDtBQUNIOztBQUVELFdBQU87QUFDSCxtQkFBVyxTQURSO0FBRUgsbUJBQVcsU0FGUjtBQUdILHVCQUFlLGFBSFo7QUFJSCxzQkFBYyxZQUpYO0FBS0gsb0JBQVk7QUFMVCxLQUFQO0FBT0g7O1FBRVEsUSxHQUFBLFE7Ozs7O0FDemZUOztBQUNBOztBQUNBOztBQUVBLE9BQU8sa0JBQVAsR0FBNEI7QUFDMUIsNkJBRDBCO0FBRTFCLDJCQUYwQjtBQUcxQjtBQUgwQixDQUE1Qjs7Ozs7Ozs7Ozs7O0FDSkE7Ozs7QUFDQTs7Ozs7Ozs7Ozs7QUFhQTtBQUNBLFNBQVMsU0FBVCxDQUFtQixLQUFuQixFQUEwQixDQUExQixFQUE2QixVQUE3QixFQUF5QyxTQUF6QyxFQUFvRCxVQUFwRCxFQUFnRSxTQUFoRSxFQUEyRTs7QUFFekUsTUFBSSxjQUFjLEVBQUUsU0FBRixDQUFZLGdCQUFaLEVBQThCLElBQTlCLENBQW1DLEtBQW5DLEVBQTBDO0FBQUEsV0FBSyxFQUFFLElBQVA7QUFBQSxHQUExQyxDQUFsQjs7QUFFQSxjQUFZLElBQVosR0FBbUIsTUFBbkI7QUFDQSxjQUFZLEtBQVosR0FBb0IsTUFBcEIsQ0FBMkIsUUFBM0IsRUFDSyxPQURMLENBQ2EsZUFEYixFQUM4QixJQUQ5QixFQUVLLEtBRkwsQ0FFVyxXQUZYLEVBR0ssSUFITCxDQUdVLFdBSFYsRUFHdUIsVUFBUyxDQUFULEVBQVk7QUFBRSxXQUFPLGVBQWUsV0FBVyxDQUFDLENBQUMsRUFBRSxJQUFKLEVBQVMsQ0FBQyxFQUFFLEdBQVosQ0FBWCxDQUFmLEdBQThDLEdBQXJEO0FBQTJELEdBSGhHLEVBSUssT0FKTCxDQUlhLE9BSmIsRUFJc0I7QUFBQSxXQUFLLEVBQUUsU0FBRixLQUFnQixTQUFyQjtBQUFBLEdBSnRCLEVBS0ssRUFMTCxDQUtRLFdBTFIsRUFLcUIsVUFBUyxDQUFULEVBQVksQ0FDNUIsQ0FOTCxFQU9LLEVBUEwsQ0FPUSxVQVBSLEVBT29CLFVBQVMsQ0FBVCxFQUFZLENBQzNCLENBUkwsRUFTSyxVQVRMLEdBVUssSUFWTCxDQVVVLEdBVlYsRUFVZSxTQVZmLEVBV0ssS0FYTCxDQVdXLE1BWFgsRUFXbUIsVUFYbkIsRUFZSyxLQVpMLENBWVcsZ0JBWlgsRUFZNkIsUUFaN0IsRUFhSyxLQWJMLENBYVcsUUFiWCxFQWFxQixVQWJyQjtBQWNEOztJQUVLLEk7QUFDSixnQkFBWSxHQUFaLEVBQWlCLElBQWpCLEVBQXVCO0FBQUE7O0FBQ3JCLFFBQUksT0FBTyxJQUFJLE1BQUosQ0FBVyxHQUFYLEVBQWdCLE9BQWhCLENBQXdCLE1BQXhCLEVBQWdDLElBQWhDLENBQVg7QUFDQSxTQUFLLE1BQUwsQ0FBWSxRQUFaLEVBQ0csSUFESCxDQUNRLElBRFIsRUFDYyxDQURkLEVBRUcsSUFGSCxDQUVRLElBRlIsRUFFYyxDQUFDLElBRmYsRUFHRyxJQUhILENBR1EsR0FIUixFQUdhLENBSGI7QUFJQSxTQUFLLE1BQUwsQ0FBWSxNQUFaLEVBQ0csSUFESCxDQUNRLElBRFIsRUFDYyxDQURkLEVBRUcsSUFGSCxDQUVRLElBRlIsRUFFYyxDQUZkLEVBR0csSUFISCxDQUdRLElBSFIsRUFHYyxDQUhkLEVBSUcsSUFKSCxDQUlRLElBSlIsRUFJYyxDQUFDLElBSmY7O0FBTUEsU0FBSyxJQUFMLEdBQVksSUFBWjtBQUNEOzs7OzJCQUVNO0FBQ0wsV0FBSyxJQUFMLENBQVUsT0FBVixDQUFrQixRQUFsQixFQUE0QixJQUE1QjtBQUNEOzs7eUJBRUksRSxFQUFJO0FBQ1AsV0FBSyxJQUFMLENBQVUsT0FBVixDQUFrQixRQUFsQixFQUE0QixLQUE1QjtBQUNBLFdBQUssSUFBTCxDQUFVLElBQVYsQ0FBZSxXQUFmLGlCQUF5QyxHQUFHLENBQUgsQ0FBekMsVUFBbUQsR0FBRyxDQUFILENBQW5EO0FBQ0Q7Ozs7OztBQUdILFNBQVMsT0FBVCxDQUFpQixNQUFqQixFQUF5QjtBQUFBLE1BQ2hCLE9BRGdCLEdBQ3VDLE1BRHZDLENBQ2hCLE9BRGdCO0FBQUEsTUFDUCxNQURPLEdBQ3VDLE1BRHZDLENBQ1AsTUFETztBQUFBLE1BQ0MsTUFERCxHQUN1QyxNQUR2QyxDQUNDLE1BREQ7QUFBQSxNQUNTLFFBRFQsR0FDdUMsTUFEdkMsQ0FDUyxRQURUO0FBQUEsTUFDbUIsT0FEbkIsR0FDdUMsTUFEdkMsQ0FDbUIsT0FEbkI7QUFBQSxNQUM0QixPQUQ1QixHQUN1QyxNQUR2QyxDQUM0QixPQUQ1Qjs7O0FBR3ZCLE1BQUksV0FBVyxHQUFHLE1BQUgsQ0FBVSxPQUFWLEVBQW1CLE1BQW5CLENBQTBCLEtBQTFCLEVBQ0UsT0FERixDQUNVLFFBRFYsRUFDb0IsSUFEcEIsQ0FBZjs7QUFHQSxNQUFJLFVBQVUsU0FBUyxNQUFULENBQWdCLEtBQWhCLEVBQ0csT0FESCxDQUNXLFlBRFgsRUFDeUIsSUFEekIsRUFFRyxPQUZILENBRVcsUUFGWCxFQUVxQixJQUZyQixFQUdHLE9BSEgsQ0FHVyxNQUhYLEVBR21CLEtBSG5CLEVBSUcsSUFKSCwyakJBQWQ7O0FBYUEsVUFBUSxNQUFSLENBQWUsUUFBZixFQUF5QixFQUF6QixDQUE0QixPQUE1QixFQUFxQyxZQUFNO0FBQ3pDLE9BQUcsS0FBSCxDQUFTLGNBQVQ7QUFDQSxRQUFJLE9BQUosRUFBYTtBQUNYLGNBQVEsUUFBUSxNQUFSLENBQWUsUUFBZixFQUF5QixJQUF6QixFQUFSO0FBQ0Q7QUFDRixHQUxEOztBQU9BLE1BQUksUUFBUSxHQUFHLE1BQUgsQ0FBVSxPQUFWLEVBQW1CLElBQW5CLEdBQTBCLFdBQXRDO0FBQ0EsTUFBSSxTQUFTLFFBQVEsR0FBUixHQUFjLElBQTNCOztBQUVBLE1BQUksTUFBTSxTQUFTLE1BQVQsQ0FBZ0IsS0FBaEIsRUFDSyxJQURMLENBQ1UsT0FEVixFQUNtQixLQURuQixFQUVLLElBRkwsQ0FFVSxRQUZWLEVBRW9CLE1BRnBCLENBQVY7O0FBSUEsTUFBSSxlQUFlLElBQUksTUFBSixDQUFXLEdBQVgsRUFBZ0IsSUFBaEIsQ0FBcUIsSUFBckIsRUFBMEIsY0FBMUIsQ0FBbkI7QUFDQSxNQUFJLGVBQWUsSUFBSSxNQUFKLENBQVcsR0FBWCxFQUFnQixJQUFoQixDQUFxQixJQUFyQixFQUEwQixjQUExQixDQUFuQjtBQUNBLE1BQUksWUFBWSxhQUFhLE1BQWIsQ0FBb0IsR0FBcEIsRUFBeUIsSUFBekIsQ0FBOEIsT0FBOUIsRUFBdUMsYUFBdkMsQ0FBaEI7O0FBRUEsTUFBSSxlQUFlLEVBQW5CO0FBQ0EsTUFBSSxPQUFPLElBQUksSUFBSixDQUFTLFlBQVQsRUFBdUIsWUFBdkIsQ0FBWDs7QUFFQSxNQUFJLG1CQUFKOztBQUVBLE1BQUksc0JBQUo7QUFDQSxNQUFJLGFBQWEsR0FBRyxXQUFILEdBQ0UsS0FERixDQUNRLENBQUMsU0FBRCxFQUFZLFNBQVosQ0FEUixDQUFqQjs7QUFHQSxNQUFJLFlBQVksR0FBRyxTQUFILEVBQWhCOztBQUVBLE1BQUksY0FBYyxHQUFHLFdBQUgsR0FDQyxLQURELENBQ08sQ0FBQyxTQUFELEVBQVksU0FBWixDQURQLENBQWxCOztBQUdBLE1BQUksYUFBYSxHQUFHLFNBQUgsRUFBakI7O0FBRUEsTUFBSSxVQUFVLE1BQWQ7QUFDQSxNQUFJLFVBQVUsTUFBZDtBQUNBLE1BQUksZUFBSjtBQUNBLE1BQUksZ0JBQUo7O0FBRUEsTUFBSSxrQkFBSjs7QUFFQSxXQUFTLE1BQVQsR0FBa0I7QUFDaEIsUUFBSSxtQkFBSjtBQUFBLFFBQWdCLGtCQUFoQjtBQUNBLFFBQUksOEJBQTRCLE9BQTVCLGFBQTJDLE9BQS9DO0FBQ0EsWUFBUSxNQUFSLENBQWUsUUFBZixFQUF5QixJQUF6QixDQUE4QixZQUE5Qjs7QUFFQSxRQUFJLFdBQVcsUUFBWCxJQUF1QixXQUFXLGNBQXRDLEVBQXNEOztBQUVwRCxtQkFBYSxvQkFBQyxDQUFEO0FBQUEsZUFBTyxXQUFXLEVBQUUseUJBQUYsQ0FBWCxDQUFQO0FBQUEsT0FBYjtBQUNBLGtCQUFZLG1CQUFDLENBQUQ7QUFBQSxlQUFPLFVBQVUsRUFBRSx5QkFBRixDQUFWLENBQVA7QUFBQSxPQUFaO0FBQ0Esc0JBQWdCLHVCQUFDLENBQUQ7QUFBQSxlQUFPLEVBQUUseUJBQUYsQ0FBUDtBQUFBLE9BQWhCO0FBQ0EsY0FBUSxPQUFSLENBQWdCLE1BQWhCLEVBQXdCLEtBQXhCO0FBRUQsS0FQRCxNQU9PLElBQUksV0FBVyxRQUFYLElBQXVCLFdBQVcsYUFBdEMsRUFBcUQ7O0FBRTFELG1CQUFhLG9CQUFDLENBQUQ7QUFBQSxlQUFPLFlBQVksRUFBRSx3QkFBRixDQUFaLENBQVA7QUFBQSxPQUFiO0FBQ0Esa0JBQVksbUJBQUMsQ0FBRDtBQUFBLGVBQU8sV0FBVyxFQUFFLHdCQUFGLENBQVgsQ0FBUDtBQUFBLE9BQVo7QUFDQSxzQkFBZ0IsdUJBQUMsQ0FBRDtBQUFBLGVBQU8sRUFBRSx3QkFBRixDQUFQO0FBQUEsT0FBaEI7QUFDQSxjQUFRLE9BQVIsQ0FBZ0IsTUFBaEIsRUFBd0IsSUFBeEI7QUFFRCxLQVBNLE1BT0EsSUFBSSxXQUFXLFFBQVgsSUFBdUIsV0FBVyxjQUF0QyxFQUFzRDs7QUFFM0QsbUJBQWEsb0JBQUMsQ0FBRDtBQUFBLGVBQU8sV0FBVyxFQUFFLHlCQUFGLENBQVgsQ0FBUDtBQUFBLE9BQWI7QUFDQSxrQkFBWSxtQkFBQyxDQUFEO0FBQUEsZUFBTyxVQUFVLEVBQUUseUJBQUYsQ0FBVixDQUFQO0FBQUEsT0FBWjtBQUNBLHNCQUFnQix1QkFBQyxDQUFEO0FBQUEsZUFBTyxFQUFFLHlCQUFGLENBQVA7QUFBQSxPQUFoQjtBQUNBLGNBQVEsT0FBUixDQUFnQixNQUFoQixFQUF3QixLQUF4QjtBQUVELEtBUE0sTUFPQSxJQUFJLFdBQVcsUUFBWCxJQUF1QixXQUFXLGFBQXRDLEVBQXFEOztBQUUxRCxtQkFBYSxvQkFBQyxDQUFEO0FBQUEsZUFBTyxZQUFZLEVBQUUsd0JBQUYsQ0FBWixDQUFQO0FBQUEsT0FBYjtBQUNBLGtCQUFZLG1CQUFDLENBQUQ7QUFBQSxlQUFPLFdBQVcsRUFBRSx3QkFBRixDQUFYLENBQVA7QUFBQSxPQUFaO0FBQ0Esc0JBQWdCLHVCQUFDLENBQUQ7QUFBQSxlQUFPLEVBQUUsd0JBQUYsQ0FBUDtBQUFBLE9BQWhCO0FBQ0EsY0FBUSxPQUFSLENBQWdCLE1BQWhCLEVBQXdCLElBQXhCO0FBRUQ7O0FBRUQsY0FBVSxNQUFWLEVBQWtCLFNBQWxCLEVBQTZCLFVBQTdCLEVBQXlDLFNBQXpDLEVBQW9ELFVBQXBELEVBQWdFLFNBQWhFO0FBQ0Q7O0FBRUQsV0FBUyxNQUFULEdBQWtCOztBQUVoQixRQUFJLFFBQVEsU0FBUyxJQUFULEdBQWdCLFdBQTVCO0FBQ0EsUUFBSSxTQUFTLFFBQVEsR0FBUixHQUFjLElBQTNCOztBQUVBLFFBQUksSUFBSixDQUFTLE9BQVQsRUFBa0IsS0FBbEIsRUFDSSxJQURKLENBQ1MsUUFEVCxFQUNtQixNQURuQjs7QUFHQSxRQUFJLGFBQWEsRUFBakI7QUFDQSxpQkFBYSx3Q0FDVixTQURVLENBQ0EsQ0FBQyxDQUFDLElBQUksVUFBTCxFQUFpQixJQUFJLFVBQXJCLENBQUQsRUFBbUMsQ0FBQyxRQUFRLFVBQVQsRUFBcUIsU0FBUyxVQUE5QixDQUFuQyxDQURBLEVBQytFO0FBQ3hGLFlBQU0sbUJBRGtGO0FBRXhGLGdCQUFVO0FBRjhFLEtBRC9FLENBQWI7O0FBTUE7QUFDQSxRQUFJLGFBQWEsYUFBYSxTQUFiLENBQXVCLE1BQXZCLEVBQ1osSUFEWSxDQUNQLE9BRE8sQ0FBakI7QUFFQSxlQUFXLEtBQVgsR0FDSyxNQURMLENBQ1ksTUFEWixFQUVHLEtBRkgsQ0FFUyxVQUZULEVBR0ssSUFITCxDQUdVLEdBSFYsRUFHZSxHQUFHLE9BQUgsQ0FBVyxVQUFYLENBSGYsRUFJSyxLQUpMLENBSVcsTUFKWCxFQUltQixTQUpuQixFQUtLLEtBTEwsQ0FLVyxRQUxYLEVBS3FCO0FBQUEsYUFBSyxFQUFFLFVBQUYsQ0FBYSxNQUFiLEtBQXdCLElBQXhCLEdBQStCLFNBQS9CLEdBQTJDLE9BQWhEO0FBQUEsS0FMckI7O0FBT0E7QUFDQSxRQUFJLGFBQWEsR0FBRyxNQUFILENBQ1AsT0FBTyxHQUFQLENBQVc7QUFBQSxhQUFLLEVBQUUseUJBQUYsQ0FBTDtBQUFBLEtBQVgsRUFDRCxNQURDLENBQ00sT0FBTyxHQUFQLENBQVc7QUFBQSxhQUFLLEVBQUUseUJBQUYsQ0FBTDtBQUFBLEtBQVgsQ0FETixDQURPLENBQWpCOztBQUlBLFFBQUksY0FBYyxHQUFHLE1BQUgsQ0FDUixPQUFPLEdBQVAsQ0FBVztBQUFBLGFBQUssRUFBRSx3QkFBRixDQUFMO0FBQUEsS0FBWCxFQUNELE1BREMsQ0FDTSxPQUFPLEdBQVAsQ0FBVztBQUFBLGFBQUssRUFBRSx3QkFBRixDQUFMO0FBQUEsS0FBWCxDQUROLENBRFEsQ0FBbEI7O0FBSUEsUUFBSSxZQUFZLElBQUksR0FBSixHQUFVLEtBQTFCO0FBQ0EsUUFBSSxZQUFZLEtBQUssR0FBTCxHQUFXLEtBQTNCOztBQUVBLGVBQVcsTUFBWCxDQUFrQixVQUFsQjtBQUNBLGNBQVUsTUFBVixDQUFpQixVQUFqQixFQUNHLEtBREgsQ0FDUyxDQUFDLFNBQUQsRUFBWSxTQUFaLENBRFQ7QUFFQSxnQkFBWSxNQUFaLENBQW1CLFdBQW5CO0FBQ0EsZUFBVyxNQUFYLENBQWtCLFdBQWxCLEVBQ0csS0FESCxDQUNTLENBQUMsU0FBRCxFQUFZLFNBQVosQ0FEVDs7QUFHQSxRQUFJLFNBQVMsT0FBTyxHQUFQLENBQVc7QUFBQSxhQUFLLFdBQVcsQ0FBQyxDQUFDLEVBQUUsSUFBSixFQUFVLENBQUMsRUFBRSxHQUFiLENBQVgsQ0FBTDtBQUFBLEtBQVgsQ0FBYjs7QUFFQSxRQUFJLEtBQUssR0FBRyxPQUFIO0FBQ1A7QUFETyxLQUVOLENBRk0sQ0FFSixhQUFLO0FBQUUsYUFBTyxXQUFZLENBQUMsQ0FBQyxFQUFFLElBQUosRUFBVSxDQUFDLEVBQUUsR0FBYixDQUFaLEVBQStCLENBQS9CLENBQVA7QUFBMkMsS0FGOUMsRUFHTixDQUhNLENBR0osYUFBSztBQUFFLGFBQU8sV0FBWSxDQUFDLENBQUMsRUFBRSxJQUFKLEVBQVUsQ0FBQyxFQUFFLEdBQWIsQ0FBWixFQUErQixDQUEvQixDQUFQO0FBQTJDLEtBSDlDLEVBSU4sTUFKTSxDQUFUOztBQU1BLGFBQVMsV0FBVCxDQUFxQixDQUFyQixFQUF3QixPQUF4QixFQUFpQztBQUMvQixnQkFBVSxXQUFXLENBQXJCO0FBQ0EsVUFBSSx1QkFBdUIsRUFBM0I7QUFDQSxhQUFPLEdBQUcsSUFBSCxDQUFRLEVBQUUsQ0FBRixDQUFSLEVBQWMsRUFBRSxDQUFGLElBQU8sT0FBckIsRUFBOEIsb0JBQTlCLENBQVA7QUFDRDs7QUFFRCxRQUFJLFVBQVUsS0FBZDs7QUFFQSxhQUFTLFNBQVQsQ0FBbUIsUUFBbkIsRUFBNkI7QUFDM0IsVUFBSSxRQUFKLEVBQWM7O0FBRVosb0JBQVksU0FBUyxJQUFULENBQWMsU0FBMUI7QUFDQTs7QUFFQSxnQkFBUSxPQUFSLENBQWdCLFFBQWhCLEVBQTBCLEtBQTFCO0FBQ0EsZ0JBQVEsTUFBUixDQUFlLFFBQWYsRUFBeUIsSUFBekIsQ0FBOEIsU0FBUyxJQUFULENBQWMsU0FBNUM7QUFDQSxnQkFBUSxNQUFSLENBQWUsU0FBZixFQUEwQixJQUExQixDQUErQixjQUFjLFNBQVMsSUFBdkIsQ0FBL0I7O0FBRUEsWUFBSSxLQUFLLFFBQVEsSUFBUixHQUFlLFdBQWYsR0FBNkIsQ0FBdEM7QUFDQSxZQUFJLEtBQUssU0FBUyxDQUFULElBQWMsUUFBUSxJQUFSLEdBQWUsWUFBN0IsR0FBNEMsQ0FBckQsQ0FWWSxDQVU0QztBQUN4RCxhQUFLLFNBQVMsQ0FBVCxJQUFjLEVBQW5COztBQUVBLGdCQUFRLEtBQVIsQ0FBYyxNQUFkLEVBQXNCLEtBQUssSUFBM0I7QUFDQSxnQkFBUSxLQUFSLENBQWMsS0FBZCxFQUFxQixLQUFLLElBQTFCOztBQUVBO0FBQ0EsWUFBSSxPQUFPLFFBQVEsSUFBUixHQUFlLHFCQUFmLEVBQVg7QUFDQSxZQUFJLFdBQVcsT0FBTyxVQUF0Qjs7QUFFQSxZQUFJLEtBQUssQ0FBTCxHQUFTLENBQWIsRUFBZ0I7QUFDZCxnQkFBTSxLQUFLLENBQVg7QUFDRCxTQUZELE1BRU8sSUFBSSxLQUFLLENBQUwsR0FBUyxLQUFLLEtBQWQsR0FBc0IsUUFBMUIsRUFBb0M7QUFDekMsZUFBSyxXQUFXLEtBQUssS0FBckI7QUFDRDs7QUFFRCxnQkFBUSxLQUFSLENBQWMsTUFBZCxFQUFzQixLQUFLLElBQTNCO0FBQ0EsZ0JBQVEsS0FBUixDQUFjLEtBQWQsRUFBcUIsS0FBSyxJQUExQjtBQUVELE9BN0JELE1BNkJPO0FBQ0wsZ0JBQVEsT0FBUixDQUFnQixRQUFoQixFQUEwQixJQUExQjtBQUNBLG9CQUFZLElBQVo7QUFDQTtBQUNEO0FBQ0Y7O0FBRUQsUUFBSSxFQUFKLENBQU8sT0FBUCxFQUFnQixZQUFXO0FBQ3pCLFVBQUksT0FBTyxZQUFZLEdBQUcsS0FBSCxDQUFTLElBQVQsQ0FBWixDQUFYO0FBQ0EsZ0JBQVUsSUFBVjtBQUNBLGdCQUFVLFFBQVEsSUFBbEI7QUFDRCxLQUpEOztBQU1BLFFBQUksRUFBSixDQUFPLFdBQVAsRUFBb0IsVUFBUyxDQUFULEVBQVk7QUFDOUIsV0FBSyxJQUFMLENBQVUsR0FBRyxPQUFILENBQVcsSUFBWCxFQUFpQixDQUFqQixDQUFWO0FBQ0EsVUFBSSxPQUFPLFlBQVksR0FBRyxPQUFILENBQVcsSUFBWCxFQUFpQixDQUFqQixDQUFaLEVBQWlDLFlBQWpDLENBQVg7QUFDQSxnQkFBVSxJQUFWO0FBQ0EsU0FBRyxLQUFILENBQVMsY0FBVDtBQUNELEtBTEQ7QUFNQSxRQUFJLEVBQUosQ0FBTyxVQUFQLEVBQW1CLFVBQVMsQ0FBVCxFQUFZO0FBQzdCLFdBQUssSUFBTDtBQUNELEtBRkQ7QUFHQSxRQUFJLEVBQUosQ0FBTyxXQUFQLEVBQW9CLFlBQVc7QUFDN0IsVUFBSSxDQUFDLE9BQUwsRUFBYztBQUNaLFlBQUksT0FBTyxZQUFZLEdBQUcsS0FBSCxDQUFTLElBQVQsQ0FBWixDQUFYO0FBQ0Esa0JBQVUsSUFBVjtBQUNEO0FBQ0YsS0FMRDs7QUFPQTtBQUVELEdBM05zQixDQTJOckI7O0FBRUYsV0FBUyxTQUFULENBQW1CLE1BQW5CLEVBQTJCLE1BQTNCLEVBQW1DO0FBQ2pDLGNBQVUsTUFBVjtBQUNBLGNBQVUsTUFBVjtBQUNBO0FBQ0Q7O0FBRUQ7QUFDQSxLQUFHLEtBQUgsR0FDRyxLQURILENBQ1MsR0FBRyxJQURaLEVBQ2tCLFFBRGxCLEVBRUcsS0FGSCxDQUVTLEdBQUcsR0FGWixFQUVpQixPQUZqQixFQUdHLFFBSEgsQ0FHWSxVQUFTLEtBQVQsRUFBZ0IsT0FBaEIsRUFBeUI7O0FBRW5DLFFBQUksU0FBUyxRQUFRLENBQVIsQ0FBYjtBQUNBLFFBQUksUUFBUSxRQUFRLENBQVIsQ0FBWjs7QUFFQTtBQUNBLFVBQU0sT0FBTixDQUFjLFVBQVMsSUFBVCxFQUFlO0FBQzNCLFdBQUssSUFBTCxHQUFZLEtBQUssSUFBakI7QUFDQSxXQUFLLFNBQUwsR0FBaUIsS0FBSyxTQUF0QjtBQUNBLFdBQUssVUFBTCxHQUFrQixLQUFLLFVBQXZCO0FBQ0EsV0FBSyxlQUFMLEdBQXVCLENBQUMsS0FBSyxlQUE3QjtBQUNBLFdBQUssZUFBTCxHQUF1QixDQUFDLEtBQUssZUFBN0I7QUFDQSxXQUFLLElBQUwsR0FBWSxDQUFDLEtBQUssSUFBbEI7QUFDQSxXQUFLLEdBQUwsR0FBVyxDQUFDLEtBQUssR0FBakI7QUFDQSxXQUFLLHlCQUFMLEdBQWlDLENBQUMsS0FBSyxpQkFBdkM7QUFDQSxXQUFLLHlCQUFMLEdBQWlDLENBQUMsS0FBSyxpQkFBdkM7QUFDQSxXQUFLLHlCQUFMLEdBQWlDLENBQUMsS0FBSyx5QkFBdkM7QUFDQSxXQUFLLHlCQUFMLEdBQWlDLENBQUMsS0FBSyx5QkFBdkM7QUFDQSxXQUFLLHdCQUFMLEdBQWdDLENBQUMsS0FBSyx3QkFBdEM7QUFDQSxXQUFLLHdCQUFMLEdBQWdDLENBQUMsS0FBSyx3QkFBdEM7QUFDQSxXQUFLLHNCQUFMLEdBQThCLENBQUMsS0FBSyxzQkFBcEM7QUFDQSxXQUFLLHNCQUFMLEdBQThCLENBQUMsS0FBSyxzQkFBcEM7QUFDQSxXQUFLLHVCQUFMLEdBQStCLENBQUMsS0FBSyx1QkFBckM7QUFDQSxXQUFLLHVCQUFMLEdBQStCLENBQUMsS0FBSyx1QkFBckM7QUFDRCxLQWxCRDs7QUFvQkE7QUFDQSxhQUFTLE9BQU8sUUFBUCxDQUFnQixNQUFoQixDQUF1QixhQUFLO0FBQ25DLGFBQU8sRUFBRSxVQUFGLENBQWEsT0FBYixJQUF3QixLQUF4QixJQUFpQyxFQUFFLFVBQUYsQ0FBYSxNQUFiLElBQXVCLElBQS9EO0FBQ0QsS0FGUSxDQUFUOztBQUtBLGFBQVMsS0FBVDtBQUNBLGNBQVUsTUFBVjs7QUFFQTs7QUFFQSxXQUFPLGdCQUFQLENBQXdCLFFBQXhCLEVBQWtDLE1BQWxDO0FBRUQsR0ExQ0Q7O0FBNENBLFNBQU87QUFDTCxlQUFXO0FBRE4sR0FBUDtBQUdEOztRQUVRLE8sR0FBQSxPOzs7Ozs7OztBQ25WVCxTQUFTLGNBQVQsQ0FBd0IsQ0FBeEIsRUFBMkI7QUFDdkIsV0FBTyxLQUFLLEtBQUwsQ0FBVyxJQUFJLEdBQWYsSUFBc0IsR0FBN0I7QUFDSDs7QUFFRCxTQUFTLFNBQVQsQ0FBbUIsT0FBbkIsRUFBNEIsQ0FBNUIsRUFBK0I7QUFDM0I7QUFDQTs7QUFFQSxRQUFJLFFBQVEsUUFBUSxJQUFSLEdBQWUsV0FBM0I7QUFDQSxRQUFJLFdBQVcsUUFBUSxJQUFSLEdBQWUsVUFBZixDQUEwQixXQUF6Qzs7QUFFQSxRQUFJLElBQUksUUFBUSxDQUFoQjs7QUFFQTtBQUNBLFFBQUksSUFBSSxDQUFSLEVBQVc7QUFDUCxZQUFJLENBQUo7QUFDSCxLQUZELE1BRU8sSUFBSSxJQUFJLEtBQUosR0FBWSxRQUFoQixFQUEwQjtBQUM3QixZQUFJLFdBQVcsS0FBZjtBQUNIOztBQUVELFlBQVEsS0FBUixDQUFjLE1BQWQsRUFBc0IsSUFBSSxJQUExQjtBQUNIOztBQUVELFNBQVMsUUFBVCxDQUFrQixNQUFsQixFQUEwQjtBQUFBLFFBQ2YsT0FEZSxHQUMrQixNQUQvQixDQUNmLE9BRGU7QUFBQSxRQUNOLFFBRE0sR0FDK0IsTUFEL0IsQ0FDTixRQURNO0FBQUEsUUFDSSxPQURKLEdBQytCLE1BRC9CLENBQ0ksT0FESjtBQUFBLFFBQ2EsT0FEYixHQUMrQixNQUQvQixDQUNhLE9BRGI7QUFBQSxRQUNzQixLQUR0QixHQUMrQixNQUQvQixDQUNzQixLQUR0Qjs7O0FBR3RCLFFBQUksUUFBUSxFQUFaO0FBQ0EsUUFBSSxvQkFBSjtBQUNBLFFBQUksU0FBUyxFQUFiOztBQUVBLFFBQU0sU0FBUyxDQUFmO0FBQ0EsUUFBTSxrQkFBa0IsRUFBeEI7QUFDQSxRQUFJLFlBQVksU0FBUyxDQUFULEdBQWEsZUFBN0I7QUFDQSxRQUFJLFNBQVM7QUFDVCxhQUFLLENBREk7QUFFVCxjQUFNO0FBRkcsS0FBYjtBQUlBLFFBQUksVUFBSjs7QUFHQSxRQUFJLE1BQU0sUUFBUSxNQUFSLENBQWUsS0FBZixFQUNHLE1BREgsQ0FDVSxHQURWLEVBRUcsSUFGSCxDQUVRLFdBRlIsaUJBRWtDLE9BQU8sSUFGekMsVUFFa0QsT0FBTyxHQUZ6RCxPQUFWOztBQUlBLFFBQUksTUFBSixDQUFXLE1BQVgsRUFDSyxJQURMLENBQ1UsT0FEVixFQUNtQixTQURuQixFQUVLLElBRkwsQ0FFVSxRQUZWLEVBRW9CLE1BRnBCLEVBR0ssSUFITCxDQUdVLEdBSFYsRUFHZSxDQUhmLEVBSUssSUFKTCxDQUlVLEdBSlYsRUFJZSxDQUpmLEVBS0ssSUFMTCxDQUtVLGNBTFYsRUFLMEIsR0FMMUI7O0FBT0EsUUFBSSxRQUFRLFFBQVEsTUFBUixDQUFlLEtBQWYsRUFBc0IsT0FBdEIsQ0FBOEIscUJBQTlCLEVBQXFELElBQXJELEVBQTJELE9BQTNELENBQW1FLFFBQW5FLEVBQTZFLElBQTdFLENBQVo7QUFDQSxRQUFJLGFBQWEsUUFBUSxNQUFSLENBQWUsS0FBZixFQUFzQixPQUF0QixDQUE4QixrQkFBOUIsRUFBa0QsSUFBbEQsQ0FBakI7QUFDQSxRQUFJLGNBQUo7O0FBRUEsYUFBUyxNQUFULENBQWdCLElBQWhCLEVBQXNCLE1BQXRCLEVBQThCLFFBQTlCLEVBQXdDO0FBQ3BDO0FBQ0EsZ0JBQVEsTUFBUjtBQUNBLGdCQUFRLEtBQUssS0FBTCxFQUFSOztBQUVBO0FBQ0EsY0FBTSxJQUFOLENBQVcsVUFBQyxDQUFELEVBQUksQ0FBSjtBQUFBLG1CQUFVLEdBQUcsU0FBSCxDQUFhLEVBQUUsS0FBRixDQUFiLEVBQXVCLEVBQUUsS0FBRixDQUF2QixDQUFWO0FBQUEsU0FBWDs7QUFFQTtBQUNBLFlBQUksUUFBUSxRQUFRLElBQVIsR0FBZSxXQUEzQjtBQUNBLGdCQUFRLEtBQVIsQ0FBYyxRQUFkLEVBQXdCLFNBQVMsSUFBakM7QUFDQSxnQkFBUSxNQUFSLENBQWUsS0FBZixFQUNLLElBREwsQ0FDVSxPQURWLEVBQ21CLEtBRG5CLEVBRUssSUFGTCxDQUVVLFFBRlYsRUFFb0IsTUFGcEI7O0FBS0E7O0FBRUEsWUFBSSxXQUFKO0FBQ0EsWUFBSSxTQUFTLEtBQWIsRUFBb0I7QUFDaEIsaUJBQUssR0FBRyxRQUFILEdBQ0EsS0FEQSxDQUNNLENBQUMsQ0FBRCxFQUFJLFFBQVEsSUFBSSxPQUFPLElBQXZCLENBRE4sRUFFQSxLQUZBLENBRU0sSUFGTixDQUFMO0FBR0EsZ0JBQUksU0FBUyxHQUFHLE1BQUgsQ0FBVSxJQUFWLEVBQWdCO0FBQUEsdUJBQUssRUFBRSxLQUFGLElBQVcsR0FBaEI7QUFBQSxhQUFoQixDQUFiO0FBQ0EsbUJBQU8sQ0FBUCxJQUFZLEtBQUssR0FBTCxDQUFTLENBQVQsRUFBWSxPQUFPLENBQVAsQ0FBWixDQUFaO0FBQ0EsZUFBRyxNQUFILENBQVUsTUFBVjtBQUNILFNBUEQsTUFPTztBQUNILGlCQUFLLEdBQUcsV0FBSCxHQUNBLEtBREEsQ0FDTSxDQUFDLENBQUQsRUFBSSxRQUFRLElBQUksT0FBTyxJQUF2QixDQUROLEVBRUEsS0FGQSxDQUVNLElBRk4sQ0FBTDtBQUdBLGVBQUcsTUFBSCxDQUFVLEdBQUcsTUFBSCxDQUFVLElBQVYsRUFBZ0I7QUFBQSx1QkFBSyxFQUFFLEtBQUYsSUFBVyxHQUFoQjtBQUFBLGFBQWhCLENBQVY7QUFDSDs7QUFFRCxZQUFJLFdBQUMsQ0FBRDtBQUFBLG1CQUFPLEdBQUcsRUFBRSxLQUFGLElBQVcsR0FBZCxDQUFQO0FBQUEsU0FBSjs7QUFFQTs7QUFFQSxZQUFJLGVBQWUsTUFBTSxJQUFOLENBQVc7QUFBQSxtQkFBSyxFQUFFLFNBQUYsSUFBZSxRQUFwQjtBQUFBLFNBQVgsQ0FBbkI7O0FBRUE7QUFDQSxZQUFJLGVBQWUsSUFBSSxTQUFKLENBQWMsa0JBQWQsRUFBa0MsSUFBbEMsQ0FBdUMsQ0FBQyxZQUFELENBQXZDLENBQW5CO0FBQ0EscUJBQWEsS0FBYixHQUNLLE1BREwsQ0FDWSxRQURaLEVBRUssT0FGTCxDQUVhLGlCQUZiLEVBRWdDLElBRmhDLEVBR0ssS0FITCxDQUdXLFlBSFgsRUFJUyxJQUpULENBSWMsSUFKZCxFQUlvQixDQUpwQixFQUtTLElBTFQsQ0FLYyxJQUxkLEVBS29CLFNBTHBCLEVBTVMsSUFOVCxDQU1jLEdBTmQsRUFNbUIsZUFObkI7O0FBUUE7QUFDQSxZQUFJLGFBQWEsTUFBTSxNQUFOLENBQWE7QUFBQSxtQkFBSyxFQUFFLFNBQUYsSUFBZSxRQUFwQjtBQUFBLFNBQWIsQ0FBakI7QUFDQTtBQUNBLFlBQUksT0FBTyxJQUFJLFNBQUosQ0FBYyxTQUFkLEVBQXlCLElBQXpCLENBQThCLFVBQTlCLENBQVg7QUFDQSxhQUFLLEtBQUwsR0FDSyxNQURMLENBQ1ksUUFEWixFQUVLLE9BRkwsQ0FFYSxRQUZiLEVBRXVCLElBRnZCLEVBR0ssS0FITCxDQUdXLElBSFgsRUFJUyxPQUpULENBSWlCLFVBSmpCLEVBSTZCO0FBQUEsbUJBQUssRUFBRSxTQUFGLEtBQWdCLFFBQXJCO0FBQUEsU0FKN0IsRUFLUyxJQUxULENBS2MsSUFMZCxFQUtvQixDQUxwQixFQU1TLElBTlQsQ0FNYyxJQU5kLEVBTW9CLFNBTnBCLEVBT1MsSUFQVCxDQU9jLEdBUGQsRUFPbUIsTUFQbkI7O0FBU0Esc0JBQWMsR0FBRyxPQUFILEdBQ1QsQ0FEUyxDQUNQLENBRE8sRUFFVCxDQUZTLENBRVAsQ0FGTyxFQUdULFVBSFMsQ0FBZDs7QUFLQTtBQUNBLFlBQUksVUFBVSxJQUFJLE1BQUosQ0FBVyxVQUFYLEVBQ1QsSUFEUyxDQUNKLE9BREksRUFDSyxLQURMLEVBRVQsRUFGUyxDQUVOLFdBRk0sRUFFTyxTQUZQLEVBR1QsRUFIUyxDQUdOLFVBSE0sRUFHTTtBQUFBLG1CQUFLLFNBQUw7QUFBQSxTQUhOLEVBSVQsRUFKUyxDQUlOLFdBSk0sRUFJTyxTQUpQLEVBS1QsRUFMUyxDQUtOLFdBTE0sRUFLTyxTQUxQLEVBTVQsRUFOUyxDQU1OLE9BTk0sRUFNRyxVQU5ILENBQWQ7O0FBUUE7QUFDQSxZQUFJLGFBQWEsRUFBakI7QUFDQSxZQUFJLFFBQUosRUFBYztBQUNWLHlCQUFhLGFBQWEsU0FBYixHQUF5QixHQUF0QztBQUNIO0FBQ0Qsc0JBQWMsZUFBZSxhQUFhLEtBQWIsQ0FBZixDQUFkO0FBQ0EsbUJBQVcsSUFBWCxDQUFnQixVQUFoQjs7QUFHQSxZQUFJLEtBQUssWUFBYSxrQkFBa0IsQ0FBL0IsR0FBb0MsRUFBcEMsR0FBeUMsT0FBTyxHQUF6RDtBQUNBLG1CQUFXLEtBQVgsQ0FBaUIsS0FBakIsRUFBd0IsS0FBSyxJQUE3Qjs7QUFFQSxrQkFBVSxVQUFWLEVBQXNCLEVBQUUsWUFBRixJQUFrQixPQUFPLElBQS9DOztBQUVBLGFBQUssWUFBYSxTQUFTLENBQXRCLEdBQTJCLEVBQTNCLEdBQWdDLE9BQU8sR0FBNUM7QUFDQSxjQUFNLEtBQU4sQ0FBWSxLQUFaLEVBQW1CLEtBQUssSUFBeEI7QUFDSDs7QUFFRCxhQUFTLFVBQVQsR0FBc0I7QUFDbEIsWUFBSSxTQUFKLENBQWMsU0FBZCxFQUNLLE9BREwsQ0FDYSxTQURiLEVBQ3dCLEtBRHhCOztBQUdBO0FBQ0EsY0FBTSxPQUFOLENBQWMsUUFBZCxFQUF3QixJQUF4QjtBQUNIOztBQUVELGFBQVMsV0FBVCxDQUFxQixJQUFyQixFQUEyQjtBQUN2QjtBQUNBO0FBQ0EsWUFBSSxNQUFNLE1BQU0sSUFBTixDQUFXO0FBQUEsbUJBQUssRUFBRSxTQUFGLEtBQWdCLElBQXJCO0FBQUEsU0FBWCxDQUFWO0FBQ0EsWUFBSSxDQUFDLEdBQUwsRUFBVTtBQUNOO0FBQ0E7QUFDSDtBQUNELFlBQUksU0FBSixDQUFjLFNBQWQsRUFDSyxPQURMLENBQ2EsU0FEYixFQUN3QjtBQUFBLG1CQUFLLEVBQUUsU0FBRixLQUFnQixJQUFJLFNBQXpCO0FBQUEsU0FEeEI7O0FBR0E7QUFDQSxZQUFJLE9BQU8sRUFBWDtBQUNBLFlBQUksUUFBSixFQUFjO0FBQ1YsbUJBQU8sSUFBSSxTQUFKLEdBQWdCLEdBQXZCO0FBQ0g7QUFDRCxnQkFBUSxlQUFlLElBQUksS0FBSixDQUFmLENBQVI7QUFDQSxjQUFNLElBQU4sQ0FBVyxJQUFYO0FBQ0EsY0FBTSxPQUFOLENBQWMsUUFBZCxFQUF3QixLQUF4Qjs7QUFFQSxrQkFBVSxLQUFWLEVBQWlCLEVBQUUsR0FBRixJQUFTLE9BQU8sSUFBakM7QUFDQTtBQUNBLFlBQUksVUFBVSxJQUFJLE1BQUosQ0FBVyxVQUFYLEVBQXVCLElBQXZCLEVBQWQ7QUFDQSxnQkFBUSxhQUFSLENBQXNCLFdBQXRCLENBQWtDLE9BQWxDO0FBQ0g7O0FBRUQsYUFBUyxTQUFULEdBQXFCO0FBQ2pCLFlBQUksU0FBUyxHQUFHLE9BQUgsQ0FBVyxJQUFYLEVBQWlCLENBQWpCLEVBQW9CLENBQXBCLENBQWI7QUFDQSxZQUFJLFFBQVEsWUFBWSxJQUFaLENBQWlCLE1BQWpCLEVBQXlCLENBQXpCLEVBQTRCLEVBQTVCLENBQVo7O0FBRUEsWUFBSSxLQUFKLEVBQVc7QUFDUCxvQkFBUSxNQUFNLElBQWQ7QUFDQTtBQUNBLG9CQUFRLE1BQU0sU0FBZDtBQUNILFNBSkQsTUFJTztBQUNIO0FBQ0g7QUFDSjs7QUFFRCxhQUFTLFNBQVQsR0FBcUI7QUFDakIsWUFBSSxTQUFTLEdBQUcsS0FBSCxDQUFTLElBQVQsRUFBZSxDQUFmLENBQWI7QUFDQSxZQUFJLFFBQVEsWUFBWSxJQUFaLENBQWlCLE1BQWpCLEVBQXlCLENBQXpCLEVBQTRCLEVBQTVCLENBQVo7O0FBRUEsWUFBSSxLQUFKLEVBQVc7QUFDUCxvQkFBUSxNQUFNLElBQWQ7QUFDQTtBQUNBLG9CQUFRLE1BQU0sU0FBZDtBQUNILFNBSkQsTUFJTztBQUNIO0FBQ0g7QUFDSjs7QUFFRCxhQUFTLFVBQVQsR0FBc0I7QUFDbEIsWUFBSSxTQUFTLEdBQUcsS0FBSCxDQUFTLElBQVQsRUFBZSxDQUFmLENBQWI7QUFDQSxZQUFJLFFBQVEsWUFBWSxJQUFaLENBQWlCLE1BQWpCLEVBQXlCLENBQXpCLEVBQTRCLEVBQTVCLENBQVo7O0FBRUEsWUFBSSxLQUFKLEVBQVc7QUFDUCxnQkFBSSxPQUFKLEVBQWE7QUFDVCx3QkFBUSxNQUFNLElBQU4sQ0FBVyxTQUFuQjtBQUNIO0FBQ0o7QUFDSjs7QUFFRCxXQUFPO0FBQ0gsZ0JBQVEsTUFETDtBQUVILG1CQUFXLFdBRlI7QUFHSCx3QkFBZ0I7QUFIYixLQUFQO0FBS0g7O0FBRUQsU0FBUyxhQUFULENBQXVCLE1BQXZCLEVBQStCO0FBQUEsUUFDdEIsT0FEc0IsR0FDcUIsTUFEckIsQ0FDdEIsT0FEc0I7QUFBQSxRQUNiLE9BRGEsR0FDcUIsTUFEckIsQ0FDYixPQURhO0FBQUEsUUFDSixJQURJLEdBQ3FCLE1BRHJCLENBQ0osSUFESTtBQUFBLFFBQ0UsT0FERixHQUNxQixNQURyQixDQUNFLE9BREY7QUFBQSxRQUNXLE1BRFgsR0FDcUIsTUFEckIsQ0FDVyxNQURYOztBQUUzQixRQUFJLFVBQVUsVUFBVSxRQUF4Qjs7QUFFQSxjQUFVLEdBQUcsTUFBSCxDQUFVLE9BQVYsQ0FBVjs7QUFFQTtBQUNBLFlBQVEsSUFBUjs7QUFnQ0EsUUFBSSxPQUFPLEVBQVg7QUFDQSxRQUFJLFlBQVksSUFBSSxRQUFKLENBQWE7QUFDekIsaUJBQVMsUUFBUSxNQUFSLENBQWUsZUFBZixDQURnQjtBQUV6QixrQkFBVSxJQUZlO0FBR3pCLGlCQUFTLE9BSGdCO0FBSXpCLGlCQUFTLE9BSmdCO0FBS3pCLGVBQU87QUFMa0IsS0FBYixDQUFoQjtBQU9BLFFBQUksWUFBWSxJQUFJLFFBQUosQ0FBYTtBQUN6QixpQkFBUyxRQUFRLE1BQVIsQ0FBZSxnQkFBZixDQURnQjtBQUV6QixrQkFBVSxLQUZlO0FBR3pCLGlCQUFTLE9BSGdCO0FBSXpCLGlCQUFTLE9BSmdCO0FBS3pCLGVBQU87QUFMa0IsS0FBYixDQUFoQjtBQU9BLFFBQUksWUFBWSxJQUFJLFFBQUosQ0FBYTtBQUN6QixpQkFBUyxRQUFRLE1BQVIsQ0FBZSxnQkFBZixDQURnQjtBQUV6QixrQkFBVSxLQUZlO0FBR3pCLGlCQUFTLE9BSGdCO0FBSXpCLGlCQUFTLE9BSmdCO0FBS3pCLGVBQU87QUFMa0IsS0FBYixDQUFoQjs7QUFRQSxhQUFTLE9BQVQsQ0FBaUIsSUFBakIsRUFBdUI7QUFDbkIsWUFBSSxDQUFDLElBQUwsRUFBVztBQUNQLHNCQUFVLGNBQVY7QUFDQSxzQkFBVSxjQUFWO0FBQ0Esc0JBQVUsY0FBVjtBQUNBO0FBQ0g7O0FBRUQsa0JBQVUsU0FBVixDQUFvQixJQUFwQjtBQUNBLGtCQUFVLFNBQVYsQ0FBb0IsSUFBcEI7QUFDQSxrQkFBVSxTQUFWLENBQW9CLElBQXBCO0FBQ0g7O0FBRUQsYUFBUyxNQUFULEdBQWtCO0FBQ2Qsa0JBQVUsTUFBVixDQUFpQixJQUFqQixFQUF1QixjQUFjLE9BQXJDLEVBQThDLElBQTlDO0FBQ0Esa0JBQVUsTUFBVixDQUFpQixJQUFqQixFQUF1Qix3QkFBd0IsT0FBL0MsRUFBd0QsSUFBeEQ7QUFDQSxrQkFBVSxNQUFWLENBQWlCLElBQWpCLEVBQXVCLHVCQUF1QixPQUE5QyxFQUF1RCxJQUF2RDtBQUNIOztBQUVELGFBQVMsU0FBVCxDQUFtQixNQUFuQixFQUEyQjtBQUN2QixZQUFJLFdBQVcsUUFBWCxJQUF1QixXQUFXLFFBQXRDLEVBQWdEO0FBQzVDLHNCQUFVLE1BQVY7QUFDQTtBQUNILFNBSEQsTUFHTztBQUNILG9CQUFRLEdBQVIsQ0FBWSxrREFBWixFQUFnRSxNQUFoRTtBQUNIO0FBQ0o7O0FBRUQsT0FBRyxHQUFILENBQU8sT0FBUCxFQUFnQixVQUFDLEtBQUQsRUFBUSxJQUFSLEVBQWlCO0FBQzdCLGdCQUFRLEdBQVIsQ0FBWSxLQUFaOztBQUVBO0FBQ0EsYUFBSyxPQUFMLENBQWEsYUFBSztBQUNkLGNBQUUseUJBQUYsR0FBOEIsQ0FBQyxFQUFFLHlCQUFqQztBQUNBLGNBQUUseUJBQUYsR0FBOEIsQ0FBQyxFQUFFLHlCQUFqQztBQUNBLGNBQUUsd0JBQUYsR0FBNkIsQ0FBQyxFQUFFLHdCQUFoQztBQUNBLGNBQUUsd0JBQUYsR0FBNkIsQ0FBQyxFQUFFLHdCQUFoQztBQUNBLGNBQUUsZUFBRixHQUFvQixDQUFDLEVBQUUsZUFBdkI7QUFDQSxjQUFFLGVBQUYsR0FBb0IsQ0FBQyxFQUFFLGVBQXZCO0FBQ0gsU0FQRDs7QUFTQTtBQUNBLGVBQU8sSUFBUDs7QUFFQTtBQUNBLGVBQU8sZ0JBQVAsQ0FBd0IsUUFBeEIsRUFBa0MsTUFBbEM7QUFDSCxLQWxCRDs7QUFvQkEsV0FBTztBQUNILG1CQUFXO0FBRFIsS0FBUDtBQUdIOztRQUVRLGEsR0FBQSxhIiwiZmlsZSI6ImdlbmVyYXRlZC5qcyIsInNvdXJjZVJvb3QiOiIiLCJzb3VyY2VzQ29udGVudCI6WyIoZnVuY3Rpb24oKXtmdW5jdGlvbiBlKHQsbixyKXtmdW5jdGlvbiBzKG8sdSl7aWYoIW5bb10pe2lmKCF0W29dKXt2YXIgYT10eXBlb2YgcmVxdWlyZT09XCJmdW5jdGlvblwiJiZyZXF1aXJlO2lmKCF1JiZhKXJldHVybiBhKG8sITApO2lmKGkpcmV0dXJuIGkobywhMCk7dmFyIGY9bmV3IEVycm9yKFwiQ2Fubm90IGZpbmQgbW9kdWxlICdcIitvK1wiJ1wiKTt0aHJvdyBmLmNvZGU9XCJNT0RVTEVfTk9UX0ZPVU5EXCIsZn12YXIgbD1uW29dPXtleHBvcnRzOnt9fTt0W29dWzBdLmNhbGwobC5leHBvcnRzLGZ1bmN0aW9uKGUpe3ZhciBuPXRbb11bMV1bZV07cmV0dXJuIHMobj9uOmUpfSxsLGwuZXhwb3J0cyxlLHQsbixyKX1yZXR1cm4gbltvXS5leHBvcnRzfXZhciBpPXR5cGVvZiByZXF1aXJlPT1cImZ1bmN0aW9uXCImJnJlcXVpcmU7Zm9yKHZhciBvPTA7bzxyLmxlbmd0aDtvKyspcyhyW29dKTtyZXR1cm4gc31yZXR1cm4gZX0pKCkiLCIvLyBsb3RzIG9mIHN0dWZmIGhhcnZlc3RlZCBmcm9tIGQzLmpzXG4vLyBvbmx5IHJlYWwgZGlmZmVyZW5jZSBpcyByb3RhdGlvbiAvIHNjYWxlIC8gY2xpcHBwaW5nIGFuZCB0cmFuc2xhdGlvbiBvZlxuLy8gdGhlIGFsYXNrYSBwb3J0aW9uIG9mIGFsYmVyc1VzYVxuXG52YXIgZXBzaWxvbiQyID0gMWUtNjtcbmZ1bmN0aW9uIG5vb3AkMSgpIHt9XG52YXIgeDAkMiA9IEluZmluaXR5O1xudmFyIHkwJDIgPSB4MCQyO1xudmFyIHgxID0gLXgwJDI7XG52YXIgeTEgPSB4MTtcblxudmFyIGJvdW5kc1N0cmVhbSQxID0ge1xuICBwb2ludDogYm91bmRzUG9pbnQkMSxcbiAgbGluZVN0YXJ0OiBub29wJDEsXG4gIGxpbmVFbmQ6IG5vb3AkMSxcbiAgcG9seWdvblN0YXJ0OiBub29wJDEsXG4gIHBvbHlnb25FbmQ6IG5vb3AkMSxcbiAgcmVzdWx0OiBmdW5jdGlvbigpIHtcbiAgICB2YXIgYm91bmRzID0gW1t4MCQyLCB5MCQyXSwgW3gxLCB5MV1dO1xuICAgIHgxID0geTEgPSAtKHkwJDIgPSB4MCQyID0gSW5maW5pdHkpO1xuICAgIHJldHVybiBib3VuZHM7XG4gIH1cbn07XG5cbmZ1bmN0aW9uIGJvdW5kc1BvaW50JDEoeCwgeSkge1xuICBpZiAoeCA8IHgwJDIpIHgwJDIgPSB4O1xuICBpZiAoeCA+IHgxKSB4MSA9IHg7XG4gIGlmICh5IDwgeTAkMikgeTAkMiA9IHk7XG4gIGlmICh5ID4geTEpIHkxID0geTtcbn1cblxuZnVuY3Rpb24gZml0KHByb2plY3Rpb24sIGZpdEJvdW5kcywgb2JqZWN0KSB7XG4gIHZhciBjbGlwID0gcHJvamVjdGlvbi5jbGlwRXh0ZW50ICYmIHByb2plY3Rpb24uY2xpcEV4dGVudCgpO1xuICBwcm9qZWN0aW9uLnNjYWxlKDE1MCkudHJhbnNsYXRlKFswLCAwXSk7XG4gIGlmIChjbGlwICE9IG51bGwpIHByb2plY3Rpb24uY2xpcEV4dGVudChudWxsKTtcbiAgZDMuZ2VvU3RyZWFtKG9iamVjdCwgcHJvamVjdGlvbi5zdHJlYW0oYm91bmRzU3RyZWFtJDEpKTtcbiAgZml0Qm91bmRzKGJvdW5kc1N0cmVhbSQxLnJlc3VsdCgpKTtcbiAgaWYgKGNsaXAgIT0gbnVsbCkgcHJvamVjdGlvbi5jbGlwRXh0ZW50KGNsaXApO1xuICByZXR1cm4gcHJvamVjdGlvbjtcbn1cblxuZnVuY3Rpb24gZml0RXh0ZW50KHByb2plY3Rpb24sIGV4dGVudCwgb2JqZWN0KSB7XG4gIHJldHVybiBmaXQocHJvamVjdGlvbiwgZnVuY3Rpb24oYikge1xuICAgIHZhciB3ID0gZXh0ZW50WzFdWzBdIC0gZXh0ZW50WzBdWzBdLFxuICAgICAgICBoID0gZXh0ZW50WzFdWzFdIC0gZXh0ZW50WzBdWzFdLFxuICAgICAgICBrID0gTWF0aC5taW4odyAvIChiWzFdWzBdIC0gYlswXVswXSksIGggLyAoYlsxXVsxXSAtIGJbMF1bMV0pKSxcbiAgICAgICAgeCA9ICtleHRlbnRbMF1bMF0gKyAodyAtIGsgKiAoYlsxXVswXSArIGJbMF1bMF0pKSAvIDIsXG4gICAgICAgIHkgPSArZXh0ZW50WzBdWzFdICsgKGggLSBrICogKGJbMV1bMV0gKyBiWzBdWzFdKSkgLyAyO1xuICAgIHByb2plY3Rpb24uc2NhbGUoMTUwICogaykudHJhbnNsYXRlKFt4LCB5XSk7XG4gIH0sIG9iamVjdCk7XG59XG5cbmZ1bmN0aW9uIGZpdFNpemUocHJvamVjdGlvbiwgc2l6ZSwgb2JqZWN0KSB7XG4gIHJldHVybiBmaXRFeHRlbnQocHJvamVjdGlvbiwgW1swLCAwXSwgc2l6ZV0sIG9iamVjdCk7XG59XG5cbmZ1bmN0aW9uIGZpdFdpZHRoKHByb2plY3Rpb24sIHdpZHRoLCBvYmplY3QpIHtcbiAgcmV0dXJuIGZpdChwcm9qZWN0aW9uLCBmdW5jdGlvbihiKSB7XG4gICAgdmFyIHcgPSArd2lkdGgsXG4gICAgICAgIGsgPSB3IC8gKGJbMV1bMF0gLSBiWzBdWzBdKSxcbiAgICAgICAgeCA9ICh3IC0gayAqIChiWzFdWzBdICsgYlswXVswXSkpIC8gMixcbiAgICAgICAgeSA9IC1rICogYlswXVsxXTtcbiAgICBwcm9qZWN0aW9uLnNjYWxlKDE1MCAqIGspLnRyYW5zbGF0ZShbeCwgeV0pO1xuICB9LCBvYmplY3QpO1xufVxuXG5mdW5jdGlvbiBmaXRIZWlnaHQocHJvamVjdGlvbiwgaGVpZ2h0LCBvYmplY3QpIHtcbiAgcmV0dXJuIGZpdChwcm9qZWN0aW9uLCBmdW5jdGlvbihiKSB7XG4gICAgdmFyIGggPSAraGVpZ2h0LFxuICAgICAgICBrID0gaCAvIChiWzFdWzFdIC0gYlswXVsxXSksXG4gICAgICAgIHggPSAtayAqIGJbMF1bMF0sXG4gICAgICAgIHkgPSAoaCAtIGsgKiAoYlsxXVsxXSArIGJbMF1bMV0pKSAvIDI7XG4gICAgcHJvamVjdGlvbi5zY2FsZSgxNTAgKiBrKS50cmFuc2xhdGUoW3gsIHldKTtcbiAgfSwgb2JqZWN0KTtcbn1cblxuZnVuY3Rpb24gbXVsdGlwbGV4KHN0cmVhbXMpIHtcbiAgdmFyIG4gPSBzdHJlYW1zLmxlbmd0aDtcbiAgcmV0dXJuIHtcbiAgICBwb2ludDogZnVuY3Rpb24oeCwgeSkgeyB2YXIgaSA9IC0xOyB3aGlsZSAoKytpIDwgbikgc3RyZWFtc1tpXS5wb2ludCh4LCB5KTsgfSxcbiAgICBzcGhlcmU6IGZ1bmN0aW9uKCkgeyB2YXIgaSA9IC0xOyB3aGlsZSAoKytpIDwgbikgc3RyZWFtc1tpXS5zcGhlcmUoKTsgfSxcbiAgICBsaW5lU3RhcnQ6IGZ1bmN0aW9uKCkgeyB2YXIgaSA9IC0xOyB3aGlsZSAoKytpIDwgbikgc3RyZWFtc1tpXS5saW5lU3RhcnQoKTsgfSxcbiAgICBsaW5lRW5kOiBmdW5jdGlvbigpIHsgdmFyIGkgPSAtMTsgd2hpbGUgKCsraSA8IG4pIHN0cmVhbXNbaV0ubGluZUVuZCgpOyB9LFxuICAgIHBvbHlnb25TdGFydDogZnVuY3Rpb24oKSB7IHZhciBpID0gLTE7IHdoaWxlICgrK2kgPCBuKSBzdHJlYW1zW2ldLnBvbHlnb25TdGFydCgpOyB9LFxuICAgIHBvbHlnb25FbmQ6IGZ1bmN0aW9uKCkgeyB2YXIgaSA9IC0xOyB3aGlsZSAoKytpIDwgbikgc3RyZWFtc1tpXS5wb2x5Z29uRW5kKCk7IH1cbiAgfTtcbn1cblxuLy8gQSBjb21wb3NpdGUgcHJvamVjdGlvbiBmb3IgdGhlIFVuaXRlZCBTdGF0ZXMsIGNvbmZpZ3VyZWQgYnkgZGVmYXVsdCBmb3Jcbi8vIDk2MMOXNTAwLiBUaGUgcHJvamVjdGlvbiBhbHNvIHdvcmtzIHF1aXRlIHdlbGwgYXQgOTYww5c2MDAgaWYgeW91IGNoYW5nZSB0aGVcbi8vIHNjYWxlIHRvIDEyODUgYW5kIGFkanVzdCB0aGUgdHJhbnNsYXRlIGFjY29yZGluZ2x5LiBUaGUgc2V0IG9mIHN0YW5kYXJkXG4vLyBwYXJhbGxlbHMgZm9yIGVhY2ggcmVnaW9uIGNvbWVzIGZyb20gVVNHUywgd2hpY2ggaXMgcHVibGlzaGVkIGhlcmU6XG4vLyBodHRwOi8vZWdzYy51c2dzLmdvdi9pc2IvcHVicy9NYXBQcm9qZWN0aW9ucy9wcm9qZWN0aW9ucy5odG1sI2FsYmVyc1xuZXhwb3J0IGZ1bmN0aW9uIGFsYmVyc0JpZ0FsYXNrYSgpIHtcbiAgdmFyIGNhY2hlLFxuICAgICAgY2FjaGVTdHJlYW0sXG4gICAgICBsb3dlcjQ4ID0gZDMuZ2VvQWxiZXJzKCksIGxvd2VyNDhQb2ludCxcbiAgICAgIGFsYXNrYSA9IGQzLmdlb0NvbmljRXF1YWxBcmVhKCkucm90YXRlKFsxNTQsIDBdKS5jZW50ZXIoWy0yLCA1OC41XSkucGFyYWxsZWxzKFs1NSwgNjVdKSwgYWxhc2thUG9pbnQsIC8vIEVQU0c6MzMzOFxuICAgICAgaGF3YWlpID0gZDMuZ2VvQ29uaWNFcXVhbEFyZWEoKS5yb3RhdGUoWzE1NywgMF0pLmNlbnRlcihbLTMsIDE5LjldKS5wYXJhbGxlbHMoWzgsIDE4XSksIGhhd2FpaVBvaW50LCAvLyBFU1JJOjEwMjAwN1xuICAgICAgcG9pbnQsIHBvaW50U3RyZWFtID0ge3BvaW50OiBmdW5jdGlvbih4LCB5KSB7IHBvaW50ID0gW3gsIHldOyB9fTtcblxuICBmdW5jdGlvbiBhbGJlcnNVc2EoY29vcmRpbmF0ZXMpIHtcbiAgICB2YXIgeCA9IGNvb3JkaW5hdGVzWzBdLCB5ID0gY29vcmRpbmF0ZXNbMV07XG4gICAgcmV0dXJuIHBvaW50ID0gbnVsbCwgKGxvd2VyNDhQb2ludC5wb2ludCh4LCB5KSwgcG9pbnQpXG4gICAgICAgIHx8IChhbGFza2FQb2ludC5wb2ludCh4LCB5KSwgcG9pbnQpXG4gICAgICAgIHx8IChoYXdhaWlQb2ludC5wb2ludCh4LCB5KSwgcG9pbnQpO1xuICB9XG5cbiAgYWxiZXJzVXNhLmludmVydCA9IGZ1bmN0aW9uKGNvb3JkaW5hdGVzKSB7XG4gICAgdmFyIGsgPSBsb3dlcjQ4LnNjYWxlKCksXG4gICAgICAgIHQgPSBsb3dlcjQ4LnRyYW5zbGF0ZSgpLFxuICAgICAgICB4ID0gKGNvb3JkaW5hdGVzWzBdIC0gdFswXSkgLyBrLFxuICAgICAgICB5ID0gKGNvb3JkaW5hdGVzWzFdIC0gdFsxXSkgLyBrO1xuICAgIHJldHVybiAoeSA+PSAwLjEyMCAmJiB5IDwgMC4yMzQgJiYgeCA+PSAtMC40MjUgJiYgeCA8IC0wLjIxNCA/IGFsYXNrYVxuICAgICAgICA6IHkgPj0gMC4xNjYgJiYgeSA8IDAuMjM0ICYmIHggPj0gLTAuMjE0ICYmIHggPCAtMC4xMTUgPyBoYXdhaWlcbiAgICAgICAgOiBsb3dlcjQ4KS5pbnZlcnQoY29vcmRpbmF0ZXMpO1xuICB9O1xuXG4gIGFsYmVyc1VzYS5zdHJlYW0gPSBmdW5jdGlvbihzdHJlYW0pIHtcbiAgICByZXR1cm4gY2FjaGUgJiYgY2FjaGVTdHJlYW0gPT09IHN0cmVhbSA/IGNhY2hlIDogY2FjaGUgPSBtdWx0aXBsZXgoW2xvd2VyNDguc3RyZWFtKGNhY2hlU3RyZWFtID0gc3RyZWFtKSwgYWxhc2thLnN0cmVhbShzdHJlYW0pLCBoYXdhaWkuc3RyZWFtKHN0cmVhbSldKTtcbiAgfTtcblxuICBhbGJlcnNVc2EucHJlY2lzaW9uID0gZnVuY3Rpb24oXykge1xuICAgIGlmICghYXJndW1lbnRzLmxlbmd0aCkgcmV0dXJuIGxvd2VyNDgucHJlY2lzaW9uKCk7XG4gICAgbG93ZXI0OC5wcmVjaXNpb24oXyksIGFsYXNrYS5wcmVjaXNpb24oXyksIGhhd2FpaS5wcmVjaXNpb24oXyk7XG4gICAgcmV0dXJuIHJlc2V0KCk7XG4gIH07XG5cbiAgYWxiZXJzVXNhLnNjYWxlID0gZnVuY3Rpb24oXykge1xuICAgIGlmICghYXJndW1lbnRzLmxlbmd0aCkgcmV0dXJuIGxvd2VyNDguc2NhbGUoKTtcbiAgICBsb3dlcjQ4LnNjYWxlKF8pLCBhbGFza2Euc2NhbGUoXyAqIDAuNTIpLCBoYXdhaWkuc2NhbGUoXyk7XG4gICAgcmV0dXJuIGFsYmVyc1VzYS50cmFuc2xhdGUobG93ZXI0OC50cmFuc2xhdGUoKSk7XG4gIH07XG5cbiAgYWxiZXJzVXNhLnRyYW5zbGF0ZSA9IGZ1bmN0aW9uKF8pIHtcbiAgICBpZiAoIWFyZ3VtZW50cy5sZW5ndGgpIHJldHVybiBsb3dlcjQ4LnRyYW5zbGF0ZSgpO1xuICAgIHZhciBrID0gbG93ZXI0OC5zY2FsZSgpLCB4ID0gK19bMF0sIHkgPSArX1sxXTtcblxuICAgIGxvd2VyNDhQb2ludCA9IGxvd2VyNDhcbiAgICAgICAgLnRyYW5zbGF0ZShfKVxuICAgICAgICAuY2xpcEV4dGVudChbW3ggLSAwLjQ1NSAqIGssIHkgLSAwLjIzOCAqIGtdLCBbeCArIDAuNDU1ICogaywgeSArIDAuMjM4ICoga11dKVxuICAgICAgICAuc3RyZWFtKHBvaW50U3RyZWFtKTtcblxuICAgIGFsYXNrYVBvaW50ID0gYWxhc2thXG4gICAgICAgIC50cmFuc2xhdGUoW3ggLSAwLjMwNyAqIGssIHkgKyAwLjIxMSAqIGtdKVxuICAgICAgICAuY2xpcEV4dGVudChbW3ggLSAwLjQyNSAqIGsgKyBlcHNpbG9uJDIsIHkgKyAwLjAyMCAqIGsgKyBlcHNpbG9uJDJdLCBbeCAtIDAuMTg0ICogayAtIGVwc2lsb24kMiwgeSArIDAuMjU0ICogayAtIGVwc2lsb24kMl1dKVxuICAgICAgICAuc3RyZWFtKHBvaW50U3RyZWFtKTtcblxuICAgIGhhd2FpaVBvaW50ID0gaGF3YWlpXG4gICAgICAgIC50cmFuc2xhdGUoW3ggLSAwLjIwNSAqIGssIHkgKyAwLjIxMiAqIGtdKVxuICAgICAgICAuY2xpcEV4dGVudChbW3ggLSAwLjIxNCAqIGsgKyBlcHNpbG9uJDIsIHkgKyAwLjE2NiAqIGsgKyBlcHNpbG9uJDJdLCBbeCAtIDAuMTE1ICogayAtIGVwc2lsb24kMiwgeSArIDAuMjM0ICogayAtIGVwc2lsb24kMl1dKVxuICAgICAgICAuc3RyZWFtKHBvaW50U3RyZWFtKTtcblxuICAgIHJldHVybiByZXNldCgpO1xuICB9O1xuXG4gIGFsYmVyc1VzYS5maXRFeHRlbnQgPSBmdW5jdGlvbihleHRlbnQsIG9iamVjdCkge1xuICAgIHJldHVybiBmaXRFeHRlbnQoYWxiZXJzVXNhLCBleHRlbnQsIG9iamVjdCk7XG4gIH07XG5cbiAgYWxiZXJzVXNhLmZpdFNpemUgPSBmdW5jdGlvbihzaXplLCBvYmplY3QpIHtcbiAgICByZXR1cm4gZml0U2l6ZShhbGJlcnNVc2EsIHNpemUsIG9iamVjdCk7XG4gIH07XG5cbiAgYWxiZXJzVXNhLmZpdFdpZHRoID0gZnVuY3Rpb24od2lkdGgsIG9iamVjdCkge1xuICAgIHJldHVybiBmaXRXaWR0aChhbGJlcnNVc2EsIHdpZHRoLCBvYmplY3QpO1xuICB9O1xuXG4gIGFsYmVyc1VzYS5maXRIZWlnaHQgPSBmdW5jdGlvbihoZWlnaHQsIG9iamVjdCkge1xuICAgIHJldHVybiBmaXRIZWlnaHQoYWxiZXJzVXNhLCBoZWlnaHQsIG9iamVjdCk7XG4gIH07XG5cbiAgZnVuY3Rpb24gcmVzZXQoKSB7XG4gICAgY2FjaGUgPSBjYWNoZVN0cmVhbSA9IG51bGw7XG4gICAgcmV0dXJuIGFsYmVyc1VzYTtcbiAgfVxuXG4gIHJldHVybiBhbGJlcnNVc2Euc2NhbGUoMTA3MCk7XG59XG4iLCIvLyBCaXJkIERvdCBhbmltYXRpb25zXG5cblxuZnVuY3Rpb24gYW5pbWF0ZUNvdW50KGVsZW1lbnQsIHN0YXJ0LCBlbmQsIGR1cmF0aW9uKSB7XG4gICAgLy8gZW5kIGlzIGEgbnVtYmVyIHN0YXJ0IGlzIGEgbnVtYmVyXG4gICAgY29uc3QgaW50ZXJwb2xhdG9yID0gZDMuaW50ZXJwb2xhdGVOdW1iZXIoc3RhcnQsIGVuZCk7XG4gICAgbGV0IGFuaW1hdGlvblRpbWVyO1xuXG4gICAgZnVuY3Rpb24gYW5pbWF0aW9uRnVuYyhlbGFwc2VkKSB7XG4gICAgICBjb25zdCBzdGVwID0gZWxhcHNlZCAvIGR1cmF0aW9uO1xuICAgICAgaWYgKHN0ZXAgPj0gMSkge1xuICAgICAgICBhbmltYXRpb25UaW1lci5zdG9wKCk7XG4gICAgICAgIHJldHVybjtcbiAgICAgIH1cbiAgICAgIGxldCBudW0gPSBNYXRoLnJvdW5kKGludGVycG9sYXRvcihkMy5lYXNlUXVhZEluT3V0KHN0ZXApKSk7XG4gICAgICBlbGVtZW50LnRleHQobnVtKTtcbiAgICB9XG5cbiAgICBhbmltYXRpb25UaW1lciA9IGQzLnRpbWVyKGFuaW1hdGlvbkZ1bmMpO1xufVxuXG5cblxuZnVuY3Rpb24gR3JpZEhlbHBlcihyYWRpdXMsIHNwYWNpbmcsIG51bURvdHMpIHtcblxuXG4gICAgbGV0IF9jb2xTY2FsZSA9IGQzLnNjYWxlTGluZWFyKClcbiAgICAgICAgLmRvbWFpbihbODAsIDkxLCAxMDksIDEyN10pXG4gICAgICAgIC5yYW5nZShbNSwgNiwgNywgOF0pXG4gICAgICAgIC5jbGFtcCh0cnVlKTtcblxuICAgIGZ1bmN0aW9uIGNvbFNjYWxlKG51bURvdHMpIHtcbiAgICAgICAgcmV0dXJuIE1hdGguZmxvb3IoX2NvbFNjYWxlKG51bURvdHMpKTtcbiAgICB9XG5cbiAgICBsZXQgY29scyA9IGNvbFNjYWxlKG51bURvdHMpO1xuICAgIGxldCBudW1Sb3dzID0gTWF0aC5jZWlsKG51bURvdHMgLyBjb2xzKTtcbiAgICBsZXQgb2Zmc2V0ID0gbnVtUm93cyAqIGNvbHMgLSBudW1Eb3RzO1xuXG4gICAgZnVuY3Rpb24gZ3JpZFBvc2l0aW9uKGlkeCkge1xuICAgICAgICBpZHggKz0gb2Zmc2V0O1xuICAgICAgICBsZXQgcm93ID0gTWF0aC5mbG9vcihpZHggLyBjb2xzKTtcbiAgICAgICAgbGV0IGNvbCA9IGlkeCAtIChyb3cgKiBjb2xzKTtcblxuICAgICAgICByZXR1cm4ge1xuICAgICAgICAgICAgeDogY29sICogc3BhY2luZyxcbiAgICAgICAgICAgIHk6IHJvdyAqIHNwYWNpbmdcbiAgICAgICAgfVxuICAgIH1cblxuICAgIGxldCB3aWR0aCA9IGNvbHMgKiBzcGFjaW5nO1xuICAgIGxldCBoZWlnaHQgPSBudW1Sb3dzICogc3BhY2luZztcblxuICAgIHJldHVybiB7XG4gICAgICAgIGdyaWRQb3NpdGlvbjogZ3JpZFBvc2l0aW9uLFxuICAgICAgICBoZWlnaHQ6IGhlaWdodCxcbiAgICAgICAgd2lkdGg6IHdpZHRoXG4gICAgfVxufVxuXG5cbmZ1bmN0aW9uIHJhbmRvbUJpcmRQb3MoKSB7XG4gICAgcmV0dXJuIHtcbiAgICAgICAgeDogLTEwMCArIE1hdGgucmFuZG9tKCkgKiAyMDAgKyAyMCxcbiAgICAgICAgeTogLTMwMFxuICAgIH1cbn1cblxuZnVuY3Rpb24gZ2VuZXJhdGVQb2ludHMoZGF0YSwgZ3JpZEhlbHBlcikge1xuICAgIGNvbnN0IHsgbnVtQ29sb25pemVkLCBudW1DdXJyZW50LCBudW1FeHRpcnBhdGVkIH0gPSBkYXRhO1xuICAgIGxldCBudW1SZW1haW5pbmcgPSBudW1DdXJyZW50IC0gbnVtRXh0aXJwYXRlZDtcblxuICAgIGxldCBjb2xvcnMgPSB7XG4gICAgICAgIGNvbG9uaXplZDogJyMxOGExYWQnLFxuICAgICAgICBjdXJyZW50OiAnIzkwZDJkOCcsXG4gICAgICAgIGV4dGlycGF0ZWQ6ICcjZThjNTc4J1xuICAgIH1cblxuICAgIGxldCBjYyA9IGQzLnJhbmdlKG51bUNvbG9uaXplZCkubWFwKGkgPT4ge1xuICAgICAgICByZXR1cm4ge1xuICAgICAgICAgICAgaW5pdFBvczogcmFuZG9tQmlyZFBvcygpLFxuICAgICAgICAgICAgZmluYWxQb3M6IGdyaWRIZWxwZXIuZ3JpZFBvc2l0aW9uKGkpLFxuICAgICAgICAgICAgbGFiZWw6ICdDJyxcbiAgICAgICAgICAgIGluaXRGaWxsT3BhY2l0eTogMCxcbiAgICAgICAgICAgIGluaXRGaWxsOiBjb2xvcnMuY29sb25pemVkLFxuICAgICAgICAgICAgZmluYWxGaWxsT3BhY2l0eTogMSxcbiAgICAgICAgICAgIGZpbmFsRmlsbDogY29sb3JzLmNvbG9uaXplZFxuICAgICAgICB9XG4gICAgfSk7XG5cbiAgICBsZXQgZGQgPSBkMy5yYW5nZShudW1SZW1haW5pbmcpLm1hcChpID0+IHtcbiAgICAgICAgcmV0dXJuIHtcbiAgICAgICAgICAgIGluaXRQb3M6IGdyaWRIZWxwZXIuZ3JpZFBvc2l0aW9uKGkgKyBudW1Db2xvbml6ZWQpLFxuICAgICAgICAgICAgZmluYWxQb3M6IGdyaWRIZWxwZXIuZ3JpZFBvc2l0aW9uKGkgKyBudW1Db2xvbml6ZWQpLFxuICAgICAgICAgICAgbGFiZWw6ICdSJyxcbiAgICAgICAgICAgIGluaXRGaWxsT3BhY2l0eTogMSxcbiAgICAgICAgICAgIGluaXRGaWxsOiBjb2xvcnMuY3VycmVudCxcbiAgICAgICAgICAgIGZpbmFsRmlsbE9wYWNpdHk6IDEsXG4gICAgICAgICAgICBmaW5hbEZpbGw6IGNvbG9ycy5jdXJyZW50XG4gICAgICAgIH1cbiAgICB9KTtcblxuICAgIGxldCBlZSA9IGQzLnJhbmdlKG51bUV4dGlycGF0ZWQpLm1hcChpID0+IHtcbiAgICAgICAgbGV0IGZpbmFsUG9zID0gZ3JpZEhlbHBlci5ncmlkUG9zaXRpb24oaSArIG51bUNvbG9uaXplZCArIG51bVJlbWFpbmluZyk7XG4gICAgICAgIGZpbmFsUG9zLnkgKz0gMTA7XG5cbiAgICAgICAgcmV0dXJuIHtcbiAgICAgICAgICAgIGluaXRQb3M6IGdyaWRIZWxwZXIuZ3JpZFBvc2l0aW9uKGkgKyBudW1Db2xvbml6ZWQgKyBudW1SZW1haW5pbmcpLFxuICAgICAgICAgICAgZmluYWxQb3M6IGZpbmFsUG9zLFxuICAgICAgICAgICAgbGFiZWw6ICdFJyxcbiAgICAgICAgICAgIGluaXRGaWxsT3BhY2l0eTogMSxcbiAgICAgICAgICAgIGluaXRGaWxsOiBjb2xvcnMuY3VycmVudCxcbiAgICAgICAgICAgIGZpbmFsRmlsbE9wYWNpdHk6IDEsXG4gICAgICAgICAgICBmaW5hbEZpbGw6IGNvbG9ycy5leHRpcnBhdGVkXG4gICAgICAgIH1cbiAgICB9KVxuXG4gICAgcmV0dXJuIGNjLmNvbmNhdChkZCkuY29uY2F0KGVlKTtcblxufVxuXG5mdW5jdGlvbiBfQmlyZERvdHMocGFyYW1zKSB7XG4gICAgLy8gYXR0YWNoZXMgYW4gc3ZnIHRvIHRoZSBlbGVtZW50XG4gICAgY29uc3QgeyBlbGVtZW50LCBudW1Db2xvbml6ZWQsIG51bUN1cnJlbnQsIG51bUV4dGlycGF0ZWQsXG4gICAgICAgIGNvbG9uaXplZENvdW50ZXIsIGV4dGlycGF0ZWRDb3VudGVyLCBvbkxvYWR9ID0gcGFyYW1zO1xuXG4gICAgbGV0IHJhZGl1cyA9IDM7XG4gICAgbGV0IHNwYWNpbmcgPSA2O1xuICAgIGxldCBncmlkSGVscGVyID0gbmV3IEdyaWRIZWxwZXIocmFkaXVzLCBzcGFjaW5nLCBudW1DdXJyZW50ICsgbnVtQ29sb25pemVkKTtcblxuICAgIGxldCBkYXRhID0gZ2VuZXJhdGVQb2ludHMocGFyYW1zLCBncmlkSGVscGVyKTtcblxuICAgIGxldCBzdmdDb250YWluZXIgPSBkMy5zZWxlY3QoZWxlbWVudClcbiAgICAgICAgLmFwcGVuZCgnc3ZnJylcbiAgICAgICAgICAgIC5hdHRyKCd3aWR0aCcsIDQwMClcbiAgICAgICAgICAgIC5hdHRyKCdoZWlnaHQnLCA0MDApO1xuXG4gICAgbGV0IHN2ZyA9IHN2Z0NvbnRhaW5lci5hcHBlbmQoJ2cnKTtcblxuICAgIGZ1bmN0aW9uIGFsaWduRG90cygpIHtcbiAgICAgICAgbGV0IFtkb3RCb3hXaWR0aCwgZG90Qm94SGVpZ2h0XSA9IFtncmlkSGVscGVyLndpZHRoLCBncmlkSGVscGVyLmhlaWdodF07XG5cbiAgICAgICAgbGV0IGRpdkNvbnRhaW5lciA9IGQzLnNlbGVjdChlbGVtZW50KTtcblxuICAgICAgICBsZXQgZGl2V2lkdGggPSBkaXZDb250YWluZXIubm9kZSgpLm9mZnNldFdpZHRoO1xuICAgICAgICBsZXQgZGl2SGVpZ2h0ID0gZGl2Q29udGFpbmVyLm5vZGUoKS5vZmZzZXRIZWlnaHQ7XG5cbiAgICAgICAgbGV0IG9mZnNldFkgPSAoZGl2SGVpZ2h0IC0gZG90Qm94SGVpZ2h0KSAvIDJcbiAgICAgICAgbGV0IG9mZnNldFggPSAoZGl2V2lkdGggLSBkb3RCb3hXaWR0aCkgLyAyXG5cbiAgICAgICAgbGV0IHN2Z09mZnNldFkgPSBNYXRoLmFicyhwYXJzZUludChzdmdDb250YWluZXIuc3R5bGUoJ3RvcCcpKSk7XG4gICAgICAgIGxldCBzdmdPZmZzZXRYID0gTWF0aC5hYnMocGFyc2VJbnQoc3ZnQ29udGFpbmVyLnN0eWxlKCdsZWZ0JykpKTtcblxuICAgICAgICBsZXQgdHJhbnNsYXRlWCA9IG9mZnNldFggKyBzdmdPZmZzZXRYO1xuICAgICAgICBsZXQgdHJhbnNsYXRlWSA9IG9mZnNldFkgKyBzdmdPZmZzZXRZO1xuXG4gICAgICAgIHN2Zy5hdHRyKCd0cmFuc2Zvcm0nLCBgdHJhbnNsYXRlKCR7dHJhbnNsYXRlWH0sICR7dHJhbnNsYXRlWX0pYCk7XG4gICAgfVxuXG4gICAgYWxpZ25Eb3RzKCk7XG5cbiAgICBsZXQgY29sb25pemVkSW5WaWV3ID0gZmFsc2U7XG4gICAgbGV0IGV4dGlycGF0ZWRJblZpZXcgPSBmYWxzZTtcbiAgICBsZXQgZGlzYWJsZWRPcGFjaXR5ID0gMC4yO1xuXG4gICAgbGV0IGRvdHMgPSBzdmcuc2VsZWN0QWxsKCcuZG90JykuZGF0YShkYXRhKTtcbiAgICBkb3RzLmVudGVyKClcbiAgICAgICAgLmFwcGVuZCgnY2lyY2xlJylcbiAgICAgICAgLmF0dHIoJ2NsYXNzJywgJ2RvdCcpXG4gICAgICAgIC5jbGFzc2VkKCdSJyxkID0+IGQubGFiZWwgPT0gJ1InKVxuICAgICAgICAuY2xhc3NlZCgnRScsIGQgPT4gZC5sYWJlbCA9PSAnRScpXG4gICAgICAgIC5jbGFzc2VkKCdDJywgZCA9PiBkLmxhYmVsID09ICdDJylcbiAgICAgICAgLmF0dHIoJ2N4JywgZCA9PiBkLmluaXRQb3MueClcbiAgICAgICAgLmF0dHIoJ2N5JywgZCA9PiBkLmluaXRQb3MueSlcbiAgICAgICAgLmF0dHIoJ3InLCByYWRpdXMpXG4gICAgICAgIC5hdHRyKCdmaWxsLW9wYWNpdHknLCBkID0+IGQuaW5pdEZpbGxPcGFjaXR5KVxuICAgICAgICAuYXR0cignZmlsbCcsIGQgPT4gZC5pbml0RmlsbCk7XG5cbiAgICAvLyAvLyBqdXN0IHRoZSBzZXBhcmF0aW9uXG4gICAgLy8gLy8gd2Ugd2FudCB0byBzdGFnZXIgdGhlIG1vdmVtZW50IG9mIHRoZVxuXG4gICAgZnVuY3Rpb24gZW50ZXJDb2xvbml6ZWQob25GaW5pc2hlZCkge1xuICAgICAgICBsZXQgbiA9IG51bUNvbG9uaXplZDtcbiAgICAgICAgc3ZnLnNlbGVjdEFsbCgnLmRvdC5DJylcbiAgICAgICAgICAgIC5jbGFzc2VkKCduZXctdmlzaWJsZScsIHRydWUpXG4gICAgICAgICAgICAudHJhbnNpdGlvbigpXG4gICAgICAgICAgICAuZWFzZShkMy5lYXNlUXVhZEluT3V0KVxuICAgICAgICAgICAgLmR1cmF0aW9uKChkLCBpKSA9PiBNYXRoLnJhbmRvbSgpICogMzAwICsgOTUwKVxuICAgICAgICAgICAgLmRlbGF5KChkLCBpKSA9PiAobnVtQ29sb25pemVkIC0gaSkgKiAyMClcbiAgICAgICAgICAgIC5hdHRyKCdjeCcsIGQgPT4gZC5maW5hbFBvcy54KVxuICAgICAgICAgICAgLmF0dHIoJ2N5JywgZCA9PiBkLmZpbmFsUG9zLnkpXG4gICAgICAgICAgICAuYXR0cignZmlsbC1vcGFjaXR5JywgZCA9PiBkLmZpbmFsRmlsbE9wYWNpdHkpXG4gICAgICAgICAgICAuYXR0cignZmlsbCcsIGQgPT4gZC5maW5hbEZpbGwpXG4gICAgICAgICAgICAub24oJ2VuZCcsIChkLCBpKSA9PiB7XG4gICAgICAgICAgICAgICAgbi0tO1xuICAgICAgICAgICAgICAgIGlmIChuID09IDApIHtcbiAgICAgICAgICAgICAgICAgICAgaWYgKG9uRmluaXNoZWQpIHtcbiAgICAgICAgICAgICAgICAgICAgICAgIG9uRmluaXNoZWQoKTtcbiAgICAgICAgICAgICAgICAgICAgfVxuICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgIH0pO1xuICAgICAgICBjb2xvbml6ZWRJblZpZXcgPSB0cnVlO1xuICAgIH1cblxuICAgIGZ1bmN0aW9uIGV4aXRDb2xvbml6ZWQob25GaW5pc2hlZCkge1xuICAgICAgICBsZXQgbiA9IG51bUNvbG9uaXplZDtcbiAgICAgICAgc3ZnLnNlbGVjdEFsbCgnLmRvdC5DJylcbiAgICAgICAgICAgIC5jbGFzc2VkKCduZXctdmlzaWJsZScsIGZhbHNlKVxuICAgICAgICAgICAgLnRyYW5zaXRpb24oKVxuICAgICAgICAgICAgLmVhc2UoZDMuZWFzZVF1YWRJbk91dClcbiAgICAgICAgICAgIC5kdXJhdGlvbigoZCwgaSkgPT4gTWF0aC5yYW5kb20oKSAqIDMwMCArIDk1MClcbiAgICAgICAgICAgIC5kZWxheSgoZCwgaSkgPT4gaSAqIDIwKVxuICAgICAgICAgICAgLmF0dHIoJ2N4JywgZCA9PiBkLmluaXRQb3MueClcbiAgICAgICAgICAgIC5hdHRyKCdjeScsIGQgPT4gZC5pbml0UG9zLnkpXG4gICAgICAgICAgICAuYXR0cignZmlsbC1vcGFjaXR5JywgZCA9PiBkLmluaXRGaWxsT3BhY2l0eSlcbiAgICAgICAgICAgIC5hdHRyKCdmaWxsJywgZCA9PiBkLmluaXRGaWxsKVxuICAgICAgICAgICAgLm9uKCdlbmQnLCAoZCwgaSkgPT4ge1xuICAgICAgICAgICAgICAgIG4tLTtcbiAgICAgICAgICAgICAgICBpZiAobiA9PSAwKSB7XG4gICAgICAgICAgICAgICAgICAgIGlmIChvbkZpbmlzaGVkKSB7XG4gICAgICAgICAgICAgICAgICAgICAgICBvbkZpbmlzaGVkKCk7XG4gICAgICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgICAgICB9XG4gICAgICAgICAgICB9KTtcbiAgICAgICAgY29sb25pemVkSW5WaWV3ID0gZmFsc2U7XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gZW50ZXJFeHRpcnBhdGVkKG9uRmluaXNoZWQpIHtcbiAgICAgICAgbGV0IG4gPSBudW1FeHRpcnBhdGVkO1xuICAgICAgICBzdmcuc2VsZWN0QWxsKCcuZG90LkUnKVxuICAgICAgICAgICAgLmNsYXNzZWQoJ2V4dGlycGF0ZWQtdmlzaWJsZScsIHRydWUpXG4gICAgICAgICAgICAudHJhbnNpdGlvbigpXG4gICAgICAgICAgICAuZHVyYXRpb24oKGQsIGkpID0+IE1hdGgucmFuZG9tKCkgKiAyMDAgKyAyNTApXG4gICAgICAgICAgICAuZGVsYXkoKGQsIGkpID0+IChudW1FeHRpcnBhdGVkIC0gaSkgKiAyMClcbiAgICAgICAgICAgIC5hdHRyKCdjeCcsIGQgPT4gZC5maW5hbFBvcy54KVxuICAgICAgICAgICAgLmF0dHIoJ2N5JywgZCA9PiBkLmZpbmFsUG9zLnkpXG4gICAgICAgICAgICAuYXR0cignZmlsbCcsIGQgPT4gZC5maW5hbEZpbGwpXG4gICAgICAgICAgICAub24oJ2VuZCcsIChkLCBpKSA9PiB7XG4gICAgICAgICAgICAgICAgbi0tO1xuICAgICAgICAgICAgICAgIGlmIChuID09IDApIHtcbiAgICAgICAgICAgICAgICAgICAgaWYgKG9uRmluaXNoZWQpIHtcbiAgICAgICAgICAgICAgICAgICAgICAgIG9uRmluaXNoZWQoKTtcbiAgICAgICAgICAgICAgICAgICAgfVxuICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgIH0pO1xuICAgICAgICBleHRpcnBhdGVkSW5WaWV3ID0gdHJ1ZTtcbiAgICB9XG5cbiAgICBmdW5jdGlvbiBleGl0RXh0aXJwYXRlZChvbkZpbmlzaGVkKSB7XG4gICAgICAgIGxldCBuID0gbnVtRXh0aXJwYXRlZDtcbiAgICAgICAgc3ZnLnNlbGVjdEFsbCgnLmRvdC5FJylcbiAgICAgICAgICAgIC50cmFuc2l0aW9uKClcbiAgICAgICAgICAgIC5kdXJhdGlvbigoZCwgaSkgPT4gTWF0aC5yYW5kb20oKSAqIDIwMCArIDI1MClcbiAgICAgICAgICAgIC5kZWxheSgoZCwgaSkgPT4gaSAqIDIwKVxuICAgICAgICAgICAgLmF0dHIoJ2N4JywgZCA9PiBkLmluaXRQb3MueClcbiAgICAgICAgICAgIC5hdHRyKCdjeScsIGQgPT4gZC5pbml0UG9zLnkpXG4gICAgICAgICAgICAuYXR0cignZmlsbCcsIGQgPT4gZC5pbml0RmlsbClcbiAgICAgICAgICAgIC5vbignZW5kJywgKGQsIGkpID0+IHtcbiAgICAgICAgICAgICAgICBuLS07XG4gICAgICAgICAgICAgICAgaWYgKG4gPT0gMCkge1xuICAgICAgICAgICAgICAgICAgICBpZiAob25GaW5pc2hlZCkge1xuICAgICAgICAgICAgICAgICAgICAgICAgb25GaW5pc2hlZCgpO1xuICAgICAgICAgICAgICAgICAgICB9XG4gICAgICAgICAgICAgICAgfVxuICAgICAgICAgICAgfSk7XG4gICAgICAgIGV4dGlycGF0ZWRJblZpZXcgPSBmYWxzZTtcbiAgICB9XG5cbiAgICBmdW5jdGlvbiBqaWdnbGUoc2VsZWN0aW9uKSB7XG4gICAgICAgIHNlbGVjdGlvblxuICAgICAgICAgICAgLnRyYW5zaXRpb24oKVxuICAgICAgICAgICAgLmR1cmF0aW9uKChkLCBpKSA9PiBNYXRoLnJhbmRvbSgpICogMjAwICsgMTAwKVxuICAgICAgICAgICAgLmF0dHIoJ2N5JywgZCA9PiBkLmZpbmFsUG9zLnkgLSAyKVxuICAgICAgICAgICAgLnRyYW5zaXRpb24oKVxuICAgICAgICAgICAgLmR1cmF0aW9uKDIwMClcbiAgICAgICAgICAgIC5hdHRyKCdjeScsIGQgPT4gZC5maW5hbFBvcy55KTtcbiAgICB9XG5cbiAgICBmdW5jdGlvbiBoaWdobGlnaHRFeHRpcnBhdGVkKCkge1xuICAgICAgICBzdmcuc2VsZWN0QWxsKCcuZG90LkUnKS5jYWxsKGppZ2dsZSk7XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gaGlnaGxpZ2h0Q29sb25pemF0aW9ucygpIHtcbiAgICAgICAgc3ZnLnNlbGVjdEFsbCgnLmRvdC5DJykuY2FsbChqaWdnbGUpO1xuICAgIH1cblxuICAgIGZ1bmN0aW9uIGFuaW1hdGVJbigpIHtcbiAgICAgICAgYW5pbWF0ZUNvdW50KGQzLnNlbGVjdChjb2xvbml6ZWRDb3VudGVyKSwgMCwgbnVtQ29sb25pemVkLCAxMjAwKTtcbiAgICAgICAgZW50ZXJDb2xvbml6ZWQoKCkgPT4ge1xuICAgICAgICAgICAgYW5pbWF0ZUNvdW50KGQzLnNlbGVjdChleHRpcnBhdGVkQ291bnRlciksIDAsIG51bUV4dGlycGF0ZWQsIDEyMDApO1xuICAgICAgICAgICAgZW50ZXJFeHRpcnBhdGVkKCgpID0+IHtcbiAgICAgICAgICAgICAgICBpZiAob25Mb2FkKSB7XG4gICAgICAgICAgICAgICAgICAgIHNldFRpbWVvdXQoKCkgPT4gb25Mb2FkKCksIDEwMDApO1xuICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgIH0pO1xuICAgICAgICB9KTtcblxuICAgIH1cbiAgICBmdW5jdGlvbiBzZXRDdXJyZW50KCkge1xuICAgICAgICBpZiAoY29sb25pemVkSW5WaWV3IHx8IGV4dGlycGF0ZWRJblZpZXcpIHtcbiAgICAgICAgICAgIC8vIGNsZWFySGlnaGxpZ2h0KCk7XG4gICAgICAgICAgICBleGl0Q29sb25pemVkKCk7XG4gICAgICAgICAgICBleGl0RXh0aXJwYXRlZCgpO1xuICAgICAgICB9XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gc2V0Q29sb25pemVkKCkge1xuICAgICAgICBpZiAoIWNvbG9uaXplZEluVmlldykge1xuICAgICAgICAgICAgZW50ZXJDb2xvbml6ZWQoKTtcbiAgICAgICAgfSBlbHNlIHtcbiAgICAgICAgICAgIGhpZ2hsaWdodENvbG9uaXphdGlvbnMoKVxuICAgICAgICB9XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gc2V0RXh0aXJwYXRlZCgpIHtcbiAgICAgICAgaWYgKCFleHRpcnBhdGVkSW5WaWV3KSB7XG4gICAgICAgICAgICBlbnRlckV4dGlycGF0ZWQoKTtcbiAgICAgICAgfSBlbHNlIHtcbiAgICAgICAgICAgIGhpZ2hsaWdodEV4dGlycGF0ZWQoKTtcbiAgICAgICAgfVxuICAgIH1cblxuICAgIHJldHVybiB7XG4gICAgICAgIGFuaW1hdGVJbjogYW5pbWF0ZUluLFxuICAgICAgICBzdmc6IHN2Z0NvbnRhaW5lci5ub2RlKCksXG4gICAgICAgIG51bUNvbG9uaXplZDogbnVtQ29sb25pemVkLFxuICAgICAgICBudW1DdXJyZW50OiBudW1DdXJyZW50LFxuICAgICAgICBudW1FeHRpcnBhdGVkOiBudW1FeHRpcnBhdGVkLFxuICAgICAgICBlbnRlckV4dGlycGF0ZWQ6IGVudGVyRXh0aXJwYXRlZCxcbiAgICAgICAgZW50ZXJDb2xvbml6ZWQ6IGVudGVyQ29sb25pemVkLFxuICAgICAgICBzZXRFeHRpcnBhdGVkOiBzZXRFeHRpcnBhdGVkLFxuICAgICAgICBzZXRDb2xvbml6ZWQ6IHNldENvbG9uaXplZCxcbiAgICAgICAgc2V0Q3VycmVudDogc2V0Q3VycmVudFxuICAgIH1cbn1cblxuZnVuY3Rpb24gQmlyZERvdHMocGFyYW1zKSB7XG4gICAgY29uc3Qge1xuICAgICAgICBlbGVtZW50LCBkYXRhVXJsLCBzZWFzb24sXG4gICAgICAgIHBhcmssIGN1cnJlbnRDb3VudGVyLCBjb2xvbml6ZWRDb3VudGVyLFxuICAgICAgICBleHRpcnBhdGVkQ291bnRlciwgb25Mb2FkLCBpbml0U3RhdHN9ID0gcGFyYW1zO1xuXG4gICAgbGV0IF9zZWFzb24gPSBzZWFzb247XG4gICAgbGV0IHN1bW1lckRvdHMsIHdpbnRlckRvdHM7XG4gICAgbGV0IHJlYWR5ID0gZmFsc2U7XG4gICAgbGV0IG5vZGUgPSBkMy5zZWxlY3QoZWxlbWVudCkuYXBwZW5kKCdkaXYnKVxuICAgICAgICAgICAgICAgIC5jbGFzc2VkKCdiaXJkLWRvdC1jb250YWluZXInLCB0cnVlKTtcblxuICAgIGQzLmNzdihkYXRhVXJsLCAoZXJyb3IsIGRhdGEpID0+IHtcbiAgICAgICAgaWYgKGVycm9yKSB7XG4gICAgICAgICAgICBjb25zb2xlLmxvZygnZXJyb3InLCBlcnJvcik7XG4gICAgICAgICAgICByZXR1cm47XG4gICAgICAgIH1cblxuICAgICAgICBsZXQgcGFya1JvdyA9IGRhdGEuZmluZChkID0+IGQudW5pdF9uYW1lID09IHBhcmspO1xuXG4gICAgICAgIGxldCBzdW1tZXJQYXJhbXMgPSB7XG4gICAgICAgICAgICBlbGVtZW50OiBub2RlLm5vZGUoKSxcbiAgICAgICAgICAgIG51bUN1cnJlbnQ6ICtwYXJrUm93LmN1cnJlbnRfc3BlY2llc19zdW1tZXIsXG4gICAgICAgICAgICBudW1Db2xvbml6ZWQ6ICtwYXJrUm93Lm5vX2NvbG9uaXphdGlvbnNfc3VtbWVyLFxuICAgICAgICAgICAgbnVtRXh0aXJwYXRlZDogK3BhcmtSb3cubm9fZXh0aXJwYXRpb25zX3N1bW1lclxuICAgICAgICB9O1xuXG4gICAgICAgIGxldCB3aW50ZXJQYXJhbXMgPSB7XG4gICAgICAgICAgICBlbGVtZW50OiBub2RlLm5vZGUoKSxcbiAgICAgICAgICAgIG51bUN1cnJlbnQ6ICtwYXJrUm93LmN1cnJlbnRfc3BlY2llc193aW50ZXIsXG4gICAgICAgICAgICBudW1Db2xvbml6ZWQ6ICtwYXJrUm93Lm5vX2NvbG9uaXphdGlvbnNfd2ludGVyLFxuICAgICAgICAgICAgbnVtRXh0aXJwYXRlZDogK3BhcmtSb3cubm9fZXh0aXJwYXRpb25zX3dpbnRlclxuICAgICAgICB9XG5cbiAgICAgICAgc3VtbWVyRG90cyA9IG5ldyBfQmlyZERvdHMoc3VtbWVyUGFyYW1zKTtcbiAgICAgICAgd2ludGVyRG90cyA9IG5ldyBfQmlyZERvdHMod2ludGVyUGFyYW1zKTtcblxuICAgICAgICBpbml0Q2hhcnQoX3NlYXNvbiwgaW5pdFN0YXRzKTtcbiAgICAgICAgcmVhZHkgPSB0cnVlO1xuICAgICAgICBpZiAob25Mb2FkKSB7XG4gICAgICAgICAgICBvbkxvYWQoKTtcbiAgICAgICAgfVxuICAgIH0pO1xuXG4gICAgZnVuY3Rpb24gaW5pdENoYXJ0KHNlYXNvbiwgaW5pdFN0YXRzKSB7XG4gICAgICAgIGxldCBwbG90O1xuICAgICAgICBpZiAoc2Vhc29uID09PSAnc3VtbWVyJykge1xuICAgICAgICAgICAgZDMuc2VsZWN0KHdpbnRlckRvdHMuc3ZnKS5zdHlsZSgnb3BhY2l0eScsIDApO1xuICAgICAgICAgICAgZDMuc2VsZWN0KHN1bW1lckRvdHMuc3ZnKS5zdHlsZSgnb3BhY2l0eScsIDEpO1xuICAgICAgICAgICAgcGxvdCA9IHN1bW1lckRvdHM7XG4gICAgICAgIH0gZWxzZSB7XG4gICAgICAgICAgICBkMy5zZWxlY3Qod2ludGVyRG90cy5zdmcpLnN0eWxlKCdvcGFjaXR5JywgMSk7XG4gICAgICAgICAgICBkMy5zZWxlY3Qoc3VtbWVyRG90cy5zdmcpLnN0eWxlKCdvcGFjaXR5JywgMCk7XG4gICAgICAgICAgICBwbG90ID0gd2ludGVyRG90cztcbiAgICAgICAgfVxuICAgICAgICBpZiAoaW5pdFN0YXRzKSB7XG4gICAgICAgICAgICBkMy5zZWxlY3QoY29sb25pemVkQ291bnRlcikudGV4dChwbG90Lm51bUNvbG9uaXplZCk7XG4gICAgICAgICAgICBkMy5zZWxlY3QoZXh0aXJwYXRlZENvdW50ZXIpLnRleHQocGxvdC5udW1FeHRpcnBhdGVkKTtcbiAgICAgICAgICAgIGQzLnNlbGVjdChjdXJyZW50Q291bnRlcikudGV4dChwbG90Lm51bUN1cnJlbnQpO1xuICAgICAgICB9XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gX2FuaW1hdGVJbihvbkZpbmlzaGVkKSB7XG4gICAgICAgIC8vIHNob3VsZCBiZSBjYWxsZWQgYWZ0ZXIgcmVhZHkgdG8gYmUgaW5pdGVkXG4gICAgICAgIGxldCBwbG90O1xuICAgICAgICBpZiAoX3NlYXNvbiA9PT0gJ3N1bW1lcicpIHtcbiAgICAgICAgICAgIHBsb3QgPSBzdW1tZXJEb3RzO1xuICAgICAgICB9IGVsc2Uge1xuICAgICAgICAgICAgcGxvdCA9IHdpbnRlckRvdHM7XG4gICAgICAgIH1cblxuICAgICAgICBkMy5zZWxlY3QoY3VycmVudENvdW50ZXIpLnRleHQocGxvdC5udW1DdXJyZW50KTtcbiAgICAgICAgYW5pbWF0ZUNvdW50KGQzLnNlbGVjdChjb2xvbml6ZWRDb3VudGVyKSwgMCwgcGxvdC5udW1Db2xvbml6ZWQsIDEyMDApO1xuICAgICAgICBwbG90LmVudGVyQ29sb25pemVkKCgpID0+IHtcbiAgICAgICAgICAgIGFuaW1hdGVDb3VudChkMy5zZWxlY3QoZXh0aXJwYXRlZENvdW50ZXIpLCAwLCBwbG90Lm51bUV4dGlycGF0ZWQsIDEyMDApO1xuICAgICAgICAgICAgcGxvdC5lbnRlckV4dGlycGF0ZWQoKCkgPT4ge1xuICAgICAgICAgICAgICAgIGlmIChvbkZpbmlzaGVkKSB7XG4gICAgICAgICAgICAgICAgICAgIHNldFRpbWVvdXQoKCkgPT4gb25GaW5pc2hlZCgpLCAxMDAwKTtcbiAgICAgICAgICAgICAgICB9XG4gICAgICAgICAgICB9KTtcbiAgICAgICAgfSk7XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gYW5pbWF0ZUluKG9uRmluaXNoZWQpIHtcbiAgICAgICAgaWYgKHJlYWR5KSB7XG4gICAgICAgICAgICBfYW5pbWF0ZUluKG9uRmluaXNoZWQpO1xuICAgICAgICB9XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gZmFkZU91dChlbCkge1xuICAgICAgICBlbC50cmFuc2l0aW9uKClcbiAgICAgICAgICAgIC5kdXJhdGlvbigyMDApXG4gICAgICAgICAgICAuZWFzZShkMy5lYXNlUXVhZE91dClcbiAgICAgICAgICAgIC5zdHlsZSgnb3BhY2l0eScsIDApO1xuICAgIH1cblxuICAgIGZ1bmN0aW9uIGZhZGVJbihlbCkge1xuICAgICAgICBlbC50cmFuc2l0aW9uKClcbiAgICAgICAgICAgIC5kdXJhdGlvbigyMDApXG4gICAgICAgICAgICAuZGVsYXkoMjAwKVxuICAgICAgICAgICAgLmVhc2UoZDMuZWFzZVF1YWRPdXQpXG4gICAgICAgICAgICAuc3R5bGUoJ29wYWNpdHknLCAxKTtcbiAgICB9XG5cbiAgICBmdW5jdGlvbiBzZXRTZWFzb24oc2Vhc29uKSB7XG4gICAgICAgIGlmIChzZWFzb24gPT09IF9zZWFzb24pIHtcbiAgICAgICAgICAgIHJldHVybjtcbiAgICAgICAgfVxuXG4gICAgICAgIF9zZWFzb24gPSBzZWFzb247XG5cbiAgICAgICAgaWYgKCFyZWFkeSkge1xuICAgICAgICAgICAgcmV0dXJuO1xuICAgICAgICB9XG5cbiAgICAgICAgaWYgKHNlYXNvbiA9PT0gJ3N1bW1lcicpIHtcbiAgICAgICAgICAgIGQzLnNlbGVjdCh3aW50ZXJEb3RzLnN2ZykuY2FsbChmYWRlT3V0KTtcbiAgICAgICAgICAgIGQzLnNlbGVjdChzdW1tZXJEb3RzLnN2ZykuY2FsbChmYWRlSW4pO1xuXG4gICAgICAgICAgICBkMy5zZWxlY3QoY29sb25pemVkQ291bnRlcikudGV4dChzdW1tZXJEb3RzLm51bUNvbG9uaXplZCk7XG4gICAgICAgICAgICBkMy5zZWxlY3QoZXh0aXJwYXRlZENvdW50ZXIpLnRleHQoc3VtbWVyRG90cy5udW1FeHRpcnBhdGVkKTtcbiAgICAgICAgICAgIGQzLnNlbGVjdChjdXJyZW50Q291bnRlcikudGV4dChzdW1tZXJEb3RzLm51bUN1cnJlbnQpO1xuICAgICAgICB9IGVsc2Uge1xuICAgICAgICAgICAgZDMuc2VsZWN0KHN1bW1lckRvdHMuc3ZnKS5jYWxsKGZhZGVPdXQpO1xuICAgICAgICAgICAgZDMuc2VsZWN0KHdpbnRlckRvdHMuc3ZnKS5jYWxsKGZhZGVJbik7XG5cbiAgICAgICAgICAgIGQzLnNlbGVjdChjb2xvbml6ZWRDb3VudGVyKS50ZXh0KHdpbnRlckRvdHMubnVtQ29sb25pemVkKTtcbiAgICAgICAgICAgIGQzLnNlbGVjdChleHRpcnBhdGVkQ291bnRlcikudGV4dCh3aW50ZXJEb3RzLm51bUV4dGlycGF0ZWQpO1xuICAgICAgICAgICAgZDMuc2VsZWN0KGN1cnJlbnRDb3VudGVyKS50ZXh0KHdpbnRlckRvdHMubnVtQ3VycmVudCk7XG4gICAgICAgIH1cbiAgICB9XG5cbiAgICAvLyBub25lIG9mIHRoZXNlIHNob2x1ZCBiZSBjYWxsZWQgdW50aWwgdGhlIGNvbXBvbmVudCBpcyByZWFkeVxuICAgIGZ1bmN0aW9uIHNldEV4dGlycGF0ZWQoKSB7XG4gICAgICAgIGlmICghcmVhZHkpIHtcbiAgICAgICAgICAgIHJldHVybjtcbiAgICAgICAgfVxuXG4gICAgICAgIHN1bW1lckRvdHMuc2V0RXh0aXJwYXRlZCgpO1xuICAgICAgICB3aW50ZXJEb3RzLnNldEV4dGlycGF0ZWQoKTtcbiAgICB9XG5cbiAgICBmdW5jdGlvbiBzZXRDdXJyZW50KCkge1xuICAgICAgICBpZiAoIXJlYWR5KSB7XG4gICAgICAgICAgICByZXR1cm47XG4gICAgICAgIH1cblxuICAgICAgICBzdW1tZXJEb3RzLnNldEN1cnJlbnQoKTtcbiAgICAgICAgd2ludGVyRG90cy5zZXRDdXJyZW50KCk7XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gc2V0Q29sb25pemVkKCkge1xuICAgICAgICBpZiAoIXJlYWR5KSB7XG4gICAgICAgICAgICByZXR1cm47XG4gICAgICAgIH1cblxuICAgICAgICBzdW1tZXJEb3RzLnNldENvbG9uaXplZCgpO1xuICAgICAgICB3aW50ZXJEb3RzLnNldENvbG9uaXplZCgpO1xuICAgIH1cblxuICAgIHJldHVybiB7XG4gICAgICAgIGFuaW1hdGVJbjogYW5pbWF0ZUluLFxuICAgICAgICBzZXRTZWFzb246IHNldFNlYXNvbixcbiAgICAgICAgc2V0RXh0aXJwYXRlZDogc2V0RXh0aXJwYXRlZCxcbiAgICAgICAgc2V0Q29sb25pemVkOiBzZXRDb2xvbml6ZWQsXG4gICAgICAgIHNldEN1cnJlbnQ6IHNldEN1cnJlbnRcbiAgICB9XG59XG5cbmV4cG9ydCB7IEJpcmREb3RzIH07XG4iLCJpbXBvcnQgeyBCaXJkRG90cyB9IGZyb20gJy4vYmlyZERvdC5qcyc7XG5pbXBvcnQgeyBUdXJub3ZlckNoYXJ0IH0gZnJvbSAnLi90dXJub3Zlci5qcyc7XG5pbXBvcnQgeyBQYXJrTWFwIH0gZnJvbSAnLi9wYXJrTWFwLmpzJztcblxud2luZG93LlN0YW1lbkF1ZHVib25QYXJrcyA9IHtcbiAgQmlyZERvdHM6IEJpcmREb3RzLFxuICBQYXJrTWFwOiBQYXJrTWFwLFxuICBUdXJub3ZlckNoYXJ0OiBUdXJub3ZlckNoYXJ0XG59O1xuIiwiaW1wb3J0IHthbGJlcnNCaWdBbGFza2F9IGZyb20gJy4vYWxiZXJzQmlnQWxhc2thJztcbi8qXG4gIFBhcmsgTWFwXG5cbiAgZWxlbWVudFxuICBzZWFzb24gJ3N1bW1lcicgb3IgJ3dpbnRlcidcbiAgbWV0cmljXG4gIHNoYXBlVXJsOiBwYXRoIHRvIHRoZSB1cyBib3VuZGFyaWVzIGRhdGFzZXRcbiAgZGF0YVVybDogcGF0aCB0byB0aGUgY29sb25pemF0aW9uIC8gZXh0aXJwYXRpb24gLmNzdlxuXG4qL1xuXG5cblxuLy8gdGhpcyBjYW4gYmUgYnJvdWdodCBpbnRvIHRoZSBjbGFzc1xuZnVuY3Rpb24gZHJhd1BhcmtzKHBhcmtzLCBnLCBjb2xvclNjYWxlLCBzaXplU2NhbGUsIHByb2plY3Rpb24sIHNlbGVjdGlvbikge1xuXG4gIHZhciBwYXJrQ2lyY2xlcyA9IGcuc2VsZWN0QWxsKFwiLnNkLXBhcmtjaXJjbGVcIikuZGF0YShwYXJrcywgZCA9PiBkLnBhcmspO1xuXG4gIHBhcmtDaXJjbGVzLmV4aXQoKS5yZW1vdmUoKTtcbiAgcGFya0NpcmNsZXMuZW50ZXIoKS5hcHBlbmQoXCJjaXJjbGVcIilcbiAgICAgIC5jbGFzc2VkKFwic2QtcGFya2NpcmNsZVwiLCB0cnVlKVxuICAgICAgLm1lcmdlKHBhcmtDaXJjbGVzKVxuICAgICAgLmF0dHIoXCJ0cmFuc2Zvcm1cIiwgZnVuY3Rpb24oZCkgeyByZXR1cm4gXCJ0cmFuc2xhdGUoXCIgKyBwcm9qZWN0aW9uKFsrZC5sb25nLCtkLmxhdF0pICsgXCIpXCI7IH0pXG4gICAgICAuY2xhc3NlZCgnaG92ZXInLCBkID0+IGQudW5pdF9uYW1lID09PSBzZWxlY3Rpb24pXG4gICAgICAub24oXCJtb3VzZW92ZXJcIiwgZnVuY3Rpb24oZCkge1xuICAgICAgfSlcbiAgICAgIC5vbihcIm1vdXNlb3V0XCIsIGZ1bmN0aW9uKGQpIHtcbiAgICAgIH0pXG4gICAgICAudHJhbnNpdGlvbigpXG4gICAgICAuYXR0cihcInJcIiwgc2l6ZVNjYWxlKVxuICAgICAgLnN0eWxlKFwiZmlsbFwiLCBjb2xvclNjYWxlKVxuICAgICAgLnN0eWxlKFwibWl4LWJsZW5kLW1vZGVcIiwgXCJub3JtYWxcIilcbiAgICAgIC5zdHlsZSgnc3Ryb2tlJywgY29sb3JTY2FsZSk7XG59XG5cbmNsYXNzIFdhbmQge1xuICBjb25zdHJ1Y3RvcihzdmcsIHNpemUpIHtcbiAgICBsZXQgd2FuZCA9IHN2Zy5hcHBlbmQoJ2cnKS5jbGFzc2VkKCd3YW5kJywgdHJ1ZSk7XG4gICAgd2FuZC5hcHBlbmQoJ2NpcmNsZScpXG4gICAgICAuYXR0cignY3gnLCAwKVxuICAgICAgLmF0dHIoJ2N5JywgLXNpemUpXG4gICAgICAuYXR0cigncicsIDIpO1xuICAgIHdhbmQuYXBwZW5kKCdsaW5lJylcbiAgICAgIC5hdHRyKCd4MScsIDApXG4gICAgICAuYXR0cigneTEnLCAwKVxuICAgICAgLmF0dHIoJ3gyJywgMClcbiAgICAgIC5hdHRyKCd5MicsIC1zaXplKTtcblxuICAgIHRoaXMud2FuZCA9IHdhbmQ7XG4gIH1cblxuICBoaWRlKCkge1xuICAgIHRoaXMud2FuZC5jbGFzc2VkKCdoaWRkZW4nLCB0cnVlKTtcbiAgfVxuXG4gIG1vdmUocHQpIHtcbiAgICB0aGlzLndhbmQuY2xhc3NlZCgnaGlkZGVuJywgZmFsc2UpO1xuICAgIHRoaXMud2FuZC5hdHRyKCd0cmFuc2Zvcm0nLCBgdHJhbnNsYXRlKCR7cHRbMF19LCAke3B0WzFdfSlgKTtcbiAgfVxufVxuXG5mdW5jdGlvbiBQYXJrTWFwKHBhcmFtcykge1xuICBjb25zdCB7ZWxlbWVudCwgc2Vhc29uLCBtZXRyaWMsIHNoYXBlVXJsLCBkYXRhVXJsLCBvbkNsaWNrfSA9IHBhcmFtcztcblxuICBsZXQgX2VsZW1lbnQgPSBkMy5zZWxlY3QoZWxlbWVudCkuYXBwZW5kKCdkaXYnKVxuICAgICAgICAgICAgICAgICAgLmNsYXNzZWQoJ3NkLW1hcCcsIHRydWUpO1xuXG4gIGxldCB0b29sdGlwID0gX2VsZW1lbnQuYXBwZW5kKCdkaXYnKVxuICAgICAgICAgICAgICAgICAgLmNsYXNzZWQoJ3NkLXRvb2x0aXAnLCB0cnVlKVxuICAgICAgICAgICAgICAgICAgLmNsYXNzZWQoJ2hpZGRlbicsIHRydWUpXG4gICAgICAgICAgICAgICAgICAuY2xhc3NlZCgnZG93bicsIGZhbHNlKVxuICAgICAgICAgICAgICAgICAgLmh0bWwoYFxuICAgICAgICAgICAgICAgICAgICA8aDIgY2xhc3M9XCJ0aXRsZVwiPk5hbWU8L2gyPlxuICAgICAgICAgICAgICAgICAgICA8ZGl2PlxuICAgICAgICAgICAgICAgICAgICAgIDxzdmcgY2xhc3M9XCJzZC1hcnJvd1wiIGlkPVwiTGF5ZXJfMVwiIHdpZHRoPVwiMThcIiBoZWlnaHQ9XCIyMi41XCIgZGF0YS1uYW1lPVwiTGF5ZXIgMVwiIHhtbG5zPVwiaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmdcIiB2aWV3Qm94PVwiMCAwIDE4LjcgMjIuNVwiPjxwb2x5Z29uIGNsYXNzPVwic2QtYXJyb3ctaWNvblwiIHBvaW50cz1cIjYuMzQgMTQuMjYgNi4zNCAyMi41IDYuOTcgMjIuNSAxMS43MiAyMi41IDEyLjM2IDIyLjUgMTIuMzYgMTQuMjYgMTguNyAxNC4yNiA5LjM1IDAgMCAxNC4yNiA2LjM0IDE0LjI2XCIvPjwvc3ZnPlxuICAgICAgICAgICAgICAgICAgICAgIDxoMiBjbGFzcz1cIm51bWJlclwiPjM0PC9oMj5cbiAgICAgICAgICAgICAgICAgICAgICA8cCBjbGFzcz1cImxhYmVsXCI+RXh0aXJwYXRpb25zPC9wPlxuICAgICAgICAgICAgICAgICAgICA8L2Rpdj5cbiAgICAgICAgICAgICAgICAgIGApXG5cbiAgdG9vbHRpcC5zZWxlY3QoJy50aXRsZScpLm9uKCdjbGljaycsICgpID0+IHtcbiAgICBkMy5ldmVudC5wcmV2ZW50RGVmYXVsdCgpO1xuICAgIGlmIChvbkNsaWNrKSB7XG4gICAgICBvbkNsaWNrKHRvb2x0aXAuc2VsZWN0KCcudGl0bGUnKS50ZXh0KCkpO1xuICAgIH1cbiAgfSk7XG5cbiAgbGV0IHdpZHRoID0gZDMuc2VsZWN0KGVsZW1lbnQpLm5vZGUoKS5vZmZzZXRXaWR0aDtcbiAgbGV0IGhlaWdodCA9IHdpZHRoICogNzAzIC8gMTEwNjtcblxuICB2YXIgc3ZnID0gX2VsZW1lbnQuYXBwZW5kKFwic3ZnXCIpXG4gICAgICAgICAgICAgICAgLmF0dHIoJ3dpZHRoJywgd2lkdGgpXG4gICAgICAgICAgICAgICAgLmF0dHIoJ2hlaWdodCcsIGhlaWdodCk7XG5cbiAgdmFyIGJhY2tncm91bmRfZyA9IHN2Zy5hcHBlbmQoXCJnXCIpLmF0dHIoXCJpZFwiLFwiYmFja2dyb3VuZF9nXCIpO1xuICB2YXIgZm9yZWdyb3VuZF9nID0gc3ZnLmFwcGVuZChcImdcIikuYXR0cihcImlkXCIsXCJmb3JlZ3JvdW5kX2dcIik7XG4gIHZhciBwYXJrR3JvdXAgPSBmb3JlZ3JvdW5kX2cuYXBwZW5kKFwiZ1wiKS5hdHRyKFwiY2xhc3NcIiwgXCJwYXJrQ2lyY2xlc1wiKTtcblxuICB2YXIgdG91Y2hPZmZzZXRZID0gNTA7XG4gIHZhciB3YW5kID0gbmV3IFdhbmQoZm9yZWdyb3VuZF9nLCB0b3VjaE9mZnNldFkpO1xuXG4gIGxldCBwcm9qZWN0aW9uO1xuXG4gIGxldCB0b29sdGlwTnVtYmVyO1xuICBsZXQgY29sb25Db2xvciA9IGQzLnNjYWxlTGluZWFyKClcbiAgICAgICAgICAgICAgICAgICAgLnJhbmdlKFsnIzE4YTFhZCcsICcjMThhMWFkJ10pO1xuXG4gIGxldCBjb2xvblNpemUgPSBkMy5zY2FsZVNxcnQoKTtcblxuICBsZXQgZXh0aXJwQ29sb3IgPSBkMy5zY2FsZUxpbmVhcigpXG4gICAgICAgICAgICAgICAgICAgIC5yYW5nZShbJyNlOGM1NzgnLCAnI2U4YzU3OCddKTtcblxuICBsZXQgZXh0aXJwU2l6ZSA9IGQzLnNjYWxlU3FydCgpO1xuXG4gIGxldCBfc2Vhc29uID0gc2Vhc29uO1xuICBsZXQgX21ldHJpYyA9IG1ldHJpYztcbiAgbGV0IF9wYXJrcztcbiAgbGV0IF9zdGF0ZXM7XG5cbiAgbGV0IHNlbGVjdGlvbjtcblxuICBmdW5jdGlvbiByZW5kZXIoKSB7XG4gICAgbGV0IGNvbG9yU2NhbGUsIHNpemVTY2FsZTtcbiAgICBsZXQgdG9vbHRpcExhYmVsID0gYFBvdGVudGlhbCAke19tZXRyaWN9cyBpbiAke19zZWFzb259YDtcbiAgICB0b29sdGlwLnNlbGVjdCgnLmxhYmVsJykudGV4dCh0b29sdGlwTGFiZWwpO1xuXG4gICAgaWYgKF9zZWFzb24gPT0gJ3N1bW1lcicgJiYgX21ldHJpYyA9PSAnY29sb25pemF0aW9uJykge1xuXG4gICAgICBjb2xvclNjYWxlID0gKGQpID0+IGNvbG9uQ29sb3IoZFsnbm9fY29sb25pemF0aW9uc19zdW1tZXInXSk7XG4gICAgICBzaXplU2NhbGUgPSAoZCkgPT4gY29sb25TaXplKGRbJ25vX2NvbG9uaXphdGlvbnNfc3VtbWVyJ10pO1xuICAgICAgdG9vbHRpcE51bWJlciA9IChkKSA9PiBkWydub19jb2xvbml6YXRpb25zX3N1bW1lciddO1xuICAgICAgdG9vbHRpcC5jbGFzc2VkKCdkb3duJywgZmFsc2UpO1xuXG4gICAgfSBlbHNlIGlmIChfc2Vhc29uID09ICdzdW1tZXInICYmIF9tZXRyaWMgPT0gJ2V4dGlycGF0aW9uJykge1xuXG4gICAgICBjb2xvclNjYWxlID0gKGQpID0+IGV4dGlycENvbG9yKGRbJ25vX2V4dGlycGF0aW9uc19zdW1tZXInXSk7XG4gICAgICBzaXplU2NhbGUgPSAoZCkgPT4gZXh0aXJwU2l6ZShkWydub19leHRpcnBhdGlvbnNfc3VtbWVyJ10pO1xuICAgICAgdG9vbHRpcE51bWJlciA9IChkKSA9PiBkWydub19leHRpcnBhdGlvbnNfc3VtbWVyJ107XG4gICAgICB0b29sdGlwLmNsYXNzZWQoJ2Rvd24nLCB0cnVlKTtcblxuICAgIH0gZWxzZSBpZiAoX3NlYXNvbiA9PSAnd2ludGVyJyAmJiBfbWV0cmljID09ICdjb2xvbml6YXRpb24nKSB7XG5cbiAgICAgIGNvbG9yU2NhbGUgPSAoZCkgPT4gY29sb25Db2xvcihkWydub19jb2xvbml6YXRpb25zX3dpbnRlciddKTtcbiAgICAgIHNpemVTY2FsZSA9IChkKSA9PiBjb2xvblNpemUoZFsnbm9fY29sb25pemF0aW9uc193aW50ZXInXSk7XG4gICAgICB0b29sdGlwTnVtYmVyID0gKGQpID0+IGRbJ25vX2NvbG9uaXphdGlvbnNfd2ludGVyJ107XG4gICAgICB0b29sdGlwLmNsYXNzZWQoJ2Rvd24nLCBmYWxzZSk7XG5cbiAgICB9IGVsc2UgaWYgKF9zZWFzb24gPT0gJ3dpbnRlcicgJiYgX21ldHJpYyA9PSAnZXh0aXJwYXRpb24nKSB7XG5cbiAgICAgIGNvbG9yU2NhbGUgPSAoZCkgPT4gZXh0aXJwQ29sb3IoZFsnbm9fZXh0aXJwYXRpb25zX3dpbnRlciddKTtcbiAgICAgIHNpemVTY2FsZSA9IChkKSA9PiBleHRpcnBTaXplKGRbJ25vX2V4dGlycGF0aW9uc193aW50ZXInXSk7XG4gICAgICB0b29sdGlwTnVtYmVyID0gKGQpID0+IGRbJ25vX2V4dGlycGF0aW9uc193aW50ZXInXTtcbiAgICAgIHRvb2x0aXAuY2xhc3NlZCgnZG93bicsIHRydWUpO1xuXG4gICAgfVxuXG4gICAgZHJhd1BhcmtzKF9wYXJrcywgcGFya0dyb3VwLCBjb2xvclNjYWxlLCBzaXplU2NhbGUsIHByb2plY3Rpb24sIHNlbGVjdGlvbik7XG4gIH1cblxuICBmdW5jdGlvbiByZWRyYXcoKSB7XG5cbiAgICBsZXQgd2lkdGggPSBfZWxlbWVudC5ub2RlKCkub2Zmc2V0V2lkdGg7XG4gICAgbGV0IGhlaWdodCA9IHdpZHRoICogNzAzIC8gMTEwNjtcblxuICAgIHN2Zy5hdHRyKCd3aWR0aCcsIHdpZHRoKVxuICAgICAgIC5hdHRyKCdoZWlnaHQnLCBoZWlnaHQpO1xuXG4gICAgbGV0IG1hcFBhZGRpbmcgPSA0MDtcbiAgICBwcm9qZWN0aW9uID0gYWxiZXJzQmlnQWxhc2thKClcbiAgICAgIC5maXRFeHRlbnQoW1swICsgbWFwUGFkZGluZywgMCArIG1hcFBhZGRpbmddLCBbd2lkdGggLSBtYXBQYWRkaW5nLCBoZWlnaHQgLSBtYXBQYWRkaW5nXV0sIHtcbiAgICAgICAgdHlwZTogJ0ZlYXR1cmVDb2xsZWN0aW9uJyxcbiAgICAgICAgZmVhdHVyZXM6IF9zdGF0ZXNcbiAgICAgIH0pO1xuXG4gICAgLy8gZHJhdyBiYXNlIGxheWVyXG4gICAgbGV0IHN0YXRlc1BhdGggPSBiYWNrZ3JvdW5kX2cuc2VsZWN0QWxsKFwicGF0aFwiKVxuICAgICAgICAuZGF0YShfc3RhdGVzKTtcbiAgICBzdGF0ZXNQYXRoLmVudGVyKClcbiAgICAgICAgLmFwcGVuZChcInBhdGhcIilcbiAgICAgIC5tZXJnZShzdGF0ZXNQYXRoKVxuICAgICAgICAuYXR0cihcImRcIiwgZDMuZ2VvUGF0aChwcm9qZWN0aW9uKSlcbiAgICAgICAgLnN0eWxlKFwiZmlsbFwiLCBcIiNlNWU1ZTVcIilcbiAgICAgICAgLnN0eWxlKFwic3Ryb2tlXCIsIGQgPT4gZC5wcm9wZXJ0aWVzLnBvc3RhbCA9PT0gJ0FLJyA/IFwiI2Q4ZDhkOFwiIDogXCJ3aGl0ZVwiKVxuXG4gICAgLy8gY29tcHV0ZSB0aGUgZG9tYWluc1xuICAgIGxldCBjb2xvblJhbmdlID0gZDMuZXh0ZW50KFxuICAgICAgICAgICAgICBfcGFya3MubWFwKGQgPT4gZFsnbm9fY29sb25pemF0aW9uc19zdW1tZXInXSlcbiAgICAgICAgICAgIC5jb25jYXQoX3BhcmtzLm1hcChkID0+IGRbJ25vX2NvbG9uaXphdGlvbnNfd2ludGVyJ10pKSk7XG5cbiAgICBsZXQgZXh0aXJwUmFuZ2UgPSBkMy5leHRlbnQoXG4gICAgICAgICAgICAgIF9wYXJrcy5tYXAoZCA9PiBkWydub19leHRpcnBhdGlvbnNfc3VtbWVyJ10pXG4gICAgICAgICAgICAuY29uY2F0KF9wYXJrcy5tYXAoZCA9PiBkWydub19leHRpcnBhdGlvbnNfd2ludGVyJ10pKSk7XG5cbiAgICBsZXQgbWluUmFkaXVzID0gMiAvIDMyMCAqIHdpZHRoO1xuICAgIGxldCBtYXhSYWRpdXMgPSAxMyAvIDMyMCAqIHdpZHRoXG5cbiAgICBjb2xvbkNvbG9yLmRvbWFpbihjb2xvblJhbmdlKTtcbiAgICBjb2xvblNpemUuZG9tYWluKGNvbG9uUmFuZ2UpXG4gICAgICAucmFuZ2UoW21pblJhZGl1cywgbWF4UmFkaXVzXSk7XG4gICAgZXh0aXJwQ29sb3IuZG9tYWluKGV4dGlycFJhbmdlKTtcbiAgICBleHRpcnBTaXplLmRvbWFpbihleHRpcnBSYW5nZSlcbiAgICAgIC5yYW5nZShbbWluUmFkaXVzLCBtYXhSYWRpdXNdKTtcblxuICAgIGxldCBwb2ludHMgPSBfcGFya3MubWFwKHAgPT4gcHJvamVjdGlvbihbK3AubG9uZywgK3AubGF0XSkpO1xuXG4gICAgbGV0IF92ID0gZDMudm9yb25vaSgpXG4gICAgICAvL3BpeGVsIHNwYWNlXG4gICAgICAueChkID0+IHsgcmV0dXJuIHByb2plY3Rpb24oIFsrZC5sb25nLCArZC5sYXRdKVswXTsgfSlcbiAgICAgIC55KGQgPT4geyByZXR1cm4gcHJvamVjdGlvbiggWytkLmxvbmcsICtkLmxhdF0pWzFdOyB9KVxuICAgICAgKF9wYXJrcyk7XG5cbiAgICBmdW5jdGlvbiBoaXREZXRlY3RvcihwLCBvZmZzZXRZKSB7XG4gICAgICBvZmZzZXRZID0gb2Zmc2V0WSB8fCAwO1xuICAgICAgbGV0IG1heERpc3RhbmNlRnJvbVBvaW50ID0gMjA7XG4gICAgICByZXR1cm4gX3YuZmluZChwWzBdLCBwWzFdIC0gb2Zmc2V0WSwgbWF4RGlzdGFuY2VGcm9tUG9pbnQpO1xuICAgIH1cblxuICAgIGxldCBmb2N1c2VkID0gZmFsc2U7XG5cbiAgICBmdW5jdGlvbiBoaWdobGlnaHQocGFya05vZGUpIHtcbiAgICAgIGlmIChwYXJrTm9kZSkge1xuXG4gICAgICAgIHNlbGVjdGlvbiA9IHBhcmtOb2RlLmRhdGEudW5pdF9uYW1lO1xuICAgICAgICByZW5kZXIoKTtcblxuICAgICAgICB0b29sdGlwLmNsYXNzZWQoJ2hpZGRlbicsIGZhbHNlKVxuICAgICAgICB0b29sdGlwLnNlbGVjdCgnLnRpdGxlJykudGV4dChwYXJrTm9kZS5kYXRhLnVuaXRfbmFtZSk7XG4gICAgICAgIHRvb2x0aXAuc2VsZWN0KCcubnVtYmVyJykudGV4dCh0b29sdGlwTnVtYmVyKHBhcmtOb2RlLmRhdGEpKTtcblxuICAgICAgICBsZXQgZHggPSB0b29sdGlwLm5vZGUoKS5jbGllbnRXaWR0aCAvIDI7XG4gICAgICAgIGxldCBkeSA9IHBhcmtOb2RlWzFdIC0gdG9vbHRpcC5ub2RlKCkuY2xpZW50SGVpZ2h0IC0gNTsgLy8gYSBiaXQgb2ZmIGNlbnRlclxuICAgICAgICBkeCA9IHBhcmtOb2RlWzBdIC0gZHg7XG5cbiAgICAgICAgdG9vbHRpcC5zdHlsZSgnbGVmdCcsIGR4ICsgJ3B4Jyk7XG4gICAgICAgIHRvb2x0aXAuc3R5bGUoJ3RvcCcsIGR5ICsgJ3B4Jyk7XG5cbiAgICAgICAgLy8gc25hcCB0byB0aGUgd2luZG93XG4gICAgICAgIGxldCByZWN0ID0gdG9vbHRpcC5ub2RlKCkuZ2V0Qm91bmRpbmdDbGllbnRSZWN0KCk7XG4gICAgICAgIGxldCBtYXhXaWR0aCA9IHdpbmRvdy5pbm5lcldpZHRoO1xuXG4gICAgICAgIGlmIChyZWN0LnggPCAwKSB7XG4gICAgICAgICAgZHggLT0gcmVjdC54O1xuICAgICAgICB9IGVsc2UgaWYgKHJlY3QueCArIHJlY3Qud2lkdGggPiBtYXhXaWR0aCkge1xuICAgICAgICAgIGR4ID0gbWF4V2lkdGggLSByZWN0LndpZHRoO1xuICAgICAgICB9XG5cbiAgICAgICAgdG9vbHRpcC5zdHlsZSgnbGVmdCcsIGR4ICsgJ3B4Jyk7XG4gICAgICAgIHRvb2x0aXAuc3R5bGUoJ3RvcCcsIGR5ICsgJ3B4Jyk7XG5cbiAgICAgIH0gZWxzZSB7XG4gICAgICAgIHRvb2x0aXAuY2xhc3NlZCgnaGlkZGVuJywgdHJ1ZSlcbiAgICAgICAgc2VsZWN0aW9uID0gbnVsbDtcbiAgICAgICAgcmVuZGVyKCk7XG4gICAgICB9XG4gICAgfVxuXG4gICAgc3ZnLm9uKCdjbGljaycsIGZ1bmN0aW9uKCkge1xuICAgICAgbGV0IHBhcmsgPSBoaXREZXRlY3RvcihkMy5tb3VzZSh0aGlzKSk7XG4gICAgICBoaWdobGlnaHQocGFyayk7XG4gICAgICBmb2N1c2VkID0gcGFyayAhPSBudWxsO1xuICAgIH0pO1xuXG4gICAgc3ZnLm9uKCd0b3VjaG1vdmUnLCBmdW5jdGlvbihlKSB7XG4gICAgICB3YW5kLm1vdmUoZDMudG91Y2hlcyh0aGlzKVswXSk7XG4gICAgICBsZXQgcGFyayA9IGhpdERldGVjdG9yKGQzLnRvdWNoZXModGhpcylbMF0sIHRvdWNoT2Zmc2V0WSk7XG4gICAgICBoaWdobGlnaHQocGFyayk7XG4gICAgICBkMy5ldmVudC5wcmV2ZW50RGVmYXVsdCgpO1xuICAgIH0pXG4gICAgc3ZnLm9uKCd0b3VjaGVuZCcsIGZ1bmN0aW9uKGUpIHtcbiAgICAgIHdhbmQuaGlkZSgpO1xuICAgIH0pO1xuICAgIHN2Zy5vbignbW91c2Vtb3ZlJywgZnVuY3Rpb24oKSB7XG4gICAgICBpZiAoIWZvY3VzZWQpIHtcbiAgICAgICAgbGV0IHBhcmsgPSBoaXREZXRlY3RvcihkMy5tb3VzZSh0aGlzKSk7XG4gICAgICAgIGhpZ2hsaWdodChwYXJrKTtcbiAgICAgIH1cbiAgICB9KTtcblxuICAgIHJlbmRlcigpO1xuXG4gIH0gLy9lbmQgaW5pdFxuXG4gIGZ1bmN0aW9uIHNldFBhcmFtcyhzZWFzb24sIG1ldHJpYykge1xuICAgIF9zZWFzb24gPSBzZWFzb247XG4gICAgX21ldHJpYyA9IG1ldHJpYztcbiAgICByZW5kZXIoKTtcbiAgfVxuXG4gIC8vbG9hZCB0aGUgZGF0YVxuICBkMy5xdWV1ZSgpXG4gICAgLmRlZmVyKGQzLmpzb24sIHNoYXBlVXJsKVxuICAgIC5kZWZlcihkMy5jc3YsIGRhdGFVcmwpXG4gICAgLmF3YWl0QWxsKGZ1bmN0aW9uKGVycm9yLCByZXN1bHRzKSB7XG5cbiAgICBsZXQgc3RhdGVzID0gcmVzdWx0c1swXTtcbiAgICBsZXQgcGFya3MgPSByZXN1bHRzWzFdO1xuXG4gICAgLy8gdHlwZWNhc3RcbiAgICBwYXJrcy5mb3JFYWNoKGZ1bmN0aW9uKHBhcmspIHtcbiAgICAgIHBhcmsucGFyayA9IHBhcmsucGFyaztcbiAgICAgIHBhcmsudW5pdF9uYW1lID0gcGFyay51bml0X25hbWU7XG4gICAgICBwYXJrLm5wc19yZWdpb24gPSBwYXJrLm5wc19yZWdpb247XG4gICAgICBwYXJrLnR1cm5vdmVyX3N1bW1lciA9ICtwYXJrLnR1cm5vdmVyX3N1bW1lcjtcbiAgICAgIHBhcmsudHVybm92ZXJfd2ludGVyID0gK3BhcmsudHVybm92ZXJfd2ludGVyO1xuICAgICAgcGFyay5sb25nID0gK3BhcmsubG9uZztcbiAgICAgIHBhcmsubGF0ID0gK3BhcmsubGF0O1xuICAgICAgcGFyay5jdXJyZW50X25vX3NwZWNpZXNfc3VtbWVyID0gK3Bhcmsubm9fc3BlY2llc19zdW1tZXI7XG4gICAgICBwYXJrLmN1cnJlbnRfbm9fc3BlY2llc193aW50ZXIgPSArcGFyay5ub19zcGVjaWVzX3dpbnRlcjtcbiAgICAgIHBhcmsucHJvcF9jb2xvbml6YXRpb25zX3N1bW1lciA9ICtwYXJrLnByb3BfY29sb25pemF0aW9uc19zdW1tZXI7XG4gICAgICBwYXJrLnByb3BfY29sb25pemF0aW9uc193aW50ZXIgPSArcGFyay5wcm9wX2NvbG9uaXphdGlvbnNfd2ludGVyO1xuICAgICAgcGFyay5wcm9wX2V4dGlycGF0aW9uc193aW50ZXIgPSArcGFyay5wcm9wX2V4dGlycGF0aW9uc193aW50ZXI7XG4gICAgICBwYXJrLnByb3BfZXh0aXJwYXRpb25zX3N1bW1lciA9ICtwYXJrLnByb3BfZXh0aXJwYXRpb25zX3N1bW1lcjtcbiAgICAgIHBhcmsubm9fZXh0aXJwYXRpb25zX3N1bW1lciA9ICtwYXJrLm5vX2V4dGlycGF0aW9uc19zdW1tZXI7XG4gICAgICBwYXJrLm5vX2V4dGlycGF0aW9uc193aW50ZXIgPSArcGFyay5ub19leHRpcnBhdGlvbnNfd2ludGVyO1xuICAgICAgcGFyay5ub19jb2xvbml6YXRpb25zX3N1bW1lciA9ICtwYXJrLm5vX2NvbG9uaXphdGlvbnNfc3VtbWVyO1xuICAgICAgcGFyay5ub19jb2xvbml6YXRpb25zX3dpbnRlciA9ICtwYXJrLm5vX2NvbG9uaXphdGlvbnNfd2ludGVyO1xuICAgIH0pO1xuXG4gICAgLy8gZ2V0IHJpZCBvZiBoYXdhaWlcbiAgICBzdGF0ZXMgPSBzdGF0ZXMuZmVhdHVyZXMuZmlsdGVyKGQgPT4ge1xuICAgICAgcmV0dXJuIGQucHJvcGVydGllcy5hZG0wX2EzID09ICdVU0EnICYmIGQucHJvcGVydGllcy5wb3N0YWwgIT0gJ0hJJztcbiAgICB9KVxuXG5cbiAgICBfcGFya3MgPSBwYXJrcztcbiAgICBfc3RhdGVzID0gc3RhdGVzO1xuXG4gICAgcmVkcmF3KCk7XG5cbiAgICB3aW5kb3cuYWRkRXZlbnRMaXN0ZW5lcihcInJlc2l6ZVwiLCByZWRyYXcpO1xuXG4gIH0pO1xuXG4gIHJldHVybiB7XG4gICAgc2V0UGFyYW1zOiBzZXRQYXJhbXNcbiAgfVxufVxuXG5leHBvcnQgeyBQYXJrTWFwIH07XG4iLCJmdW5jdGlvbiBmb3JtYXRUdXJub3ZlcihkKSB7XG4gICAgcmV0dXJuIE1hdGgucm91bmQoZCAqIDEwMCkgKyAnJSc7XG59XG5cbmZ1bmN0aW9uIGNlbnRlck9uWChlbGVtZW50LCB4KSB7XG4gICAgLy8gcG9zaXRpb25zIGFuIGVsZW1lbnQgb24geCByZWxhdGl2ZSB0byBpdHMgcGFyZW50XG4gICAgLy8gc25hcHMgdGhlIGVsZW1lbnQgdG8gdGhlIGJvdW5kYXJpZXMgb2YgdGhlIHBhcmVudFxuXG4gICAgbGV0IHdpZHRoID0gZWxlbWVudC5ub2RlKCkub2Zmc2V0V2lkdGg7XG4gICAgbGV0IG1heFdpZHRoID0gZWxlbWVudC5ub2RlKCkucGFyZW50Tm9kZS5vZmZzZXRXaWR0aDtcblxuICAgIHggPSB4IC0gd2lkdGggLyAyO1xuXG4gICAgLy8gc25hcCB0byB0aGUgd2luZG93XG4gICAgaWYgKHggPCAwKSB7XG4gICAgICAgIHggPSAwO1xuICAgIH0gZWxzZSBpZiAoeCArIHdpZHRoID4gbWF4V2lkdGgpIHtcbiAgICAgICAgeCA9IG1heFdpZHRoIC0gd2lkdGg7XG4gICAgfVxuXG4gICAgZWxlbWVudC5zdHlsZSgnbGVmdCcsIHggKyAncHgnKTtcbn1cblxuZnVuY3Rpb24gRG90Q2hhcnQocGFyYW1zKSB7XG4gICAgY29uc3Qge2VsZW1lbnQsIHNob3dOYW1lLCBvbkhvdmVyLCBvbkNsaWNrLCBzY2FsZX0gPSBwYXJhbXM7XG5cbiAgICBsZXQgX2RhdGEgPSBbXTtcbiAgICBsZXQgaGl0RGV0ZWN0b3I7XG4gICAgbGV0IGhlaWdodCA9IDkwO1xuXG4gICAgY29uc3QgUkFESVVTID0gNjtcbiAgICBjb25zdCBTRUxFQ1RFRF9SQURJVVMgPSAxMztcbiAgICBsZXQgZG90Q2VudGVyID0gaGVpZ2h0IC0gNiAtIFNFTEVDVEVEX1JBRElVUztcbiAgICBsZXQgbWFyZ2luID0ge1xuICAgICAgICB0b3A6IDAsXG4gICAgICAgIGxlZnQ6IDIwXG4gICAgfTtcbiAgICBsZXQgeDtcblxuXG4gICAgbGV0IHN2ZyA9IGVsZW1lbnQuYXBwZW5kKCdzdmcnKVxuICAgICAgICAgICAgICAgIC5hcHBlbmQoJ2cnKVxuICAgICAgICAgICAgICAgIC5hdHRyKCd0cmFuc2Zvcm0nLCBgdHJhbnNsYXRlKCR7bWFyZ2luLmxlZnR9LCAke21hcmdpbi50b3B9KWApO1xuXG4gICAgc3ZnLmFwcGVuZCgncmVjdCcpXG4gICAgICAgIC5hdHRyKCdjbGFzcycsICdvdmVybGF5JylcbiAgICAgICAgLmF0dHIoJ2hlaWdodCcsIGhlaWdodClcbiAgICAgICAgLmF0dHIoJ3gnLCAwKVxuICAgICAgICAuYXR0cigneScsIDApXG4gICAgICAgIC5hdHRyKCdmaWxsLW9wYWNpdHknLCAwLjApO1xuXG4gICAgbGV0IGZvY3VzID0gZWxlbWVudC5hcHBlbmQoJ2RpdicpLmNsYXNzZWQoJ3NkLXR1cm5vdmVyLXRvb2x0aXAnLCB0cnVlKS5jbGFzc2VkKCdoaWRkZW4nLCB0cnVlKTtcbiAgICBsZXQgcGVybWFGb2N1cyA9IGVsZW1lbnQuYXBwZW5kKCdkaXYnKS5jbGFzc2VkKCdzZC1wZXJtYS10b29sdGlwJywgdHJ1ZSlcbiAgICBsZXQgZmllbGQ7XG5cbiAgICBmdW5jdGlvbiByZWRyYXcoZGF0YSwgX2ZpZWxkLCBzZWxlY3RlZCkge1xuICAgICAgICAvLyBjb3B5IG92ZXIgdGhlIGFycmF5XG4gICAgICAgIGZpZWxkID0gX2ZpZWxkO1xuICAgICAgICBfZGF0YSA9IGRhdGEuc2xpY2UoKTtcblxuICAgICAgICAvLyBzb3J0IGluIGFzY2VuZGluZyB2YWx1ZVxuICAgICAgICBfZGF0YS5zb3J0KChhLCBiKSA9PiBkMy5hc2NlbmRpbmcoYVtmaWVsZF0sIGJbZmllbGRdKSk7XG5cbiAgICAgICAgLy8gc2l6ZSB0aGUgc3ZnXG4gICAgICAgIGxldCB3aWR0aCA9IGVsZW1lbnQubm9kZSgpLm9mZnNldFdpZHRoO1xuICAgICAgICBlbGVtZW50LnN0eWxlKCdoZWlnaHQnLCBoZWlnaHQgKyAncHgnKVxuICAgICAgICBlbGVtZW50LnNlbGVjdCgnc3ZnJylcbiAgICAgICAgICAgIC5hdHRyKCd3aWR0aCcsIHdpZHRoKVxuICAgICAgICAgICAgLmF0dHIoJ2hlaWdodCcsIGhlaWdodClcblxuXG4gICAgICAgIC8vIHRoaXMgc2NhbGUgaXMgbm93IGluZGVwZW5kZW50XG5cbiAgICAgICAgbGV0IF94O1xuICAgICAgICBpZiAoc2NhbGUgPT0gJ2xvZycpIHtcbiAgICAgICAgICAgIF94ID0gZDMuc2NhbGVMb2coKVxuICAgICAgICAgICAgICAgIC5yYW5nZShbMCwgd2lkdGggLSAyICogbWFyZ2luLmxlZnRdKVxuICAgICAgICAgICAgICAgIC5jbGFtcCh0cnVlKTtcbiAgICAgICAgICAgIGxldCBkb21haW4gPSBkMy5leHRlbnQoZGF0YSwgZCA9PiBkW2ZpZWxkXSAqIDEwMCk7XG4gICAgICAgICAgICBkb21haW5bMF0gPSBNYXRoLm1heCgxLCBkb21haW5bMF0pO1xuICAgICAgICAgICAgX3guZG9tYWluKGRvbWFpbik7XG4gICAgICAgIH0gZWxzZSB7XG4gICAgICAgICAgICBfeCA9IGQzLnNjYWxlTGluZWFyKClcbiAgICAgICAgICAgICAgICAucmFuZ2UoWzAsIHdpZHRoIC0gMiAqIG1hcmdpbi5sZWZ0XSlcbiAgICAgICAgICAgICAgICAuY2xhbXAodHJ1ZSk7XG4gICAgICAgICAgICBfeC5kb21haW4oZDMuZXh0ZW50KGRhdGEsIGQgPT4gZFtmaWVsZF0gKiAxMDApKTtcbiAgICAgICAgfVxuXG4gICAgICAgIHggPSAoZCkgPT4gX3goZFtmaWVsZF0gKiAxMDApO1xuXG4gICAgICAgIC8vIGNvbnNvbGUubG9nKCd4JywgX3guZG9tYWluKCksIF94LnJhbmdlKCkpO1xuXG4gICAgICAgIGxldCBzZWxlY3RlZERhdGEgPSBfZGF0YS5maW5kKGQgPT4gZC51bml0X25hbWUgPT0gc2VsZWN0ZWQpO1xuXG4gICAgICAgIC8vIHJlbmRlciB0aGUgc2VsZWN0aW9uXG4gICAgICAgIGxldCBzZWxlY3RlZERvdHMgPSBzdmcuc2VsZWN0QWxsKCcuc2Qtc2VsZWN0ZWQtZG90JykuZGF0YShbc2VsZWN0ZWREYXRhXSk7XG4gICAgICAgIHNlbGVjdGVkRG90cy5lbnRlcigpXG4gICAgICAgICAgICAuYXBwZW5kKCdjaXJjbGUnKVxuICAgICAgICAgICAgLmNsYXNzZWQoJ3NkLXNlbGVjdGVkLWRvdCcsIHRydWUpXG4gICAgICAgICAgICAubWVyZ2Uoc2VsZWN0ZWREb3RzKVxuICAgICAgICAgICAgICAgIC5hdHRyKCdjeCcsIHgpXG4gICAgICAgICAgICAgICAgLmF0dHIoJ2N5JywgZG90Q2VudGVyKVxuICAgICAgICAgICAgICAgIC5hdHRyKCdyJywgU0VMRUNURURfUkFESVVTKTtcblxuICAgICAgICAvLyByZW5kZXIgdGhlIG90aGVyIHBhcmtzXG4gICAgICAgIGxldCBvdGhlclBhcmtzID0gX2RhdGEuZmlsdGVyKGQgPT4gZC51bml0X25hbWUgIT0gc2VsZWN0ZWQpO1xuICAgICAgICAvLyBjb25zb2xlLmxvZygnb3RoZXJwYXJrcycsIG90aGVyUGFya3MpO1xuICAgICAgICBsZXQgZG90cyA9IHN2Zy5zZWxlY3RBbGwoJy5zZC1kb3QnKS5kYXRhKG90aGVyUGFya3MpO1xuICAgICAgICBkb3RzLmVudGVyKClcbiAgICAgICAgICAgIC5hcHBlbmQoJ2NpcmNsZScpXG4gICAgICAgICAgICAuY2xhc3NlZCgnc2QtZG90JywgdHJ1ZSlcbiAgICAgICAgICAgIC5tZXJnZShkb3RzKVxuICAgICAgICAgICAgICAgIC5jbGFzc2VkKCdzZWxlY3RlZCcsIGQgPT4gZC51bml0X25hbWUgPT09IHNlbGVjdGVkKVxuICAgICAgICAgICAgICAgIC5hdHRyKCdjeCcsIHgpXG4gICAgICAgICAgICAgICAgLmF0dHIoJ2N5JywgZG90Q2VudGVyKVxuICAgICAgICAgICAgICAgIC5hdHRyKCdyJywgUkFESVVTKTtcblxuICAgICAgICBoaXREZXRlY3RvciA9IGQzLnZvcm9ub2koKVxuICAgICAgICAgICAgLngoeClcbiAgICAgICAgICAgIC55KDApXG4gICAgICAgICAgICAob3RoZXJQYXJrcyk7XG5cbiAgICAgICAgLy8gaGl0IGRldGVjdG9yIG92ZXJsYXlcbiAgICAgICAgdmFyIG92ZXJsYXkgPSBzdmcuc2VsZWN0KCcub3ZlcmxheScpXG4gICAgICAgICAgICAuYXR0cignd2lkdGgnLCB3aWR0aClcbiAgICAgICAgICAgIC5vbignbW91c2VvdmVyJywgbW91c2Vtb3ZlKVxuICAgICAgICAgICAgLm9uKCdtb3VzZW91dCcsIGQgPT4gb25Ib3ZlcigpKVxuICAgICAgICAgICAgLm9uKCdtb3VzZW1vdmUnLCBtb3VzZW1vdmUpXG4gICAgICAgICAgICAub24oJ3RvdWNobW92ZScsIHRvdWNobW92ZSlcbiAgICAgICAgICAgIC5vbignY2xpY2snLCBtb3VzZWNsaWNrKTtcblxuICAgICAgICAvLyBsYWJlbHNcbiAgICAgICAgbGV0IHBlcm1hTGFiZWwgPSAnJztcbiAgICAgICAgaWYgKHNob3dOYW1lKSB7XG4gICAgICAgICAgICBwZXJtYUxhYmVsID0gc2VsZWN0ZWREYXRhLnVuaXRfbmFtZSArICcgJztcbiAgICAgICAgfVxuICAgICAgICBwZXJtYUxhYmVsICs9IGZvcm1hdFR1cm5vdmVyKHNlbGVjdGVkRGF0YVtmaWVsZF0pO1xuICAgICAgICBwZXJtYUZvY3VzLnRleHQocGVybWFMYWJlbCk7XG5cblxuICAgICAgICBsZXQgZHkgPSBkb3RDZW50ZXIgLSAoU0VMRUNURURfUkFESVVTICogMykgLSAxMCArIG1hcmdpbi50b3A7XG4gICAgICAgIHBlcm1hRm9jdXMuc3R5bGUoJ3RvcCcsIGR5ICsgJ3B4Jyk7XG5cbiAgICAgICAgY2VudGVyT25YKHBlcm1hRm9jdXMsIHgoc2VsZWN0ZWREYXRhKSArIG1hcmdpbi5sZWZ0KTtcblxuICAgICAgICBkeSA9IGRvdENlbnRlciAtIChSQURJVVMgKiAzKSAtIDE0ICsgbWFyZ2luLnRvcDtcbiAgICAgICAgZm9jdXMuc3R5bGUoJ3RvcCcsIGR5ICsgJ3B4Jyk7XG4gICAgfVxuXG4gICAgZnVuY3Rpb24gY2xlYXJIb3ZlcigpIHtcbiAgICAgICAgc3ZnLnNlbGVjdEFsbChcIi5zZC1kb3RcIilcbiAgICAgICAgICAgIC5jbGFzc2VkKFwiaG92ZXJlZFwiLCBmYWxzZSk7XG5cbiAgICAgICAgLy8gY2xlYXIgZm9jdXNcbiAgICAgICAgZm9jdXMuY2xhc3NlZCgnaGlkZGVuJywgdHJ1ZSlcbiAgICB9XG5cbiAgICBmdW5jdGlvbiByZW5kZXJIb3ZlcihuYW1lKSB7XG4gICAgICAgIC8vIHJlbmRlciBob3ZlciBzdGF0ZVxuICAgICAgICAvLyBjb25zb2xlLmxvZygncmVuZGVySG92ZXIgZm9yJywgZWxlbWVudC5ub2RlKCkuaWQpO1xuICAgICAgICBsZXQgb2JqID0gX2RhdGEuZmluZChkID0+IGQudW5pdF9uYW1lID09PSBuYW1lKTtcbiAgICAgICAgaWYgKCFvYmopIHtcbiAgICAgICAgICAgIC8vIGNvbnNvbGUubG9nKFwiT0ggTk8gY2FuJ3QgZmluZFwiLCBuYW1lKTtcbiAgICAgICAgICAgIHJldHVybjtcbiAgICAgICAgfVxuICAgICAgICBzdmcuc2VsZWN0QWxsKFwiLnNkLWRvdFwiKVxuICAgICAgICAgICAgLmNsYXNzZWQoXCJob3ZlcmVkXCIsIGQgPT4gZC51bml0X25hbWUgPT09IG9iai51bml0X25hbWUpO1xuXG4gICAgICAgIC8vIGZvcm1hdCB0aGUgZm9jdXNcbiAgICAgICAgbGV0IHRleHQgPSAnJztcbiAgICAgICAgaWYgKHNob3dOYW1lKSB7XG4gICAgICAgICAgICB0ZXh0ID0gb2JqLnVuaXRfbmFtZSArICcgJztcbiAgICAgICAgfVxuICAgICAgICB0ZXh0ICs9IGZvcm1hdFR1cm5vdmVyKG9ialtmaWVsZF0pO1xuICAgICAgICBmb2N1cy50ZXh0KHRleHQpO1xuICAgICAgICBmb2N1cy5jbGFzc2VkKCdoaWRkZW4nLCBmYWxzZSlcblxuICAgICAgICBjZW50ZXJPblgoZm9jdXMsIHgob2JqKSArIG1hcmdpbi5sZWZ0KTtcbiAgICAgICAgLy8gbW92ZSB0byB0b3BcbiAgICAgICAgbGV0IGhvdmVyZWQgPSBzdmcuc2VsZWN0KCcuaG92ZXJlZCcpLm5vZGUoKTtcbiAgICAgICAgaG92ZXJlZC5wYXJlbnRFbGVtZW50LmFwcGVuZENoaWxkKGhvdmVyZWQpO1xuICAgIH1cblxuICAgIGZ1bmN0aW9uIHRvdWNobW92ZSgpIHtcbiAgICAgICAgdmFyIG1vdXNlWCA9IGQzLnRvdWNoZXModGhpcylbMF1bMF07XG4gICAgICAgIHZhciBmb3VuZCA9IGhpdERldGVjdG9yLmZpbmQobW91c2VYLCAwLCAyMCk7XG5cbiAgICAgICAgaWYgKGZvdW5kKSB7XG4gICAgICAgICAgICBmb3VuZCA9IGZvdW5kLmRhdGE7XG4gICAgICAgICAgICAvLyBjb25zb2xlLmxvZygnZm91bmQgaG92ZXInLCBmb3VuZCk7XG4gICAgICAgICAgICBvbkhvdmVyKGZvdW5kLnVuaXRfbmFtZSk7XG4gICAgICAgIH0gZWxzZSB7XG4gICAgICAgICAgICBvbkhvdmVyKCk7XG4gICAgICAgIH1cbiAgICB9XG5cbiAgICBmdW5jdGlvbiBtb3VzZW1vdmUoKSB7XG4gICAgICAgIHZhciBtb3VzZVggPSBkMy5tb3VzZSh0aGlzKVswXTtcbiAgICAgICAgdmFyIGZvdW5kID0gaGl0RGV0ZWN0b3IuZmluZChtb3VzZVgsIDAsIDIwKTtcblxuICAgICAgICBpZiAoZm91bmQpIHtcbiAgICAgICAgICAgIGZvdW5kID0gZm91bmQuZGF0YTtcbiAgICAgICAgICAgIC8vIGNvbnNvbGUubG9nKCdmb3VuZCBob3ZlcicsIGZvdW5kKTtcbiAgICAgICAgICAgIG9uSG92ZXIoZm91bmQudW5pdF9uYW1lKTtcbiAgICAgICAgfSBlbHNlIHtcbiAgICAgICAgICAgIG9uSG92ZXIoKTtcbiAgICAgICAgfVxuICAgIH1cblxuICAgIGZ1bmN0aW9uIG1vdXNlY2xpY2soKSB7XG4gICAgICAgIHZhciBtb3VzZVggPSBkMy5tb3VzZSh0aGlzKVswXTtcbiAgICAgICAgdmFyIGZvdW5kID0gaGl0RGV0ZWN0b3IuZmluZChtb3VzZVgsIDAsIDIwKTtcblxuICAgICAgICBpZiAoZm91bmQpIHtcbiAgICAgICAgICAgIGlmIChvbkNsaWNrKSB7XG4gICAgICAgICAgICAgICAgb25DbGljayhmb3VuZC5kYXRhLnVuaXRfbmFtZSk7XG4gICAgICAgICAgICB9XG4gICAgICAgIH1cbiAgICB9XG5cbiAgICByZXR1cm4ge1xuICAgICAgICByZWRyYXc6IHJlZHJhdyxcbiAgICAgICAgaGlnaGxpZ2h0OiByZW5kZXJIb3ZlcixcbiAgICAgICAgY2xlYXJIaWdobGlnaHQ6IGNsZWFySG92ZXJcbiAgICB9XG59XG5cbmZ1bmN0aW9uIFR1cm5vdmVyQ2hhcnQocGFyYW1zKSB7XG4gICAgbGV0IHtlbGVtZW50LCBkYXRhVXJsLCBwYXJrLCBvbkNsaWNrLCBzZWFzb259ID0gcGFyYW1zO1xuICAgIGxldCBfc2Vhc29uID0gc2Vhc29uIHx8ICdzdW1tZXInO1xuXG4gICAgZWxlbWVudCA9IGQzLnNlbGVjdChlbGVtZW50KTtcblxuICAgIC8vIGNyZWF0ZSB0aGUgdGVtcGxhdGVcbiAgICBlbGVtZW50Lmh0bWwoYFxuICAgICAgICA8ZGl2IGNsYXNzPVwic2QtdHVybm92ZXItY2hhcnRcIj5cbiAgICAgICAgICAgIDxkaXYgY2xhc3M9XCJzZC1kb3QtY2hhcnRcIj5cbiAgICAgICAgICAgICAgICA8ZGl2IGlkPVwic2QtbWFpbmNoYXJ0XCI+PC9kaXY+XG4gICAgICAgICAgICAgICAgPGRpdiBjbGFzcz1cInNkLWxpbmVcIj48L2Rpdj5cbiAgICAgICAgICAgICAgICA8ZGl2IGNsYXNzPVwic2QtbGFiZWwtYXJlYVwiPlxuICAgICAgICAgICAgICAgICAgICA8aDIgY2xhc3M9XCJzZC1heGlzLWxhYmVsXCI+UG90ZW50aWFsIFR1cm5vdmVyPC9oMj5cbiAgICAgICAgICAgICAgICA8L2Rpdj5cbiAgICAgICAgICAgIDwvZGl2PlxuICAgICAgICAgICAgPGRpdj5cbiAgICAgICAgICAgICAgICA8ZGl2IGNsYXNzPVwic2Qtc3Vicm93IHNkLWxlZnRcIj5cbiAgICAgICAgICAgICAgICAgICAgPGRpdiBjbGFzcz1cInNkLWRvdC1jaGFydFwiPlxuICAgICAgICAgICAgICAgICAgICAgICAgPGRpdiBpZD1cInNkLXN1YmNoYXJ0LTFcIj48L2Rpdj5cbiAgICAgICAgICAgICAgICAgICAgICAgIDxkaXYgY2xhc3M9XCJzZC1saW5lXCI+PC9kaXY+XG4gICAgICAgICAgICAgICAgICAgICAgICA8ZGl2IGNsYXNzPVwic2QtbGFiZWwtYXJlYVwiPlxuICAgICAgICAgICAgICAgICAgICAgICAgICAgIDxoMiBjbGFzcz1cInNkLWF4aXMtbGFiZWxcIj5Qb3RlbnRpYWwgQ29sb25pemF0aW9uPC9oMj5cbiAgICAgICAgICAgICAgICAgICAgICAgIDwvZGl2PlxuICAgICAgICAgICAgICAgICAgICA8L2Rpdj5cbiAgICAgICAgICAgICAgICA8L2Rpdj5cbiAgICAgICAgICAgICAgICA8ZGl2IGNsYXNzPVwic2Qtc3Vicm93IHNkLXJpZ2h0XCI+XG4gICAgICAgICAgICAgICAgICAgIDxkaXYgY2xhc3M9XCJzZC1kb3QtY2hhcnRcIj5cbiAgICAgICAgICAgICAgICAgICAgICAgIDxkaXYgaWQ9XCJzZC1zdWJjaGFydC0yXCI+PC9kaXY+XG4gICAgICAgICAgICAgICAgICAgICAgICA8ZGl2IGNsYXNzPVwic2QtbGluZVwiPjwvZGl2PlxuICAgICAgICAgICAgICAgICAgICAgICAgPGRpdiBjbGFzcz1cInNkLWxhYmVsLWFyZWFcIj5cbiAgICAgICAgICAgICAgICAgICAgICAgICAgICA8aDIgY2xhc3M9XCJzZC1heGlzLWxhYmVsXCI+UG90ZW50aWFsIEV4dGlycGF0aW9uPC9oMj5cbiAgICAgICAgICAgICAgICAgICAgICAgIDwvZGl2PlxuICAgICAgICAgICAgICAgICAgICA8L2Rpdj5cbiAgICAgICAgICAgICAgICA8L2Rpdj5cbiAgICAgICAgICAgIDwvZGl2PlxuICAgICAgICA8L2Rpdj5cbiAgICBgKTtcblxuICAgIGxldCBkYXRhID0gW107XG4gICAgbGV0IG1haW5DaGFydCA9IG5ldyBEb3RDaGFydCh7XG4gICAgICAgIGVsZW1lbnQ6IGVsZW1lbnQuc2VsZWN0KCcjc2QtbWFpbmNoYXJ0JyksXG4gICAgICAgIHNob3dOYW1lOiB0cnVlLFxuICAgICAgICBvbkNsaWNrOiBvbkNsaWNrLFxuICAgICAgICBvbkhvdmVyOiBvbkhvdmVyLFxuICAgICAgICBzY2FsZTogJ2xpbmVhcidcbiAgICB9KTtcbiAgICBsZXQgc3ViQ2hhcnQxID0gbmV3IERvdENoYXJ0KHtcbiAgICAgICAgZWxlbWVudDogZWxlbWVudC5zZWxlY3QoJyNzZC1zdWJjaGFydC0xJyksXG4gICAgICAgIHNob3dOYW1lOiBmYWxzZSxcbiAgICAgICAgb25DbGljazogb25DbGljayxcbiAgICAgICAgb25Ib3Zlcjogb25Ib3ZlcixcbiAgICAgICAgc2NhbGU6ICdsb2cnXG4gICAgfSk7XG4gICAgbGV0IHN1YkNoYXJ0MiA9IG5ldyBEb3RDaGFydCh7XG4gICAgICAgIGVsZW1lbnQ6IGVsZW1lbnQuc2VsZWN0KCcjc2Qtc3ViY2hhcnQtMicpLFxuICAgICAgICBzaG93TmFtZTogZmFsc2UsXG4gICAgICAgIG9uQ2xpY2s6IG9uQ2xpY2ssXG4gICAgICAgIG9uSG92ZXI6IG9uSG92ZXIsXG4gICAgICAgIHNjYWxlOiAnbG9nJ1xuICAgIH0pO1xuXG4gICAgZnVuY3Rpb24gb25Ib3ZlcihuYW1lKSB7XG4gICAgICAgIGlmICghbmFtZSkge1xuICAgICAgICAgICAgbWFpbkNoYXJ0LmNsZWFySGlnaGxpZ2h0KCk7XG4gICAgICAgICAgICBzdWJDaGFydDEuY2xlYXJIaWdobGlnaHQoKTtcbiAgICAgICAgICAgIHN1YkNoYXJ0Mi5jbGVhckhpZ2hsaWdodCgpO1xuICAgICAgICAgICAgcmV0dXJuO1xuICAgICAgICB9XG5cbiAgICAgICAgbWFpbkNoYXJ0LmhpZ2hsaWdodChuYW1lKTtcbiAgICAgICAgc3ViQ2hhcnQxLmhpZ2hsaWdodChuYW1lKTtcbiAgICAgICAgc3ViQ2hhcnQyLmhpZ2hsaWdodChuYW1lKTtcbiAgICB9XG5cbiAgICBmdW5jdGlvbiByZWRyYXcoKSB7XG4gICAgICAgIG1haW5DaGFydC5yZWRyYXcoZGF0YSwgJ3R1cm5vdmVyXycgKyBfc2Vhc29uLCBwYXJrKTtcbiAgICAgICAgc3ViQ2hhcnQxLnJlZHJhdyhkYXRhLCAncHJvcF9jb2xvbml6YXRpb25zXycgKyBfc2Vhc29uLCBwYXJrKTtcbiAgICAgICAgc3ViQ2hhcnQyLnJlZHJhdyhkYXRhLCAncHJvcF9leHRpcnBhdGlvbnNfJyArIF9zZWFzb24sIHBhcmspO1xuICAgIH1cblxuICAgIGZ1bmN0aW9uIHNldFNlYXNvbihzZWFzb24pIHtcbiAgICAgICAgaWYgKHNlYXNvbiA9PT0gJ3N1bW1lcicgfHwgc2Vhc29uID09PSAnd2ludGVyJykge1xuICAgICAgICAgICAgX3NlYXNvbiA9IHNlYXNvbjtcbiAgICAgICAgICAgIHJlZHJhdygpO1xuICAgICAgICB9IGVsc2Uge1xuICAgICAgICAgICAgY29uc29sZS5sb2coJ0VSUk9SOiBzZWFzb24gbXVzdCBiZSBzdW1tZXIgb3Igd2ludGVyLCByZWNlaXZlZCcsIHNlYXNvbik7XG4gICAgICAgIH1cbiAgICB9XG5cbiAgICBkMy5jc3YoZGF0YVVybCwgKGVycm9yLCByb3dzKSA9PiB7XG4gICAgICAgIGNvbnNvbGUubG9nKGVycm9yKTtcblxuICAgICAgICAvLyBwcmVwcm9jZXNzXG4gICAgICAgIHJvd3MuZm9yRWFjaChyID0+IHtcbiAgICAgICAgICAgIHIucHJvcF9jb2xvbml6YXRpb25zX3N1bW1lciA9ICtyLnByb3BfY29sb25pemF0aW9uc19zdW1tZXI7XG4gICAgICAgICAgICByLnByb3BfY29sb25pemF0aW9uc193aW50ZXIgPSArci5wcm9wX2NvbG9uaXphdGlvbnNfd2ludGVyO1xuICAgICAgICAgICAgci5wcm9wX2V4dGlycGF0aW9uc19zdW1tZXIgPSArci5wcm9wX2V4dGlycGF0aW9uc19zdW1tZXI7XG4gICAgICAgICAgICByLnByb3BfZXh0aXJwYXRpb25zX3dpbnRlciA9ICtyLnByb3BfZXh0aXJwYXRpb25zX3dpbnRlcjtcbiAgICAgICAgICAgIHIudHVybm92ZXJfc3VtbWVyID0gK3IudHVybm92ZXJfc3VtbWVyO1xuICAgICAgICAgICAgci50dXJub3Zlcl93aW50ZXIgPSArci50dXJub3Zlcl93aW50ZXI7XG4gICAgICAgIH0pXG5cbiAgICAgICAgLy8gY29uc29sZS5sb2cocm93cyk7XG4gICAgICAgIGRhdGEgPSByb3dzO1xuXG4gICAgICAgIHJlZHJhdygpO1xuICAgICAgICB3aW5kb3cuYWRkRXZlbnRMaXN0ZW5lcihcInJlc2l6ZVwiLCByZWRyYXcpO1xuICAgIH0pO1xuXG4gICAgcmV0dXJuIHtcbiAgICAgICAgc2V0U2Vhc29uOiBzZXRTZWFzb25cbiAgICB9XG59XG5cbmV4cG9ydCB7IFR1cm5vdmVyQ2hhcnQgfTtcbiJdfQ==
