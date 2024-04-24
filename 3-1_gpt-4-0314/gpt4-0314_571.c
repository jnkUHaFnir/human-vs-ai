int recv_txt_file(int sockfd, int msg_len, const char *filename);
while (total < msg_len){
    b = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if(b <= 0) break;
    total += b;
    fwrite(buffer, 1, b, fp);
}
int msg_len;
if((res = strcmp(buffer, "SENDFILE_TXT\n") == 0)){
    // ...
    read = recv_all(client_fd, buffer, BUFFER_SIZE);
    if(read <= 0){
        // ...
    }
    printf("-------FROM CLIENT: %s-------\n", buffer);
    msg_len = atoi(buffer); // Include this line to get the message length from the client
    // ...
}
else if((res = strcmp(buffer, "SENDTXTFILE\n") == 0)){ // change this to SENDTXTFILE
    // ...
    recv_txt_file(client_fd, msg_len, filename); // Add msg_len as parameter
}
long int file_size;
int msg_len;
if(strstr(buffer, "SENDTXTFILE") != NULL){
    // ...
    printf("Give filename> ");
    // ...
    file_size = get_file_size(fname); // Include this line to get the file size in bytes
    msg_len = snprintf(buffer, BUFFER_SIZE, "%ld", file_size); // Include this line to set the msg_len
    if(send_all(sockfd, buffer, BUFFER_SIZE) < 0){
        // ...
    }
    // ...
    send_txt_file(sockfd, BUFFER_SIZE, fname);
}
