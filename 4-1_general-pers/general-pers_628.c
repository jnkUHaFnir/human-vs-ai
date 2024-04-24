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
    int len = strlen(text);

    while (i < len) {
        if (text[i] == '\"' && strncmp(text + i + 1, "id", 2) == 0) {
            i += 4; // Skip to the number part
            serv_data[menunum].id = atoi(text + i);
            while (text[i] != ',' && text[i] != '}') {
                i++; // Move to the end of the number
            }
        } else if (strncmp(text + i, "service_charge_list", 19) == 0) {
            i += 19;
            while (i < len && text[i] != ']') {
                if (text[i] == '{') {
                    i++; // Move to the start of the object
                    while (text[i] != '}') {
                        if (strncmp(text + i, "\"from\"", 5) == 0) {
                            i += 7; // Skip to the number part
                            serv_data[menunum].charge_arr[0].from = atoi(text + i);
                            while (text[i] != ',' && text[i] != '}') {
                                i++; // Move to the end of the number
                            }
                        }
                        // Similar handling for other fields like "to", "charge", "slap", "percentage"
                        i++;
                    }
                } else {
                    i++;
                }
            }
        } else {
            i++;
        }
    }
}

int main() {
    char text[1000] = "{\"success\": true,\"language\": \"en\",\"action\": \"GetServiceList\",\"version\": 1,"
                      "\"data\": {\"service_list\": [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\","
                      "\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,\"inquiry_required\": true,"
                      "\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": true},"
                      "{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": true},"
                      "{\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": 5,\"percentage\": false}]}";

    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
