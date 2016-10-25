<?php
/**
 * @file
 * Template of NAS Three Column. Used in Press Release.
 */
?>
<?php print $content['magazine_bar']; ?>
<section class="global-content">
  <article class="article">
    <header class="article-header row">
      <div class="large-10 large-centered columns">
        <?php print $content['header']; ?>
      </div>
    </header>
    <div class="article-body row reflow-body" <?php if (!empty($css_id)) {print "id=\"$css_id\"";} ?>>
      <div class="article-text large-push-2 large-10 columns">
        <aside class="medium-12 article-aside small reflow reflow-into-sidebar-bottom" data-reflow-class="full-width">
          <?php print $content['right']; ?>
        </aside>
        <?php print $content['main']; ?>
        <?php if(!empty($content['file_attachments'])): ?>
        <div class="file-attachments">
          <h3><?php print t('Downloadable Resources'); ?></h3>
          <div class="files-list">
            <?php print $content['file_attachments']; ?>
          </div>
        </div>
        <?php endif;?>
      </div>
      <div class="article-sidebar large-pull-10 large-2 columns press-release">
        <?php print $content['left']; ?>
      </div>
    </div>
  </article>
  <?php print $content['related']; ?>
  <section class="card-set reset-white">
    <?php print $content['card_set']; ?>
  </section>
</section>