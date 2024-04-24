void service_data_func(char text[]) {
    int i = 0;
    int len = strlen(text);
    int menunum = 0;
    int menunum_charge = 0;

    while (i < len) {
        if (text[i] == '"' && text[i+1] == 'i' &&
            text[i+2] == 'd') {
            // Handling id field

            // Increment menunum
            menunum++;

            // Your code to extract and store 'id' goes here

        } else if (text[i] == 's' && text[i+1] == 'e' &&
                   text[i+2] == 'r' && text[i+3] == 'v' &&
                   text[i+4] == 'i' && text[i+5] == 'c' &&
                   text[i+6] == 'e' && text[i+7] == '_' &&
                   text[i+8] == 'c' && text[i+9] == 'h' &&
                   text[i+10] == 'a' && text[i+11] == 'r' &&
                   text[i+12] == 'g' && text[i+13] == '_' &&
                   text[i+14] == 'l' && text[i+15] == 'i' &&
                   text[i+16] == 's' && text[i+17] == 't') {
            // Handling service_charge_list

            while (i < len) {
                if (text[i] == 'f' && text[i+1] == 'r' &&
                    text[i+2] == 'o' && text[i+3] == 'm') {
                    // Handling 'from'

                    // Increment menunum_charge
                    menunum_charge++;

                    // Your code to extract and store 'from' goes here
                }

                i++;
            }
        }

        i++;
    }
}
