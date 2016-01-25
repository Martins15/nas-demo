'use strict';

(function(window, $) {

  var elZoom = null,
      zoomIsteningForAnimation;

  if (!location.hash.substring(1)) {
    alert('No bird id found');
  }

  var birdPageView = new STMN.audubonClimateModel.BirdPageView(
    {
      SPECIES_CODE : location.hash.substring(1),
      paths : {
        data   : './data/audubon-climate-model.json',
        giphy  : './data/giphy_manifest.json',
        states : './data/audubon-climate-model-st-BBC-{countryCode}-{audubonId}.json'
      },
      animation : {
        slideDuration : 500,
        lastSlidePause : 1000
      },
      selectors : {
        title     : 'h1',
        animation : '#detail-view .map',
        nonGeoViz : '.notmap',
        shareMenu : '#share',
        searchBox : '#detail-view input[type=search]'
      },
      templates        : {
        title          : '{PRIMARY_COM_NAME}<br><i>{SCI_NAME}</i>',
        animationImage                  : 'http://studio.stamen.com/audubon/files/animations_2014-08-13/map_{SPECIES_CODE}_{year}.png',
        animationControlStepButton      : '<button class="action-step" data-step="{step}">{label}</button>',
        animationControlPlayPauseButton : '<button class="action-play-pause">ll</button>',
        animationControlZoomButton      : '<button class="action-zoom">Zoom</button>',
        nonGeoViz      : 'non-geo viz for {PRIMARY_COM_NAME}',
        shareMenu      : '<a id="twitter-share" href="#" onclick="javascript:void window.open(\'http://twitter.com/share?url={giphyUrlTiny}&amp;text=Global warming threatens the birds we love. Take action with @audubonsociety to help the {PRIMARY_COM_NAME}.\',\'twitter-share\',\'width=500,height=252,toolbar=0,menubar=0,location=0,status=1,scrollbars=0,resizable=1,left=0,top=0\');return false;" target="_blank">Twitter</a>&nbsp;|&nbsp;<a href="#" onclick="javascript:void window.open(\'http://www.facebook.com/sharer/sharer.php?u={giphyUrlTiny}\',\'facebook-share\',\'width=650,height=280,toolbar=0,menubar=0,location=0,status=0,scrollbars=0,resizable=1,left=0,top=0\');return false;" target="_blank">Facebook</a>&nbsp;|&nbsp;<a href="#" onclick="javascript:void window.open(\'http://www.pinterest.com/pin/create/button/?url={giphyUrlTiny}&media={giphyUrlGif}&description=Global warming threatens the birds we love. Take action with @audubonsociety to help the {PRIMARY_COM_NAME}.\',\'pintrest-share\',\'width=650,height=280,toolbar=0,menubar=0,location=0,status=0,scrollbars=0,resizable=1,left=0,top=0\');return false;" target="_blank">Pinterest</a>&nbsp;|&nbsp;<a href="mailto:?subject=The%20U.S.%20could%20lose%20half%20it\'s%20bird%20species%20by%202080&body=Global%20warming%20threatens%20the%20birds%20we%20love,%20including%20the%20{PRIMARY_COM_NAME_EMAIL},%20{url}.%20But%20if%20we%20band%20together,%20we%20can%20build%20a%20brighter%20future%20for%20birds%20and%20ourselves.%20Take%20action%20today%20at%20http://audubon.org/climate." target="_blank">Email</a>',
        listItem       : '<li><a href="#{id}" data-listtype="{listtype}">{name}</a><br><i>{description}</i></li>'
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
      $(window).bind( 'hashchange', function(e) {
        if (!location.hash.substring(1)) {
          alert('No bird id found');
        } else {
          view.setBird(location.hash.substring(1));
        }
        window.scrollTo(0,0);
      });

      view.on('mapAnimationPaused', function() {
        $('#playpause').text('►');
      });

      view.on('mapAnimationPlayed', function() {
        $('#playpause').text('ll');
      });

      $('#playpause').bind('click', function() {

        if (view.getMapAnimationState()) {
          view.pauseMapAnimation();
        } else {
          view.playMapAnimation();
        }

      });

      //
      // Zoom
      //
      view.on('animation:ready', function(e) {
        window.scale = e.caller.instance.setScale;
      });


      //
      // What happens when somebody clicks on a search option
      //
      view.on('search:selected', function(e) {
        $('.audubon-climate-model input[type=search]').attr('value');
        location.href='bird.html#' + e.caller[0]['SPECIES_CODE'];
      });
    }
  );

}(window, $));
