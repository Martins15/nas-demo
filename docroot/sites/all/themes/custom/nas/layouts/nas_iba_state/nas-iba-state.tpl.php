<?php
/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<section class="global-content">
  <div class="row section-header">
    <div class="column">
    <?php print l(t('Important Bird Areas'), 'iba', array('attributes' => array('class' => array('section-header-slug')))); ?>
      <?php print $content['title']; ?>
    </div>
    <?php print $content['top']; ?>
  </div>

  <div class="row space-bottom">
    <?php print $content['map']; ?>
    <div class="inline-map small">
      <div class="columns medium-6 large-8">
        <div class="inline-map-canvas">
          <div class="inline-map-mask"></div>
          <iframe width="100%" height="100%" frameborder="0" scrolling="no" marginheight="0" marginwidth="0" src="//audubon.maps.arcgis.com/home/webmap/embedViewer.html?webmap=5b8624b080484d2e8b0ea6f6abb6d08e&amp;extent=-174.8584,47.7477,-133.418,73.1604&amp;zoom=true&amp;scale=true"></iframe>
        </div>
      </div>
    </div>
    <div class="columns medium-6 large-4">
      <?php print $content['sidebar']; ?>
    </div>
  </div>
  <div class="row space-bottom">
    <div class="column text-container">
      <?php print $content['main']; ?>
    </div>
  </div>

  <div class="row table-sort">
    <div class="columns medium-6 large-3">
      <select>
        <option value="">Filter by Status</option>
      </select>
    </div>
    <div class="columns medium-6 large-3">
      <select name="" id="">
        <option value="">Filter by Priority</option>
      </select>
    </div>
    <div class="columns medium-12 large-6">
      <input class="table-sort-search" type="search" placeholder="Search for a specific site...">
      <button class="table-sort-button pea-green large">Go</button>
    </div>
  </div>
  <div class="row">
    &nbsp;&nbsp;
    <div class="column">
      <table class="data row-borders responsive">
        <thead>
          <tr>
            <th>Site Name</th>
            <th>Status</th>
            <th>Priority</th> 
            <th>Counties</th>
            <th>IBA Criteria</th>
          </tr>
        </thead>
        <tbody>
          <tr>
            <td><a href="#">Adobe Valley</a></td>
            <td>Recognized</td>
            <td>State</td>
            <td>Mono</td>
            <td>D1</td>
          </tr>
          <tr>
            <td><a href="#">Aguanga Area</a></td>
            <td>Recognized</td>
            <td>State</td>
            <td>Riverside, San Diego</td>
            <td>D1</td>
          </tr>
          <tr>
            <td><a href="#">Alameda Wildlife Refuge</a></td>
            <td>Recognized</td>
            <td>State</td>
            <td>Alameda, San Francisco</td>
            <td>D5, D4i</td>
          </tr>
          <tr>
            <td><a href="#">Argus Range &ndash; Southern</a></td>
            <td>Recognized</td>
            <td>State</td>
            <td>Inyo</td>
            <td>D4i</td>
          </tr>
          <tr>
            <td><a href="#">Ballona Wetlands (Ballona Valley)</a></td>
            <td>Recognized</td>
            <td>State</td>
            <td>Los Angeles</td>
            <td>D4i</td>
          </tr>
          <tr>
            <td><a href="#">Bautista Creek</a></td>
            <td>Recognized</td>
            <td>State</td>
            <td>Riverside</td>
            <td>D1</td> 
          </tr>
          <tr>
            <td><a href="#">Benicia State Recreation Area</a></td>
            <td>Recognized</td>
            <td>State</td>
            <td>Solano</td>
            <td>D1, D4i, D4ii</td>
          </tr>
          <tr>
            <td><a href="#">Big Morongo Canyon</a></td>
            <td>Recognized</td>
            <td>State</td>
            <td>San Bernardino, Riverside</td>
            <td>D1, D4i</td>
          </tr>
          <tr>
            <td><a href="#">Big Valley &ndash; Ash Creek</a></td>
            <td>Recognized</td>
            <td>State</td>
            <td>Modoc, Lassen</td>
            <td>D1, D4i, D4ii</td>
          </tr>
          <tr>
            <td><a href="#">Argus Range &ndash; Southern</a></td>
            <td>Recognized</td>
            <td>State</td>
            <td>Inyo</td>
            <td>D4i</td>
          </tr>
          <tr>
            <td><a href="#">Ballona Wetlands (Ballona Valley)</a></td>
            <td>Recognized</td>
            <td>State</td>
            <td>Los Angeles</td>
            <td>D4i</td>
          </tr>
          <tr>
            <td><a href="#">Bautista Creek</a></td>
            <td>Recognized</td>
            <td>State</td>
            <td>Riverside</td>
            <td>D1</td> 
          </tr>
          <tr>
            <td><a href="#">Benicia State Recreation Area</a></td>
            <td>Recognized</td>
            <td>State</td>
            <td>Solano</td>
            <td>D1, D4i, D4ii</td>
          </tr>
          <tr>
            <td><a href="#">Big Morongo Canyon</a></td>
            <td>Recognized</td>
            <td>State</td>
            <td>San Bernardino, Riverside</td>
            <td>D1, D4i</td>
          </tr>
          <tr>
            <td><a href="#">Big Valley &ndash; Ash Creek</a></td>
            <td>Recognized</td>
            <td>State</td>
            <td>Modoc, Lassen</td>
            <td>D1, D4i, D4ii</td>
          </tr>
          <tr>
            <td><a href="#">Adobe Valley</a></td>
            <td>Recognized</td>
            <td>State</td>
            <td>Mono</td>
            <td>D1</td>
          </tr>
          <tr>
            <td><a href="#">Aguanga Area</a></td>
            <td>Recognized</td>
            <td>State</td>
            <td>Riverside, San Diego</td>
            <td>D1</td>
          </tr>
          <tr>
            <td><a href="#">Alameda Wildlife Refuge</a></td>
            <td>Recognized</td>
            <td>State</td>
            <td>Alameda, San Francisco</td>
            <td>D5, D4i</td>
          </tr>
          <tr>
            <td><a href="#">Argus Range &ndash; Southern</a></td>
            <td>Recognized</td>
            <td>State</td>
            <td>Inyo</td>
            <td>D4i</td>
          </tr>
          <tr>
            <td><a href="#">Central Orange County Preserves (Orange County Wilderness Parks)</a></td>
            <td>Recognized</td>
            <td>State</td>
            <td>Riverside, Orange</td>
            <td>D4i, D1</td>
          </tr>
        </tbody>
      </table>
    </div>
  </div>
  <div class="row space-bottom">
    <div class="column">
      <div class="pagination-centered">
        <ul class="pagination">
          <li class="arrow unavailable"><a href="">&larr; First</a></li>
          <li class="current"><a href="">1</a></li>
          <li><a href="">2</a></li>
          <li><a href="">3</a></li>
          <li class="unavailable"><a href="">&hellip;</a></li>
          <li><a href="">8</a></li>
          <li class="arrow"><a href="">Last &rarr;</a></li>
        </ul>
        <p>Displaying 1 &ndash; 20 (of 175)</p>
      </div>
    </div>
  </div>
  <?php print $content['more']; ?>
  <section class="card-set bg-1">
  	<?php print $content['cards_set']; ?>
  </section>
</section>
