if (strstr(buffer, "q") != NULL) {
  printf("El cliente intenta cerrar la conexión\n");
  break;
}

do {
  printf("Please, type your message: ");
  bzero(buffer, 256);
  fgets(buffer, 255, stdin);

  if (strcmp("q", buffer) == 0) {
    printf("Closing connection\n");
    break;
  }

  n = write(socketfd, buffer, strlen(buffer)+1);
  if (n < 0 )
    error("Error writing to socket \n");
  else
    printf("...Message sent \n");

  n = read(socketfd, buffer, sizeof(buffer));
  if (n < 0 )
    error("Error reading from socket \n");
  else
    printf("\n Message from server: %s \n", buffer);

} while (1);