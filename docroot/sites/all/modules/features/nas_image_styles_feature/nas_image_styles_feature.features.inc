<?php
/**
 * @file
 * nas_image_styles_feature.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function nas_image_styles_feature_image_default_styles() {
  $styles = array();

  // Exported image style: about_page_success_section.
  $styles['about_page_success_section'] = array(
    'label' => 'About page success section',
    'effects' => array(
      15 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 2400,
          'height' => 1600,
          'anchor' => 'center-top',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 1,
          ),
        ),
        'weight' => 1,
      ),
      16 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2400,
          'height' => 1600,
        ),
        'weight' => 2,
      ),
      17 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: article_featured.
  $styles['article_featured'] = array(
    'label' => 'Article featured',
    'effects' => array(
      2 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 1007,
          'height' => 600,
          'anchor' => 'center-top',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 0,
          ),
        ),
        'weight' => 1,
      ),
      3 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: article_hero_inline.
  $styles['article_hero_inline'] = array(
    'label' => 'Article hero inline',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1597,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: article_teaser.
  $styles['article_teaser'] = array(
    'label' => 'Article teaser',
    'effects' => array(
      27 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 630,
          'height' => 401,
        ),
        'weight' => 2,
      ),
      28 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: article_teaser_list.
  $styles['article_teaser_list'] = array(
    'label' => 'Article teaser list',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 630,
          'height' => 472,
        ),
        'weight' => 1,
      ),
      4 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: bean_wysiwyg_full_width.
  $styles['bean_wysiwyg_full_width'] = array(
    'label' => 'bean_wysiwyg_full_width',
    'effects' => array(
      27 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1592,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      28 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: bio_image.
  $styles['bio_image'] = array(
    'label' => 'Bio image',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 260,
          'height' => 260,
        ),
        'weight' => 2,
      ),
      3 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: bird_illustration.
  $styles['bird_illustration'] = array(
    'label' => 'Bird Species Illustration',
    'effects' => array(
      4 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 189,
          'height' => 100,
          'upscale' => 0,
        ),
        'weight' => -10,
      ),
      5 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: bird_teaser_illustration.
  $styles['bird_teaser_illustration'] = array(
    'label' => 'Bird Species teaser illustration',
    'effects' => array(
      5 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 193,
          'height' => 186,
          'upscale' => 0,
        ),
        'weight' => -10,
      ),
      6 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: birds_landing_banner.
  $styles['birds_landing_banner'] = array(
    'label' => 'Birds landing banner',
    'effects' => array(
      3 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 970,
          'height' => 570,
          'anchor' => 'right-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 1,
          ),
        ),
        'weight' => 1,
      ),
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 970,
          'height' => 570,
        ),
        'weight' => 2,
      ),
      5 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: boa_family_species.
  $styles['boa_family_species'] = array(
    'label' => 'BOA Family Species',
    'effects' => array(
      14 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 460,
          'height' => 602,
          'anchor' => 'center-top',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 1,
          ),
        ),
        'weight' => -10,
      ),
      13 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 460,
          'height' => 602,
        ),
        'weight' => -9,
      ),
      15 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: boa_lightbox.
  $styles['boa_lightbox'] = array(
    'label' => 'BOA lightbox',
    'effects' => array(
      0 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: conservation_slideshow_featured_project.
  $styles['conservation_slideshow_featured_project'] = array(
    'label' => 'Conservation Slideshow featured project',
    'effects' => array(
      2 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 306,
          'height' => 306,
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 0,
          ),
        ),
        'weight' => 1,
      ),
      3 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: conservation_slideshow_icon.
  $styles['conservation_slideshow_icon'] = array(
    'label' => 'Conservation Slideshow icon',
    'effects' => array(
      3 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 100,
          'height' => 100,
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 0,
          ),
        ),
        'weight' => 1,
      ),
      4 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: conservation_strategy_icon.
  $styles['conservation_strategy_icon'] = array(
    'label' => 'Conservation Strategy Icon',
    'effects' => array(
      0 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: conservation_strategy_slideshow.
  $styles['conservation_strategy_slideshow'] = array(
    'label' => 'Conservation Strategy slideshow',
    'effects' => array(
      1 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 1072,
          'height' => 972,
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 0,
          ),
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: default_teaser_image.
  $styles['default_teaser_image'] = array(
    'label' => 'Standard teaser',
    'effects' => array(
      2 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 306,
          'height' => 194,
          'anchor' => 'center-top',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 0,
          ),
        ),
        'weight' => 1,
      ),
      3 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: donate_banner_bg.
  $styles['donate_banner_bg'] = array(
    'label' => 'Donate banner background',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 970,
          'height' => 570,
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: featured_frontpage.
  $styles['featured_frontpage'] = array(
    'label' => 'Featured frontpage',
    'effects' => array(
      1 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 2400,
          'height' => 1400,
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 1,
          ),
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2400,
          'height' => 1400,
        ),
        'weight' => 2,
      ),
      3 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: front_flyway_image.
  $styles['front_flyway_image'] = array(
    'label' => 'Frontpage flyway',
    'effects' => array(
      2 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 600,
          'height' => 842,
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 0,
          ),
        ),
        'weight' => 1,
      ),
      3 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: frontpage_featured_article_image.
  $styles['frontpage_featured_article_image'] = array(
    'label' => 'Frontpage featured article image',
    'effects' => array(
      29 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 1280,
          'height' => 720,
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => 1.77778,
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 1,
          ),
        ),
        'weight' => 2,
      ),
      30 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: get_outside.
  $styles['get_outside'] = array(
    'label' => 'Get Outside',
    'effects' => array(
      1 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 2400,
          'height' => 1400,
          'anchor' => 'center-top',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 0,
          ),
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: hero_cover_bird_page.
  $styles['hero_cover_bird_page'] = array(
    'label' => 'Hero cover bird page',
    'effects' => array(
      7 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 1920,
          'height' => 1200,
          'anchor' => 'center-top',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 1,
          ),
        ),
        'weight' => 1,
      ),
      8 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: hero_image.
  $styles['hero_image'] = array(
    'label' => 'Hero image',
    'effects' => array(
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 2400,
          'height' => 1800,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      7 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: hero_mobile.
  $styles['hero_mobile'] = array(
    'label' => 'Hero mobile',
    'effects' => array(
      11 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1060,
          'height' => 994,
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
      12 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: local_chapters_centers.
  $styles['local_chapters_centers'] = array(
    'label' => 'Local chapters centers',
    'effects' => array(
      5 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 629,
          'height' => 409,
          'anchor' => 'center-top',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 1,
          ),
        ),
        'weight' => 1,
      ),
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 629,
          'height' => 409,
        ),
        'weight' => 2,
      ),
      7 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: magazine_issue_cover.
  $styles['magazine_issue_cover'] = array(
    'label' => 'Magazine issue cover',
    'effects' => array(
      3 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 628,
          'height' => 840,
          'anchor' => 'center-top',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 1,
          ),
        ),
        'weight' => 1,
      ),
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 628,
          'height' => 840,
        ),
        'weight' => 2,
      ),
      6 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: magazine_issue_cover_teaser.
  $styles['magazine_issue_cover_teaser'] = array(
    'label' => 'Magazine issue cover teaser',
    'effects' => array(
      4 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 460,
          'height' => 620,
          'anchor' => 'center-top',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 1,
          ),
        ),
        'weight' => 1,
      ),
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 460,
          'height' => 620,
        ),
        'weight' => 2,
      ),
      7 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: nas_bird_node_full_illustration.
  $styles['nas_bird_node_full_illustration'] = array(
    'label' => 'Bird Species Full Illustration',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 189,
          'height' => 100,
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
      3 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: nas_bird_photo_thumbnnail.
  $styles['nas_bird_photo_thumbnnail'] = array(
    'label' => 'Bird species thumbnnail',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 97,
          'height' => 97,
        ),
        'weight' => 1,
      ),
      5 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: nas_bird_teaser_illustration.
  $styles['nas_bird_teaser_illustration'] = array(
    'label' => 'nas_bird_teaser_illustration',
    'effects' => array(
      16 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 386,
          'height' => 400,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      17 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: nas_birds_landing_epsacrop_mobile.
  $styles['nas_birds_landing_epsacrop_mobile'] = array(
    'label' => 'Birds landing mobile',
    'effects' => array(
      2 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 640,
          'height' => 600,
          'anchor' => 'right-bottom',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 1,
          ),
        ),
        'weight' => 1,
      ),
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 600,
        ),
        'weight' => 2,
      ),
      4 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: our_leadership.
  $styles['our_leadership'] = array(
    'label' => 'Our leadership',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 350,
          'height' => 350,
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: related_features.
  $styles['related_features'] = array(
    'label' => 'Related features',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 463,
          'height' => 340,
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: slideshow.
  $styles['slideshow'] = array(
    'label' => 'Slideshow',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1320,
          'height' => 780,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      3 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: slideshow_sidebar.
  $styles['slideshow_sidebar'] = array(
    'label' => 'Slideshow sidebar',
    'effects' => array(
      1 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 629,
          'height' => 409,
          'anchor' => 'center-top',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 1,
          ),
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 629,
          'height' => 409,
        ),
        'weight' => 2,
      ),
      3 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: slideshow_teaser.
  $styles['slideshow_teaser'] = array(
    'label' => 'Slideshow teaser',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 463,
          'height' => 340,
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: static_cards_two_columns.
  $styles['static_cards_two_columns'] = array(
    'label' => 'Static cards two columns',
    'effects' => array(
      1 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 970,
          'height' => 570,
          'anchor' => 'center-top',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 1,
          ),
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 970,
          'height' => 570,
        ),
        'weight' => 2,
      ),
      3 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: static_cards_two_columns_mobile.
  $styles['static_cards_two_columns_mobile'] = array(
    'label' => 'Static cards two columns mobile',
    'effects' => array(
      3 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 970,
          'height' => 570,
          'anchor' => 'center-top',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 1,
          ),
        ),
        'weight' => 1,
      ),
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 970,
          'height' => 570,
        ),
        'weight' => 2,
      ),
      5 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: wysiwyg_slide.
  $styles['wysiwyg_slide'] = array(
    'label' => 'Wysiwyg slide',
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 2400,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      4 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}
