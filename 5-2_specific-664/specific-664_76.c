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
  char ip_copy[16]; // Assuming IPv4 address length
  ip = strtok(buff, " ");
  ip = strtok(NULL, " ");
  ip = strtok(NULL, " ");
  ip = strtok(ip, ":");

  if (ip != NULL) {
    snprintf(ip_copy, sizeof(ip_copy), "%s", ip);
    printf("IP below\n");
    printf("%s\n", ip_copy);
    return 0;
  }

  return -1; // indicate an error if ip is NULL
}
