<?php

/**
 * @file
 * Token module integration.
 */

/**
 * Implements hook_token_info().
 */
function refcode_token_info() {
  $types['refcode-field'] = array(
    'name' => t('Refcode field values'),
    'description' => t('Refcode field in the default format.'),
    'needs-data' => 'refcode-field',
  );
  $tokens['refcode-field'] = array();
  $tokens['refcode-field']['default'] = array(
    'name' => t('Refcode default'),
    'description' => t('Refcode default'),
  );
  return array(
    'types' => $types,
    'tokens' => $tokens,
  );
}
