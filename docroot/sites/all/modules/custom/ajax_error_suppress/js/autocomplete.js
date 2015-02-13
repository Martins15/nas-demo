/**
 * @file
 * Drupal core's AJAX error hack for autocomplete functionality.
 * The content is based on misc/autocomplete.js.
 */
(function($) {

  // Autocomplete AJAX error handler.
  /**
   * Performs a cached and delayed search.
   */
  Drupal.ACDB.prototype.search = function(searchString) {
    var db = this;
    this.searchString = searchString;

    // See if this string needs to be searched for anyway.
    searchString = searchString.replace(/^\s+|\s+$/, '');
    if (searchString.length <= 0 ||
            searchString.charAt(searchString.length - 1) == ',') {
      return;
    }

    // See if this key has been searched for before.
    if (this.cache[searchString]) {
      return this.owner.found(this.cache[searchString]);
    }

    // Initiate delayed search.
    if (this.timer) {
      clearTimeout(this.timer);
    }
    this.timer = setTimeout(function() {
      db.owner.setStatus('begin');

      // Ajax GET request for autocompletion. We use Drupal.encodePath instead of
      // encodeURIComponent to allow autocomplete search terms to contain slashes.
      $.ajax({
        type: 'GET',
        url: db.uri + '/' + Drupal.encodePath(searchString),
        dataType: 'json',
        success: function(matches) {
          if (typeof matches.status == 'undefined' || matches.status !== 0) {
            db.cache[searchString] = matches;
            // Verify if these are still the matches the user wants to see.
            if (db.searchString == searchString) {
              db.owner.found(matches);
            }
            db.owner.setStatus('found');
          }
        },
        error: function(xmlhttp) {
          // Suppressing the error message if status = 0.
          if (xmlhttp.status !== 0) {
            alert(Drupal.ajaxError(xmlhttp, db.uri));
          }
        }
      });
    }, this.delay);
  };

})(jQuery);