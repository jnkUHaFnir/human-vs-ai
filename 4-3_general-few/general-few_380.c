void service_data_func (char text[]) {

    int i = 0;
    int Wstart = 0;
    int Wend = 0;
    char name[19] = {0x20};
    char name1[19] = {0x20};
    int len = strlen(text);
    int menunum = 0;

    while (1) //while ALL
    {
        if(i >= len) {
            break;
        }
        if(text[i] == '"' && text[i + 1] == 'i' && text[i + 2] == 'd') {
            while (1) { //while "id

                if(text[i] == ':') {
                    Wstart = i + 1;
                    Wend = 0;
                    i++;
                } else if(text[i] == ',' || text[i] == '}' ) {
                    Wend = i;

                    strncpy(name, text + Wstart, Wend - Wstart);
                    serv_data[menunum].id = atoi(name);
                    memset(name, 0, sizeof(name));
                    i++;
                    break;
                } else {
                    i++;
                }

            } //while id
        } else if(text[i] == 's' && text[i + 1] == 'e' && text[i + 2] == 'r' && text[i + 3] == 'v' && text[i + 4] == 'i' && text[i + 5] == 'c' && text[i + 6] == 'e' && text[i + 7] == '_' && text[i + 8] == 'c' && text[i + 9] == 'h' && text[i + 10] == 'a' && text[i + 11] == 'r' && text[i + 12] == 'g' && text[i + 13] == '_' && text[i + 14] == 'l' && text[i + 15] == 'i' && text[i + 16] == 's' && text[i + 17] == 't') {
            int menunum_charge = 0; // Initialize for each charge entry
            while (1) //while ALL
            {
                if(i >= len) {
                    break;
                }
                if(text[i] == 'f' && text[i + 1] == 'r' && text[i + 2] == 'o' && text[i + 3] == 'm') {
                    while (1) { //while from

                        if(text[i] == ':') {
                            Wstart = i + 1;
                            Wend = 0;
                            i++;
                        } else if(text[i] == ',' || text[i] == '}') {
                            Wend = i;

                            strncpy(name, text + Wstart, Wend - Wstart);

                            serv_data[menunum].charge_arr[menunum_charge].from = atoi(name);
                            memset(name, 0, sizeof(name));
                            i++;
                            menunum_charge++; // Increment for each charge entry
                            break;
                        } else {
                            i++;
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
