#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

struct service_charge {
    int from;
    int to;
    int charge;
    int slap;
    char percentage[6]; // Increased the size to accommodate "true1" and "true2"
};

struct service {
    int id;
    int provider_id;
    char name[30];
    int price_type;
    int min_value;
    int max_value;
    int sort_order;
    char inquiry_required[6]; // Increased the size to accommodate "true"
    struct service_charge charge_arr[10];
};

struct service serv_data[8];

void service_data_func(char text[]) {
    cJSON *root = cJSON_Parse(text);
    if (root == NULL) {
        printf("Error parsing JSON\n");
    } else {
        cJSON *serviceList = cJSON_GetObjectItem(cJSON_GetObjectItem(root, "data"), "service_list");
        int serviceListSize = cJSON_GetArraySize(serviceList);
        if (serviceListSize > 8) {
            serviceListSize = 8; // Ensure we don't overflow the serv_data array
        }

        for (int i = 0; i < serviceListSize; i++) {
            cJSON *serviceItem = cJSON_GetArrayItem(serviceList, i);

            serv_data[i].id = cJSON_GetObjectItem(serviceItem, "id")->valueint;
            serv_data[i].provider_id = cJSON_GetObjectItem(serviceItem, "provider_id")->valueint;
            strcpy(serv_data[i].name, cJSON_GetObjectItem(serviceItem, "name")->valuestring);
            serv_data[i].price_type = cJSON_GetObjectItem(serviceItem, "price_type")->valueint;
            serv_data[i].min_value = cJSON_GetObjectItem(serviceItem, "min_value")->valueint;
            serv_data[i].max_value = cJSON_GetObjectItem(serviceItem, "max_value")->valueint;
            serv_data[i].sort_order = cJSON_GetObjectItem(serviceItem, "sort_order")->valueint;
            strcpy(serv_data[i].inquiry_required, cJSON_GetObjectItem(serviceItem, "inquiry_required")->valuestring);

            cJSON *chargeList = cJSON_GetObjectItem(serviceItem, "service_charge_list");
            int chargeListSize = cJSON_GetArraySize(chargeList);
            if (chargeListSize > 10) {
                chargeListSize = 10; // Ensure we don't overflow the charge_arr array
            }

            for (int j = 0; j < chargeListSize; j++) {
                cJSON *chargeItem = cJSON_GetArrayItem(chargeList, j);

                serv_data[i].charge_arr[j].from = cJSON_GetObjectItem(chargeItem, "from")->valueint;
                serv_data[i].charge_arr[j].to = cJSON_GetObjectItem(chargeItem, "to")->valueint;
                serv_data[i].charge_arr[j].charge = cJSON_GetObjectItem(chargeItem, "charge")->valueint;
                serv_data[i].charge_arr[j].slap = cJSON_GetObjectItem(chargeItem, "slap")->valueint;
                strcpy(serv_data[i].charge_arr[j].percentage, cJSON_GetObjectItem(chargeItem, "percentage")->valuestring);
            }
        }

        cJSON_Delete(root);
    }
}

int main() {
    char text[1000] = "{\"success\": true,\"language\": \"en\",\"action\":
                        \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\":
                        [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC
                        AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\":
                        10000,\"sort_order\": 2,\"inquiry_required\":
                        true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\":
                        1,\"slap\": 1,\"percentage\": \"true1\"},{\"from\": 2,\"to\":
                        54875,\"charge\": 4,\"slap\": 5,\"percentage\": \"true1\"},
                        {\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\":
                        5,\"percentage\": \"true2\"}]}";

    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
