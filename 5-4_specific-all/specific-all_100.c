#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct service_charge {
    int from;
    int to;
    int charge;
    int slap;
    char percentage[6]; // Increased to 6 to accommodate "true1" and "true2"
};

struct service {
    int id;
    int provider_id;
    char name[30];
    int price_type;
    int min_value;
    int max_value;
    int sort_order;
    char inquiry_required[6]; // Increased to 6 to accommodate "true"
    struct service_charge charge_arr[10];
};

struct service serv_data[8];
char text[1000] = "{\"success\": true,\"language\": \"en\",\"action\": \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\": [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,\"inquiry_required\": true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": true1},{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": true1},{\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": 5,\"percentage\": true2}]}}}";   

void service_data_func(char text[]) {
    int i = 0;    
    while (text[i] != '[') {
        i++;
    }
    i++; // Move to the first service object in the JSON array
    int serv_num = 0;
    while (text[i] != ']' && serv_num < 8) {
        if (text[i] == '{') {
            i++; // Move past the '{'
            while (text[i] != '}' && text[i] != ']') {
                if (strncmp(&text[i], "\"id\":", 5) == 0) {
                    i += 5; // Move past "\"id\":"
                    serv_data[serv_num].id = atoi(&text[i]);
                } else if (strncmp(&text[i], "\"name\":", 7) == 0) {
                    i += 7; // Move past "\"name\":"
                    sscanf(&text[i], "\"%29[^\"]\"", serv_data[serv_num].name);
                } else if (strncmp(&text[i], "\"service_charge_list\":", 22) == 0) {
                    i += 22; // Move past "\"service_charge_list\":"
                    i++; // Move past '['
                    int charge_num = 0;
                    while (text[i] != ']' && charge_num < 10) {
                        i++; // Move past '{'
                        while (text[i] != '}' && text[i] != ']') {
                            if (strncmp(&text[i], "\"from\":", 7) == 0) {
                                i += 7; // Move past "\"from\":"
                                serv_data[serv_num].charge_arr[charge_num].from = atoi(&text[i]);
                            } else if (strncmp(&text[i], "\"to\":", 5) == 0) {
                                i += 5; // Move past "\"to\":"
                                serv_data[serv_num].charge_arr[charge_num].to = atoi(&text[i]);
                            } else if (strncmp(&text[i], "\"charge\":", 9) == 0) {
                                i += 9; // Move past "\"charge\":"
                                serv_data[serv_num].charge_arr[charge_num].charge = atoi(&text[i]);
                            } else if (strncmp(&text[i], "\"slap\":", 7) == 0) {
                                i += 7; // Move past "\"slap\":"
                                serv_data[serv_num].charge_arr[charge_num].slap = atoi(&text[i]);
                            } else if (strncmp(&text[i], "\"percentage\":", 13) == 0) {
                                i += 13; // Move past "\"percentage\":"
                                sscanf(&text[i], "\"%5[^\"]\"", serv_data[serv_num].charge_arr[charge_num].percentage);
                            }
                            while (text[i] != ',' && text[i] != '}') {
                                i++;
                            }
                            i++; // Move past the ',' or '}'
                        }
                        charge_num++;
                        i++; // Move past the ','
                    }
                }
                while (text[i] != ',' && text[i] != '}') {
                    i++;
                }
                i++; // Move past the ',' or '}'
            }
            serv_num++;
        }
        i++; // Move to the next service object
    }
}

int main() {
    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);
    return 0;
}
