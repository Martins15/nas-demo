Audubon climate model demo
==========================

This site is meant to demonstrate the functions of the Audubon climate model tools. This site can be built and run using Jekyll. There is also a pre-built static version in the _site directory.

Running the demo
----------------
These instructions are intended for 10.9.4, thought this should work on Windows or Unix
   * Make sure [Homebrew](http://brew.sh/) is installed
   * Run `brew doctor` to make sure your computer is in a good state to install new things using Brew
   * Install [Jekyll Sass](https://github.com/noct/jekyll-sass)
   * Make sure you have [Node.JS](http://nodejs.org/) installed 
   * Run `npm install uglify-js -g`

Now you are ready to run the demo. From _this_ directory, run the following:
`jekyll serve -w`
You will now have a [webserver running on port 4000](http://localhost:4000)

Minified JS
-----------

The minified version of the JS file should be used for production. This file is audubon-climate-model.min.js

This file can be rebuilt by running the `make` command in the ./js directory. A list of the files which are used to generate this file can be found in ./js/Makefile

CSS
---
The jekyll command run above to run the demo also generates the ./_site/css/audubon-mlimate-model.css file, which is the one which is the best one to find styles. The ./css/audubon-mlimate-model.scss file is written using [SASS](http://sass-lang.com/) which can not be read by the browser without processing.

JS
--
Once the audubon-climate-model.min.js has been included, use the following interface to use it:

*The constructor*
`STMN.audubonClimateModel.BirdPageView({config object}, callback function);`

*Config options*
   * SPECIES_CODE : (optional) A six didgit bird code (for detailed views for a specific bird)
   * paths : (required) Path to the data file
   * selectors {} : (required) an object of css selector paths to areas in the document to bind functionality. The following selectors can optionally be added: title, flywayNavMap, flywayList, searchBox, animation, nonGeoViz, or shareMenu. Not including any of these items will prevent it from being rendered on the page.
   * templates {} : (required) an object of string templates. The following templates can optionally be added: title, animationImage, nonGeoViz, shareMenu, listItem, animationUrl, flywayNavMap , flywayNavMapArea, flywayNavList, listItem.
   * lists [] : An array of list objects. This will create a markup list and put it on the page by selector. The properties of each list item are: listId (required), selector (required), stateFilter, columnFilter, limit, template (required), sortColumn
   * defaults : Default data. This only accepts title at the moment
   * flywayMap {} : Config for the flyway map. This requires the following properties name, imageUrl, polygons

_There is a demonstration of these configurations in ./js/view-BirdPageView.js and
 ./js/view-ListPageView.js_

 *Events*
   * dataUpdate : gets called when ever data is updated or a bird changes
   * titleUpdated : The title element is updated'
   * listSelect : A user clicks a link in a list
   * flywayListUIBackAction : A back button click
   * flywayListUIStateChange : User has requested a change to the flyway selector
   * clickFlywayMapRegion : a region of the flyway map has been clicked
   * search:selected : a bird has been selected from the search box

*Public properties*
   * name : The name of this instance of the climate model js
   * setBird(SPECIES_CODE _string_) : takes the 6 didgit SPECIES_CODE of a bird
   * on(callback _function_)   : subscribes to an event
   * once(callback _function_) : subscribes to an event and unsubscribes after it is fired once
   * setFlywayListUIState() : sets the ui_state of the flyway selector lists
   * setFlywayMapUIState() :  sets the ui_state of the flyway selector map
   * getCoreData(sort _function_, dedup _bool_): returns the current loaded core data object. 
   Takes a sort function as an argument
   * getFlywayData() : returns an object with flyway data
   * getPercentageLostData : returns an array of objects keyed by SPECIES_CODE, which has the percentage lost for each season.
   * drawLists() : takes an array of list configs and draws lists of birds from the JSON data
   * drawList() : takes a list config and draws a list of birds from the JSON data
   * getSearchBoxInstance : Returns an instance of the [Twitter Typeahead Jquery plugin](https://twitter.github.io/typeahead.js/)

_There is a demonstration of these configurations in ./js/view-BirdPageView.js and
 ./js/view-ListPageView.js_
