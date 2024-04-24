#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For malloc, free

int good_data(char* buff) {
      char *ip, *originalIP;
      ip = strtok(buff, " ");
      ip = strtok(NULL, " ");
      ip = strtok(NULL, " ");
      ip = strtok(ip, ":");

      // Duplicate ip to ensure it's not overwritten by subsequent strtok calls
      originalIP = strdup(ip);

      if (originalIP != NULL) {
          printf("IP below\n");
          printf("%s\n", originalIP);
          // Use originalIP for further operations
          // Example comparison - remember to free originalIP afterwards
          // int result = strcmp(originalIP, "69.12.26.238");
          // Handle the result or do further operations...

          free(originalIP); // Free the duplicated string after use
          return 0;
      } else {
          // Handling memory allocation failure
          printf("Failed to allocate memory for IP\n");
          return 0;
      }
}
