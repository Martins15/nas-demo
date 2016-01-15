<div id="list-view" class="climate-flyway-map-container">
  <div id="flywaynav">
    <div class="row">
      <h2 class="flyway-map-label thin centered"><?php print t('Select a flyway to find birds near you'); ?></h2>
      <h5 class="flyway-label flyway-pacific-label"><?php print t('Pacific <br class="hide-for-xlarge hide-for-large">Flyway'); ?></h5>
      <h5 class="flyway-label flyway-central-label"><?php print t('Central <br class="hide-for-xlarge hide-for-large">Flyway'); ?></h5>
      <h5 class="flyway-label flyway-mississippi-label"><?php print t('Mississippi <br class="hide-for-xlarge hide-for-large">Flyway'); ?></h5>
      <h5 class="flyway-label flyway-atlantic-label"><?php print t('Atlantic <br class="hide-for-xlarge hide-for-large">Flyway'); ?></h5>
      <div id="flywaynavmap" class="climate-flyway-map">
      </div>
    </div>
    <div class="row">
      <div id="flywaylist" class="climate-flyway-overlay" style="display: none;">
        <a href="#" class="close"></a>
        <h2 class="thin"><span class="flyway-name"></span></h2>
        <div class="flyway-list-more"></div>
        <div class="flyway-list-sort-copy"><?php print $sort_description; ?></div>
        <table class="flyway-list-sort">
          <thead>
          <tr>
            <th width="45%" class="bird-list-header-name">
              <span class="flyway-list-button" data-reverse="false" data-sortcolumn="PRIMARY_COM_NAME"><?php print t('Bird Names'); ?></span>
            </th>
            <th width="27.5%" class="bird-list-header-percent">
              <span class="flyway-list-button" data-reverse="false" data-sortcolumn="percentageLost.BBS"><?php print t('Summer Range Lost'); ?></span>
            </th>
            <th width="27.5%" class="bird-list-header-percent">
              <span class="flyway-list-button" data-reverse="false" data-sortcolumn="percentageLost.CBC"><?php print t('Winter Range Lost'); ?></span>
            </th>
          </tr>
          </thead>
        </table>
        <table class="flyway-list-data">
          <tbody>

          </tbody>
        </table>
      </div>
      <div id="stateprovincelist" class="climate-flyway-overlay" style="display: none;">
        <a href="#" class="close"></a>
        <h2 class="thin"><?php print t('<span class="flyway-name"></span> Flyway'); ?></h2>
        <div class="flyway-description"></div>
        <ul>
        </ul>
      </div>
    </div>
  </div>
</div>

<div class="microsite-bird-search-lower hide-for-xlarge hide-for-large row">
  <div class="column">
    <input class="microsite-bird-search" type="search" placeholder="<?php print t('Search for a specific bird here'); ?>" />
  </div>
</div>