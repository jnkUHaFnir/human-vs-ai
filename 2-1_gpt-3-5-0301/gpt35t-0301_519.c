char* tbuf;
int num_bytes;
while ((num_bytes = sgetline(sockfd, &tbuf)) >= 0)
{
    if (num_bytes == 0)
    {
        // end of file, connection closed
        break;
    }
    
    if(strstr(tbuf, "\r\n\r\n") != NULL)
    {
        printf("End of Headers detected.\n");
        break;
    }
    
    // do something with the line
    printf("%s", tbuf);
    
    free(tbuf);
}