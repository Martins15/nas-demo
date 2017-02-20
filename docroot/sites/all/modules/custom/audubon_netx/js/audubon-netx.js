(function ($) {
  Drupal.behaviors.audubon_netx = {
    attach: function (context, settings) {
      $('.audubon-netx-preview .form-item input', context).once('audubon-netx-selected', function () {
        $(this).bind('change', function () {
          $('.audubon-netx-preview tr.netx-selected', context).removeClass('netx-selected');
          $(this).parents('tr').addClass('netx-selected');
        });
      });

      $('div.audubon-netx-preview').once(function () {
        $('#netx-pager-submit').hide();

        var pages = $('.netx-total-pages').val(),
          pager = $('.view-pager');

        if (pages > 1) {
          var $pagerList = $('<ul class="netx-pager"></ul>'),
            $pagerMiddle = Number('4'),
            // Current is the page we are currently paged to.
            $pagerCurrent = Number($('.netx-current-page').val()),
            // First is the first page listed by this pager piece (re quantity).
            $pagerFirst = $pagerCurrent - $pagerMiddle,
            // Last is the last page listed by this pager piece (re quantity).
            $pagerLast = $pagerCurrent + $pagerMiddle,
            // Max is the maximum page number.
            $pagerMax = pages - 1,
            $pagerItem = '';

          // Prepare item offset for generation loop.
          var $item = $pagerFirst;
          // Adjust "center" if at end of query.
          if ($pagerLast > $pagerMax) {
            $item = $item + ($pagerMax - $pagerLast);
            $pagerLast = $pagerMax;
          }
          // Adjust "center" if at start of query.
          if ($item <= 1) {
            $item = 2;
          }
          // Add Previous page link or text.
          if ($pagerCurrent != 1) {
            $pagerItem = $('<li class="netx-pager-item">' +
              '<a href="#" data-page="' + ($pagerCurrent - 1) + '">' + Drupal.t('Previous page') + '</a>' + '</li>');
            $pagerItem.appendTo($pagerList);
          }
          else {
            $pagerItem = $('<li class="netx-pager-item">' +
              '<span>' + Drupal.t('Previous page') + '</span>' + '</li>');
            $pagerItem.appendTo($pagerList);
          }
          // Add first item.
          $pagerItem = $('<li class="netx-pager-item"><a href="#" data-page="1">1</a></li>');
          $pagerItem.appendTo($pagerList);
          if ($item > 2) {
            $pagerItem = $('<li class="netx-pager-item">' + '<span>...</span>' + '</li>');
            $pagerItem.appendTo($pagerList);
          }
          // Generate page list.
          for (var i = $item; i < ($pagerLast + 1); i++) {
            $pagerItem = $('<li class="netx-pager-item">' + '<a href="#" data-page="' + i + '">' + i + '</a>' + '</li>');
            if (i == $pagerCurrent) {
              // Add specific class for current item.
              $pagerItem.addClass('current');
            }
            $pagerItem.appendTo($pagerList);
          }
          if (i < $pagerMax) {
            $pagerItem = $('<li class="netx-pager-item">' + '<span>...</span>' + '</li>');
            $pagerItem.appendTo($pagerList);
          }
          // Add last item.
          $pagerItem = $('<li class="netx-pager-item">' + '<a href="#" data-page="' + ($pagerMax + 1) + '">' + ($pagerMax + 1) + '</a>' + '</li>');
          $pagerItem.appendTo($pagerList);
          // Add Next page link or text.
          if ($pagerCurrent != ($pagerMax + 1)) {
            $pagerItem = $('<li class="netx-pager-item">' + '<a href="#" data-page="' + ($pagerCurrent + 1) + '">' + Drupal.t('Next page') + '</a>' + '</li>');
            $pagerItem.appendTo($pagerList);
          }
          else {
            $pagerItem = $('<li class="netx-pager-item">' + '<span>' + Drupal.t('Next page') + '</span>' + '</li>');
            $pagerItem.appendTo($pagerList);
          }
          $pagerList.appendTo(pager);
        }

        // Clicking on pager links.
        $('.view-pager a').on('click', function (e) {
          e.preventDefault();
          var page = $(this).data('page'),
            progress = $('<div class="ajax-progress ajax-progress-throbber"><div class="throbber">&nbsp;</div><div class="message">Please wait...</div></div>');
          $('input[name="current_page"]').val(page);
          $('#netx-pager-submit').click();
          progress.appendTo(pager);
        });
      });
    }
  };
})(jQuery);
