<?php
/**
 * TPL file for CT content type.
 */
?>
<aside class="ct-landscapes-main">
    <div class="filter-block__menu-block hide-for-medium hide-for-small hide-for-tiny dark-style">
        <ul class="first-level">
            <li class="js-open"><p>Strategies<i class="plus"></i></p>
                <ul class="second-level">
                    <li><p>Coasts<i class="down"></i></p></li>
                    <li class="js-open"><p>Working Land<i class="down"></i></p>
                    </li>
                    <li><p>Water<i class="down"></i></p></li>
                </ul>
            </li>
            <li><p>Guild<i class="plus"></i></p></li>
            <li><p>Threat Status<i class="plus"></i></p></li>
        </ul>
    </div>
    <div class="wrap-map-diagram">
      <?php print $map; ?>
    </div>
</aside>
