/**
 * @file
 * D3 Bar Graph library js file.
 */

(function ($) {

  Drupal.d3.ct_bar = function (select, settings) {

    function drawData(select, settings) {
      settings.id = settings.id || select;

      var key = [],
        range = settings.graphColor || ["blue", "red", "orange", "green"];
      if (typeof settings.legend != 'undefined') {
        key = settings.legend;
      }

      if (settings.rows !== null && typeof settings.rows == 'object' && !settings.rows.length) {
        var rows = settings.rows,
          // Use first value in each row as the label.
          xLabels = Object.keys(rows),
          max = d3.max(d3.merge(
            Object.keys(settings.rows).map(function (site) {
              return Object.keys(settings.rows[site]).map(function (key) {
                return settings.rows[site][key][1];
              });
            }))),
          bars = Object.keys(rows).length;


      }
      else {
        var rows = settings.rows,
          // Use first value in each row as the label.
          xLabels = rows.map(function (d) {
            return d.shift();
          }),
          max = d3.max(d3.merge(rows).map(function (d) {
            return +d;
          })),
          bars = rows.length;
      }

      // From inside out:
      // - Convert all values to numeric numbers.
      // - Merge all sub-arrays into one flat array.
      // - Return the highest (numeric) value from flat array.

      var hq = .75;
      if (key.length > 0) {
        hq = .60;
      }

      // Padding is top, right, bottom, left as in css padding.
      var p = [40, 50, 40, 40],
        w = settings.width || 800,
        h = settings.height || 400,
        // chart is 65% and 80% of overall height
        //chart = {w: w * .65, h: h * .80},
        chart = {w: w, h: h * hq},
        legend = {w: w * .35, h: h};
      // bar width is calculated based on chart width, and amount of data
      // items - will resize if there is more or less
      // space in between each set
//        x = d3.scale.linear().domain([0, bars]).range([0, chart.w]),


      if (settings.lineY) {
        p[3] = 100;
      }

      if (key.length > 0) {
        barWidth = settings.barWidth || ((.90 * chart.w) / (rows.length * key.length)),
          // each cluster of bars - makes coding later easier
          barGroupWidth = key.length * barWidth;
      }
      else {
        var barWidth = settings.barWidth || ((.90 * chart.w) / rows.length),
          // each cluster of bars - makes coding later easier
          barGroupWidth = barWidth;
      }
      //var barSpacing = (.10 * chart.w) / rows.length;
      var barSpacing = (chart.w - rows.length * barWidth) / rows.length,
        barRx = settings.barRx || 0;

      var full_width = bars * (barGroupWidth + 40);
      var range_width = chart.w;
      if (full_width > chart.w) {
        range_width = full_width;
        //
      }
      else {
        full_width = chart.w;
      }

      x = d3.scale.linear().domain([0, bars]).range([0, range_width]),
        y = d3.scale.linear().domain([0, max]).range([chart.h, 0]),
        z = d3.scale.ordinal().range(range),
        div = (settings.id) ? settings.id : 'visualization';

      var svg = d3.select('#' + div).append("svg")
        .attr("width", w)
        .attr("height", h)
        .style('cursor', function () {
          if (full_width > chart.w) {
            return 'ew-resize';
          }
          else {
            return 'auto';
          }
        })
        .append("g")
        .attr("transform", "translate(" + p[3] + "," + p[0] + ")");

      var graph = svg.append("g")
        .attr("class", "chart")
        .attr('transform', 'translate(0,0)');

      /* X AXIS  */
      var xTicks = graph.selectAll("g.ticks")
        .data(rows)
        .enter().append("g")
        .attr("class", "ticks")
        .attr('transform', function (d, i) {
          return 'translate(' + (x(i) + (barGroupWidth / 2)) + ',' + (chart.h) + ')'
        })
        .append("text")
        .attr("font-size", "12px")
        .attr("font-family", "\"Source Sans Pro\", Verdana, sans-serif")
        .attr("dy", "1.75em")
        .attr("text-anchor", "middle")
        .style('fill', d3.rgb("#666666"))
        .text(function (d, i) {
          return xLabels[i];
        })
        .call(wrap, barGroupWidth + barSpacing - 10);

      /* LINES */
      var rule = graph.selectAll("g.rule")
        .data(y.ticks(4))
        .enter().append("g")
        .attr("class", "rule")
        .attr("transform", function (d) {
          return "translate(0," + y(d) + ")";
        });
      if (settings.lineX) {
        rule.append("line")
          .attr("x2", chart.w)
          .style("stroke", function (d) {
            return d ? "#ccc" : "#000";
          })
          .style("stroke-opacity", function (d) {
            return d ? .7 : null;
          });
      }


      /* Y AXIS */
      if (settings.lineY) {
        rule.append("text")
          .attr("x", -70)
          .attr("dy", ".35em")
          .attr("text-anchor", "end")
          .attr("font-size", "12px")
          .attr("font-family", "\"Source Sans Pro\", Verdana, sans-serif")
          .text(function (d) {
            return d;
          });
        //.text(d3.format(",d"));

        rule.append("line")
          .attr("y2", ".35em")
          .attr("x1", -55)
          .attr("x2", full_width)
          .style("stroke", "#ccc")
          .style("stroke-opacity", .7);

      }

      if (!key) {
        //Draw the line
        var line = graph.selectAll('line')
          .data(rows)
          .enter().append("line")
          .attr("x1", function (d, i) {
            return x(i) + 4;
          })
          .attr("y1", 0)
          .attr("x2", function (d, i) {
              return x(i) + 4;
          })
          .attr("y2", chart.h)
          .attr("stroke-width", 1)
          .attr("stroke", d3.rgb("#666666"))
          .style("stroke-opacity", 0.2);

      }

      var bar = graph.selectAll('g.bars')
        .data(rows)
        .enter().append('g')
        .attr('class', 'bargroup')
        .attr('transform', function (d, i) {
          return "translate(" + (x(i)) + ", 0)";
        });


      bar.selectAll('rect')
        .data(function (d) {
          for (var z in d) {
            if (isNaN(d[z])) {
              d[z] = 0;
            }
          }
          return d;
        })
        .enter().append('rect')
        .attr("width", barWidth)
        .attr("height", 0)
        .attr('x', function (d, i) {
          return i * barWidth;
        })
        .attr("rx", barRx)
        .attr('y', function (d, i) {
          return y(d) + (chart.h - y(d));
        })
        .attr('fill', function (d, i) {
          return d3.rgb(z(i));
        })
        .style('cursor', 'pointer')
        .on('mouseover', function (d, i) {
          showToolTip(d, i, this);
        })
        .on('mouseout', function (d, i) {
          hideToolTip(d, i, this);
        })
        .transition()
        .duration(700)
        .ease("linear")
        .attr("height", function (d) {

          return chart.h - y(d);
        })
        .attr('y', function (d, i) {
          return y(d);
        });


      if (!settings.tooltip) {
        // Add text label in bar
        bar.selectAll('text')
          .data(function (d) {
            return d;
          })
          .enter().append("text")
          .attr("text-anchor", "middle")
          .attr("x", function (d, i) {
            return i * barWidth + 5;
          })
          .attr("y", function (d, i) {
            return y(d) - 5;
          })
          .style('fill', function (d, i) {
            return d3.rgb(z(i));
          })
          .text(function (d, i) {
            return d;
          });
      }

      /* LEGEND */
      if (key.length > 0) {
        var legend = svg.append("g")
          .attr("class", "chart-legend")
          .attr("transform", "translate(0, 55)");

        var keys = legend.selectAll("g")
          .data(key)
          .enter().append("g")
          .attr("transform", function (d, i) {
            if (key[i-1]) {
              var size = textSize(key[i-1], '12px', "\"Source Sans Pro\", Verdana, sans-serif");
            }
            else {
              var size = {width: 0};
            }
            return "translate(" + ((i * 50) + size.width) + ", " + chart.h + ")"
          });

        keys.append("rect")
          .attr("fill", function (d, i) {
            return d3.rgb(z(i));
          })
          .attr("width", 16)
          .attr("height", 16)
          .attr("y", 0)
          .attr("x", 0);

        var labelWrapper = keys.append("g");

        labelWrapper.selectAll("text")
          .data(function (d, i) {
            return d3.splitString('' + key[i], 50);
          })
          .enter().append("text")
          .text(function (d) {
            return d;
          })
          .attr("x", 20)
          .attr("y", "1em")
          .attr("font-size", "12px")
          .attr("font-family", "\"Source Sans Pro\", Verdana, sans-serif");
      }


      if (full_width > chart.w) {
        var drag = {
          elem: null,
          x: 0,
          y: 0,
          state: false
        };

        var currentX = 0,
          currentY = 0;
        var currentdx = 201.70001220703125,
          currentdy = 36.69999694824219;
        var previousdx = 0,
          previousdy = 0;

        var max_scroll = 0,
          min_scroll = -(full_width - chart.w + p[1] + p[3]);


        $('.diagram-item').mousedown(function (e) {
          if (!drag.state && e.which == 1) {
            drag.elem = $('.diagram-item svg .chart');
            drag.state = true;
            currentX = e.offsetX;
            currentY = 0;
          }
          return false;
        });


        $('.diagram-item').mousemove(function (e) {
          if (drag.state) {
            dx = e.offsetX - currentX + currentdx;
            dy = 0;
            if (dx > min_scroll && dx < max_scroll) {
              newMatrix = 'translate(' + (dx) + ',' + (dy) + ')';
              previousdx = dx;
              previousdy = 0;
              $(drag.elem).attr('transform', newMatrix);
            }
          }
        });
        $('.diagram-item').mouseup(stopScroll);

        $('.diagram-item').mouseout(stopScroll);

        function stopScroll() {
          if (drag.state) {
            drag.state = false;
            currentdx = previousdx;
            currentdy = 0;
          }
        }

      }
      else {
        $('.diagram-item').unbind('mousedown');
        $('.diagram-item').unbind('mousemove');
        $('.diagram-item').unbind('mouseup');
      }


      function textSize(text, fontSize, fontFamily) {
        var container = d3.select('body').append('svg');

        container.append('text')
          .attr(
            {
              x: -99999,
              y: -99999
            })
          .attr("font-size", fontSize)
          .attr("font-family", fontFamily)
          .text(text);

        var size = container.node().getBBox();
        container.remove();
        return {width: size.width, height: size.height};
      }

      function showToolTip(d, i, obj) {
        // Change color and style of the bar.
        var bar = d3.select(obj);
        bar.attr('stroke', '#ccc')
          .attr('stroke-width', '1')
          .attr('opacity', '0.75');

        if (settings.tooltip) {
          var group = d3.select(obj.parentNode);

          var tooltip = graph.append('g')
            .attr('class', 'tooltip')
            // move to the x position of the parent group
            .attr('transform', function (data) {
              return group.attr('transform');
            })
            .append('g')
            // now move to the actual x and y of the bar within that group
            .attr('transform', function (data) {
              return 'translate(' + (Number(bar.attr('x')) + barWidth) + ','
                + y(d) + ')';
            });
          d3.ct_tooltip(tooltip, d);
        }

      }

      function hideToolTip(d, i, obj) {
        var group = d3.select(obj.parentNode);
        var bar = d3.select(obj);
        bar.attr('stroke-width', '0')
          .attr('opacity', 1);

        if (settings.tooltip) {
          graph.select('g.tooltip').remove();
        }

      }

      function wrap(text, width) {
        text.each(function () {
          var text = d3.select(this),
            words = text.text().split(/\s+/).reverse(),
            word,
            line = [],
            lineNumber = 0,
            lineHeight = -0.75, // ems
            y = text.attr("y"),
            dy = parseFloat(text.attr("dy")),
            tspan = text.text(null).append("tspan").attr("x", 0).attr("y", y).attr("dy", dy + "em");
          while (word = words.pop()) {
            line.push(word);
            tspan.text(line.join(" "));
            if (tspan.node().getComputedTextLength() > width) {
              line.pop();
              tspan.text(line.join(" "));
              line = [word];
              //tspan = text.append("tspan").attr("x", 0).attr("y",
              // y).attr("dy", ++lineNumber * lineHeight + dy +
              // "em").text(word);
              tspan = text.append("tspan").attr("x", 0).attr("y", y).attr("dy", "1em").text(word);
            }
          }
        });
      }

    }


    return {
      clear: function () {
        $('#' + select).empty();
      },
      update: function (settings) {
        this.clear();
        drawData(select, settings);
      },
    }


  }


})(jQuery);
