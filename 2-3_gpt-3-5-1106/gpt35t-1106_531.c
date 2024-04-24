if(strcmp(result, get) == 0) {
    // ...
} else {
    if(strcmp(result, head) == 0) {
        // ...
    } else {
        // ...
    }
}
char serverReply[BUFSIZE];

// ...

if(recv(clientSocket, serverReply, BUFSIZE, 0) < 0) {
    printf("failure in receiving from server!\n");
} else {
    printf("%s\n", serverReply);
}
