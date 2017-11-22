<?php
/**
 * @file
 * Hero Video pane template.
 */
?>
<video
  class=""
  <?php print !empty($video_settings['loop']) ? $video_settings['loop'] : 'disabled'?>
  <?php print !empty($video_settings['controls']) ? $video_settings['controls'] : 'disabled'?>
  <?php print !empty($video_settings['muted']) ? $video_settings['muted'] : 'disabled'?>
  <?php print !empty($video_settings['playsinline']) ? $video_settings['playsinline'] : 'disabled'?>
  <?php print !empty($video_settings['autoplay']) ? $video_settings['autoplay'] : 'disabled'?>
  poster="<?php print $video_poster; ?>">

  <source src="<?php print $video_url; ?>" type="<?php print $video_type; ?>">
</video>
