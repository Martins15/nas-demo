Nav = {};
var Nas = Nas || {};

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
      });
    }
  };

  Drupal.behaviors.magIssueFeatured = {
    attach: function (context, settings) {
      $(window).bind('load resize', function() {
        var magIssueCoverHeight = $(".node-type-magazine-issue .sidebar-section.editorial-card-photo img").height();
        var magIssueEdBlockHeight = $(".node-type-magazine-issue .editorial-card.collapse-minimal:eq(0)").height();
        if (magIssueEdBlockHeight !== 0 && magIssueEdBlockHeight < magIssueCoverHeight) {
          $(".node-type-magazine-issue .editorial-card.collapse-minimal").css("min-height", magIssueCoverHeight);
        }
      });
    }
  };

  Drupal.behaviors.articleFullscreen = {
    attach: function (context, settings) {
      if ($(".bean-welcome-to-audubon").length > 0) {
        var hide = false,
            _time = (new Date).getTime();
        var firsttimecookievalue = parseInt($.cookie('firsttimevisitors'));
        if (firsttimecookievalue) {
          if (_time - firsttimecookievalue < 15 * 60 * 1000) {
            $.cookie('firsttimevisitors', _time, { expires: 365, path: '/' });
          }
          else {
            hide = true;
          }
        } else {
          $.cookie('firsttimevisitors', _time, { expires: 365, path: '/' });
        }
        if (hide) {
          $(".bean-welcome-to-audubon .article-aside").addClass('hidden');
        }
      }
    }
  };

  Drupal.behaviors.bird_in_this_story_see_all = {
    attach: function (context, settings) {
      $('.article-related-birds', context).once('article-related-birds', function () {
        var $this = $(this);
        $('.bits-see-all-controller', $this).click(function () {
          $('.bits-see-all-hide', $this).hide();
          $('.bits-see-all-show', $this).show();
          return false;
        });
      });
    }
  };

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
    $(".primary-nav-toggler").bind("touchend", function (e) {
      var $this = $(this);

      if (!$this.hasClass("open")) {
        markLinkTouched($this, 500);
        Nav._toggleEffect($this);
      }
    });

    $(".primary-nav-toggler").bind("click", function (e) {
      if (!$(this).hasClass("open") || $(this).data("touched")) {
          e.preventDefault();
      }
    });

    Nav._bindSearch();

    function markLinkTouched($link, timeout) {
      $link.data("touched", 1);
      setTimeout(function(){
        $link.removeData("touched");
      }, timeout);
    }
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