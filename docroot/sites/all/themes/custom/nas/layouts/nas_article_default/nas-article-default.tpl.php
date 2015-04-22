<?php
/**
 * @file
 * Default template of Article layout.
 */
?>
<?php print $content['magazine_bar']; ?>
<section class="global-content">
  <article class="article">
    <header class="article-header row">
      <div class="large-10 large-centered columns">
        <?php print $content['header']; ?>
        <div class="article-meta clearfix hide-for-large hide-for-xlarge">
          <?php print $content['mobile_author']; ?>
        </div>
      </div> 
    </header>
    <div class="article-body row">
      <div class="article-sidebar large-2 columns">
        <?php print $content['social']; ?>
        <section class="clearfix article-sidebar-section article-meta hide-for-tiny hide-for-small hide-for-medium">
          <?php print $content['author']; ?>
        </section>
        <section class="clearfix article-sidebar-section article-related-birds reflow reflow-into-body" data-reflow-class="article-aside half-width">
          <?php print $content['birds']; ?>
        </section>
        <?php print $content['left']; ?>
      </div>
      <div class="article-text large-10 columns reflow-body">
        <aside class="article-aside reflow reflow-into-body">
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
    </div>
  </article>
  <section class="card-set reset-white">
    <?php print $content['card_set']; ?>
  </section>
</section>