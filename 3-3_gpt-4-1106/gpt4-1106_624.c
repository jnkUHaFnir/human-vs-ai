memset(buf, 0, BUFSIZE);
bytesRec = recv(clientSocket, buf, BUFSIZE - 1, 0); // Leave room for null-terminator
if(strcmp(buf, get) == 0) {
    // ...
} else if(strcmp(buf, head) == 0) {
    // ...
char serverReply[1024];

// ...

printf("Enter your request: ");
scanf("%99s", request); // Note: this reads up to 99 characters, leaving 1 for null-terminator.
send(clientSocket, request, strlen(request), 0);

int bytesRec = recv(clientSocket, serverReply, sizeof(serverReply) - 1, 0); // Again, leave space for null-terminator
if (bytesRec < 0) {
    printf("Failure in receiving from server!\n");
} else {
    serverReply[bytesRec] = '\0'; // null-terminate the received string
    printf("%s\n", serverReply);
}
