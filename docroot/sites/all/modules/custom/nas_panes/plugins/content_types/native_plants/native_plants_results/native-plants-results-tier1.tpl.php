<?php

/**
 * @file
 * Template for Native Plants results listing.
 */
?>
<div data-ng-controller="NativePlantsResultsController as resultsC">
  <!--View Filters-->
  <div class="view-filters">
    <div class="view-filters-select clearfix">
      <select class="search-select wrap-select-skip" multiple
              data-native-plants-multiselect
              data-placeholder="<?php print t('All types of plants'); ?>"
              data-ng-model="resultsC.storage.attribute_tier1"
              data-ng-options="term.name for term in resultsC.storage.data.terms.native_plant_attributes track by term.tid"
              data-ng-change="resultsC.setFilter('attribute_tier1', resultsC.storage.attribute_tier1, 'page_tier1')">
      </select>
      <select class="search-select wrap-select-skip" multiple
              data-native-plants-multiselect
              data-placeholder="<?php print t('All plant resources'); ?>"
              data-ng-model="resultsC.storage.resource_tier1"
              data-ng-options="term.name for term in resultsC.storage.data.terms.native_plant_resources track by term.tid"
              data-ng-change="resultsC.setFilter('resource_tier1', resultsC.storage.resource_tier1, 'page_tier1')">
      </select>
      <select class="search-select wrap-select-skip" multiple
              data-native-plants-multiselect
              data-placeholder="<?php print t('Attracts: Any type of bird'); ?>"
              data-ng-model="resultsC.storage.bird_type_tier1"
              data-ng-options="term.name for term in resultsC.storage.data.terms.native_plant_bird_types track by term.tid"
              data-ng-change="resultsC.setFilter('bird_type_tier1', resultsC.storage.bird_type_tier1, 'page_tier1')">
      </select>
    </div>
    <div class="view-filters-controls clearfix">
      <div class="filters-controls-wrapper">
        <fieldset>
          <legend><?php print t('Sort by'); ?></legend>
          <div class="form-item form-item-radio">
            <input type="radio" class="form-radio" name="native-plants-sort-tier1" id="common-name-tier1" value="CommonName"
                   data-ng-model="resultsC.storage.stateParams.orderBy_tier1"/>
            <label for="common-name-tier1"><?php print t('Common Name'); ?></label>
          </div>

          <div class="form-item form-item-radio">
            <input type="radio" class="form-radio" name="native-plants-sort-tier1" id="scientific-name-tier1" value="ScientificName"
                   data-ng-model="resultsC.storage.stateParams.orderBy_tier1"/>
            <label for="scientific-name-tier1"><?php print t('Scientific Name'); ?></label>
          </div>
        </fieldset>
      </div>
      <div class="form-filter--controls" data-ng-class="resultsC.textSearchProgressCheck('tier1')">
        <input class="form-text" type="text" placeholder="<?php print t('Filter by plant name'); ?>"
               data-ng-model="resultsC.storage.stateParams.text_search_tier1"
               data-ng-model-options="{ debounce: 250 }"/>
      </div>
      <button class="button tomato large"
              data-ng-click="resultsC.storage.clearFilters()"><?php print t('Clear all filters'); ?></button>
    </div>

    <div>
      <div class="form-item form-item-checkbox">
        <input type="checkbox" class="np-checkbox" id="select-all-tier1"
               data-ng-model="resultsC.storage.all_tier1_in_cart"
               data-ng-change="resultsC.storage.calculateTier1inCart()"/>
        <label for="select-all-tier1"
               data-ng-click="resultsC.storage.selectAllTier1()"><?php print t('Add all plants below to your list'); ?></label>
      </div>
    </div>
  </div>

  <!--View Content-->
  <div id="pager-scroll-page_tier1" class="view-content row">
    <div class="view-row columns"
         data-ng-repeat="plant in resultsC.storage.results_tier1_filtered |
         orderBy : resultsC.storage.stateParams.orderBy_tier1 |
         limitTo : resultsC.storage.pager_tier1.items_per_page : ((resultsC.storage.stateParams.page_tier1 - 1) * resultsC.storage.pager_tier1.items_per_page)">
      <div class="row" style="position: relative;">
        <div class="column medium-8">
          <h3>{{plant.CommonName}} (<em data-ng-bind="plant.ScientificName"></em>)</h3>
        </div>
      </div>
      <div class="row">
        <div class="column medium-8">
          <div class="row">
            <div class="column medium-4 tier-1-plant-picture hide-for-tiny hide-for-small"
                 data-ng-if="plant.PlantImgDesktop">
              <a href="#" class="clearing-attach" data-ng-bind-html="plant.PlantImgDesktop | trusted"></a>
              <ul data-clearing>
                <li style="display: none;">
                  <a target="_self"
                     data-ng-href="{{plant.PlantImgLightbox}}"
                     data-ng-bind-html="plant.PlantImgDesktop | trusted"></a>
                </li>
              </ul>
            </div>
            <div class="tier-1-plant-picture-mobile hide-for-medium hide-for-large hide-for-xlarge"
                 data-ng-if="plant.PlantImgMobile"
                 data-ng-bind-html="plant.PlantImgMobile"></div>
            <div class="column medium-4 hide-for-medium hide-for-large hide-for-xlarge">
              <h4><?php print t('Types of birds attracted'); ?></h4>
              <div class="bird-card-carousel">
                <div class="row">
                  <div class="owl-carousel">
                    <div class="node node-bird node-teaser clearfix"
                         data-ng-repeat="birdTypeID in plant.BirdTypesRandomized">
                      <figure class="bird-card">
                        <div class="bird-card-illustration">
                          <a data-ng-href="{{resultsC.storage.data.terms.native_plant_bird_types[birdTypeID].url}}" target="_blank">
                            <img alt="{{resultsC.storage.data.terms.native_plant_bird_types[birdTypeID].name}}"
                                 data-ng-src="{{resultsC.storage.data.terms.native_plant_bird_types[birdTypeID].image}}">
                          </a>
                        </div>
                        <figcaption class="bird-card-caption">
                          <h4 class="common-name">
                            <a target="_blank"
                               data-ng-href="{{resultsC.storage.data.terms.native_plant_bird_types[birdTypeID].url}}"
                               data-ng-bind="resultsC.storage.data.terms.native_plant_bird_types[birdTypeID].name"></a>
                          </h4>
                        </figcaption>
                      </figure>
                    </div>
                  </div>
                </div>
              </div>
            </div>
            <div class="column tier-1-plant"
                 data-ng-class="resultsC.plantDescriptionClass(plant)">
              <?php if (user_access('create native_plant content')): ?>
                <span><a data-ng-href="{{plant.LocalLink}}" target="_blank"><?php print t('Add/edit local info'); ?></a></span>
              <?php endif; ?>
              <div class="tier-1-plant--description" data-ng-if="plant.Description" data-ng-bind-html="plant.Description"></div>
              <div class="tier-1-plant--source" data-ng-if="plant.Source"><?php print t('Source') . ': '; ?>{{plant.Source}}</div>
              <ul class="clearfix plant-attributes-list">
                <li data-ng-repeat="attributeID in plant.Attributes">
                  <a href="javascript:void(0)" class="native-plants-attribute"
                     data-tid="{{attributeID}}"
                     style="background-color: {{resultsC.storage.data.terms.native_plant_attributes[attributeID].color}};"
                     data-ng-click="resultsC.setFilterLink('attribute_tier1', attributeID, 'page_tier1')"
                     data-ng-bind="resultsC.storage.data.terms.native_plant_attributes[attributeID].name"></a>
                </li>
                <li data-ng-repeat="resourceID in plant.Resources">
                  <a href="javascript:void(0)" class="native-plants-attribute"
                     data-tid="{{resourceID}}"
                     style="background-color: {{resultsC.storage.data.terms.native_plant_resources[resourceID].color}};"
                     data-ng-click="resultsC.setFilterLink('resource_tier1', resourceID, 'page_tier1')"
                     data-ng-bind="resultsC.storage.data.terms.native_plant_resources[resourceID].name"></a>
                </li>
              </ul>
              <div class="tier-1-plant--add-to-list">
                <input type="checkbox" id="checkbox-{{plant.PlantID}}" class="np-checkbox"
                       data-ng-model="resultsC.storage.localStorage.cart[plant.PlantID].selected"
                       data-ng-change="resultsC.storage.updateCart(plant)"/>
                <label for="checkbox-{{plant.PlantID}}"><?php print t('Add to your plant list'); ?></label>
              </div>
            </div>
          </div>
        </div>
        <div class="column medium-4 hide-for-tiny hide-for-small">
          <div class="bird-card-carousel">
            <div class="row">
              <div class="owl-carousel">
                <div class="node node-bird node-teaser clearfix"
                     data-ng-repeat="birdTypeID in plant.BirdTypesRandomized">
                  <figure class="bird-card">
                    <div class="bird-card-illustration">
                      <img alt="{{resultsC.storage.data.terms.native_plant_bird_types[birdTypeID].name}}"
                           data-ng-src="{{resultsC.storage.data.terms.native_plant_bird_types[birdTypeID].image}}">
                    </div>
                    <figcaption class="bird-card-caption">
                      <h4 class="common-name"
                          data-ng-bind="resultsC.storage.data.terms.native_plant_bird_types[birdTypeID].name">
                      </h4>
                    </figcaption>
                  </figure>
                  <a target="_blank"
                    class="bird-card-link"
                    data-ng-href="{{resultsC.storage.data.terms.native_plant_bird_types[birdTypeID].url}}"></a>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>

  <!--Pager-->
  <div class="search-results-total row">
    <div class="column medium-12 large-3 hide-for-tiny hide-for-small"
         data-ng-bind-html="resultsC.pagerResults(resultsC.storage.results_tier1_filtered.length)"></div>
    <div class="column medium-12 large-9">
      <ul class="pager-list">
        <li class="pager-prev">
          <a href="javascript:void(0)" data-ng-if="resultsC.storage.pager_tier1.pager_items.previous.link"
             data-ng-click="resultsC.setPage('page_tier1', resultsC.storage.pager_tier1.pager_items.previous.page)"><?php print t('Previous page'); ?></a>
          <span class="pager-prev" data-ng-if="!resultsC.storage.pager_tier1.pager_items.previous.link"><?php print t('Previous page'); ?></span>
        </li>
        <li class="pager-item" data-ng-if="resultsC.storage.pager_tier1.pager_items.first.link">
          <a href="javascript:void(0)" title=""
             data-ng-click="resultsC.setPage('page_tier1', resultsC.storage.pager_tier1.pager_items.first.page)"
             data-ng-bind="resultsC.storage.pager_tier1.pager_items.first.page"></a>
        </li>
        <li class="pager-item pager-item--ellipsis"
            data-ng-if="resultsC.storage.pager_tier1.pager_items.separator_left">
          <span>...</span>
        </li>
        <li class="pager-item" data-ng-repeat="item in resultsC.storage.pager_tier1.pager_items.items_before">
          <a href="javascript:void(0)" title=""
             data-ng-click="resultsC.setPage('page_tier1', item.page)"
             data-ng-bind="item.page"></a>
        </li>
        <li class="pager-item">
          <span data-ng-bind="resultsC.storage.pager_tier1.pager_items.current.page"></span>
        </li>
        <li class="pager-item" data-ng-repeat="item in resultsC.storage.pager_tier1.pager_items.items_after">
          <a href="javascript:void(0)" title=""
             data-ng-click="resultsC.setPage('page_tier1', item.page)"
             data-ng-bind="item.page"></a>
        </li>
        <li class="pager-item pager-item--ellipsis"
            data-ng-if="resultsC.storage.pager_tier1.pager_items.separator_right">
          <span >...</span>
        </li>
        <li class="pager-item" data-ng-if="resultsC.storage.pager_tier1.pager_items.last.link">
          <a href="javascript:void(0)" title=""
             data-ng-click="resultsC.setPage('page_tier1', resultsC.storage.pager_tier1.pager_items.last.page)"
             data-ng-bind="resultsC.storage.pager_tier1.pager_items.last.page"></a>
        </li>
        <li class="pager-next">
          <a href="javascript:void(0)" data-ng-if="resultsC.storage.pager_tier1.pager_items.next.link"
             data-ng-click="resultsC.setPage('page_tier1', resultsC.storage.pager_tier1.pager_items.next.page)"><?php print t('Next page'); ?></a>
          <span class="pager-next" data-ng-if="!resultsC.storage.pager_tier1.pager_items.next.link"><?php print t('Next page'); ?></span>
        </li>
      </ul>
    </div>
  </div>

</div>
