// See: http://bost.ocks.org/mike/chart/ "Towards Reusable Charts"
// And: http://bost.ocks.org/mike/chart/time-series-chart.js
function vennOverVenn() {
  var seasons = ['BBS','CBC'],
      seasonname = { 'BBS': 'summer', 'CBC': 'winter' },
      leftBuffer = 10,
      height = 60,
      circleRadius = 20;  // For the default (year 2000) ranges

  function chart(selection) {
    selection.each(function(data) {

      // Select the div element, if it exists.
      var div = d3.select(this).selectAll("div").data([data]);

      // Otherwise, create the skeletal chart.
      var divEnter = div.enter().append("div")
          .classed("nongeodiv", true);

      var divViz = divEnter.append("div");

      seasons.filter(function(season) { return data[season+'_range_relative']; }).forEach(function(season) {
        var div = divViz.append("div")
          .classed("focal-bird-venn venndiv medium-6 columns", true);

        var svg = div.append("svg")
          .attr("width", "100%")
          .attr("height", "100%");

        var height = 60,
            width = 200;

        //console.log(leftBuffer);

        var r1 = circleRadius;
        var r2 = Math.sqrt(data[season+"_range_relative"])*circleRadius;
        var overlapArea = Math.PI*circleRadius*circleRadius*data[season+"_range_left"];
        var distanceBetweenCenters = venn.distanceFromIntersectArea(r1,r2,overlapArea);
        var vennWidth = r1+r2+distanceBetweenCenters;
        var remainingSpace = (width-vennWidth)/2
        var x1 = remainingSpace+r1;
        var x2 = x1+distanceBetweenCenters;
        if (remainingSpace < leftBuffer) {
          // But if they are big enough to overflow, left align the circles against the buffer
          x1 = leftBuffer;
          x2 = leftBuffer+distanceBetweenCenters;
        }

        svg.append("circle")
          .attr("cx", x1)
          .attr("cy", height/2)
          .attr("r", r1)
          .classed("venn", true)
          .classed("venn" + seasonname[season], true);
        svg.append("circle")
          .attr("cx", x2)
          .attr("cy", height/2)
          .attr("r", r2)
          .classed("venn", true)
          .classed("venn" + seasonname[season], true)
          .classed("vennfuture", true);

        div.append("div") // Just for the label
          .classed("vennlabel", true)
          .html(function(d) {
            if (d[season+'_range_relative']) {
              var change = d3.round(100 * d[season+'_range_relative']);
              var stability = d3.round(100 * d[season+'_range_left']);
              var html = "<p class='venndata'>" + stability + "% of " + seasonname[season] + " 2000 range is stable";
              if (change <= 100) {
                html += "<p class='venndata'>" + (100-change) + "% decrease in " + seasonname[season] + " 2080 from 2000 range";
              } else {
                html += "<p class='venndata'>" + (change-100) + "% increase in " + seasonname[season] + " 2080 from 2000 range";
              }
            } else {
              var html = "";
            }
            return html;
          });
      });

    });
  }

  chart.leftBuffer = function(_) {
    if (!arguments.length) return leftBuffer;
    leftBuffer = _;
    return chart;
  };

  chart.width = function(_) {
    if (!arguments.length) return width;
    width = _;
    return chart;
  };

  chart.height = function(_) {
    if (!arguments.length) return height;
    height = _;
    return chart;
  };

  chart.radius = function(_) {
    if (!arguments.length) return circleRadius;
    circleRadius = _;
    return chart;
  };

  return chart;
}