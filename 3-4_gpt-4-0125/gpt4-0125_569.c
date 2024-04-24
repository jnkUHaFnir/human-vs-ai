// Add before the while loop a part to receive the file size
// Assuming the client sends the file size as an ASCII string followed by '\n' before the file content
char fileSizeStr[20];
memset(fileSizeStr, '\0', sizeof(fileSizeStr));
recv_all(sockfd, fileSizeStr, sizeof(fileSizeStr)-1); // You may need a different function to handle this part
long int fileSize = atol(fileSizeStr);

long int bytesReceived = 0;

// Then, inside your file receive logic
while (bytesReceived < fileSize)
{
    int toRead = BUFFER_SIZE < (fileSize - bytesReceived) ? BUFFER_SIZE : (fileSize - bytesReceived);
    b = recv(sockfd, buffer, toRead, 0);
    if (b <= 0) break; // add error handling here
    fwrite(buffer, 1, b, fp);
    bytesReceived += b;
}
long int fileSize = get_file_size(fname);
sprintf(buffer, "%ld\n", fileSize);
// Send fileSizeStr to the server
send_all(sockfd, buffer, strlen(buffer));
// Then proceed to send the file content
