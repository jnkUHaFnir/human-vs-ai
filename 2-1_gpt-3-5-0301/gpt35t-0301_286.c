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
char text[] = "{\"success\": true,\"language\": \"en\",\"action\":"
                "\"GetServiceList\",\"version\": 1,\"data\": {\"service_list\":"
                "[{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\","
                "\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,"
                "\"inquiry_required\": true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,"
                "\"charge\": 1,\"slap\": 1,\"percentage\": \"true1\"},{\"from\": 2,\"to\": 54875,"
                "\"charge\": 4,\"slap\": 5,\"percentage\": \"true1\"},{\"from\": 2,\"to\": 68945,"
                "\"charge\": 4,\"slap\": 5,\"percentage\": \"true2\"}]}," 
                "{\"id\": 4807,\"provider_id\": 582,\"name\": \"Bill Payment (SC)\","
                "\"price_type\": 1,\"min_value\": 70,\"max_value\": 50000,\"sort_order\": 4,"
                "\"inquiry_required\": false,\"service_charge_list\": [{\"from\": 1,\"to\": 547,"
                "\"charge\": 2,\"slap\": 0,\"percentage\": \"true1\"},{\"from\": 2,\"to\": 54875,"
                "\"charge\": 5,\"slap\": 5,\"percentage\": \"true1\"},{\"from\": 2,\"to\": 68945,"
                "\"charge\": 5,\"slap\": 10,\"percentage\": \"true2\"}]}]}";

void service_data_func(char text[]) {

    int i=0;
    int len;
    len=strlen(text);
    int service_index = 0;
    int charge_index = 0;

    while (1)//while ALL
    {
        if(i>=len) {
            break;
        }
        if(text[i] == '"' && text[i+1] == 'i'&&
                text[i+2] == 'd') {
            // Service ID
            char id_str[10];
            int id_str_index = 0;
            while (1) { //while "id"

                if(text[i] == ':') {
                    i++;
                } else if(text[i] == ',' || text[i] == '}' ) {

                    id_str[id_str_index] = '\0';
                    serv_data[service_index].id = atoi(id_str);
                    service_index++;
                    charge_index = 0;
                    i++;
                    break;
                } else {
                    id_str[id_str_index++] = text[i++];
                }

            }//while id
        } else if(text[i] == 's' && text[i+1] == 'e'&&
                  text[i+2] == 'r'&& text[i+3] == 'v'&& text[i+4] == 'i'&&
                  text[i+5] == 'c'&& text[i+6] == 'e'&& text[i+7] == '_'&& text[i+8]
                  == 'c'&& text[i+9] == 'h'&& text[i+10] == 'a'&& text[i+11] ==
                  'r'&& text[i+12] == 'g'&& text[i+13] == 'e'&& text[i+14] == '_'&&
                  text[i+15] == 'l'&& text[i+16] == 'i'&& text[i+17] == 's'&&
                  text[i+18] == 't') {
            // Service Charge List
            while (1)//while ALL
            {
                if(i>=len) {
                    break;
                }
                if(text[i] == 'f' && text[i+1] == 'r'&&
                        text[i+2] == 'o'&& text[i+3] == 'm') {
                    // Charge From
                    char from_str[10];
                    int from_str_index = 0;
                    while (1) { //while from

                        if(text[i] == ':') {
                            i++;
                        } else if(text[i] == ',' || text[i] == '}' ) {

                            from_str[from_str_index] = '\0';
                            serv_data[service_index-1].charge_arr[charge_index].from=atoi(from_str);
                            charge_index++;
                            i++;
                            break;
                        } else {
                            from_str[from_str_index++] = text[i++];
                        }

                    }
                } else {
                    i++;
                }

            }
        } else {
            i++;
        }

    }

}

int main()
{
    service_data_func(text);
    printf("%d\n",serv_data[0].charge_arr[0].from);
    printf("%d\n",serv_data[0].charge_arr[1].charge);
    printf("%d\n",serv_data[1].charge_arr[2].to);

    return 0;
}
