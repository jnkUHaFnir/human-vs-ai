#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SERVICE 8
#define MAX_CHARGE 10

struct service_charge {
    int from;
    // ... other fields omitted for brevity
};

struct service {
    int id;
    // ... other fields omitted for brevity
    struct service_charge charge_arr[MAX_CHARGE];
};

struct service serv_data[MAX_SERVICE];

char text[] = "{\"id\": 4806,\"service_charge_list\": [{\"from\": 1}] }"; // Simplified input for demonstration

void service_data_func(char text[]) {
    int i = 0;
    int menu_num = 0;
    int charge_num = 0;
    char buffer[256];
    int buf_index = 0;
    int len = strlen(text);

    while (i < len) {
        // Skipping whitespace
        if (text[i] <= ' ') {
            ++i;
            continue;
        }

        // Parsing "id"
        if (strncmp(&text[i], "\"id\":", 5) == 0) {
            i += 5; // Skip past the "id":
            while (i < len && text[i] <= ' ') ++i; // Skip whitespace

            buf_index = 0;
            while (i < len && text[i] >= '0' && text[i] <= '9') {
                buffer[buf_index++] = text[i++];
            }
            buffer[buf_index] = '\0'; // Null-terminate the buffer

            serv_data[menu_num].id = atoi(buffer); // Convert to int
        }
        // Look for the start of the "service_charge_list"
        else if (strncmp(&text[i], "\"service_charge_list\":", 22) == 0) {
            i += 22;
            charge_num = 0; // Reset charge counter
            while (i < len && text[i] != '[') ++i; // Find the opening bracket
            ++i; // Skip the '['

            // Parse each service_charge
            while (i < len && charge_num < MAX_CHARGE && text[i] != ']') {
                // Skip possible whitespace and opening braces
                while (i < len && (text[i] <= ' ' || text[i] == '{')) ++i;

                if (strncmp(&text[i], "\"from\":", 7) == 0) {
                    i += 7; // Skip past "from":
                    while (i < len && text[i] <= ' ') ++i; // Skip whitespace

                    buf_index = 0;
                    while (i < len && text[i] >= '0' && text[i] <= '9') {
                        buffer[buf_index++] = text[i++];
                    }
                    buffer[buf_index] = '\0'; // Null-terminate the buffer

                    serv_data[menu_num].charge_arr[charge_num].from = atoi(buffer); // Convert to int
                }

                // Skipping to the end of current service_charge object
                while (i < len && text[i] != '}') ++i;
                ++i; // Skip the '}' or ','
                ++charge_num; // Move to next service_charge
            }
        } else {
            ++i;
        }
    }
}

int main() {
    service_data_func(text);
    printf("ID: %d\n",serv_data[0].id);
    printf("First charge 'from': %d\n",serv_data[0].charge_arr[0].from);

    return 0;
}
