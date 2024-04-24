#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_entries() {
  int count = 0;
  for (int i = 0; i < top; i++) {
    FILE *fp;
    fp = fopen(File_List[i], "r");
    char buff[1024];

    while (fgets(buff, 1024, fp) != NULL) {
      char* ip = strdup(buff);
      if (ip != NULL) {
        if (good_data(ip)) {
          count++;
        }
        free(ip); // free the allocated memory for the copied IP
      } else {
        // handle allocation failure
        // you may want to log an error or take appropriate action
      }

    }

    fclose(fp);
  }
}

int good_data(char* buff) {
  char* ip_copy = strdup(buff); // make a copy of the IP string
  char *ip;
  ip = strtok(ip_copy, " ");
  ip = strtok(NULL, " ");
  ip = strtok(NULL, " ");
  ip = strtok(ip, ":");
  
  printf("IP below\n");
  printf("%s\n", ip);
  
  // Do something with the IP value here
  
  free(ip_copy); // free the allocated memory for the copied IP

  return 0;
}
