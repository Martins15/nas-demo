$(function() {
  $(".microsite-cta-form input[type='submit']").bind("click", function(e) {
    e.preventDefault();
    $(".call").fadeOut("fast", function(){
      $(".response").removeClass("off");
    });
  });
  $("#sticky-strip input[type='submit']").bind("click",function(e) {
    e.preventDefault();    
    $(".strip-call").fadeOut("fast", function(){
      $(".strip-response").removeClass("off");
    });
  });
});