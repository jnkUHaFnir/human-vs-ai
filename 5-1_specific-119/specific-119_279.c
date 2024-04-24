#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SERVICES 8
#define MAX_CHARGES 10

struct service_charge {
    int from;
    int to;
    int charge;
    int slap;
    int percentage;
};

struct service {
    int id;
    int provider_id;
    char name[30];
    int price_type;
    int min_value;
    int max_value;
    int sort_order;
    int inquiry_required;
    struct service_charge charge_arr[MAX_CHARGES];
};

struct service serv_data[MAX_SERVICES];
char text[1000] = "{\"success\": true,\"language\": \"en\",\"action\": \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\": [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,\"inquiry_required\": true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": 1},{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": 1},{\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": 5,\"percentage\": 2}]}}";

void service_data_func(char text[]) {
    int menunum = 0;
    int menunum_charge = 0;

    // Find the start of "service_list"
    char* service_list_start = strstr(text, "\"service_list\": [");
    if (service_list_start == NULL) {
        printf("Unable to find service_list in text\n");
        return;
    }

    char* current_position = service_list_start;

    while (menunum < MAX_SERVICES && sscanf(current_position, "{\"id\": %d", &serv_data[menunum].id) == 1) {
        sscanf(current_position, "\"name\": \"%29[^\"]", serv_data[menunum].name);
        sscanf(current_position, "\"inquiry_required\": %d", &serv_data[menunum].inquiry_required);

        // Find the start of "service_charge_list"
        char* charge_list_start = strstr(current_position, "\"service_charge_list\": [");
        if (charge_list_start != NULL) {
            current_position = charge_list_start;
            while (menunum_charge < MAX_CHARGES && sscanf(current_position, "{\"from\": %d", &serv_data[menunum].charge_arr[menunum_charge].from) == 1) {
                sscanf(current_position, "\"to\": %d", &serv_data[menunum].charge_arr[menunum_charge].to);
                sscanf(current_position, "\"charge\": %d", &serv_data[menunum].charge_arr[menunum_charge].charge);
                sscanf(current_position, "\"slap\": %d", &serv_data[menunum].charge_arr[menunum_charge].slap);
                sscanf(current_position, "\"percentage\": %d", &serv_data[menunum].charge_arr[menunum_charge].percentage);

                menunum_charge++;

                current_position = strstr(current_position, "},");
                if (current_position == NULL) break;  // No more charges
                current_position += 2;  // Move past the current charge
            }
        }

        menunum++;
        menunum_charge = 0;

        current_position = strstr(current_position, "},");
        if (current_position == NULL) break;  // No more services
        current_position += 2;  // Move past the current service
    }
}

int main() {
    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
