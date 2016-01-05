'use strict';

(function(window, $) {

  //
  // Instantiate the view
  //
  var birdPageView = new STMN.audubonClimateModel.BirdPageView(
    {
      defaults : {
        title : 'Climate Change & Bird Ranges'
      },
      paths : {
        data           : './data/audubon-climate-model.json',
        giphy          : './data/giphy_manifest.json',
        states         : './data/audubon-climate-model-st-BBC-{countryCode}-{audubonId}.json',
        flywayPolygons : 'data/ne_50m_usa_canada.topojson'
      },
      selectors : { //Omit items in this object and they will not display on the page.
        title        : 'h1',
        flywayNavMap : '#flywaynavmap',
        flywayList   : '#flywaylist',
        searchBox    : '.audubon-climate-model input[type=search]'
      },
      templates : {
        title : '{AOU54_COMMON_NAME}<br><i>{AOU54_SPECIES}</i>',
        animationUrl      : 'http://studio.stamen.com/audubon/files/animations/animated{BBL_ABBREV}.gif'
      },
      lists : [
        {
          listId : 'mostendangered',
          selector : '#mostendangered',
          stateFilter : 'USA:CAL',
          columnFilter : [{'AUDUBON_CLIMATE_SENSITIVITY':'THREATENED_1'}],
          limit : 6,
          template : '<li id="birdlist{SPECIES_CODE}"><a href="#{SPECIES_CODE}">{PRIMARY_COM_NAME}</a><br><i>{SCI_NAME}</i></li>'
        }
      ],
      filterTo : ['ENDANGERED','ENDANGERED_1','ENDANGERED_2','THREATENED','THREATENED_1','THREATENED_2']
    },
    function(err, view) {

    }
  );

  //
  // Bind to clicks on the flyway nav
  //
  var flywayListConfig = {
    listId : 'flywaylist',
    selector : '#flywaylist ol',
    stateFilter : 'USA:CAL',
    template : '<li id="flyway{id}"><a href="#{SPECIES_CODE}" data-listtype="mostendangered">{PRIMARY_COM_NAME}</a>|<span class="BBSpercent">{percentageLost.BBS}</span>|<span class="CBCpercent">{percentageLost.CBC}</span><br><i>{SCI_NAME}</i></li>',
    columnFormatter : function(column) {
      column['percentageLost.BBS'] = column['percentageLost.BBS'] ? parseInt(column['percentageLost.BBS']*100, 10) + '%' : 0 + '%';
      column['percentageLost.CBC'] = column['percentageLost.CBC'] ? parseInt(column['percentageLost.CBC']*100, 10) + '%' : 0 + '%';
      return column;
    } //Array.map callback function
  };

  birdPageView.on('clickFlywayMapRegion', function(e) {

    if (e.caller.state) {
      var state = birdPageView.getFlywayData().values.filter(function(stateItem) {
        return (stateItem[4] === e.caller.clickEvent.id);
      })[0];

      //Draw a state filtered
      flywayListConfig['stateFilter'] = (state[1] === 'US' ? 'USA' : 'CAN') + ':' + state[3];
      birdPageView.drawList(flywayListConfig);
      $('#flywaylist span.flyway-name').text(state[0]);

      $('#flywaylist').show();

      $('#stateprovincelist').hide();

      birdPageView.setFlywayMapUIState('flyway:' + e.caller.region);

    } else {

      // Create a new div in the html, and populate it with the list of states in the flyway.
      $('#stateprovincelist span.flyway-name').text(e.caller.region);

      var states = birdPageView.getFlywayData().values.sort().filter(function(stateItem) {
        return (stateItem[2] === e.caller.region);
      });

      $('#stateprovincelist ul').html(states.map(function(state) {
        return "<li style='cursor:pointer;' id='" + state[0] + "' data-state-filter=" + (state[1] === 'US' ? 'USA' : 'CAN') + ':' + state[3] + ">" + state[0] + "</li>";
      }));

      $('#stateprovincelist').bind('click',function(e) {
        if ($(e.target).attr('data-state-filter')) {
          flywayListConfig.stateFilter = $(e.target).attr('data-state-filter');
          birdPageView.drawList(flywayListConfig);
          $('#flywaylist span.flyway-name').text($(e.target).attr('id'));
          $('#flywaylist').show();
          $('#stateprovincelist').hide();
        }
      });

      $('#stateprovincelist').show();

      $('#flywaylist').hide();

      birdPageView.setFlywayMapUIState('flyway:' + e.caller.region);

    }

  });

  birdPageView.on('listSelect', function(e) {

    if (e.caller.listConfig.listId === 'flywaylist' || e.caller.listConfig.listId === 'mostendangered') {
      location.href = 'bird.html' + e.caller.clickEvent.target.hash;
    }

  });

  birdPageView.on('search:selected', function(e) {
    $('.audubon-climate-model input[type=search]').attr('value');
    location.href='bird.html#' + e.caller[0]['SPECIES_CODE'];
  });

  $('#flywaylist').click(function(e) {
    if (e.target.tagName === 'BUTTON') {
      flywayListConfig.sortColumn = $(e.target).attr('data-sortcolumn');
      flywayListConfig.reverseSort = true;
      birdPageView.drawList(flywayListConfig);
    }
  });

}(window, $));
