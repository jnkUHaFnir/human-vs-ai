// Received buffer.
char* buf;

// Length of the buffer.
int len;

// Initialize pointer to the start of the string data.
char* currentPointer = buf + 8; // 8 bytes for 2x 32-bit integers.

// Iterate while pointer is within buffer limits.
while (currentPointer < (buf + len)) {
    // At this point `currentPointer` points to start of a NULL-terminated string.
    // You can directly use it, for example, print:
    printf("%s\n", currentPointer);

    // Move pointer past the current string and NULL terminator.
    currentPointer += strlen(currentPointer) + 1;
}
