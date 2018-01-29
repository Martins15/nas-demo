<?php

/**
 * @file
 * Template for Native Plants bar.
 */
?>
<div class="<?php print !empty($context_links) ? 'contextual-links-region' : ''; ?>"
  <?php if ($type == 'extended'): ?>
    style="background-color: #<?php print $background_color; ?>;"
  <?php endif; ?>
>
  <?php print $context_links; ?>
  <?php if ($type == 'simple'): ?>
    <div class="row">
      <div class="columns list-of-park">
        <div class="div list-of-park__current-page">
          <a class="" href="#"><?php print $current_park_title ?></a>
        </div>
        <div class="list-of-park__others-page">
          <?php foreach ($parks as $nid => $park_title): ?>
            <a href="node/<?php print $nid ?>"><?php print $park_title ?></a>
          <?php endforeach; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>
  <?php if ($type == 'extended'): ?>
    <div class="row">
      <div class="columns">
        <div class="native-plants-green-row">
          <label for=""><?php print $select_park_label ?></label>
          <?php foreach ($parks_map_terms as $tid => $map): ?>
            <ul>
              <li class="<?php print $tid ?>"><?php print $map['title'] ?>
                <ul>
                  <?php foreach ($map['nodes'] as $nid => $park_title): ?>
                    <li>
                      <a href="node/<?php print $nid ?>"><?php print $park_title ?></a>
                    </li>
                  <?php endforeach; ?>
                </ul>
              </li>
            </ul>
          <?php endforeach; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>
</div>