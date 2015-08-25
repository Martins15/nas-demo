<?php
/**
 * @file
 * IBA State switcher.
 *
 * Available variables:
 * - $options: (array) contains the list of all IBA states.
 */
?>
<div class="column">
  <ul class="iba-state-switcher section-nav inline-list">
    <li>
      <small>View Another State</small>
      <select>
				<?php foreach ($options as $option): ?>
        <option <?php $option['default'] ? print 'secleted="selected"' : ''; ?> value="<?php print $option['path']; ?>"><?php print $option['title']; ?></option>
				<?php endforeach; ?>
      </select>
    </li>
  </ul>
</div>
