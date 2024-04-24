void service_data_func (char text[]) {
    int i=0;
    int Wstart=0;
    int Wend=0;
    char name[19]= {0x20};
    int len;
    len=strlen(text);
    int menunum=-1; // initialize with -1
    int menunum_charge=0;

    while (1) {
        if(i>=len) {
            break;
        }

        if(text[i] == '{' && text[i+1] == '"' && text[i+2] == 'i' && text[i+3] == 'd') {
            menunum++; // Incrementing to move to the next struct in the array
            menunum_charge = 0; // Resetting service charge index for the new service
            i+=4; // Move past "id":
        } else if(text[i] == '"' && text[i+1] == 'f' && text[i+2] == 'r' && text[i+3] == 'o' && text[i+4] == 'm') {
            while (1) { // while from
                if(text[i] == ':') {
                    Wstart=i+1;
                    Wend=0;
                    i++;
                } else if(text[i] == ',' || text[i] == '}') {
                    Wend=i;
                    strncpy(name,text+Wstart,Wend-Wstart);
                    serv_data[menunum].charge_arr[menunum_charge].from=atoi(name);
                    memset(name, 0, sizeof(name));
                    i++;
                    menunum_charge++; // Incrementing service charge index
                    break;
                } else {
                    i=i+1;
                }
            }
        } else {
            i++;
        }
    }
}
