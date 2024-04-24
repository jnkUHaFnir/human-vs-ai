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

char text[1000] = "{\"success\": true,\"language\": \"en\",\"action\": \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\": [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,\"inquiry_required\": true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": true1},{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": true1},{\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": 5,\"percentage\": true2}]}}";

void service_data_func(char text[]) {
    int i = 0;
    int len = strlen(text);
    int current_service = 0;
    int current_charge = 0;

    while (i < len) {
        if (text[i] == 'i' && text[i + 1] == 'd') {
            i += 5; // Skip to the ID value
            serv_data[current_service].id = atoi(text + i);
            while (text[i] != '}') {
                i++;
            }
            current_service++;
        } else if (text[i] == 's' && text[i + 1] == 'e' && text[i + 2] == 'r' &&
                   text[i + 3] == 'v' && text[i + 4] == 'i' && text[i + 5] == 'c' &&
                   text[i + 6] == 'e' && text[i + 7] == '_' && text[i + 8] == 'c' &&
                   text[i + 9] == 'h' && text[i + 10] == 'a' && text[i + 11] == 'r' &&
                   text[i + 12] == 'g' && text[i + 13] == 'e' && text[i + 14] == '_' &&
                   text[i + 15] == 'l' && text[i + 16] == 'i' && text[i + 17] == 's' &&
                   text[i + 18] == 't') {
            i += 24; // Skip to the charge list
            while (text[i] != '}') {
                if (text[i] == 'f' && text[i + 1] == 'r' && text[i + 2] == 'o' && text[i + 3] == 'm') {
                    i += 7; // Skip to the 'from' value
                    serv_data[current_service - 1].charge_arr[current_charge].from = atoi(text + i);
                    while (text[i] != '}') {
                        i++;
                    }
                    current_charge++;
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
    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
