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

struct service serv_data[1]; // just for demonstration, change to [8] if needed

void service_data_func(char text[]) {
    cJSON *root = cJSON_Parse(text);

    if (root == NULL) {
        printf("Error parsing JSON\n");
        return;
    }

    cJSON *serviceList = cJSON_GetObjectItem(cJSON_GetObjectItem(cJSON_GetObjectItem(root, "data"), "service_list"), "0");

    serv_data[0].id = cJSON_GetObjectItem(serviceList, "id")->valueint;
    serv_data[0].provider_id = cJSON_GetObjectItem(serviceList, "provider_id")->valueint;
    strncpy(serv_data[0].name, cJSON_GetObjectItem(serviceList, "name")->valuestring, sizeof(serv_data[0].name) - 1);
    serv_data[0].name[sizeof(serv_data[0].name) - 1] = '\0'; // Null terminate

    cJSON *chargeList = cJSON_GetObjectItem(serviceList, "service_charge_list");

    int charge_count = cJSON_GetArraySize(chargeList);
    for (int i = 0; i < charge_count && i < 10; i++) {
        cJSON *chargeItem = cJSON_GetArrayItem(chargeList, i);
        serv_data[0].charge_arr[i].from = cJSON_GetObjectItem(chargeItem, "from")->valueint;
        serv_data[0].charge_arr[i].to = cJSON_GetObjectItem(chargeItem, "to")->valueint;
        serv_data[0].charge_arr[i].charge = cJSON_GetObjectItem(chargeItem, "charge")->valueint;
        serv_data[0].charge_arr[i].slap = cJSON_GetObjectItem(chargeItem, "slap")->valueint;
        strncpy(serv_data[0].charge_arr[i].percentage, cJSON_GetObjectItem(chargeItem, "percentage")->valuestring, sizeof(serv_data[0].charge_arr[i].percentage) - 1);
        serv_data[0].charge_arr[i].percentage[sizeof(serv_data[0].charge_arr[i].percentage) - 1] = '\0'; // Null terminate
    }

    cJSON_Delete(root);
}

int main() {
    char text[1000] = "Your JSON data";

    service_data_func(text);

    printf("ID: %d\n", serv_data[0].id);
    printf("From: %d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
