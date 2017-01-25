<?php

/**
 * @file
 * Provides a simple cache storage class to for NetX.
 */

/**
 * Implements class NetXRepositoryProxyStorage.
 */
class NetXRepositoryProxyStorage {

  /**
   * Categories cache ID.
   *
   * @var string
   */
  static $CATEGORIES_CACHE_ID = 'netx_repository_proxy_storage_categories';

  /**
   * Assets cache ID prefix.
   *
   * @var string
   */
  static $ASSETS_CACHE_ID_PREFIX = 'netx_repository_proxy_storage_assets_';

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
    cache_set(self::$CATEGORIES_CACHE_ID, $categories);
    return $categories;
  }

  /**
   * Retrieves the categories cache.
   *
   * @return array
   *   Array of the categories.
   */
  public function getCategories() {
    $cache = cache_get(self::$CATEGORIES_CACHE_ID);
    return $cache ? $cache->data : array();
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
    return self::$ASSETS_CACHE_ID_PREFIX . $cid;
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
    cache_set($this->getAssetsVariableName($cid), $assets, 'cache', time() + 86400);
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
    $cache = cache_get($this->getAssetsVariableName($cid));

    // Cache lifetime.
    if (!$cache || time() > $cache->expire) {
      return array();
    }

    return $cache->data;
  }

}
