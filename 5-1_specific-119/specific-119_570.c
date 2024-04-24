int recv_txt_file(int sockfd, int len, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    int total = 0, bytes_received;

    if (fp != NULL)
    {
        while ((bytes_received = recv_all(sockfd, buffer, BUFFER_SIZE)) > 0)
        {
            total += bytes_received;
            fwrite(buffer, 1, bytes_received, fp);
            if (bytes_received < BUFFER_SIZE)
            {
                break;
            }
        }

        if (bytes_received < 0)
        {
            perror("Receiving");
        }

        printf("Received bytes: %d\n", total);

        fclose(fp);
    }
    else
    {
        perror("File");
    }

    return 1;
}
