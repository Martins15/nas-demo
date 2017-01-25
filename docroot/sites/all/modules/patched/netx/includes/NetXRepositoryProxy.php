<?php

/**
 * @file
 * Provides a class to communicate to NetX.
 */

/**
 * Implements class NetXRepository.
 */
class NetXRepositoryProxy {

  /**
   * NetX Repository.
   *
   * @var NetXRepository
   */
  private static $repo = NULL;

  /**
   * Storage.
   *
   * @var NetXRepositoryProxyStorage
   */
  protected $storage;

  /**
   * Constructs NetXRepository.
   *
   * @param NetXRepository $repo
   *   The NetX repository to be proxied.
   */
  public function __construct() {
    self::getRepoInstance();
    $this->storage = new NetXRepositoryProxyStorage();
  }

  /**
   * Magic call method implementation.
   */
  public function __call($name, $args) {
    if (method_exists(self::$repo, $name)) {
      return call_user_func_array(array(self::$repo, $name), $args);
    }

    return NULL;
  }

  static public function getRepoInstance() {
    if (is_null(self::$repo)) {
      self::$repo = new NetXRepository();
    }
    return self::$repo;
  }

  /**
   * Download file content.
   *
   * @param string $path
   *   The remote path to file.
   *
   * @throws \Exception
   *   When no file received.
   *
   * @return mixed
   *   Binary stream.
   */
  public function getFileContent($path) {
    return self::$repo->getFileContent($path);
  }

  /**
   * Download file content (image) via REST API.
   *
   * @param int $asset_id
   *   The asset ID.
   * @param string $type
   *   The type ('thumb', 'preview', 'original').
   *
   * @throws \Exception
   *   When no file received.
   *
   * @return mixed
   *   Binary stream.
   */
  public function getImageFileContent($asset_id, $type = 'original') {
    return self::$repo->getImageFileContent($asset_id, $type);
  }

  /**
   * Retrieves a tree of categories.
   *
   * @param int $parent
   *   The parent category ID, default to root.
   *
   * @return array
   *   An array of categories.
   *
   * @throws \Exception
   *   When no connection to repository.
   */
  public function getCategoryTree($parent = 1) {
    if (!$category_tree = $this->storage->getCategories()) {
      $category_tree = self::$repo->getCategoryTree($parent);
      $this->storage->setCategories($category_tree);
    }
    return $category_tree;
  }

  /**
   * Retrieves a list of assets for category.
   *
   * @param int $cid
   *   Category ID.
   *
   * @return array
   *   An array of asets.
   * @throws \Exception
   *   When no connection to repository.
   */
  public function getAssetsForCategory($cid) {
    if (!$assets = $this->storage->getAssets($cid)) {
      $assets = self::$repo->getAssetsForCategory($cid);
      $this->storage->setAssets($cid, $assets);
    }

    return $assets;
  }

}
