if(strcmp(result, get) == 0){
    char answer[] = "You want GET";
    send(clientSocket, answer, strlen(answer), 0);
}else if(strcmp(result, head) == 0){
    char answer[] = "You want HEAD";
    send(clientSocket, answer, strlen(answer), 0);
}else{
    char answer[] = "HTTP/1.1 400 Bad Request";
    send(clientSocket, answer, strlen(answer), 0);
}
char serverReply[1024];
fgets(request, sizeof(request), stdin);
send(clientSocket, request, strlen(request), 0);

if(recv(clientSocket, serverReply, sizeof(serverReply), 0) < 0){
    printf("failure in receiving from server!\n");
}else{
    printf("%s\n", serverReply);
}
