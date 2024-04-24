if(strcmp(result, get) == 0) {
    char answer[] = "You want GET";
    send(clientSocket, answer, sizeof(answer), 0);
} else if(strcmp(result, head) == 0) {
    char answer[] = "You want HEAD";
    send(clientSocket, answer, sizeof(answer), 0);
} else {
    char answer[] = "HTTP/1.1 400 Bad Request";
    send(clientSocket, answer, sizeof(answer), 0); 
}
char serverReply[1024];
send(clientSocket, request, strlen(request), 0);
