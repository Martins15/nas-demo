(function($) {
  Drupal.behaviors.nas_wysiwyg = {
    attach: function(context, settings) {
      /** 
       * In that case, we haven't better solution for attaching handlers
       * for loaded wysiwyg, so we follow this logic:
       * if you want to use plugin you have to move mouse pointer inside wysiwyg.
       */
      $('.cke_wysiwyg_frame').each(function() {
        $(this).mouseenter(function() {
          nas_wysiwyg_attach_behavior(this);
        });
      });

      /**
       * Attach click events to iframe and inserted block.
       */
      function nas_wysiwyg_attach_behavior(iframe) {
        $(iframe).contents().find('body').once('article-aside').click(function() {
          $(this).find('.article-aside-active').removeClass('article-aside-active');
          updateBlockInsertButtonState();
        });

        // Remove active block on Delete button click.
        $(iframe).contents().find('body').once('article-aside-active').keyup(function(e) {
          if (e.keyCode == 46 && $(iframe).contents().find('.article-aside-active').length > 0) {
            e.preventDefault();
            var isDelete = confirm(Drupal.t('You have pressed Delete button. Do you want to remove block?'));
            if (isDelete) {
              $(this).find('.article-aside-active').remove();
            }
          }
        });

        $(iframe).contents().find('.article-aside').each(function() {

          // Disable any actions clicking on links inside blocks.
          $(this).find('a').once('article-aside').click(function(event) {
            return false;
          });

          $(this).once('article-aside').click(function(event) {
            event.stopPropagation();

            // If block is placeholder do not make it active nor highlight toolbar button.
            if ($(this).find('img.article-aside-placeholder').length === 0) {

              $(this).parents('html').find('.article-aside-active').removeClass('article-aside-active');
              $(this).addClass('article-aside-active');

              updateBlockInsertButtonState();
            }
          });
        });
      }

      $('iframe.cke_wysiwyg_frame').contents().find('html').click(function() {
        $(this).find('.cke_button__article_aside').addClass('cke_button_off').removeClass('cke_button_on');
      });

    }
  };

  function updateBlockInsertButtonState() {
    $('iframe').each(function() {
      var insertBlockIsActive = $(this).contents().find('.article-aside-active').length;

      if (insertBlockIsActive) {
        $(this).parents('.cke_inner').find('.cke_button__article_aside').addClass('cke_button_on').removeClass('cke_button_off');
      } else {
        $(this).parents('.cke_inner').find('.cke_button__article_aside').addClass('cke_button_off').removeClass('cke_button_on');
      }
    });
  }

  Drupal.wysiwyg.plugins.article_aside = {

    /**
     * Get the active block from the iframe.
     */
    getActiveBlockInsert: function(instanceId) {
      return $('#cke_' + instanceId).find('iframe').contents().find('.article-aside-active');
    },

    /**
     * Method called when wysiwyg button clicked.
     **/
    invoke: function(data, settings, instanceId) {
      if (data.format == 'html') {
        var insert = new InsertBlock(instanceId);
        var $activeBlock = this.getActiveBlockInsert(instanceId);

        if ($activeBlock.length > 0) {
          // Select existing block.
          insert.onSelect();
        } else {
          // Insert new block.
          var block = {
            'head': Drupal.t('Insert title here'),
            'main': Drupal.t('Insert text here')
          };
          insert.insert(block);
        }
      }
    },

    /**
     * Attach function, called when a rich text editor loads.
     * This finds all [[tags]] and replaces them with the html
     * that needs to show in the editor.
     */
    attach: function(content, settings, instanceId) {
      nas_wysiwyg_ensure_tagmap();

      var nas_wysiwyg_tagmap = Drupal.settings.nas_wysiwyg_tagmap,
        matches = content.match(/\[article_aside_insert\](.*?)\[\/article_aside_insert\]/g);

      if (matches) {
        for (var index in matches) {
          var macro = matches[index];

          if (nas_wysiwyg_tagmap[macro]) {
            content = content.replace(macro, nas_wysiwyg_tagmap[macro]);
          } else {
            console.log("Could not find content for " + macro);
          }
        }
      }

      Drupal.attachBehaviors();
      return content;
    },

    /**
     * Detach function, called when a rich text editor detaches.
     */
    detach: function(content, settings, instanceId) {
      nas_wysiwyg_ensure_tagmap();
      var nas_wysiwyg_tagmap = Drupal.settings.nas_wysiwyg_tagmap,
        i = 0,
        markup,
        macro;

      var matches = content.match(/<aside class="article-aside(.*?)<\/aside>/gi);
      if (matches) {
        for (i = 0; i < matches.length; i++) {
          markup = matches[i];
          macro = nas_wysiwyg_create_macro(markup);
          nas_wysiwyg_tagmap[macro] = markup;
          content = content.replace(markup, macro);
        }
      }

      return content;
    }
  };

  var InsertBlock = function(instance_id) {
    this.instanceId = instance_id;
    return this;
  };

  InsertBlock.prototype = {
    onSelect: function() {
      console.log('the block has been selected');
    },

    /**
     * Insert HTML to the WYSIWYG when block has been created. Set the macro.
     */
    insert: function(block) {
      var markup = nas_wysiwyg_create_markup(block);
      macro = nas_wysiwyg_create_macro(markup);

      // Insert placeholder markup into wysiwyg.
      Drupal.wysiwyg.instances[this.instanceId].insert(markup);
      Drupal.attachBehaviors();

      // Store macro/markup pair in the nas_wysiwyg_tagmap.
      nas_wysiwyg_ensure_tagmap();
      Drupal.settings.nas_wysiwyg_tagmap[macro] = markup;
    }
  };

  /**
   * Ensure that block insert tagmap initialized.
   */
  function nas_wysiwyg_ensure_tagmap() {
    Drupal.settings.nas_wysiwyg_tagmap = Drupal.settings.nas_wysiwyg_tagmap || {};
  }

  /**
   * Create a macro token from the block.
   */
  function nas_wysiwyg_create_macro(html) {
    return '[article_aside_insert][head]' + $(html).find('.engagement-card-headline').html() + '[/head][text]' + $(html).find('.p1').html() + '[/text][/article_aside_insert]';
  }

  /**
   * Create a markup from block object.
   */
  function nas_wysiwyg_create_markup(block) {
    return '<aside class="article-aside"><div class="engagement-card side-note"><div class="engagement-card-content"><h4 class="engagement-card-headline">' + block.head + '</h4><p class="p1">' + block.main + '</p></div></div></aside>';
  }

})(jQuery);
