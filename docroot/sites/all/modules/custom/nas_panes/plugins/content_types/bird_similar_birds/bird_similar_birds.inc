<?php

/**
 * @file
 * Similar birds pane for the bird node view.
 */

$plugin = array(
  'title' => t('Bird Similar Birds'),
  'description' => t('Similar birds pane.'),
  'category' => 'NAS',
  'render callback' => 'bird_similar_birds_render',
  'hook theme' => 'bird_similar_birds_theme',
  'required context' => array(
    new ctools_context_required(t('Node'), 'node'),
  ),
);

/**
 * Render callback.
 */
function bird_similar_birds_render($subtype, $conf, $args, $context) {
  $node = reset($context)->data;
  if (empty($node->type) || $node->type !== 'bird' || empty($node->field_related_bird[LANGUAGE_NONE][0]['target_id'])) {
    return;
  }

  $birds = array();
  foreach ($node->field_related_bird[LANGUAGE_NONE] as $ref) {
    $ref_node = _i18n_node_load($ref['target_id']);
    $renderable = node_view($ref_node, 'teaser');
    $birds[] = drupal_render($renderable);
  }

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'bird_similar_birds',
    '#title' => t('Explore Similar Birds'),
    '#bird_guide_link' => l(t('The Bird Guide'), 'bird-guide'),
    '#adopt_bird_link' => l(t('Adopt a Bird'), 'https://secure.audubon.org/site/SPageNavigator/2014_Adoption_Catalog_Homepage.html',
      array('attributes' => array('class' => array('cta')))),
    '#birds' => $birds,
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function bird_similar_birds_theme(&$theme, $plugin) {
  $theme['bird_similar_birds'] = array(
    'variables' => array(
      'title' => '',
      'bird_guide_link' => '',
      'adopt_bird_link' => '',
      'birds' => array(),
    ),
    'template' => 'bird-similar-birds',
    'path' => $plugin['path'],
  );
}
