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
  return l($variables['label'], $variables['uri']);
}

/**
 * Template preprocess callback for entity links.
 *
 * @see theme_refcode()
 */
function template_preprocess_refcode_link(array &$variables) {
  $entity = $variables['entity'];
  $entity_type = $variables['type'];
  $entity_id = $variables['id'];
  $uri = entity_uri($entity_type, $entity);
  $path = $uri['path'];

  $entity_wrapper = entity_metadata_wrapper($entity_type, $entity);
  $label = $entity_wrapper->label();
  $bundle = $entity_wrapper->getBundle();

  $variables['refcode'] = check_plain($variables['refcode']);
  $variables['type'] = check_plain($entity_type);
  $variables['id'] = (int) $entity_id;
  $variables['label'] = check_plain($label);
  $variables['uri'] = check_plain($path);
}
