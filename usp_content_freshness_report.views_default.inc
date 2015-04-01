<?php
/**
 * @file
 * usp_content_freshness_report.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function usp_content_freshness_report_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'freshness_report';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Freshness Report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Freshness Report';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_content_review_due_date' => 'field_content_review_due_date',
    'title_1' => 'title_1',
    'type' => 'type',
    'field_content_review_period' => 'field_content_review_period',
    'php' => 'php',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_content_review_due_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_content_review_period' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Description and Instructions';
  $handler->display->display_options['header']['area']['content'] = 'Items listed below are either past due for review, based on when they were last updated and the Content Review Period selected for the item, or will be due for review in the next 30 days.  To review an item, click its title from the list below, select the Edit option, make any necessary changes, and save the item.  If no changes are necessary, just Edit and Save without making any changes.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['label'] = 'Summary';
  $handler->display->display_options['header']['php']['php_output'] = '<?php
$item_count = count($results);

if (isset ($_GET[\'department\']) && $_GET[\'department\']) {
  $out =  t(\'Currently, @items items are in need of review by @department.\', array(\'@items\' => $item_count, \'@department\' => $_GET[\'department\'])) ;
  $out .= " " . l(t(\'View all items in need of review.\'), $view->get_url());
}
else {
  $out =  t(\'Currently, @items items are in need of review.\', array(\'@items\' => $item_count)) ;
}
echo "<div>" . $out . "</div>";
?>';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Relationship: OG membership: Group Node from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['relationship'] = 'og_membership_rel';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  /* Field: Content: Content Review Due Date */
  $handler->display->display_options['fields']['field_content_review_due_date']['id'] = 'field_content_review_due_date';
  $handler->display->display_options['fields']['field_content_review_due_date']['table'] = 'field_data_field_content_review_due_date';
  $handler->display->display_options['fields']['field_content_review_due_date']['field'] = 'field_content_review_due_date';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Responsible Department';
  $handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['php']['alter']['path'] = 'freshness-report?department=[php]';
  $handler->display->display_options['fields']['php']['alter']['alt'] = 'Filter by Department';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$out = $row->title_1;
if (!$row->title_1) {
  $out = $row->title;
}
return $out;';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '2';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['title_1']['label'] = 'Responsible Department';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '[title_1]';
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['path'] = 'freshness-report?department=[title_1]';
  $handler->display->display_options['fields']['title_1']['empty'] = '[title]';
  $handler->display->display_options['fields']['title_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Content Review Period */
  $handler->display->display_options['fields']['field_content_review_period']['id'] = 'field_content_review_period';
  $handler->display->display_options['fields']['field_content_review_period']['table'] = 'field_data_field_content_review_period';
  $handler->display->display_options['fields']['field_content_review_period']['field'] = 'field_content_review_period';
  $handler->display->display_options['fields']['field_content_review_period']['empty'] = '[title]';
  /* Sort criterion: Content: Content Review Due Date (field_content_review_due_date) */
  $handler->display->display_options['sorts']['field_content_review_due_date_value']['id'] = 'field_content_review_due_date_value';
  $handler->display->display_options['sorts']['field_content_review_due_date_value']['table'] = 'field_data_field_content_review_due_date';
  $handler->display->display_options['sorts']['field_content_review_due_date_value']['field'] = 'field_content_review_due_date_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Content Review Due Date (field_content_review_due_date) */
  $handler->display->display_options['filters']['field_content_review_due_date_value']['id'] = 'field_content_review_due_date_value';
  $handler->display->display_options['filters']['field_content_review_due_date_value']['table'] = 'field_data_field_content_review_due_date';
  $handler->display->display_options['filters']['field_content_review_due_date_value']['field'] = 'field_content_review_due_date_value';
  $handler->display->display_options['filters']['field_content_review_due_date_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_content_review_due_date_value']['group'] = 1;
  /* Filter criterion: Review Due Date not more than 30 days from now */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['ui_name'] = 'Review Due Date not more than 30 days from now';
  $handler->display->display_options['filters']['php']['group'] = 1;
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = '$this_node = array_pop(entity_load(\'node\', array($data->nid)));
$due_date = array_pop(array_pop(field_get_items(\'node\', $this_node, \'field_content_review_due_date\')));

// exclude records due more than 30 days from now
if ($due_date >= time() + 2592000) {
  return TRUE;
}
return FALSE;';
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php_1']['id'] = 'php_1';
  $handler->display->display_options['filters']['php_1']['table'] = 'views';
  $handler->display->display_options['filters']['php_1']['field'] = 'php';
  $handler->display->display_options['filters']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php_1']['php_filter'] = 'if (isset($_GET[\'department\']) && $_GET[\'department\']) {
  if ($_GET[\'department\'] == $row->php) {
    return FALSE;
  }
  else {
    return TRUE;
  }
}
';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'freshness-report';
  $export['freshness_report'] = $view;

  return $export;
}
