while (recv_all(sockfd, buffer, len) != 1)
int recv_txt_file(int sockfd, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    int total = 0, n;
    char buffer[BUFFER_SIZE];
    if (fp == NULL)
    {
        perror("Could not open file for writing");
        return -1; // Return an error to indicate failure
    }

    do
    {
        n = recv_all(sockfd, buffer, BUFFER_SIZE);
        if (n > 0)
        {
            fwrite(buffer, 1, n, fp);
            total += n;
        }
    } while (n == BUFFER_SIZE); // Continue if a full block was received

    printf("Received %d bytes\n", total);

    fclose(fp);
    return 0; // Return 0 to indicate success
}
int recv_all(int sockfd, char *buf, int len)
{
    ssize_t n;
    int total = 0;

    do
    {
        n = recv(sockfd, buf, len, 0);
        if (n <= 0)
        {
            if (n == 0)
            {
                // Connection closed
                return total;
            }
            else
            {
                // recv error
                perror("recv_all error");
                return -1;
            }
        }
        buf += n;
        len -= n;
        total += n;
    } while (n == BUFFER_SIZE); // Continue if a full block was received

    return total;
}
while ((b = fread(buffer, 1, BUFFER_SIZE, fp)) > 0){
    if (send_all(sockfd, buffer, b) < 0) { // Use 'b' instead of BUFFER_SIZE
        perror("Error sending file content");
        fclose(fp);
        return -1; // Return an error on failure
    }
    memset(buffer, '\0', BUFFER_SIZE);
}
