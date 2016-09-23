<?php
/**
 * @file
 * Native Plants Audubon near you template.
 */
?>
<div class="native-plants-audubon-near-you connect-audubon-near-you row<?php print !empty($context_links) ? ' contextual-links-region' : ''; ?>">
  <?php print $context_links; ?>
  <?php foreach ($resources as $resource): ?>
    <div class=" vertical-spacing--bottom clearfix">
      <div class="column medium-4">
        <h2 class="connect-audubon-near-you--title text--blue"><?php print $resource['title']; ?></h2>
        <p class="connect-audubon-near-you--address">
          <i class="icon-map"></i>
          <?php print $resource['address']['rendered']; ?><br/>
          <?php print $resource['phone']; ?>
        </p>
        <?php print $resource['link']['rendered']; ?>
      </div>
      <div class="column medium-8 connect-audubon-near-you--services">
        <h3 class="thin hide-for-tiny hide-for-small"><?php print $resource['services_title_desktop']; ?></h3>
        <h3 class="thin hide-for-medium hide-for-large hide-for-xlarge"><?php print $resource['services_title_mobile']; ?></h3>
        <?php print $resource['services']['rendered']; ?>
      </div>
    </div>
  <?php endforeach; ?>
</div>
