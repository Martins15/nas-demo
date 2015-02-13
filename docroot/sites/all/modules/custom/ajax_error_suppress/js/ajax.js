/**
 * @file
 * Drupal core's AJAX error hack for AJAX functionality.
 * The content is based on misc/ajax.js.
 */
(function($) {

  // Standard AJAX error handler.
  /**
   * Handler for the form redirection error.
   */
  Drupal.ajax.prototype.error = function(response, uri) {
    // Suppressing the error message if status = 0.
    if (response.status !== 0) {
      alert(Drupal.ajaxError(response, uri));
    }
    // Remove the progress element.
    if (this.progress.element) {
      $(this.progress.element).remove();
    }
    if (this.progress.object) {
      this.progress.object.stopMonitoring();
    }
    // Undo hide.
    $(this.wrapper).show();
    // Re-enable the element.
    $(this.element).removeClass('progress-disabled').removeAttr('disabled');
    // Reattach behaviors, if they were detached in beforeSerialize().
    if (this.form) {
      var settings = response.settings || this.settings || Drupal.settings;
      Drupal.attachBehaviors(this.form, settings);
    }
  };

})(jQuery);