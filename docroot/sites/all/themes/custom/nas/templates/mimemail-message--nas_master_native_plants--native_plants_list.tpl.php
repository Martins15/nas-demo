<?php

/**
 * @file
 * Default theme implementation to format an HTML mail.
 *
 * Copy this file in your default theme folder to create a custom themed mail.
 * Rename it to mimemail-message--[module]--[key].tpl.php to override it for a
 * specific mail.
 *
 * Available variables:
 * - $recipient: The recipient of the message
 * - $subject: The message subject
 * - $body: The message body
 * - $css: Internal style sheets
 * - $module: The sending module
 * - $key: The message identifier
 *
 * @see template_preprocess_mimemail_message()
 */
?>
<html lang="en">
  <head>
    <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1"/>
    <meta charset="utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=0;" />
    <title>National Audubon Society</title>
    <link href="https://fonts.googleapis.com/css?family=Source+Sans+Pro:300,400,600|Noto+Serif:400,700,400italic" rel="stylesheet" type="text/css">
    <?php if ($css): ?>
    <style type="text/css">
      <!--
      <?php print $css ?>
      -->
    </style>
    <?php endif; ?>
    <style type="text/css">
      body {
        background-color: #fff;
        color: #404040;
        font-family: "Noto Serif", Georgia, serif;
        font-size: 16px;
        font-weight: 400;
        line-height: 22px;
        margin: 0;
        padding: 0;
        -moz-osx-font-smoothing: grayscale;
        -webkit-font-smoothing: antialiased;
      }

      h1 {
        font-family: "Source Sans Pro", Verdana, sans-serif;
        font-size: 33px;
        font-weight: 300;
        color: #FFF;
        margin: 0;
      }

      h2 {
        font-family: "Source Sans Pro", Verdana, sans-serif;
        font-size: 28px;
        line-height: 31px;
        font-weight: 300;
        color: #404040;
      }

      h3 {
        color: #262626;
        font-family: "Source Sans Pro", Verdana, sans-serif;
        font-size: 24px;
        font-weight: normal;
        line-height: 28px;
        margin: 0 0 10px 0;
      }

      img {
        margin: 0;
        display: block;
      }

      a, a:visited, a:hover, a:active {
        color: #0AA8E3;
        text-decoration: none;
      }

      table td {
      }

      table.list-table td,
      table.list-table th {
        font-family: "Source Sans Pro", Verdana, sans-serif;
      }
    </style>
  </head>
  <body id="mimemail-body" <?php if ($module && $key): print 'class="'. $module .'-'. $key .'"'; endif; ?>>
    <?php print $body ?>
  </body>
</html>
