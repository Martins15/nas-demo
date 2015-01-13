<?php
/**
 * @file
 * nas_boa_family_feature.ctools_content.inc
 */

/**
 * Implements hook_default_ctools_custom_content().
 */
function nas_boa_family_feature_default_ctools_custom_content() {
  $export = array();

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'boa_about_this_guide';
  $content->admin_title = 'About this guide';
  $content->admin_description = '';
  $content->category = 'NAS';
  $content->settings = array(
    'admin_title' => 'About this guide',
    'title' => '',
    'body' => '<div class="row boa-about-this-guide">
	<div class="columns large-12 text-container">
		<h2 class="thin">About This Guide</h2>

		<p>The National Audubon Society would like to thank Richard Buonanno for compiling the content for this online version of John James Audubon\'s <em>Birds of America</em>. It is from an 1840 “First Octavo Edition” of Audubon\'s complete seven volume text, and presents Audubon\'s images and original text descriptions. Bird species can be found listed alphabetically, or categorized by family. Audubon\'s drawings of some species\' anatomical features are also included in the Figures section. The list of species that have gone extinct since Audubon\'s time was provided by Mr. Buonanno, as was the list of State Birds.</p>
	</div>
</div>
',
    'format' => 'full_html',
    'substitute' => 0,
  );
  $export['boa_about_this_guide'] = $content;

  return $export;
}
