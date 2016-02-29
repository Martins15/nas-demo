<?php
/**
 * @file
 * Native Plants list template for mail message.
 */
?>
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

            <h2><?php print $editorial_cards_title; ?></h2>

            <table width="100%" border="0" style="border-collapse: collapse; border: none;" cellpadding="0" cellspacing="0">
              <tr border="0" style="border: none;">
                <?php $first_card = TRUE;
                foreach ($editorial_cards as $card):
                if (!$first_card): ?>
                <td width="20" border="0"  style="border-bottom: 1px solid #FFF;">
                  <img src="<?php print url(drupal_get_path('theme', 'nas') . '/img/email/transparent.gif', array('absolute' => TRUE)); ?>" alt="" width="20"/>
                </td>
                <?php endif;
                $first_card = FALSE; ?>
                <td width="315" valign="top" style="border: 1px solid #d4d4d4; box-shadow: 0 1px 1px rgba(0, 0, 0, 0.1);">
                  <div class="editorial-card-photo">
                    <a href="<?php print $card['url']; ?>" title="<?php print $card['title']; ?>">
                      <img src="<?php print $card['image_url']; ?>" alt="<?php print $card['title']; ?>" width="315" height="200" />
                    </a>
                  </div>
                  <div style="font-size: 14px;line-height: 20px;padding: 12px; min-height: 140px;">
                    <?php if ($card['blue_text_link_url']): ?>
                    <a href="<?php print $card['blue_text_link_url']; ?>" style="font-family: 'Source Sans Pro', Verdana, sans-serif;"><?php print $card['blue_text_link_text']; ?></a>
                    <?php endif; ?>
                    <a href="<?php print $card['url']; ?>"><h3><?php print $card['title']; ?></h3></a>
                    <p><?php print $card['subtitle']; ?></p>
                    <p><em><a href="<?php print $card['url']; ?>"><?php print $card['custom_link_text']; ?> »</a></em></p>
                  </div>
                </td>
                <?php endforeach; ?>
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