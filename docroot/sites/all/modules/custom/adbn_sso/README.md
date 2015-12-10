# Audubon SSO

Introduction
------------
This modules implements a Drupal authentication / authorization solution with
the Audubon (SSO) .NET service. It provides mechanisms to:

* login using SSO credentials in Drupal (thus also creating a local account)
* register a new user in the SSO (as well as a local one)
* set a mandatory registration code when registering
* manage a list of emails that are authorized to login and use the Drupal site
* synchronize profile information between SSO and Drupal
* block local accounts when an SSO account is blocked
* disallow Active Directory users to change profile information in SSO
* change the SSO password using the standard Drupal reset password page
* disable local login, and only allow SSO login
* allow (force) users to use a one-time login link when SSO is down
* configurable error and notification messages

Required and optional modules
----------------------------
This module requires the entity module to provide the authorization behavior, but
given that the module is very popular in standard Drupal projects, this should
not be a problem.

Given that the specifications for the creation of the module required the
username and email of a user to be the same, this module advises the use of the
email_registration module, to make sure both Drupal username and email are the
same. 

It is not required, but in case it is not installed, both the user name
and the email appear available on the user registration form. Upon submission
the email will override the username (the entered user name is discarded
entirely), so it would be advised to hide the user name field using a
hook_form_alter or some similar approach.


Configuration
--------------------

After enabling the module, there is a list of Drupal variables that can be 
changed by an administrator at 
**http://sitename/admin/config/people/audubon_sso**. They can also be changed 
using the drush command **drush vset variable_name**.

**Note:** It is required to choose at least the First and Last name fields to be mapped
to Drupal user fields, so the SSO user registration process works, otherwise
the service will deny creating a new user, who's name is not specified.

The messages, notifications and emails can be changed at
**http://sitename/admin/config/people/audubon_sso/messages**.

The configuration variables include:

* show a registration code on the user registration form
 * modify the registration code

* create an account in SSO when a user submits the registration form
* allow / disallow SSO authentication (login with SSO emails)
 * modify the order of login checks between SSO and standard login methods
* allow / disallow standard Drupal authentication
* force one-time login page, thus disabling all other login methods

* configure field mapping between SSO fields and Drupal user fields

* select which WSDL file to use for communication (production or testing)
 * modify the paths to the WSDL files, to allow using other ones if necessary
 
The list of authorized emails that can use the Drupal site can be found at 
**http://sitename/admin/structure/authorization-list**. This interface allows 
basic operations to add, edit, remove, sort and import emails. For a better
user interface it is advised to install the admin_views module.

Development notes
-----------------

###### SOAP and API implementation
The module uses the Zend SOAP Client component (specifically the DotNet one) to
communicate with the SSO service. It was set up using composer, and stored in
the vendor folder.

It also defines a new class **AudubonSSOService** that implements the methods 
that are essentially wrappers around the SOAP calls, with support for debugging.
This class can be inherited and used instead of the default one by implementing
the **hook_adbn_sso_class()** hook.

As another layer of indirection there are simple php functions for each method
defined in the class, which have exception handling, and also instantiate the
provided class.

###### Functionality separation

Most of the functionality of the module is split up between include files,
specific to the task they are solving. There are also a couple of classes
in regard to the SOAP types return by the service, and regarding custom
entity integration.

###### Login and registration

The module uses a customized function originally provided by Drupal for 
the external login process (specifically **user_external_login_register**).
 
It tries to to add its own functions regarding validation and submissions
hooks related to user registration, login process, reset password, and other
user related tasks, instead of removing or replacing the existing Drupal
provided ones, thus allowing more flexibility and re-using existing code.

Sometimes it is not possible to get certain information in various processes
(new user registration, or login process), and static variables are used to
pass information between method calls:
 
 * **adbn_sso_set_user_authenticated_via_service()**
 * **adbn_sso_set_user_is_being_registered_in_service()**

###### Email registration (optional) 
 
Installing the email_registration module is recommended, so it hides the
default username field on registration, and replaces it only with the email.
In case the module is not installed, the entered email will be used as the
username, so the username field should be hidden using a hook_form_alter or 
something similar.

###### Authorization

A custom entity is implemented to provide support for authorization entries,
together with a custom administration UI class. There is also an entity that
serves as a bundle (similar to Node and Node types), but there is only one
predefined bundle which is created during module installation. In the future
it might be possible to create specific authorization bundles with some custom
behaviors.

###### Field synchronization

SSO field synchronization is done when viewing a user edit page, rather than
on each page where user info is shown, so we don't make page loading slow
because of external calls to the SSO. The user fields in Drupal are essentially
used for caching purposes.

There is also code related to prefixing fields with "fields:" when storing the 
mapping configuration between SSO fields and User fields. This is to allow
future code to synchronize not only with Drupal fields, but with other 
destinations like Profile2, User properties, etc. The idea was borrowed from
the ldap module.

###### One-time login page

There is a separate page for the one-time login functionality instead of the
password reset page, for a couple of reasons:

* allow changes to text markup of the form and pages regarding one-time login
* disallow SSO password change without entering current password, the way
 the reset password page works.
 
The code is mostly copy-paste of the reset password page with slight
modifications for viewing purposes, and to remove the pass reset functionality.

###### Reset password and Active Directory users

We do not allow users that were imported via Active Directory to change any of 
their profile settings or change their password.

The method to check if a user is an ADUser, is currently not stable, it just 
checks ig the first part of the email is equal to the username. This should be
fixed when the SSO service will correctly return the ADUser value. 

TODOs
-----

There are a couple of small TODOs spread in the code which should be fixed /
implemented in the future:

* On the SSO Message administration form, if you click the "Get default message"
button, and your site is a multi-language one, odds are it will not return the
proper message because of the way t() and custom locale string overrides work.
It might take some time to figure out how to do this properly.

* On cron run, all SSO users cached profile data is updated at once. For a site
with a small user count this is fine, but if there are multiple users, it would
be better to update the users in batches, rather than all at once.

* On the user registration form, the callback that creates the SSO account is
appended to the list of validation callbacks, via an after_build callback. 
Depending on other contributed modules that deal with user registration, there 
might be a problem if the following conditions are met:
    * the contributed module adds its own after_build callback on the user
      registration form
    * it appends a validation callback inside that after_build callback 

If this happens, the SSO account will be created before checking that last
validation callback. The chances of this happening is very-very small. We cannot
use module_implements_alter to change the form_alter order, or increase the
module weight, because that would change the order for all forms. It would
create some inconsistencies for the edit account / profile form, in cases where
distributions like Commons are used, which executes the edit profile form alter
twice.