(function($) {
  Drupal.behaviors.native_plants_share_message = {};
  Drupal.behaviors.native_plants_share_message.attach = function (context, settings) {
    var $socials = $('.native-plants__socials', context),
      $textarea = $socials.find('textarea'),
      $twitter_link = $socials.find('a.social-sharing-icon.twitter'),
      twitter_url = settings.native_plants_share_message.twitter_url
        .replace('share_text_placeholder', $textarea.val());
    $twitter_link.attr('href', twitter_url);

    $textarea.on('change', function() {
      var twitter_url = settings.native_plants_share_message.twitter_url
        .replace('share_text_placeholder', $textarea.val());
      $twitter_link.attr('href', twitter_url);
    });
  };
})(jQuery);
