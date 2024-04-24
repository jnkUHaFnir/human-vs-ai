#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ... your struct definitions ...

void parse_service_charge(const char* text, struct service_charge* charge) {
    // Implement the logic to parse a service charge from text and fill in the 'charge' struct
}

void parse_service(const char* text, struct service* srv) {
    // Implement the logic to parse a service from text and fill in the 'srv' struct
    // including parsing service charges and adding them into 'srv->charge_arr'
}

void service_data_func(const char* text) {
    // This function would call the above parse functions to fill in the serv_data array
}

int main() {
    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);
    // ...
    return 0;
}
