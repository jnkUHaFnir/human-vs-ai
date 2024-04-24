FILE *stock_file = fopen(stockfile, "r");
if (stock_file == NULL) {
    // Handle error
}

stock_node *head = NULL;
stock_node *current = NULL;

while (fgets(temp_line, MAX_LINE_SIZE, stock_file) != NULL) {
    stock_node *new_node = (stock_node *) malloc(sizeof(stock_node));
    if (new_node == NULL) { abort(); }
    
    new_node->data = (struct stock_data *) malloc(sizeof(struct stock_data));
    if (new_node->data == NULL) { abort(); }
    
    new_node->next_node = NULL; // Initialize the next_node to NULL

    // Now, token processing and data assignment...
    token = strtok(temp_line, DELIMITER);
    i = 0;
    while(token != NULL) {
        // Your case switch here, assigning values to new_node->data based on i++
        // No need for count - 1 logic; direct assignment to new_node->data's fields.
        
        token = strtok (NULL, DELIMITER);
        i++;
    }
    
    // Inserting the newly created node into the linked list
    if (head == NULL) {
        // First node (head)
        head = new_node;
        current = new_node;
    } else {
        current->next_node = new_node;
        current = new_node;
    }
}
