/**
 * Provides an extention that removes content lock call on unload event.
 */

(function($, window) {
  'use strict';
  jQuery.fn.extend({
    removeUnloadCallback: function (data) {
      // Do not call unlock.
      jQuery().onUserExit({
        execute: function () {
          'use strict';
        },
        executeConfirm: function () {
          'use strict';
        },
        internalURLs: Drupal.settings.content_lock.internal_urls
      });

      window.onunload = function () {
        'use strict';
      };
    }
  });
})(jQuery, window);
