<?php
/**
 * @file
 * nas_metatags_feature.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function nas_metatags_feature_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: global.
  $config['global'] = array(
    'instance' => 'global',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => '[current-page:title] | [site:name]',
      ),
      'generator' => array(
        'value' => 'Drupal 7 (http://drupal.org)',
      ),
      'canonical' => array(
        'value' => '[current-page:url:absolute]',
      ),
      'shortlink' => array(
        'value' => '[current-page:url:unaliased]',
      ),
      'og:site_name' => array(
        'value' => '[site:name]',
      ),
      'og:title' => array(
        'value' => '[current-page:title]',
      ),
      'og:type' => array(
        'value' => 'article',
      ),
      'og:url' => array(
        'value' => '[current-page:url:absolute]',
      ),
    ),
  );

  // Exported Metatag config instance: global:403.
  $config['global:403'] = array(
    'instance' => 'global:403',
    'disabled' => FALSE,
    'config' => array(
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'shortlink' => array(
        'value' => '[site:url]',
      ),
      'og:title' => array(
        'value' => '[site:name]',
      ),
      'og:type' => array(
        'value' => 'website',
      ),
      'og:url' => array(
        'value' => '[site:url]',
      ),
    ),
  );

  // Exported Metatag config instance: global:404.
  $config['global:404'] = array(
    'instance' => 'global:404',
    'disabled' => FALSE,
    'config' => array(
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'shortlink' => array(
        'value' => '[site:url]',
      ),
      'og:title' => array(
        'value' => '[site:name]',
      ),
      'og:type' => array(
        'value' => 'website',
      ),
      'og:url' => array(
        'value' => '[site:url]',
      ),
    ),
  );

  // Exported Metatag config instance: global:frontpage.
  $config['global:frontpage'] = array(
    'instance' => 'global:frontpage',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => 'National Audubon Society',
      ),
      'description' => array(
        'value' => 'Audubon’s mission is to conserve and restore natural ecosystems, focusing on birds, other wildlife, and their habitats for the benefit of humanity and the earth\'s biological diversity.',
      ),
      'abstract' => array(
        'value' => 'Audubon’s mission is to conserve and restore natural ecosystems, focusing on birds, other wildlife, and their habitats for the benefit of humanity and the earth\'s biological diversity.',
      ),
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'shortlink' => array(
        'value' => '[site:url]',
      ),
      'og:site_name' => array(
        'value' => 'National Audubon Society',
      ),
      'og:type' => array(
        'value' => 'website',
      ),
      'og:url' => array(
        'value' => '[site:url]',
      ),
      'og:title' => array(
        'value' => 'National Audubon Society',
      ),
      'og:determiner' => array(
        'value' => 'the',
      ),
      'og:description' => array(
        'value' => 'Audubon’s mission is to conserve and restore natural ecosystems, focusing on birds, other wildlife, and their habitats for the benefit of humanity and the earth\'s biological diversity.',
      ),
      'og:image' => array(
        'value' => 'https://www.audubon.org/sites/default/files/sartore_FB.jpg',
      ),
      'og:image:type' => array(
        'value' => 'image/jpeg',
      ),
      'og:image:width' => array(
        'value' => 1200,
      ),
      'og:image:height' => array(
        'value' => 630,
      ),
    ),
  );

  // Exported Metatag config instance: node.
  $config['node'] = array(
    'instance' => 'node',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => '[node:title] | [site:name]',
      ),
      'description' => array(
        'value' => '[node:summary]',
      ),
      'og:title' => array(
        'value' => '[node:title]',
      ),
      'og:description' => array(
        'value' => '[node:field_editorial_card_subtitle]',
      ),
      'og:updated_time' => array(
        'value' => '[node:changed:custom:c]',
      ),
      'og:image' => array(
        'value' => '[node:field_editorial_card_image]',
      ),
      'article:published_time' => array(
        'value' => '[node:created:custom:c]',
      ),
      'article:modified_time' => array(
        'value' => '[node:changed:custom:c]',
      ),
    ),
  );

  // Exported Metatag config instance: node:article.
  $config['node:article'] = array(
    'instance' => 'node:article',
    'disabled' => FALSE,
    'config' => array(
      'description' => array(
        'value' => '[node:field_subtitle]',
      ),
      'robots' => array(
        'value' => array(
          'notranslate' => 'notranslate',
          'index' => 0,
          'follow' => 0,
          'noindex' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
          'noimageindex' => 0,
        ),
      ),
      'og:title' => array(
        'value' => '[node:editorial_card_title]',
      ),
      'og:description' => array(
        'value' => '[node:field_subtitle]',
      ),
      'og:image' => array(
        'value' => '[node:field_social_media_photo:social_media_photo],[node:editorial_card_image:hero_mobile]',
      ),
      'article:published_time' => array(
        'value' => '[node:field_article_date]',
      ),
      'twitter:card' => array(
        'value' => 'summary_large_image',
      ),
      'twitter:creator' => array(
        'value' => '@audubonsociety',
      ),
      'twitter:url' => array(
        'value' => '[current-page:url:absolute]',
      ),
      'twitter:title' => array(
        'value' => '[node:editorial_card_title]',
      ),
      'twitter:description' => array(
        'value' => '[node:field_subtitle]',
      ),
      'twitter:image' => array(
        'value' => '[node:meta_twitter_photo]',
      ),
    ),
  );

  // Exported Metatag config instance: node:bird.
  $config['node:bird'] = array(
    'instance' => 'node:bird',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => '[node:title] | Audubon Field Guide',
      ),
      'description' => array(
        'value' => '[node:field_bird_description]',
      ),
      'og:description' => array(
        'value' => '[node:field_bird_description]',
      ),
      'og:image' => array(
        'value' => '[node:field_hero_image:facebook_image]',
      ),
    ),
  );

  // Exported Metatag config instance: node:conservation_news.
  $config['node:conservation_news'] = array(
    'instance' => 'node:conservation_news',
    'config' => array(
      'robots' => array(
        'value' => array(
          'noindex' => 'noindex',
          'index' => 0,
          'follow' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
      ),
    ),
  );

  // Exported Metatag config instance: node:project.
  $config['node:project'] = array(
    'instance' => 'node:project',
    'disabled' => FALSE,
    'config' => array(
      'description' => array(
        'value' => '[node:editorial_card_subtitle]',
      ),
      'og:title' => array(
        'value' => '[node:editorial_card_title]',
      ),
      'og:description' => array(
        'value' => '[node:editorial_card_subtitle]',
      ),
      'og:image' => array(
        'value' => '[node:editorial_card_image:hero_mobile]',
      ),
    ),
  );

  // Exported Metatag config instance: node:slideshow.
  $config['node:slideshow'] = array(
    'instance' => 'node:slideshow',
    'disabled' => FALSE,
    'config' => array(
      'description' => array(
        'value' => '[node:editorial_card_subtitle]',
      ),
      'og:title' => array(
        'value' => '[node:editorial_card_title]',
      ),
      'og:description' => array(
        'value' => '[node:editorial_card_subtitle]',
      ),
      'og:image' => array(
        'value' => '[node:editorial_card_image:hero_mobile]',
      ),
    ),
  );

  // Exported Metatag config instance: node:static_page.
  $config['node:static_page'] = array(
    'instance' => 'node:static_page',
    'disabled' => FALSE,
    'config' => array(
      'description' => array(
        'value' => '[node:editorial_card_subtitle]',
      ),
      'og:title' => array(
        'value' => '[node:editorial_card_title]',
      ),
      'og:description' => array(
        'value' => '[node:editorial_card_subtitle]',
      ),
      'og:image' => array(
        'value' => '[node:editorial_card_image:hero_mobile]',
      ),
    ),
  );

  // Exported Metatag config instance: taxonomy_term.
  $config['taxonomy_term'] = array(
    'instance' => 'taxonomy_term',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => '[term:name] | [site:name]',
      ),
      'description' => array(
        'value' => '[term:description]',
      ),
      'og:description' => array(
        'value' => '[term:description]',
      ),
      'og:title' => array(
        'value' => '[term:name]',
      ),
    ),
  );

  // Exported Metatag config instance: user.
  $config['user'] = array(
    'instance' => 'user',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => '[user:name] | [site:name]',
      ),
      'og:title' => array(
        'value' => '[user:name]',
      ),
      'og:type' => array(
        'value' => 'profile',
      ),
      'profile:username' => array(
        'value' => '[user:name]',
      ),
    ),
  );

  return $config;
}
