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
char text[1000]="Your JSON data here";

void service_data_func(char text[]) {
    cJSON *root = cJSON_Parse(text);
    if (root == NULL) {
        printf("Error parsing JSON\n");
        return;
    }

    cJSON *service_list = cJSON_GetObjectItemCaseSensitive(root, "service_list");
    if (!cJSON_IsArray(service_list)) {
        printf("Error: service_list is not an array\n");
        cJSON_Delete(root);
        return;
    }

    int num_services = cJSON_GetArraySize(service_list);
    for (int i = 0; i < num_services; i++) {
        cJSON *service_item = cJSON_GetArrayItem(service_list, i);
        serv_data[i].id = cJSON_GetObjectItemCaseSensitive(service_item, "id")->valueint;
        // Parse other fields and the charge_arr array here
    }

    cJSON_Delete(root);
}

int main() {
    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);
    return 0;
}
