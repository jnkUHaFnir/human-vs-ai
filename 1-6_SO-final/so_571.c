#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#define BUFFER_SIZE 1024
int send_all(int sockfd, const char *buf, int len)
{
    ssize_t n;
    while (len > 0)
    {
        n = send(sockfd, buf, len, 0);
        if (n < 0)
		{
            perror("Client write failed");
            return n;
        }
		buf += n;
        len -= n;
    }
    return 0;
}
int send_uint32(int sockfd, uint32_t value)
{
    value = htonl(value);
    if (send_all(sockfd, &value, sizeof(value)) < 0)
        return -1;
    return 0;
}
int send_str(int sockfd, const char *s)
{
    uint32_t len = strlen(s);
    int res = send_uint32(sockfd, len);
    if (res == 0)
        res = send_all(sockfd, s, len);
    return res;
}
int recv_all(int sockfd, char * buf, int len)
{
    ssize_t n;
    while (len > 0)
    {
        n = recv(sockfd, buf, len, 0);
        if (n <= 0)
        {
            if (n < 0)
                perror("Client read failed");
            else
                printf("Client disconnected\n");
            return n;
        }
        buf += n;
        len -= n;
    }
    return 1;
}
int recv_uint32(int sockfd, uint32_t *value)
{
    int res = recv_all(sockfd, value, sizeof(*value));
    if (res > 0)
        *value = ntohl(*value);
    return res;
}
int recv_uint64(int sockfd, uint64_t *value)
{
    int res = recv_all(sockfd, value, sizeof(*value));
    if (res > 0)
        *value = ntohll(*value); // <-- use any implementation of your choosing...
    return res;
}
int recv_str(int sockfd, char **str)
{
    uint32_t len;
    int res = recv_uint32(sockfd, &len);
    if (res <= 0)
        return res;
    *str = (char*) malloc(len + 1);
    if (*str == NULL)
    {
        perror("Could not allocate memory");
        return -1;
    }
    int res = recv_all(sockfd, *str, len);
    if (res <= 0)
        free(*str);
    else
        (*str)[len] = '\0';
    return res;
}
int recv_txt_file(int sockfd)
{
    char *filename;
    uint64_t filesize;
    if (recv_str(sockfd, &filename) <= 0)
        return -1;
    res = recv_uint64(sockfd, &filesize);
    if (res <= 0)
    {
        free(filename);
        return -1;
    }
    printf("-------FROM CLIENT: %s-------\n", filename);
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        perror("Could not create file");
        free(filename);
        send_str(sockfd, "NO");
        return 0;
    }
    free(filename);
    if (send_str(client_fd, "OK") < 0)
        return -1;
    char buffer[BUFFER_SIZE];
    int b;
    uint64_t total = 0;
    while (filesize > 0)
    {
        b = (filesize > BUFFER_SIZE) ? BUFFER_SIZE : (int) filesize;
        res = recv_all(sockfd, buffer, b);
        if (res <= 0)
		{
            fclose(fp);
            return -1;
        }
        if (fwrite(buffer, b, 1, fp) < 1)
        {
            perror("Could not write to file");
            fclose(fp);
            return -1;
        }
        total += b;
        filesize -= b;
    }
    fclose(fp);
    printf("Received bytes: %lu\n", total);
    return 1;
}
int main()
{
    int port = 6666;
    int server_fd, client_fd, read;
    struct sockaddr_in server, client;
    char filename[BUFFER_SIZE], *cmd;
    char remote_ip[16];
    int remote_port, res = 0;
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        perror("Could not create socket");
        return 1;
    }
    int optval = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int));
    memset(&server, '\0', sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(server_fd, (struct sockaddr *) &server, sizeof(server)) < 0)
    {
        perror("Could not bind socket");
        close(server_fd);
        return 1;
    }
    if (listen(server_fd, 1) < 0)
    {
        perror("Could not listen on socket");
        close(server_fd);
        return 1;
    }
    printf("Server TCP is listening on port %d ... \n", port);
    socklen_t client_len = sizeof(client);
    client_fd = accept(server_fd, (struct sockaddr *) &client, &client_len);
    if (client_fd < 0)
    {
        perror("Could not establish new connection");
        close(server_fd);
        return 1;
    }
    remote_port = ntohs(client.sin_port);
    inet_ntop(AF_INET, &client.sin_addr, remote_ip, sizeof(remote_ip));
    printf("Client IP address: %s, port %d\n", remote_ip, remote_port);
    while (recv_str(client_fd, &cmd) > 0)
    {
        printf("-------FROM CLIENT: %s-------\n", cmd);
        if (strcmp(cmd, "SENDFILE_TXT") == 0)
        {
            if (send_str(sockfd, "OK") < 0)
                break;
            if (recv_txt_file(client_fd) < 0)
                break;
        }
        else
        {
            if (send_str(client_fd, cmd) < 0)
            {
                free(cmd);
                break;
            }
        }
        free(cmd);
    }
    close(client_fd);
    close(server_fd);
    return 0;
}
**client.c**
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#define BUFFER_SIZE 1024
socklen_t hostname_to_ip_port(char *hostname, int port, struct sockaddr_storage *addr)
{
    int sockfd;
    struct addrinfo hints, *servinfo;
    int rv;
    char service[20];
    sprintf(service, "%d", port);
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    if ((rv = getaddrinfo(hostname, service, &hints, &servinfo)) != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 0;
    }
    socklen_t addrlen = servinfo->ai_addrlen;
    memcpy(addr, servinfo->ai_addr, addrlen);
    freeaddrinfo(servinfo);
    return addrlen;
}
int send_all(int sockfd, const char *buf, size_t len)
{
    ssize_t n;
    while (len > 0)
    {
        n = send(sockfd, buf, len, 0);
        if (n < 0)
        {
            perror("Server write failed");
            return n;
        }
        buf += n;
        len -= n;
    }
    return 0;
}
int send_uint32(int sockfd, uint32_t value)
{
    value = htonl(value);
    return send_all(sockfd, &value, sizeof(value));
}
int send_uint64(int sockfd, uint64_t value)
{
    value = htonll(value); // <-- use any implementation of your choosing...
    return send_all(sockfd, &value, sizeof(value));
}
int send_str(int sockfd, const char *s)
{
    uint32_t len = strlen(s);
    int res = send_uint32(sockfd, len);
    if (res == 0)
        res = send_all(sockfd, s, len);
    return res;
}
int recv_all(int sockfd, char *buf, int len)
{
    ssize_t n;
    while (len > 0)
    {
        n = recv(sockfd, buf, len, 0);
        if (n <= 0)
        {
            if (res < 0)
                perror("Server read failed");
            else
                printf("Server disconnected\n");
            return n;
        }
        buf += n;
        len -= n;
    }
    return 1;
}
int recv_uint32(int sockfd, uint32_t *value)
{
    int res = recv_all(sockfd, value, sizeof(*value));
    if (res > 0)
        *value = ntohl(*value);
    return res;
}
int recv_str(int sockfd, char **str)
{
    uint32_t len;
    int res = recv_uint32(sockfd, &len);
    if (res <= 0)
        return res;
    *str = (char*) malloc(len + 1);
    if (*str == NULL)
    {
        perror("Could not allocate memory");
        return -1;
    }
    int res = recv_all(sockfd, *str, len);
    if (res <= 0)
        free(*str);
    else
        (*str)[len] = '\0';
    return res;
}
int send_txt_file(int sockfd, const char *filename)
{
    char *resp;
    int res;
    long int filesize;
    char buffer[BUFFER_SIZE];
    int b;
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL)
	{
        printf("Could not open file!\n");
        return 0;
    }
    fseek(fp, 0L, SEEK_END);
    filesize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    if (filesize < 0)
	{
        fclose(fp);
        return 0;
    }
    if (send_str(sockfd, "SENDFILE_TXT") < 0)
	{
        fclose(fp);
        return -1;
    }
    res = recv_str(sockfd, &resp);
    if (res <= 0)
        return res;
    printf("-------FROM SERVER: %s-------\n", resp);
    if (strcmp(resp, "OK") != 0)
    {
        free(resp);
        fclose(fp);
        return 0;
    }
    free(resp);
    if (send_str(sockfd, filename) < 0)
	{
        fclose(fp);
        return -1;
    }
    if (send_uint64(sockfd, filesize) < 0)
	{
        fclose(fp);
        return -1;
    }
    while (filesize > 0)
	{
        b = (filesize > BUFFER_SIZE) ? BUFFER_SIZE : (int) filesize;
		
        b = fread(buffer, 1, b, fp);
        if (b < 1)
		{
            fclose(fp);
            return -1;
		}
        if (send_all(sockfd, buffer, b) < 0)
		{
            fclose(fp);
            return -1;
		}
        filesize -= b;
    }
    fclose(fp);
    return 0;
}
int prompt(const char *text, char **input)
{
    *input = NULL;
	size_t size = 0;
    printf("%s> ", text);
    ssize_t len = getline(*input, &size, stdin);
	if (len < 0)
        return len;
    if ((*input)[len-1] == '\n')
	{
	   --len;
       (*input)[len] = '\0';
    }
	   
    return len;
}
int main(int argc, char **argv)
{
    char *hostname = "127.0.0.1";
    int port = 6666;
    char *cmd, *resp, *fname;
	size_t size;
	ssize_t len;
    int sockfd, res;
    struct sockaddr_storage server_addr;
    socklen_t server_addr_len;
    server_addr_len = hostname_to_ip_port(hostname, port, &server_addr);
    if (server_addr_len == 0)
        return 1;
    sockfd = socket(server_addr.ss_family, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0)
    {
        perror("Could not create socket");
        return 1;
    }
    if (connect(sockfd, (struct sockaddr *) &server_addr, server_addr_len) < 0)
    {
        perror("Could not connect socket");
        return 1;
    }
    while (prompt("", &cmd) >= 0)
    {
        if (strcmp(cmd, "SENDFILE_TXT") == 0)
        {
            if (prompt("Give filename", &fname) < 0)
                break;
            if (send_txt_file(sockfd, fname) < 0)
				break;
			
			free(fname);
        }
        else
        {
            if (send_str(sockfd, cmd) < 0)
            {
                free(cmd);
                close(sockfd);
                return 1;
            }
            if (recv_str(sockfd, &resp) <= 0)
                break;
            printf("FROM SERVER: %s\n", resp);
			free(resp);
        }
        free(cmd);
    }
    close(sockfd);
    return 0;
}