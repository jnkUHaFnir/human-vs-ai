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

void service_data_func(char text[]) {
    // Simplified example assuming well-formatted JSON-like text
    char *ptr = strstr(text, "\"from\":");
    if (ptr) {
        int from_value = atoi(ptr + 7); // Move pointer past "\"from\":".
        serv_data[0].charge_arr[0].from = from_value;
    }
}

int main() {
    char text[] = "{\"id\": 4806,\"service_charge_list\": [{\"from\": 1,\"to\": 547}]}"; // Simplified version for demonstration
    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from); // Output the 'from' value.
    return 0;
}
