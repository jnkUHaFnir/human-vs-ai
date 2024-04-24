#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define DELIMITER ","
#define TICKET_NAME_LEN 40
#define TICKET_ZONE_LEN 10

struct stock_data 
{
    char ticket_name[TICKET_NAME_LEN+1];
    char ticket_type;
    char ticket_zone[TICKET_ZONE_LEN+1];
    unsigned int ticket_price;
    unsigned int stock_level;
};

typedef struct stock_node 
{
    struct stock_data data;
    struct stock_node *next_node;
} stock_node;

int main() {
    char temp_line[MAX_LINE_SIZE];
    char *token;
    int count = 0;

    stock_node *head = NULL;
    stock_node *current = NULL;

    FILE *stock_file = fopen("stockfile.txt", "r");
    if (stock_file == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    while (fgets(temp_line, MAX_LINE_SIZE, stock_file) != NULL) {
        count++;

        stock_node *new_node = (stock_node *)malloc(sizeof(stock_node));
        if (new_node == NULL) {
            perror("Memory allocation failed");
            return 1;
        }

        new_node->next_node = NULL;

        token = strtok(temp_line, DELIMITER);

        if (token == NULL) {
            free(new_node);
            continue; // Skip empty lines
        }

        strcpy(new_node->data.ticket_name, token);

        token = strtok(NULL, DELIMITER);
        if (token == NULL) {
            free(new_node);
            continue; // Handling incomplete lines
        }

        new_node->data.ticket_type = token[0];

        token = strtok(NULL, DELIMITER);
        if (token == NULL) {
            free(new_node);
            continue; // Handling incomplete lines
        }

        strcpy(new_node->data.ticket_zone, token);

        token = strtok(NULL, DELIMITER);
        if (token == NULL) {
            free(new_node);
            continue; // Handling incomplete lines
        }

        new_node->data.ticket_price = atoi(token);

        token = strtok(NULL, DELIMITER);
        if (token == NULL) {
            free(new_node);
            continue; // Handling incomplete lines
        }

        new_node->data.stock_level = atoi(token);

        if (head == NULL) {
            head = new_node;
            current = head;
        } else {
            current->next_node = new_node;
            current = new_node;
        }
    }

    fclose(stock_file);

    // Output information from linked list
    current = head;
    while (current != NULL) {
        printf("Ticket Name: %s\n", current->data.ticket_name);
        printf("Ticket Type: %c\n", current->data.ticket_type);
        printf("Ticket Zone: %s\n", current->data.ticket_zone);
        printf("Ticket Price: %u\n", current->data.ticket_price);
        printf("Stock Level: %u\n", current->data.stock_level);
        
        stock_node *temp = current;
        current = current->next_node;
        free(temp);
    }

    return 0;
}
