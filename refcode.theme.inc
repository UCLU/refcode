<?php
/**
 * @file
 * Theme functions for the Refcode module.
 */

/**
 * Template for linking to referenced entities.
 *
 * Variables:
 *     - 'refcode'      The refcode (string).
 *     - 'path'         The referenced entity's path (string).
 *     - 'label'        A label for the referenced entity (string).
 *     - 'link'         Whether to provide a link (Boolean).
 *     - 'append code'  Whether to append the raw refcode if 'label' is set.
 */
function theme_refcode_link(array $variables) {
  $label = $variables['label'];
  if (empty($label)) {
    $label = '<code>' . $variables['refcode'] . '</code>';
  }
  elseif ($variables['append code']) {
    $label .= ' <code class="refcode-small">(' . $variables['refcode'] . ')</code>';
  }
  if ($variables['link']) {
    return l($label, $variables['path'], array('html' => TRUE, 'attributes' => $variables['attributes']) + $variables['link options']);
  }
  return '<span' . drupal_attributes($variables['attributes']) . '>' . $label . '</span>';
}

/**
 * Template preprocess callback for entity links.
 *
 * @see theme_refcode()
 */
function template_preprocess_refcode_link(array &$variables) {

  // Sanitize variables.
  $variables['refcode'] = check_plain($variables['refcode']);

  if (!empty($variables['label'])) {
    $variables['label'] = check_plain($variables['label']);
    $variables['attributes']['title'] = t('!refcode: !label', array(
      '!refcode' => $variables['refcode'],
      '!label' => $variables['label'],
    ));
  }

  if ($variables['broken']) {
    $variables['attributes']['class'][] = 'refcode-broken';
  }

  // Don't link if there is no path.
  if (empty($variables['path'])) {
    $variables['link'] = FALSE;
  }

}
