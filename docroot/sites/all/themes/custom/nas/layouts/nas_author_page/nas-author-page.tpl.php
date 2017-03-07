<?php

/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<?php print $content['header']; ?>
</header>
<section <?php print !empty($css_id) ? "id=\"$css_id\"" : ''; ?> class="global-content">
  <div class="row space-top">
    <div class="column">
      <header class="bio-header">
        <?php print $content['image']; ?>
        <?php print $content['link']; ?>
        <h1 class="bio-name"><?php print $content['name']; ?> <?php print $content['twitter']; ?></h1>
        <small class="bio-title"><?php print $content['title']; ?></small>
      </header>
    </div>
  </div>

  <div class="row space-top">

    <!-- BEGIN MAIN COLUMN -->
    <div class="large-8 columns text-container">
      <?php print $content['bio']; ?>
      <?php print $content['articles']; ?>
    </div>
    <!-- END MAIN COLUMN -->

    <!-- BEGIN SIDEBAR -->
    <div class="sidebar large-4 columns">
      <?php print $content['right']; ?>
    </div>
    <!-- END SIDEBAR -->

  </div>

  <?php print $content['related_birds']; ?>

</section>
