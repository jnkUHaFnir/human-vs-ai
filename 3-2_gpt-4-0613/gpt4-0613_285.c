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
char text[1000] = "Your JSON Text Here";

void service_data_func (char text[]) {
    int i=0;
    int Wstart=0;
    int Wend=0;
    char name[19]={0x20};
    char name1[19]={0x20};
    int menunum=0;
    int len=strlen(text);
    int menunum_charge=0;

    while (1){
        if(i>=len)
            break;

        if(text[i] == '"' && text[i+1] == 'i'&& text[i+2] == 'd') {
            for (; text[i] != ':'; i++);
            Wstart = i+2; // Skip ':' and ' '
            for (i=Wstart; text[i] != ',' && text[i] != '}'; i++);
            Wend = i;
            strncpy(name,text+Wstart,Wend-Wstart);
            serv_data[menunum].id=atoi(name);
            memset(name, 0, sizeof(name));

        }

        if(text[i] == '"' && text[i+1] == 'f'&& text[i+2] == 'r'&& text[i+3] == 'o'&& text[i+4] == 'm') {
            for (; text[i] != ':'; i++);
            Wstart = i+2; // Skip ':' and ' '
            for (i=Wstart; text[i] != ',' && text[i] != '}'; i++);
            Wend = i;
            strncpy(name,text+Wstart,Wend-Wstart);
            serv_data[menunum].charge_arr[menunum_charge].from=atoi(name);
            memset(name, 0, sizeof(name));
        }
        i++; // Skip current character
    }

}

int main() {
    service_data_func(text);
    printf("%d\n",serv_data[0].charge_arr[0].from);
    return 0;
}
#include <jansson.h>
#include <stdio.h>

int main() {
    const char *data = "{ \"key\": \"value\" }";
    json_error_t error;
    json_t *root = json_loads(data, 0, &error);

    if (!root) {
        printf("JSON error on line %d: %s\n", error.line, error.text);
        return 1;
    }

    json_t *key = json_object_get(root, "key");
    if (json_is_string(key))
        printf("%s\n", json_string_value(key));

    json_decref(root);
    return 0;
}
