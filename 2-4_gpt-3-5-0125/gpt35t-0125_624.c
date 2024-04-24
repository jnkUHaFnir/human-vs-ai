    if(strcmp(result, get) == 0){
        char answer[] = "You want GET";
        send(clientSocket, answer, strlen(answer), 0);
    }else{
        if(strcmp(result, head) == 0){
            char answer[] = "You want HEAD";
            send(clientSocket, answer, strlen(answer), 0);
        }else{
            char answer[] = "HTTP/1.1 400 Bad Request";
            send(clientSocket, answer, strlen(answer), 0); 
        }
    }

    close(clientSocket); // close the client socket after sending response
char serverReply[1024]; // Use a character array to store server's reply

for(;;){
    char request[100];
    printf("Enter your request: ");
    scanf("%s", request); // Remove & before request
    send(clientSocket, request, strlen(request), 0); // Use strlen(request) instead of strlen(serverReply)
    if(recv(clientSocket, serverReply, sizeof(serverReply), 0) < 0){
        printf("failure in receiving from server!\n");
    }else{
        printf("%s\n", serverReply);
    }
}
