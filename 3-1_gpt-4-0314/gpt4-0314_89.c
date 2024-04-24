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
    struct stock_data data;
    struct stock_node *next_node;
} stock_node;

int main()
{
    char temp_line[MAX_LINE_SIZE];
    char *token;
    int i, count = 0;

    stock_node *snode = NULL;
    stock_node *prev_node = NULL;

    FILE *stock_file = fopen("stockfile.txt", "r");

    while (fgets(temp_line, MAX_LINE_SIZE, stock_file) != NULL)
    {

        token = strtok(temp_line, DELIMITER);
        count++;

        stock_node *new_node = (stock_node *)malloc(sizeof(stock_node));
        if (new_node == NULL)
        {
            abort();
        }

        i = 1;

        while (token != NULL)
        {
            switch (i)
            {
            case 1:
                strcpy(new_node->data.ticket_name, token);
                break;
            case 2:
                new_node->data.ticket_type = token[0];
                break;
            case 3:
                strcpy(new_node->data.ticket_zone, token);
                break;
            case 4:
                new_node->data.ticket_price = atoi(token);
                break;
            case 5:
                new_node->data.stock_level = atoi(token);
                break;
            }

            token = strtok(NULL, DELIMITER);
            i++;
        }

        if (prev_node)
        {
            prev_node->next_node = new_node;
        }
        else
        {
            snode = new_node;
        }
        prev_node = new_node;
    }

    fclose(stock_file);
    return 0;
}
