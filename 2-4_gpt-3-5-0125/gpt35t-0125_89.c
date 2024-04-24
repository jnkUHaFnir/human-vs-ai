strcpy(snode[count - 1]->data->ticket_name, token); 
snode[count - 1]->data->ticket_type = token[0]; 
strcpy(snode[count - 1]->data->ticket_zone, token); 
snode[count - 1]->data->ticket_price = atoi(token); 
snode[count - 1]->data->stock_level = atoi(token); 
