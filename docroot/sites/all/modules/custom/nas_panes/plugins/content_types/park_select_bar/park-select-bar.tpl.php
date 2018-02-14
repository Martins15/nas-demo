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
            <a href="/node/<?php print $nid ?>"><?php print $park_title ?></a>
          <?php endforeach; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>
  <?php if ($type == 'extended'): ?>
    <div class="form-container green">
      <div class="row">
        <div class="columns">
          <div class="form-container__text inner">
            <label for="parks_map_terms"><?php print $select_park_label ?></label>
          </div>
          <div class="form-container__form inner">
            <div class="state-select columns large-3">
<!--              <select id="parks_map_terms">
                <?php /*foreach ($parks_map_terms as $tid => $map): */?>
                  <option value="<?php /*print $tid */?>"><?php /*print $map['title'] */?></option>
                <?php /*endforeach; */?>
              </select>-->
                <select name="parks" id="parks-select">
                    <option value=""><?php print t('Select')?></option>
                </select>
            </div>
            <div class="bird-select columns large-9">
<!--              <?php /*foreach ($parks_map_terms as $tid => $map): */?>
                <select id="<?php /*print $tid */?>">
                  <?php /*foreach ($map['nodes'] as $nid => $park_title): */?>
                    <option value="<?php /*print $nid */?>"><?php /*print $park_title */?></option>
                  <?php /*endforeach; */?>
                </select>
              --><?php /*endforeach; */?>
                <select name="state" id="state-select">
                    <option value="" selected><?php print t('Select')?></option>
                </select>
            </div>
          </div>
        </div>
      </div>
    </div>
  <?php endif; ?>
</div>
