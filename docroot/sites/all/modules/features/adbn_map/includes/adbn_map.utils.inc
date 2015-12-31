<?php

/**
 * Returns the path to the adbn_map module.
 */
function adbn_map_get_module_path() {
  $path = drupal_get_path('module', 'adbn_map');
  return $path;
}

/**
 * Returns the path to the stamen asset folder.
 */
function adbn_map_get_map_assets_path() {
  $path = adbn_map_get_module_path() . '/stamen';
  return $path;
}

/**
 * Returns the path to the stamen js folder.
 */
function adbn_map_get_map_js_path() {
  $path = adbn_map_get_map_assets_path() . '/js';
  return $path;
}

/**
 * Returns the path to the stamen css folder.
 */
function adbn_map_get_map_css_path() {
  $path = adbn_map_get_map_assets_path() . '/css';
  return $path;
}

/**
 * Returns the path to the stamen data folder.
 */
function adbn_map_get_map_data_path() {
  $path = adbn_map_get_map_assets_path() . '/data';
  return $path;
}

/**
 * Returns a render array with attached JS and CSS assets for map component.
 */
function adbn_map_attach_map_assets($aggregated = TRUE) {
  $module_path = adbn_map_get_module_path();
  $map_js_path = adbn_map_get_map_js_path();
  $map_css_path = adbn_map_get_map_css_path();
  $element = array();

  // Load this to assign the jQuery to the global $ sign, because that's what
  // Stamen JS requires.
  $element['#attached']['js'][] = array(
    'data' => $module_path . '/js/adbn_map_init.js',
    'type' => 'file',
    'weight' => -1,
  );

  // Depending on whether we include the aggregated version or not, we load
  // the aggregated js, or all the separate ones.
  if ($aggregated) {
    $element['#attached']['js'][] = $map_js_path . '/audubon-climate-model.min.js';
  }
  else {
    $element['#attached']['js'][] = $map_js_path . '/vendor/polyfills.js';
    $element['#attached']['js'][] = $map_js_path . '/vendor/stamen-super-classy.js';
    $element['#attached']['js'][] = $map_js_path . '/vendor/typeahead.js';
    $element['#attached']['js'][] = $map_js_path . '/vendor/d3.v3.min.js';
    $element['#attached']['js'][] = $map_js_path . '/vendor/topojson.v1.min.js';
    $element['#attached']['js'][] = $map_js_path . '/vendor/queue.v1.min.js';
    $element['#attached']['js'][] = $map_js_path . '/vendor/venn.js';
    $element['#attached']['js'][] = $map_js_path . '/venn-over-venn.js';
    $element['#attached']['js'][] = $map_js_path . '/audubon-climate-model.js';
    $element['#attached']['js'][] = $map_js_path . '/audubon-climate-model-slideshow.js';
    $element['#attached']['js'][] = $map_js_path . '/audubon-climate-model-imagemap.js';
  }

  // Add the various js settings required to initialize the map functionality.
  $element['#attached']['js'][] = array(
    'type' => 'setting',
    'data' => array(ADBN_MAP_JS_NAMESPACE => array(
      'imagesPath' => adbn_map_get_map_css_path()
    )),
  );

  // Load the CSS. Not sure if will be needed in the future.
  $element['#attached']['css'][] = $map_css_path . '/audubon-mlimate-model.css';

  return $element;
}

/**
 * Returns a render array with the stamen search js attached.
 */
function adbn_map_attach_search_js($aggregated = TRUE, $force_attach = FALSE) {
  $content = array();

  // Check if we already attached the search js.
  $is_attached = &drupal_static('adbn_map_search_attached', FALSE);
  if ($is_attached || $force_attach) {
    return $content;
  }
  else {
    // Mark that we already have JS that attaches to the search input.
    $is_attached = TRUE;
  }

  // Get various asset paths.
  $module_path = adbn_map_get_module_path();
  $plugin_path = $module_path . '/plugins/content_types/bird_list_search_box';

  // Add the various js settings required to initialize the plugin.
  $content['#attached']['js'][] = array(
    'type' => 'setting',
    'data' => array(
      ADBN_MAP_JS_NAMESPACE => array(
        'ajaxPath' => ADBN_MAP_AJAX_PATH,
        'birdDetailPath' => ADBN_MAP_BIRD_DETAIL_PATH,
        'area' => 'BBC',
      )
    ),
  );

  // Attach general map assets.
  $content = drupal_array_merge_deep_array(array(
    $content,
    adbn_map_attach_map_assets($aggregated)
  ));

  // Load the JS file that will initialize the map.
  $content['#attached']['js'][] = $plugin_path . '/bird_list_search_box.js';
  return $content;
}

