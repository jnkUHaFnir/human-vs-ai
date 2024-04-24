bool foundHeaders = false;
bool isBinaryFile = false;
while ((readed = recv(sock, buffer, 128, 0)) > 0) {
    if (!foundHeaders) {
        char* headerEnd = strstr(buffer, "\r\n\r\n");
        if (headerEnd != NULL) {
            foundHeaders = true;
            // Check if it is a binary file type
            char* contentType = strstr(buffer, "Content-Type:");
            if (contentType != NULL) {
                char* lineEnd = strchr(contentType, '\r\n');
                if (lineEnd != NULL) {
                    char* type = contentType + strlen("Content-Type:");
                    char* end = lineEnd;
                    while (*type == ' ') type++;  // Trim leading spaces
                    while (*(end - 1) == ' ') end--; // Trim trailing spaces
                    *end = '\0';
                    if (strcmp(type, "application/pdf") == 0) {
                        isBinaryFile = true;
                    }
                }
            }
        }
        continue;
    }

    if (isBinaryFile) {
        fwrite(buffer, 1, readed, fp);
    }
}
