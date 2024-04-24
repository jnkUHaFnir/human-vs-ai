void service_data_func(char text[]) {
    int i = 0;
    int len = strlen(text);
    int menunum = 0;
    int menunum_charge = 0;
    int Wstart = 0;
    int Wend = 0;
    char name[19] = {0x20};

    while (i < len) {
        switch (text[i]) {
            case '"':
                if (strncmp(text + i, "\"id\":", 5) == 0) {
                    Wstart = i + 5;
                    i += 5;
                    while (text[i] != ',' && text[i] != '}') {
                        i++;
                    }
                    Wend = i;
                    strncpy(name, text + Wstart, Wend - Wstart);
                    serv_data[menunum].id = atoi(name);
                    memset(name, 0, sizeof(name));
                    menunum++;
                } else if (strncmp(text + i, "\"from\":", 7) == 0) {
                    Wstart = i + 7;
                    i += 7;
                    while (text[i] != ',' && text[i] != '}') {
                        i++;
                    }
                    Wend = i;
                    strncpy(name, text + Wstart, Wend - Wstart);
                    serv_data[menunum - 1].charge_arr[menunum_charge].from = atoi(name);
                    memset(name, 0, sizeof(name));
                    menunum_charge++;
                }
                break;
            default:
                i++;
                break;
        }
    }
}
