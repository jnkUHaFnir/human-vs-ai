#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>

struct service_charge {
    int from;
    int to;
    int charge;
    int slap;
    char percentage[6];  // Increased size by 1 to prevent buffer overflow
};

struct service {
    int id;
    int provider_id;
    char name[30];
    int price_type;
    int min_value;
    int max_value;
    int sort_order;
    char inquiry_required[6];  // Increased size by 1 to prevent buffer overflow
    struct service_charge charge_arr[10];
};

struct service serv_data[8];

void service_data_func(const char* text) {
    json_error_t error;
    json_t *root = json_loads(text, 0, &error);

    if (!root) {
        fprintf(stderr, "Error parsing JSON: %s\n", error.text);
        return;
    }

    // Parse JSON data
    json_t *service_list = json_object_get(root, "data");
    service_list = json_object_get(service_list, "service_list");

    int service_count = json_array_size(service_list);

    for (int i = 0; i < service_count && i < 8; i++) {
        json_t *service_item = json_array_get(service_list, i);

        serv_data[i].id = json_integer_value(json_object_get(service_item, "id"));
        serv_data[i].provider_id = json_integer_value(json_object_get(service_item, "provider_id"));
        strncpy(serv_data[i].name, json_string_value(json_object_get(service_item, "name")), 29);
        serv_data[i].price_type = json_integer_value(json_object_get(service_item, "price_type"));
        serv_data[i].min_value = json_integer_value(json_object_get(service_item, "min_value"));
        serv_data[i].max_value = json_integer_value(json_object_get(service_item, "max_value"));
        serv_data[i].sort_order = json_integer_value(json_object_get(service_item, "sort_order"));
        strncpy(serv_data[i].inquiry_required, json_string_value(json_object_get(service_item, "inquiry_required")), 5);

        json_t *charge_list = json_object_get(service_item, "service_charge_list");
        int charge_count = json_array_size(charge_list);

        for (int j = 0; j < charge_count && j < 10; j++) {
            json_t *charge_item = json_array_get(charge_list, j);

            serv_data[i].charge_arr[j].from = json_integer_value(json_object_get(charge_item, "from"));
            serv_data[i].charge_arr[j].to = json_integer_value(json_object_get(charge_item, "to"));
            serv_data[i].charge_arr[j].charge = json_integer_value(json_object_get(charge_item, "charge"));
            serv_data[i].charge_arr[j].slap = json_integer_value(json_object_get(charge_item, "slap"));
            strncpy(serv_data[i].charge_arr[j].percentage, json_string_value(json_object_get(charge_item, "percentage")), 5);
        }
    }

    json_decref(root);
}

int main() {
    const char text[1000] = "{\"success\": true,\"language\": \"en\",\"action\": \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\": [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,\"inquiry_required\": true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": \"true1\"},{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": \"true1\"},{\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": 5,\"percentage\": \"true2\"}]}}}";

    service_data_func(text);

    printf("ID: %d\n", serv_data[0].id);
    printf("From Charge 1: %d\n", serv_data[0].charge_arr[0].from);
    printf("From Charge 2: %d\n", serv_data[0].charge_arr[1].from);
    printf("From Charge 3: %d\n", serv_data[0].charge_arr[2].from);

    return 0;
}
