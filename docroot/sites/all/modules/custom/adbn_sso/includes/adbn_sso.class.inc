<?php

/**
 * @file
 * Provides a class with implemented SOAP methods for SSO service.
 */

/**
 * Class AudubonSSOService
 *
 * Provides access to Audubon SSO service.
 */
class AudubonSSOService {
  private $soapClient;
  private $debug;
  private $debugFunction = 'dpm';

  public function __construct($soapClient, $debug = FALSE) {
    $this->soapClient = $soapClient;
    $this->debug = $debug;
  }

  /**
   * @param String $username
   * @return mixed
   */
  public function GetUserProfile($username) {
    $soapClient = $this->getSoapClient();

    $parameters = array('sUsername' => $username);
    $user_profile = $soapClient->GetUserProfile($parameters);

    if ($this->isDebug()) {
      $d = $this->getDebugFunction();
      $d($soapClient->getLastRequest());
      $d($soapClient->getLastResponse());
    }

    return $user_profile;
  }

  /**
   * @param AdbnUserProfile $profile
   * @param String $password
   * @return mixed
   */
  public function CreateUserProfile(AdbnUserProfile $profile, $password) {
    $soapClient = $this->getSoapClient();

    $parameters = array('profileUser' => $profile, 'sPassword' => $password);
    $user_profile = $soapClient->CreateUserProfile($parameters);

    if ($this->isDebug()) {
      $d = $this->getDebugFunction();
      $d($soapClient->getLastRequest());
      $d($soapClient->getLastResponse());
    }

    return $user_profile;
  }

  /**
   * Updates the profile in the SSO service.
   *
   * Note that the User field has to be set to the username that is updating
   * the profile data.
   *
   * @param AdbnUserProfile $profile
   * @param string $updating_username If null, will set to the provided
   *   profile username.
   * @return mixed
   */
  public function UpdateUserProfile(AdbnUserProfile $profile, $updating_username = NULL) {
    $soapClient = $this->getSoapClient();

    if (is_null($updating_username)) {
      $profile->User = $profile->Username;
    }
    else {
      $profile->User = $updating_username;
    }

    $parameters = array('profileUser' => $profile);
    $user_profile = $soapClient->UpdateUserProfile($parameters);

    if ($this->isDebug()) {
      $d = $this->getDebugFunction();
      $d($soapClient->getLastRequest());
      $d($soapClient->getLastResponse());
    }

    return $user_profile;
  }

  /**
   * Sets a new password for a user, using a password reset token.
   *
   * @return AdbnAAPResponse
   */
  public function SetUserPassword($username, $new_password, $password_reset_token, $is_temporary = FALSE) {
    $soapClient = $this->getSoapClient();

    $parameters = array(
      'sLink' => $password_reset_token,
      'bIsTemporary' => $is_temporary,
      'sUser' => $username,
      'sPassword' => $new_password,
    );
    $password_update_response = $soapClient->SetUserPassword($parameters);

    if ($this->isDebug()) {
      $d = $this->getDebugFunction();
      $d($soapClient->getLastRequest());
      $d($soapClient->getLastResponse());
    }

    return $password_update_response;
  }

  /**
   * Validates username and password in the SSO service.
   *
   * Note that if the Active flag is set to FALSE on the profile, this method
   * will also return FALSE, which means the user is blocked.
   *
   * @param String $username
   * @param String $password
   * @return mixed
   */
  public function ValidateUser($username, $password) {
    $soapClient = $this->getSoapClient();

    $parameters = array('sUsername' => $username, 'sPassword' => $password);
    $is_valid = $soapClient->ValidateUser($parameters);

    if ($this->isDebug()) {
      $d = $this->getDebugFunction();
      $d($soapClient->getLastRequest());
      $d($soapClient->getLastResponse());
    }

    return $is_valid;
  }

