(function ($) {
  Drupal.behaviors.heroVideo = {
    attach: function (context, settings) {
      setVideoHeight();
      $(window).resize(function () {
        setTimeout(function () {
          setVideoHeight();
        }, 500);
      });
    }
  };

  function setVideoHeight() {
    var h = (window.innerWidth > 767) ? window.innerHeight - 32 + 'px' : '56.25%';
    $('.hero-video-wrapper').css({'padding-top': h});
  }
})(jQuery);
