while (recv_all(sockfd, buffer, len) != 1)
{
    total += b; // This should be total += len
    b = fwrite(buffer, 1, len, fp); // Update b with the return value of fwrite
}
while ((b = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
    send_all(sockfd, buffer, b); // Send the actual number of bytes read
    memset(buffer, '\0', BUFFER_SIZE);
}
