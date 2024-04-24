int good_data(char* buff) {
    // Make a copy of the buffer to avoid modifying the original string
    char buffer_copy[1024];
    strcpy(buffer_copy, buff);

    char *ip = strtok(buffer_copy, " ");
    for (int i = 0; i < 2 && ip != NULL; i++) {
        ip = strtok(NULL, " "); // Get the next token
    }

    if (ip) {
        ip = strtok(ip, ":");
        if (ip) {
            printf("IP below\n");
            printf("%s\n", ip);

            // strcmp returns 0 if strings are equal, so you may want to check if it's not equal
            // return strcmp(ip, "69.12.26.238") != 0;
            
            return 1; // Assuming the data is good if all above conditions are met
        }
    }

    return 0;
}
FILE *fp;
fp = fopen(File_List[i], "r");
if(fp == NULL) {
  fprintf(stderr, "Failed to open file %s\n", File_List[i]);
  continue; // Skip this file and move on to the next
}
