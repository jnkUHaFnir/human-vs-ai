#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct service_charge {
    int from;
    int to;
    int charge;
    int slap;
    char percentage[6]; // Increased size to accomodate "true1" and "true2"
};

struct service {
    int id;
    int provider_id;
    char name[30];
    int price_type;
    int min_value;
    int max_value;
    int sort_order;
    char inquiry_required[6]; // Increased size to accomodate "true"
    struct service_charge charge_arr[10];
};

struct service serv_data[8];

void service_data_func(char text[]) {
    int i = 0;
    int len = strlen(text);
    int menunum = 0;
    int menunum_charge = 0;

    while (i < len) {
        if (text[i] == '"') {
            if (strncmp(&text[i], "\"id\":", 5) == 0) {
                i += 5;
                serv_data[menunum].id = atoi(&text[i]);
                menunum_charge = 0;
            } else if (strncmp(&text[i], "\"from\":", 7) == 0) {
                i += 7;
                serv_data[menunum].charge_arr[menunum_charge].from = atoi(&text[i]);
            } else if (strncmp(&text[i], "\"to\":", 5) == 0) {
                i += 5;
                serv_data[menunum].charge_arr[menunum_charge].to = atoi(&text[i]);
            } else if (strncmp(&text[i], "\"charge\":", 9) == 0) {
                i += 9;
                serv_data[menunum].charge_arr[menunum_charge].charge = atoi(&text[i]);
            } else if (strncmp(&text[i], "\"slap\":", 7) == 0) {
                i += 7;
                serv_data[menunum].charge_arr[menunum_charge].slap = atoi(&text[i]);
            } else if (strncmp(&text[i], "\"percentage\":\"", 14) == 0) {
                i += 14;
                // Copy up to the next "
                int copyLen = strcspn(&text[i], "\"");
                strncpy(serv_data[menunum].charge_arr[menunum_charge].percentage, &text[i], copyLen);
                serv_data[menunum].charge_arr[menunum_charge].percentage[copyLen] = '\0';
                menunum_charge++;
            }
        }
        i++;
    }
}

int main() {
    char text[1000] = "{\"success\": true,\"language\": \"en\",\"action\": \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\": [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,\"inquiry_required\": true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": \"true1\"},{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": \"true1\"},{\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": 5,\"percentage\": \"true2\"}]}}";

    service_data_func(text);

    printf("%d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
