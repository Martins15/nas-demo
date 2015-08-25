<?php
/**
 * @file
 * Template implementation to display the panel's layout.
 */
?>
<section class="global-content">
  <div class="row section-header">
    <?php print $content['top']; ?>
  </div>

  <div class="row space-bottom">
    <div class="column">
      <?php print $content['main']; ?>
      <div class="inline-map small">
        <div class="columns medium-6 large-8">
          <div class="inline-map-canvas">
            <div class="inline-map-mask"></div>
            <iframe width="100%" height="100%" frameborder="0" scrolling="no" marginheight="0" marginwidth="0" src="http://audubon.maps.arcgis.com/home/webmap/embedViewer.html?webmap=5b8624b080484d2e8b0ea6f6abb6d08e&amp;extent=-174.8584,47.7477,-133.418,73.1604&amp;zoom=true&amp;scale=true"></iframe>
          </div>
        </div>
      </div>
      <div class="columns medium-6 large-4">
      <?php print $content['sidebar']; ?>
        <p>
          <strong>Andrea Jones</strong><br>
          State Program Director<br>
          <a href="#">Important Bird Areas of California</a>
        </p>
        <br>
        <h4>California IBAs by Type</h4>
        <table class="data">
          <thead>
            <tr>
              <th>IBA Priority</th>
              <th>Number</th>
              <th>Acres</th>
            </tr>
          </thead>
          <tbody>
            <tr>
              <td>Global</td>
              <td>69</td>
              <td>13,014,412</td>
            </tr>
            <tr>
              <td>State</td>
              <td>106</td>
              <td>6,672,934</td>
            </tr>
            <tr>
              <td>Continental</td>
              <td>0</td>
              <td>0</td>
            </tr>
          </tbody>
          <tfoot>
            <tr>
              <td>Total</td>
              <td>175</td>
              <td>19,687,346</td>
            </tr>
          </tfoot>
        </table>
      </div>
    </div>
  </div>
  <div class="row space-bottom">
    <div class="column text-container">
      <p>California's Important Bird Areas Program, launched in 1996, surged forward in 2000. Beginning in 2001, dozens of California field ornithologists, representing a broad range of agencies and affiliations, were interviewed and questioned about sites significant to bird populations in the state. These interviews, in combination with collecting data from around the state, and review by a technical committee, led to 145 sites becoming designated as Important Bird Areas. In 2004, Audubon published the book "Important Bird Areas of California" by Daniel S. Cooper. This network of IBAs is the cornerstone of Audubon's conservation activities in California. Their identification is guiding conservation at the chapter, state, and national levels of Audubon, and serves to showcase noteworthy habitat to other interested groups and agencies. </p>
      <p>In 2006, Audubon California prioritized IBAs based on bird value, degree of threat, and availability of conservation opportunities, and works with local chapters to conserve these sites and to develop systems to monitor their bird life. Audubon California has partnered with Cornell Lab of Ornithology and Point Blue Conservation Science to develop <a href="#">California eBird</a> to gather bird abundance and distribution data at IBA sites into an online database. </p>
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
  <section class="card-set bg-1">
  	<?php print $content['cards_set']; ?>
  </section>
</section>
