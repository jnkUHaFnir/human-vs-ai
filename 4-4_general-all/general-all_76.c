void read_entries() {
    int count = 0;
    for (int i = 0; i < top; i++) {
        FILE *fp;
        fp = fopen(File_List[i], "r");
        if (fp == NULL) {
            // Handle file open error
            continue;
        }

        char buff[1024];

        while (fgets(buff, 1024, fp) != NULL) {
            if (good_data(buff)) {
                count++;
            }
        }

        fclose(fp);
    }
}

int good_data(char* buff) {
    char* temp = strdup(buff); // Make a copy of buff

    char *ip;
    ip = strtok(temp, " ");
    ip = strtok(NULL, " ");
    ip = strtok(NULL, " ");
    if (ip != NULL) {
        char* ipCopy = strdup(ip); // Make a copy of ip to pass it safely
        printf("IP below\n");
        printf("%s\n", ipCopy);

        // Call a function with ipCopy
        // function_name(ipCopy);

        free(ipCopy); // Free the memory allocated for ipCopy
    }

    free(temp); // Free the memory allocated for temp

    return 0;
}
