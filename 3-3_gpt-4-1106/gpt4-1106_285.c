#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h" // Make sure to have cJSON library included in your project

// Assuming your service and service_charge structs are defined here...

void service_data_func (const char* text) {
    cJSON *json = cJSON_Parse(text);
    if (json == NULL) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error before: %s\n", error_ptr);
        }
        return;
    }

    cJSON *data = cJSON_GetObjectItemCaseSensitive(json, "data");
    cJSON *service_list = cJSON_GetObjectItemCaseSensitive(data, "service_list");
    cJSON *service_json = NULL;

    int service_idx = 0;
    cJSON_ArrayForEach(service_json, service_list) {
        if (service_idx >= sizeof(serv_data) / sizeof(serv_data[0])) {
            break;
        }
        struct service *serv = &serv_data[service_idx];
        service_idx++;

        cJSON *id = cJSON_GetObjectItemCaseSensitive(service_json, "id");
        if (cJSON_IsNumber(id)) {
            serv->id = id->valueint;
        }

        // Parse other attributes here...

        cJSON *charge_list = cJSON_GetObjectItemCaseSensitive(service_json, "service_charge_list");
        cJSON *charge_json = NULL;
        int charge_idx = 0;
        cJSON_ArrayForEach(charge_json, charge_list) {
            if (charge_idx >= sizeof(serv->charge_arr) / sizeof(serv->charge_arr[0])) {
                break;
            }
            struct service_charge *charge = &serv->charge_arr[charge_idx];
            charge_idx++;

            cJSON *from = cJSON_GetObjectItemCaseSensitive(charge_json, "from");
            if (cJSON_IsNumber(from)) {
                charge->from = from->valueint;
            }

            // Parse other attributes here...
        }
    }

    cJSON_Delete(json);
}

int main() {
    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);
    // ... Further code ...
    return 0;
}
