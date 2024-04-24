int good_data(char* buff) {
  char *ip;
  ip = strtok (buff, " ");
  if (ip == NULL) return 0;
  
  ip = strtok (NULL, " ");
  if (ip == NULL) return 0;
  
  ip = strtok (NULL, " ");
  if (ip == NULL) return 0;
  
  ip = strtok (ip, ":");
  if (ip == NULL) return 0;
 
  printf("IP below\n");
  printf("%s\n", ip);
  return 0;
}
