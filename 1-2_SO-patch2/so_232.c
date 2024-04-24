    /*
     Soner
     Send a file over a socket.
     Interface:
     ./executable [<sever_hostname> [<port>]]
     Defaults:
     - server_hostname: 127.0.0.1
     - port: 12345
     */
    #define _XOPEN_SOURCE 700
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <signal.h>
    #include <arpa/inet.h>
    #include <fcntl.h>
    #include <netdb.h>                      /* getprotobyname */
    #include <netinet/in.h>
    #include <sys/stat.h>
    #include <sys/socket.h>
    #include <unistd.h>
    // NOTE/BUG: this didn't provide enough space for a 5 digit port + EOS char
    #if 0
    enum { PORTSIZE = 5 };
    #else
    enum { PORTSIZE = 6 };
    #endif
    void
    sig_handler(int signo)
    {
        if (signo == SIGINT)
            printf("!!  OUCH,  CTRL - C received on client  !!\n");
    }
    int
    main(int argc, char **argv)
    {
        struct addrinfo hints,
        *res;
        char *server_hostname = "127.0.0.1";
        char file_path[BUFSIZ];
        char *server_reply = NULL;
        char *user_input = NULL;
        char buffer[BUFSIZ];
        int filefd;
        int sockfd;
        ssize_t read_return;
        struct hostent *hostent;
        unsigned short server_port = 12345;
        char portNum[PORTSIZE];
        char remote_file[BUFSIZ];
        int select;
        // char filename_to_send[BUFSIZ];
        if (argc != 3) {
            fprintf(stderr, "Usage   ./client  <ip>  <port>\n");
            exit(EXIT_FAILURE);
        }
        server_hostname = argv[1];
        server_port = strtol(argv[2], NULL, 10);
        /* Prepare hint (socket address input). */
        hostent = gethostbyname(server_hostname);
        if (hostent == NULL) {
            fprintf(stderr, "error: gethostbyname(\"%s\")\n", server_hostname);
            exit(EXIT_FAILURE);
        }
        memset(&hints, 0, sizeof hints);
        hints.ai_family = AF_INET;          // ipv4
        hints.ai_socktype = SOCK_STREAM;    // tcp
        hints.ai_flags = AI_PASSIVE;        // fill in my IP for me
        sprintf(portNum, "%d", server_port);
        getaddrinfo(NULL, portNum, &hints, &res);
        sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            exit(EXIT_FAILURE);
        }
        /* Do the actual connection. */
        if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
            perror("connect");
            return EXIT_FAILURE;
        }
        while (1) {
            if (signal(SIGINT, sig_handler))
                break;
            puts("connected to the server");
            puts("-----------------");
            puts("|1 - listLocal| \n|2 - listServer| \n|3 - sendFile| \n|4 - help| \n");
            puts("-----------------");
            scanf("%d", &select);
            switch (select) {
            case 1: // list files of client's directory
                system("find . -maxdepth 1 -type f | sort");
                break;
            case 3: // send file
                fgets(file_path, sizeof(file_path), stdin);
                // send file name to server
                sprintf(remote_file, "%s", file_path);
                send(sockfd, remote_file, sizeof(remote_file), 0);
                filefd = open(file_path, O_RDONLY);
                if (filefd == -1) {
                    perror("open");
                    exit(EXIT_FAILURE);
                }
                while (1) {
                    read_return = read(filefd, buffer, BUFSIZ);
                    if (read_return == 0)
                        break;
                    if (read_return == -1) {
                        perror("read");
                        exit(EXIT_FAILURE);
                    }
                    if (write(sockfd, buffer, read_return) == -1) {
                        perror("write");
                        exit(EXIT_FAILURE);
                    }
                }
                close(filefd);
                break;
            case 5:
                free(user_input);
                free(server_reply);
                exit(EXIT_SUCCESS);
            default:
                puts("Wrong selection!");
                break;
            }
        }
        free(user_input);
        free(server_reply);
        exit(EXIT_SUCCESS);
    }