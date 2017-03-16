<?php

/**
 * File info?
 */

/**
 * Interface needed to handle storage and export of H5P Content.
 */
interface H5PFileStorage {

  /**
   * Store the library folder.
   *
   * @param array $library
   *  Library properties
   */
  public function saveLibrary($library);

  /**
   * Store the content folder.
   *
   * @param string $source
   *  Path on file system to content directory.
   * @param array $content
   *  Content properties
   */
  public function saveContent($source, $content);

  /**
   * Remove content folder.
   *
   * @param array $content
   *  Content properties
   */
  public function deleteContent($content);

  /**
   * Creates a stored copy of the content folder.
   *
   * @param string $id
   *  Identifier of content to clone.
   * @param int $newId
   *  The cloned content's identifier
   */
  public function cloneContent($id, $newId);

  /**
   * Get path to a new unique tmp folder.
   *
   * @return string
   *  Path
   */
  public function getTmpPath();

  /**
   * Fetch content folder and save in target directory.
   *
   * @param int $id
   *  Content identifier
   * @param string $target
   *  Where the content folder will be saved
   */
  public function exportContent($id, $target);

  /**
   * Fetch library folder and save in target directory.
   *
   * @param array $library
   *  Library properties
   * @param string $target
   *  Where the library folder will be saved
   */
  public function exportLibrary($library, $target);

  /**
   * Save export in file system
   *
   * @param string $source
   *  Path on file system to temporary export file.
   * @param string $filename
   *  Name of export file.
   */
  public function saveExport($source, $filename);

  /**
   * Removes given export file
   *
   * @param string $filename
   */
  public function deleteExport($filename);

  /**
   * Check if the given export file exists
   *
   * @param string $filename
   * @return boolean
   */
  public function hasExport($filename);

  /**
   * Will concatenate all JavaScrips and Stylesheets into two files in order
   * to improve page performance.
   *
   * @param array $files
   *  A set of all the assets required for content to display
   * @param string $key
   *  Hashed key for cached asset
   */
  public function cacheAssets(&$files, $key);

  /**
   * Will check if there are cache assets available for content.
   *
   * @param string $key
   *  Hashed key for cached asset
   * @return array
   */
  public function getCachedAssets($key);

  /**
   * Remove the aggregated cache files.
   *
   * @param array $keys
   *   The hash keys of removed files
   */
  public function deleteCachedAssets($keys);

  /**
   * Read file content of given file and then return it.
   *
   * @param string $file_path
   * @return string contents
   */
  public function getContent($file_path);

  /**
   * Save files uploaded through the editor.
   * The files must be marked as temporary until the content form is saved.
   *
   * @param \H5peditorFile $file
   * @param int $contentid
   */
  public function saveFile($file, $contentId);

  /**
   * Copy a file from another content or editor tmp dir.
   * Used when copy pasting content in H5P.
   *
   * @param string $file path + name
   * @param string|int $fromid Content ID or 'editor' string
   * @param int $toid Target Content ID
   */
  public function cloneContentFile($file, $fromId, $toId);

  /**
   * Checks to see if content has the given file.
   * Used when saving content.
   *
   * @param string $file path + name
   * @param int $contentId
   * @return string|int File ID or NULL if not found
   */
  public function getContentFile($file, $contentId);

  /**
   * Remove content files that are no longer used.
   * Used when saving content.
   *
   * @param string $file path + name
   * @param int $contentId
   */
  public function removeContentFile($file, $contentId);
}
