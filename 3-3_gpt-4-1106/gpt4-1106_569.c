char buffer[BUFFER_SIZE];
int bytes_left = // here should be the size of the file obtained from the client
int bytes_read;

while (bytes_left > 0)
{
    bytes_read = recv(sockfd, buffer, (bytes_left < BUFFER_SIZE) ? bytes_left : BUFFER_SIZE, 0);
    
    if (bytes_read <= 0)
        return bytes_read;

    // write bytes_read instead of len
    fwrite(buffer, 1, bytes_read, fp);
    bytes_left -= bytes_read;
}
char buffer[BUFFER_SIZE];
size_t bytes_read, bytes_to_send;
long int file_size = get_file_size(filename);  // obtain the file size

// Send the file size before the content
send_all(sockfd, (char*)&file_size, sizeof(file_size));

while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, fp)) > 0)
{
    send_all(sockfd, buffer, bytes_read);
}
