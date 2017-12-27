/**
 * @file
 * D3 Bar Graph library js file.
 */

(function ($) {

  Drupal.d3.ct_bar = function (select, settings) {

    function drawData(select, settings) {
      settings.id = settings.id || select;

      var key = [],
          range = settings.barColor || ["blue", "red", "orange", "green"];
      if (typeof settings.legend != 'undefined') {
        key = settings.legend;
      }


      var rows = settings.rows,
          // Use first value in each row as the label.
          xLabels = rows.map(function (d) {
            return d.shift();
          })

      // From inside out:
      // - Convert all values to numeric numbers.
      // - Merge all sub-arrays into one flat array.
      // - Return the highest (numeric) value from flat array.
      max = d3.max(d3.merge(settings.rows).map(function (d) {
        return +d;
      })),
          // Padding is top, right, bottom, left as in css padding.
          p = [20, 50, 30, 50],
          w = settings.width || 800,
          h = settings.height || 400,
          // chart is 65% and 80% of overall height
          //chart = {w: w * .65, h: h * .80},
          chart = {w: w, h: h * .80},
          legend = {w: w * .35, h: h},
          // bar width is calculated based on chart width, and amount of data
          // items - will resize if there is more or less
          // space in between each set
          x = d3.scale.linear().domain([0, rows.length]).range([0, chart.w]),
          y = d3.scale.linear().domain([0, max]).range([chart.h, 0]),
          z = d3.scale.ordinal().range(range),
          div = (settings.id) ? settings.id : 'visualization';


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
          .attr("font-size", "11px")
          .attr("font-family", "\"Source Sans Pro\", Verdana, sans-serif")
          .attr("dy", function (d, i) {
            return ".75em";
          })
          .attr("text-anchor", "middle")
          .text(function (d, i) {
            return xLabels[i];
          })
          .call(wrap, barGroupWidth + barSpacing);

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
            .attr("x", -15)
            .attr("dy", ".35em")
            .attr("text-anchor", "end")
            .text(d3.format(",d"));
      }

      var bar = graph.selectAll('g.bars')
          .data(rows)
          .enter().append('g')
          .attr('class', 'bargroup')
          .attr('transform', function (d, i) {
            return "translate(" + (x(i)) + ", 0)";
          });

      // bar.selectAll('rect')
      //     .data(function (d) {
      //       return d;
      //     })
      //     .enter().append('rect')
      //     .attr("width", barWidth)
      //     .attr("height", function (d) {
      //       return chart.h - y(d);
      //     })
      //     .attr("rx", barRx)
      //     // .attr('x', function (d, i) {
      //     //   return x(i);
      //     // })
      //     .attr('y', function (d, i) {
      //       return y(d);
      //     })
      //     .attr('fill', function (d, i) {
      //       return d3.rgb(z(i));
      //     })
      //     .on('mouseover', function (d, i) {
      //       showToolTip(d, i, this);
      //     })
      //     .on('mouseout', function (d, i) {
      //       hideToolTip(d, i, this);
      //     });

      bar.selectAll('rect')
          .data(function (d) {
            return d;
          })
          .enter().append('rect')
          .attr("width", barWidth)
          .attr("height", 0)
          .attr("rx", barRx)
          .attr('y', function (d, i) {
            return y(d) + (chart.h - y(d));
          })
          .attr('fill', function (d, i) {
            return d3.rgb(z(i));
          }).on('mouseover', function (d, i) {
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

      graph.selectAll("text.bar")
          .data(rows)
          .enter().append("text")
          .attr("class", "bar")
          .style('fill', function (d, i) {
            return d3.rgb(z(i));
          })
          .attr("text-anchor", "middle")
          .attr("x", function (d, i) {
            return x(i) + 5;
          })
          .attr("y", function (d) {
            return y(d[0]) - 5;
          })
          .text(function (d) {
            return d[0];
          });


      /* LEGEND */

      if (key.length > 0) {
        var legend = svg.append("g")
            .attr("class", "legend")
            .attr("transform", "translate(" + (chart.w + 20) + "," + 0 + ")");

        var keys = legend.selectAll("g")
            .data(key)
            .enter().append("g")
            .attr("transform", function (d, i) {
              return "translate(0," + d3.tileText(d, 15) + ")"
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
              return i * 20
            })
            .attr("dy", "1em");
      }


      function showToolTip(d, i, obj) {
        // Change color and style of the bar.
        var bar = d3.select(obj);
        bar.attr('stroke', '#ccc')
            .attr('stroke-width', '1')
            .attr('opacity', '0.75');

        // var group = d3.select(obj.parentNode);
        //
        // var tooltip = graph.append('g')
        //     .attr('class', 'tooltip')
        //     // move to the x position of the parent group
        //     .attr('transform', function (data) {
        //       return group.attr('transform');
        //     })
        //     .append('g')
        //     // now move to the actual x and y of the bar within that group
        //     .attr('transform', function (data) {
        //       return 'translate(' + (Number(bar.attr('x')) + barWidth) + ','
        // + y(d) + ')'; });  d3.tooltip(tooltip, d);
      }

      function hideToolTip(d, i, obj) {
        var group = d3.select(obj.parentNode);
        var bar = d3.select(obj);
        bar.attr('stroke-width', '0')
            .attr('opacity', 1);

        //graph.select('g.tooltip').remove();
      }

      function wrap(text, width) {
        text.each(function () {
          var text = d3.select(this),
              words = text.text().split(/\s+/).reverse(),
              word,
              line = [],
              lineNumber = 0,
              lineHeight = 0.1, // ems
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
              tspan = text.append("tspan").attr("x", 0).attr("y", y).attr("dy", ++lineNumber * lineHeight + dy + "em").text(word);
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
