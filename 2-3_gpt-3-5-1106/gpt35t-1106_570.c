long int filesize = get_file_size(filename);
send_all(sockfd, (const char*)&filesize, sizeof(filesize));
long int filesize;
recv_all(sockfd, (char*)&filesize, sizeof(filesize));

FILE *fp = fopen(filename, "wb");
int total = 0;
char buffer[BUFFER_SIZE];
memset(buffer, '\0', BUFFER_SIZE);

if (fp != NULL)
{
    while (total < filesize) {
        int bytes_to_read = (filesize - total) > BUFFER_SIZE ? BUFFER_SIZE : (filesize - total);
        int b = recv_all(sockfd, buffer, bytes_to_read);
        fwrite(buffer, 1, b, fp);
        total += b;
    }

    printf("Received bytes: %d\n", total);

    fclose(fp);

    send_all(sockfd, "FILE_UPLOADED", strlen("FILE_UPLOADED"));
}
if (strcmp(buffer, "FILE_UPLOADED") == 0) {
    printf("File successfully uploaded\n");
}
