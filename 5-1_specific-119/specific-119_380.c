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

void service_data_func (char text[]) {
    int i = 0;
    int menu_num = 0;
    int charge_menu_num = 0;
    
    while (text[i] != '\0') {
        if (text[i] == '{') {
            i++; // Skip opening brace '{'
            while (text[i] != '}') {
                i++; // Process fields until closing brace '}'
                // Implement parsing logic here
                // You may use a JSON parser library for a more robust solution
            }
            menu_num++; // Move to the next service
        }
        i++;
    }
}

int main() {
    char text[1000] = "{\"success\": true,\"language\": \"en\",\"action\": \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\": [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,\"inquiry_required\": true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": true},{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": true1},{\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": 5,\"percentage\": true2}]},\"service_list\": [{}]}";
  
    service_data_func(text);
  
    printf("%d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
