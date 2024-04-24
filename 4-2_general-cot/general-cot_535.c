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

    stock_node *snode = NULL;
    FILE *stock_file = fopen("stockfile.txt", "r"); // Update your stock file name

    while (fgets(temp_line, MAX_LINE_SIZE, stock_file) != NULL) {
        token = strtok(temp_line, DELIMITER);

        snode = (stock_node *)realloc(snode, (count + 1) * sizeof(stock_node));
        if (snode == NULL) { 
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }

        snode[count].data = (struct stock_data *)malloc(sizeof(struct stock_data));
        if (snode[count].data == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }

        int i = 1;
        while (token != NULL) {
            switch (i) {
                case 1:
                    strncpy(snode[count].data->ticket_name, token, TICKET_NAME_LEN);
                    break;
                case 2:
                    snode[count].data->ticket_type = token[0];
                    break;
                case 3:
                    strncpy(snode[count].data->ticket_zone, token, TICKET_ZONE_LEN);
                    break;
                case 4:
                    snode[count].data->ticket_price = atoi(token);
                    break;
                case 5:
                    snode[count].data->stock_level = atoi(token);
                    break;
            }

            token = strtok(NULL, DELIMITER);
            i++;
        }
        count++;
    }

    // Free dynamically allocated memory
    for (int i = 0; i < count; i++) {
        free(snode[i].data);
    }
    free(snode);
    
    fclose(stock_file);

    return 0;
}
