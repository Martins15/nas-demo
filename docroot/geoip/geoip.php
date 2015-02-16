<?php
/**
 * @file
 * Returns user location by IP.
 */

require_once 'vendor/autoload.php';
use MaxMind\Db\Reader;

// Disabled cache for this page.
header('Content-Type: application/json; charset=utf-8');
header('Pragma: no-cache');
header('Cache-Control: private, no-cache, no-store, max-age=0, must-revalidate, proxy-revalidate');
header('Expires: 0');

define('GEOIP_DATABASE', '../sites/default/files/GeoLite2-City.mmdb');

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
  if (empty($response)) {
    $response = array(
      'code' => 0,
      'message' => 'Location is not found',
    );
  }
  echo json_encode($response);
  $reader->close();
}
catch (Exception $e) {
  echo json_encode(array('code' => $e->getCode(), 'message' => $e->getMessage()));
}
