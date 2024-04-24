#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define DELIMITER ","
#define TICKET_NAME_LEN 40
#define TICKET_ZONE_LEN 10

struct stock_data
{
    char ticket_name[TICKET_NAME_LEN + 1];
    char ticket_type;
    char ticket_zone[TICKET_ZONE_LEN + 1];
    unsigned int ticket_price;
    unsigned int stock_level;
};

typedef struct stock_node
{
    struct stock_data* data;
    struct stock_node* next_node;
} stock_node;

int main()
{
    char temp_line[MAX_LINE_SIZE];
    char* token;
    int count = 0;

    stock_node* head = NULL;
    stock_node* current = NULL;

    FILE* stock_file = fopen("stockfile.txt", "r");

    while (fgets(temp_line, MAX_LINE_SIZE, stock_file) != NULL)
    {
        token = strtok(temp_line, DELIMITER);
        count++;

        stock_node* new_node = (stock_node*)malloc(sizeof(stock_node));
        new_node->data = (struct stock_data*)malloc(sizeof(struct stock_data));

        int i = 1;
        while (token != NULL)
        {
            switch (i)
            {
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

        new_node->next_node = NULL;

        if (head == NULL)
        {
            head = new_node;
            current = head;
        }
        else
        {
            current->next_node = new_node;
            current = new_node;
        }
    }

    // Free allocated memory
    current = head;
    while (current != NULL)
    {
        stock_node* tmp = current;
        current = current->next_node;
        free(tmp->data);
        free(tmp);
    }

    fclose(stock_file);

    return 0;
}
