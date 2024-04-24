char *header_end = "\r\n\r\n";
char *ptr;

while ((readed = recv(sock, buffer, 128, 0)) > 0) {
    if (isnheader == 0) {
        if ((ptr = strstr(buffer, header_end)) != NULL) {
            isnheader = 1;
            fwrite(ptr + strlen(header_end), 1, readed - (ptr - buffer) - strlen(header_end), fp);
        } else {
            // Process headers line by line here if needed
        }
    } else {
        fwrite(buffer, 1, readed, fp);
    }
}
