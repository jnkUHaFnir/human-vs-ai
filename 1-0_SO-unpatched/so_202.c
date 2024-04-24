    char name[100], value[100];
    if (sscanf(buffer, " %99[a-z] = %99[0-9]", name, value) == 2) {
        // matched a line with name=value, do something with it
    } else {
        // didn't match -- give an error?
    }