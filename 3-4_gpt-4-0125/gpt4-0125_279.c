void service_data_func (char text[]) {
    int i=0;
    int Wstart=0;
    int Wend=0;
    char name[20]= {0}; // Ensure sufficient size and initialize with 0
    int menunum=0;
    int len;
    len = strlen(text);
    int menunum_charge = 0;
    int in_service_charge = 0; // A flag to control the flow within the service charge list

    while (i < len) // Make sure the condition is explicit for the redundancy check
    {
        if(text[i] == '"' && text[i+1] == 'i' && text[i+2] == 'd' && !in_service_charge) {
            i += 3;
            // Loop to search for ':'
            while (i < len && text[i] != ':') ++i; // Skip to the colon
            Wstart = i + 1;

            // Loop to search for ',' or '}'
            while (i < len && text[i] != ',' && text[i] != '}') ++i;
            Wend = i;

            strncpy(name, text + Wstart, Wend - Wstart);
            name[Wend-Wstart] = '\0'; // NULL terminate the string
            serv_data[menunum].id = atoi(name);
        } 
        else if(strncmp(text+i, "service_charge_list", 19) == 0) {
            i += 19; // Move past "service_charge_list"
            in_service_charge = 1; // Set the flag indicating we are parsing service charges
            menunum_charge = 0; // Reset for each service
        } 
        else if(text[i] == 'f' && text[i+1] == 'r' && text[i+2] == 'o' && text[i+3] == 'm' && in_service_charge) {
            i += 4;
            // Loop to search for ':'
            while (i < len && text[i] != ':') ++i; // Skip to the colon
            Wstart = i + 1;

            // Loop to search for ',' or '}'
            while (i < len && text[i] != ',' && text[i] != '}') ++i;
            Wend = i;

            strncpy(name, text + Wstart, Wend - Wstart);
            name[Wend-Wstart] = '\0'; // NULL terminate the string
            serv_data[menunum].charge_arr[menunum_charge].from = atoi(name);

            menunum_charge++; // Increment charge index for the next charge item
            if(menunum_charge >= 10) // Prevent overflow of charge_arr
                break;
        } 
        else {
            i++; // Continue searching
        }
    }
}
