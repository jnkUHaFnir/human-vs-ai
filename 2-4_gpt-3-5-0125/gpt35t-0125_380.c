else if(text[i] == 's' && text[i+1] == 'e'&&
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
                            menunum_charge++; // Increment menunum_charge for each set of values parsed
                            break;
                        } else {
                            i=i+1;
                        }

                    }
                } else {
                    i++;
                }

            }
        } else {
            i++;
        }
