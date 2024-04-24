#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    struct stock_data * data;
    struct stock_node * next_node;
} stock_node;

int main() {
    char temp_line[MAX_LINE_SIZE];
    char *token;
    int count = 0;

    stock_node *head = NULL;
    stock_node *current = NULL;

    FILE *stock_file = fopen(stockfile, "r");

    while (fgets(temp_line, MAX_LINE_SIZE, stock_file) != NULL) {
        count++;
        
        token = strtok(temp_line, DELIMITER);
        
        stock_node *new_node = (stock_node *)malloc(sizeof(stock_node));
        new_node->data = (struct stock_data *)malloc(sizeof(struct stock_data));
        
        int i = 1;
        while (token != NULL) {
            switch (i) {
                case 1:
                    strncpy(new_node->data->ticket_name, token, TICKET_NAME_LEN);
                    new_node->data->ticket_name[TICKET_NAME_LEN] = '\0'; // Ensure null-terminated
                    break;
                case 2:
                    new_node->data->ticket_type = token[0];
                    break;
                case 3:
                    strncpy(new_node->data->ticket_zone, token, TICKET_ZONE_LEN);
                    new_node->data->ticket_zone[TICKET_ZONE_LEN] = '\0'; // Ensure null-terminated
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
        
        new_node->next_node = NULL;

        if (head == NULL) {
            head = new_node;
            current = new_node;
        } else {
            current->next_node = new_node;
            current = new_node;
        }
    }

    // Example of using the populated linked list
    stock_node *temp = head;
    while (temp != NULL) {
        printf("Name: %s, Zone: %s, Price: %u, Level: %u\n", temp->data->ticket_name, temp->data->ticket_zone, temp->data->ticket_price, temp->data->stock_level);
        temp = temp->next_node;
    }

    // Free memory
    temp = head;
    while (temp != NULL) {
        stock_node *to_free = temp;
        temp = temp->next_node;
        free(to_free->data);
        free(to_free);
    }

    fclose(stock_file);

    return 0;
}
