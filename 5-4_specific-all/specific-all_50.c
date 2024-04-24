size_t total_received = 0;
do {
    if ((received = recvfrom(context->socket, context->packet + total_received, BUFF_SIZE - total_received, 0, NULL, NULL)) < 0) {
        perror("Failed to receive");
        exit(-1);
    }

    if (received > 0) {
        total_received += received;
        context->packet[total_received] = '\0'; // Ensure null-termination
    }

} while (received > 0 && total_received < BUFF_SIZE);

// Print or process the entire response here
printf("%s", context->packet);

// Close the connection after reading the response
close(context->socket);
