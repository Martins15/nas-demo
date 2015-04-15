<?php
/**
 * @file
 * event_test_feature.features.uuid_node.inc
 */

/**
 * Implements hook_uuid_features_default_content().
 */
function event_test_feature_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
  'title' => 'test',
  'log' => 'Created by FeedsNodeProcessor',
  'status' => 1,
  'comment' => 0,
  'promote' => 1,
  'sticky' => 0,
  'type' => 'event',
  'language' => 'und',
  'created' => 1429097256,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '1c8c05f5-d3fc-4d19-896f-a6b83c028d39',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>SDGh</p>
',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_event_date' => array(
    'und' => array(
      0 => array(
        'value' => '2015-04-09 14:00:00',
        'value2' => '2015-04-09 14:00:00',
        'timezone' => 'America/New_York',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_event_description' => array(
    'und' => array(
      0 => array(
        'value' => 'test new',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_event_location_help' => array(),
  'field_event_registration' => array(
    'und' => array(
      0 => array(
        'url' => 'http://www.olympicbirdfest.org',
        'title' => NULL,
        'attributes' => array(),
      ),
    ),
  ),
  'field_event_registration_notes' => array(
    'und' => array(
      0 => array(
        'value' => '<p>shxgj</p>
',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_event_type' => array(
    'und' => array(
      0 => array(
        'tid' => '807ac0e7-e41d-44fe-a843-b50a2b899daf',
        'uuid' => '807ac0e7-e41d-44fe-a843-b50a2b899daf',
      ),
    ),
  ),
  'field_geolocation' => array(),
  'field_image' => array(
    'und' => array(
      0 => array(
        'fid' => 51601,
        'filename' => 'images_0.jpg',
        'uri' => 'public://images_0.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => 8574,
        'status' => 1,
        'timestamp' => 1429097256,
        'type' => 'image',
        'uuid' => '',
        'field_file_image_alt_text' => array(),
        'field_file_image_title_text' => array(),
        'field_file_caption' => array(),
        'field_file_credit' => array(),
        'metatags' => array(),
        'metadata' => array(),
        'alt' => NULL,
        'title' => NULL,
        'width' => 246,
        'height' => 205,
        'user_uuid' => '4bf1b159-87cc-4b07-b2fe-bff20b35eed2',
      ),
    ),
  ),
  'field_event_location' => array(
    'und' => array(
      0 => array(
        'lid' => 26,
        'name' => '',
        'street' => '1300 North Fort Christmas Rd',
        'additional' => '',
        'city' => 'Christmas',
        'province' => '',
        'postal_code' => 32709,
        'country' => 'us',
        'latitude' => 28.562047,
        'longitude' => -81.022307,
        'source' => 1,
        'is_primary' => 0,
        'locpick' => array(
          'user_latitude' => 28.562047,
          'user_longitude' => -81.022307,
        ),
        'province_name' => '',
        'country_name' => 'United States',
      ),
    ),
  ),
  'metatags' => array(),
  'panelizer' => array(
    'page_manager' => array(
      'name' => 'node:event:event_panelizer',
    ),
  ),
  'date' => '2015-04-15 07:27:36 -0400',
  'user_uuid' => '4bf1b159-87cc-4b07-b2fe-bff20b35eed2',
);
  $nodes[] = array(
  'title' => 'Testing a National Event',
  'log' => 'Created by FeedsNodeProcessor',
  'status' => 1,
  'comment' => 0,
  'promote' => 1,
  'sticky' => 0,
  'type' => 'event',
  'language' => 'und',
  'created' => 1429097256,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '336fa8f1-bbca-490f-9839-99172de15054',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>test</p>
',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_event_date' => array(
    'und' => array(
      0 => array(
        'value' => '2015-04-04 13:45:00',
        'value2' => '2015-04-04 14:00:00',
        'timezone' => 'America/New_York',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_event_description' => array(),
  'field_event_location_help' => array(),
  'field_event_registration' => array(
    'und' => array(
      0 => array(
        'url' => '',
        'title' => NULL,
        'attributes' => array(),
      ),
    ),
  ),
  'field_event_registration_notes' => array(),
  'field_event_type' => array(
    'und' => array(
      0 => array(
        'tid' => '807ac0e7-e41d-44fe-a843-b50a2b899daf',
        'uuid' => '807ac0e7-e41d-44fe-a843-b50a2b899daf',
      ),
    ),
  ),
  'field_geolocation' => array(),
  'field_image' => array(),
  'field_event_location' => array(
    'und' => array(
      0 => array(
        'lid' => 36,
        'name' => '',
        'street' => '',
        'additional' => '',
        'city' => '',
        'province' => '',
        'postal_code' => '',
        'country' => 'us',
        'latitude' => '0.000000',
        'longitude' => '0.000000',
        'source' => 0,
        'is_primary' => 0,
        'province_name' => '',
        'country_name' => 'United States',
      ),
    ),
  ),
  'metatags' => array(),
  'panelizer' => array(
    'page_manager' => array(
      'name' => 'node:event:event_panelizer',
    ),
  ),
  'date' => '2015-04-15 07:27:36 -0400',
  'user_uuid' => '4bf1b159-87cc-4b07-b2fe-bff20b35eed2',
);
  $nodes[] = array(
  'title' => 'National only event',
  'log' => 'Created by FeedsNodeProcessor',
  'status' => 1,
  'comment' => 0,
  'promote' => 1,
  'sticky' => 0,
  'type' => 'event',
  'language' => 'und',
  'created' => 1429097256,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '3b520092-d85d-4cdd-a9e5-585f85e73473',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>description for national event</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '    ',
      ),
    ),
  ),
  'field_event_date' => array(
    'und' => array(
      0 => array(
        'value' => '2015-04-23 11:00:00',
        'value2' => '2015-04-23 12:00:00',
        'timezone' => 'America/New_York',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_event_description' => array(
    'und' => array(
      0 => array(
        'value' => '<p>subtitle for national event</p>
',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_event_location_help' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Location contact info National</p>
',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_event_registration' => array(
    'und' => array(
      0 => array(
        'url' => 'http://worksdev.prod.acquia-sites.com/',
        'title' => '',
        'attributes' => array(),
      ),
    ),
  ),
  'field_event_registration_notes' => array(
    'und' => array(
      0 => array(
        'value' => '<p>registration info national</p>
',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_event_type' => array(
    'und' => array(
      0 => array(
        'tid' => '429d4b1c-2dc1-41a8-8640-e4905c2b5618',
        'uuid' => '429d4b1c-2dc1-41a8-8640-e4905c2b5618',
      ),
    ),
  ),
  'field_geolocation' => array(),
  'field_image' => array(),
  'field_event_location' => array(
    'und' => array(
      0 => array(
        'lid' => 41,
        'name' => '',
        'street' => 'Alexei Mateevici 87',
        'additional' => '',
        'city' => 'Chișinău',
        'province' => 'DC',
        'postal_code' => '',
        'country' => 'us',
        'latitude' => 47.020257,
        'longitude' => 28.820388,
        'source' => 1,
        'is_primary' => 0,
        'locpick' => array(
          'user_latitude' => 47.020257,
          'user_longitude' => 28.820388,
        ),
        'province_name' => 'District Of Columbia',
        'country_name' => 'United States',
      ),
    ),
  ),
  'metatags' => array(),
  'panelizer' => array(
    'page_manager' => array(
      'name' => 'node:event:event_panelizer',
    ),
  ),
  'date' => '2015-04-15 07:27:36 -0400',
  'user_uuid' => '4bf1b159-87cc-4b07-b2fe-bff20b35eed2',
);
  $nodes[] = array(
  'title' => 'Test event',
  'log' => 'Created by FeedsNodeProcessor',
  'status' => 1,
  'comment' => 0,
  'promote' => 1,
  'sticky' => 0,
  'type' => 'event',
  'language' => 'und',
  'created' => 1429097256,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '4f0b01c9-6b38-420d-9750-a71fda85866d',
  'body' => array(),
  'field_event_date' => array(
    'und' => array(
      0 => array(
        'value' => '2015-04-08 17:15:00',
        'value2' => '2015-04-08 17:15:00',
        'timezone' => 'America/New_York',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_event_description' => array(),
  'field_event_location_help' => array(),
  'field_event_registration' => array(
    'und' => array(
      0 => array(
        'url' => '',
        'title' => NULL,
        'attributes' => array(),
      ),
    ),
  ),
  'field_event_registration_notes' => array(),
  'field_event_type' => array(
    'und' => array(
      0 => array(
        'tid' => '807ac0e7-e41d-44fe-a843-b50a2b899daf',
        'uuid' => '807ac0e7-e41d-44fe-a843-b50a2b899daf',
      ),
    ),
  ),
  'field_geolocation' => array(),
  'field_image' => array(),
  'field_event_location' => array(
    'und' => array(
      0 => array(
        'lid' => 21,
        'name' => '',
        'street' => '',
        'additional' => '',
        'city' => '',
        'province' => 'AK',
        'postal_code' => '',
        'country' => 'us',
        'latitude' => '0.000000',
        'longitude' => '0.000000',
        'source' => 0,
        'is_primary' => 0,
        'province_name' => 'Alaska',
        'country_name' => 'United States',
      ),
    ),
  ),
  'metatags' => array(),
  'panelizer' => array(
    'page_manager' => array(
      'name' => 'node:event:event_panelizer',
    ),
  ),
  'date' => '2015-04-15 07:27:36 -0400',
  'user_uuid' => '4bf1b159-87cc-4b07-b2fe-bff20b35eed2',
);
  $nodes[] = array(
  'title' => 'Audubon Pennsylvania Assembly, "Healthy Forests for Birds and People"',
  'log' => 'Created by FeedsNodeProcessor',
  'status' => 1,
  'comment' => 0,
  'promote' => 1,
  'sticky' => 0,
  'type' => 'event',
  'language' => 'und',
  'created' => 1429097256,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '5f3256f7-773d-4223-8b2b-cc4f4cd5dbbc',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Audubon-PA is pleased to be coordinating an Audubon Assembly in Wellsboro, PA (just south of Corning, NY off Route 15) this September 19 &amp; 20. Contact <a href="mailto:pzeph@audubon.org ?subject=Audubon%20PA%20Assembly">Paul Zeph</a>: or 717-574-6668 with any questions.</p>
',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_event_date' => array(
    'und' => array(
      0 => array(
        'value' => '2014-09-19 04:00:00',
        'value2' => '2014-09-21 04:00:00',
        'timezone' => 'America/New_York',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_event_description' => array(),
  'field_event_location_help' => array(),
  'field_event_registration' => array(
    'und' => array(
      0 => array(
        'url' => '',
        'title' => NULL,
        'attributes' => array(),
      ),
    ),
  ),
  'field_event_registration_notes' => array(),
  'field_event_type' => array(
    'und' => array(
      0 => array(
        'tid' => '807ac0e7-e41d-44fe-a843-b50a2b899daf',
        'uuid' => '807ac0e7-e41d-44fe-a843-b50a2b899daf',
      ),
    ),
  ),
  'field_geolocation' => array(),
  'field_image' => array(
    'und' => array(
      0 => array(
        'fid' => 51596,
        'filename' => 'images_4.jpg',
        'uri' => 'public://images_4.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => 8574,
        'status' => 1,
        'timestamp' => 1429097256,
        'type' => 'image',
        'uuid' => '',
        'field_file_image_alt_text' => array(),
        'field_file_image_title_text' => array(),
        'field_file_caption' => array(),
        'field_file_credit' => array(),
        'metatags' => array(),
        'metadata' => array(),
        'alt' => NULL,
        'title' => NULL,
        'width' => 246,
        'height' => 205,
        'user_uuid' => '4bf1b159-87cc-4b07-b2fe-bff20b35eed2',
      ),
    ),
  ),
  'field_event_location' => array(
    'und' => array(
      0 => array(
        'lid' => 16,
        'name' => '',
        'street' => '',
        'additional' => '',
        'city' => 'Wellsboro',
        'province' => 'PA',
        'postal_code' => '',
        'country' => 'us',
        'latitude' => '0.000000',
        'longitude' => '0.000000',
        'source' => 0,
        'is_primary' => 0,
        'province_name' => 'Pennsylvania',
        'country_name' => 'United States',
      ),
    ),
  ),
  'metatags' => array(),
  'panelizer' => array(
    'page_manager' => array(
      'name' => 'node:event:event_panelizer',
    ),
  ),
  'date' => '2015-04-15 07:27:36 -0400',
  'user_uuid' => '4bf1b159-87cc-4b07-b2fe-bff20b35eed2',
);
  $nodes[] = array(
  'title' => 'Tucson Bird & Wildlife Festival',
  'log' => 'Created by FeedsNodeProcessor',
  'status' => 1,
  'comment' => 0,
  'promote' => 1,
  'sticky' => 0,
  'type' => 'event',
  'language' => 'und',
  'created' => 1429097256,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '73ca14fe-167b-4477-bd80-170259bb2479',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>We invite you to explore and enjoy the beautiful and fascinating Sonoran Desert and Sky Islands. Join the fun at the Fifth Annual Tucson Bird &amp; Wildlife Festival. Get to know our friendly local birding and conservation community and the dazzling array of watchable wildlife experiences accessible from Tucson!</p>
',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_event_date' => array(
    'und' => array(
      0 => array(
        'value' => '2015-08-12 04:00:00',
        'value2' => '2015-08-16 04:00:00',
        'timezone' => 'America/New_York',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_event_description' => array(
    'und' => array(
      0 => array(
        'value' => 'EXPERIENCE SOUTHEAST ARIZONA BIRDING AT ITS BEST',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_event_location_help' => array(
    'und' => array(
      0 => array(
        'value' => '<p>&nbsp;</p>

<p>For festival questions, please email festival@tucsonaudubon.org</p>
',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_event_registration' => array(
    'und' => array(
      0 => array(
        'url' => 'https://www.z2systems.com/np/clients/tas/eventRegistration.jsp?event=1126&',
        'title' => NULL,
        'attributes' => array(),
      ),
    ),
  ),
  'field_event_registration_notes' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Early Bird Group Registration Discount!&nbsp;</p>

<p>Attend the Festival with your Birding Buddies &amp; SAVE! Parties of 6 or more registering together before May 1 get 10% off! To access the Early Bird Group Discount, your group must register before May 1 by contacting the festival staff directly at 520-209-1802.</p>
',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_event_type' => array(
    'und' => array(
      0 => array(
        'tid' => '8a712213-2386-4ac4-a80e-e281178da2f5',
        'uuid' => '8a712213-2386-4ac4-a80e-e281178da2f5',
      ),
    ),
  ),
  'field_geolocation' => array(),
  'field_image' => array(
    'und' => array(
      0 => array(
        'fid' => 51581,
        'filename' => 'riverpark_map.jpg',
        'uri' => 'public://riverpark_map.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => 12894,
        'status' => 1,
        'timestamp' => 1429097256,
        'type' => 'image',
        'uuid' => '',
        'field_file_image_alt_text' => array(),
        'field_file_image_title_text' => array(),
        'field_file_caption' => array(),
        'field_file_credit' => array(),
        'metatags' => array(),
        'metadata' => array(),
        'alt' => NULL,
        'title' => NULL,
        'width' => 216,
        'height' => 175,
        'user_uuid' => '4bf1b159-87cc-4b07-b2fe-bff20b35eed2',
      ),
    ),
  ),
  'field_event_location' => array(
    'und' => array(
      0 => array(
        'lid' => 1,
        'name' => '',
        'street' => '350 South Freeway Tucson, AZ, From I-10, take Congress Street exit 258',
        'additional' => '',
        'city' => 'Tucson',
        'province' => 'AZ',
        'postal_code' => 85745,
        'country' => 'us',
        'latitude' => 32.216208,
        'longitude' => -110.981066,
        'source' => 1,
        'is_primary' => 0,
        'locpick' => array(
          'user_latitude' => 32.216208,
          'user_longitude' => -110.981066,
        ),
        'province_name' => 'Arizona',
        'country_name' => 'United States',
      ),
    ),
  ),
  'metatags' => array(),
  'panelizer' => array(
    'page_manager' => array(
      'name' => 'node:event:event_panelizer',
    ),
  ),
  'date' => '2015-04-15 07:27:36 -0400',
  'user_uuid' => '4bf1b159-87cc-4b07-b2fe-bff20b35eed2',
);
  $nodes[] = array(
  'title' => 'Both National And works',
  'log' => 'Created by FeedsNodeProcessor',
  'status' => 1,
  'comment' => 0,
  'promote' => 1,
  'sticky' => 0,
  'type' => 'event',
  'language' => 'und',
  'created' => 1429097256,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '7afe0e17-ba26-436c-9776-b45fd81595d8',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>description for National and Works</p>

<p>&nbsp;</p>
',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_event_date' => array(
    'und' => array(
      0 => array(
        'value' => '2015-04-15 04:00:00',
        'value2' => '2015-04-15 04:00:00',
        'timezone' => 'America/New_York',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_event_description' => array(
    'und' => array(
      0 => array(
        'value' => 'subtitle for national and works',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_event_location_help' => array(
    'und' => array(
      0 => array(
        'value' => '<p>location contact info for National and works</p>
',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_event_registration' => array(
    'und' => array(
      0 => array(
        'url' => 'http://worksdev.prod.acquia-sites.com/groups/national-only-event',
        'title' => NULL,
        'attributes' => array(),
      ),
    ),
  ),
  'field_event_registration_notes' => array(
    'und' => array(
      0 => array(
        'value' => '<p>registrantion info for national and works</p>
',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_event_type' => array(
    'und' => array(
      0 => array(
        'tid' => '3199c874-065e-44a6-83d9-847d965e0152',
        'uuid' => '3199c874-065e-44a6-83d9-847d965e0152',
      ),
      1 => array(
        'tid' => '429d4b1c-2dc1-41a8-8640-e4905c2b5618',
        'uuid' => '429d4b1c-2dc1-41a8-8640-e4905c2b5618',
      ),
      2 => array(
        'tid' => '9b8a4c01-4835-4b47-877e-7e2dc33ac7fe',
        'uuid' => '9b8a4c01-4835-4b47-877e-7e2dc33ac7fe',
      ),
    ),
  ),
  'field_geolocation' => array(),
  'field_image' => array(),
  'field_event_location' => array(
    'und' => array(
      0 => array(
        'lid' => 46,
        'name' => '',
        'street' => '1203 19th St. NW, 3rd Floor',
        'additional' => '',
        'city' => 'Washington',
        'province' => 'DC',
        'postal_code' => 20036,
        'country' => 'us',
        'latitude' => 38.905971,
        'longitude' => -77.043208,
        'source' => 1,
        'is_primary' => 0,
        'locpick' => array(
          'user_latitude' => 38.905971,
          'user_longitude' => -77.043208,
        ),
        'province_name' => 'District Of Columbia',
        'country_name' => 'United States',
      ),
    ),
  ),
  'metatags' => array(),
  'panelizer' => array(
    'page_manager' => array(
      'name' => 'node:event:event_panelizer',
    ),
  ),
  'date' => '2015-04-15 07:27:36 -0400',
  'user_uuid' => '4bf1b159-87cc-4b07-b2fe-bff20b35eed2',
);
  $nodes[] = array(
  'title' => 'Monthly Bird Walks',
  'log' => 'Created by FeedsNodeProcessor',
  'status' => 1,
  'comment' => 0,
  'promote' => 1,
  'sticky' => 0,
  'type' => 'event',
  'language' => 'und',
  'created' => 1429097256,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '8509cb88-85c5-404b-b0bf-a3537e8c0edf',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, consequat vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus. Phasellus viverra nulla ut metus varius laoreet. Quisque rutrum. Aenean imperdiet. Etiam ultricies nisi vel augue. Curabitur ullamcorper ultricies nisi. Nam eget dui. Etiam rhoncus. Maecenas tempus, tellus eget condimentum rhoncus, sem quam semper libero, sit amet adipiscing sem neque sed ipsum. Nam quam nunc, blandit vel, luctus pulvinar, hendrerit id, lorem. Maecenas nec odio et ante tincidunt tempus. Donec vitae sapien ut libero venenatis faucibus. Nullam quis ante. Etiam sit amet orci eget eros faucibus tincidunt. Duis leo. Sed fringilla mauris sit amet nibh. Donec sodales sagittis magna. Sed consequat, leo eget bibendum sodales, augue velit cursus nunc,</p>
',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_event_date' => array(
    'und' => array(
      0 => array(
        'value' => '2015-04-23 04:00:00',
        'value2' => '2015-04-23 04:00:00',
        'timezone' => 'America/New_York',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_event_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Join us for monthly bird walks on the Sanctuary!',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_event_location_help' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Meet at our iron gate entrance. &nbsp;Contact&nbsp;<a href="mailto:kwilcox@audubon.org">Kerry Wilcox</a>&nbsp;for more information</p>
',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_event_registration' => array(
    'und' => array(
      0 => array(
        'url' => 'http://richardsonbay.audubon.org/',
        'title' => NULL,
        'attributes' => array(),
      ),
    ),
  ),
  'field_event_registration_notes' => array(
    'und' => array(
      0 => array(
        'value' => '<p>PLEASE RSVP prior to the bird walk so we know to expect you! &nbsp;</p>
',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_event_type' => array(
    'und' => array(
      0 => array(
        'tid' => '5aff60e6-14ca-411e-9191-aace8e49fac2',
        'uuid' => '5aff60e6-14ca-411e-9191-aace8e49fac2',
      ),
    ),
  ),
  'field_geolocation' => array(),
  'field_image' => array(
    'und' => array(
      0 => array(
        'fid' => 51591,
        'filename' => 'volunteer_training_fall_2013.jpg',
        'uri' => 'public://volunteer_training_fall_2013.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => 66311,
        'status' => 1,
        'timestamp' => 1429097256,
        'type' => 'image',
        'uuid' => '',
        'field_file_image_alt_text' => array(),
        'field_file_image_title_text' => array(),
        'field_file_caption' => array(),
        'field_file_credit' => array(),
        'metatags' => array(),
        'metadata' => array(),
        'alt' => NULL,
        'title' => NULL,
        'width' => 250,
        'height' => 188,
        'user_uuid' => '4bf1b159-87cc-4b07-b2fe-bff20b35eed2',
      ),
    ),
  ),
  'field_event_location' => array(
    'und' => array(
      0 => array(
        'lid' => 11,
        'name' => '',
        'street' => 'Richardson Bay Audubon Center & Sanctuary',
        'additional' => '',
        'city' => 'Tiburon',
        'province' => 'CA',
        'postal_code' => 94920,
        'country' => 'us',
        'latitude' => 37.894471,
        'longitude' => -122.496784,
        'source' => 1,
        'is_primary' => 0,
        'locpick' => array(
          'user_latitude' => 37.894471,
          'user_longitude' => -122.496784,
        ),
        'province_name' => 'California',
        'country_name' => 'United States',
      ),
    ),
  ),
  'metatags' => array(),
  'panelizer' => array(
    'page_manager' => array(
      'name' => 'node:event:event_panelizer',
    ),
  ),
  'date' => '2015-04-15 07:27:36 -0400',
  'user_uuid' => '4bf1b159-87cc-4b07-b2fe-bff20b35eed2',
);
  $nodes[] = array(
  'title' => 'Perry Lakes and environs',
  'log' => 'Created by FeedsNodeProcessor',
  'status' => 1,
  'comment' => 0,
  'promote' => 1,
  'sticky' => 0,
  'type' => 'event',
  'language' => 'und',
  'created' => 1429097256,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '955926f2-9f8c-4fd6-b756-ea112d2d1de9',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, consequat vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus.</p>
',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_event_date' => array(
    'und' => array(
      0 => array(
        'value' => '2015-03-21 04:00:00',
        'value2' => '2015-03-21 04:00:00',
        'timezone' => 'America/New_York',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_event_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Full-day Trip',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_event_location_help' => array(
    'und' => array(
      0 => array(
        'value' => '<p>DEPARTURE TIME: 7 A.M.</p>

<p>TRIP LEADERS: Dr. Ken Marion</p>

<p>MEETING PLACE: Galleria McDonald’s</p>
',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_event_registration' => array(
    'und' => array(
      0 => array(
        'url' => 'http://alabamabirdingtrails.com/sites/perry-lakes-park-state-fish-hatcheries/',
        'title' => NULL,
        'attributes' => array(),
      ),
    ),
  ),
  'field_event_registration_notes' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Bring snacks and picnic lunch</p>
',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_event_type' => array(
    'und' => array(
      0 => array(
        'tid' => '5aff60e6-14ca-411e-9191-aace8e49fac2',
        'uuid' => '5aff60e6-14ca-411e-9191-aace8e49fac2',
      ),
    ),
  ),
  'field_geolocation' => array(),
  'field_image' => array(
    'und' => array(
      0 => array(
        'fid' => 51586,
        'filename' => 'Birders_copy.jpg',
        'uri' => 'public://Birders_copy.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => 1614742,
        'status' => 1,
        'timestamp' => 1429097256,
        'type' => 'image',
        'uuid' => '',
        'field_file_image_alt_text' => array(),
        'field_file_image_title_text' => array(),
        'field_file_caption' => array(),
        'field_file_credit' => array(),
        'metatags' => array(),
        'metadata' => array(),
        'alt' => NULL,
        'title' => NULL,
        'width' => 3264,
        'height' => 2448,
        'user_uuid' => '4bf1b159-87cc-4b07-b2fe-bff20b35eed2',
      ),
    ),
  ),
  'field_event_location' => array(
    'und' => array(
      0 => array(
        'lid' => 6,
        'name' => '',
        'street' => 'Birmingham Audubon - 200 19th St. N. - Birmingham, AL 35203',
        'additional' => '',
        'city' => 'Birmingham',
        'province' => 'AL',
        'postal_code' => 35203,
        'country' => 'us',
        'latitude' => 33.517877,
        'longitude' => -86.809481,
        'source' => 1,
        'is_primary' => 0,
        'locpick' => array(
          'user_latitude' => 33.517877,
          'user_longitude' => -86.809481,
        ),
        'province_name' => 'Alabama',
        'country_name' => 'United States',
      ),
    ),
  ),
  'metatags' => array(),
  'panelizer' => array(
    'page_manager' => array(
      'name' => 'node:event:event_panelizer',
    ),
  ),
  'date' => '2015-04-15 07:27:36 -0400',
  'user_uuid' => '4bf1b159-87cc-4b07-b2fe-bff20b35eed2',
);
  $nodes[] = array(
  'title' => 'Exploring Our Center & Sanctuary',
  'log' => 'Created by FeedsNodeProcessor',
  'status' => 1,
  'comment' => 0,
  'promote' => 1,
  'sticky' => 0,
  'type' => 'event',
  'language' => 'und',
  'created' => 1429097256,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'b6145146-9e9e-40c6-9db6-cd1e91d84a1e',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Teachers, home school groups, troop leaders, families, children, teens, and everyone inbetween will find the Richardson Bay Audubon Center &amp; Sanctuary a wonderful place to learn and connect with the natural world around us.</p>
',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_event_date' => array(
    'und' => array(
      0 => array(
        'value' => '2015-04-03 14:00:00',
        'value2' => '2015-04-03 22:00:00',
        'timezone' => 'America/New_York',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_event_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Teachers, home school groups, troop leaders, families, children, teens, and everyone inbetween will find the Richardson Bay Audubon Center & Sanctuary a wonderful place to learn and connect with the natural world around us.',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_event_location_help' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Call us for more details:&nbsp;415-388-2524</p>
',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_event_registration' => array(
    'und' => array(
      0 => array(
        'url' => 'http://richardsonbay.audubon.org/',
        'title' => NULL,
        'attributes' => array(),
      ),
    ),
  ),
  'field_event_registration_notes' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Expedition Camp runs 9am - 3pm, $385/wk</p>
',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_event_type' => array(
    'und' => array(
      0 => array(
        'tid' => '429d4b1c-2dc1-41a8-8640-e4905c2b5618',
        'uuid' => '429d4b1c-2dc1-41a8-8640-e4905c2b5618',
      ),
    ),
  ),
  'field_geolocation' => array(),
  'field_image' => array(),
  'field_event_location' => array(
    'und' => array(
      0 => array(
        'lid' => 31,
        'name' => '',
        'street' => '376 Greenwood Beach Road',
        'additional' => '',
        'city' => 'Tiburon',
        'province' => 'CA',
        'postal_code' => 94920,
        'country' => 'us',
        'latitude' => 37.894519,
        'longitude' => -122.495716,
        'source' => 1,
        'is_primary' => 0,
        'locpick' => array(
          'user_latitude' => 37.894519,
          'user_longitude' => -122.495716,
        ),
        'province_name' => 'California',
        'country_name' => 'United States',
      ),
    ),
  ),
  'metatags' => array(),
  'panelizer' => array(
    'page_manager' => array(
      'name' => 'node:event:event_panelizer',
    ),
  ),
  'date' => '2015-04-15 07:27:36 -0400',
  'user_uuid' => '4bf1b159-87cc-4b07-b2fe-bff20b35eed2',
);
  return $nodes;
}
