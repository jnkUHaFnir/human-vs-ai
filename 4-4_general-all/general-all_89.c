#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define DELIMITER ","
#define TICKET_NAME_LEN 40
#define TICKET_ZONE_LEN 10

struct stock_data {
    char ticket_name[TICKET_NAME_LEN + 1];
    char ticket_type;
    char ticket_zone[TICKET_ZONE_LEN + 1];
    unsigned int ticket_price;
    unsigned int stock_level;
};

typedef struct stock_node {
    struct stock_data *data;
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
        token = strtok(temp_line, DELIMITER);
        count++;

        // Allocate memory for new node
        stock_node *new_node = (stock_node*)malloc(sizeof(stock_node));
        new_node->data = (struct stock_data*)malloc(sizeof(struct stock_data));

        if (new_node == NULL || new_node->data == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }

        if (head == NULL) {
            head = new_node;
            current = new_node;
        } else {
            current->next_node = new_node;
            current = new_node;
        }

        int i = 1;
        while (token != NULL) {
            switch (i) {
                case 1:
                    strncpy(current->data->ticket_name, token, TICKET_NAME_LEN);
                    current->data->ticket_name[TICKET_NAME_LEN] = '\0'; // Ensure null termination
                    break;
                case 2:
                    current->data->ticket_type = token[0];
                    break;
                case 3:
                    strncpy(current->data->ticket_zone, token, TICKET_ZONE_LEN);
                    current->data->ticket_zone[TICKET_ZONE_LEN] = '\0'; // Ensure null termination
                    break;
                case 4:
                    current->data->ticket_price = atoi(token);
                    break;
                case 5:
                    current->data->stock_level = atoi(token);
                    break;
            }

            token = strtok(NULL, DELIMITER);
            i++;
        }
    }

    // Free allocated memory
    current = head;
    while (current != NULL) {
        stock_node *next = current->next_node;
        free(current->data);
        free(current);
        current = next;
    }

    fclose(stock_file);
    return 0;
}
