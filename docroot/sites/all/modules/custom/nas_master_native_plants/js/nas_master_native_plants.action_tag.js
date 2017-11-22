var nvtag_callbacks = nvtag_callbacks || {};

var alterFill = function (args) {
  var storage = JSON.parse(jQuery.cookie('native_plants_fields_sync'));
  var zipcode = '';
  var email = '';
  if (storage) {
    zipcode = storage.PostalCode;
    email = storage.EmailAddress;
  }

  jQuery('.PostalCode input').attr('placeholder', Drupal.t('U.S. ZIP code')).val(zipcode);
  jQuery('.EmailAddress input').attr('placeholder', Drupal.t('Email Address')).val(email);

  return args;
};

nvtag_callbacks.alterFill = nvtag_callbacks.alterFill || [];
nvtag_callbacks.alterFill.push(alterFill);

var alterFormDefinition = function (args) {
  args.form_definition.form_elements[0].value = Drupal.t('Search');
  args.form_definition.form_elements[1].children[1].required = false;
  return args;
};
nvtag_callbacks.alterFormDefinition = nvtag_callbacks.alterFormDefinition || [];
nvtag_callbacks.alterFormDefinition.push(alterFormDefinition);

var alterPost = function (args) {
  var storage = JSON.stringify(args.data);
  jQuery.cookie('native_plants_fields_sync', storage, {expires: 7, path: Drupal.settings.basePath});

  if (typeof args.data.PostalCode != 'undefined') {
    var isValidZip = /(^\d{5}$)|(^\d{5}-\d{4}$)/.test(args.data.PostalCode);
    if (isValidZip && typeof args.data.EmailAddress == 'undefined') {
      Drupal.ajaxScreenLock.blockUI();
      jQuery('.ngp-form').hide();
      location = Drupal.settings.basePath + 'native-plants/search?zipcode=' + args.data.PostalCode;
    }
  }
  return args;
};
nvtag_callbacks.alterPost = nvtag_callbacks.alterPost || [];
nvtag_callbacks.alterPost.push(alterPost);

var preSegue = function (args) {
  Drupal.ajaxScreenLock.blockUI();
  jQuery('.ngp-form').hide();
  location = Drupal.settings.basePath + 'native-plants/search?zipcode=' + args.postVals.PostalCode;
};
nvtag_callbacks.preSegue = nvtag_callbacks.preSegue || [];
nvtag_callbacks.preSegue.push(preSegue);


var postRender = function () {
  jQuery('.at-row.EmailAddress').detach().insertBefore(".at-row.PostalCode");
  jQuery('.at-form-submit').detach().insertAfter(".at-row.PostalCode");
};
nvtag_callbacks.postRender = nvtag_callbacks.postRender || [];
nvtag_callbacks.postRender.push(postRender);
