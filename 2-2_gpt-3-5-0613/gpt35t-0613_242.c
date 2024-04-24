// Create the message payload
char* information_i_want_to_send = "Hello, World!";

// Calculate the length of the payload
size_t payload_length = strlen(information_i_want_to_send) + 1; // +1 for null terminator

// Create the message header
struct MessageHeader {
    size_t length;
} header;

// Populate the header with the payload length
header.length = payload_length;

// Send the header
send(ioSock, &header, sizeof(header), 0);
 
// Send the payload
send(ioSock, information_i_want_to_send, payload_length, 0);
// Receive the header
struct MessageHeader header;
recv(ioSock, &header, sizeof(header), 0);

// Allocate a buffer for the payload
char* payload = malloc(header.length);

// Receive the payload
size_t total_received = 0;
while (total_received < header.length) {
    ssize_t received = recv(ioSock, payload + total_received, header.length - total_received, 0);
    if (received <= 0) {
        // Handle error or termination condition
        break;
    }
    total_received += received;
}

// Make sure the payload is null-terminated
payload[header.length - 1] = '\0';

// Use the received payload
printf("Received: %s\n", payload);

// Clean up
free(payload);
