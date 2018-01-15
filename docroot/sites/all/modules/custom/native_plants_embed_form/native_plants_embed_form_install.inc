<?php

function native_plants_embed_form_install_get_body() {
  return '
    <h3>Square, white background</h3>
    <pre>
      var nativePlantsEmbedFormSettings = {
        color_scheme: &#39;white&#39;,
        shape: &#39;<span>square</span>&#39;,
      };
      &lt;script src=&quot;http://audubon.org/sites/all/modules/custom/native_plants_embed_form/native_plants_embed_form.js&quot;&gt;&lt;/script&gt;
    </pre>
    <h3>Square, black background</h3>
    <pre>
      var nativePlantsEmbedFormSettings = {
        color_scheme: &#39;black&#39;,
        shape: &#39;square&#39;,
      };
      &lt;script src=&quot;http://audubon.org/sites/all/modules/custom/native_plants_embed_form/native_plants_embed_form.js&quot;&gt;&lt;/script&gt;
    </pre>
    <h3>Rectangle, white background</h3>
    <pre>
      var nativePlantsEmbedFormSettings = {
        color_scheme: &#39;white&#39;,
        shape: &#39;rectangle&#39;,
      };
      &lt;script src=&quot;http://audubon.org/sites/all/modules/custom/native_plants_embed_form/native_plants_embed_form.js&quot;&gt;&lt;/script&gt;
    </pre>
    <h3>Rectangle, black background</h3>
    <pre>
      var nativePlantsEmbedFormSettings = {
        color_scheme: &#39;black&#39;,
        shape: &#39;rectangle&#39;,
      };
      &lt;script src=&quot;http://audubon.org/sites/all/modules/custom/native_plants_embed_form/native_plants_embed_form.js&quot;&gt;&lt;/script&gt;
    </pre>
  ';
}
