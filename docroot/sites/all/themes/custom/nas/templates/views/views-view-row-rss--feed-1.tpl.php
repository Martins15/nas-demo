<?php

/**
 * @file
 * Default view template to display a item in an RSS feed.
 *
 * @ingroup views_templates
 */
?>
  <item>
    <title><?php print $title; ?></title>
    <link><?php print $link; ?></link>
    <guid isPermaLink="false"><?php print $guid; ?></guid>
    <?php if (!empty($author)): ?>
      <?php if ($facebook_rss): ?>
        <author><?php print $author; ?></author>
      <?php else: ?>
        <dc:creator><?php print $author; ?></dc:creator>
      <?php endif; ?>
    <?php endif; ?>
    <pubDate><?php print $pub_date; ?></pubDate>
    <?php foreach ($categories as $category): ?>
      <category><?php print $category; ?></category>
    <?php endforeach; ?>
    <description><?php print $description; ?></description>
    <?php if (!empty($content)): ?>
      <content:encoded><![CDATA[<?php print $content; ?>]]></content:encoded>
    <?php endif; ?>
  </item>
