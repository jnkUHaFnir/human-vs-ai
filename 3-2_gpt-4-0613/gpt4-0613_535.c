snode = (stock_node *) realloc(snode, count * sizeof(stock_node));
if (snode == NULL) { abort(); }  

for(int j = 0; j < count; j++) {
    snode[j].data = (struct stock_data *) malloc(sizeof(struct stock_data));
    // you need to initialize your next_node values too
    snode[j].next_node = NULL; // or `snode[j].next_node = address_of_another_stock_node`
    if (snode[j].data == NULL) { abort(); }  
}
     switch(i) {
        //...
        default:
           fprintf(stderr, "Unexpected additional data in line: %s\n", token);
           exit(1);
    }
