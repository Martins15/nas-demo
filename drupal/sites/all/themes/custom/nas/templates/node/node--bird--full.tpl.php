<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * Custom variables:
 * - $bird_priority: Boolean, check if field_bird_priority true or false.
 * - $bird_illustration_author: Contains data from field_bird_illustration's alt.
 * - $learn_more_link: Static link for article.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<div class="row">
  <div class="column">
    <div id="node-<?php print $node->nid; ?>" class="bird-guide-card <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
      <?php if ($bird_priority): ?>
      <div class="bird-guide-tag"><?php print t('Priority Bird'); ?></div>
      <?php endif; ?>
      <header class="bird-guide-header">
        <div class="row">
          <div class="medium-8 columns">
            <h1 class="common-name"><?php print $title; ?></h1>
            <p class="scientific-name">
              <?php print render($content['field_bird_sci_name']); ?>
            </p>
          </div>
          <div class="medium-4 columns illustration">
            <?php print render($content['field_bird_illustration']); ?>
          </div>
        </div>
      </header>
      <section class="bird-guide-body">
        <div class="row">
          <div class="large-8 columns">
            <section class="bird-guide-section left-col">
              <table class="collapse">
                <tbody>
                    <?php print render($content['field_bird_conserv_status']); ?>
                    <?php print render($content['field_bird_family']); ?>
                    <?php print render($content['field_bird_description']); ?>
                    <?php print render($content['field_bird_habitat']); ?>
                </tbody>
              </table>
              <?php print render($content['body']); ?>
            </section>
            <section class="bird-guide-section left-col">
              <h5><i class="icon-camera"></i> <?php print t('Photo Gallery'); ?></h5>
              <div class="thumb-strip clearfix">
                <a class="thumb-strip-prev"><i class="icon-chevron-left"></i></a>
                <div class="thumb-strip-wrapper">
                  <?php print render($content['field_bird_photo']); ?>
                </div>
                <a class="thumb-strip-next"><i class="icon-chevron-right"></i></a>
              </div>
            </section>
            <section class="bird-guide-section left-col sans">
              <div class="row">
                <div class="large-6 columns">
                  <h5><i class="icon-music"></i> <?php print t('Songs and Calls'); ?></h5>
                    <?php print render($content['field_bird_calls']); ?>
                  <br>
                    <?php print render($content['field_bird_audio']); ?>
                </div>
                <div class="large-6 columns">
                  <?php print render($content['field_bird_nesting']); ?>
                  <br>
                  <?php print render($content['field_bird_range']); ?>
                </div>
              </div>
            </section>
          </div>
          <div class="large-4 columns">
            <section class="illustration-attribution bird-guide-section right-col small center hide-for-medium hide-for-small hide-for-tiny">
              <p>
                <?php if (isset($bird_illustration_author)): ?>
                  <?php print $bird_illustration_author; ?>
                <?php endif; ?>
                <br>
                <?php if (isset($learn_more_link)): ?>
                  <?php print $learn_more_link; ?>
                <?php endif; ?>
              </p>
            </section>
            <div id="bird-cta">
              <section class="social-sharing bird-guide-section right-col small center">
                <span class="social-sharing-caption small"><?php print t('Share this bird'); ?></span>
                <a class="social-sharing-icon blue small" target="_blank" href="http://twitter.com/share?url=/&amp;text=<?php print $page_link; ?>"><i class="icon-twitter"></i></a>&nbsp;
                <a class="social-sharing-icon blue small" target="_blank" href="http://www.facebook.com/sharer/sharer.php?u=<?php print $page_link; ?>"><i class="icon-facebook"></i></a>&nbsp;
                <a class="social-sharing-icon blue small" target="_blank" href="http://pinterest.com/pin/create/button/?url=<?php print $page_link; ?>"><i class="icon-pinterest"></i></a>&nbsp;
                <a class="social-sharing-icon blue small" href="mailto:?subject=<?php print $title; ?>&body=<?php print $page_link; ?>"><i class="icon-mail"></i></a>
              </section>
              <section class="bird-guide-section right-col small center"></section>
            </div>
            <?php if (!empty($content['field_bird_tip'])): ?>
            <section id="bird-dyk" class="bird-guide-section right-col small sans">
              <?php print render($content['field_bird_tip']); ?>
            </section>
            <?php endif; ?>
            <section id="bird-map" class="bird-guide-section right-col">
              <?php print render($content['field_bird_rangemap']); ?>
            </section>
          </div>
        </div>
      </section>
    </div>
  </div>
</div>
