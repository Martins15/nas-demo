<?php
/**
 * @file
 * Native Plants list template for mail message.
 */
?>
<html lang="en">
  <head>
    <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1"/>
    <meta charset="utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=0;" />
    <title>National Audubon Society</title>
    <link href="https://fonts.googleapis.com/css?family=Source+Sans+Pro:300,400,600|Noto+Serif:400,700,400italic" rel="stylesheet" type="text/css">
    <?php if (!empty($css)): ?>
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
        color: #404040;
        font-family: "Source Sans Pro", Verdana, sans-serif;
        font-size: 28px;
        font-weight: 300;
        line-height: 31px;
        margin: 24px 0 24px 0;
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
  <body id="mimemail-body" class="native_plants_master-native_plants_list">
    <table width="100%" border="0" cellspacing="0" cellpadding="0">
      <tr>
        <td background="<?php print file_create_url(drupal_get_path('theme', 'nas') . '/img/email/transparent.gif'); ?>" style="background-repeat: repeat-x" bgcolor="#000">
          <table align="center" width="650" border="0" cellspacing="0" cellpadding="0">
            <tr>
              <td height="129" style="height:129px; vertical-align: middle;" valign="middle">
                <a href="<?php print url('<front>', array('absolute' => TRUE)); ?>">
                  <?php print theme('image', array('path' => drupal_get_path('theme', 'nas') . '/img/wordmark-white.png', 'alt' => '', 'width' => 236, 'attributes' => array('style' => 'width: 236px;'))); ?>
                </a>
              </td>
            </tr>
          </table>
        </td>
      </tr>
      <tr>
        <td background="<?php print file_create_url(drupal_get_path('theme', 'nas') . '/img/email/transparent.gif'); ?>" style="background-repeat: repeat-x" bgcolor="#<?php print $bar_background_color; ?>">
          <table align="center" width="650" border="0" cellspacing="0" cellpadding="0">
            <tr>
              <td height="56" style="height:56px; vertical-align: middle;" valign="middle">
                <h1 style="font-family: 'Source Sans Pro', Verdana, sans-serif; font-size: 33px; font-weight: 300; color: #FFF; margin: 0;">
                  <a href="<?php print url($bar_link, array('absolute' => TRUE)); ?>" style="color: #FFF; text-decoration: none;"><?php print $bar_title; ?></a>
                </h1>
              </td>
            </tr>
          </table>
        </td>
      </tr>
      <tr>
        <td background="<?php print file_create_url(drupal_get_path('theme', 'nas') . '/img/email/transparent.gif'); ?>" style="background-repeat: repeat-x" bgcolor="#FFFFFF">
          <table align="center" width="650" border="0" cellspacing="0" cellpadding="0">
            <tr>
              <td>
                <h2 style="font-family: 'Source Sans Pro', Verdana, sans-serif; font-size: 28px; line-height: 31px; font-weight: 300; color: #404040;">
                  <?php print $list_title_1; ?>
                </h2>
                <?php print $list_text_1; ?>
                <h2 style="font-family: 'Source Sans Pro', Verdana, sans-serif; font-size: 28px; line-height: 31px; font-weight: 300; color: #404040;">
                  <?php print $list_title_2; ?>
                </h2>
                <?php print $list_text_2; ?>
                <a href="<?php print $permalink_url; ?>" class="button" style="Margin:0;background-color:#F15936;border-radius:8px;color:#fff;display:inline-block;font-family:'Source Sans Pro',Verdana,sans-serif;font-size:20px;font-weight:inherit;height:45px;line-height:45px;margin:9px 0 9px 0;padding:0 35px 0 35px;text-align:left;text-decoration:none"><?php print t('How Many Will You Plant?'); ?></a>

                <table width="100%" border="0" cellspacing="0" cellpadding="12" class="list-table" style="border-collapse: collapse;">
                  <thead>
                  <tr bgcolor="#f4f4f4" style="border-bottom: 1px solid #d4d4d4;border-top: 1px solid #d4d4d4; background-color: #f4f4f4;">
                    <th valign="middle"><?php print t('Plant name'); ?></th>
                    <th valign="middle"><?php print t('Scientific Name'); ?></th>
                    <th valign="middle"><?php print t('May attract'); ?></th>
                  </tr>
                  </thead>
                  <tbody>
                  <?php foreach ($plants as $plant): ?>
                  <tr style="border-bottom: 1px solid #d4d4d4;border-top: 1px solid #d4d4d4;">
                    <td><?php print $plant['CommonName']; ?></td>
                    <td align="center"><em><?php print $plant['ScientificName']; ?></em></td>
                    <td width="180">
                      <?php print implode(', ', $plant['BirdTypesMail']); ?>
                    </td>
                  </tr>
                  <?php endforeach; ?>
                  </tbody>
                </table>

              </td>
            </tr>
            <tr>
              <td>

                <h2 style="font-family: 'Source Sans Pro', Verdana, sans-serif; font-size: 28px; line-height: 31px; font-weight: 300; color: #404040;">
                  <?php print $editorial_cards_title; ?>
                </h2>

                <table width="100%" border="0" style="border-collapse: collapse; border: none;" cellpadding="0" cellspacing="0">
                  <tr border="0" style="border: none;">
                    <?php $first_card = TRUE;
                    foreach ($editorial_cards as $card):
                    if (!$first_card): ?>
                    <td width="20" border="0"  style="border-bottom: 1px solid #FFF;">
                      <?php print theme('image', array('path' => drupal_get_path('theme', 'nas') . '/img/email/transparent.gif', 'alt' => '', 'width' => 20)); ?>
                    </td>
                    <?php endif;
                    $first_card = FALSE; ?>
                    <td width="315" valign="top" style="border: 1px solid #d4d4d4; box-shadow: 0 1px 1px rgba(0, 0, 0, 0.1);">
                      <div class="editorial-card-photo">
                        <a href="<?php print $card['url']; ?>" title="<?php print $card['title']; ?>">
                          <?php print theme('image', array(
                            'path' => $card['image_url'],
                            'alt' => $card['title'],
                            'width' => 315,
                            'height' => 200,
                            'attributes' => array(
                              'width' => 315,
                              'height' => 200,
                              'style' => 'width: 315px; height: 200px;',
                            ),
                          )); ?>
                        </a>
                      </div>
                      <div style="font-size: 14px;line-height: 20px;padding: 12px; min-height: 140px;">
                        <?php if ($card['blue_text_link_url']): ?>
                        <a href="<?php print $card['blue_text_link_url']; ?>" style="font-family: 'Source Sans Pro', Verdana, sans-serif;"><?php print $card['blue_text_link_text']; ?></a>
                        <?php endif; ?>
                        <h3 style="color: #262626; font-family: 'Source Sans Pro', Verdana, sans-serif; font-size: 24px; font-weight: normal; line-height: 28px; margin: 0 0 10px 0;">
                          <a href="<?php print $card['url']; ?>" style="color: #262626; text-decoration: none;">
                            <?php print $card['title']; ?>
                          </a>
                        </h3>
                        <p><?php print $card['subtitle']; ?></p>
                        <p><em><a href="<?php print $card['url']; ?>"><?php print $card['custom_link_text']; ?> »</a></em></p>
                      </div>
                    </td>
                    <?php endforeach; ?>
                  </tr>
                  <tr  border="0" style="border: none;">
                    <td colspan="3" border="0" style="border: 0;">
                      <?php print theme('image', array('path' => drupal_get_path('theme', 'nas') . '/img/email/transparent.gif', 'alt' => '', 'height' => 70, 'attributes' => array('style' => 'height: 70px;', 'height' => '70'))); ?>
                    </td>
                  </tr>
                </table>

              </td>
            </tr>
          </table>
        </td>
      </tr>
      <tr>
        <td background="<?php print file_create_url(drupal_get_path('theme', 'nas') . '/img/email/transparent.gif'); ?>" style="background-repeat: repeat-x" bgcolor="#3A3A3A">
          <table align="center" width="650" border="0" cellspacing="0" cellpadding="0">
            <tr>
              <td height="158" style="height: 158px;">

                <table width="100%">
                  <tr>
                    <td width="260" valign="top" align="right" style="border-right: 1px solid #4e4e4e; padding-right: 15px;">
                      <a href="<?php print url('<front>', array('absolute' => TRUE)); ?>">
                        <?php print theme('image', array('path' => drupal_get_path('theme', 'nas') . '/img/email/footer-logo.png', 'width' => 144, 'alt' => '')); ?>
                      </a>
                    </td>
                    <td width="" valign="center" style="padding-left: 15px;">
                      <p color="#FFF" style="color:#fff;font-family: Arial; font-weight: bold; font-size: 13px; line-height: 17px;">
                        225 Varick Street, 7th Floor, New York, NY 10014<br>
                        <a href="mailto:AudubonConnect@audubon.org">AudubonConnect@audubon.org</a>
                      </p>
                    </td>
                  </tr>
                </table>

              </td>
            </tr>
          </table>
        </td>
      </tr>
    </table>
  </body>
</html>