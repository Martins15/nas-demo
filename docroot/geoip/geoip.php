<?php
/**
 * @file
 * Returns user location by IP.
 */

require_once 'vendor/autoload.php';
use MaxMind\Db\Reader;

// Disabled cache for this page.
header('Content-Type: text/plain; charset=utf-8');
header('Pragma: no-cache');
header('Cache-Control: private, no-cache, no-store, max-age=0, must-revalidate, proxy-revalidate');
header('Expires: 0');

define('GEOIP_DATABASE', '../sites/default/files/GeoLite2-City.mmdb');
define('DRUPAL_SETTINGS', '../sites/default/settings.php');
define('GEOIP_DEBUG', FALSE);

$conf = array();
if (file_exists(DRUPAL_SETTINGS)) {
  include_once DRUPAL_SETTINGS;
}

// Get client IP. Can be in $_GET query or server env.
$ip = !empty($_GET['ip']) ? $_GET['ip'] : ip_address($conf);

try {
  if (!file_exists(__DIR__ . '/' . GEOIP_DATABASE)) {
    throw new Exception('Database file not found.');
  }

  $reader = new Reader(__DIR__ . '/' . GEOIP_DATABASE);
  $response = $reader->get($ip);
  // Return only iso_code.
  if (!empty($response) && !empty($response['subdivisions'][0]['iso_code'])) {
    echo $response['subdivisions'][0]['iso_code'];
  }
  elseif (GEOIP_DEBUG || !empty($_GET['debug'])) {
    echo 'Location is not found';
  }
  $reader->close();
}
catch (Exception $e) {
  if (GEOIP_DEBUG || !empty($_GET['debug'])) {
    echo $e->getMessage();
  }
}

/**
 * Returns user IP based on conf.
 */
function ip_address($conf) {
  $ip_address = $_SERVER['REMOTE_ADDR'];
  if (!empty($conf['reverse_proxy_addresses'])) {
    if (!empty($_SERVER['HTTP_X_FORWARDED_FOR'])) {
      // Turn XFF header into an array.
      $ips = explode(',', $_SERVER['HTTP_X_FORWARDED_FOR']);
      // Trim the forwarded IPs; they may have been delimited by commas and spaces.
      $ips = array_map('trim', $ips);
      // Tack direct client IP onto end of forwarded array.
      $ips[] = $ip_address;

      $ips = array_reverse($ips);
      foreach ($ips as $ip) {
        if (strpos($ip, '10.') !== 0) {
          // We get first non 10. ip.
          return $ip;
        }
      }
    }
  }

  return $ip_address;
}
