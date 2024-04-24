#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* get_ip(const char* buff) {
    char *ip;
    ip = strtok (buff, " ");
    ip = strtok (NULL, " ");
    ip = strtok (NULL, " ");
    ip = strtok (ip, ":");
    
    // Make a copy of ip
    char *ip_copy = strdup(ip);
    
    return ip_copy;
}

void read_entries() {
    int count = 0;
    for (int i = 0; i < top; i++) {
        FILE *fp;
        fp = fopen(File_List[i], "r");
        char buff[1024];

        while (fgets(buff, 1024, fp) != NULL) {
            if (good_data(buff)) {
                char* ip = get_ip(buff);
                
                // Now you can use ip safely
                printf("IP: %s\n", ip);
                
                free(ip); // Free the memory allocated by strdup
                
                count++;
            }

        }

        fclose(fp);
    }
}

int good_data(char* buff) {
    // Your existing implementation of good_data function
    return 0;
}
