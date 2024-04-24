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

char text[1000] = "{\"success\": true,\"language\": \"en\",\"action\": \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\": [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,\"inquiry_required\": true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": true},{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": true1},{\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": 5,\"percentage\": true2}]}}}";

void service_data_func(char text[]) {
    int i = 0;
    int len = strlen(text);
    int service_index = 0;
    int charge_index = 0;

    while (i < len) {
        if (text[i] == '\"' && text[i + 1] == 'i' && text[i + 2] == 'd') {
            i += 5; // Move beyond "id":
            serv_data[service_index].id = atoi(&text[i]);
        } else if (text[i] == 'n' && text[i + 1] == 'a' && text[i + 2] == 'm' && text[i + 3] == 'e') {
            i += 7; // Move beyond "name":
            int name_end = i;
            while (text[name_end] != '\"') {
                name_end++;
            }
            strncpy(serv_data[service_index].name, &text[i], name_end - i);
        } else if (text[i] == 'i' && text[i + 1] == 'n' && text[i + 2] == 'q' && text[i + 3] == 'u' && text[i + 4] == 'i' && text[i + 5] == 'r' && text[i + 6] == 'y') {
            i += 18; // Move beyond "inquiry_required":
            serv_data[service_index].inquiry_required = text[i] == 't' ? true : false;
        } else if (text[i] == 's' && text[i + 1] == 'e' && text[i + 2] == 'r' && text[i + 3] == 'v' && text[i + 4] == 'i' && text[i + 5] == 'c' && text[i + 6] == 'e' && text[i + 7] == '_' && text[i + 8] == 'c' && text[i + 9] == 'h' && text[i + 10] == 'a' && text[i + 11] == 'r' && text[i + 12] == 'g' && text[i + 13] == 'e' && text[i + 14] == '_' && text[i + 15] == 'l' && text[i + 16] == 'i' && text[i + 17] == 's' && text[i + 18] == 't') {
            while (!(text[i] == ']' && text[i + 1] == '}')) {
                if (text[i] == '{') {
                    i++;
                    if (text[i] == 'f' && text[i + 1] == 'r' && text[i + 2] == 'o' && text[i + 3] == 'm') {
                        i += 6; // Move beyond "from":
                        serv_data[service_index].charge_arr[charge_index].from = atoi(&text[i]);
                    } else if (text[i] == 't' && text[i + 1] == 'o') {
                        i += 4; // Move beyond "to":
                        serv_data[service_index].charge_arr[charge_index].to = atoi(&text[i]);
                    } else if (text[i] == 'c' && text[i + 1] == 'h' && text[i + 2] == 'a' && text[i + 3] == 'r' && text[i + 4] == 'g' && text[i + 5] == 'e') {
                        i += 8; // Move beyond "charge":
                        serv_data[service_index].charge_arr[charge_index].charge = atoi(&text[i]);
                    } else if (text[i] == 's' && text[i + 1] == 'l' && text[i + 2] == 'a' && text[i + 3] == 'p') {
                        i += 6; // Move beyond "slap":
                        serv_data[service_index].charge_arr[charge_index].slap = atoi(&text[i]);
                    } else if (text[i] == 'p' && text[i + 1] == 'e' && text[i + 2] == 'r' && text[i + 3] == 'c' && text[i + 4] == 'e' && text[i + 5] == 'n' && text[i + 6] == 't' && text[i + 7] == 'a' && text[i + 8] == 'g' && text[i + 9] == 'e') {
                        i += 11; // Move beyond "percentage":
                        serv_data[service_index].charge_arr[charge_index].percentage = text[i] == 't' ? true : false;
                        charge_index++;
                    }
                }
                i++;
            }
            charge_index = 0; // Reset charge index for the next service charge
            service_index++;
        }
        i++;
    }
}

int main()
{
    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
