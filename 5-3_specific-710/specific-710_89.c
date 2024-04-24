snode = (stock_node *)realloc(snode, count * sizeof(stock_node));
if (snode == NULL) { abort(); }

snode[count - 1].data = (struct stock_data *)malloc(sizeof(struct stock_data));
if (snode[count - 1].data == NULL) { abort(); }
strcpy(snode[count - 1].data->ticket_name, token);
snode[count - 1].data->ticket_type = token[0];
strcpy(snode[count - 1].data->ticket_zone, token);
snode[count - 1].data->ticket_price = atoi(token);
snode[count - 1].data->stock_level = atoi(token);
