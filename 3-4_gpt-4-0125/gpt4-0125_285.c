void service_data_func (char text[]) {
    int i=0;
    int Wstart=0;
    int Wend=0;
    char name[20]= {0}; // Increased size for null terminator
    char name1[20]= {0}; // Unused, can be removed if not needed.
    int menunum=0;
    int len = strlen(text);
    int menunum_charge=0;
    int in_service_charge_list = 0; // New flag to indicate if we're in the service charge list section

    while (i < len)
    {
        // Simplified logic to detect entering the service charge list
        if(strncmp(&text[i], "\"service_charge_list\"", 21) == 0) {
            in_service_charge_list = 1;
            i += 21;
        }

        // Once we're in the service_charge_list, look for "from" values specifically
        if(in_service_charge_list && strncmp(&text[i], "\"from\"", 6) == 0) {
            i += 6; // Move past "from"
            while (i < len && text[i] != ':') {
                i++; // Skip until colon
            }
            i++; // Skip colon itself

            Wstart = i;
            while (i < len && text[i] != ',' && text[i] != '}') {
                i++; // Find the end of the number
            }
            Wend = i;

            // Copy and parse the number
            strncpy(name, text+Wstart, Wend-Wstart);
            name[Wend-Wstart] = '\0'; // Null-terminate the string
            serv_data[menunum].charge_arr[menunum_charge].from = atoi(name);

            // Increment to parse next if exists, or break if done
            menunum_charge++; // If you intend to parse more than one, but make sure to handle array bounds
            in_service_charge_list = 0; // Simplified just to parse first; adjust logic as needed for full parsing
            break; // For this example, we just break after finding the first from in the charge list.
        }
        else {
            i++; // Continue searching
        }
    }
}
