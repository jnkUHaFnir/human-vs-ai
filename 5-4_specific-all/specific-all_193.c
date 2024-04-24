#include <signal.h>
#include <unistd.h>

#define ALARM_TIME 1

void handleAlarm(int signum) {
    // Do nothing, just provide a signal handler for alarm
}

int findHost(struct addrinfo *servinfo[])
{
    puts("Searching for a server...");
    
    // Set up the alarm signal handler
    signal(SIGALRM, handleAlarm);

    int found = FAIL;
    for (int i = 1; i < MAX_CONN; i++) {
        if ((mySock = socket(servinfo[0]->ai_family, 
                servinfo[0]->ai_socktype, servinfo[0]->ai_protocol)) == -1) {
            sendErr("Socket() failed");
        }

        printf("Trying for 192.168.1.%d...\n", i);

        // Set an alarm to limit the connection time
        alarm(ALARM_TIME);

        if (connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) != -1) {
            alarm(0); // Disable the alarm if connection successful
            printf("Connected to 192.168.1.%d\n", i);
            found = SUCCESS;
            break; // Exit loop on successful connection
        }
        
        // Close socket if connection failed
        close(mySock);
    }

    // Ensure the alarm is disabled before returning
    alarm(0);

    return found;
}
