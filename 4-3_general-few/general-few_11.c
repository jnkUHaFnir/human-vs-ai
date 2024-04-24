void service_data_func(char text[]) {
    int i = 0;
    int len = strlen(text);
    int menunum = 0;
    int menunum_charge = 0;

    while (1) {
        if (i >= len) {
            break;
        }
        if (text[i] == '"' && text[i + 1] == 'i' && text[i + 2] == 'd') {
            // Parsing and assigning id field
            // Skipped for brevity
        } else if (strncmp(text + i, "\"service_charge_list\":", 22) == 0) {
            i += 22; // Move past the field label to get to the first charge_arr element
            while (1) {
                if (text[i] == '{') {
                    i++; // Move past the opening brace
                    // Parsing and assigning fields of charge_arr
                    // Skipped for brevity
                    menunum_charge++; // Increment the index of charge_arr
                } else if (text[i] == '}') {
                    menunum++; // Move to the next service item
                    menunum_charge = 0; // Reset the index of charge_arr for the next service
                    i++; // Move past the closing brace
                } else if (text[i] == ']') {
                    break; // End of service_list
                } else {
                    i++;
                }
            }
        } else {
            i++;
        }
    }
}
