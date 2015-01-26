<?php

/**
 * @file
 * Default theme implementation to display the basic html structure of a single
 * Drupal page.
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or 'rtl'.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE
 *   tag.
 * - $head_title_array: (array) An associative array containing the string parts
 *   that were used to generate the $head_title variable, already prepared to be
 *   output as TITLE tag. The key/value pairs may contain one or more of the
 *   following, depending on conditions:
 *   - title: The title of the current page, if any.
 *   - name: The name of the site.
 *   - slogan: The slogan of the site, if any, and if there is no title.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 *
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 *
 * @ingroup themeable
 */
global $base_url;
?><!doctype html>
<html lang="en">
  <head>
  <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=0;" />
  <title><?php print $head_title; ?></title>
  <link href="http://fonts.googleapis.com/css?family=Source+Sans+Pro:300,400,600|Noto+Serif:400,700,400italic" rel="stylesheet" type="text/css">
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <!--[if lt IE 10]>
    <script src="<?php print $base_url . '/' . drupal_get_path('theme', 'nas'); ?>/js/mute/respond.min.js"></script>
    <script src="<?php print $base_url . '/' . drupal_get_path('theme', 'nas'); ?>/js/mute/ie9.js"></script>
  <![endif]-->
  <!--[if lt IE 9]>
    <link rel="stylesheet" href="<?php print $base_url . '/' . drupal_get_path('theme', 'nas'); ?>/css/ie8.css" />
    <script src="<?php print $base_url . '/' . drupal_get_path('theme', 'nas'); ?>/js/mute/ie-carousel.js"></script>
    <script src="<?php print $base_url . '/' . drupal_get_path('theme', 'nas'); ?>/js/mute/custom.modernizr.js"></script>
  <![endif]-->
  <!--[if IE 9]>
    <link rel="stylesheet" href="<?php print $base_url . '/' . drupal_get_path('theme', 'nas'); ?>/css/ie9.css" />
  <![endif]-->
  </head>
  <body class="<?php print $classes; ?>" <?php print $attributes;?>>
    <!-- Google Tag Manager -->
    <noscript><iframe src="//www.googletagmanager.com/ns.html?id=GTM-WWKLTG"
                      height="0" width="0" style="display:none;visibility:hidden"></iframe></noscript>
    <script>(function(w,d,s,l,i){w[l]=w[l]||[];w[l].push({'gtm.start':
        new Date().getTime(),event:'gtm.js'});var f=d.getElementsByTagName(s)[0],
        j=d.createElement(s),dl=l!='dataLayer'?'&l='+l:'';j.async=true;j.src=
        '//www.googletagmanager.com/gtm.js?id='+i+dl;f.parentNode.insertBefore(j,f);
      })(window,document,'script','dataLayer','GTM-WWKLTG');</script>
    <!-- End Google Tag Manager -->
    <?php print $page_top; ?>
    <?php print $page; ?>
    <?php print $page_bottom; ?>
  </body>
</html>
