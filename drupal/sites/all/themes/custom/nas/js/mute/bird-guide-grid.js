(function($) {

$(function() {
  $(".bg-egg").bind("click", function(e) {
    e.preventDefault();

    var $this = $(this),
        $parent = $this.parent();

    $this.toggleClass("active").toggleClass("icon-close");
    $parent.toggleClass("show-bg");
  });
});

})(jQuery);
