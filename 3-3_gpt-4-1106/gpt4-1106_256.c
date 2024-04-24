size_t total_read = 0;
size_t header_length = 0;
int headers_found = 0;
char buffer[8192];
char *body_ptr = NULL;

// Assume fp is already open for writing the binary data

while ((readed = recv(sock, buffer + total_read, sizeof(buffer) - total_read - 1, 0)) > 0) {
    total_read += readed;
    
    if (!headers_found) {
        // Search for the end of the headers
        buffer[total_read] = '\0'; // Null-terminate to use strstr safely
        
        body_ptr = strstr(buffer, "\r\n\r\n");
        
        if (body_ptr) {
            headers_found = 1;
            body_ptr += 4; // Move the pointer past the "\r\n\r\n"
            header_length = body_ptr - buffer;
            
            // Write the first part of body we already read from the socket
            fwrite(body_ptr, 1, total_read - header_length, fp);
        }
    } else {
        // We found the headers before, so write everything we receive to file
        fwrite(buffer, 1, readed, fp);
    }
    
    if (headers_found) {
        // Reset the total_read for reading the rest of the body
        total_read = 0;
    } else if (total_read == sizeof(buffer) - 1) {
        // We reached the end of the buffer but didn't find end of headers
        // Handle this error - maybe increase buffer size or handle this case separately
        fprintf(stderr, "Header too large for buffer\n");
        break;
    }
}

if (ferror(fp)) {
    perror("fwrite");
}

fclose(fp);
close(sock);
