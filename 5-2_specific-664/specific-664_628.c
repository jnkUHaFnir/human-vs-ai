#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

#define MAX_SERVICES 8
#define MAX_SERVICE_CHARGES 10

struct service_charge {
    int from;
    int to;
    int charge;
    int slap;
    char percentage[5];
};

struct service {
    int id;
    // Add other fields as needed
    struct service_charge charge_arr[MAX_SERVICE_CHARGES];
};

struct service serv_data[MAX_SERVICES];

void service_data_func(char text[]) {
    cJSON *root = cJSON_Parse(text);
    if (root == NULL) {
        printf("Error parsing JSON.\n");
        return;
    }

    cJSON *service_list = cJSON_GetObjectItem(root, "service_list");
    if (service_list == NULL || cJSON_IsArray(service_list) == 0) {
        printf("Error accessing service_list.\n");
        cJSON_Delete(root);
        return;
    }

    int service_count = cJSON_GetArraySize(service_list);
    if (service_count > MAX_SERVICES) {
        printf("Exceeded maximum number of services.\n");
        cJSON_Delete(root);
        return;
    }

    for (int i = 0; i < service_count; i++) {
        cJSON *service_item = cJSON_GetArrayItem(service_list, i);
        if (service_item != NULL && cJSON_IsObject(service_item)) {
            serv_data[i].id = cJSON_GetObjectItem(service_item, "id")->valueint;

            // Parse service_charge_list
            cJSON *charge_list = cJSON_GetObjectItem(service_item, "service_charge_list");
            if (charge_list != NULL && cJSON_IsArray(charge_list)) {
                int charge_count = cJSON_GetArraySize(charge_list);
                for (int j = 0; j < charge_count && j < MAX_SERVICE_CHARGES; j++) {
                    cJSON *charge_item = cJSON_GetArrayItem(charge_list, j);
                    if (charge_item != NULL && cJSON_IsObject(charge_item)) {
                        serv_data[i].charge_arr[j].from = cJSON_GetObjectItem(charge_item, "from")->valueint;
                        // Add parsing for other charge details here
                    }
                }
            }
            // Add parsing for other service details here
        }
    }

    cJSON_Delete(root);
}

int main() {
    char text[1000] = "{\"success\": true,\"language\": \"en\",\"action\": \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\": [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,\"inquiry_required\": true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": true1},{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": true1},{\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": 5,\"percentage\": true2}]}}}";

    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
