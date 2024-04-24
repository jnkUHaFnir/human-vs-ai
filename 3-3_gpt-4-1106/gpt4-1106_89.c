stock_node *snode_head = NULL; // List head
stock_node *snode_last = NULL; // Pointer to the last node
FILE *stock_file = fopen(stockfile, "r");

if (stock_file == NULL) {
    perror("Error opening file");
    return 1;
}

while (fgets(temp_line, MAX_LINE_SIZE, stock_file) != NULL) {
    token = strtok(temp_line, DELIMITER);

    snode = (stock_node *)malloc(sizeof(stock_node));
    if (snode == NULL) {
        abort(); // Or handle the memory allocation failure gracefully
    }

    snode->data = (struct stock_data *)malloc(sizeof(struct stock_data));
    if (snode->data == NULL) {
        abort(); // Or handle the memory allocation failure gracefully
    }

    snode->next_node = NULL; // Initialize the next_node pointer

    // If this is the first element, snode_head will point to it,
    // Otherwise, we add the new snode at the end of the list.
    if (snode_last != NULL) {
        snode_last->next_node = snode;
    } else {
        snode_head = snode;
    }
    snode_last = snode; // Update snode_last to point to the new last node.

    i = 1;

    while (token != NULL) {
        switch (i) {
            case 1:
                strncpy(snode->data->ticket_name, token, TICKET_NAME_LEN);
                snode->data->ticket_name[TICKET_NAME_LEN] = '\0';  // Ensure termination
                break;
            case 2:
                snode->data->ticket_type = token[0];
                break;
            case 3:
                strncpy(snode->data->ticket_zone, token, TICKET_ZONE_LEN);
                snode->data->ticket_zone[TICKET_ZONE_LEN] = '\0';  // Ensure termination
                break;
            case 4:
                snode->data->ticket_price = (unsigned int)atoi(token);
                break;
            case 5:
                snode->data->stock_level = (unsigned int)atoi(token);
                break;
        }

        token = strtok(NULL, DELIMITER);
        i++;
    }

    count++; // Keep track of how many nodes you have processed
}

// Don't forget to close the file after you're finished processing it
fclose(stock_file);
