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
    struct stock_data *data;
    struct stock_node *next_node;
} stock_node;

char temp_line[MAX_LINE_SIZE];
char *token;
int i, count = 0;

stock_node *snode = NULL;
struct stock_data *sdata = NULL;

FILE *stock_file = fopen(stockfile, "r");

while (fgets(temp_line, MAX_LINE_SIZE, stock_file) != NULL)
{

    token = strtok(temp_line, DELIMITER);
    count++;

    snode = (stock_node *)realloc(snode, count * sizeof(stock_node));
    if (snode == NULL)
    {
        abort();
    }

    snode[count - 1].data = (struct stock_data *)malloc(sizeof(struct stock_data));
    if (snode[count - 1].data == NULL)
    {
        abort();
    }

    i = 1;

    while (token != NULL)
    {
        switch (i)
        {
        case 1:
            strncpy(snode[count - 1].data->ticket_name, token, TICKET_NAME_LEN);
            snode[count - 1].data->ticket_name[TICKET_NAME_LEN] = '\0'; // Ensure null termination
            break;
        case 2:
            snode[count - 1].data->ticket_type = token[0];
            break;
        case 3:
            strncpy(snode[count - 1].data->ticket_zone, token, TICKET_ZONE_LEN);
            snode[count - 1].data->ticket_zone[TICKET_ZONE_LEN] = '\0'; // Ensure null termination
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
