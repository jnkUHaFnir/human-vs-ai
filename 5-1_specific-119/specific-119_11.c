#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

struct service_charge {
    int from;
    int to;
    int charge;
    int slap;
    char percentage[5];
};
struct service {
    int id;
    int provider_id;
    char name[30];
    int price_type;
    int min_value;
    int max_value;
    int sort_order;
    char inquiry_required[5];
    struct service_charge charge_arr[10];
};
struct service serv_data[8];

void service_data_func (char text[]) {
    cJSON *root = cJSON_Parse(text);
    if (root == NULL) {
        printf("Error parsing JSON\n");
        return;
    }

    cJSON *service_list = cJSON_GetObjectItem(root, "data")->child;
    int service_index = 0;

    while (service_list != NULL) {
        serv_data[service_index].id = cJSON_GetObjectItem(service_list, "id")->valueint;
        // Parse other fields similarly

        cJSON *charge_list = cJSON_GetObjectItem(service_list, "service_charge_list")->child;
        int charge_index = 0;
        while (charge_list != NULL) {
            serv_data[service_index].charge_arr[charge_index].from = cJSON_GetObjectItem(charge_list, "from")->valueint;
            // Parse other charge fields similarly

            charge_list = charge_list->next;
            charge_index++;
        }

        service_list = service_list->next;
        service_index++;
    }

    cJSON_Delete(root);
}

int main()
{
    char text[1000] = "Your JSON data here";

    service_data_func(text);

    printf("%d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
