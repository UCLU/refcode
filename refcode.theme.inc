<?php
/**
 * @file
 * Theme functions for the Refcode module.
 */

/**
 * Template for linking to referenced entities.
 *
 * Variables:
 *     - refcode The refcode.
 *     - type    The referenced entity type.
 *     - id      The referenced entity's ID.
 *     - bundle  The referenced entity's bundle.
 *     - label   The referenced entity's label.
 *     - path    The referenced entity's path.
 */
function theme_refcode_link(array $variables) {
  $label = $variables['label'];
  if (empty($label)) {
    $label = '<code>' . $variables['refcode'] . '</code>';
  }
  elseif ($variables['append code']) {
    $label .= ' (<code>' . $variables['refcode'] . '</code>)';
  }
  if ($variables['link']) {
    $output = l($label, $variables['path'], array('html' => TRUE) + $variables['link options']);
  }
  else {
    $output = $label;
  }
  return '<span' . drupal_attributes($variables['attributes']) . '>' . $output . '</span>';
}

/**
 * Template preprocess callback for entity links.
 *
 * @see theme_refcode()
 */
function template_preprocess_refcode_link(array &$variables) {

  if (empty($variables['path'])) {
    $variables['link'] = FALSE;
  }

  $variables['attributes']['class'][] = 'refcode';

  if ($variables['broken']) {
    $variables['attributes']['class'][] = 'refcode-broken';
  }

  // Sanitize variables.
  $variables['refcode'] = check_plain($variables['refcode']);
  $variables['label'] = check_plain($variables['label']);

}
