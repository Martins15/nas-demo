<?php
/**
 * @file
 * Administration pages for the NAS Master Native Plants module.
 */

/**
 * Administration settings form.
 */
function nas_master_native_plants_settings($form, &$form_state) {
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Create taxonomy terms'),
  );

  return $form;
}

/**
 * Submit callback for nas_master_native_plants_settings.
 */
function nas_master_native_plants_settings_submit($form, &$form_state) {
  global $user;
  $terms = _nas_master_native_plants_taxonomy_terms();

  foreach ($terms as $voc_machine_name => $voc_term_values) {
    $vocabulary = taxonomy_vocabulary_machine_name_load($voc_machine_name);
    if (taxonomy_get_tree($vocabulary->vid)) {
      continue;
    }
    foreach ($voc_term_values as $values) {
      $term = new stdClass();
      $term->vid = $vocabulary->vid;
      $term->vocabulary_machine_name = $voc_machine_name;
      $term->name = $values['name'];
      $term->description = '';
      $term->format = 'plain_text';
      $term->field_np_attr_machine_attributes[LANGUAGE_NONE] = array();
      foreach ($values['attributes'] as $attribute) {
        $term->field_np_attr_machine_attributes[LANGUAGE_NONE][] = array(
          'value' => $attribute,
        );
      }
      if (isset($values['color'])) {
        $term->field_np_attr_color[LANGUAGE_NONE][]['rgb'] = '#' . $values['color'];
      }
      if (isset($values['image'])) {
        $image_path = drupal_get_path('module', 'nas_master_native_plants') . '/sibleys/' . $values['image'];
        $source = new stdClass();
        $source->uri = $image_path;
        $source->uid = $user->uid;
        $source->filemime = 'image/' . pathinfo($image_path, PATHINFO_EXTENSION);
        $source->filename = basename($image_path);

        $destination_dir = file_default_scheme() . '://np_bird_types';
        file_prepare_directory($destination_dir, FILE_CREATE_DIRECTORY);
        $destination = $destination_dir . '/' . basename($image_path);

        if ($file = file_copy($source, $destination)) {
          $term->field_np_bird_type_image[LANGUAGE_NONE][] = (array) $file;
        }
      }
      taxonomy_term_save($term);
    }
  }
}

/**
 * Native Plants taxonomy terms.
 */
function _nas_master_native_plants_taxonomy_terms() {
  $attributes = array(
    array(
      'name' => 'Nectar',
      'attributes' => array(
        'HummingBirdNectar',
      ),
      'color' => 'cd1818',
    ),
    array(
      'name' => 'Butterflies',
      'attributes' => array(
        'ButterflyTallamyPlant',
      ),
      'color' => 'f99090',
    ),
    array(
      'name' => 'Caterpillars',
      'attributes' => array(
        'ButterflyTallamyPlant',
      ),
      'color' => 'e8b939',
    ),
    array(
      'name' => 'Fruit',
      'attributes' => array(
        'FleshyFruits',
        'FruitVegetation',
      ),
      'color' => 'ff7b16',
    ),
    array(
      'name' => 'Nuts/Seeds',
      'attributes' => array(
        'NutsSeeds',
      ),
      'color' => 'd3874c',
    ),
    array(
      'name' => 'Forbs',
      'attributes' => array(
        'Forbs',
      ),
      'color' => '2a91dd',
    ),
    array(
      'name' => 'Grasses',
      'attributes' => array(
        'GrassGrasslike',
      ),
      'color' => '417505',
    ),
    array(
      'name' => 'Succulents',
      'attributes' => array(
        'Succulent',
      ),
      'color' => '99c863',
    ),
    array(
      'name' => 'Shrubs',
      'attributes' => array(
        'Shrub',
      ),
      'color' => '465d2c',
    ),
    array(
      'name' => 'Trees',
      'attributes' => array(
        'Tree',
      ),
      'color' => 'b55500',
    ),
    array(
      'name' => 'Vines',
      'attributes' => array(
        'Vine',
      ),
      'color' => '9ab17f',
    ),
  );
  $bird_types = array(
    array(
      'name' => 'Finches',
      'attributes' => array(
        'NutsSeeds',
      ),
      'image' => '4995_Sibl_9780307957900_art_r1.jpg',
    ),
    array(
      'name' => 'Chickadees & Titmice',
      'attributes' => array(
        'NutsSeeds',
      ),
      'image' => '4464_Sibl_9780307957900_art_r1.jpg',
    ),
    array(
      'name' => 'Sparrows',
      'attributes' => array(
        'NutsSeeds',
      ),
      'image' => '6532_Sibl_9780307957900_art_r1.jpg',
    ),
    array(
      'name' => 'Cardinals',
      'attributes' => array(
        'NutsSeeds',
      ),
      'image' => '4387_Sibl_9780307957900_art_r1.jpg',
    ),
    array(
      'name' => 'Woodpeckers',
      'attributes' => array(
        'NutsSeeds',
      ),
      'image' => '5192_Sibl_9780307957900_art_r1.jpg',
    ),
    array(
      'name' => 'Blackbirds & Orioles',
      'attributes' => array(
        'FleshyFruits',
        'FruitVegetation',
      ),
      'image' => '4979_Sibl_9780307957900_art_r1.jpg',
    ),
    array(
      'name' => 'Crows & Jays',
      'attributes' => array(
        'FleshyFruits',
        'FruitVegetation',
      ),
      'image' => '5504_Sibl_9780307957900_art_r1.jpg',
    ),
    array(
      'name' => 'Thrushes',
      'attributes' => array(
        'FleshyFruits',
        'FruitVegetation',
      ),
      'image' => '3546_Sibl_9780307957900_art_r1.jpg',
    ),
    array(
      'name' => 'Hummingbirds',
      'attributes' => array(
        'HummingBirdNectar',
      ),
      'image' => '2762_Sibl_9780307957900_art_r1.jpg',
    ),
  );

  return array(
    'native_plant_attributes' => $attributes,
    'native_plant_bird_types' => $bird_types,
  );
}
