bytesRec = recv(clientSocket, buf, BUFSIZE-1, 0);
while(bytesRec > 0){
    // Ensure null termination
    buf[bytesRec] = '\0';  

    // Rest of your server code
}
if((bytesRec = recv(clientSocket, serverReply, sizeof(serverReply)-1, 0)) < 0){
    printf("failure in receiving from server!\n");
}else{
    serverReply[bytesRec] = '\0';
    printf("%s\n", serverReply);
}
