int good_data(char* buff, char* ip_address) {
      char *ip;
      ip = strtok (buff, " ");
      ip = strtok (NULL, " ");
      ip = strtok (NULL, " ");
      ip = strtok (ip, ":");

      strcpy(ip_address, ip); // copy the IP address to the ip_address variable

      printf("IP below\n");
      printf("%s\n", ip);
      //strcmp(ip, "69.12.26.238");
      return 0;
}
char ip_address[16]; // assuming the maximum length of an IP address is 15 characters
while (fgets(buff, 1024, fp) != NULL) {
    if (good_data(buff, ip_address)) {
        count++;
    }
    // use ip_address for further processing
}
