char *convert_to_16(char *characters, int n){

    char sub_buffer[3];
    char code[3];
    char *buffer = (char*)malloc(strlen(characters) * 2 + 1); // Add 1 for null terminator
    buffer[0] = '\0'; // Initialize buffer with null terminator
    for(int i=0; i < n; i++){
        strncpy(code, characters+i, 1);
        sprintf(sub_buffer, "%x", *code);
        strncat(buffer, sub_buffer, 2);
    } 
    return buffer;
}
