<h5><?php print t('Species Range Change from 2000 to 2080'); ?><span class="venn-help"></span></h5>
<div class="row venn-container"></div>
<?php if (!empty($venn_description)): ?>
  <div id="venn-description-popup" class="climate-flyway-overlay element-hidden">
    <a class="close"></a>
    <div class="flyway-description">
      <?php print $venn_description; ?>
    </div>
  </div>
<?php endif; ?>