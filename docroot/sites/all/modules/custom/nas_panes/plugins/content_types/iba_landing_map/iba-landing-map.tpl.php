<?php
/**
 * @file
 * IBA State switcher.
 *
 * Available variables:
 * - $options: (array) contains the list of all IBA states.
 */
?>
<style>

</style>
<div class="iba-landing-map inline-map">
  <div class="row section-header">
    <div class="columns">
      <h2 class="thin">Explore IBAs near you</h2>
    </div>
    <div class="columns">
      <ul class="iba-state-switcher section-nav inline-list">
        <li>
          <small>Browse by State</small>
          <select>
            <?php foreach ($options as $option): ?>
              <option <?php $option['default'] ? print 'secleted="selected"' : ''; ?> value="<?php print $option['path']; ?>"><?php print $option['title']; ?></option>
            <?php endforeach; ?>
          </select>
        </li>
      </ul>
    </div>
  </div>
  <div class="embed-container">
    <iframe width="500" height="400" frameborder="0" scrolling="no" marginheight="0" marginwidth="0" title="IBA_Website_Audubon" src="<?php print $src; ?>"></iframe>
  </div>
</div>
