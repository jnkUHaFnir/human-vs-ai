#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* good_data(char* buff) {
  char *ip;
  ip = strtok(buff, " ");
  ip = strtok(NULL, " ");
  ip = strtok(NULL, " ");
  ip = strtok(ip, ":");

  printf("IP below\n");
  printf("%s\n", ip);

  return strdup(ip);
}

void read_entries() {
  int count = 0;
  for (int i = 0; i < top; i++) {
    FILE *fp;
    fp = fopen(File_List[i], "r");
    char buff[1024];

    while (fgets(buff, 1024, fp) != NULL) {
      char* ip = good_data(buff);
      if (ip) {
        // Use the IP address here
        // Example: printf("Good IP: %s\n", ip);
        count++;
      }
      free(ip); // Remember to free the dynamically allocated string
    }

    fclose(fp);
  }
}

int main() {
  read_entries();
  return 0;
}
