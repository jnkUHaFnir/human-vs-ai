#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
    int i = 0;
    int menunum = 0;
    
    while (text[i] != '\0') {
        if (text[i] == '"') {
            i++;
            // Check for different fields using conditions
            if (strncmp(&text[i], "id", 2) == 0) {
                i += 5; // Skip past "id": 
                serv_data[menunum].id = atoi(&text[i]);
            } else if (strncmp(&text[i], "name", 4) == 0) {
                // Implement similar logic for other fields
            } else if (strncmp(&text[i], "service_charge_list", 19) == 0) {
                i += 23; // Skip past "service_charge_list":[
                int charge_index = 0;
                while (text[i] != ']') {
                    if (text[i] == '{') {
                        i++; // Skip {
                        if (text[i] == '}') {
                            break; // Empty charge object
                        }
                        i += 9; // Skip past {"from":
                        serv_data[menunum].charge_arr[charge_index].from = atoi(&text[i]);
                        // Implement parsing for other fields within charge object
                        while (text[i] != '}') {
                            i++;
                        }
                        charge_index++;
                    }
                    i++;
                }
            }
        }
        i++;
    }
}

int main() {
    char text[1000] = "{\"success\": true,\"language\": \"en\",\"action\":\"GetServiceList\",\"version\": 1,\"data\": {\"service_list\":[{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,\"inquiry_required\": true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": true},{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": true},{\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": 5,\"percentage\": true}]}}}";

    service_data_func(text);

    printf("%d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
