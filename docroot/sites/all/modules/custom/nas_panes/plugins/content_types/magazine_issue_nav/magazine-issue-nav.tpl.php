<?php
/**
 * @file
 * Template to custom pane Magazine Issue. Featured Articles.
 *
 * Available variables:
 *  $past_issues_link - link to past issues.
 */
?>

<ul class="section-nav inline-list mag-issue-nav">
  <li><?php print l(t('Subscriber Services'), 'https://ssl.palmcoastd.com/pcd/app/index.cfm?imagid=10102&ipage=membership'); ?></li>
  <li><?php print $past_issues_link; ?></li>
</ul>