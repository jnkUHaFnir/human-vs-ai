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
char text[1000] = "{\"success\": true,\"language\": \"en\",\"action\":"
                "\"GetServiceList\",\"version\": 1,\"data\": {\"service_list\":"
                "[{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\","
                "\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,"
                "\"inquiry_required\": true,\"service_charge_list\": "
                "[{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": \"true1\"},"
                "{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": \"true1\"},"
                "{\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": 5,\"percentage\": \"true2\"}]}]}";

void service_data_func(char text[]) {
    int i = 0;
    int len = strlen(text);
    int service_index = 0;
    int charge_index = 0;

    while (i < len) {
        if (text[i] == '\"' && text[i + 1] == 'i' && text[i + 2] == 'd') {
            sscanf(text + i, "\"id\": %d", &serv_data[service_index].id);
        } else if (text[i] == '\"' && text[i + 1] == 'n' && text[i + 2] == 'a' && text[i + 3] == 'm' && text[i + 4] == 'e') {
            sscanf(text + i, "\"name\": \"%29[^\"]\"", serv_data[service_index].name);
        } else if (text[i] == '\"' && text[i + 1] == 's' && text[i + 2] == 'e' && text[i + 3] == 'r' &&
                   text[i + 4] == 'v' && text[i + 5] == 'i' && text[i + 6] == 'c' && text[i + 7] == 'e' &&
                   text[i + 8] == '_' && text[i + 9] == 'c' && text[i + 10] == 'h' && text[i + 11] == 'a' &&
                   text[i + 12] == 'r' && text[i + 13] == 'g' && text[i + 14] == 'e' && text[i + 15] == '_' &&
                   text[i + 16] == 'l' && text[i + 17] == 'i' && text[i + 18] == 's' && text[i + 19] == 't') {
            if (text[i + 24] == '{') {
                i = i + 25; // Skip "{" of service_charge_list
                while (text[i] != '}') {
                    if (text[i] == '{') {
                        i++;
                        sscanf(text + i, "\"from\": %d,\"to\": %d,\"charge\": %d,\"slap\": %d,\"percentage\": \"%4[^\"]\"",
                               &serv_data[service_index].charge_arr[charge_index].from,
                               &serv_data[service_index].charge_arr[charge_index].to,
                               &serv_data[service_index].charge_arr[charge_index].charge,
                               &serv_data[service_index].charge_arr[charge_index].slap,
                               serv_data[service_index].charge_arr[charge_index].percentage);
                        charge_index++;
                    }
                    i++;
                }
            }
        }

        i++;
    }

}

int main()
{
    service_data_func(text);

    // Print out the parsed data for verification
    printf("Service ID: %d\n", serv_data[0].id);
    printf("Service Name: %s\n", serv_data[0].name);
    printf("Charge from Service 0, Charge 0: %d\n", serv_data[0].charge_arr[0].charge);
    printf("Charge from Service 0, Charge 1: %d\n", serv_data[0].charge_arr[1].charge);

    return 0;
}
