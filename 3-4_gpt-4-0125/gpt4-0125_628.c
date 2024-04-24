else if(strncmp(&text[i], "service_charge_list", 19) == 0) {
    i += 19; // Move past the "service_charge_list"
    while (1) // Parsing individual service charges
    {
        if(i >= len) break;

        // Example to parse "from" attribute in charge list
        if (strncmp(&text[i], "from", 4) == 0) {
            i += 5; // Skip past "from": to the value
            Wstart = i;
            while (text[i] != ',') { // Assume value ends at ',' for simplicity
                i++;
            }
            Wend = i;
            strncpy(name, text+Wstart, Wend-Wstart);
            serv_data[menunum].charge_arr[menunum_charge].from = atoi(name);
            memset(name, 0, sizeof(name));
            // You would need to do the similar for "to", "charge", etc.
            menunum_charge++; // Important to move to the next charge element for the next loop
        } else if (text[i] == ']') { // Assuming a ']' denotes end of service_charge_list
            break; // Exit the loop for service_charge_list parsing
        }

        i++; // Ensure we always move forward to avoid infinite loop
    }
}
