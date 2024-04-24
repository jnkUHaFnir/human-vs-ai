void sig_handler(int signo) {
    if (signo == SIGINT) {
        stop = 1;
        printf("!!  OUCH,  CTRL - C received  !!\n");
    }
}
