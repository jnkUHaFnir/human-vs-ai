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
    // NOTE2: the "volatile" attribute here is critical to proper operation
    volatile int signo_taken;
    // NOTE/BUG2: don't use BUFSIZ when you really want something else
    #define MAXFILES        1000
    void
    sig_handler(int signo)
    {
        // NOTE/BUG2/FIX: doing printf within a signal handler is _not_ [AFAIK] a
        // safe thing to do because it can foul up the internal structure data of
        // stdout if the base task was doing printf/puts and the signal occurred
        // in the middle -- there are a number of other restrictions, such as
        // _no_ malloc, etc.
        // so, just alert the base layer and let it handle things when it's in a
        // "safe" state to do so ...
        signo_taken = signo;
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
        struct stat st;
        ssize_t read_return;
        struct hostent *hostent;
        unsigned short server_port = 12345;
        char portNum[PORTSIZE];
        char remote_file[BUFSIZ];
        int select;
        char *client_server_files[MAXFILES];
        int i = 0;
        int j;
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
        // NOTE/FIX2: this only needs to be done once, since the desired action is
        // to [cleanly] stop the program
        signal(SIGINT, sig_handler);
        // NOTES:
        // (1) instead of using signo_taken as is done, below there are alternate
        //     ways to handle signals with sigsetjmp and siglongjmp
        // (2) but the main reason to _not_ do this is to prevent the handler
        //     from messing up a file transfer
        while (! signo_taken) {
            puts("connected to the server");
    #if 0
            puts("-----------------");
            puts("|1 - listLocal| \n|2 - listServer| \n|3 - sendFile| \n|4 - help| \n|5 - exit| ");
            puts("-----------------");
    #endif
            while (! signo_taken) {
                // NOTE: not a bug, but it helps the user to output the menu each
                // time
    #if 1
                puts("-----------------");
                puts("|1 - listLocal| \n|2 - listServer| \n|3 - sendFile| \n|4 - help| \n|5 - exit| ");
                puts("-----------------");
    #endif
                scanf("%d", &select);
                // NOTE: we should check this after _any_ call that requests user
                // input (e.g. scanf, fgets(...,stdin), etc.)
                if (signo_taken)
                    break;
                switch (select) {
                case 1:                 // list files of client's directory
                    system("find . -maxdepth 1 -type f | sort");
                    break;
                case 2:                 // listServer
                    puts("---- Files btw Server and the Client ----");
                    for (j = 0; j < i; ++j) {
                        puts(client_server_files[j]);
                    }
                    break;
                case 3:                 // send file
                    fputs("Enter filename: ",stdout);
                    fflush(stdout);
                    memset(file_path, 0, sizeof file_path);
                    scanf("%s", file_path);
                    if (signo_taken)
                        break;
                    // NOTE/FIX: check the file _before_ sending request to server
                    // and we [now] want to know the file length so we can send
                    // that to the server so it will know when to stop receiving
    #if 1
                    filefd = open(file_path, O_RDONLY);
                    if (filefd == -1) {
                        perror("open send file");
                        // exit(EXIT_FAILURE);
                        break;
                    }
                    // get the file's byte length
                    if (fstat(filefd,&st) < 0) {
                        perror("stat send file");
                        // exit(EXIT_FAILURE);
                        close(filefd);
                        break;
                    }
    #endif
                    // send file name to server
                    memset(remote_file, 0, sizeof(remote_file));
    #if 0
                    sprintf(remote_file, "%s", file_path);
    #else
                    sprintf(remote_file, "%lld,%s",
                        (long long) st.st_size,file_path);
    #endif
                    send(sockfd, remote_file, sizeof(remote_file), 0);
                    // NOTE/BUG2: this should be done above to _not_ confuse server
    #if 0
                    filefd = open(file_path, O_RDONLY);
                    if (filefd == -1) {
                        perror("open send file");
                        // exit(EXIT_FAILURE);
                        break;
                    }
    #endif
                    while (1) {
                        read_return = read(filefd, buffer, BUFSIZ);
                        if (read_return == 0)
                            break;
                        if (read_return == -1) {
                            perror("read");
                            // exit(EXIT_FAILURE);
                            break;
                        }
                        if (write(sockfd, buffer, read_return) == -1) {
                            perror("write");
                            // exit(EXIT_FAILURE);
                            break;
                        }
                    }
                    close(filefd);
                    // add files in char pointer array
                    // NOTE/BUG2: file_path gets overwritten, so we must save it
                    // here
    #if 0
                    client_server_files[i++] = file_path;
    #else
                    if (i < MAXFILES)
                        client_server_files[i++] = strdup(file_path);
    #endif
                    puts("file complete");
                    break;
                case 5:
                    free(user_input);
                    free(server_reply);
                    exit(EXIT_SUCCESS);
                    break;
                default:
                    puts("Wrong selection!");
                    break;
                }
            }
        }
        // NOTE/FIX2: we output this here when it's save to do so
        if (signo_taken)
            printf("!!  OUCH,  CTRL - C received on client  !!\n");
        free(user_input);
        free(server_reply);
        exit(EXIT_SUCCESS);
    }