#include <signal.h>

volatile sig_atomic_t flag = 0;

void sigint_handler(int signo) {
    if (signo == SIGINT) {
        flag = 1;
    }
}

int main() {
    // Set up signal handler
    struct sigaction sa;
    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    // Main loop
    while (!flag) {
        // Your server/client logic here
    }

    // Clean up resources before exiting
    return 0;
}
