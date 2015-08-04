<?php

/**
 * @file
 * Per domain settings.
 */

if (strpos($_SERVER['HTTP_HOST'], 'nas.192.168.56.132.xip.io') !== FALSE) {
  // Base domain cookie.
  $cookie_domain = '.nas.192.168.56.132.xip.io';

  // Local environment.
  $conf['language_domains'] = array(
    'es' => 'es.nas.192.168.56.132.xip.io',
    'en' => 'nas.192.168.56.132.xip.io',
  );
}
elseif (strpos($_SERVER['HTTP_HOST'], 'nas.wearepropeople.md') !== FALSE) {

  // Base domain cookie.
  $cookie_domain = '.nas.wearepropeople.md';

  // Build environment.
  $conf['language_domains'] = array(
    'es' => 'es.nas.wearepropeople.md',
    'en' => 'nas.wearepropeople.md',
  );
}
elseif (strpos($_SERVER['HTTP_HOST'], 'audubon.org') !== FALSE) {

  // Base domain cookie.
  $cookie_domain = '.audubon.org';

  // Build environment.
  $conf['language_domains'] = array(
    'es' => 'es.audubon.org',
    'en' => 'audubon.org',
  );
}
