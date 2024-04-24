while ((b = recv_all(sockfd, buffer, BUFFER_SIZE)) > 0)
{
    total += b;
    fwrite(buffer, 1, b, fp);
    memset(buffer, '\0', BUFFER_SIZE);
}

