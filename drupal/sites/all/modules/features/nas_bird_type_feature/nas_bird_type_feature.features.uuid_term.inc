<?php
/**
 * @file
 * nas_bird_type_feature.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function nas_bird_type_feature_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Florida',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '00dbe5ce-c3ab-4f2c-ad1d-f3d6f466702d',
    'vocabulary_machine_name' => 'bird_region',
  );
  $terms[] = array(
    'name' => 'Cormorants',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '01fdefb3-eeb5-40f8-92af-812f43c309ca',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Pigeons and Doves',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '047a31e0-93ed-4a9d-a1d3-eba7529e7e18',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Starlings and Mynas',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '04f3634b-0562-4a32-8c0b-0d59e04b17a5',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'New England',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '05934dec-7206-490f-82a4-8da0cd20afce',
    'vocabulary_machine_name' => 'bird_region',
  );
  $terms[] = array(
    'name' => 'Great Lakes',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0c1a1f99-78fb-4aba-b521-d07fa97c2e71',
    'vocabulary_machine_name' => 'bird_region',
  );
  $terms[] = array(
    'name' => 'Ducks and Geese',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0ee73a82-c622-44e9-817e-28eb2efad61c',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Swifts',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '11eaa822-57f1-4bf7-9f91-40e4e7912a1b',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Extinct (EX)',
    'description' => 'No known individuals remaining',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '12a22841-f7c1-4369-b330-7d81c365c0e5',
    'vocabulary_machine_name' => 'conservation_status',
  );
  $terms[] = array(
    'name' => 'Ospreys',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '12bbeff5-3192-41b8-a9f6-79ece269f959',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Bulbuls',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '14f5d23e-3805-40e1-a8ec-4ca50550eebf',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Sandpipers',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1916930c-9ef5-457d-bf32-3e54fc45ee90',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Albatrosses',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '196d5568-3fcf-4732-8605-5ff1e09f8899',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Mockingbirds and Thrashers',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1a8e4c3d-b903-4890-9c60-56eef4be37e2',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Cranes',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1b8d6253-142c-4a0e-b931-0eade7880e34',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Eastern Canada',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1be1d021-eea7-4bc6-9fc2-129fe1c351b8',
    'vocabulary_machine_name' => 'bird_region',
  );
  $terms[] = array(
    'name' => 'Auks, Murres, Puffins',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '20b2851c-715f-47eb-bc6f-04703bcb0050',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Hummingbirds',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2329628c-f694-4c7d-83c3-039ef1048951',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Larks',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '24ea00ad-6c75-4d70-b7da-d259c5a3bb26',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Old World Warblers',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '26137f8d-8884-4a80-a051-9d16b93f6f6c',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Storks',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '302498fd-f5f4-4129-936e-61a37c68ce5d',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Creepers',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '322deb5d-4623-413b-b711-840fbf5ab788',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Texas',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '32f3b6ea-847f-4c76-a840-241a4c6fe47c',
    'vocabulary_machine_name' => 'bird_region',
  );
  $terms[] = array(
    'name' => 'Southeast',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '369b7c7e-f695-4277-9433-6b980c5183ca',
    'vocabulary_machine_name' => 'bird_region',
  );
  $terms[] = array(
    'name' => 'Dippers',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3815e741-f8b0-49b3-b4c0-d56675251951',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Plovers',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '388cf3d8-a2cd-4063-b6ca-6cb63a1722b5',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Longspurs and Snow Buntings',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3925329e-ae1e-4219-b7c1-aad9a8000995',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Leaf-Warblers',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3a98974f-b2d2-4c32-90b8-9580f5f87aed',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Cardinals',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3b58b977-89ed-47c5-ad90-a0f0e675b3cd',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'New World Quail',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3ccbdfd5-da45-459f-9bde-5e35854d72fb',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Shearwaters and Petrels',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3e37fec5-b67b-48ae-9dee-8106244e4d76',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Tanagers',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '410fe4b4-4af0-4774-98d7-ae8ab623dda6',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Bushtits',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4214ba54-d4cf-4b60-ab45-125f59b46292',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Ibises and Spoonbills',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4248c1bf-0fcb-4133-a49d-854201d01d4b',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Finches',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '43e60161-a6e4-45fc-b9a1-2c6a78f05964',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Oystercatchers',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '44e0cd92-c6a9-4869-b4c7-c050af893d2b',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Parrots and Allie',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '491b3fef-9328-4198-82da-ae7ff12331f4',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Chickadees and Titmice',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '49d48887-ea84-4fbf-b6f4-13edbaaf4d40',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Thrushes',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '505a16e6-4283-4a8c-a109-79d665b73478',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Mid Atlantic',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '60f2f864-d268-45d1-bb2a-16c1a3afedde',
    'vocabulary_machine_name' => 'bird_region',
  );
  $terms[] = array(
    'name' => 'New World Sparrows',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6203bf2e-a273-49b7-a468-b77dcdcbe14b',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Shrikes',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '621145d7-d851-4eff-bd38-c0933bd450db',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Nightjars',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6c20be37-a46a-4e5a-81eb-1b0f0eef155b',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Owls',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '72ddfc7b-a8f1-4cc5-979b-f166b42f937a',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Grebes',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7698c184-8a5d-4717-ac55-13de312d9dd9',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Barn Owls',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '76e80b58-d382-4ee6-afb6-772052087423',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Hawks and Eagles',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '79bddea0-17c0-4d4b-be9b-d81c4bc0d211',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Herons, Egrets, Bitterns',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7f76f999-1640-4ac1-8b78-a1d9a166d7bd',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Verdins',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7faae3ea-ee0c-42da-ae48-99e7beb061ca',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Kingfishers',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8309ba56-d2d4-4f5b-ac09-a18f40252d3a',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Nuthatches',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '867aa7d1-b959-44b1-92e2-210b2e136db7',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Silky Flycatchers',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8e031bbf-3d68-4406-9a1f-14a9a953f5c6',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Gulls and Terns',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8f3708ad-e19a-4926-85e8-39117921c9c8',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Pheasants and Grouse',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '90fb38e9-30e1-4d63-8c00-0d9c9c0b6013',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Swallows',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '91518f94-83b4-4b47-bfa4-e629d1c55789',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Waxwings',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9397300f-2778-4f42-96d0-56ff0780269a',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Loons',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9a7bce24-21c7-4ccf-b886-6ceb43c6f6d8',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Old World Sparrows',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9b10b5a1-9a8e-43fc-9aab-9ba32363f178',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Tropicbirds',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9da492bb-49ee-4b53-aa45-0e08b3fa5ebd',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Chachalacas',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a10725f8-e9e6-4182-a673-f7f8452912ef',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Kinglets',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a572dd1e-a97c-4140-a190-97718a680413',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Pelicans',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a5f3b1f4-3cf9-4b41-9205-d680f0de5440',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Old World Flycatchers',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a684c989-4ebb-4f92-b1e3-9ebefd1fab0f',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Tyrant Flycatchers',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'aa986865-ae91-491f-b74f-8b32311b173e',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Vireos',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'abf2bb3f-6d98-4935-a0ee-9fd540f3e620',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Extinct in the wild (EW)',
    'description' => 'Known only to survive in captivity, or as a naturalized population outside its historic range.',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ad30e6a0-fdab-4dc8-bc8a-5770ee6842a3',
    'vocabulary_machine_name' => 'conservation_status',
  );
  $terms[] = array(
    'name' => 'Rocky Mountains',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'adca68d4-c9b6-49a7-bd96-3a0323d681a3',
    'vocabulary_machine_name' => 'bird_region',
  );
  $terms[] = array(
    'name' => 'New World Vultures',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b191f99b-9173-461a-89ac-4a637917ee17',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Bananaquits',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b492b126-8943-4356-87c6-c15ef0c43777',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Northwest',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b60e7637-969b-4d6e-8b7a-1288ddcecc2f',
    'vocabulary_machine_name' => 'bird_region',
  );
  $terms[] = array(
    'name' => 'Wagtails and Pipits',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b61cffd5-4db2-4ace-9779-512d67c8143b',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Limpkins',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ba2000e1-6051-46db-bad7-30a97c2c4ff6',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'California',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bcdbf79a-2069-4906-a8d6-3b496ce1c02d',
    'vocabulary_machine_name' => 'bird_region',
  );
  $terms[] = array(
    'name' => 'Anhingas',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c158c7ae-956e-42c9-8d55-13988caa8dd9',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Cuckoos, Roadrunners, Anis',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c5722c38-42f3-4d65-bbc4-a62433e7c251',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Southwest',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c5d832dd-7446-45d6-9859-8f019a292026',
    'vocabulary_machine_name' => 'bird_region',
  );
  $terms[] = array(
    'name' => 'Flamingos',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c7826962-1d71-4bc9-84b4-8622c5602554',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Plains',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c78ce6ac-a975-4498-a279-dfadb8fc9e6e',
    'vocabulary_machine_name' => 'bird_region',
  );
  $terms[] = array(
    'name' => 'Olive Warblers',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c8e19b3b-f4c9-4d09-b6f4-6d675a96f676',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Falcons',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c9d53242-5c1a-456b-ad38-8567ff79bcb5',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Skuas and Jaegers',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd117f9e0-975a-466e-96e0-0ec8fae0e4bc',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Gnatcatchers',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd7f1fd86-9f46-4013-ba40-1ddbd19b139c',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Trogons',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'da5f9668-f18b-4706-9349-565ea9ad61c3',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Wrens',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ddc2c356-378c-4437-88c1-c6acb301fe79',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Blackbirds and Orioles',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e0b1f29d-51ad-4700-a3d6-bbbd283221ee',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Storm-Petrels',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e62cfa13-8808-410f-b713-27a49a4d72e2',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Alaska and The North',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ef4065ad-09c1-4899-b778-667fa19bee38',
    'vocabulary_machine_name' => 'bird_region',
  );
  $terms[] = array(
    'name' => 'Rails, Gallinules, Coots',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'efac24c6-fb83-4a3c-9044-1e91da8225d9',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Wood Warblers',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'eff85e6a-e38b-45e8-956a-4ea42fd5e266',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Crows, Magpies, Jays',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f0eda9f9-c070-4967-9247-4959a901557c',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Stilts and Avocets',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f4411130-cda5-484e-b56c-fe6d79367d87',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Woodpeckers',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f5927e7f-bad7-4540-963f-819bd2e834a3',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Becards, Tityras and allies',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f74e465e-588e-4922-820e-4beb0fff9af8',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Boobies and Gannets',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f9fdbe4f-7998-470f-965b-c68ea7e5d081',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Western Canada',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'fba942c0-ae22-4986-8675-b9dae40e57ed',
    'vocabulary_machine_name' => 'bird_region',
  );
  $terms[] = array(
    'name' => 'Frigatebirds',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'fd0820e5-f609-41eb-aada-e845bced21a0',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  $terms[] = array(
    'name' => 'Jacanas',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'fdf3ddfd-bb71-4b61-851d-2acfc78051cc',
    'vocabulary_machine_name' => 'bird_family',
    'field_bird_family_sci_name' => array(),
  );
  return $terms;
}
