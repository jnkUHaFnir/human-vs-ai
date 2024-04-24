char re[size_data];
strncpy(re, data, size_data); // data is the buffer and size_data the buffer size

char method[10]; // Assuming method can be at most 10 characters long
sscanf(re, "%s", method);

if(strcmp(method, "POST") == 0) {
    // Handle POST method
}
