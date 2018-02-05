<?php

/**
 * @file
 * Theme override for the basic structure of a single Drupal page.
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
 * - $amp-skip_link: Markup for skip link.
 *
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<!doctype html>
<html amp lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">

<head>
  <meta charset="utf-8">
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php include $nas_amp_path_file . '/templates/amp-css/amp-boilerplate-styles.inc' ?>
  <style amp-custom>
    <?php include $nas_amp_path_file . '/css/nas-amp-custom-style.css' ?>
  </style>
  <script async src="https://cdn.ampproject.org/v0.js"></script>
  <link href="https://fonts.googleapis.com/css?family=Source+Sans+Pro:300,400,600|Noto+Serif:400,700,400italic|Roboto:400,700" rel="stylesheet" type="text/css">
</head>

<body class="<?php print $classes; ?>" <?php print $attributes;?>>

<main class="hg-article-container" role="main">
  <header>
    <div class="hg-brand-header">
      <a href="http://www.audubon.org" class="logo_main">
        <amp-img alt="www.audubon.org" src="data:image/png;base64,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"
                 width="92" height="21" layout="fixed" style="width: 92px; height: 21px;">
          <noscript>
            <img alt="www.audubon.org" src="data:image/png;base64,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">
          </noscript>
        </amp-img>
      </a>
      <a href="https://action.audubon.org/donate/now" class="action-nav-link button small tomato now">Donate Now</a>
      <a href="/takeaction" class="action-nav-link button small tomato">Take Action</a>
    </div>
  </header>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</main>
</body>
</html>
