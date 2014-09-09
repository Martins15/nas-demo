(function($) {

$(function() {
  $("[data-toggler]").bind("click", function() {
    var $this = $(this),
        selector = $this.attr("data-toggler");

    $this.toggleClass("open");
    $(selector).toggleClass("show");
  });
});

})(jQuery);
