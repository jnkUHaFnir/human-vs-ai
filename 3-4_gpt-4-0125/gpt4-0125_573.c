while ((b = fread(buffer, 1, sizeof(buffer), fp)) > 0){
    if(send_all(sockfd, buffer, b) < 0) {  // Make sure to only send the number of bytes actually read
        perror("Failed to send file content");
        break;
    }
    memset(buffer, '\0', sizeof(buffer)); // Corrected memset usage
}
// Receive file size first
int32_t net_file_size;
ssize_t recv_res = recv(sockfd, &net_file_size, sizeof(net_file_size), 0);
if (recv_res <= 0) return -1;

int file_size = ntohl(net_file_size);  // Convert from network byte order to host byte order

// Allocate a buffer based on file_size here and receive the file data accordingly
