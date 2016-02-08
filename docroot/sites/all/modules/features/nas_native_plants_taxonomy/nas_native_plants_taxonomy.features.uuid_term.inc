<?php
/**
 * @file
 * nas_native_plants_taxonomy.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function nas_native_plants_taxonomy_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Shrubs',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 8,
    'uuid' => '13f3fe81-2a3b-4de6-af85-32810597f3e8',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'native_plant_attributes',
    'field_np_attr_color' => array(
      'und' => array(
        0 => array(
          'rgb' => '#465d2c',
        ),
      ),
    ),
    'field_np_attr_machine_attributes' => array(
      'und' => array(
        0 => array(
          'value' => 'Shrub',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Trees',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 9,
    'uuid' => '161c8520-42d1-4c6b-8ec4-055c9120f8b8',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'native_plant_attributes',
    'field_np_attr_color' => array(
      'und' => array(
        0 => array(
          'rgb' => '#b55500',
        ),
      ),
    ),
    'field_np_attr_machine_attributes' => array(
      'und' => array(
        0 => array(
          'value' => 'Tree',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Succulent',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => '26147cf4-cb74-4cc5-9166-133c3a966834',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'native_plant_attributes',
    'field_np_attr_color' => array(
      'und' => array(
        0 => array(
          'rgb' => '#99c863',
        ),
      ),
    ),
    'field_np_attr_machine_attributes' => array(
      'und' => array(
        0 => array(
          'value' => 'Succulent',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Grasses',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => '2fbc8ee0-9ce4-4f2c-8cc2-c3ea3860965d',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'native_plant_attributes',
    'field_np_attr_color' => array(
      'und' => array(
        0 => array(
          'rgb' => '#417505',
        ),
      ),
    ),
    'field_np_attr_machine_attributes' => array(
      'und' => array(
        0 => array(
          'value' => 'GrassGrasslike',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Fruit',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '66b04bc8-2a19-4a9d-b4c9-1a872fc9fac5',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'native_plant_attributes',
    'field_np_attr_color' => array(
      'und' => array(
        0 => array(
          'rgb' => '#ff7b16',
        ),
      ),
    ),
    'field_np_attr_machine_attributes' => array(
      'und' => array(
        0 => array(
          'value' => 'FleshyFruits',
        ),
        1 => array(
          'value' => 'FruitVegetation',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Butterflies',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '6a2987cf-5dcf-41b7-9ee7-0c51bd8dd833',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'native_plant_attributes',
    'field_np_attr_color' => array(
      'und' => array(
        0 => array(
          'rgb' => '#f99090',
        ),
      ),
    ),
    'field_np_attr_machine_attributes' => array(
      'und' => array(
        0 => array(
          'value' => 'ButterflyTallamyPlant',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Forbs',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => '8837d39a-8a5a-4129-92b6-576de9c75d9f',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'native_plant_attributes',
    'field_np_attr_color' => array(
      'und' => array(
        0 => array(
          'rgb' => '#2a91dd',
        ),
      ),
    ),
    'field_np_attr_machine_attributes' => array(
      'und' => array(
        0 => array(
          'value' => 'Forbs',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Nuts/Seeds',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '920ae4b1-93b4-4927-88a9-cc1641c8c408',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'native_plant_attributes',
    'field_np_attr_color' => array(
      'und' => array(
        0 => array(
          'rgb' => '#d3874c',
        ),
      ),
    ),
    'field_np_attr_machine_attributes' => array(
      'und' => array(
        0 => array(
          'value' => 'NutsSeeds',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Nectar',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a93260cd-9361-4f41-8871-596444f5c56c',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'native_plant_attributes',
    'field_np_attr_color' => array(
      'und' => array(
        0 => array(
          'rgb' => '#cd1818',
        ),
      ),
    ),
    'field_np_attr_machine_attributes' => array(
      'und' => array(
        0 => array(
          'value' => 'HummingBirdNectar',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Caterpillars',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'bfe08f6d-0081-4aea-9999-fca06812bae4',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'native_plant_attributes',
    'field_np_attr_color' => array(
      'und' => array(
        0 => array(
          'rgb' => '#e8b939',
        ),
      ),
    ),
    'field_np_attr_machine_attributes' => array(
      'und' => array(
        0 => array(
          'value' => 'ButterflyTallamyPlant',
        ),
      ),
    ),
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Vines',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 10,
    'uuid' => 'cac396a5-ca66-4a94-a63d-8f77440f7604',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'native_plant_attributes',
    'field_np_attr_color' => array(
      'und' => array(
        0 => array(
          'rgb' => '#9ab17f',
        ),
      ),
    ),
    'field_np_attr_machine_attributes' => array(
      'und' => array(
        0 => array(
          'value' => 'Vine',
        ),
      ),
    ),
    'metatags' => array(),
  );
  return $terms;
}
