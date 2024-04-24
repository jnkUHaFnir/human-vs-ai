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
char text[1000] = "{\"success\": true,\"language\": \"en\",\"action\": \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\": [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,\"inquiry_required\": true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": true},{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": true},{\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": 5,\"percentage\": false}]}";

void service_data_func(char text[]) {
    int i = 0;
    int service_idx = 0;
    int charge_idx = 0;

    while (text[i] != '\0') {
        if (text[i] == '\"' && text[i + 1] == 'i' && text[i + 2] == 'd') {
            i += 6;
            char id_str[10] = "";
            int j = 0;
            while (text[i] != ',') {
                id_str[j++] = text[i++];
            }
            serv_data[service_idx].id = atoi(id_str);
            service_idx++;
        } else if (text[i] == '{' && text[i + 1] == '\"' && text[i + 2] == 'f' && text[i + 3] == 'r' && text[i + 4] == 'o' && text[i + 5] == 'm') {
            i += 8;
            char from_str[10] = "";
            int j = 0;
            while (text[i] != ',') {
                from_str[j++] = text[i++];
            }
            serv_data[service_idx - 1].charge_arr[charge_idx].from = atoi(from_str);
            charge_idx++;
        } else if (text[i] == 't' && text[i + 1] == 'r' && text[i + 2] == 'u' && text[i + 3] == 'e') {
            serv_data[service_idx - 1].charge_arr[charge_idx - 1].percentage = true;
        } else if (text[i] == 'f' && text[i + 1] == 'a' && text[i + 2] == 'l' && text[i + 3] == 's' && text[i + 4] == 'e') {
            serv_data[service_idx - 1].charge_arr[charge_idx - 1].percentage = false;
        }
        i++;
    }
}

int main() {
    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
