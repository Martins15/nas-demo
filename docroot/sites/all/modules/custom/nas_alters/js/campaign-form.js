/**
 * @file
 * Javascript refinements for the Campaign node form.
 */

(function ($) {
  Drupal.behaviors.campaignForm = {
    attach: function (context, settings) {
      if ($('body').hasClass('page-node-edit') && $('body').hasClass('node-type-campaign')) {

        campaignFormTransliterate = function (source, settings) {
          var rx = new RegExp(settings.replace_pattern, 'g');
          return source.toLowerCase().replace(rx, settings.replace).substr(0, settings.maxlength);
        };

        $('#edit-title-machine-name-suffix').append('<span class="generate-url-parameter admin-link"><a href="#">Generate</a></span>');

        $('.generate-url-parameter').click(function(e) {
          e.preventDefault();
   
        $.each(settings.machineName, function (source_id, options) {
          var $source = $(source_id, context).addClass('machine-name-source'),
              $target = $(options.target, context).addClass('machine-name-target'),
              $suffix = $(options.suffix, context),
              $wrapper = $target.closest('.form-item'),
              machine = campaignFormTransliterate($source.val(), options);
            // Set the machine name to the transliterated value.
            if (machine !== '') {
              if (machine != options.replace) {
                $target.val(machine);
                $('.machine-name-value').html(options.field_prefix + Drupal.checkPlain(machine) + options.field_suffix);
              }
              $suffix.show();
            }
          });
        });
      }
    }
  };
})(jQuery);
