//
// a few handpicked polyfills from https://github.com/jonathantneal/polyfill
//

window.STMN = window.STMN || {};

// Array.prototype.forEach
if (!Array.prototype.forEach) {
  Array.prototype.forEach = function forEach(callback, scope) {
    for (var array = this, index = 0, length = array.length; index < length; ++index) {
      callback.call(scope || window, array[index], index, array);
    }
  };
}

// Array.prototype.filter
if (!Array.prototype.filter) {
  Array.prototype.filter = function filter(callback, scope) {
    for (var array = this, arrayB = [], index = 0, length = array.length, element; index < length; ++index) {
      element = array[index];

      if (callback.call(scope || window, element, index, array)) {
        arrayB.push(element);
      }
    }

    return arrayB;
  };
}

// Array.prototype.map
if (!Array.prototype.map) {
  Array.prototype.map = function map(callback, scope) {
    for (var array = this, arrayB = [], index = 0, length = array.length, element; index < length; ++index) {
      element = array[index];

      arrayB.push(callback.call(scope || window, array[index], index, array));
    }

    return arrayB;
  };
}

//
// a classList prototype from https://github.com/remy/polyfills
//

//(function () {
//
//if (typeof window.Element === "undefined" || "classList" in document.documentElement) return;
//
//STMN.classListPolyfill=true;
//
//var prototype = Array.prototype,
//    push = prototype.push,
//    splice = prototype.splice,
//    join = prototype.join;
//
//function DOMTokenList(el) {
//
//  this.el = el;
//  // The className needs to be trimmed and split on whitespace
//  // to retrieve a list of classes.
//  var classes = el.className.replace(/^\s+|\s+$/g,'').split(/\s+/);
//  for (var i = 0; i < classes.length; i++) {
//    push.call(this, classes[i]);
//  }
//};
//
//
//
//})();
