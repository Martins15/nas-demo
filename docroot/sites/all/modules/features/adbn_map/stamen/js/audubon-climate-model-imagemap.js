//
// Bound image map.
// Developed by Stamen in July 2014
//
'use strict';

(function(window, $) {

  window.STMN.audubonClimateModel = window.STMN.audubonClimateModel || {};

  function BoundImageMap(map, img) {

    STMN.StamenBase.apply( this, arguments );

    //
    // Inspired (sometimes line by line) from http://stackoverflow.com/a/13322059
    //

    var areas  = $(map).find('area'),
        coords = [],
        self   = this;

    areas.each(function(n, area) {
      coords[n] = area.coords.split(',');
    });

    function resize() {
        var m, clen,
            x = $(img).width() / self.previousWidth;

        areas.each(function(n,area) {
          clen = coords[n].length;
          for (m = 0; m < clen; m++) {
              coords[n][m] *= x;
          }
          areas[n].coords = coords[n].join(',');
        });
        self.previousWidth = $(img).width();

        self.fire('resize');

        return true;
    };

    function updateOriginalSize(callback) {
      var newImg = new Image();

      newImg.onload = function() {
        self.previousWidth = newImg.width;
        callback();
      };

      newImg.src=$(img).attr('src');
    }

    $(window).bind('resize', resize);

    $(map).bind('click', function(e) {
      var region = $(e.target).attr('data-region');

      if (region) {
        self.fire('clickRegion', {
          region : region
        });
      }

    });

    updateOriginalSize(function() {
      resize();
    });

    return this;
  }

  STMN.BoundImageMap = BoundImageMap;

}(window, $));