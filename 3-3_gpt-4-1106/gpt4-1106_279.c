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

// Example text snippet, truncated for brevity and simplicity
char text[] = 
    "{\"id\": 4806,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": 1,"
    "\"slap\": 1,\"percentage\": \"true\"},{\"from\": 2,\"to\": 54875,"
    "\"charge\": 4,\"slap\": 5,\"percentage\": \"true\"}]}";

void parse_service_data(char *text) {
    // This function assumes the text is in the correct format and is a simplified parser.
    char *key, *value;
    char service_id_str[10];
    key = strtok(text, ":,{}");

    while (key != NULL) {
        if (strcmp(key, "\"id\"") == 0) {
            value = strtok(NULL, ":,{}");
            strcpy(service_id_str, value);
            serv_data[0].id = atoi(service_id_str);
        } else if (strcmp(key, "\"service_charge_list\"") == 0) {
            int charge_count = 0;
            do {
                key = strtok(NULL, ":,{}");
                if (strcmp(key, "\"from\"") == 0) {
                    value = strtok(NULL, ":,{}");
                    serv_data[0].charge_arr[charge_count].from = atoi(value);
                } else if (strcmp(key, "\"to\"") == 0) {
                    value = strtok(NULL, ":,{}");
                    serv_data[0].charge_arr[charge_count].to = atoi(value);
                } else if (strcmp(key, "\"charge\"") == 0) {
                    value = strtok(NULL, ":,{}");
                    serv_data[0].charge_arr[charge_count].charge = atoi(value);
                } else if (strcmp(key, "\"slap\"") == 0) {
                    value = strtok(NULL, ":,{}");
                    serv_data[0].charge_arr[charge_count].slap = atoi(value);
                } else if (strcmp(key, "\"percentage\"") == 0) {
                    value = strtok(NULL, ":,{}\"");
                    strncpy(serv_data[0].charge_arr[charge_count].percentage, value, sizeof(serv_data[0].charge_arr[charge_count].percentage) - 1);
                    charge_count++; // Move to next charge
                }
            } while (strcmp(key, "]") != 0 && charge_count < 10);
        }

        key = strtok(NULL, ":,{}");
    }
}

int main() {
    parse_service_data(text);
    printf("Service ID: %d\n", serv_data[0].id);
    printf("First Charge From: %d\n", serv_data[0].charge_arr[0].from);
    printf("First Charge Percentage: %s\n", serv_data[0].charge_arr[0].percentage);

    return 0;
}
