stock_node *new_node = (stock_node *) malloc(sizeof(stock_node));
if (new_node == NULL) { abort(); }
new_node->data = (struct stock_data *) malloc(sizeof(struct stock_data));
if (new_node->data == NULL) { abort(); }
strcpy(new_node->data->ticket_name, token);
new_node->data->ticket_type = token[0];
strcpy(new_node->data->ticket_zone, token);
new_node->data->ticket_price = atoi(token);
new_node->data->stock_level = atoi(token);
new_node->next_node = snode;
snode = new_node;
