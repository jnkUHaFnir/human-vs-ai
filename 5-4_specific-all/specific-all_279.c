#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Update your service_data_func to parse the JSON data
void service_data_func(char text[]) {
    int service_index = 0;
    int charge_index = 0;

    // Start parsing the JSON data here
    char* token = strtok(text, ",:{}");
    while (token != NULL) {
        if (strcmp(token, "\"id\"")==0) {
            token = strtok(NULL, ",:{}");
            serv_data[service_index].id = atoi(token);
        }
        else if (strcmp(token, "\"from\"")==0) {
            token = strtok(NULL, ",:{}");
            serv_data[service_index].charge_arr[charge_index].from = atoi(token);
            charge_index++;
        }
        // Add more conditions to handle other fields as needed

        token = strtok(NULL, ",:{}");
    }
}

int main() {
    char text[] = "{\"success\": true,\"language\": \"en\",\"action\": \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\": [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,\"inquiry_required\": true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": true1},{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": true1},{\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": 5,\"percentage\": true2}]}}";

    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);
    
    return 0;
}
