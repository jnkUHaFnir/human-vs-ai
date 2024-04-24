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
    int findHost(int maxhost, int npar);
    void handleArgs(int argc, char *argv[], int * maxhost, int * npar);
    void sendErr(char *msg);
    
    int main(int argc, char *argv[])
    {
      int maxhost = 10;  //search 192.168.1.1 .. 192.168.1.<MaxIP>
      int npar;        //number of // connections
    
      handleArgs(argc, argv, &maxhost, &npar);
      
        //if (catchSignal(SIGALRM, doNoth) == -1)
        //        sendErr("Sigaction failed");
      if (!findHost(maxhost, npar))
        sendErr("No hosts found");
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
    
    void handleArgs(int argc, char *argv[], int * maxhost, int * npar)
    {
      if ((argc < 2) || 
          (argc > 4) ||
          (sscanf(argv[1], "%d", maxhost) != 1) ||
          (*maxhost < 1) ||
          ((argc >= 3) && ((sscanf(argv[2], "%d", npar) != 1) || (*npar < 1))) ||
          ((Debug = (argc == 4)) && strcmp(argv[3], "-d"))) {
        fprintf(stderr, "Usage: %s max_host [n_par [-d]] (default n_par is 10)\n", *argv);
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
    
    int do_connect(int host, int * highersock, fd_set * fdset)
    {
      if (Debug)
        printf("Trying for 192.168.1.%d...\n", host);
      
      int sock = socket(AF_INET, SOCK_STREAM, 0);
               
      if (fcntl(sock, F_SETFL,O_NONBLOCK) != 0)
        sendErr("fcntl nonblock");
          
      struct sockaddr_in sin = { 0 };
      
      sin.sin_addr.s_addr = htonl(0xC0a80100 + host); /* 192.168.1. */
      sin.sin_port = htons(PORT);
      sin.sin_family = AF_INET; /////AF_UNSPEC;     // any IPv*
      
      errno = 0;
      
      int r = connect(sock, (struct sockaddr*) &sin, sizeof(sin));
      
      if ((r < 0) && (errno != EINPROGRESS)) {
        close(sock);
        return 0;
      }
      
      if (sock > *highersock)
        *highersock = sock;
      
      FD_SET(sock, fdset);
      return sock;
    }
    
    int findHost(int maxhost, int npar)
    {
      int socks[npar];    /* socks under connection or 0 */
      int hosts[npar];    /* the next host to check */
      int highersock = 0; /* for select */
      fd_set fdset;
      int i = 0, nsocks = 0, host = 1;
        
      memset(socks, 0, sizeof(int)*npar);
      FD_ZERO(&fdset);
      
      puts("Searching for a server...");
      
      /* set the initial list */
      do {
        int sock = do_connect(host, &highersock, &fdset);
        
        if (sock != 0) {
          socks[i] = sock;
          hosts[i++] = host;
        }
      } while ((++host <= maxhost) && (i != npar));
    
      nsocks = i;
      
      while (nsocks) {
        fd_set rset2 = fdset;
        fd_set wset2 = fdset;
          
        if (select(highersock+1, &rset2, &wset2, NULL, NULL) < 0)
          sendErr("select");
    
        for (int j = 0; j != i; ++j) {
          int sock = socks[j];
          
          if (sock &&
              (FD_ISSET(sock, &rset2) || FD_ISSET(sock, &wset2))) {
            int r;
            socklen_t len = sizeof(r);
            
            FD_CLR(sock, &rset2);
            FD_CLR(sock, &wset2);
            FD_CLR(sock, &fdset);
            nsocks -= 1;
            socks[j] = 0;
              
            if (sock == highersock) {
              /* must be recomputed */
              highersock = socks[0];
              
              for (int k = 1; k < i; ++k) {
                if (socks[k] > highersock)
                  highersock = socks[k];
              }
            }
            
            if ((getsockopt(sock, SOL_SOCKET, SO_ERROR, &r, &len) < 0) || r) {
              if (Debug)
                printf("cannot connect to 192.168.1.%d\n", hosts[j]);
              close(sock);
              
              if (!MySock) {
                /* replace it with an other */
                while (host <= maxhost) {
                  if ((sock = do_connect(host, &highersock, &fdset)) != 0) {
                    socks[j] = sock;
                    hosts[j] = host++;
                    nsocks += 1;
                    break;
                  }
                  host += 1;
                }
              }
            }
            else {
              if (Debug)
                printf("connected to 192.168.1.%d\n", hosts[j]);
              MySock = sock;
              /* may be you want to return, without waiting other attempts finish */
            }
          }
        }
      }
      
      if (MySock) {
        /* put socket in blocking mode */
        int flags = fcntl(MySock, F_GETFL, 0);
        
        if (fcntl(MySock, F_SETFL, flags ^ O_NONBLOCK) < 0)
          sendErr("fcntl set non blocking");
        
        alarm(OFF);
        return SUCCESS;
      }
      
      return FAIL;
    }
    
    //
    void sendErr(char *msg)
    {
        perror(msg);
        exit(1);
    }