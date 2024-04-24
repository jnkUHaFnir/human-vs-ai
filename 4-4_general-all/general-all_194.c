#include <signal.h>

volatile sig_atomic_t alarm_fired = 0;

void alarm_handler(int sig) {
    alarm_fired = 1;
}

int findHost(struct addrinfo *servinfo[]) {
    signal(SIGALRM, alarm_handler);
    
    puts("Searching for a server...");
    int i, conn_result = FAIL;
    struct sockaddr *serv_addr;
    socklen_t addr_len;

    if ((mySock = socket(servinfo[0]->ai_family, servinfo[0]->ai_socktype, servinfo[0]->ai_protocol)) == -1)
        sendErr("Socket() failed");

    addr_len = servinfo[0]->ai_addrlen;
    serv_addr = servinfo[1]->ai_addr; // start with the first address

    for (i = 1; i < MAX_CONN; i++) {
        alarm(1);
        if (connect(mySock, serv_addr, addr_len) != -1) {
            conn_result = SUCCESS;
            printf("Connected to 192.168.1.%d\n", i);
            break;
        } else {
            if (alarm_fired) {
                printf("Timeout while trying to connect to 192.168.1.%d\n", i);
                break;
            }
        }
    }

    alarm(0); // reset the alarm
    if (conn_result == FAIL) {
        close(mySock); // close the socket if connection failed
    }

    return conn_result;
}
