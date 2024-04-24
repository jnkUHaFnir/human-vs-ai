#include <stdio.h>
#include <string.h>

int top = 1;
char *File_List[] = {"testdata.txt"};

void read_entries();
int good_data(char* buff);

int main()
{
    read_entries();
    return 0;
}

void read_entries() {
  int count = 0;
  for (int i = 0; i < top; i++) {
    FILE *fp;
    fp = fopen(File_List[i], "r");
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
      char *ip;
      ip = strtok (buff, " ");
      ip = strtok (NULL, " ");
      ip = strtok (NULL, " ");
      ip = strtok (ip, ":");

      char ip_copy[16]; // To store a copy of the IP address
      strncpy(ip_copy, ip, 15); // Be sure not to overflow the buffer
      ip_copy[15] = '\0'; // Make sure it's null-terminated

      printf("IP below\n");
      printf("%s\n", ip_copy);
      //strcmp(ip_copy, "69.12.26.238");
      // Pass ip_copy to any other function

      return 0;
}
