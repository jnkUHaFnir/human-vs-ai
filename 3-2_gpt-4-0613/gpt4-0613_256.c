#include <string.h>

#define BUF_SIZE 8192

int main(int argc, char **argv) {
    char buffer[BUF_SIZE];
    char *endptr;
    int headers_finished = 0;
    int readed, i;

    while((readed = recv(sock, buffer, BUF_SIZE - 1, 0)) > 0) {

        buffer[readed] = '\0';  // null-terminate the buffer

        if(!headers_finished) {
            endptr = strstr(buffer, "\r\n\r\n");

            if(endptr) {
                /* found end of headers */
                headers_finished = 1;

                /* write the part after the headers to file */
                fwrite(endptr + 4, 1, readed - (endptr - buffer + 4), fp);
            }
        } else {
            fwrite(buffer, 1, readed, fp);
        }
    }

    return 0;
}
