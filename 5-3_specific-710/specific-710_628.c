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
char text[1000] = "{\"success\": true,\"language\": \"en\",\"action\": "
                  "\"GetServiceList\",\"version\": 1,\"data\": {\"service_list\": ["
                  "{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\","
                  "\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,"
                  "\"inquiry_required\": true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,"
                  "\"charge\": 1,\"slap\": 1,\"percentage\": true1},{\"from\": 2,\"to\": 54875,"
                  "\"charge\": 4,\"slap\": 5,\"percentage\": true1},{\"from\": 2,\"to\": 68945,"
                  "\"charge\": 4,\"slap\": 5,\"percentage\": true2}]}}}";

void service_data_func(char text[]) {
    int i = 0;
    int len = strlen(text);
    int service_index = -1;
    int charge_index = 0;

    while (i < len) {
        if (text[i] == '{') {
            i++;
        } else if (text[i] == '\"' && text[i+1] == 'i' && text[i+2] == 'd') {
            char id_str[10];
            int j = 0;
            i += 6; // Skip to value
            while (text[i] != ',') {
                id_str[j++] = text[i++];
            }
            id_str[j] = '\0';
            serv_data[++service_index].id = atoi(id_str);
            i += 2; // Skip to next field
        } else if (text[i] == '\"' && text[i+1] == 'f' && text[i+2] == 'r' && text[i+3] == 'o' && text[i+4] == 'm') {
            char from_str[10];
            int j = 0;
            i += 7; // Skip to value
            while (text[i] != ',') {
                from_str[j++] = text[i++];
            }
            from_str[j] = '\0';
            serv_data[service_index].charge_arr[charge_index].from = atoi(from_str);
            i += 2; // Skip to next field
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
