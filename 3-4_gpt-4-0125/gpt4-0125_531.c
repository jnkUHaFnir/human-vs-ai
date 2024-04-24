// Note: minimal changes for brevity; consider other optimizations and checks.
while(bytesRec > 0){
    buf[bytesRec] = '\0'; // Null-terminate the received data.

    if(strcmp(buf, "GET") == 0){
        char answer[] = "You want GET";
        send(clientSocket, answer, sizeof(answer) - 1, 0);
    } else if(strcmp(buf, "HEAD") == 0){
        char answer[] = "You want HEAD";
        send(clientSocket, answer, sizeof(answer) - 1, 0);
    } else {
        char answer[] = "HTTP/1.1 400 Bad Request";
        send(clientSocket, answer, sizeof(answer) - 1, 0); 
    }

    bytesRec = recv(clientSocket, buf, BUFSIZE-1, 0);
}
// Missing: close(clientSocket) after the loop.
// Note: Minimal changes for clarity and demonstration.
char serverReply[1024]; // Use a char buffer, not an array of char pointers.

for(;;){
    char request[100];
    printf("Enter your request: ");
    scanf("%99s", request); // Add a limit to scanf to prevent buffer overflow
    send(clientSocket, request, strlen(request), 0);

    int bytesReceived = recv(clientSocket, serverReply, sizeof(serverReply) - 1, 0);
    if(bytesReceived < 0){
        printf("Failure in receiving from server!\n");
    } else {
        serverReply[bytesReceived] = '\0'; // Null-terminate the received data.
        printf("%s\n", serverReply);
    }
}

close(clientSocket);
