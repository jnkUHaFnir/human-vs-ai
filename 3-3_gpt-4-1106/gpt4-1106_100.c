// ... your code ...

else if(text[i] == '"' && strncmp(&text[i+1], "id", 2) == 0) {
    i += 4; // Skip past "id": including the quotation marks and colon
    Wstart = i;
    while(text[i] != ',' && text[i] != '}' && text[i] != '\0') {
        i++; // Find the end of the number
    }
    Wend = i;

    strncpy(name, text+Wstart, Wend-Wstart);
    serv_data[menunum].id = atoi(name);
    memset(name, 0, sizeof(name));
    // Rest of your code...
}

// ... your code ...
