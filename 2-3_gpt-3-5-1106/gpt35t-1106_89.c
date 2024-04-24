while (fgets(temp_line, MAX_LINE_SIZE, stock_file) != NULL) {

  token = strtok (temp_line, DELIMITER);
  count++;

  snode = (stock_node *) realloc(snode, count * sizeof(stock_node));
  if (snode == NULL) { abort(); }  

  snode[count - 1].data = (struct stock_data *) malloc(sizeof(struct stock_data)); // Allocate memory for snode->data
  if (snode[count - 1].data == NULL) { abort(); }  

  i = 1;

 while(token != NULL) {
     switch(i) {
        case 1:
           strcpy(snode[count - 1].data->ticket_name, token);
           break;
        case 2:
           snode[count - 1].data->ticket_type = token[0];
           break;
        case 3:
           strcpy(snode[count - 1].data->ticket_zone, token);
           break;
        case 4:
           snode[count - 1].data->ticket_price = atoi(token);
           break;
        case 5:
           snode[count - 1].data->stock_level = atoi(token);
           break;                                                            
     }

     token = strtok (NULL, DELIMITER);
     i++;
  }
}
