#define BUFFER_SIZE 4096

char buffer[BUFFER_SIZE];
char *response = NULL; // Dynamic buffer to hold aggregated chunks
size_t response_size = 0;

int header_ended = 0; // Flag to indicate the end of headers
char *header_end; // Pointer to mark the end of headers in the buffer

// Receive and process data
while((readed = recv(sock, buffer, BUFFER_SIZE - 1, 0)) > 0) {
    // Ensure null-termination for string operations
    buffer[readed] = '\0';

    // If headers haven't ended, search for the delimiter
    if (!header_ended) {
        // Allocate / resize the response buffer and copy new data
        response = realloc(response, response_size + readed + 1);
        memcpy(response + response_size, buffer, readed);
        response_size += readed;
        
        // Search for the delimiter in the accumulated response
        if ((header_end = strstr(response, "\r\n\r\n")) != NULL) {
            header_ended = 1; // Mark the end of headers
            // Calculate the start of the binary data
            char *binary_start = header_end + 4; // After the "\r\n\r\n"
            // Write the initial chunk of binary data to the file
            fwrite(binary_start, 1, response + response_size - binary_start, fp);
        }
    } else {
        // Headers are done, write everything received to the file
        fwrite(buffer, 1, readed, fp);
    }
}

// Clean up
if (response != NULL) {
    free(response);
}
