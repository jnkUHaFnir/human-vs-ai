
**Client Side Issues:**
1. You are using `strlen(serverReply)` to get the buffer size in `recv`, but `serverReply` is uninitialized, causing undefined behavior. Instead, you should use `sizeof(serverReply)` or a defined buffer size.
2. You missed checking for the null terminator in the received message.
3. Ensure you close the socket after exiting the loop.

**Corrected Client Code:**

```C
// ... includes as you have them already

int main() {
    // ... Client setup as you have it already

    char serverReply[1024];
    char request[100]; // Not needed in an infinite loop
    while (1) {
        printf("Enter your request: ");
        scanf("%99s", request);
        send(clientSocket, request, strlen(request), 0);
        
        memset(serverReply, 0, sizeof(serverReply)); // Clear the buffer
        int bytesRec = recv(clientSocket, serverReply, sizeof(serverReply) - 1, 0);
        if (bytesRec < 0) {
            perror("failure in receiving from server");
            break; // Exit the loop if there is a recv error
        } else {
            printf("%s\n", serverReply);
        }
    }

    close(clientSocket);

    return 0;
}
