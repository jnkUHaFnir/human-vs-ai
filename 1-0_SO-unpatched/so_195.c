    #include <arpa/inet.h>
    #include <ifaddrs.h>
    #include <netdb.h>       //adds symbolic network constants
    #include <poll.h>
    #include <signal.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/socket.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <errno.h>
    
    #define FDS_NUM            2
    #define HOST_SIZE          4
    #define MSG_LEN            255
    
    #define PORT 39071
    
    enum { ERROR = -1, OFF = 0, SERV_DOWN = 0 , FAIL = 0, SUCCESS = 1 };
    
    int Debug;       //command-line argument
    int MySock;      //the successfuly connected socket
    
    //int catchSignal(int sig, void (*handler)(int));
    void chat();
    //void doNoth(int sig) { sig = sig; return; }
    void exit_closedConn();
    int findHost(int maxhost);
    void handleArgs(int argc, char *argv[], int * maxhost);
    void sendErr(char *msg);
    
    int main(int argc, char *argv[])
    {
      int maxhost = 10;  //search 192.168.1.1 .. 192.168.1.<MaxIP>
    
      handleArgs(argc, argv, &maxhost);
    
        //if (catchSignal(SIGALRM, doNoth) == -1)
        //        sendErr("Sigaction failed");
      if (!findHost(maxhost)) {
        puts("No hosts found");
        exit(-1);
      }
      else
        puts("host found");
    
      chat();
    
      return 0;
    }
    //
    int catchSignal(int sig, void (*handler)(int))
    {
        struct sigaction new;
    
        new.sa_handler = handler;
        sigemptyset(&new.sa_mask);
        new.sa_flags = 0;
    
        return sigaction(sig, &new, NULL);
    }
    //
    void chat()
    {
        struct pollfd pds[FDS_NUM];  
        int status;
        char msgIn[MSG_LEN];
        char usrMsg[MSG_LEN];
        pds[0].fd = 0;  //stdin
        pds[1].fd = MySock;
        pds[0].events = pds[1].events = POLLIN;
        while (1) {
            if (poll(pds, FDS_NUM, -1) == -1)
                sendErr("Poll failed");
    
            if (pds[0].revents & POLLIN) {
                fgets(usrMsg, MSG_LEN, stdin);
                if (send(pds[1].fd, usrMsg, MSG_LEN, 0) == -1)
                    sendErr("Sent failed");
            } else if (pds[1].revents & POLLIN) {
                if ((status = recv(pds[1].fd, msgIn, MSG_LEN, 0)) == ERROR)
                    sendErr("recv failed");
                else if (status == SERV_DOWN)
                    exit_closedConn();
                printf("%s", msgIn);
                fflush(stdout);
            }
        }
    }
    
    //
    
    void handleArgs(int argc, char *argv[], int * maxhost)
    {
      if ((argc < 2) || 
          (argc > 3) ||
          (sscanf(argv[1], "%d", maxhost) != 1) ||
          (*maxhost < 1) ||
          ((Debug = (argc == 3)) && strcmp(argv[2], "-d"))) {
        fprintf(stderr, "Usage: %s max_host [-d]\n", *argv);
        exit(-1);
      }
    }
    
    //
    
    void exit_closedConn()
    {
      puts("Server closed connection. Exiting...");
      exit(1);
    }
    
    //
    
    int do_connect(int host, fd_set * fdset)
    {
      if (Debug)
        printf("Trying for 192.168.1.%d...\n", host);
    
      int sock = socket(AF_INET, SOCK_STREAM, 0);
    
      if (fcntl(sock, F_SETFL,O_NONBLOCK) != 0)
        sendErr("fcntl nonblock");
    
      struct sockaddr_in sin = { 0 };
    
      sin.sin_addr.s_addr = htonl(0xC0a80100 + host); /* 192.168.1.host */
      sin.sin_port = htons(PORT);
      sin.sin_family = AF_INET;
    
      errno = 0;
    
      int r = connect(sock, (struct sockaddr*) &sin, sizeof(sin));
    
      if ((r < 0) && (errno != EINPROGRESS)) {
        if (Debug)
          printf("cannot connect to 192.168.1.%d\n", host);
        close(sock);
        return 0;
      }
    
      FD_SET(sock, fdset);
      return sock;
    }
    
    int findHost(int maxhost)
    {
      int host;
      
      puts("Searching for a server...");
      
      for (host = 1; host <= maxhost; host += 1) {
        fd_set rset;
    
        FD_ZERO(&rset);
        if ((MySock = do_connect(host, &rset)) != 0) {
          fd_set wset = rset;
          struct timeval timeout;
          int r;
          
          timeout.tv_sec = 2;
          timeout.tv_usec = 0;
    
          r = select(MySock+1, &rset, &wset, NULL, &timeout);
          if (r < 0)
            sendErr("select");
          else if (r) {
            socklen_t len = sizeof(r);
    
            if (!getsockopt(MySock, SOL_SOCKET, SO_ERROR, &r, &len) && !r) {
              int flags;
              
              if (Debug)
                printf("connected to 192.168.1.%d\n", host);
    
              /* put socket in blocking mode */
              flags = fcntl(MySock, F_GETFL, 0);
              
              if (fcntl(MySock, F_SETFL, flags ^ O_NONBLOCK) < 0)
                sendErr("fcntl set non blocking");
              
              alarm(OFF);
              return SUCCESS;
            }
          }
          if (Debug)
            printf("cannot connect to 192.168.1.%d\n", host);
          close(MySock);
        }
      }
    
      return FAIL;
    }
    
    //
    void sendErr(char *msg)
    {
        perror(msg);
        exit(1);
    }