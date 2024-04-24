#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SERVICES 8
#define MAX_CHARGE_ARR 10

struct service_charge {
    int from;
    int to;
    int charge;
    int slap;
    bool percentage;
};

struct service {
    int id;
    int provider_id;
    char name[30];
    int price_type;
    int min_value;
    int max_value;
    int sort_order;
    bool inquiry_required;
    struct service_charge charge_arr[MAX_CHARGE_ARR];
};

struct service serv_data[MAX_SERVICES];

void service_data_func(char text[]) {
  // Your JSON parsing logic can be implemented here securely
}

int main()
{
    // Initialize serv_data
    for (int i = 0; i < MAX_SERVICES; i++) {
        for (int j = 0; j < MAX_CHARGE_ARR; j++) {
            serv_data[i].charge_arr[j].percentage = false;
        }
    }

    char text[1000] = "{\"success\": true,\"language\": \"en\",\"action\": \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\": [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,\"inquiry_required\": true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": true},{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": true},{\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": 5,\"percentage\": true}]}}";

    service_data_func(text);

    // Print the values for demonstration
    printf("%d\n", serv_data[0].charge_arr[0].from);
    printf("%d\n", serv_data[0].charge_arr[1].from);
    printf("%d\n", serv_data[0].charge_arr[2].from);

    return 0;
}
