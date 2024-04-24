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
    struct stock_data * data;
    struct stock_node * next_node;
} stock_node;

int main() {
    char temp_line[MAX_LINE_SIZE];
    char *token;
    int count = 0;

    stock_node * list_head = NULL;
    stock_node * current_node = NULL;

    FILE *stock_file = fopen("stockfile", "r");

    while (fgets(temp_line, MAX_LINE_SIZE, stock_file) != NULL) {
        token = strtok(temp_line, DELIMITER);
        count++;

        if (list_head == NULL) {
            list_head = (stock_node *)malloc(sizeof(stock_node));
            current_node = list_head;
        } else {
            current_node->next_node = (stock_node *)malloc(sizeof(stock_node));
            current_node = current_node->next_node;
        }

        current_node->data = (struct stock_data *)malloc(sizeof(struct stock_data));
        
        int i = 1;
        while (token != NULL) {
            switch(i) {
                case 1:
                    strncpy(current_node->data->ticket_name, token, TICKET_NAME_LEN);
                    break;
                case 2:
                    current_node->data->ticket_type = token[0];
                    break;
                case 3:
                    strncpy(current_node->data->ticket_zone, token, TICKET_ZONE_LEN);
                    break;
                case 4:
                    current_node->data->ticket_price = atoi(token);
                    break;
                case 5:
                    current_node->data->stock_level = atoi(token);
                    break;
            }
            token = strtok(NULL, DELIMITER);
            i++;
        }
        current_node->next_node = NULL; // Set next node to NULL for the last node in the list
    }

    fclose(stock_file);

    // Code to free the allocated memory goes here

    return 0;
}
