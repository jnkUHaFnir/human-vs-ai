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
char text[1000]="{\"success\": true,\"language\": \"en\",\"action\":
                \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\":
                [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC
                AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\":
                10000,\"sort_order\": 2,\"inquiry_required\":
                true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\":
                1,\"slap\": 1,\"percentage\": true1},{\"from\": 2,\"to\":
                54875,\"charge\": 4,\"slap\": 5,\"percentage\": true1},,
                {\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\":
                5,\"percentage\": true2}]}";

void service_data_func (char text[]) {
    cJSON *root = cJSON_Parse(text);
    cJSON *data = cJSON_GetObjectItem(root, "data");
    cJSON *service_list = cJSON_GetObjectItem(data, "service_list");

    for (int i = 0; i < cJSON_GetArraySize(service_list); i++) {
        cJSON *item = cJSON_GetArrayItem(service_list, i);

        serv_data[i].id = cJSON_GetObjectItem(item, "id")->valueint;
        // Parse and fill in other struct members as needed
    }

    cJSON_Delete(root);
}

int main() {
    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
