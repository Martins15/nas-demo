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
      <div class="columns">
        <div class="">
          <a class="" href="#"><?php print $current_park_title ?></a>
        </div>
        <div class="">
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
          <label for="parks_map_terms"><?php print $select_park_label ?></label>
          <select id="parks_map_terms">
            <?php foreach ($parks_map_terms as $tid => $map): ?>
              <option value="<?php print $tid ?>"><?php print $map['title'] ?></option>
            <?php endforeach; ?>
          </select>
          <?php foreach ($parks_map_terms as $tid => $map): ?>
            <select id="<?php print $tid ?>">
              <?php foreach ($map['nodes'] as $nid => $park_title): ?>
                <option value="<?php print $nid ?>"><?php print $park_title ?></option>
              <?php endforeach; ?>
            </select>
          <?php endforeach; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>
</div>