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

char text[1000] = "{\"success\": true,\"language\": \"en\",\"action\": \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\": [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,\"inquiry_required\": true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": true1},{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": true1},{\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": 5,\"percentage\": true2}]}}}";

void service_data_func(char text[]) {
    int i = 0;
    int serv_index = 0;
    int charge_index = 0;
    char numberStr[20] = "";

    while (text[i] != '\0') {
        if (text[i] == '\"' && strncmp(&text[i+1], "id", 2) == 0) {
            i += 4; // Skip "id":
            int j = 0;
            while (text[i] != ',' && text[i] != '}' && j < 19) {
                if (text[i] != '"') {
                    numberStr[j++] = text[i];
                }
                i++;
            }
            numberStr[j] = '\0';
            serv_data[serv_index].id = atoi(numberStr);
            serv_index++;
        }
        else if (text[i] == 'f' && strncmp(&text[i+1], "rom", 3) == 0) {
            i += 6; // Skip "from":
            int j = 0;
            while (text[i] != ',' && text[i] != '}' && j < 19) {
                if (text[i] != '"') {
                    numberStr[j++] = text[i];
                }
                i++;
            }
            numberStr[j] = '\0';
            serv_data[serv_index - 1].charge_arr[charge_index].from = atoi(numberStr);
            charge_index++;
        }
        else {
            i++;
        }
    }
}

int main() {
    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
