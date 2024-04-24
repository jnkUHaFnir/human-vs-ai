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

void service_data_func(char text[]) {
    cJSON *root = cJSON_Parse(text);
    if (root == NULL) {
        printf("Error parsing JSON\n");
        return;
    }

    cJSON *service_list = cJSON_GetObjectItem(root, "service_list");
    if (service_list == NULL) {
        printf("Error getting service_list\n");
        cJSON_Delete(root);
        return;
    }

    int num_services = cJSON_GetArraySize(service_list);
    for (int i = 0; i < num_services && i < 8; i++) {
        cJSON *service_item = cJSON_GetArrayItem(service_list, i);
        
        serv_data[i].id = cJSON_GetObjectItem(service_item, "id")->valueint;
        serv_data[i].provider_id = cJSON_GetObjectItem(service_item, "provider_id")->valueint;
        strncpy(serv_data[i].name, cJSON_GetObjectItem(service_item, "name")->valuestring, 30);
        // Fill in other fields as needed
        
        cJSON *charge_list = cJSON_GetObjectItem(service_item, "service_charge_list");
        int num_charges = cJSON_GetArraySize(charge_list);
        for (int j = 0; j < num_charges && j < 10; j++) {
            cJSON *charge_item = cJSON_GetArrayItem(charge_list, j);
            
            serv_data[i].charge_arr[j].from = cJSON_GetObjectItem(charge_item, "from")->valueint;
            // Fill in other charge fields as needed
        }
    }

    cJSON_Delete(root);
}

int main() {
    char text[1000] = "Your JSON data here";

    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
