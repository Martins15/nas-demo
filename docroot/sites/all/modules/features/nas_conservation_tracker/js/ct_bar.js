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
        hq = .65;
      }

      // Padding is top, right, bottom, left as in css padding.
      var p = [40, 50, 400, 50],
        w = settings.width || 800,
        h = settings.height || 400,
        // chart is 65% and 80% of overall height
        //chart = {w: w * .65, h: h * .80},
        chart = {w: w, h: h * hq},
        legend = {w: w * .35, h: h},
        // bar width is calculated based on chart width, and amount of data
        // items - will resize if there is more or less
        // space in between each set
        x = d3.scale.linear().domain([0, bars]).range([0, chart.w]),
        y = d3.scale.linear().domain([0, max]).range([chart.h, 0]),
        z = d3.scale.ordinal().range(range),
        div = (settings.id) ? settings.id : 'visualization';

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

      var svg = d3.select('#' + div).append("svg")
        .attr("width", w)
        .attr("height", h)
        .append("g")
        .attr("transform", "translate(" + p[3] + "," + p[0] + ")");

      var graph = svg.append("g")
        .attr("class", "chart");

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
          .attr("x2", chart.w)
          .style("stroke", "#ccc")
          .style("stroke-opacity", .7);

      }

      //Draw the line
      var line = graph.selectAll('line')
        .data(rows)
        .enter().append("line")
        .attr("x1", function (d, i) {
          if (d.length > 1) {
            return x(i) + barGroupWidth;
          }
          else {
            return x(i) + 4;
          }


        })
        .attr("y1", 0)
        .attr("x2", function (d, i) {
          if (d.length > 1) {
            return x(i) + barGroupWidth;
          }
          else {
            return x(i) + 4;
          }
        })
        .attr("y2", chart.h)
        .attr("stroke-width", 1)
        .attr("stroke", d3.rgb("#666666"))
        .style("stroke-opacity", 0.2);

      var bar = graph.selectAll('g.bars')
        .data(rows)
        .enter().append('g')
        .attr('class', 'bargroup')
        .attr('transform', function (d, i) {
          return "translate(" + (x(i)) + ", 0)";
        });
      // var bar = graph.selectAll('g.bars')
      //   .data(rows)
      //   .enter().append('g')
      //   .attr('class', 'bargroup')
      //   .attr('transform', function (d, i) {
      //     return "translate(" + i * (barGroupWidth + barSpacing) + ", 0)";
      //   });


      bar.selectAll('rect')
        .data(function (d) {
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
        .text('111').on('mouseover', function (d, i) {
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


      // bar.selectAll('rect')
      //   .data(function (d) {
      //     return d;
      //   })
      //   .enter().append('rect')
      //   .attr("width", barWidth)
      //   .attr("height", function (d) {
      //     return chart.h - y(d);
      //   })
      //   .attr('x', function (d, i) {
      //     return i * barWidth;
      //   })
      //   .attr('y', function (d, i) {
      //     return y(d);
      //   })
      //   .attr('fill', function (d, i) {
      //     return d3.rgb(z(i));
      //   })
      //   .on('mouseover', function (d, i) {
      //     showToolTip(d, i, this);
      //   })
      //   .on('mouseout', function (d, i) {
      //     hideToolTip(d, i, this);
      //   });


//       var rowsValues = d3.merge(rows);
// console.log('ROWS!!!', rows, rowsValues);
//       graph.selectAll("text.bar")
//           .data(rowsValues)
//           .enter().append("text")
//           .attr("class", "bar")
//           .style('fill', function (d, i) {
//             console.log('RGB!!!', z(i));
//             return d3.rgb(z(i));
//           })
//           .attr("text-anchor", "middle")
//           .attr("x", function (d, i) {
//             console.log('X!!!',  x(i) + 5);
//             return x(i) + 5;
//           })
//           .attr("y", function (d) {
//             console.log('Y!!!',  y(d[0]) - 5);
//             return y(d[0]) - 5;
//           })
//           .text(function (d) {
//             console.log('TEXT!!!',  d);
//             return d[0];
//           });

      /* LEGEND */
      if (key.length > 0) {
        var legend = svg.append("g")
          .attr("class", "chart-legend")
          .attr("transform", "translate(0, 35)");

        var keys = legend.selectAll("g")
          .data(key)
          .enter().append("g")
          .attr("transform", function (d, i) {
            var size = textSize(d, '12px', "\"Source Sans Pro\", Verdana, sans-serif");

            return "translate(" + (((i + 1) * 70) + size.width) + ", " + chart.h + ")"
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
            return d3.splitString(key[i], 15);
          })
          .enter().append("text")
          .text(function (d, i) {
            return d
          })
          .attr("x", 20)
          .attr("y", function (d, i) {
            return i * 15
          })
          .attr("dy", "1em")
          .attr("font-size", "12px")
          .attr("font-family", "\"Source Sans Pro\", Verdana, sans-serif");
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