  /**
   * @param String $email
   * @param String $user_type
   * @return mixed
   */
  public function EmailExists($email, $user_type = AdbnUserType::ALL) {
    $soapClient = $this->getSoapClient();

    $parameters = array('sEmailAddress' => $email, 'eType' => $user_type);
    $email_exists = $soapClient->EmailExists($parameters);

    if ($this->isDebug()) {
      $d = $this->getDebugFunction();
      $d($soapClient->getLastRequest());
      $d($soapClient->getLastResponse());
    }

    return $email_exists;
  }

  /**
   * Given a username, and a link type, will return a new link value.
   *
   * @param String $username
   * @param String $link_type See AdbnLinkType.
   * @param String $requesting_user
   * @return mixed
   */
  public function GetNewActionLink($username, $link_type, $requesting_user = NULL) {
    $soapClient = $this->getSoapClient();

    if (is_null($requesting_user)) {
      $requesting_user = $username;
    }

    $parameters = array('sUsername' => $username, 'sUser' => $requesting_user, 'eLinkType' => $link_type);
    $result = $soapClient->GetNewActionLink($parameters);

    if ($this->isDebug()) {
      $d = $this->getDebugFunction();
      $d($soapClient->getLastRequest());
      $d($soapClient->getLastResponse());
    }

    return $result;
  }

  /**
   * Returns TRUE if the Active field on the profile is set to TRUE.
   *
   * @param String $username
   * @param String $type
   * @return mixed
   */
  public function UserIsValid($username, $type = AdbnUserType::ALL) {
    $soapClient = $this->getSoapClient();

    $parameters = array('sUsername' => $username, 'eType' => $type);
    $is_valid = $soapClient->UserIsValid($parameters);

    if ($this->isDebug()) {
      $d = $this->getDebugFunction();
      $d($soapClient->getLastRequest());
      $d($soapClient->getLastResponse());
    }

    return $is_valid;
  }

  /**
   * Searches for profiles by matching the given string in fields.
   *
   * @param String $criterion
   * @param bool $ad_user
   * @return mixed
   */
  public function SearchUserProfiles($criterion, $ad_user = FALSE) {
    $soapClient = $this->getSoapClient();

    $parameters = array('sCriterion' => $criterion, 'bADUser' => $ad_user);
    $user_profiles = $soapClient->SearchUserProfiles($parameters);

    if ($this->isDebug()) {
      $d = $this->getDebugFunction();
      $d($soapClient->getLastRequest());
      $d($soapClient->getLastResponse());
    }

    return $user_profiles;
  }

  /**
   * @param String $email
   * @return mixed
   */
  public function GetUserEmailAddress($username) {
    $soapClient = $this->getSoapClient();

    $parameters = array('sUsername' => $username);
    $email = $soapClient->GetUserEmailAddress($parameters);

    if ($this->isDebug()) {
      $d = $this->getDebugFunction();
      $d($soapClient->getLastRequest());
      $d($soapClient->getLastResponse());
    }

    return $email;
  }

  /**
   * @param String $email
   * @return mixed
   */
  public function GetUsername($email) {
    $soapClient = $this->getSoapClient();

    $parameters = array('sEmailAddress' => $email);
    $username = $soapClient->GetUsername($parameters);

    if ($this->isDebug()) {
      $d = $this->getDebugFunction();
      $d($soapClient->getLastRequest());
      $d($soapClient->getLastResponse());
    }

    return $username;
  }

  /**
   * @return mixed
   */
  public function getSoapClient() {
    return $this->soapClient;
  }

  /**
   * @param mixed $soapClient
   */
  public function setSoapClient($soapClient) {
    $this->soapClient = $soapClient;
  }

  /**
   * @return boolean
   */
  public function isDebug() {
    return $this->debug;
  }

  /**
   * @param boolean $debug
   */
  public function setDebug($debug) {
    $this->debug = $debug;
  }

  /**
   * @return string
   */
  public function getDebugFunction() {
    return $this->debugFunction;
  }

  /**
   * @param string $debugFunction
   */
  public function setDebugFunction($debugFunction) {
    $this->debugFunction = $debugFunction;
  }
}