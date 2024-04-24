const char* hello(char* name) {
    char* greeting = (char*)malloc(strlen("Hello, ") + strlen(name) + strlen("!\n") + 1);
    if (greeting == NULL) {
        return NULL; // Handle allocation failure
    }

    strcpy(greeting, "Hello, ");
    strcat(greeting, name);
    strcat(greeting, "!\n");
    
    printf("%s\n", greeting);
    return greeting;
}

By dynamically allocating memory using `malloc`, you can safely return the string from the function and handle memory management appropriately in your Python script. Make sure to free the memory after you are done using it to avoid memory leaks and segfaults.
