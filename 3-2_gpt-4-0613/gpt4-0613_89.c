  snode = (stock_node *) realloc(snode, count * sizeof(stock_node));
  if (snode == NULL) { abort(); }  

  snode[count - 1].data = (struct stock_data *) malloc(sizeof(struct stock_data));
  if (snode[count - 1].data == NULL) { abort(); }
