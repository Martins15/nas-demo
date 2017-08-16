(function($) {

  // Change hash on scroll.
  $(window).on('scroll',function(e){
    $('.video-page-section').each(function(){
      if (
          $(this).offset().top < window.pageYOffset + 10

          && $(this).offset().top + $(this).height() > window.pageYOffset + 10
      ) {
        //window.location.hash = $(this).attr('id');
      }
    });
  });

  $(window).on('load', function() {

    // Init thumbnail preview.
    $('.thumbnail-container ul').owlCarousel({
      margin:10,
      loop:true,
      items: 3,
      navigation: true
    });


    // Thumbnail auto play
    var thumbnailVideo = $('.thumbnail-video');
    thumbnailVideo.on('mouseenter', function(){
      if( this.paused) this.play();
    }).on('mouseleave', function(){
      if( !this.paused) this.pause();
    });



    // Add fixed class for dot navigation.
    var stickyHeaderTop = $('.js-dot-navigation').offset().top;
    var $dotLink = $('a', stickyHeaderTop);
    var fixedclass = 'is-fixed';
    $(window).scroll(function(){
      if( $(window).scrollTop() > stickyHeaderTop-85 ) {
        $('.js-dot-navigation').addClass(fixedclass);
      } else {
        $('.js-dot-navigation').removeClass(fixedclass);
      }
    });


    // Animated anchor link scroll.
    var activeDotClass = 'active';
    $('a[href^="#"]').on('click',function (e) {
      e.preventDefault();

      $('a[href^="#"]').removeClass(activeDotClass);

      $(this).addClass(activeDotClass);

      var target = this.hash;
      var $target = $(target);

      $('html, body').stop().animate({
        'scrollTop': $target.offset().top
      }, 900, 'swing', function () {
        window.location.hash = target;
      });
    });




  })


})(jQuery);

