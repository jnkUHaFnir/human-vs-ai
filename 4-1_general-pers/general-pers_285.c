#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SERVICES 8
#define MAX_SERVICE_CHARGES 10

struct service_charge {
    int from;
    int to;
    int charge;
    int slap;
    char percentage[6]; // Changed to 6 to include terminating null character
};

struct service {
    int id;
    int provider_id;
    char name[31]; // Changed to 31 to include terminating null character
    int price_type;
    int min_value;
    int max_value;
    int sort_order;
    char inquiry_required[6]; // Changed to 6 to include terminating null character
    struct service_charge charge_arr[MAX_SERVICE_CHARGES];
};

struct service serv_data[MAX_SERVICES];
char text[1000] = "Your JSON data here";

void service_data_func(const char text[]) {
    // Your data parsing logic here
    // Make sure to validate JSON input, handle escape characters, etc.
    // For simplicity, I'm omitting the JSON parsing logic as it's complex

    // Mock values for demonstration
    serv_data[0].charge_arr[0].from = 1;
}

int main() {
    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
