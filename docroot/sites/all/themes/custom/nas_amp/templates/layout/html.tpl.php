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
  <link href="https://fonts.googleapis.com/css?family=Merriweather:400,400italic,700,700italic|Roboto:400,700|Roboto+Slab:700" rel="stylesheet" type="text/css">
</head>

<body class="<?php print $classes; ?>" <?php print $attributes;?>>

<main class="hg-article-container" role="main">
  <header>
    <div class="hg-brand-header">
      <a href="http://www.audubon.org">
        <amp-img alt="www.audubon.org" src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADwAAAA8CAYAAAA6/NlyAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAyJpVFh0WE1MOmNvbS5hZG9iZS54bXAAAAAAADw/eHBhY2tldCBiZWdpbj0i77u/IiBpZD0iVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkIj8+IDx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuMy1jMDExIDY2LjE0NTY2MSwgMjAxMi8wMi8wNi0xNDo1NjoyNyAgICAgICAgIj4gPHJkZjpSREYgeG1sbnM6cmRmPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4gPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIgeG1sbnM6eG1wPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvIiB4bWxuczp4bXBNTT0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL21tLyIgeG1sbnM6c3RSZWY9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9zVHlwZS9SZXNvdXJjZVJlZiMiIHhtcDpDcmVhdG9yVG9vbD0iQWRvYmUgUGhvdG9zaG9wIENTNiAoV2luZG93cykiIHhtcE1NOkluc3RhbmNlSUQ9InhtcC5paWQ6N0Q4RTI3MTdEMDNDMTFFNzkzMDRFRTQ0REY4QTNGMTUiIHhtcE1NOkRvY3VtZW50SUQ9InhtcC5kaWQ6N0Q4RTI3MThEMDNDMTFFNzkzMDRFRTQ0REY4QTNGMTUiPiA8eG1wTU06RGVyaXZlZEZyb20gc3RSZWY6aW5zdGFuY2VJRD0ieG1wLmlpZDo3RDhFMjcxNUQwM0MxMUU3OTMwNEVFNDRERjhBM0YxNSIgc3RSZWY6ZG9jdW1lbnRJRD0ieG1wLmRpZDo3RDhFMjcxNkQwM0MxMUU3OTMwNEVFNDRERjhBM0YxNSIvPiA8L3JkZjpEZXNjcmlwdGlvbj4gPC9yZGY6UkRGPiA8L3g6eG1wbWV0YT4gPD94cGFja2V0IGVuZD0iciI/Po3M52MAAAd7SURBVHja7JoJbFRV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"
                 width="26" height="26" layout="fixed" style="width: 26px; height: 26px;">
          <noscript>
            <img alt="www.audubon.org" src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADwAAAA8CAYAAAA6/NlyAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAyJpVFh0WE1MOmNvbS5hZG9iZS54bXAAAAAAADw/eHBhY2tldCBiZWdpbj0i77u/IiBpZD0iVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkIj8+IDx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuMy1jMDExIDY2LjE0NTY2MSwgMjAxMi8wMi8wNi0xNDo1NjoyNyAgICAgICAgIj4gPHJkZjpSREYgeG1sbnM6cmRmPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4gPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIgeG1sbnM6eG1wPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvIiB4bWxuczp4bXBNTT0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL21tLyIgeG1sbnM6c3RSZWY9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9zVHlwZS9SZXNvdXJjZVJlZiMiIHhtcDpDcmVhdG9yVG9vbD0iQWRvYmUgUGhvdG9zaG9wIENTNiAoV2luZG93cykiIHhtcE1NOkluc3RhbmNlSUQ9InhtcC5paWQ6N0Q4RTI3MTdEMDNDMTFFNzkzMDRFRTQ0REY4QTNGMTUiIHhtcE1NOkRvY3VtZW50SUQ9InhtcC5kaWQ6N0Q4RTI3MThEMDNDMTFFNzkzMDRFRTQ0REY4QTNGMTUiPiA8eG1wTU06RGVyaXZlZEZyb20gc3RSZWY6aW5zdGFuY2VJRD0ieG1wLmlpZDo3RDhFMjcxNUQwM0MxMUU3OTMwNEVFNDRERjhBM0YxNSIgc3RSZWY6ZG9jdW1lbnRJRD0ieG1wLmRpZDo3RDhFMjcxNkQwM0MxMUU3OTMwNEVFNDRERjhBM0YxNSIvPiA8L3JkZjpEZXNjcmlwdGlvbj4gPC9yZGY6UkRGPiA8L3g6eG1wbWV0YT4gPD94cGFja2V0IGVuZD0iciI/Po3M52MAAAd7SURBVHja7JoJbFRV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">
          </noscript>
        </amp-img>
        <span class="hg-brand-header-name">Audubon</span>
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
