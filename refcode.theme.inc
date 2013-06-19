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
  if ($variables['append code']) {
    $label .= ' (' . $variables['refcode'] . ')';
  }
  if ($variables['link']) {
    $output = l($label, $variables['path'], $variables['link options']);
  }
  else {
    $output = $label;
  }
  if ($variables['broken']) {
    $output = '<span class="refcode-broken">' . $output . '</span>';
  }
  return $output;
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

  if (empty($variables['label'])) {
    $variables['label'] = $variables['refcode'];
    $variables['append code'] = FALSE;
  }

  // Sanitize variables.
  $variables['refcode'] = check_plain($variables['refcode']);
  $variables['label'] = check_plain($variables['label']);

}
