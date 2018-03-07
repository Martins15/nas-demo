<?php

/**
 * Class NASFeedsExJsonPath.
 */
class NASFeedsExJsonPath extends FeedsExJsonPath {

  /**
   * {@inheritdoc}
   */
  protected function executeContext(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $raw = $fetcher_result->getRaw();
    $raw = $this->getEncoder()->convertEncoding($raw);
    $parsed = drupal_json_decode($raw);
    if (!is_array($parsed)) {
      $parsed = drupal_json_decode($parsed);
    }
    return jsonPath($parsed, $this->config['context']['value']);
  }

}
