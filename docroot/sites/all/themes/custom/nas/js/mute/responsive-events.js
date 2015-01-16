var StateManager = {
  state: "",
  touch: 'ontouchstart' in document.documentElement,

  handleResize: function() {
    var width = jQuery("body").width();

    if (width < 480 && this.state != "tiny") {
      this.state = "tiny";
      var e = jQuery.Event( "respond", { size: this.state } );
      jQuery(document).trigger(e);
    } else if (width > 479 && width < 601 && this.state != "small") {
      this.state = "small";
      var e = jQuery.Event( "respond", { size: this.state } );
      jQuery(document).trigger(e);
    } else if (width > 600 && width < 768 && this.state != "medium") {
      this.state = "medium";
      var e = jQuery.Event( "respond", { size: this.state } );
      jQuery(document).trigger(e);
    } else if (width > 767 && this.state != "large") {
      this.state = "large";
      var e = jQuery.Event( "respond", { size: this.state } );
      jQuery(document).trigger(e);
    }
  },

  init: function() {
    this.handleResize();
    jQuery(window).bind("resize", this.handleResize);
    if(StateManager.touch) {
      console.log("got touch!");
      jQuery("body").addClass("touch");
    }
  }
}

jQuery(function() {
  jQuery(window).load(function() {
    StateManager.init();
  });
});
