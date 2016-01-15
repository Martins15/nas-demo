'use strict';

(function(window, JQ2){

  window.STMN.audubonClimateModel = window.STMN.audubonClimateModel || {};

  function Slideshow(rootNodeSelector, imagesArray, config) {

    STMN.StamenBase.apply( this, arguments );

    var self       = this,
        totalSteps = imagesArray.length,
        interf     = {},
        state      = {nudge:{},nudgeOffset:{x:0,y:0}},
        images     = [],
        scale      = null,
        PAUSE      = 'll',
        PLAY       = '►',
        mapNodeSelector = rootNodeSelector + " .map-canvas div",
        rootNode;

    //
    // Defaults
    //
    config                = config                || {};
    config.autoStart      = config.autoStart      || true;
    config.duration       = config.duration       || 1000;
    config.hideControls   = config.hideControls   || false;
    config.lastSlidePause = config.lastSlidePause || false;

    //
    // Preload images
    //
    self.on('imagesPreloaded', init);
    imagesArray.forEach(function(imageConfig, i) {
      images.push(new Image());
      images[images.length-1].src = imageConfig.src;

      if (i === totalSteps-1) {
        self.fire('imagesPreloaded');
      }
    });

    //
    // Private stuff
    //

    function get(selector, root) {
      if (JQ2) {
        return ((root) ? JQ2(root).find(selector) : JQ2(selector)).get();
      } else {
        return ((root) ? root : document).querySelectorAll(selector);
      }
    }

    function changeStep(step) {

      var old       = state.step,
          container = get(rootNodeSelector)[0];

      state.step = step;

      setImage(images[step-1].src, scale);

      if (config.lastSlidePause && (step === images.length) && state.playing) {
        pause();
        state.lastPause = setTimeout(function() {
          start();
        }, config.lastSlidePause);
      } else if(state.playing) {
        clearTimeout(state.lastPause);
      }

      self.fire('stepChanged', {
        old : old,
        new : state.step
      });
    }

    function _start() {
      if (!state.step || state.step > totalSteps-1) {
        state.step = 0;
      }

      var step = state.step;

      changeStep(step+1);
    }

    function start() {
      
      if (!state.playing || state.paused === true) {

        _start();

        state.playing = setInterval(_start, config.duration);

        if (!state.paused) {
          self.fire('started');
        } else {
          self.fire('unpaused');
          state.paused = false;
        }
      }

    }

    function stop() {
      
      if (state.playing) {
        clearInterval(state.playing);
        clearTimeout(state.lastPause);
        state.playing = false;

        self.fire('stopped');
        if (state.paused) {
          self.fire('unpaused');
          state.paused = false;
        }
      }

    }

    function pause() {

      if (state.playing) {
        clearInterval(state.playing);
        state.paused = true;

        self.fire('paused');
      }

    }

    function setScale(newScale) {
      var old = scale;

      scale = newScale;

      setImage(null, newScale);

      if (scale < 101) {
        get(rootNodeSelector)[0].style.backgroundPosition = '0px 0px';
      } else {
        rootNode.style.backgroundPosition = -(rootNode.offsetWidth) + 'px ' + -(rootNode.offsetHeight) + 'px';
      }

      self.fire('setScale', {
        newVal : newScale,
        oldVal : old
      });
    }

    function setImage(src, scale) {
      if (src) {
        get(mapNodeSelector)[0].style.backgroundImage = 'url('+src+')';
      }
      get(mapNodeSelector)[0].style.backgroundSize = !(scale > 100) ? 'cover' : (scale + '% ' + scale + '%');
      get(mapNodeSelector)[0].style.backgroundRepeat = 'no-repeat';

    }

    function showControls() {

      var controlsNode = get('.controls', rootNode)[0];

      if (!controlsNode) {

        var playButton = self.processTemplate(config.templates.animationControlPlayPauseButton, {});
        var controlsNode = document.createElement('div');
        controlsNode.className = 'controls';
        rootNode.appendChild(controlsNode);

        controlsNode.innerHTML = (playButton + imagesArray.map(function(imageConfig, i) {

          imageConfig.step = (i+1);

          return self.processTemplate(config.templates.animationControlStepButton, imageConfig);

        }).join(' ') + self.processTemplate(config.templates.animationControlZoomButton, {}))

      }

      controlsNode.style.display = 'block';

    }

    function hideControls() {
      var controlsNode = get('.controls', rootNode)[0];
      controlsNode.style.display = 'block';
    }

    function updateControlsUI() {

      get('a', rootNode).forEach(function(button) {

        if (button.getAttribute('data-step')) {
          if(parseInt(button.getAttribute('data-step'), 10) === state.step) {
            JQ2(button).addClass('active');
          } else {
            JQ2(button).removeClass('active');
          }
        }

      });

    }

    function addImagesToDom() {
      var existingImage = get('.map-canvas img', rootNode)[0];

      if (existingImage) {
        existingImage.style.opacity = 0;

        
        return true;
      } else {
        return false;
      }

    }

    function _clickHandler(e) {
      if (JQ2(e.target).hasClass('map-pause')) {
        e.preventDefault();

        if (state.playing) {
          stop();
          JQ2(e.target).addClass("active");
        } else {
          start();
          JQ2(e.target).removeClass("active");
        }

      }

      if (JQ2(e.target).hasClass('action-zoom')) {
        if (scale > 100) {
          JQ2(e.target).removeClass('active');
          setScale(100);
        } else {
          JQ2(e.target).addClass('active');
          setScale(300);
        }
      }

      if (e.target.getAttribute('data-step')) {
        e.preventDefault();

        stop();
        JQ2(get('.map-pause', rootNode)[0]).addClass("active");
        changeStep(parseInt(e.target.getAttribute('data-step'), 10));
      }
    }

    function subscribeListeners() {
      self.on('started',updateControlsUI);
      self.on('stopped',updateControlsUI);
      self.on('stepChanged',updateControlsUI);

      get('.controls',rootNode)[0].addEventListener('click', _clickHandler, false);
    }

    function destroy() {

      get('.controls',rootNode)[0].removeEventListener('click', _clickHandler);

      stop();

    }


    //
    // The public interface
    //
    interf = {

      //Copied methods
      on       : self.on,
      once     : self.once,
      start    : start,
      stop     : stop,
      destroy  : destroy,
      setScale : setScale,

      //Wrapper Methods
      getStep : function() {
        return state.step;
      },

      getStepElement : function(step) {
        return imagesArray[step];
      }
    }

    //
    // Go for it!
    //
    function init () {

      rootNode = get(rootNodeSelector)[0];

      if (config.autoStart) {
        start();

        updateControlsUI();
      }

      addImagesToDom();

      subscribeListeners();

      self.fire('ready');
    }

    return interf;

  }

  STMN.audubonClimateModel.Slideshow = Slideshow;

}(window, JQ2));