<?php
/**
 * @file
 * Contains NASFeedsExJsonPath.
 */

class NASFeedsExJsonPath extends FeedsExJsonPath {
  /**
   * {@inheritdoc}
   */
  protected function executeContext(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $raw = $fetcher_result->getRaw();
    if ($encoding = $this->detectEncoding($raw)) {
      $raw = $this->convertEncoding($raw, $encoding);
    }

    $parsed = drupal_json_decode($raw);
    if (!is_array($parsed)) {
      $parsed = drupal_json_decode($parsed);
    }
    return jsonPath($parsed, $this->config['context']['value']);
  }
}
