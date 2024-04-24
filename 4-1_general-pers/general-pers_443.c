// Before writing to the buffer, make sure there is enough space
if (strlen(buffer) >= sizeof(buffer) - 1) {
    fprintf(stderr, "ERROR: Input message too long\n");
    exit(1);
}

// Copy input message to the buffer
strncpy(buffer, input_message, sizeof(buffer) - 1);
buffer[sizeof(buffer) - 1] = '\0'; // Ensure null-termination
