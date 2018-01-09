<?php

/**
 * @file
 * Template of Article layout with Fullscreen image.
 *
 * Available variables:
 *  - $color_mode_text: text color mode for hero image.
 *  - $color_mode_gradient: gradient color mode for hero image.
 *
 * @impove
 *   These variables only available when rendering in NAS theme, so have to be
 *   sure they are initialized or notices will be generated in panels edit
 *   interface.
 *
 * @see nas_preprocess_nas_article_fullscreen()
 */
?>
<section class="global-content with-padding static-page-content">
    <div class="tabs ct-item-nav-conservation" ng-cloak data-ng-controller="Tabs">
        <div class="row">
            <div class="menu-wrap columns large-6">
                <ul>
                    <li
                            ng-repeat="tab in tabs"
                            ui-sref="{{ tab.route }}"
                            class="{{tab.heading}} {{tab.active}}">{{ tab.heading }}
                    </li>
                </ul>
            </div>
            <div class="text-wrap columns large-6">
                <div class="text-wrap__content" ng-cloak>
                    <div class="threats" ng-class="{'active': isActiveTab === 'threats'}">
                        <h4>Threats</h4>
                    </div>
                    <div class="actions" ng-class="{'active': isActiveTab === 'actions'}">
                        <h4>Actions</h4>
                    </div>
                    <div class="responses"  ng-class="{'active': isActiveTab === 'responses'}">
                        <h4>Responses</h4>
                    </div>
                    <div class="partners"  ng-class="{'active': isActiveTab === 'partners'}">
                        <h4>Partners</h4>
                    </div>
                </div>
            </div>
        </div>
    </div>
</section>
