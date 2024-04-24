#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct service_charge {
    int from;
};

struct service {
    int id;
    struct service_charge charge_arr[10];
};

struct service serv_data[8];
char text[1000] = "{\"id\": 4806,\"service_charge_list\": [{\"from\": 1},{\"from\": 2}]}";

void service_data_func(char text[]) {
    int i = 0;
    int len = strlen(text);
    int menunum = 0;
    int menunum_charge = 0;

    while (i < len) {
        if (text[i] == '"' && text[i + 1] == 'i' && text[i + 2] == 'd') {
            i += 5; // Skip to the actual id value
            serv_data[menunum].id = 0; // Initialize id

            // Parse id value until next non-digit character
            while (text[i] >= '0' && text[i] <= '9') {
                serv_data[menunum].id = serv_data[menunum].id * 10 + (text[i] - '0');
                i++;
            }

            menunum++; // Move to the next service
        } else if (strncmp(&text[i], "service_charge_list", 19) == 0) {
            i += 21; // Skip to the start of the array
            while (text[i] != '[') {
                i++;
            }
            i++; // Skip the '['

            // Parse charge_arr values
            while (text[i] != ']') {
                if (text[i] == '{' && menunum_charge < 10) {
                    while (text[i++] != ':'); // Skip to 'from'
                    i++; // Skip the ' '
                    serv_data[menunum - 1].charge_arr[menunum_charge].from = 0; // Initialize from

                    // Parse from value until next non-digit character
                    while (text[i] >= '0' && text[i] <= '9') {
                        serv_data[menunum - 1].charge_arr[menunum_charge].from = serv_data[menunum - 1].charge_arr[menunum_charge].from * 10 + (text[i] - '0');
                        i++;
                    }

                    menunum_charge++;
                    i++; // Skip the '}' or ','
                } else {
                    i++;
                }
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
