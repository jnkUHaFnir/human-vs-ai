#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct service_charge {
    int from;
    int to;
    int charge;
    int slap;
    char percentage[5]; // It would be better to use int or bool for true/false values.
};
struct service {
    int id;
    int provider_id;
    char name[30];
    int price_type;
    int min_value;
    int max_value;
    int sort_order;
    char inquiry_required[5]; // It would be better to use int or bool for true/false values.
    struct service_charge charge_arr[10];
};
struct service serv_data[8];

void service_data_func(char *text) {
    int i = 0, len = strlen(text);
    int menunum = 0, menunum_charge = 0;
    char buffer[50] = {0}; // Increase buffer size to accommodate larger strings.
    
    // Assuming only one service for simplification. The logic can be expanded for multiple services.
    while (i < len) {
        // Skipping non-relevant parts
        i++;

        // Example parsing for "from" in charge list
        // This is an overly simplified parsing example. You need to expand it for other fields.
        if (strncmp(&text[i], "\"from\":", 7) == 0) {
            i += 7; // Move past "from":
            int j = 0;
            while (text[i] != ',' && text[i] != '}' && i < len) {
                buffer[j++] = text[i++];
            }
            buffer[j] = '\0'; // Null-terminate the string
            serv_data[menunum].charge_arr[menunum_charge].from = atoi(buffer);
            memset(buffer, 0, sizeof(buffer)); // Clear buffer for next use
            menunum_charge++; // Move to the next charge entry
            if (menunum_charge >= 10) break; // Prevent overflow of charge_arr
        }
    }
}

int main() {
    char text[] = "{\"success\": true,\"language\": \"en\",\"action\": \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\": [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,\"inquiry_required\": true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": \"true1\"},{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": \"true1\"},{\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": 5,\"percentage\": \"true2\"}]}]}";
    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);
    return 0;
}
