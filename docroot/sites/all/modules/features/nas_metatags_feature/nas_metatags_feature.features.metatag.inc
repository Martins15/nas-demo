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
    'config' => array(
      'title' => array(
        'value' => '[site:name]',
      ),
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'shortlink' => array(
        'value' => '[site:url]',
      ),
      'og:description' => array(
        'value' => '[site:slogan]',
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

  // Exported Metatag config instance: node.
  $config['node'] = array(
    'instance' => 'node',
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
      'article:published_time' => array(
        'value' => '[node:field_article_date]',
      ),
    ),
  );

  // Exported Metatag config instance: node:project.
  $config['node:project'] = array(
    'instance' => 'node:project',
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
