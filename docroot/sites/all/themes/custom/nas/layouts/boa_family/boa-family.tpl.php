<?php
/**
 * @file
 * Template implementation to display BOA layout.
 */
?>
<?php print $content['header']; ?>
</header>
<section class="global-content with-padding">
  <div class="row">
    <div class="boa-family-text-block columns text-container">
      <div class="large-12">
        <h1 class="thin family-name"><?php print $content['title']; ?></h1>
        <p class="scientific-name"><?php print $content['scientific_name']; ?></p>
      </div>
      <?php print $content['body_column_1']; ?>
    </div>
  </div>
  <?php print $content['bottom']; ?>
  <section class="card-set bg-1">
    <?php print render($content['cards']); ?>
  </section>
</section>
