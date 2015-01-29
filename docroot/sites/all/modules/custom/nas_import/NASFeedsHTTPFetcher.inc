<?php

/**
 * @file
 * Custom Feeds fetcher and fetcher result.
 */

/**
 * Override to use cache.
 */
class NASFeedsHTTPFetcherResult extends FeedsHTTPFetcherResult {
  /**
   * Overrides FeedsFetcherResult::getRaw();
   */
  public function getRaw() {

    $cached_filepath = variable_get('nas_cached_files_folder', NAS_FILES_CACHE_DIR) . '/urls/' . preg_replace('/[^A-Za-z0-9-.]/', '-', $this->url) . '.txt';
    if (file_exists($cached_filepath)) {
      $data = file_get_contents($cached_filepath);
    }
    else {
      feeds_include_library('http_request.inc', 'http_request');

      // Propeople debugging performance.
      $time_pre = microtime(TRUE);
      $result = http_request_get($this->url, NULL, NULL, NULL, $this->timeout);
      $time_post = microtime(TRUE);
      watchdog('feeds-http-request', '%export', array('%export' => '<pre>' . $time_post - $time_pre . '</pre>'));

      if (!in_array($result->code, array(200, 201, 202, 203, 204, 205, 206))) {
        throw new Exception(t('3Download of @url failed with code !code.', array('@url' => $this->url, '!code' => $result->code)));
      }

      $data = $result->data;

      $cached_directory = drupal_dirname($cached_filepath);
      file_prepare_directory($cached_directory, FILE_CREATE_DIRECTORY);
      file_put_contents($cached_filepath, $data);
    }
    return $this->sanitizeRaw($data);
  }
}

/**
 * Extend basic FeedsHTTPFetcher to use NASFeedsHTTPFetcherResult.
 */
class NASFeedsHTTPFetcher extends FeedsHTTPFetcher {

  /**
   * Implements FeedsFetcher::fetch().
   */
  public function fetch(FeedsSource $source) {
    $source_config = $source->getConfigFor($this);
    if ($this->config['use_pubsubhubbub'] && ($raw = $this->subscriber($source->feed_nid)->receive())) {
      return new FeedsFetcherResult($raw);
    }

    // This is the only change from original FeedsHTTPFetcher.
    $fetcher_result = new NASFeedsHTTPFetcherResult($source_config['source']);
    // End of change from original FeedsHTTPFetcher.

    // When request_timeout is empty, the global value is used.
    $fetcher_result->setTimeout($this->config['request_timeout']);
    return $fetcher_result;
  }
}
