FILE *stock_file = fopen(stockfile, "r");
if (stock_file == NULL) {
    // Handle error.
}

stock_node *head = NULL;
stock_node *current = NULL;

while (fgets(temp_line, MAX_LINE_SIZE, stock_file) != NULL) {
    token = strtok(temp_line, DELIMITER);

    stock_node *new_node = (stock_node *) malloc(sizeof(stock_node));
    if (new_node == NULL) { abort(); }

    new_node->data = (struct stock_data *) malloc(sizeof(struct stock_data));
    if (new_node->data == NULL) { abort(); }
  
    // Set the next_node to NULL as this will be the latest node in the list
    new_node->next_node = NULL;

    i = 1;

    while (token != NULL) {
        switch (i) {
            case 1:
                strcpy(new_node->data->ticket_name, token);
                break;
            case 2:
                new_node->data->ticket_type = token[0];
                break;
            case 3:
                strcpy(new_node->data->ticket_zone, token);
                break;
            case 4:
                new_node->data->ticket_price = atoi(token);
                break;
            case 5:
                new_node->data->stock_level = atoi(token);
                break;                                                            
        }

        token = strtok(NULL, DELIMITER);
        i++;
    }

    // Adding the newly created node to the linked list
    if (head == NULL) {
        head = new_node;
        current = new_node;
    } else {
        current->next_node = new_node;
        current = new_node;
    }
}

fclose(stock_file);
