...
} else if(text[i] == 's' && text[i+1] == 'e'&&
                  text[i+2] == 'r'&& text[i+3] == 'v'&& text[i+4] == 'i'&&
                  text[i+5] == 'c'&& text[i+6] == 'e'&& text[i+7] == '_'&& text[i+8]
                  == 'c'&& text[i+9] == 'h'&& text[i+10] == 'a'&& text[i+11] ==
                  'r'&& text[i+12] == 'g'&& text[i+13] == 'e'&& text[i+14] == '_'&&
                  text[i+15] == 'l'&& text[i+16] == 'i'&& text[i+17] == 's'&&
                  text[i+18] == 't') {
            while (1)//while ALL
            {
                if(i>=len) {
                    break;
                }
                if(text[i] == 'f' && text[i+1] == 'r'&&
                        text[i+2] == 'o'&& text[i+3] == 'm') {
                    while (1) { //while from

                        if(text[i] == ':') {
                            Wstart=i+1;
                            Wend=0;
                            i++;
                        } else if(text[i] == ',' || text[i] == '}' ) {

                            Wend=i;

                            strncpy(name,text+Wstart,Wend-Wstart);

                            serv_data[menunum].charge_arr[menunum_charge].from=atoi(name);
                            memset(name, 0, sizeof(name));
                            i++;
                            break;
                        } else {
                            i=i+1;
                        }

                    }
                } else {
                    i++;
                }
            } // This closing brace should be here
        } else {
            i++;
        }
...
void service_data_func (char text[]) {

    int i=0;
    int Wstart=0;
    int Wend=0;
    char name[19]= {0x20};
    int menunum=0;
    int len;
    len=strlen(text);
    int menunum_charge=0;

    while (1)//while ALL
    {
        if(i>=len) {
            break;
        }

        // Add code for processing other attributes of service structure and 
        // increment menunum after fully processing a service element

        if(text[i] == 'f' && text[i+1] == 'r'&&
                text[i+2] == 'o'&& text[i+3] == 'm') {
            while (1) { //while from

                if(text[i] == ':') {
                    Wstart=i+1;
                    Wend=0;
                    i++;
                } else if(text[i] == ',' || text[i] == '}' ) {

                    Wend=i;
                    strncpy(name,text+Wstart,Wend-Wstart);

                    serv_data[menunum].charge_arr[menunum_charge].from=atoi(name);
                    memset(name, 0, sizeof(name));
                    i++;
                    break;
                } else {
                    i=i+1;
                }
                
                // Add code for processing other attributes of service_charge structure
            }
            
            menunum_charge++;  // Increment menunum_charge after each service_charge element is processed
        } else {
            i++;
        }
        
        // Reset menunum_charge to 0 and increment menunum if all charges for the current service are processed
    }
}
