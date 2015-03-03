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
define('GEOIP_DEBUG', FALSE);

// Get client IP. Can be in $_GET query or server env.
$ip = !empty($_GET['ip']) ? $_GET['ip'] :
  getenv('HTTP_CLIENT_IP') ?:
  getenv('HTTP_X_FORWARDED_FOR') ?:
  getenv('HTTP_X_FORWARDED') ?:
  getenv('HTTP_FORWARDED_FOR') ?:
  getenv('HTTP_FORWARDED') ?:
  getenv('REMOTE_ADDR');

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
