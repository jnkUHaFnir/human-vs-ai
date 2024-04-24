#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct service_charge {
    int from;
};

struct service {
    struct service_charge charge_arr[10];
};

struct service serv_data[8];

char text[1000] = "{\"success\": true,\"language\": \"en\",\"action\":"
                   "\"GetServiceList\",\"version\": 1,\"data\": {\"service_list\":"
                   "[{\"id\": 4806,\"service_charge_list\": [{\"from\": 1},{\"from\": 2},{\"from\": 2}]}";

void service_data_func(char text[]) {
    int i = 0;
    int menunum = 0;
    int menunum_charge = 0;
    int len = strlen(text);

    while (i < len) {
        if (text[i] == '{' && i + 1 < len && text[i + 1] == '\"' && i + 2 < len) {
            i = i + 2;
            if (strncmp(text + i, "id\":", 4) == 0) {
                char num_str[10];
                int num_index = 0;
                i = i + 4;
                while (i < len && text[i] != ',' && text[i] != '}') {
                    num_str[num_index] = text[i];
                    num_index++;
                    i++;
                }
                num_str[num_index] = '\0';
                serv_data[menunum].id = atoi(num_str);
            } else if (strncmp(text + i, "from\":", 6) == 0) {
                char num_str[10];
                int num_index = 0;
                i = i + 6;
                while (i < len && text[i] != ',' && text[i] != '}') {
                    num_str[num_index] = text[i];
                    num_index++;
                    i++;
                }
                num_str[num_index] = '\0';
                serv_data[menunum].charge_arr[menunum_charge].from = atoi(num_str);
                menunum_charge++;
            } else {
                i++;
            }
        } else {
            i++;
        }
    }
}

int main() {
    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
