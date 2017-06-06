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
  <script async custom-element="amp-accordion" src="https://cdn.ampproject.org/v0/amp-accordion-0.1.js"></script>
  <script async custom-element="amp-fit-text" src="https://cdn.ampproject.org/v0/amp-fit-text-0.1.js"></script>
  <script async custom-element="amp-sidebar" src="https://cdn.ampproject.org/v0/amp-sidebar-0.1.js"></script>
  <link href="https://fonts.googleapis.com/css?family=Merriweather:400,400italic,700,700italic|Roboto:400,700|Roboto+Slab:700" rel="stylesheet" type="text/css">
</head>

<body class="<?php print $classes; ?>" <?php print $attributes;?>>

<main class="hg-article-container" role="main">
  <header>
    <div class="hg-brand-header">
      <a href="http://www.audubon.org">
        <amp-img alt="www.audubon.org" src="data:image/png;base64,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"
                 class="hg-brand-header-logo i-amphtml-element i-amphtml-layout-fixed i-amphtml-layout-size-defined i-amphtml-layout"
                 width="26" height="26" layout="fixed" style="width: 26px; height: 26px;">
          <noscript>
            <img alt="www.audubon.org" class="i-amphtml-fill-content i-amphtml-replaced-content" src="data:image/png;base64,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">
          </noscript>
        </amp-img>
        <div class="hg-brand-header-name">Audubon</div>
      </a>
    </div>
  </header>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</main>
</body>
</html>
