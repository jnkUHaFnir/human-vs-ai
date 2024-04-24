if(strcmp(result, get) == 0){ // Compare result with get
    char answer[] = "You want GET";
    send(clientSocket, answer, strlen(answer), 0);
} else {
    if(strcmp(result, head) == 0){ // Compare result with head
        char answer[] = "You want HEAD";
        send(clientSocket, answer, strlen(answer), 0);
    } else {
        char answer[] = "HTTP/1.1 400 Bad Request";
        send(clientSocket, answer, strlen(answer), 0); 
    }
}
bytesRec = recv(clientSocket, buf, BUFSIZE, 0);
buf[bytesRec] = '\0'; // Null-terminate the buffer
char serverReply[1024]; // Change to character array

for(;;){
    char request[100];
    printf("Enter your request: ");
    scanf("%s", request); // Remove the & when reading a string

    send(clientSocket, request, strlen(request), 0); // Use request's length
    int bytesRec = recv(clientSocket, serverReply, sizeof(serverReply), 0);
    if(bytesRec < 0){
        printf("failure in receiving from server!\n");
    } else {
        serverReply[bytesRec] = '\0'; // Null-terminate the received data
        printf("%s\n", serverReply);
    }
}
