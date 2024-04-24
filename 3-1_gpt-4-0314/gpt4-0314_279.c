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
char text[1000] = "your-text-data-in-a-single-line";

void service_data_func(char text[]) {
    int i = 0;
    int Wstart = 0;
    int Wend = 0;
    char name[19] = {0x20};
    char name1[19] = {0x20};
    int menunum = 0;
    int len;
    int menunum_charge = 0;

    while (1) //while ALL
    {
        printf("Entering ALL loop, i: %d\n", i);
        if (i >= strlen(text)) {
            printf("ALL loop complete\n");
            break;
        }

        if (text[i] == '"' && text[i + 1] == 'i' && text[i + 2] == 'd') {
            printf("Entering \"id\" loop, i: %d\n", i);
            while (1) { //while "id
                if (text[i] == ':') {
                    Wstart = i + 1;
                    Wend = 0;
                    i++;
                } else if (text[i] == ',' || text[i] == '}') {
                    Wend = i;
                    strncpy(name, text + Wstart, Wend - Wstart);
                    serv_data[menunum].id = atoi(name);
                    memset(name, 0, sizeof(name));
                    printf("Exiting \"id\" loop, i: %d, ID: %d\n", i, menunum);
                    i++;
                    break;
                } else {
                    i = i + 1;
                }
            } //while id
        } else if (text[i] == 's' &&
                   strncmp(text + i, "service_charge_list", 19) == 0) {
            printf("Entering charge list loop, i: %d\n", i);
            while (1) //while ALL
            {
                printf("Entering from loop, i: %d\n", i);
                if (i >= strlen(text)) {
                    break;
                }

                if (text[i] == 'f' && text[i + 1] == 'r' &&
                    text[i + 2] == 'o' && text[i + 3] == 'm') {
                    printf("Entering from inner loop, i: %d\n", i);
                    while (1) { //while from
                        if (text[i] == ':') {
                            Wstart = i + 1;
                            Wend = 0;
                            i++;
                        } else if (text[i] == ',' || text[i] == '}') {
                            Wend = i;
                            strncpy(name, text + Wstart, Wend - Wstart);
                            serv_data[menunum].charge_arr[menunum_charge].from = atoi(name);
                            memset(name, 0, sizeof(name));
                            printf("Exiting from inner loop, i: %d, From: %d\n", i, serv_data[menunum].charge_arr[menunum_charge].from);
                            i++;
                            break;
                        } else {
                            i = i + 1;
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

int main() {
    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
