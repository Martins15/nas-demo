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
  <li><?php print l(t('Subscriber Services'), 'https://ssl.palmcoastd.com/pcd/app/index.cfm?iXz=B46E00C3B4311C08FB08C4F500E5D85F'); ?></li>
  <li><?php print $past_issues_link; ?></li>
</ul>