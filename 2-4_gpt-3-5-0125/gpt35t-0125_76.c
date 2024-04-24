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
      char ip_buffer[16]; // assuming IPv4 address
      ip = strtok (buff, " ");
      ip = strtok (NULL, " ");
      ip = strtok (NULL, " ");
      ip = strtok (ip, ":");
      
      strcpy(ip_buffer, ip); // copy IP address to a separate buffer

      printf("IP below\n");
      printf("%s\n", ip_buffer);
      // now you can use ip_buffer as the IP address
      // strcmp(ip_buffer, "69.12.26.238");

      return 0;
}
