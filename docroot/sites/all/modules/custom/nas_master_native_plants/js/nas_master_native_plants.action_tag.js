var nvtag_callbacks = nvtag_callbacks || {};

var alterFill = function (args) {
  var fields = Drupal.native_plants_fields_sync.get_fields();
  args.fill_dict.EmailAddress = fields.email;
  args.fill_dict.PostalCode = fields.zipcode;
  jQuery('.PostalCode input').attr('placeholder', Drupal.t('U.S. ZIP code'));
  jQuery('.EmailAddress input').attr('placeholder', Drupal.t('Email Address'));
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

var postRender = function () {
  jQuery('.at-row.EmailAddress').detach().insertBefore(".at-row.PostalCode");
  jQuery('.at-form-submit').detach().insertAfter(".at-row.PostalCode");
  var mapping = {
    '.EmailAddress > input': '.native-plants-search-form--email',
    '.PostalCode > input': '.native-plants-search-form--zip-code'
  };
  jQuery.each(mapping, function (actionTagSelector, usualSelector) {
    jQuery(actionTagSelector).on('input', function () {
      jQuery(usualSelector).val(jQuery(actionTagSelector).val()).trigger('input');
    })
  });
};
nvtag_callbacks.postRender = nvtag_callbacks.postRender || [];
nvtag_callbacks.postRender.push(postRender);
