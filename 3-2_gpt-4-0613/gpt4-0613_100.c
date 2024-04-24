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

char text[1000]="your JSON here";

void service_data_func (char text[]) {

    int i=0;
    int Wstart=0;
    int Wend=0;
    char name[256] = "";
    int len;
    len=strlen(text);
    int menunum=0;

    while (i < len)
    {
        if(text[i] == '"' && strncmp(&text[i+1], "id", 2) == 0) {
            i += 4; // skip over ":" in the JSON
            sscanf(&text[i], "%d", &serv_data[menunum].id);
            // skip over the rest of this line in the JSON
            while (text[i] != ',' && text[i] != '}')
                i++;
        } 
        else if (text[i] == 's' && strncmp(&text[i+1], "ervice_charge_list", 18) == 0) {
            i += 21; // skip over "[{" in the JSON
            sscanf(&text[i], "%d", &serv_data[menunum].charge_arr[0].from);
            // skip over the rest of this line in the JSON
            while (text[i] != ',' && text[i] != '}')
                i++;
        } 
        else {
            i++;
        }
    }
}

int main()
{
    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);

    return 0;
}
