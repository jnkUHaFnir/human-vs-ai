    if (sscanf(buffer, " %[a-z] = %[0-9]", &name, &value) == 2) {
        // matched a line with name=value, do something with it
    } else {
        // didn't match -- give an error?
    }