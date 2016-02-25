<?php
/**
 * @file
 * Native Plants list temaplte for mail message.
 */
?>
<!doctype html>
<html lang="en">
<head>
  <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1"/>
  <meta charset="utf-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=0;" />
  <title>National Audubon Society</title>
  <link href="https://fonts.googleapis.com/css?family=Source+Sans+Pro:300,400,600|Noto+Serif:400,700,400italic" rel="stylesheet" type="text/css">

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

    /*h4 {*/
    /*font-family: "Source Sans Pro", Verdana, sans-serif;*/
    /*font-size: 14px;*/
    /*font-weight: bold;*/
    /*color: #595959;*/
    /*line-height: 135%;*/
    /*}*/

    /*h5 {*/
    /*font-family: "Source Sans Pro", Verdana, sans-serif;*/
    /*font-size: 16px;*/
    /*font-weight: normal;*/
    /*color: #666666;*/
    /*line-height: 135%;*/
    /*}*/

    /*h6 {*/
    /*font-family: "Source Sans Pro", Verdana, sans-serif;*/
    /*font-size: 12px;*/
    /*font-weight: bold;*/
    /*color: #595959;*/
    /*line-height: 135%;*/
    /*}*/

    /*p {*/
    /*margin-top: 5px;*/
    /*}*/

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

    a.native-plant-bird-category-link {
      color: #404040;
      text-decoration: underline;
      white-space: nowrap;
    }

  </style>
