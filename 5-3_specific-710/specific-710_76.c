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

      printf("IP below\n");
      printf("%s\n", ip);
      
      if (ip == NULL) {
          // handle case where ip is NULL
          return 0;
      }

      // Make a copy of ip before using it in another function
      char *ip_copy = strdup(ip);
      if (ip_copy == NULL) {
          // handle case where strdup fails
          return 0;
      }

      // Now you can safely use ip_copy in other functions
      // For example, pass it to another function like this:
      // some_other_function(ip_copy);

      // Don't forget to free the memory allocated by strdup when done
      free(ip_copy);

      return 0;
}
