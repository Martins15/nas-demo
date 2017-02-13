
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
          "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" lang="en" xml:lang="en">
  <head>
    <link rel="stylesheet" type="text/css" href="<?php print $css_path; ?>">
    <link href="https://fonts.googleapis.com/css?family=Source+Sans+Pro:300,400,600|Noto+Serif:400,700,400italic" rel="stylesheet" type="text/css">
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <meta name="viewport" content="width=device-width">
    <title></title>

  </head>
  <body>
    <!-- <style> -->
    <span class="preheader"></span>
    <table class="body">
      <tbody>
        <tr>
          <td class="header-wrap">
            <table align="center" border="0" cellspacing="0" cellpadding="0" style="max-width: 632px; width: 100%;">
              <tr>
                <td height="129" style="height:129px; vertical-align: middle;" valign="middle">
                  <a href="http://www.audubon.org">
                    <img src="<?php print $wordmark_url; ?>" alt="" width="236" style="width:236px;">
                  </a>
                </td>
              </tr>
            </table>

          </td>
        </tr>

        <tr>
          <td class="green-bar-wrap">
            <table align="center" style="max-width: 632px; width: 100%;" border="0" cellspacing="0" cellpadding="0" class="green-bar">
              <tr>
                <td height="56" style="height:56px; vertical-align: middle;" valign="middle">
                  <h1>
                    <a href="http://www.audubon.org/native-plants"><?php print t('Audubon Native Plants Database'); ?></a>
                  </h1>
                </td>
              </tr>
            </table>

          </td>
        </tr>

        <tr>
          <td class="center body-wrap" align="center" valign="top">
            <table align="center" class="container"><tbody><tr><td>

              <table class="row"><tbody><tr>

                <th class="small-12 large-12 columns first last"><table><tr><th>
                  <h2 style="color: #404040;
                             font-family: 'Source Sans Pro', Verdana, sans-serif;
                             font-size: 28px;
                             font-weight: 300;
                             line-height: 31px;
                             margin-top: 35px;
                             ">
                    <?php print $list_title_1; ?>
                  </h2>
                  <?php print $list_text_1; ?>
                  <h2 style="color: #404040;
                             font-family: 'Source Sans Pro', Verdana, sans-serif;
                             font-size: 28px;
                             font-weight: 300;
                             line-height: 31px;">
                    <?php print $list_title_2; ?>
                  </h2>
                  <?php print $list_text_2; ?>
                  <a href="<?php print $permalink_url; ?>" class="button"><?php print t('How Many Will You Plant?'); ?></a>
                </th>
                <th class="expander"></th></tr></table></th>

              </tr></tbody></table>

              <table align="center" class="container show-for-large"><tbody><tr><td>
                <table class="row"><tbody><tr>
                  <th class="small-12 large-12 columns first last"><table><tr><th>
                    <h2 style="color: #404040;
                               font-family: 'Source Sans Pro', Verdana, sans-serif;
                               font-size: 28px;
                               font-weight: 300;
                               line-height: 30px;
                               margin-top: 0;">
                      <?php print t('Your Native Plant List'); ?>
                    </h2>
                      <p>
                        <?php print t('Zip Code') ?>:
                        <a href="<?php print $search_url; ?>"><?php print $permalink->zip_code . ' (' . t('Search again') . ')'; ?></a>
                      </p>
                    <table width="100%" border="0" cellspacing="0" cellpadding="12" class="list-table" style="margin-bottom: 20px;">
                      <thead>
                        <tr>
                          <th class="plant-name-cell"><?php print t('Plant name'); ?></th>
                          <th class="scientific-name-cell"><?php print t('Scientific Name'); ?></th>
                          <th class="may-attract-cell"><?php print t('May attract'); ?></th>
                        </tr>
                      </thead>
                      <tbody>
                        <?php foreach ($plants as $plant): ?>
                          <tr>
                            <td class="plant-name-cell"><?php print $plant['CommonName']; ?></td>
                            <td class="scientific-name-cell"><em><?php print $plant['ScientificName']; ?></em></td>
                            <td class="may-attract-cell"><?php print implode(', ', $plant['BirdTypesDesktop']); ?></td>
                          </tr>
                        <?php endforeach; ?>
                      </tbody>
                    </table>
                  </th>
                  <th class="expander"></th></tr></table></th>
                </tr></tbody></table>
              </td></tr></tbody></table>

              <div class="plants-list hide-for-large">
                <table align="center" class="container"><tbody><tr><td>
                  <table class="row"><tbody><tr>
                    <th class="small-12 large-12 columns first last"><table><tr><th>
                    <h2 class="plants-list-title"><?php print t('Your Plants list'); ?></h2>
                    </th>
                    <th class="expander"></th></tr></table></th>
                  </tr></tbody></table>
                </td></tr></tbody></table>

                <?php foreach ($plants as $plant): ?>
                  <div class="clearfix view-row">
                    <div class="columns">
                      <div>
                        <span class="mobile-search-full-results--label"><?php print t('Plant'); ?>:</span>
                        <?php print $plant['CommonName']; ?>
                      </div>
                      <div>
                        <span class="mobile-search-full-results--label"><?php print t('Scientific name'); ?>:</span>
                        <em><?php print $plant['ScientificName']; ?></em>
                      </div>
                      <div>
                        <span class="mobile-search-full-results--label"><?php print t('Attracts'); ?>:</span>
                        <?php print implode(', ', $plant['BirdTypesMobile']); ?>
                      </div>
                    </div>
                  </div>
                <?php endforeach; ?>

              <table align="center" class="container show-for-large"><tbody><tr><td>
                <table class="row"><tbody><tr>
                  <th class="small-12 large-12 columns first last"><table><tr><th>
                    <h2 style="color: #404040;
                               font-family: 'Source Sans Pro', Verdana, sans-serif;
                               font-size: 28px;
                               font-weight: 300;
                               line-height: 30px;
                               margin-top: 0;">
                      <?php t('Audubon Near You'); ?>
                    </h2>

                    <table width="100%" border="0" cellspacing="0">
                      <tbody>
                        <?php foreach ($resources as $resource): ?>
                          <tr>
                            <td style="width: 240px;">
                              <table>
                                <thead>
                                  <tr>
                                    <th colspan="2">
                                      <h3 style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                                 color: #0aa8e3;
                                                 font-size: 22px;"><?php print $resource['title']; ?>
                                      </h3>
                                    </th>
                                  </tr>
                                </thead>
                                <tbody>
                                  <tr>
                                    <td style="text-align: left;
                                               vertical-align: middle;
                                               width: 60px;">
                                      <img alt="map" src="<?php print $icon_map_url; ?>" style="display: inline-block;
                                                                                          margin-bottom: 20px;">
                                    </td>
                                    <td>
                                      <div style="color: #404040;
                                                  font-family: 'Noto Serif', Georgia, serif;
                                                  margin-bottom: 20px;
                                                  font-size: 16px;
                                                  white-space: nowrap;">
                                        <?php print $resource['address']['rendered']; ?>
                                      </div>
                                    </td>
                                  </tr>
                                  <tr>
                                    <td colspan="2">
                                      <a href="<?php print $resource['link']['url']; ?>"
                                         style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                                display: block;
                                                background-color: #66a122;
                                                color: #ffffff;
                                                max-width: 140px;
                                                text-align: center;
                                                border-radius: 6px;
                                                line-height: 44px;
                                                margin-bottom: 40px;">
                                        <?php print t('Visit Site'); ?>
                                      </a>
                                    </td>
                                  </tr>
                                </tbody>
                              </table>
                            </td>
                            <td>
                              <h3 style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                         color: #404040;
                                         font-size: 22px;">
                                <?php print t('Services provided at @title', array('@title' => $resource['title'])); ?>
                              </h3>

                              <ul style="font-size: 16px;">
                                <?php foreach ($resource['services'] as $service): ?>
                                  <li><?php print $service; ?></li>
                                <?php endforeach; ?>
                              </ul>
                            </td>
                          </tr>
                        <?php endforeach; ?>
                      </tbody>
                    </table>
                  </th>
                  <th class="expander"></th></tr></table></th>
                </tr></tbody></table>
              </td></tr></tbody></table>

              <table align="center" class="container hide-for-large"><tbody><tr><td>
                <table class="row"><tbody><tr>
                  <th class="small-12 large-12 columns first last"><table><tr><th>
                    <h2 style="color: #404040;
                               font-family: 'Source Sans Pro', Verdana, sans-serif;
                               font-size: 28px;
                               font-weight: 300;
                               line-height: 30px;
                               margin-top: 0;">
                      <?php t('Audubon Near You'); ?>
                    </h2>
                  </th>
                  <th class="expander"></th></tr></table></th>
                </tr></tbody></table>
                <?php foreach ($resources as $resource): ?>
                  <div class="clearfix view-row">
                    <div class="columns">
                      <h3 style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                 color: #0aa8e3;
                                 font-size: 22px;"><?php print $resource['title']; ?>
                      </h3>

                      <div style="color: #404040;
                                  font-family: 'Noto Serif', Georgia, serif;
                                  margin-bottom: 20px;
                                  font-size: 16px;">
                        <?php print $resource['address']['rendered']; ?>
                      </div>

                      <a href="<?php print $resource['link']['url']; ?>"
                         style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                display: block;
                                background-color: #66a122;
                                color: #ffffff;
                                max-width: 140px;
                                text-align: center;
                                border-radius: 6px;
                                line-height: 44px;
                                margin-bottom: 20px;">
                        <?php print t('Visit Site'); ?>
                      </a>
                    </div>
                  </div>

                  <div class="clearfix view-row">
                    <div class="columns">

                      <h3 style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                 color: #404040;
                                 font-size: 22px;">
                        <?php print t('Services provided at @title', array('@title' => $resource['title'])); ?>
                      </h3>

                      <ul style="font-size: 16px;">
                        <?php foreach ($resource['services'] as $service): ?>
                          <li><?php print $service; ?></li>
                        <?php endforeach; ?>
                      </ul>

                    </div>
                  </div>
                <?php endforeach; ?>
              </td></tr></tbody></table>


              <table align="center" class="container show-for-large"><tbody><tr><td>
                <table class="row"><tbody><tr>
                  <th class="small-12 large-12 columns first last"><table><tr><th>
                    <?php if (!empty($nurseries)): ?>
                      <h2 style="color: #404040;
                                 font-family: 'Source Sans Pro', Verdana, sans-serif;
                                 font-size: 28px;
                                 font-weight: 300;
                                 line-height: 30px;
                                 margin-top: 0;">
                        <?php print t('Where to buy native plants near you'); ?>
                      </h2>

                      <table style="font-family: 'Source Sans Pro', Verdana, sans-serif;">
                        <tbody>
                          <?php foreach (array_chunk($nurseries, 3) as $row): ?>
                            <tr>
                              <?php foreach ($row as $nursery): ?>
                                <td style="width: 33.33%;">
                                  <div class="address" style="margin-bottom: 16px !important;
                                                              text-align: left;">
                                    <h4 style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                               font-size: 16px;
                                               margin-bottom: 0;
                                               font-weight: 600;
                                               color: #404040;">
                                      <?php print $nursery['title']; ?>
                                    </h4>

                                    <p style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                              font-size: 16px;
                                              margin-bottom: 6px;">
                                      <?php print $nursery['address']['rendered']; ?>
                                    </p>
                                    <?php if (!empty($nursery['phone'])): ?>
                                      <p style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                                font-size: 16px;
                                                margin-bottom: 0;"><?php print $nursery['phone']; ?></p>
                                    <?php endif; ?>
                                    <?php if (!empty($nursery['link']['url'])): ?>
                                      <a style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                                font-size: 16px;" href="<?php print $nursery['link']['url']; ?>" target="_blank">
                                        <img alt="link" src="<?php print $icon_link_url; ?>" style="display: inline-block;
                                                                                               vertical-align: baseline;">
                                        <?php print $nursery['link']['print']; ?>
                                      </a>
                                    <?php endif; ?>
                                  </div>
                                </td>
                              <?php endforeach; ?>
                            </tr>
                          <?php endforeach; ?>
                        </tbody>
                      </table>
                    <?php endif; ?>

                    <?php if (!empty($online_nurseries)): ?>
                      <h2 style="color: #404040;
                                 font-family: 'Source Sans Pro', Verdana, sans-serif;
                                 font-size: 28px;
                                 font-weight: 300;
                                 line-height: 30px;">
                        <?php print t('Online Retailers'); ?>
                      </h2>
                      <table style="font-family: 'Source Sans Pro', Verdana, sans-serif;">
                        <tbody>
                          <?php foreach (array_chunk($online_nurseries, 3) as $row): ?>
                            <tr>
                              <?php foreach ($row as $nursery): ?>
                                <td style="width: 33.33%;">
                                  <div class="address" style="margin-bottom: 16px !important;
                                                              text-align: left;">
                                    <h4 style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                               font-size: 16px;
                                               margin-bottom: 0;
                                               font-weight: 600;
                                               color: #404040;">
                                      <?php print $nursery['title']; ?>
                                    </h4>

                                    <p style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                              font-size: 16px;
                                              margin-bottom: 6px;">
                                      <?php print $nursery['address']['rendered']; ?>
                                    </p>
                                    <?php if (!empty($nursery['phone'])): ?>
                                      <p style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                                font-size: 16px;
                                                margin-bottom: 0;"><?php print $nursery['phone']; ?></p>
                                    <?php endif; ?>
                                    <?php if (!empty($nursery['link']['url'])): ?>
                                      <a style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                                font-size: 16px;" href="<?php print $nursery['link']['url']; ?>" target="_blank">
                                        <img alt="link" src="<?php print $icon_link_url; ?>" style="display: inline-block;
                                                                                              vertical-align: baseline;">
                                        <?php print $nursery['link']['print']; ?>
                                      </a>
                                    <?php endif; ?>
                                  </div>
                                </td>
                              <?php endforeach; ?>
                            </tr>
                          <?php endforeach; ?>
                        </tbody>
                      </table>
                    <?php endif; ?>

                    <h2 style="color: #404040;
                               font-family: 'Source Sans Pro', Verdana, sans-serif;
                               font-size: 28px;
                               font-weight: 300;
                               line-height: 30px;">
                      <?php print t('Other Local Resources'); ?>
                    </h2>
                    <table style="font-family: 'Source Sans Pro', Verdana, sans-serif;">
                      <tbody>
                        <tr>
                          <?php foreach ($additional_resources as $resource): ?>
                            <td style="width: 50%;">
                              <div class="address" style="margin-bottom: 16px !important;
                                                          margin-right: 10px !important;
                                                          text-align: left;">
                                <h4 style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                           font-size: 16px;
                                           margin-bottom: 0;
                                           font-weight: 600;
                                           color: #404040;">
                                  <?php print $resource['title']; ?>
                                </h4>
                                <?php if (!empty($resource['description'])): ?>
                                  <p style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                            font-size: 16px;
                                            margin-bottom: 6px;"><?php print $resource['description']; ?></p>
                                <?php endif; ?>
                                <p style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                          font-size: 16px;
                                          margin-bottom: 6px;">
                                  <?php print $resource['address']['rendered']; ?>
                                </p>
                                <?php if (!empty($resource['phone'])): ?>
                                  <p style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                            font-size: 16px;
                                            margin-bottom: 0;"><?php print $resource['phone']; ?></p>
                                <?php endif; ?>
                                <?php if (!empty($resource['link']['url'])): ?>
                                  <a style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                            font-size: 16px;" href="<?php print $resource['link']['url']; ?>">
                                    <img alt="link" src="<?php print $icon_link_url; ?>" style="display: inline-block;
                                                                                          vertical-align: baseline;">
                                    <?php print $resource['link']['print']; ?>
                                  </a>
                                <?php endif; ?>
                              </div>
                            </td>
                          <?php endforeach; ?>
                        </tr>
                      </tbody>
                    </table>
                  </th>
                  <th class="expander"></th></tr></table></th>
                </tr></tbody></table>
              </td></tr></tbody></table>

              <div class="hide-for-large">
                <?php if (!empty($nurseries)): ?>
                  <table class="row"><tbody><tr>
                    <th class="small-12 large-12 columns first last"><table><tr><th>
                      <h2 style="color: #404040;
                                 font-family: 'Source Sans Pro', Verdana, sans-serif;
                                 font-size: 28px;
                                 font-weight: 300;
                                 line-height: 30px;">
                        <?php print t('Where to buy native plants near you'); ?>
                      </h2>
                    </th>
                    <th class="expander"></th></tr></table></th>
                  </tr></tbody></table>

                  <?php foreach ($nurseries as $nursery): ?>
                    <div class="clearfix view-row">
                      <div class="columns">
                        <div class="address" style="margin-bottom: 16px !important;
                                                    text-align: left;">
                          <h4 style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                     font-size: 16px;
                                     margin-bottom: 0;
                                     font-weight: 600;
                                     color: #404040;">
                            <?php print $nursery['title']; ?>
                          </h4>

                          <p style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                    font-size: 16px;
                                    margin-bottom: 6px;">
                            <?php print $nursery['address']['rendered']; ?>
                          </p>
                          <?php if (!empty($nursery['phone'])): ?>
                            <p style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                      font-size: 16px;
                                      margin-bottom: 0;"><?php print $nursery['phone']; ?></p>
                          <?php endif; ?>
                          <?php if (!empty($nursery['link']['url'])): ?>
                            <a style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                      font-size: 16px;" href="<?php print $nursery['link']['url']; ?>">
                              <img alt="link" src="<?php print $icon_link_url; ?>" style="display: inline-block;
                                                                                    vertical-align: baseline;">
                              <?php print $nursery['link']['print']; ?>
                            </a>
                          <?php endif; ?>
                        </div>
                      </div>
                    </div>
                  <?php endforeach; ?>
                <?php endif; ?>

                <?php if (!empty($online_nurseries)): ?>
                  <table class="row"><tbody><tr>
                    <th class="small-12 large-12 columns first last"><table><tr><th>
                      <h2 style="color: #404040;
                                 font-family: 'Source Sans Pro', Verdana, sans-serif;
                                 font-size: 28px;
                                 font-weight: 300;
                                 line-height: 30px;">
                        <?php print t('Online Retailers'); ?>
                      </h2>
                    </th>
                    <th class="expander"></th></tr></table></th>
                  </tr></tbody></table>

                  <?php foreach ($online_nurseries as $nursery): ?>
                    <div class="clearfix view-row">
                      <div class="columns">
                        <div class="address" style="margin-bottom: 16px !important;
                                                    text-align: left;">
                          <h4 style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                     font-size: 16px;
                                     margin-bottom: 0;
                                     font-weight: 600;
                                     color: #404040;">
                            <?php print $nursery['title']; ?>
                          </h4>

                          <p style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                    font-size: 16px;
                                    margin-bottom: 6px;">
                            <?php print $nursery['address']['rendered']; ?>
                          </p>
                          <?php if (!empty($nursery['phone'])): ?>
                            <p style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                      font-size: 16px;
                                      margin-bottom: 0;"><?php print $nursery['phone']; ?></p>
                          <?php endif; ?>
                          <?php if (!empty($nursery['link']['url'])): ?>
                            <a style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                      font-size: 16px;" href="<?php print $nursery['link']['url']; ?>">
                              <img alt="link" src="<?php print $icon_link_url; ?>" style="display: inline-block;
                                                                                    vertical-align: baseline;">
                              <?php print $nursery['link']['print']; ?>
                            </a>
                          <?php endif; ?>
                        </div>
                      </div>
                    </div>
                  <?php endforeach; ?>
                <?php endif; ?>

                <table class="row"><tbody><tr>
                  <th class="small-12 large-12 columns first last"><table><tr><th>
                    <h2 style="color: #404040;
                               font-family: 'Source Sans Pro', Verdana, sans-serif;
                               font-size: 28px;
                               font-weight: 300;
                               line-height: 30px;">
                      <?php print t('Other Local Resources'); ?>
                    </h2>
                  </th>
                  <th class="expander"></th></tr></table></th>
                </tr></tbody></table>

                <?php foreach ($additional_resources as $resource): ?>
                  <div class="clearfix view-row">
                    <div class="columns">
                      <div class="address" style="margin-bottom: 16px !important;
                                                  text-align: left;">
                        <h4 style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                   font-size: 16px;
                                   margin-bottom: 0;
                                   font-weight: 600;
                                   color: #404040;">
                          <?php print $resource['title']; ?>
                        </h4>
                        <?php if (!empty($resource['description'])): ?>
                          <p style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                    font-size: 16px;
                                    margin-bottom: 6px;"><?php print $resource['description']; ?></p>
                        <?php endif; ?>
                        <p style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                  font-size: 16px;
                                  margin-bottom: 6px;">
                          <?php print $resource['address']['rendered']; ?>
                        </p>
                        <?php if (!empty($resource['phone'])): ?>
                          <p style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                    font-size: 16px;
                                    margin-bottom: 0;"><?php print $resource['phone']; ?></p>
                        <?php endif; ?>
                        <?php if (!empty($resource['link']['url'])): ?>
                          <a style="font-family: 'Source Sans Pro', Verdana, sans-serif;
                                    font-size: 16px;" href="<?php print $resource['link']['url']; ?>">
                            <img alt="link" src="<?php print $icon_link_url; ?>" style="display: inline-block;
                                                                                  vertical-align: baseline;">
                            <?php print $resource['link']['print']; ?>
                          </a>
                        <?php endif; ?>
                      </div>
                    </div>
                  </div>
                <?php endforeach; ?>

              <table class="row"><tbody><tr>
                <th class="small-12 large-12 columns first last" larget="12"><table><tr><th>
                  <h2 class="editorial-cards-title">
                    <?php print t('More Audubon Native Plant resources'); ?>
                  </h2>
                </th>
                <th class="expander"></th></tr></table></th>
              </tr></tbody></table>
              <table class="row editorial-cards"><tbody><tr>
                <?php foreach ($editorial_cards as $card): ?>
                  <th class="small-12 large-6 columns first"><table><tr><th>
                    <div class="editorial-card">
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
                      <div class="editorial-card-content">
                        <?php if ($card['blue_text_link_url']): ?>
                          <a href="<?php print $card['blue_text_link_url']; ?>" class="editorial-card-slug">
                            <?php print $card['blue_text_link_text']; ?>
                          </a>
                        <?php endif; ?>

                        <h3>
                          <a href="<?php print $card['url']; ?>"><?php print $card['title']; ?></a>
                        </h3>
                        <p><?php print $card['subtitle']; ?></p>
                        <p><em><a href="<?php print $card['url']; ?>"><?php print $card['custom_link_text']; ?> »</a></em></p>
                      </div>
                    </div>
                  </th></tr></table></th>
                <?php endforeach; ?>
              </tr></tbody></table>

            </td></tr></tbody></table>

          </td>
        </tr>

        <tr>
          <td class="footer-wrap">
            <table align="center" border="0" cellspacing="0" cellpadding="0" style="max-width: 632px; width: 100%;">
              <tbody>
                <tr>
                  <td height="158" style="height: 158px;">
                    <table align="center" class="container footer-container"><tbody><tr><td>
                      <table class="row"><tbody><tr>

                        <th class="footer-column-logo small-12 large-5 columns first"><table><tr><th>
                          <a href="<?php print url('<front>', array('absolute' => TRUE)); ?>">
                            <img src="<?php print $logo_url; ?>" class="footer-logo" width="144" alt="">
                          </a>
                        </th></tr></table></th>

                        <th class="footer-column-address small-12 large-7 columns last"><table><tr><th>
                          <p class="address">
                            225 Varick Street, 7th Floor, New York, NY 10014<br>
                            <a href="mailto:AudubonConnect@audubon.org">AudubonConnect@audubon.org</a>
                          </p>
                        </th></tr></table></th>

                      </tr></tbody></table>
                    </td></tr></tbody></table>
                  </td>
                </tr>
              </tbody>
            </table>

          </td>
        </tr>
      </tbody>
    </table>
    <!-- prevent Gmail on iOS font size manipulation -->
    <div style="display:none; white-space:nowrap; font:15px courier; line-height:0;"> &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </div>
  </body>
</html>
