    /*
     Soner
     Receive a file over a socket.
     Saves it to output.tmp by default.
     Interface:
     ./executable [<port>]
     Defaults:
     - output_file: output.tmp
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
    #include <pthread.h>
    // NOTE: this consolidates four arrays that were indexed by socket_index
    struct client {
        socklen_t client_len;
        struct sockaddr_in client_address;
        int client_sockfd;
        pthread_t thread;
    };
    // NOTE: no longer used/needed for true multiclient
    #if 0
    pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
    #endif
    // NOTE/BUG: this didn't provide enough space for a 5 digit port + EOS char
    #if 0
    enum { PORTSIZE = 5 };
    #else
    enum { PORTSIZE = 6 };
    #endif
    void *forClient(void *ptr);
    void
    sig_handler(int signo)
    {
        if (signo == SIGINT)
            printf("!!  OUCH,  CTRL - C received  by server !!\n");
    }
    int
    main(int argc, char **argv)
    {
        struct addrinfo hints,
        *res;
        int enable = 1;
        //int filefd;  // NOTE: this is never initialized/used
        int server_sockfd;
        unsigned short server_port = 12345u;
        char portNum[PORTSIZE];
        // NOTE: now all client related data is malloc'ed
    #if 0
        int socket_index = 0;
    #else
        struct client *ctl;
    #endif
        if (argc != 2) {
            fprintf(stderr, "Usage   ./server  <port>\n");
            exit(EXIT_FAILURE);
        }
        server_port = strtol(argv[1], NULL, 10);
        memset(&hints, 0, sizeof hints);
        hints.ai_family = AF_INET;          // ipv4
        hints.ai_socktype = SOCK_STREAM;    // tcp
        hints.ai_flags = AI_PASSIVE;        // fill in my IP for me
        sprintf(portNum, "%d", server_port);
        getaddrinfo(NULL, portNum, &hints, &res);
        server_sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        if (server_sockfd == -1) {
            perror("socket");
            exit(EXIT_FAILURE);
        }
        if (setsockopt(server_sockfd, SOL_SOCKET, (SO_REUSEPORT | SO_REUSEADDR), &enable, sizeof(enable)) < 0) {
            perror("setsockopt(SO_REUSEADDR) failed");
            exit(EXIT_FAILURE);
        }
        if (bind(server_sockfd, res->ai_addr, res->ai_addrlen) == -1) {
            perror("bind");
            exit(EXIT_FAILURE);
        }
        if (listen(server_sockfd, 5) == -1) {
            perror("listen");
            exit(EXIT_FAILURE);
        }
        fprintf(stderr, "listening on port %d\n", server_port);
        // NOTE: we want the threads to run detached so we don't have to wait
        // for them to do cleanup -- the thread now does its own close/cleanup
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr,1);
        while (1) {
            // NOTE/BUG: using a fixed list, if you actually let threads detach,
            // you don't know which thread completes allowing its control struct
            // to be reused
            // the solution is to allocate a fresh one, fill it, pass it to the
            // thread and let the _thread_ do all the closes and cleanup
    #if 0
            ctl = &control_list[socket_index];
    #else
            ctl = malloc(sizeof(struct client));
    #endif
            ctl->client_len = sizeof(ctl->client_address);
            puts("waiting for client");
            ctl->client_sockfd = accept(server_sockfd,
                (struct sockaddr *) &ctl->client_address, &ctl->client_len);
            if (ctl->client_sockfd < 0) {
                perror("Cannot accept connection\n");
                close(server_sockfd);
                exit(EXIT_FAILURE);
            }
            // NOTE: we're running the threads detached now and we're passing down
            // extra information just in case the client loop needs it
    #if 0
            pthread_create(&ctl->thread, NULL, forClient, ctl);
    #else
            pthread_create(&ctl->thread, &attr, forClient, ctl);
    #endif
    #if 0
            if (BUFSIZ == socket_index) {
                socket_index = 0;
            }
            else {
                ++socket_index;
            }
    #endif
            // NOTE/BUG: this is why you couldn't do multiple clients at the same
            // time -- you are doing a thread join
            // but you _had_ to because the main thread didn't know when a thread
            // was done with the control struct without the join
    #if 0
            pthread_join(threads[socket_index], NULL);
            close(filefd);
            close(client_sockfd[socket_index]);
    #endif
        }
        return EXIT_SUCCESS;
    }
    void *
    forClient(void *ptr)
    {
    #if 0
        int connect_socket = (int) ptr;
    #else
        struct client *ctl = ptr;
        int connect_socket = ctl->client_sockfd;
    #endif
        int filefd;
        ssize_t read_return;
        char buffer[BUFSIZ];
        char *file_path;
        char receiveFileName[BUFSIZ];
        //int ret = 1;
        // Thread number means client's id
        printf("Thread number %ld\n", pthread_self());
        // NOTE: to run parallel threads, this prevents that
    #if 0
        pthread_mutex_lock(&mutex1);
    #endif
        // until stop receiving go on taking information
        while (recv(connect_socket, receiveFileName, sizeof(receiveFileName), 0)) {
            file_path = receiveFileName;
            fprintf(stderr, "is the file name received? ?   =>  %s\n", file_path);
            filefd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
            if (filefd == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }
            do {
                read_return = read(connect_socket, buffer, BUFSIZ);
                if (read_return == -1) {
                    perror("read");
                    exit(EXIT_FAILURE);
                }
                if (write(filefd, buffer, read_return) == -1) {
                    perror("write");
                    exit(EXIT_FAILURE);
                }
            } while (read_return > 0);
            // NOTE/BUG: filefd was never closed
    #if 1
            close(filefd);
    #endif
        }
    #if 0
        pthread_mutex_unlock(&mutex1);
    #endif
        fprintf(stderr, "Client dropped connection\n");
        // NOTE: do all client related cleanup here
        // previously, the main thread was doing the close, which is why it had
        // to do the pthread_join
        close(connect_socket);
        free(ctl);
        // NOTE: this needs a void * value like below
    #if 0
        pthread_exit(&ret);
    #endif
        return (void *) 0;
    }