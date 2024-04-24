void service_data_func(char text[]) {

    // ...

    while (1) {
        if (i >= len) {
            break;
        } else if (/* "id" condition */) {
            // ...
        } else if (/* "service_charge_list" condition */) {
            // separate loop for service_charge_list
            int j = i;
            while (1) {
                if (j >= len) {
                    break;
                } else if (/* "from" condition */) {
                    // add values to charge_arr array
                    while (1) {
                        if (text[j] == ':') {
                            Wstart = j + 1;
                            Wend = 0;
                            j++;
                        } else if (text[j] == ',' || text[j] == '}') {
                            Wend = j;

                            strncpy(name, text + Wstart, Wend - Wstart);
                            serv_data[menunum].charge_arr[menunum_charge].from = atoi(name);
                            memset(name, 0, sizeof(name));
                            j++;
                            menunum_charge++; // increment charge_arr index
                            break;
                    } // end while from or to or charge or slap or percentage
                } // end if from
                j++; // increment loop counter
            } // end while service_charge_list
        } // end if service_charge_list
        i++; // increment loop counter
    } // end while ALL
} // end service_data_func
