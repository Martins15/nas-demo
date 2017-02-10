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
      <select data-ng-model="resultsC.storage.attribute"
              data-ng-options="term.name for term in resultsC.storage.data.terms.native_plant_attributes track by term.tid"
              data-ng-change="resultsC.setFilter('attribute', resultsC.storage.attribute.tid, 'page')">
      </select>
      <select data-ng-model="resultsC.storage.resource"
              data-ng-options="term.name for term in resultsC.storage.data.terms.native_plant_resources track by term.tid"
              data-ng-change="resultsC.setFilter('resource', resultsC.storage.resource.tid, 'page')">
      </select>
      <select data-ng-model="resultsC.storage.bird_type"
              data-ng-options="term.name for term in resultsC.storage.data.terms.native_plant_bird_types track by term.tid"
              data-ng-change="resultsC.setFilter('bird_type', resultsC.storage.bird_type.tid, 'page')">
      </select>
    </div>
    <div class="view-filters-controls clearfix">
      <div class="filters-controls-wrapper">
        <fieldset>
          <legend><?php print t('Sort by'); ?></legend>
          <div class="form-item form-item-radio">
            <input type="radio" class="form-radio" name="native-plants-sort" id="common-name" value="CommonName"
                   data-ng-model="resultsC.storage.stateParams.orderBy"/>
            <label for="common-name"><?php print t('Common Name'); ?></label>
          </div>
          <div class="form-item form-item-radio">
            <input type="radio" class="form-radio" name="native-plants-sort" id="scientific-name" value="ScientificName"
                   data-ng-model="resultsC.storage.stateParams.orderBy"/>
            <label for="scientific-name"><?php print t('Scientific Name'); ?></label>
          </div>
        </fieldset>
      </div>
      <input class="form-text" type="text" placeholder="<?php print t('Filter by plant name'); ?>"
             data-ng-model="resultsC.storage.stateParams.text_search"
             data-ng-model-options="{ debounce: 500 }"
             data-ng-change="resultsC.storage.applyTextSearch('')"/>
      <button class="button tomato large"
              data-ng-click="resultsC.storage.clearFilters()"><?php print t('Clear all filters'); ?></button>
    </div>
  </div>

  <!--View Content-->
  <div class="view-content row">
    <div class="native-plants-full-search-results">
      <div class="columns">
        <table class="hide-for-tiny hide-for-small">
          <thead>
          <tr>
            <th><?php print t('Plant name'); ?></th>
            <th><?php print t('Scientific name'); ?></th>
            <th><?php print t('Attributes'); ?></th>
            <th><?php print t('May attract'); ?></th>
          </tr>
          </thead>
          <tbody>
          <tr data-ng-repeat="plant in resultsC.storage.results_filtered |
              orderBy : resultsC.storage.stateParams.orderBy |
              limitTo : resultsC.storage.pager.items_per_page : ((resultsC.storage.stateParams.page - 1) * resultsC.storage.pager.items_per_page)">
            <td>
              <div class="plant--add-to-list">
                <input type="checkbox" id="checkbox-f{{plant.PlantID}}" class="np-checkbox"
                       data-ng-model="resultsC.storage.localStorage.cart[plant.PlantID].selected"
                       data-ng-change="resultsC.storage.updateCart(plant)"/>
                <label for="checkbox-f{{plant.PlantID}}"
                       data-ng-bind="plant.CommonName"></label>
                <a class="icon-camera clearing-attach" title="<?php print t('Preview'); ?>"
                   data-ng-if="plant.PlantImgLightbox"
                   data-ng-href="{{plant.PlantImgLightbox}}"></a>
                <ul data-clearing class="clearing-thumbs"
                    data-ng-if="plant.PlantImgLightbox">
                  <li>
                    <a target="_self" data-ng-href="{{plant.PlantImgLightbox}}"></a>
                  </li>
                </ul>
                <?php if (user_access('create native_plant content')): ?>
                  <br><span><a data-ng-href="{{plant.LocalLink}}" target="_blank"><?php print t('Add/edit local info'); ?></a></span>
                <?php endif; ?>
              </div>
            </td>
            <td><em data-ng-bind="plant.ScientificName"></em></td>
            <td>
              <ul class="clearfix plant-attributes-list plant-attributes-list-small">
                <li data-ng-repeat="attributeID in plant.Attributes">
                  <a href="javascript:void(0)" class="native-plants-attribute"
                     data-tid="{{attributeID}}"
                     style="background-color: {{resultsC.storage.data.terms.native_plant_attributes[attributeID].color}};"
                     data-ng-bind="resultsC.storage.data.terms.native_plant_attributes[attributeID].name"
                     data-ng-click="resultsC.storage.setStateParam('attribute', attributeID, 'page')"></a>
                </li>
                <li data-ng-repeat="resourceID in plant.Resources">
                  <a href="javascript:void(0)" class="native-plants-attribute"
                     data-tid="{{resourceID}}"
                     style="background-color: {{resultsC.storage.data.terms.native_plant_resources[resourceID].color}};"
                     data-ng-bind="resultsC.storage.data.terms.native_plant_resources[resourceID].name"
                     data-ng-click="resultsC.storage.setStateParam('resource', resourceID, 'page')"></a>
                </li>
              </ul>
            </td>
            <td>
              <ul class="native-plant-bird-category--list">
                <li data-ng-repeat="birdTypeID in plant.BirdTypes">
                  <a target="_blank"
                     data-ng-href="{{resultsC.storage.data.terms.native_plant_bird_types[birdTypeID].url}}"
                     data-ng-bind="resultsC.storage.data.terms.native_plant_bird_types[birdTypeID].name"></a></li>
              </ul>
            </td>
          </tr>
          </tbody>
        </table>
      </div>

      <div class="mobile-search-full-results hide-for-medium hide-for-large hide-for-xlarge">
        <div class="clearfix view-row"
             data-ng-repeat="plant in resultsC.storage.results_filtered |
             orderBy : resultsC.storage.stateParams.orderBy |
             limitTo : resultsC.storage.pager.items_per_page : ((resultsC.storage.stateParams.page - 1) * resultsC.storage.pager.items_per_page)">
          <div class="columns">
            <div>
              <span class="mobile-search-full-results--label"><?php print t('Plant'); ?>:</span>
              {{plant.CommonName}}
              <a class="icon-camera clearing-attach" title="<?php print t('Preview'); ?>"
                 data-ng-if="plant.PlantImgLightbox"
                 data-ng-href="plant.PlantImgLightbox"></a>
              <ul data-clearing class="clearing-thumbs"
                  data-ng-if="plant.PlantImgLightbox">
                <li>
                  <a target="_self" data-ng-href="{{plant.PlantImgLightbox}}"></a>
                </li>
              </ul>
            </div>
            <div>
              <span class="mobile-search-full-results--label"><?php print t('Scientific name'); ?>:</span>
              <em data-ng-bind="plant.ScientificName"></em>
            </div>
            <div>
              <span class="mobile-search-full-results--label"><?php print t('Attributes'); ?>:</span>
              <ul class="mobile-plant-attributes--list">
                <li data-ng-repeat="attributeID in plant.Attributes">
                  <a href="javascript:void(0)" class="native-plants-attribute"
                     data-tid="{{attributeID}}"
                     style="color: {{resultsC.storage.data.terms.native_plant_attributes[attributeID].color}};"
                     data-ng-bind="resultsC.storage.data.terms.native_plant_attributes[attributeID].name"
                     data-ng-click="resultsC.storage.setStateParam('attribute', attributeID, 'page')"></a></li>
                <li data-ng-repeat="resourceID in plant.Resources">
                  <a href="javascript:void(0)" class="native-plants-attribute"
                     data-tid="{{resourceID}}"
                     style="color: {{resultsC.storage.data.terms.native_plant_resources[resourceID].color}};"
                     data-ng-bind="resultsC.storage.data.terms.native_plant_resources[resourceID].name"
                     data-ng-click="resultsC.storage.setStateParam('resource', resourceID, 'page')"></a></li>
              </ul>
            </div>
            <div>
              <span class="mobile-search-full-results--label"><?php print t('Attracts'); ?>:</span>
              <ul class="mobile-plant-attracts--list">
                <li data-ng-repeat="birdTypeID in plant.BirdTypes">
                  <a target="_blank"
                     data-ng-href="{{resultsC.storage.data.terms.native_plant_bird_types[birdTypeID].url}}"
                     data-ng-bind="resultsC.storage.data.terms.native_plant_bird_types[birdTypeID].name"></a></li>
              </ul>
            </div>
            <div class="plant--add-to-list">
              <input type="checkbox" id="checkbox-f{{plant.PlantID}}-s" class="np-checkbox"
                     data-ng-model="resultsC.storage.localStorage.cart[plant.PlantID].selected"
                     data-ng-change="resultsC.storage.updateCart(plant)"/>
              <label for="checkbox-f{{plant.PlantID}}-s"><?php print t('Add to your plant list'); ?></label>
            </div>
          </div>
        </div>
      </div>

    </div>
  </div>

  <!--Pager-->
  <div class="search-results-total row">
    <div class="column medium-12 large-3 hide-for-tiny hide-for-small"
         data-ng-bind-html="resultsC.pagerResults(resultsC.storage.results_filtered.length)"></div>
    <div class="column medium-12 large-9">
      <ul class="pager-list">
        <li class="pager-prev">
          <a href="javascript:void(0)" data-ng-if="resultsC.storage.pager.pager_items.previous.link"
             data-ng-click="resultsC.storage.setStateParam('page', resultsC.storage.pager.pager_items.previous.page)"><?php print t('Previous page'); ?></a>
          <span class="pager-prev" data-ng-if="!resultsC.storage.pager.pager_items.previous.link"><?php print t('Previous page'); ?></span>
        </li>
        <li class="pager-item" data-ng-if="resultsC.storage.pager.pager_items.first.link">
          <a href="javascript:void(0)" title=""
             data-ng-click="resultsC.storage.setStateParam('page', resultsC.storage.pager.pager_items.first.page)"
             data-ng-bind="resultsC.storage.pager.pager_items.first.page"></a>
        </li>
        <li class="pager-item pager-item--ellipsis"
            data-ng-if="resultsC.storage.pager.pager_items.separator_left">
          <span>...</span>
        </li>
        <li class="pager-item" data-ng-repeat="item in resultsC.storage.pager.pager_items.items_before">
          <a href="javascript:void(0)" title=""
             data-ng-click="resultsC.storage.setStateParam('page', item.page)"
             data-ng-bind="item.page"></a>
        </li>
        <li class="pager-item">
          <span data-ng-bind="resultsC.storage.pager.pager_items.current.page"></span>
        </li>
        <li class="pager-item" data-ng-repeat="item in resultsC.storage.pager.pager_items.items_after">
          <a href="javascript:void(0)" title=""
             data-ng-click="resultsC.storage.setStateParam('page', item.page)"
             data-ng-bind="item.page"></a>
        </li>
        <li class="pager-item pager-item--ellipsis"
            data-ng-if="resultsC.storage.pager.pager_items.separator_right">
          <span >...</span>
        </li>
        <li class="pager-item" data-ng-if="resultsC.storage.pager.pager_items.last.link">
          <a href="javascript:void(0)" title=""
             data-ng-click="resultsC.storage.setStateParam('page', resultsC.storage.pager.pager_items.last.page)"
             data-ng-bind="resultsC.storage.pager.pager_items.last.page"></a>
        </li>
        <li class="pager-next">
          <a href="javascript:void(0)" data-ng-if="resultsC.storage.pager.pager_items.next.link"
             data-ng-click="resultsC.storage.setStateParam('page', resultsC.storage.pager.pager_items.next.page)"><?php print t('Next page'); ?></a>
          <span class="pager-next" data-ng-if="!resultsC.storage.pager.pager_items.next.link"><?php print t('Next page'); ?></span>
        </li>
      </ul>
    </div>
  </div>

</div>
