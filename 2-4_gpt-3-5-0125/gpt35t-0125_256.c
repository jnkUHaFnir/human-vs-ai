char *header_end = "\r\n\r\n";
char *p = buffer;

while((readed = recv(sock, buffer, 128, 0)) > 0) {
    if(isnheader == 0) {
        p = strstr(buffer, header_end);
        if(p != NULL) {
            isnheader = 1;
            p += strlen(header_end); // advance past the headers
            fwrite(p, 1, &buffer[readed] - p, fp); // write the remaining data
        }
    } else {
        fwrite(buffer, 1, readed, fp);
    }
}
