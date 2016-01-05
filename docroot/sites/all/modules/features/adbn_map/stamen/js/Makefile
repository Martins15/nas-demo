all: js

js: audubon-climate-model.min.js
	cat prepend.txt > audubon-climate-model.min.js
	uglifyjs  vendor/polyfills.js  vendor/stamen-super-classy.js  vendor/typeahead.js vendor/d3.v3.min.js vendor/topojson.v1.min.js vendor/queue.v1.min.js vendor/venn.js venn-over-venn.js audubon-climate-model.js audubon-climate-model-slideshow.js >> audubon-climate-model.min.js
	cat append.txt >> audubon-climate-model.min.js
