#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // Include for boolean type

struct service_charge {
    int from;
    int to;
    int charge;
    int slap;
    bool percentage; // Change from char array to boolean
};

struct service {
    int id;
    int provider_id;
    char name[50]; // Increased size for name
    int price_type;
    int min_value;
    int max_value;
    int sort_order;
    bool inquiry_required; // Change from char array to boolean
    struct service_charge charge_arr[10];
};

struct service serv_data[8];

void service_data_func(char text[]) {

    int i = 0;
    int len = strlen(text);
    int serv_index = -1; // Initialize to -1 to indicate no service being parsed
    int charge_index = 0;

    while (i < len) {
        if (text[i] == '\"') {
            i++; // Move past the opening quote
            if (strncmp(&text[i], "id", 2) == 0) {
                i += 3; // Move past "id": to the value
                serv_index++;
                char id[10] = "";
                int j = 0;
                while (text[i] != '\"') {
                    id[j++] = text[i++];
                }
                serv_data[serv_index].id = atoi(id);
            }
            // Add parsing for other fields like provider_id, name, price_type, min_value, etc. following a similar pattern
            // Example parsing for provider_id:
            // else if (strncmp(&text[i], "provider_id", 10) == 0) {
            //    i += 13;
            //    // Parse and assign to serv_data[serv_index].provider_id
            // }
            else if (strncmp(&text[i], "service_charge_list", 19) == 0) { 
                i += 21;
                while (charge_index < 10 && i < len) {
                    if (text[i] == '{') {
                        i++; // Move past the opening brace
                        while (i < len && text[i] != '}') {
                            if (strncmp(&text[i], "from", 4) == 0) {
                                i += 6; // Move past "from" to the value
                                char from[10] = "";
                                int j = 0;
                                while (text[i] != ',') {
                                    from[j++] = text[i++];
                                }
                                serv_data[serv_index].charge_arr[charge_index].from = atoi(from);
                            }
                            // Add similar parsing logic for other fields in service_charge struct
                            // Example parsing for 'to':
                            // else if (strncmp(&text[i], "to", 2) == 0) {
                            //    i += 4;
                            //    // Parse and assign to serv_data[serv_index].charge_arr[charge_index].to
                            // }
                            else {
                                i++;
                            }
                        }
                        charge_index++;
                    }
                    else {
                        i++;
                    }
                }
            }
            else {
                i++;
            }
        }
        else {
            i++;
        }
    }
}

int main()
{
    char text[1000] = "{\"success\": true,\"language\": \"en\",\"action\":"
                      "\"GetServiceList\",\"version\": 1,\"data\": {\"service_list\":"
                      "[{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SCAC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,\"inquiry_required\": true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": true},{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": true},{\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": 5,\"percentage\": true}]}}";

    service_data_func(text);
    
    // Access and print values
    printf("%d\n", serv_data[0].charge_arr[0].from);
    
    return 0;
}
