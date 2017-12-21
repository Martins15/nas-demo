/**
 * @file
 * Embed native-plants (every action) form.
 *
 * Usage embedded form settings.
 *
 * <script>
 *  var nativePlantsEmbedFormSettings = {
 *    color_scheme: 'white',
 *    // color_scheme: 'black',
 *    shape: 'rectangle',
 *    // shape: 'square',
 *  };
 * </script>
 * <script id="native-plants-embed-form" src="http://audubon.org/sites/all/modules/custom/native_plants_embed_form/native_plants_embed_form.js"></script>
 */

window.onload = function() {
  nativePlantsEmbedForm();
};

function nativePlantsEmbedForm() {
  var id = 'native-plants-embed-form',
      script = document.getElementById(id);
  if (typeof script === 'undefined') {
    return;
  }
  var path = script.src.split('/')
    , homePath = path[0] + '//' + path[2];
  addAssets('script', 'https://d1aqhv4sn5kxtx.cloudfront.net/actiontag/at.js');
  addAssets('link', homePath + '/sites/all/modules/custom/native_plants_embed_form/native_plants_embed_form.min.css');
  addAssets('link', 'http://fonts.googleapis.com/css?family=Source+Sans+Pro:300,400,600');

  var parent = script.parentElement
    , div = document.createElement('div')
    , nativePlantsEmbedFormSettings = (typeof window.nativePlantsEmbedFormSettings === 'undefined')
      ? {color_scheme: 'white', shape: 'square'}
      : window.nativePlantsEmbedFormSettings;

  div.innerHTML =
    '<div class="ngp-form ' +
    nativePlantsEmbedFormSettings.color_scheme +
    ' ' +
    nativePlantsEmbedFormSettings.shape +
    '"' +
    ' data-form-url="https://actions.everyaction.com/v1/Forms/S49LshHFBUKAejEkZAfw-g2"' +
    ' data-fastaction-endpoint="https://fastaction.ngpvan.com"' +
    ' data-inline-errors="true"' +
    ' data-fastaction-nologin="true"' +
    ' data-databag="everybody">' +
    '</div>';
  parent.insertBefore(div, script.nextSibling);
}

function addAssets(type, data) {
  var asset = document.createElement(type);
  switch (type) {
    case 'script':
      asset.src = data;
      break;
    case 'link':
      asset.href = data;
      asset.rel = 'stylesheet';
      break;
  }
  document.head.appendChild(asset);
}

/**
 * Nvtag callbacks.
 */
var nvtag_callbacks = nvtag_callbacks || {};


var alterFill = function (args) {
  var emailAddress = document.getElementsByName('EmailAddress')
    , postalCode = document.getElementsByName('PostalCode');
  if (emailAddress[0].parentNode.className.indexOf('at-text') !== -1) {
    emailAddress[0].placeholder = 'Email Address';
  }
  if (postalCode[0].parentNode.className.indexOf('at-text') !== -1) {
    postalCode[0].placeholder = 'U.S. ZIP code';
  }
  return args;
};
nvtag_callbacks.alterFill = nvtag_callbacks.alterFill || [];
nvtag_callbacks.alterFill.push(alterFill);


var alterFormDefinition = function (args) {
  // Change submit button text.
  args.form_definition.form_elements[0].value = 'Search';
  args.form_definition.form_elements[1].children[1].required = false;
  // Add needed html.
  args.form_definition.form_elements[1].title = 'Find bird-friendly native plants for your area';
  var markup =
    '<div class="description">' +
      'Include your email, and Audubon will send tips on how to bring more birds to your home.' +
    '</div>' +
    '<div class="at_pp">' +
      '<a href="//audubon.org/privacy-policy">Privacy Policy</a>' +
    '</div>' +
    '<div class="at_home">' +
      '<a href="//audubon.org"><span>Audubon</span></a>' +
    '</div>';
  var new_item = {
    name: 'Description',
    title: 'Description',
    type: 'markup',
    markup: markup
  };
  args.form_definition.form_elements[1].children.push(new_item);
  return args;
};
nvtag_callbacks.alterFormDefinition = nvtag_callbacks.alterFormDefinition || [];
nvtag_callbacks.alterFormDefinition.push(alterFormDefinition);


var alterPost = function (args) {
  if (typeof args.data.PostalCode != 'undefined') {
    var isValidZip = /(^\d{5}$)|(^\d{5}-\d{4}$)/.test(args.data.PostalCode);
    if (isValidZip && typeof args.data.EmailAddress == 'undefined') {
      document.getElementsByClassName('at-inner')[0].style.display = 'none';
      location = '//audubon.org/native-plants/search?zipcode=' + args.data.PostalCode;
    }
  }
  return args;
};
nvtag_callbacks.alterPost = nvtag_callbacks.alterPost || [];
nvtag_callbacks.alterPost.push(alterPost);


var preSegue = function (args) {
  document.getElementsByClassName('at-inner')[0].style.display = 'none';
  location = '//audubon.org/native-plants/search?zipcode=' + args.data.PostalCode;
};
nvtag_callbacks.preSegue = nvtag_callbacks.preSegue || [];
nvtag_callbacks.preSegue.push(preSegue);


var postRender = function () {
  var description = document.getElementsByClassName('at-markup Description');
  description[description.length - 1].parentNode.className += 'at-description';
};
nvtag_callbacks.postRender = nvtag_callbacks.postRender || [];
nvtag_callbacks.postRender.push(postRender);
