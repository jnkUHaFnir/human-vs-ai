volatile int flag = 1;

void
sig_handler(int signo)
{
    if (signo == SIGINT) {
        printf("CTRL-C detected!\n");
        flag = 0;  // Signal to terminate threads.
    }
}
while(flag) {
    .... // execute code
}
