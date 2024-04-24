while ((b = fread(buffer, 1, BUFFER_SIZE, fp)) > 0){
    if (send_all(sockfd, buffer, b) < 0)
    {
        perror("Could not send file");
        fclose(fp);
        return 0;
    }
    memset(buffer, '\0', BUFFER_SIZE);
}
while ((b = recv_all(sockfd, buffer, BUFFER_SIZE)) > 0)
{
    total += b;
    fwrite(buffer, 1, b, fp);
    memset(buffer, '\0', BUFFER_SIZE);
}

if (b < 0)
{
    perror("Receiving file");
}
else
{
    printf("File received: %d bytes\n", total);
}
