#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct service_charge {
    int from;
    int to;
    int charge;
    int slap;
    char percentage[6]; // Increased to accommodate "true1" and "true2"
};

struct service {
    int id;
    int provider_id;
    char name[31]; // Increased to accommodate the longest name in the JSON
    int price_type;
    int min_value;
    int max_value;
    int sort_order;
    bool inquiry_required;
    struct service_charge charge_arr[10];
};

struct service serv_data[8];

void service_data_func (char text[]) {
    int i = 0;
    int serv_num = 0;
    int charge_num = 0;
    char name[256]; // Increased buffer size for name
    int len = strlen(text);

    while (i < len) {
        if (text[i] == '"') {
            i++; // Skip the opening quote
            if (strncmp(&text[i], "id", 2) == 0) {
                i += 3; // Skip "id" and the following characters
                serv_data[serv_num].id = strtol(&text[i], NULL, 10);
            } else if (strncmp(&text[i], "name", 4) == 0) {
                i += 6; // Skip "name" and the following characters
                int name_len = strcspn(&text[i], "\""); // Find the string length until the closing quote
                strncpy(serv_data[serv_num].name, &text[i], name_len);
                serv_data[serv_num].name[name_len] = '\0';
            } else if (strncmp(&text[i], "inquiry_required", 16) == 0) {
                i += 19; // Skip "inquiry_required" and the following characters
                if (text[i] == 't') {
                    serv_data[serv_num].inquiry_required = true;
                } else {
                    serv_data[serv_num].inquiry_required = false;
                }
                i += 6; // To skip "true" or "false"
            } else if (strncmp(&text[i], "from", 4) == 0) {
                i += 5; // Skip "from"
                serv_data[serv_num].charge_arr[charge_num].from = strtol(&text[i], NULL, 10);
            }
        }
        i++; // Move to the next character
    }
}

int main() {
    char text[1000] = "{\"success\": true,\"language\": \"en\",\"action\": \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\": [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\":10000,\"sort_order\": 2,\"inquiry_required\": true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": true1},{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": true1},{\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": 5,\"percentage\": true2}]}]}}";
    
    service_data_func(text);
    
    printf("Service ID: %d\n", serv_data[0].id);
    printf("Service Name: %s\n", serv_data[0].name);
    printf("Inquiry Required: %s\n", serv_data[0].inquiry_required ? "true" : "false");
    printf("Charge from: %d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
