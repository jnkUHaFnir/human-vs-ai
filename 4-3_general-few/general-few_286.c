void service_data_func (char text[]) {

    int i=0;
    int Wstart=0;
    int Wend=0;
    char name[19]= {0x20};
    int len;
    len = strlen(text);
    int menunum = 0;
    memset(serv_data, 0, sizeof(serv_data)); // Initialize serv_data array

    while (1) {
        if(i >= len) {
            break;
        }

        if(text[i] == '"' && text[i+1] == 'i' && text[i+2] == 'd') {
            while (1) {
                if(text[i] == ':') {
                    Wstart = i + 1;
                    i++;
                } else if(text[i] == ',' || text[i] == '}') {
                    Wend = i;
                    strncpy(name, text + Wstart, Wend - Wstart);
                    serv_data[menunum].id = atoi(name);
                    menunum++;
                    memset(name, 0, sizeof(name));
                    break;
                } else {
                    i++;
                }
            }
        } else if(text[i] == 'f' && text[i+1] == 'r' && text[i+2] == 'o' && text[i+3] == 'm') {
            while (1) {
                if(text[i] == ':') {
                    Wstart = i + 1;
                    i++;
                } else if(text[i] == ',' || text[i] == '}') {
                    Wend = i;
                    strncpy(name, text + Wstart, Wend - Wstart);
                    serv_data[menunum-1].charge_arr[menunum_charge].from = atoi(name);
                    memset(name, 0, sizeof(name));
                    menunum_charge++;
                    i++;
                    break;
                } else {
                    i++;
                }
            }
        } else {
            i++;
        }
    }
}
