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

void service_data_func(char text[], int index) {
    int i = 0;
    int len = strlen(text);

    // Parsing the text data
    while (i < len) {
        if (text[i] == '"' && text[i + 1] == 'i' && text[i + 2] == 'd') {
            // Parse and store fields like id
            // Update serv_data[index] accordingly
        }
        else if (text[i] == 's' && text[i + 1] == 'e' && text[i + 2] == 'r' && text[i + 3] == 'v' && text[i + 4] == 'i' && text[i + 5] == 'c' && text[i + 6] == 'e' && text[i + 7] == '_' && text[i + 8] == 'c' && text[i + 9] == 'h' && text[i + 10] == 'a' && text[i + 11] == 'r' && text[i + 12] == 'g' && text[i + 13] == '_' && text[i + 14] == 'l' && text[i + 15] == 'i' && text[i + 16] == 's' && text[i + 17] == 't') {
            // Parse service charge list
            // Update serv_data[index].charge_arr and increase index accordingly
        }

        i++;
    }
}

int main() {
    char text[1000] = "{\"success\":true,\"language\":\"en\",\"action\":\"GetServiceList\",\"version\":1,\"data\":{\"service_list\":[{\"id\":4806,\"provider_id\":581,\"name\":\"Bill Payment (MG SC AC)\",\"price_type\":0,\"min_value\":30,\"max_value\":10000,\"sort_order\":2,\"inquiry_required\":true,\"service_charge_list\":[{\"from\":1,\"to\":547,\"charge\":1,\"slap\":1,\"percentage\":\"true1\"},{\"from\":2,\"to\":54875,\"charge\":4,\"slap\":5,\"percentage\":\"true1\"},{\"from\":2,\"to\":68945,\"charge\":4,\"slap\":5,\"percentage\":\"true2\"}]}}}";

    // Assuming you want to extract details for the first service in the list
    service_data_func(text, 0);

    printf("%d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
