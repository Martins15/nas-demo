<?php
/**
 * TPL file for CT content type.
 */
?>
<div class="tabs" data-ng-controller="Tabs">
    <span>$state = <b>{{$state.current.name}}</b></span><br>
    <span>$state url = <b>{{$state.$current.url.source}}</b></span>
    <ul>
        <li
                ng-repeat="tab in tabs"
                heading="{{ tab.heading }}"
                ui-sref="{{ tab.route }}"
                active="tab.active">{{ tab.heading }}
        </li>
    </ul>
</div>


<div class="ct-scorecard-main">
  <?php //print $map; ?>
  <?php print $actions; ?>
  <?php print $objectives; ?>
</div>
