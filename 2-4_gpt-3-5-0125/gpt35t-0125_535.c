stock_node * snode = NULL;
struct stock_data * sdata = NULL;

FILE *stock_file = fopen(stockfile, "r");
if (stock_file == NULL) {
    fprintf(stderr, "Error opening file\n");
    return 1;
}

while (fgets(temp_line, MAX_LINE_SIZE, stock_file) != NULL) {
    token = strtok(temp_line, DELIMITER);
    count++;

    snode = (stock_node *)realloc(snode, count * sizeof(stock_node));
    if (snode == NULL) { 
        fprintf(stderr, "Error allocating memory\n");
        return 1;
    }
    
    snode[count - 1].data = (struct stock_data *)malloc(sizeof(struct stock_data));
    if (snode[count - 1].data == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        return 1;
    }

    i = 1;

    while (token != NULL) {
        switch (i) {
        case 1:
            strncpy(snode[count - 1].data->ticket_name, token, TICKET_NAME_LEN);
            snode[count - 1].data->ticket_name[TICKET_NAME_LEN] = '\0';
            break;
        case 2:
            snode[count - 1].data->ticket_type = token[0];
            break;
        case 3:
            strncpy(snode[count - 1].data->ticket_zone, token, TICKET_ZONE_LEN);
            snode[count - 1].data->ticket_zone[TICKET_ZONE_LEN] = '\0';
            break;
        case 4:
            snode[count - 1].data->ticket_price = atoi(token);
            break;
        case 5:
            snode[count - 1].data->stock_level = atoi(token);
            break;
        }

        token = strtok(NULL, DELIMITER);
        i++;
    }
}

fclose(stock_file);
