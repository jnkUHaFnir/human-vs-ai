size_t data_length = strlen(data_to_send);
send(ioSock, &data_length, sizeof(size_t), 0);
send(ioSock, data_to_send, data_length, 0);
size_t data_length;
recv(ioSock, &data_length, sizeof(size_t), 0);

char* received_data = (char*)malloc(data_length + 1);
if (received_data) {
    size_t total_received = 0;
    while (total_received < data_length) {
        ssize_t received = recv(ioSock, received_data + total_received, data_length - total_received, 0);
        if (received <= 0) {
            // Handle error or connection closed
            break;
        }
        total_received += received;
    }
    received_data[data_length] = '\0'; // Ensure null-termination for strings
    // Process received_data
    free(received_data);
}
