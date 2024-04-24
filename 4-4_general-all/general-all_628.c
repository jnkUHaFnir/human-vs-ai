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
    struct service_charge charge_arr[10];
};

struct service serv_data[8];
char text[1000] = "{\"success\": true,\"language\": \"en\",\"action\": \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\": [{\"id\": 4806,\"service_charge_list\": [{\"from\": 1,\"to\": 547, \"charge\": 1,\"slap\": 1,\"percentage\": \"true1\"}, {\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": \"true1\"},{\"from\": 2,\"to\": 68945, \"charge\": 4, \"slap\": 5, \"percentage\": \"true2\"}]}}}";

void service_data_func(char text[]) {
    int i = 0;
    int len = strlen(text);
    int service_index = -1; // Index for current service
    int charge_index = 0;   // Index for current charge within a service

    while (i < len) {
        if (text[i] == '\"' && text[i + 1] == 'i' && text[i + 2] == 'd') {
            // Parse service id
            i += 5; // Move i to next character after ":"
            char id_str[10] = "";
            int id_index = 0;
            while (text[i] >= '0' && text[i] <= '9') {
                id_str[id_index++] = text[i++];
            }
            serv_data[++service_index].id = atoi(id_str);
        } else if (text[i] == 'f' && text[i + 1] == 'r' && text[i + 2] == 'o' && text[i + 3] == 'm') {
            // Parse charge from value
            i += 5; // Move i to next character after ":"
            char from_str[10] = "";
            int from_index = 0;
            while (text[i] >= '0' && text[i] <= '9') {
                from_str[from_index++] = text[i++];
            }
            serv_data[service_index].charge_arr[charge_index++].from = atoi(from_str);
        } else {
            ++i;
        }
    }
}

int main() {
    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
