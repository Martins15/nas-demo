(function ($) {
  Drupal.behaviors.nasMenu = {
    attach: function (context, settings) {
      $(document).bind("respond", function (e) {
        Nav.unbind();

        if (e.size == "tiny" || e.size == "small" || e.size == "medium") {
          Nav.reset();
          Nav.bindMobile();
        }
        if (e.size == "large") {
          Nav.reset();
          if (StateManager.touch) {
            Nav.bindTablet();
          }
          else {
            Nav.bindDesktop();
          }
        }
      });
    }
  };
  
  Drupal.behaviors.nasBirdGuide = {
    attach: function (context, settings) {
      $(".bird-guide-search select").once().change(function (e) {
        var $container = $(".bird-card-grid-container");
        $container.find(".bird-card").addClass("disappear");
        $(".bird-card.disappear").bind("animationend webkitAnimationEnd oanimationend MSAnimationEnd", function () {
          $(this).addClass("invisible");
        });
//        $(".bird-card-grid .section-header h2").text("Matching Birds");
      });
    }
  };
  
})(jQuery);

Nav = {};

(function ($) {
// @todo Figure out how this is going to work on touch

  Nav.handleTouch = function () {
    $(".primary-nav-toggler").removeAttr("href");
  };

  Nav.bindMobile = function () {
    var onTrigger = StateManager.touch ? "touchend" : "click";

    function bindHeaderButton(btn, icon, widget) {
      $(btn).bind(onTrigger, function () {
        var $this = $(this);

        if ($this.hasClass("icon-close")) {
          Nav.reset();
        }
        else {
          Nav.reset();
          $this.addClass("icon-close");
          $(widget).addClass("show");
        }
      });
    }

    $(".primary-nav-toggler").bind(onTrigger, function (e) {
      var $this = $(this);

      e.preventDefault();
      $(".primary-nav-toggler").not($this).removeClass("open");
      $(".primary-sub-nav").not($this.next(".primary-sub-nav")).removeClass("show");

      $this.toggleClass("open");
      $this.next(".primary-sub-nav").toggleClass("show");

      setTimeout(function () { // this is just a "next tick"
        if (window.scrollY > $this.offset().top) {
          window.scrollTo(0, $this.offset().top);
        }
      }, 0);
    });

    bindHeaderButton(".header-btn-menu", "icon-menu", ".mobile-nav");
    bindHeaderButton(".header-btn-search", "icon-magnifier", ".header-search");
  };

// @todo Refactor desktop and tablet; this is ridiculous

  Nav.bindDesktop = function () {
    $(".primary-nav-toggler").bind("mouseover", function () {
      var $this = $(this);

      Nav._toggleEffect($this);

      $this.parent().one("mouseleave", function () {
        Nav.reset();
      });
    });

    Nav._bindSearch();
  };

  Nav.bindTablet = function () {
    $(".primary-nav-toggler").bind("touchend", function () {
      var $this = $(this);

      Nav._toggleEffect($this);

      $this.one("touchend", function () {
        Nav.reset();
        Nav.bindTablet();
      });
    });

    Nav._bindSearch();
  };

  Nav._toggleEffect = function ($this) {
    $(".primary-nav-toggler").not($this).removeClass("open");
    $(".primary-sub-nav").not($this.next(".primary-sub-nav")).removeClass("show");

    $this.addClass("open");
    $this.next(".primary-sub-nav").addClass("show");
  };

  Nav._bindSearch = function () {
    $(".primary-nav-search").bind("click", function () {
      $(".header-search").addClass("show");
      $(".global-nav").addClass("hide");
      return false;
    });

    $(".header-search-close").bind("click", function () {
      $(".header-search").removeClass("show");
      $(".global-nav").removeClass("hide");
      return false;
    });
  };

  Nav.unbind = function () {
    $(".header-btn").unbind();
    $(".primary-nav-toggler").unbind();
    $(".primary-nav-toggler").parent().unbind();
  };

  Nav.reset = function () {
    $(".header-btn").removeClass("icon-close");
    $(".mobile-nav").removeClass("show");
    $(".primary-nav-toggler").removeClass("open");
    $(".primary-sub-nav").removeClass("show");
    $(".header-search").removeClass("show");
    $(".global-nav").removeClass("hide");
  };

  if (StateManager.touch) {
    Nav.handleTouch();
  }
})(jQuery);