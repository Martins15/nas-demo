<?php

/**
 * @file
 * Provides a simple cache storag class to for NetX.
 */

/**
 * Implements class NetXRepositoryProxyStorage.
 */
class NetXRepositoryProxyStorage {

  /**
   * Sets categories cache.
   *
   * @param array $categories
   *   Array of categories.
   *
   * @return mixed
   *   Array of categories.
   */
  public function setCategories($categories) {
    variable_set('netx_repository_proxy_storage_categories', $categories);
    return $categories;
  }

  /**
   * Retrieves the categories cache.
   *
   * @return array
   *   Array of the categories.
   */
  public function getCategories() {
    return variable_get('netx_repository_proxy_storage_categories', array());
  }

  /**
   * Defines the name of the drupal variable to store assets info.
   *
   * @param int $cid
   *   Category id.
   *
   * @return string
   *   The name of variable.
   */
  private function getAssetsVariableName($cid) {
    return 'netx_repository_proxy_storage_assets_' . $cid;
  }

  /**
   * Set category assets cache.
   *
   * @param int $cid
   *   Category id.
   * @param array $assets
   *   Category assets listing.
   *
   * @return array
   *   Category assets listing.
   */
  public function setAssets($cid, $assets) {
    $assets_data = array(
      'data' => $assets,
      'timestamp' => time(),
    );
    variable_set($this->getAssetsVariableName($cid), $assets_data);
    return $assets;
  }

  /**
   * Retrieves category assets cache.
   *
   * @param int $cid
   *   Category id.
   *
   * @return array
   *   Category assets listing.
   */
  public function getAssets($cid) {
    $assets_data = variable_get($this->getAssetsVariableName($cid), array());

    if (empty($assets_data['data'])) {
      return array();
    }
    // Cache lifetime.
    if (time() - $assets_data['timestamp'] > 86400) {
      return array();
    }

    return $assets_data['data'];
  }

}
