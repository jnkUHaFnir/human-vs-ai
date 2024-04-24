#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SERVICES 8
#define MAX_SERVICE_CHARGES 10

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
    struct service_charge charge_arr[MAX_SERVICE_CHARGES];
};

struct service serv_data[MAX_SERVICES];

void service_data_func(char text[]) {
    int i = 0;
    int len = strlen(text);
    int service_index = 0;
    int charge_index = 0;
    char buffer[100]; // Temporary buffer for parsing numbers

    while (i < len) {
        if (text[i] == '\"' && text[i + 1] == 'i' && text[i + 2] == 'd') {
            i += 4; // Skipping to the value
            int j = 0;
            while (text[i] >= '0' && text[i] <= '9') {
                buffer[j] = text[i];
                i++;
                j++;
            }
            buffer[j] = '\0';
            serv_data[service_index].id = atoi(buffer);
            service_index++;
        } else if (text[i] == 's' && strncmp(&text[i], "service_charge_list", 19) == 0) {
            i += 20; // Skipping to the charges
            charge_index = 0;
            while (text[i] != ']') {
                if (text[i] == '{') {
                    i++;
                    // Parsing charge details
                    while (i < len && text[i] != '}') {
                        if (text[i] == '\"' && text[i + 1] == 'f' && text[i + 2] == 'r' && text[i + 3] == 'o' && text[i + 4] == 'm') {
                            i += 6; // Skipping to the value
                            int j = 0;
                            while (text[i] >= '0' && text[i] <= '9') {
                                buffer[j] = text[i];
                                i++;
                                j++;
                            }
                            buffer[j] = '\0';
                            serv_data[service_index - 1].charge_arr[charge_index].from = atoi(buffer);
                        } else if (text[i] == 't' && text[i + 1] == 'o') {
                            i += 4; // Skipping to the value
                            int j = 0;
                            while (text[i] >= '0' && text[i] <= '9') {
                                buffer[j] = text[i];
                                i++;
                                j++;
                            }
                            buffer[j] = '\0';
                            serv_data[service_index - 1].charge_arr[charge_index].to = atoi(buffer);
                        } // Add similar checks for other fields like 'charge', 'slap', 'percentage' if needed
                        i++;
                    }
                    charge_index++;
                }
                i++;
            }
        } else {
            i++;
        }
    }
}

int main() {
    char text[1000] = "{\"success\": true,\"language\": \"en\",\"action\": \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\": [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,\"inquiry_required\": true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": true},{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": true2}]}}";
  
    service_data_func(text);

    // Printing one of the parsed values as an example
    printf("%d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
