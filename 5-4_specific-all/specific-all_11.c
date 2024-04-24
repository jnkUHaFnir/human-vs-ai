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
char text[1000]="{\"success\": true,\"language\": \"en\",\"action\":"
                "\"GetServiceList\",\"version\": 1,\"data\": {\"service_list\":"
                "[{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\","
                "\"price_type\": 0,\"min_value\": 30,\"max_value\":"
                "10000,\"sort_order\": 2,\"inquiry_required\":true,\"service_charge_list\":"
                "[{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": true},"
                "{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": true},"
                "{\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": 5,\"percentage\": true}]}}";

void service_data_func(char text[]) {
    int i = 0, menunum = 0, menunum_charge = 0;
    int len = strlen(text);

    while (i < len) {
        if (text[i] == '"' && text[i + 1] == 'i' && text[i + 2] == 'd') {
            i += 5; // Jump to the ID value directly
            serv_data[menunum].id = atoi(text + i);
            while (i < len && text[i] != '}')
                i++;
        } else if (text[i] == 's' && strncmp(text + i, "service_charge_list", 19) == 0) {
            i += 19; // Jump to the service_charge_list
            while (i < len && text[i] != '[')
                i++;

            while (i < len && text[i] == '[') {
                i++; // Move past '['

                // Parse from value
                while (i < len && text[i] != '"')
                    i++;
                i++;
                serv_data[menunum].charge_arr[menunum_charge].from = atoi(text + i);

                // Parse to value
                while (i < len && text[i] != '"')
                    i++;
                i++;
                serv_data[menunum].charge_arr[menunum_charge].to = atoi(text + i);

                // Move to next entry
                menunum_charge++;
                while (i < len && (text[i] != ']' || text[i] != '}'))
                    i++;
            }
            menunum++; // Move to the next service
        } else {
            i++;
        }
    }
}

int main()
{
    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
