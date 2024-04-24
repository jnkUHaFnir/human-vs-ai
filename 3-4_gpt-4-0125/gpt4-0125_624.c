memset(buf, 0, BUFSIZE);  // Clear buffer
bytesRec = recv(clientSocket, buf, BUFSIZE - 1, 0);  // Leave room for null-terminator
if (bytesRec > 0) {
    buf[bytesRec] = '\0';  // Explicitly null-terminate the received string
    ...
}
char *result = strtok(buf, " \n\r");  // Also consider trimming newline and carriage return characters
if(strcmp(result, get) == 0){
    ...
}else if(strcmp(result, head) == 0){
    ...
}else{
    ...
}
char serverReply[1024];  // Correctly declare buffer

memset(serverReply, 0, 1024);  // Clear buffer before reading
int bytesRead = recv(clientSocket, serverReply, 1024 - 1, 0);
if (bytesRead > 0) {
    serverReply[bytesRead] = '\0';  // Ensure null-termination
    printf("%s\n", serverReply);
} else {
    printf("failure in receiving from server!\n");
}
scanf("%99s", request);  // Use %99s to avoid buffer overflow
send(clientSocket, request, strlen(request), 0);
