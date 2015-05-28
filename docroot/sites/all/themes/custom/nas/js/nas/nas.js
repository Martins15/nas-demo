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

  Drupal.behaviors.videoCurtainController = {
    attach: function(context, settings) {
      $('.curtain-video video').once('curtain-video-controller', function () {
        if (navigator && navigator.userAgent && navigator.userAgent !== null) {
          var strUserAgent = navigator.userAgent.toLowerCase();
          var arrMatches = strUserAgent.match(/(iphone|ipod|ipad)/);
          if (arrMatches !== null) {
            $('body').addClass('force-curtain-fallback');
          }
        }

        var $video = $(this), video = this;
        $video.hide();
        $video
          .bind('play', function () {
            $video.fadeIn('slow');
            $('.curtain-video-load-indicator').fadeOut('slow');
          });
      });
    }
  };

  Drupal.behaviors.videoCurtainSizing = {
    attach: function(context, settings) {
      $('.curtain-video.center video, .curtain-video.cover video').once('video-curtain-sizing', function () {
        var $video = $(this);

        this.onloadedmetadata = function (e) {
          var width = $video.width();
          var height = $video.height();
          $video.css({
            marginLeft: -width / 2,
            marginTop: -height / 2
          });
          if ($video.parent().hasClass('cover')) {
            $(window).bind('resize', function () {
              var width = $video.width();
              var height = $video.height();
              $video.css({
                marginLeft: -width / 2,
                marginTop: -height / 2
              });
            });
          }
        };
      });
    }
  };

  Drupal.isFirstTimeVisitor = function () {
    var firsttimecookievalue = parseInt($.cookie('firsttimevisitors'));
    if (firsttimecookievalue) {
      return false;
    }
    var _time = (new Date()).getTime();
    $.cookie('firsttimevisitors', _time, { expires: 365, path: '/' });
    return true;
  };

  Drupal.behaviors.firstTimeVisitors = {
    attach: function (context, settings) {
      if (!Drupal.isFirstTimeVisitor()) {
        $(".bean-welcome-to-audubon").addClass('hide');
        $('.hide-for-firsttime-visitors').removeClass('hide-for-firsttime-visitors');
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
  // @todo Figure out how to fix urls replacement, disable for now.
  /*  Drupal.behaviors.nasSearchPage = {
  attach: function (context, settings) {
  $('.page-search-results .node').each(function() {
  var src_str = $(this).html();
  var term = $("#nas-search-page-search-form .form-search").val();
  term = term.replace(/(\s+)/,"(<[^>]+>)*$1(<[^>]+>)*");
  var pattern = new RegExp("("+term+")", "gi");
  src_str = src_str.replace(pattern, "<mark>$1</mark>");
  src_str = src_str.replace(/(<mark>[^<>]*)((<[^>]+>)+)([^<>]*<\/mark>)/,"$1</mark>$2<mark>$4");
  $(this).html(src_str);
});
}
};*/

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

  Drupal.behaviors.viewLoadMoreGroupHandler = {
    attach: function (context, settings) {
      $('.view-display-id-boa_listing').once('views-load-more-group-handler', function () {
        $(this).bind('views_load_more.new_content', function (event, new_content) {
          var classes = new_content.className.split(' ');
          var view_dom_id = '';

          // Look up view-dom-id-# class.
          for (var i in classes) {
            var classname = classes[i];
            if (classname.match(/view-dom-id-.*/)) {
  view_dom_id = classname;
  break;
            }
          }
          // Regroup if found.
          if (view_dom_id) {
            var prev_title = '',
            prev_row = false;
            $('.' + view_dom_id).find('.views-row-odd, .views-row-even').each(function () {
              var current_title = $(this).find('.boa-family-set-title').text();
              if (prev_row && current_title == prev_title) {
                $(this).find('.boa-bird-card-container > *').appendTo(prev_row.find('.boa-bird-card-container'));
                $(this).remove();
              }
              else {
                prev_row = $(this);
                prev_title = current_title;
              }
            });
          }
        });
      });
    }
  };

  // Additional behaviour for bird guide page.
  Drupal.behaviors.colorbox_resize = {
    attach: function (context, settings) {
      $(window).on('resize', function(){
        var $colorbox_instance = $('.node-type-bird #colorbox');
        if (typeof $.colorbox != "undefined" && typeof $colorbox_instance != "undefined") {
          var offset = $colorbox_instance.offset();
          if (offset !== null && typeof offset.left != "undefined") {
            var colorbox_offset = ($(window).width() - (offset.left + $colorbox_instance.outerWidth()));
            // Resize colorbox when it overlapped.
            if (colorbox_offset < 0) {
              $.colorbox.resize({
                width: Drupal.settings.colorbox.initialWidth
              });
              $colorbox_instance.find('.cboxPhoto').css({
                width: '100%',
                height: '100%'
              });
            }
          }
        }
      });
    }
  };

  Drupal.behaviors.boaPlateViewLoadMore = {
    attach: function (context, settings) {
      var boa_plates_wrapper = $('.boa-plate-view-wrapper');
      $('.view-nas-bird-guide .pager-load-more a.load-more', boa_plates_wrapper).once('views-load-more-boa-plate-handler').click(function() {
        $('.icon-binoculars', boa_plates_wrapper).hide();
      });
    }
  };

  Drupal.behaviors.preventBouncing = {
    attach: function (context, settings) {
      $('.aid-filter .toggler').bind('click touchend', function (e) {
        e.preventDefault();
        var $this = $(this);
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
    }
  };

  Drupal.behaviors.fieldGuide = {
    attach: function (context, settings) {
      if ($('body').hasClass('page-field-guide')) {
        $.ajaxPrefilter(function( options, originalOptions, jqXHR ) {
          if (options.url.match("\/views\/ajax")) {
            options.url = options.url.replace(/\/views\/ajax\?page=\d&?/g, '/views/ajax?');
          }
        });
        $(document).ajaxComplete(function(event, xhr, settings) {
          var updated_url = '';
          // change the URL after a new content is loaded.
          if (settings.url.match("\/field-guide\\?page=")) {
            updated_url = settings.url;
          }
          if (settings.url.match("\/views\/ajax")) {
            var data = settings.data.split('&').slice(0, 3).join('&');
            updated_url = window.location.pathname + '?' + data;
          }
          if (updated_url !== '') {
            window.history.replaceState('', '', updated_url);
          }
        });
        // Additionatly change page number after bird is clicked.
        $('.bird-card a').bind('click touchend', function (e) {
          var id = parseInt($(this).parents('.views-row').attr('class').split(' ')[0].replace('page-', '')),
          page_numb_replace = 'page=' + id,
          page_regexp_replace = /page=\d+/g;
          if (id === 0) {
            page_numb_replace = '';
            page_regexp_replace = /page=\d+&?/g;
          }
          var updated_url = window.location.pathname + window.location.search.replace(page_regexp_replace, page_numb_replace);
          window.history.replaceState('', '', updated_url);
        });
      }
    }
  };

  Drupal.behaviors.NewsPage = {
    attach: function (context, settings) {
      if ($('body').hasClass('page-news') || ($('body').hasClass('page-taxonomy-term-tags'))) {
        $(document).ajaxComplete(function(event, xhr, settings) {
          var updated_url = '';
          // change the URL after a new content is loaded.
          if (settings.url.match("\\?page=")) {
            updated_url = settings.url;
          }
          if (updated_url !== '') {
            window.history.replaceState('', '', updated_url);
          }
        });
        // Additionatly change page number after links is clicked.
        $('.view-nas-news a').bind('click touchend', function (e) {
          var id = parseInt($(this).parents('.views-row').attr('class').split(' ')[0].replace('page-', '')),
              page_numb_replace = 'page=' + id,
              page_regexp_replace = /page=\d+/g;
          if (id === 0) {
            page_numb_replace = '';
            page_regexp_replace = /page=\d+&?/g;
          }
          var updated_url = window.location.pathname + window.location.search.replace(page_regexp_replace, page_numb_replace);
          window.history.replaceState('', '', updated_url);
        });
      }
    }
  };

  Drupal.behaviors.noImage = {
    attach: function (context, settings) {

      $(window).on("load resize",function(e){
        titlePosition();
      });

      function titlePosition(){
        if ($(".view-display-id-articles_term_10 .tiny-8").position() !== null){
          var lleft = $(".view-display-id-articles_term_10 .tiny-8").position().left;
          lleft = parseInt(lleft);
          var pleft = $(".view-display-id-articles_term_10 .tiny-8").css("padding-left").replace(/[^-\d\.]/g, '');
          pleft = parseInt(pleft);
          $(".tiny-12").css({"left":lleft+pleft,"width":"66%"});
        }
      }
    }
  };

  Drupal.behaviors.centerAuthorImage = {
    attach: function (context, settings) {
      articleAuthor = jQuery(".article-sidebar-section.article-meta img");
      if(articleAuthor.length) {
        jQuery(".article-sidebar-section.article-meta").css("text-align","center");
      }
    }
  };

  Drupal.behaviors.search_highlight = {
    attach: function (context, settings) {
      $('.page-search-results').each(function(){
        var query = {},
        queries = window.location.search.substring(1).split('&'),
        qr_length = queries.length,
        highlight = ['.common-name a', '.scientific-name', '.editorial-card-title a', '.editorial-card-content p', '.editorial-card-info a'],
        hl_length = highlight.length,
        i = 0,
        highlight_aplly = function(){
          var sr_length = query.search.length,
          j = 0;
          for (j = 0; j < sr_length; j = j + 1) {
            $(this).highlight(query.search[j], { caseSensitive: false });
          }
        };

        // Retrieving the search words from URL.
        for (i = 0; i < qr_length; i = i + 1) {
          queries[i] = queries[i].split('=');
          if (queries[i][0] == 'search') {
            query[queries[i][0]] = queries[i][1].split('+');
          }
          else {
            query[queries[i][0]] = queries[i][1];
          }
        }
        if ($.isArray(query.search)) {

          // Iterate over all strings container and highlight search words.
          for (i = 0; i < hl_length; i = i + 1) {
            $(highlight[i]).each(highlight_aplly);
          }
        }
        $('.highlight').css('background-color', 'yellow');
        $('.highlight').css('color', 'black');
      });
    }
  };

  Drupal.behaviors.centerAuthorImage = {
    attach: function (context, settings) {
      articleAuthor = jQuery(".article-sidebar-section.article-meta img");
      if(articleAuthor.length) {
        jQuery(".article-sidebar-section.article-meta").css("text-align","center");
      }
    }
  };

  Drupal.behaviors.search_highlight = {
    attach: function (context, settings) {
      $('.page-search-results').each(function(){
        var query = {},
            queries = window.location.search.substring(1).split('&'),
            qr_length = queries.length,
            highlight = ['.common-name a', '.scientific-name', '.editorial-card-title a', '.editorial-card-content p', '.editorial-card-info a'],
            hl_length = highlight.length,
            i = 0,
            highlight_aplly = function(){
              var sr_length = query.search.length,
                  j = 0;
              for (j = 0; j < sr_length; j = j + 1) {
                $(this).highlight(query.search[j], { caseSensitive: false });
              }
            };

        // Retrieving the search words from URL.
        for (i = 0; i < qr_length; i = i + 1) {
          queries[i] = queries[i].split('=');
          if (queries[i][0] == 'search') {
            query[queries[i][0]] = queries[i][1].split('+');
          }
          else {
            query[queries[i][0]] = queries[i][1];
		  }
        }
        if ($.isArray(query.search)) {

          // Iterate over all strings container and highlight search words.
          for (i = 0; i < hl_length; i = i + 1) {
            $(highlight[i]).each(highlight_aplly);
          }
        }
        $('.highlight').css('background-color', 'yellow');
        $('.highlight').css('color', 'black');
      });
    }
  };

  Drupal.behaviors.iframe_map = {
  attach: function (context,settings){
    var map = $("#map-canvas iframe");
      parent_h = map.parent().height();
      map_h = map.height();
        if(parent_h < map_h){
          map.parent().height(map_h);
        }
        else{
          map.height(parent_h);
        }
    }
  };

})(jQuery);
