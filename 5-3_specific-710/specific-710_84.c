#define MAX_BUFFER_SIZE 1024

// Function to send the POST request
void sendPostRequest(const char *hostname, const char *port, const char *path, const char *data) {
    // Create socket, connect, send request, receive response, etc.
    
    // Code to send the POST request
    // Example: Assuming you already have the socket file descriptor
    char request[MAX_BUFFER_SIZE];
    snprintf(request, MAX_BUFFER_SIZE, "POST %s HTTP/1.1\r\nHost: %s\r\nContent-Length: %ld\r\n\r\n%s",
             path, hostname, strlen(data), data);
    
    // Send the POST request
    send(sockfd, request, strlen(request), 0);
    
    // Code to receive and handle the response
    
    // Close the socket when done
    close(sockfd);
}

int main() {
    // Example usage
    const char *hostname = "example.com";
    const char *port = "80";
    const char *path = "/endpoint";
    const char *data = "key1=value1&key2=value2";
    
    sendPostRequest(hostname, port, path, data);
    
    return 0;
}
