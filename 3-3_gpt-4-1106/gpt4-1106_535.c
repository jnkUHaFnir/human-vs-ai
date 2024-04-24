#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define DELIMITER ","
#define TICKET_NAME_LEN 40
#define TICKET_ZONE_LEN 10

struct stock_data {
    char ticket_name[TICKET_NAME_LEN+1];
    char ticket_type;
    char ticket_zone[TICKET_ZONE_LEN+1];
    unsigned int ticket_price;
    unsigned int stock_level;
};

typedef struct stock_node {
    struct stock_data data; // Use struct stock_data directly rather than a pointer
    struct stock_node *next_node;
} stock_node;

char temp_line[MAX_LINE_SIZE];
char *token;
int i;

stock_node *head = NULL; // Use a head pointer for the linked list
stock_node *current = NULL; // This will point to the current node being processed
stock_node *previous = NULL; // This will keep track of the previous node

// stockfile path should be provided or declared somewhere before use
// FILE *stock_file = fopen(stockfile, "r");
// If stockfile is not declared, use a valid file path for fopen

if (!stock_file) { // Check if the file was successfully opened
    perror("Error opening stock file");
    return 1; // Exit if file could not be opened
}

while (fgets(temp_line, MAX_LINE_SIZE, stock_file) != NULL) {
    current = (stock_node *)malloc(sizeof(stock_node)); // Allocate memory for a new node
    if (current == NULL) { abort(); }

    // Initialize the next_node pointer to NULL for the new node
    current->next_node = NULL;

    if (previous != NULL) {
        previous->next_node = current;
    } else {
        head = current; // Set head if this is the first node
    }

    token = strtok(temp_line, DELIMITER);
    i = 1;

    while (token != NULL) {
        switch (i) {
            case 1:
                strncpy(current->data.ticket_name, token, TICKET_NAME_LEN);
                break;
            case 2:
                current->data.ticket_type = token[0];
                break;
            case 3:
                strncpy(current->data.ticket_zone, token, TICKET_ZONE_LEN);
                break;
            case 4:
                current->data.ticket_price = (unsigned int)atoi(token);
                break;
            case 5:
                current->data.stock_level = (unsigned int)atoi(token);
                break;
        }

        token = strtok(NULL, DELIMITER);
        i++;
    }

    previous = current; // Move the previous pointer to the current node
}

fclose(stock_file); // Don't forget to close the file

// Don't forget to free the linked list when you're done with it!
stock_node *tmp;
while (head) {
    tmp = head; // Save the current head node
    head = head->next_node; // Move to the next node
    free(tmp); // Free the saved node
}

return 0;
