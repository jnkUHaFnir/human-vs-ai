#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h" // Include the cJSON library

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
char text[1000]="{\"success\": true,\"language\": \"en\",\"action\": \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\": [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,\"inquiry_required\": true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": true1},{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": true1},{\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": 5,\"percentage\": true2}]}}";

void service_data_func(char text[]) {
    cJSON *root = cJSON_Parse(text); // Parse the JSON text

    if (root == NULL) {
        printf("Error parsing JSON\n");
        return;
    }

    cJSON *service_list = cJSON_GetObjectItem(cJSON_GetObjectItem(root, "data"), "service_list");

    if (service_list == NULL) {
        printf("Cannot find service_list\n");
        cJSON_Delete(root);
        return;
    }

    // Assuming there is at least one service in the service_list
    cJSON *service = service_list->child;
    cJSON *charge_list = cJSON_GetObjectItem(service, "service_charge_list");

    if (charge_list == NULL) {
        printf("Cannot find service_charge_list\n");
        cJSON_Delete(root);
        return;
    }

    cJSON *charge = NULL;
    int serv_index = 0;
    int charge_index = 0;

    cJSON_ArrayForEach(charge, charge_list) {
        serv_data[serv_index].charge_arr[charge_index].from = cJSON_GetObjectItem(charge, "from")->valueint;
        charge_index++;
    }

    cJSON_Delete(root);
}

int main() {
    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
