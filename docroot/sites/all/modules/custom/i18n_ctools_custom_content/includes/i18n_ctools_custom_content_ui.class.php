<?php

/**
 * i18n_ctools_custom_content_ui class.
 */

module_load_include('php', 'ctools_custom_content', 'plugins/export_ui/ctools_custom_content_ui.class');

class i18n_ctools_custom_content_ui extends ctools_custom_content_ui {

  public function edit_form(&$form, &$form_state) {
    parent::edit_form($form, $form_state);

    if (empty($form_state['item']->cid)) {
      $form['language'] = array(
        '#prefix' => '<div class="messages status">',
        '#suffix' => '</div>',
        '#type' => 'markup',
        '#markup' => t('You are going to create %language translation of the %name custom content', array(
          '%language' => $form_state['item']->language,
          '%name' => $form_state['item']->name,
        )),
        '#weight' => -1,
      );
    }
  }

}
