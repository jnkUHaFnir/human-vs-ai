if(strcmp(result, get) == 0){
    char answer[] = "You want GET";
    send(clientSocket, answer, strlen(answer), 0);
} else if(strcmp(result, head) == 0){
    char answer[] = "You want HEAD";
    send(clientSocket, answer, strlen(answer), 0);
} else {
    char answer[] = "HTTP/1.1 400 Bad Request";
    send(clientSocket, answer, strlen(answer), 0); 
}
char request[100];
printf("Enter your request: ");
fgets(request, sizeof(request), stdin);
// Remove newline character at the end
request[strcspn(request, "\n")] = 0;
send(clientSocket, request, strlen(request), 0);
