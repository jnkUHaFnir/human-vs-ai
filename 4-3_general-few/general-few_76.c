int good_data(char* buff) {
    char *ip;
    ip = strtok(buff, " ");
    ip = strtok(NULL, " ");
    ip = strtok(NULL, " ");
    ip = strtok(ip, ":");

    printf("IP below\n");
    printf("%s\n", ip);
    
    char* ip_copy = strdup(ip); // Create a copy of the IP address
    if (ip_copy == NULL) {
        // Handle allocation failure
        return -1;
    }

    // Now you can safely pass ip_copy to another function
    // For example:
    // some_function(ip_copy);
    
    // Remember to free the allocated memory when you're done with ip_copy
    free(ip_copy);

    return 0;
}
