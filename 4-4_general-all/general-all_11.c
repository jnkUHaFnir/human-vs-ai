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
    int menunum = -1;
    int menunum_charge = 0;
    char name[19];

    while (i < len) {
        if (text[i] == '{') {
            menunum++;
            menunum_charge = 0;
        }

        if (text[i] == ':') {
            int start = i + 1;
            while (text[i] != ',' && text[i] != '}') {
                i++;
            }
            int end = i;
            strncpy(name, text + start, end - start);
            
            if (strncmp(text + i - 3, "id", 2) == 0) {
                serv_data[menunum].id = atoi(name);
            }
            else if (strncmp(text + i - 5, "from", 4) == 0) {
                serv_data[menunum].charge_arr[menunum_charge].from = atoi(name);
            }

            memset(name, 0, sizeof(name));
        }

        i++;
    }
}

int main() {
    service_data_func(text);

    printf("From charge_arr[0]: %d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
