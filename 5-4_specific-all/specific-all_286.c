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
    int i = 0;
    int len = strlen(text);
    int current_service = -1;
    int current_charge = 0;

    while (i < len) {
        if (text[i] == '"' && strncmp(text + i + 1, "id\":", 4) == 0) {
            i += 5; // Move past "id":
            char id_str[10];
            int id_index = 0;

            while (text[i] != ',') {
                if (text[i] != ' ') {
                    id_str[id_index++] = text[i];
                }
                i++;
            }
            id_str[id_index] = '\0';
            serv_data[++current_service].id = atoi(id_str);
        } else if (strncmp(text + i, "service_charge_list\":", 21) == 0) {
            i += 21; // Move past "service_charge_list":
            i++; // Move past [
            while (i < len && text[i] != ']') {
                if (text[i] == '{') {
                    i++;
                    char key[20];
                    char value[20];
                    
                    while (text[i] != '}') {
                        i++;
                        if (text[i] == '"') {
                            i++;
                            int key_index = 0;
                            while (text[i] != '"') {
                                key[key_index++] = text[i++];
                            }
                            key[key_index] = '\0';
                            
                            i += 3; // Skip over ": "

                            int value_index = 0;
                            while (text[i] != ',' && text[i] != '}') {
                                value[value_index++] = text[i++];
                            }
                            value[value_index] = '\0';

                            if (strcmp(key, "from") == 0) {
                                serv_data[current_service].charge_arr[current_charge].from = atoi(value);
                            } else if (strcmp(key, "to") == 0) {
                                serv_data[current_service].charge_arr[current_charge].to = atoi(value);
                            } else if (strcmp(key, "charge") == 0) {
                                serv_data[current_service].charge_arr[current_charge].charge = atoi(value);
                            } else if (strcmp(key, "slap") == 0) {
                                serv_data[current_service].charge_arr[current_charge].slap = atoi(value);
                            } else if (strcmp(key, "percentage") == 0) {
                                strcpy(serv_data[current_service].charge_arr[current_charge].percentage, value);
                            }
                            i++; // Move past , or }
                        }
                    }
                    current_charge++;
                } else {
                    i++;
                }
            }
            break; // Exit the loop after processing the charge list
        } else {
            i++;
        }
    }
}

int main() {
    char text[1000] = "{\"success\": true,\"language\": \"en\",\"action\": \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\": [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,\"inquiry_required\": true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": true1},{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": true1},{\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": 5,\"percentage\": true2}]}}";

    service_data_func(text);

    // Print a value stored in the parsed data
    printf("%d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
