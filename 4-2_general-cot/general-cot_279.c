#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // Added for bool datatype

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
    struct service_charge charge_arr[10];
};

struct service serv_data[8];

void service_data_func(char text[]) {
    char *token = strtok(text, "\"{}:,");
    int menuCounter = 0;
    int chargeCounter = 0;

    while (token != NULL) {
        if (strcmp(token, "id") == 0) {
            token = strtok(NULL, "\"{},:");
            serv_data[menuCounter].id = atoi(token);
        } else if (strcmp(token, "name") == 0) {
            token = strtok(NULL, "\"{},:");
            strcpy(serv_data[menuCounter].name, token);
        } else if (strcmp(token, "service_charge_list") == 0) {
            while (1) {
                token = strtok(NULL, "\"{},:");
                if (token == NULL || strcmp(token, "}") == 0) {
                    break;
                }
                if (strcmp(token, "from") == 0) {
                    token = strtok(NULL, "\"{},:");
                    serv_data[menuCounter].charge_arr[chargeCounter].from = atoi(token);
                } else if (strcmp(token, "to") == 0) {
                    token = strtok(NULL, "\"{},:");
                    serv_data[menuCounter].charge_arr[chargeCounter].to = atoi(token);
                } else if (strcmp(token, "charge") == 0) {
                    token = strtok(NULL, "\"{},:");
                    serv_data[menuCounter].charge_arr[chargeCounter].charge = atoi(token);
                } else if (strcmp(token, "slap") == 0) {
                    token = strtok(NULL, "\"{},:");
                    serv_data[menuCounter].charge_arr[chargeCounter].slap = atoi(token);
                } else if (strcmp(token, "percentage") == 0) {
                    token = strtok(NULL, "\"{},:");
                    serv_data[menuCounter].charge_arr[chargeCounter].percentage = strcmp(token, "true") == 0;
                    chargeCounter++;
                }
            }
        }
        token = strtok(NULL, "\"{},:");
    }
}

int main() {
    char text[1000] = "{\"success\": true,\"language\": \"en\",\"action\": \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\": [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,\"inquiry_required\": true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": true},{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": true},{\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": 5,\"percentage\": true}]}}}";
  
    service_data_func(text);
  
    printf("Charge from first service: %d\n", serv_data[0].charge_arr[0].from);
  
    return 0;
}
