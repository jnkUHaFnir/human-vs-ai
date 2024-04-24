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
char text[1000]="{\"success\": true,\"language\": \"en\",\"action\": \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\": [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,\"inquiry_required\": true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": true1},{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": true1},{\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": 5,\"percentage\": true2}]}}";

void service_data_func(char text[]) {
    int i = 0;
    int len = strlen(text);
    int menunum = 0;    

    while (i < len) {
        if (text[i] == '"' && text[i+1] == 'i' && text[i+2] == 'd') {
            int Wstart = 0;
            int Wend = 0;
            char name[19] = {0};
            
            while (text[i] != ':' && i < len) {
                i++;
            }
            i++; // Move past ':'
            Wstart = i;

            while (text[i] != ',' && text[i] != '}' && i < len) {
                i++;
            }
            Wend = i;
            strncpy(name, text + Wstart, Wend - Wstart);
            serv_data[menunum].id = atoi(name);
            memset(name, 0, sizeof(name));
        } else if (strncmp(text + i, "service_charge_list", 19) == 0) {
            menunum = 0; // Reset to 0 for each new service_charge_list
            while (i < len) {
                if (strncmp(text + i, "from", 4) == 0) {
                    int Wstart = 0;
                    int Wend = 0;
                    char name[19] = {0};
                    
                    while (text[i] != ':' && i < len) {
                        i++;
                    }
                    i++; // Move past ':'
                    Wstart = i;
                    
                    while (text[i] != ',' && text[i] != '}' && i < len) {
                        i++;
                    }
                    Wend = i;
                    strncpy(name, text + Wstart, Wend - Wstart);
                    serv_data[menunum].charge_arr[menunum].from = atoi(name);
                    memset(name, 0, sizeof(name));
                }
                i++;
            }
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
