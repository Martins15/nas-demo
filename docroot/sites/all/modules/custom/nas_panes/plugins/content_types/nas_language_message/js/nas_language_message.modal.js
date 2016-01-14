/*global Drupal: false, jQuery: false */
/*jslint devel: true, browser: true, maxerr: 50, indent: 2 */
(function ($) {
  "use strict";

  /**
   * Provide the HTML to create the modal dialog.
   * Clone of function Drupal.theme.prototype.CToolsModalDialog.
   */
  Drupal.theme.prototype.NASLanguageMessageModalDialog = function () {
    var html = '';
    html += '  <div id="ctools-modal">';
    html += '    <div id="nas-language-message-modal">';
    html += '      <div class="ctools-modal-content">';
    html += '        <div id="modal-content" class="modal-content">';
    html += '        </div>';
    html += '      </div>';
    html += '    </div>';
    html += '  </div>';

    return html;
  };

})(jQuery);