</head>
<body>
<table width="100%" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td background="<?php print url(drupal_get_path('theme', 'nas') . '/img/email/transparent.gif', array('absolute' => TRUE)); ?>" style="background-repeat: repeat-x" bgcolor="#000">
      <table align="center" width="650" border="0" cellspacing="0" cellpadding="0">
        <tr>
          <td height="129" style="height:129px; vertical-align: middle;" valign="middle">
            <a href="http://www.audubon.org">
              <img src="<?php print url(drupal_get_path('theme', 'nas') . '/img/wordmark-white.png', array('absolute' => TRUE)); ?>" alt="" width="236" style="width:236px;"/>
            </a>
          </td>
        </tr>
      </table>
    </td>
  </tr>
  <tr>
    <td background="<?php print url(drupal_get_path('theme', 'nas') . '/img/email/transparent.gif', array('absolute' => TRUE)); ?>" style="background-repeat: repeat-x" bgcolor="#<?php print $bar_background_color; ?>">
      <table align="center" width="650" border="0" cellspacing="0" cellpadding="0">
        <tr>
          <td height="56" style="height:56px; vertical-align: middle;" valign="middle">
            <h1><?php print $bar_title; ?></h1>
          </td>
        </tr>
      </table>
    </td>
  </tr>
  <tr>
    <td background="<?php print url(drupal_get_path('theme', 'nas') . '/img/email/transparent.gif', array('absolute' => TRUE)); ?>" style="background-repeat: repeat-x" bgcolor="#FFFFFF">
      <table align="center" width="650" border="0" cellspacing="0" cellpadding="0">
        <tr>
          <td>
            <h2><?php print $list_title; ?></h2>
            <?php print $list_text_top; ?>
            <p><?php print l($permalink_url, $permalink_url); ?></p>

            <table cellpadding="0" cellspacing="0" border="0">
              <tr>
                <td>
                  <span style="margin-right: 30px;line-height: 21px;" valign="middle"><?php print $list_share_label; ?></span>
                </td>
                <td>
                  <a target="_blank" href="<?php print $twitter_url; ?>"><img src="<?php print url(drupal_get_path('theme', 'nas') . '/img/email/twitter.png', array('absolute' => TRUE)); ?>" width="21" height="21" style="padding-right: 10px;"></a>
                </td>
                <td>
                  <a target="_blank" href="<?php print $facebook_url; ?>"><img src="<?php print url(drupal_get_path('theme', 'nas') . '/img/email/facebook.png', array('absolute' => TRUE)); ?>" width="21" height="21"></a>
                </td>
              </tr>
            </table>

            <?php print $list_text_bottom; ?>

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
                  <?php print implode(', ', $plant['BirdTypesDesktop']); ?>
                </td>
              </tr>
              <?php endforeach; ?>
              </tbody>
            </table>

          </td>
        </tr>
        <tr>
          <td>

            <h2><?php print $editorial_cards_title; ?></h2>

            <table width="100%" border="0" style="border-collapse: collapse; border: none;" cellpadding="0" cellspacing="0">
              <tr border="0" style="border: none;">
                <td width="315" valign="top" style="border: 1px solid #d4d4d4; box-shadow: 0 1px 1px rgba(0, 0, 0, 0.1);">
                  <div class="editorial-card-photo">
                    <a href="#" title="How To Begin Birding">
                      <img src="http://www.audubon.org/sites/default/files/styles/article_teaser/public/__Camilla_Cerea_CBC_12.jpg?itok=m8Tf_J_Z" alt="How To Begin Birding"  width="315">
                    </a>
                  </div>
                  <div style="font-size: 14px;line-height: 20px;padding: 12px; min-height: 140px;">
                    <a href="#" style="font-family: 'Source Sans Pro', Verdana, sans-serif;">News</a>
                    <a href="#"><h3>How To Begin Birding</h3></a>
                    <p>Like birds, but don’t know how to make the leap to becoming a birder? Here are three easy steps to get you into the field. </p>
                    <p><em><a href="#">Read more »</a></em></p>
                  </div>
                </td>
                <td width="20" border="0"  style="border-bottom: 1px solid #FFF;">
                  <img src="<?php print url(drupal_get_path('theme', 'nas') . '/img/email/transparent.gif', array('absolute' => TRUE)); ?>" alt="" width="20"/>
                </td>
                <td width="315" valign="top" style="border: 1px solid #d4d4d4; box-shadow: 0 1px 1px rgba(0, 0, 0, 0.1);">
                  <div class="editorial-card-photo">
                    <a href="#" title="5 Great Winter Destinations">
                      <img src="https://www.audubon.org/sites/default/files/styles/article_teaser/public/w1_winter_wonderlans.jpg?itok=Ahz5xahx" alt="5 Great Winter Destinations" width="315">
                    </a>
                  </div>
                  <div style="font-size: 14px;line-height: 20px;padding: 12px; min-height: 140px;">
                    <a href="#" style="font-family: 'Source Sans Pro', Verdana, sans-serif;">Travel</a>
                    <a href="#"><h3>5 Great Winter Destinations</h3></a>
                    <p>These national parks offer a host of unique activities when the nights grow long.</p>
                    <p><em><a href="#">Read more »</a></em></p>
                  </div>
                </td>
              </tr>
              <tr  border="0" style="border: none;">
                <td colspan="3" border="0" style="border: 0;">
                  <img src="<?php print url(drupal_get_path('theme', 'nas') . '/img/email/transparent.gif', array('absolute' => TRUE)); ?>" alt="" height="70"/>
                </td>
              </tr>
            </table>




          </td>
        </tr>
      </table>
    </td>
  </tr>
  <tr>
    <td background="<?php print url(drupal_get_path('theme', 'nas') . '/img/email/transparent.gif', array('absolute' => TRUE)); ?>" style="background-repeat: repeat-x" bgcolor="#3A3A3A">
      <table align="center" width="650" border="0" cellspacing="0" cellpadding="0">
        <tr>
          <td height="158" style="height: 158px;">

            <table width="100%">
              <tr>
                <td width="260" valign="top" align="right" style="border-right: 1px solid #4e4e4e; padding-right: 15px;">
                  <a href="#"><img src="<?php print url(drupal_get_path('theme', 'nas') . '/img/email/footer-logo.png', array('absolute' => TRUE)); ?>" width="144" alt=""/></a>
                </td>
                <td width="" valign="center" style="padding-left: 15px;">
                  <p color="#FFF" style="color:#fff;font-family: Arial; font-weight: bold; font-size: 13px; line-height: 17px;">
                    225 Varick Street, 7th Floor, New York, NY 10014<br>
                    <a href="mailto:AudubonConnect@audubon.org">AudubonConnect@audubon.org</a>
                  </p>
                </td>
              </tr>
              <tr>
                <td colspan="2" align="center" style="color:#FFF; font-family: Arial; font-weight: bold; font-size: 13px; padding-top: 15px;">
                  <a href="#">Donate</a> |
                  <a href="#">Change contact information</a> |
                  <a href="#">Manage your communications</a> |
                  <a href="#">Unsubscribe</a>
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