/**
 * Returns the value of the bird page overlay variable.
 */
function adbn_map_get_bird_page_overlay_value() {
  $bird_page_overlay = variable_get(ADBN_BIRD_PAGE_OVERLAY_DESCRIPTION, array(
    'value' => '',
    'format' => 'full_html',
  ));
  return $bird_page_overlay;
}

/**
 * Returns the value of the bird page map short description variable.
 */
function adbn_map_get_bird_page_map_short_description_value() {
  $map_short_description = variable_get(ADBN_BIRD_PAGE_MAP_SHORT_DESCRIPTION, array(
    'value' => 'Darker color shades indicate increased climate suitability. The outlined areas represent approximate current range. [popup_link]',
    'format' => 'full_html',
  ));
  return $map_short_description;
}

/**
 * Returns the value of the bird page map short description link variable.
 */
function adbn_map_get_bird_page_map_short_description_link_value() {
  $map_short_description_link = variable_get(ADBN_BIRD_PAGE_MAP_SHORT_DESCRIPTION_LINK, 'More on reading these maps.');
  return $map_short_description_link;
}

/**
 * Get bird ID for the given sci name.
 */
function adbn_map_bird_id($sci_name) {
  $map = array(
    'Selasphorus sasin' => 'allhum',
    'Recurvirostra americana' => 'ameavo',
    'Botaurus lentiginosus' => 'amebit',
    'Anas rubripes' => 'ambduc',
    'Cinclus mexicanus' => 'amedip',
    'Pluvialis dominica' => 'amgplo',
    'Falco sparverius' => 'amekes',
    'Haematopus palliatus' => 'ameoys',
    'Anthus rubescens' => 'amepip',
    'Setophaga ruticilla' => 'amered',
    'Picoides dorsalis' => 'attwoo1',
    'Pelecanus erythrorhynchos' => 'amwpel',
    'Anas americana' => 'amewig',
    'Scolopax minor' => 'amewoo',
    'Synthliboramphus antiquus' => 'ancmur',
    'Anhinga anhinga' => 'anhing',
    'Ammodramus bairdii' => 'baispa',
    'Haliaeetus leucocephalus' => 'baleag',
    'Icterus galbula' => 'balori',
    'Patagioenas fasciata' => 'batpig1',
    'Riparia riparia' => 'banswa',
    'Tyto alba' => 'brnowl',
    'Bucephala islandica' => 'bargol',
    'Setophaga castanea' => 'babwar',
    'Vireo bellii' => 'belvir',
    'Toxostoma bendirei' => 'benthr',
    'Cepphus grylle' => 'blkgui',
    'Haematopus bachmani' => 'blkoys',
    'Leucosticte atrata' => 'bkrfin',
    'Rynchops niger' => 'blkski',
    'Cypseloides niger' => 'blkswi',
    'Chlidonias niger' => 'blkter',
    'Coragyps atratus' => 'blkvul',
    'Mniotilta varia' => 'bawwar',
    'Picoides arcticus' => 'bkbwoo',
    'Pluvialis squatarola' => 'bkbplo',
    'Coccyzus erythropthalmus' => 'bkbcuc',
    'Pica hudsonia' => 'bkbmag1',
    'Vireo atricapilla' => 'bkcvir1',
    'Archilochus alexandri' => 'bkchum',
    'Spizella atrogularis' => 'bkcspa',
    'Baeolophus atricristatus' => 'blctit4',
    'Nycticorax nycticorax' => 'bcnher',
    'Pheucticus melanocephalus' => 'bkhgro',
    'Rissa tridactyla' => 'bklkit',
    'Setophaga caerulescens' => 'btbwar',
    'Setophaga nigrescens' => 'btywar',
    'Setophaga virens' => 'btnwar',
    'Setophaga fusca' => 'bkbwar',
    'Setophaga striata' => 'bkpwar',
    'Anas discors' => 'buwtea',
    'Vermivora cyanoptera' => 'buwwar',
    'Quiscalus major' => 'botgra',
    'Dolichonyx oryzivorus' => 'boboli',
    'Bombycilla garrulus' => 'bohwax',
    'Poecile hudsonicus' => 'borchi2',
    'Aegolius funereus' => 'borowl',
    'Branta bernicla' => 'blkbra1',
    'Euphagus cyanocephalus' => 'brebla',
    'Spizella breweri' => 'brespa',
    'Buteo platypterus' => 'brwhaw',
    'Molothrus aeneus' => 'brocow',
    'Certhia americana' => 'brncre',
    'Pelecanus occidentalis' => 'brnpel',
    'Leucosticte australis' => 'bcrfin',
    'Sitta pusilla' => 'bnhnut',
    'Bucephala albeola' => 'buffle',
    'Icterus bullockii' => 'bulori',
    'Athene cunicularia' => 'burowl',
    'Larus californicus' => 'calgul',
    'Selasphorus calliope' => 'calhum',
    'Cardellina canadensis' => 'canwar',
    'Setophaga tigrina' => 'camwar',
    'Hydroprogne caspia' => 'caster1',
    'Ptychoramphus aleuticus' => 'casauk',
    'Haemorhous cassinii' => 'casfin',
    'Petrochelidon fulva' => 'cavswa',
    'Setophaga cerulea' => 'cerwar',
    'Calcarius ornatus' => 'chclon',
    'Setophaga pensylvanica' => 'chswar',
    'Anas cyanoptera' => 'cintea',
    'Rallus longirostris' => 'clarai',
    'Aechmophorus clarkii' => 'clagre',
    'Nucifraga columbiana' => 'clanut',
    'Spizella pallida' => 'clcspa',
    'Bucephala clangula' => 'comgol',
    'Gavia immer' => 'comloo',
    'Mergus merganser' => 'commer',
    'Phalaenoptilus nuttallii' => 'compoo',
    'Corvus corax' => 'comrav',
    'Acanthis flammea' => 'comred',
    'Sterna hirundo' => 'comter',
    'Oporornis agilis' => 'conwar',
    'Empidonax occidentalis' => 'corfly',
    'Caracara cheriway' => 'crecar1',
    'Phalacrocorax auritus' => 'doccor',
    'Alle alle' => 'doveki',
    'Calidris alpina' => 'dunlin',
    'Empidonax oberholseri' => 'dusfly',
    'Dendragapus obscurus/fuliginosus' => 'blugrs',
    'Podiceps nigricollis' => 'eargre',
    'Antrostomus vociferus' => 'whip-p1',
    'Chen canagica' => 'empgoo',
    'Anas penelope' => 'eurwig',
    'Coccothraustes vespertinus' => 'evegro',
    'Buteo regalis' => 'ferhaw',
    'Corvus ossifragus' => 'fiscro',
    'Aphelocoma coerulescens' => 'flsjay',
    'Sterna forsteri' => 'forter',
    'Leucophaeus pipixcan' => 'fragul',
    'Anas strepera' => 'gadwal',
    'Melanerpes uropygialis' => 'gilwoo',
    'Colaptes chrysoides' => 'gilfli',
    'Larus glaucescens' => 'glwgul',
    'Plegadis falcinellus' => 'gloibi',
    'Aquila chrysaetos' => 'goleag',
    'Setophaga chrysoparia' => 'gchwar',
    'Regulus satrapa' => 'gockin',
    'Melanerpes aurifrons' => 'gofwoo',
    'Vermivora chrysoptera' => 'gowwar',
    'Empidonax wrightii' => 'gryfly',
    'Vireo vicinior' => 'gryvir',
    'Catharus minimus' => 'gycthr',
    'Leucosticte tephrocotis' => 'gcrfin',
    'Larus marinus' => 'gbbgul',
    'Strix nebulosa' => 'grgowl',
    'Aythya marila' => 'gresca',
    'Anser albifrons' => 'gwfgoo',
    'Tringa melanoleuca' => 'greyel',
    'Pipilo chlorurus' => 'gnttow',
    'Gelochelidon nilotica' => 'gubter1',
    'Falco rusticolus' => 'gyrfal',
    'Picoides villosus' => 'haiwoo',
    'Empidonax hammondii' => 'hamfly',
    'Ammodramus henslowii' => 'henspa',
    'Piranga flava' => 'heptan',
    'Catharus guttatus' => 'herthr',
    'Setophaga occidentalis' => 'herwar',
    'Larus argentatus' => 'hergul',
    'Lophodytes cucullatus' => 'hoomer',
    'Setophaga citrina' => 'hoowar',
    'Podiceps auritus' => 'horgre',
    'Haemorhous mexicanus' => 'houfin',
    'Vireo huttoni' => 'hutvir',
    'Baeolophus ridgwayi' => 'juntit1',
    'Somateria spectabilis' => 'kineid',
    'Rallus elegans' => 'kinrai',
    'Brachyramphus brevirostris' => 'kitmur',
    'Leucophaeus atricilla' => 'laugul',
    'Spinus lawrencei' => 'lawgol',
    'Ammodramus leconteii' => 'lecspa',
    'Toxostoma lecontei' => 'lecthr',
    'Ixobrychus exilis' => 'leabit',
    'Empidonax minimus' => 'leafly',
    'Tachybaptus dominicus' => 'leagre',
    'Sternula antillarum' => 'leater1',
    'Tympanuchus pallidicinctus' => 'lepchi',
    'Aythya affinis' => 'lessca',
    'Tringa flavipes' => 'lesyel',
    'Melanerpes lewis' => 'lewwoo',
    'Hydrocoloeus minutus' => 'litgul',
    'Numenius americanus' => 'lobcur',
    'Toxostoma longirostre' => 'lobthr',
    'Asio otus' => 'loeowl',
    'Parkesia motacilla' => 'louwat',
    'Setophaga magnolia' => 'magwar',
    'Anas platyrhynchos' => 'mallar',
    'Coccyzus minor' => 'mancuc',
    'Limosa fedoa' => 'margod',
    'Cistothorus palustris' => 'marwre',
    'Rhynchophanes mccownii' => 'mcclon',
    'Falco columbarius' => 'merlin',
    'Aphelocoma wollweberi' => 'mexjay4',
    'Ictinia mississippiensis' => 'miskit',
    'Cyrtonyx montezumae' => 'monqua',
    'Sialia currucoides' => 'moublu',
    'Poecile gambeli' => 'mouchi',
    'Charadrius montanus' => 'mouplo',
    'Oreortyx pictus' => 'mouqua',
    'Geothlypis philadelphia' => 'mouwar',
    'Oreothlypis ruficapilla' => 'naswar',
    'Ammodramus nelsoni/caudacutus' => 'shtspa',
    'Fulmarus glacialis' => 'norful',
    'Morus bassanus' => 'norgan',
    'Circus cyaneus' => 'norhar',
    'Surnia ulula' => 'nohowl',
    'Glaucidium gnoma' => 'nopowl',
    'Aegolius acadicus' => 'nswowl',
    'Anas clypeata' => 'norsho',
    'Peucedramus taeniatus' => 'oliwar',
    'Icterus spurius' => 'orcori',
    'Pandion haliaetus' => 'osprey',
    'Seiurus aurocapilla' => 'ovenbi1',
    'Pluvialis fulva' => 'pagplo',
    'Empidonax difficilis' => 'pasfly',
    'Myioborus pictus' => 'paired',
    'Setophaga palmarum' => 'palwar',
    'Stercorarius parasiticus' => 'parjae',
    'Falco peregrinus' => 'perfal',
    'Vireo philadelphicus' => 'phivir',
    'Cepphus columba' => 'piggui',
    'Pinicola enucleator' => 'pingro',
    'Spinus pinus' => 'pinsis',
    'Setophaga pinus' => 'pinwar',
    'Gymnorhinus cyanocephalus' => 'pinjay',
    'Charadrius melodus' => 'pipplo',
    'Stercorarius pomarinus' => 'pomjae',
    'Falco mexicanus' => 'prafal',
    'Haemorhous purpureus' => 'purfin',
    'Calidris maritima' => 'pursan',
    'Sitta pygmaea' => 'pygnut',
    'Alca torda' => 'razorb',
    'Loxia curvirostra' => 'redcro',
    'Calidris canutus' => 'redkno',
    'Mergus serrator' => 'rebmer',
    'Sitta canadensis' => 'rebnut',
    'Sphyrapicus ruber' => 'rebsap',
    'Picoides borealis' => 'recwoo',
    'Cardellina rubrifrons' => 'refwar',
    'Sphyrapicus nuchalis' => 'rensap',
    'Podiceps grisegena' => 'rengre',
    'Gavia stellata' => 'retloo',
    'Egretta rufescens' => 'redegr',
    'Aythya americana' => 'redhea',
    'Cerorhinca monocerata' => 'rhiauk',
    'Larus delawarensis' => 'ribgul',
    'Aythya collaris' => 'rinduc',
    'Calidris ptilocnemis' => 'rocsan',
    'Platalea ajaja' => 'rosspo1',
    'Thalasseus maximus' => 'royter1',
    'Arenaria interpres' => 'rudtur',
    'Bonasa umbellus' => 'rufgro',
    'Selasphorus rufus' => 'rufhum',
    'Aimophila ruficeps' => 'rucspa',
    'Euphagus carolinus' => 'rusbla',
    'Oreoscoptes montanus' => 'sagthr',
    'Artemisiospiza nevadensis' => 'sagspa',
    'Grus canadensis' => 'sancra',
    'Thalasseus sandvicensis' => 'santer1',
    'Piranga olivacea' => 'scatan',
    'Ammodramus maritimus' => 'seaspa',
    'Cistothorus platensis' => 'sedwre',
    'Charadrius semipalmatus' => 'semplo',
    'Tympanuchus phasianellus' => 'shtgro',
    'Limnodromus griseus' => 'shbdow',
    'Asio flammeus' => 'sheowl',
    'Calcarius pictus' => 'smilon',
    'Bubo scandiacus' => 'snoowl1',
    'Charadrius nivosus' => 'snoplo5',
    'Tringa solitaria' => 'solsan',
    'Actitis macularius' => 'sposan',
    'Anthus spragueii' => 'sprpip',
    'Calidris himantopus' => 'stisan',
    'Calidris virgata' => 'surfbi',
    'Buteo swainsoni' => 'swahaw',
    'Elanoides forficatus' => 'swtkit',
    'Melospiza georgiana' => 'swaspa',
    'Oreothlypis peregrina' => 'tenwar',
    'Larus thayeri' => 'thagul',
    'Uria lomvia' => 'thbmur',
    'Myadestes townsendi' => 'towsol',
    'Setophaga townsendi' => 'towwar',
    'Tachycineta bicolor' => 'treswa',
    'Agelaius tricolor' => 'tribla',
    'Egretta tricolor' => 'triher',
    'Cygnus buccinator' => 'truswa',
    'Cygnus columbianus' => 'tunswa',
    'Ixoreus naevius' => 'varthr',
    'Chaetura vauxi' => 'vauswi',
    'Catharus fuscescens' => 'veery',
    'Pooecetes gramineus' => 'vesspa',
    'Tachycineta thalassina' => 'vigswa',
    'Oreothlypis virginiae' => 'virwar',
    'Sialia mexicana' => 'wesblu',
    'Aechmophorus occidentalis' => 'wesgre',
    'Larus occidentalis' => 'wesgul',
    'Megascops kennicottii' => 'wesowl1',
    'Piranga ludoviciana' => 'westan',
    'Contopus sordidulus' => 'wewpew',
    'Numenius phaeopus' => 'whimbr',
    'Sitta carolinensis' => 'whbnut',
    'Patagioenas leucocephala' => 'whcpig2',
    'Plegadis chihi' => 'whfibi',
    'Picoides albolarvatus' => 'whhwoo',
    'Geranoaetus albicaudatus' => 'whthaw',
    'Elanus leucurus' => 'whtkit',
    'Zonotrichia albicollis' => 'whtspa',
    'Aeronautes saxatalis' => 'whtswi',
    'Loxia leucoptera' => 'whwcro',
    'Grus americana' => 'whocra',
    'Meleagris gallopavo' => 'wiltur',
    'Tringa semipalmata' => 'willet1',
    'Sphyrapicus thyroideus' => 'wilsap',
    'Empidonax traillii' => 'wilfly',
    'Phalaropus tricolor' => 'wilpha',
    'Charadrius wilsonia' => 'wilplo',
    'Cardellina pusilla' => 'wlswar',
    'Troglodytes troglodytes' => 'winwre',
    'Aix sponsa' => 'wooduc',
    'Mycteria americana' => 'woosto',
    'Hylocichla mustelina' => 'woothr',
    'Helmitheros vermivorum' => 'woewar1',
    'Coturnicops noveboracensis' => 'yelrai',
    'Empidonax flaviventris' => 'yebfly',
    'Sphyrapicus varius' => 'yebsap',
    'Gavia adamsii' => 'yebloo',
    'Xanthocephalus xanthocephalus' => 'yehbla',
    'Vireo flavifrons' => 'yetvir',
    'Setophaga dominica' => 'yetwar',
    'Buteo albonotatus' => 'zothaw',
  );

  if (isset($map[$sci_name])) {
    return $map[$sci_name];
  }

  return FALSE;
}
