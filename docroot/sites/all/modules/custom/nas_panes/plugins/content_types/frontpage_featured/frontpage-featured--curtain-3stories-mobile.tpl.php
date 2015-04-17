 <?php
/**
 * @file
 * Featured Frontpage template file.
 *
 * Available variables:
 * - $title_link: the (sanitized) title with link.
 * - $blue_text_link: the (sanitized) blue text above the title with link.
 * - $image_path: path to the hero image of the bird.
 * - $image_path_mobile: path to the hero image of the bird mobile image style.
 * - $image_string: sanitized caption + credits of the hero image.
 * - $contextual_links: rendered contextual links.
 */
?>
 <div class="curtain-fallback" style="background-image: url(<?php print $image_path; ?>)">
   <div class="curtain-fallback-content">
     <div class="columns contextual-links-region">
       <?php print $contextual_links; ?>
       <div class="curtain-card">
         <h2 class="curtain-card-headline"><?php print $title_link; ?></h2>
         <?php foreach ($stories as $story): ?>
           <div class="editorial-card-list-item">
             <small><?php print $story['slug_link']; ?></small>
             <h4 class="thin close-heading"><?php print $story['title_link']; ?></h4>
           </div>
         <?php endforeach; ?>
         <?php print $action_link; ?>
       </div>
     </div>
   </div>
 </div>
