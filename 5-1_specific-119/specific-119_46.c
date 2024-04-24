// Add signal handling function for SIGINT
void sig_handler(int signo) {
    if (signo == SIGINT) {
        printf("!!  OUCH,  CTRL - C received by server !!\n");
        exit(EXIT_SUCCESS);
    }
}

// In the main function, set signal handler for SIGINT
int main(int argc, char **argv) {
    // Existing code
    
    // Set signal handler for SIGINT
    if (signal(SIGINT, sig_handler) == SIG_ERR) {
        fprintf(stderr, "Cannot catch SIGINT\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Existing code
    }
    
    return EXIT_SUCCESS;
}
// Add signal handling function for SIGINT
void sig_handler(int signo) {
    if (signo == SIGINT) {
        printf("!!  OUCH,  CTRL - C received on client !!\n");
        exit(EXIT_SUCCESS);
    }
}

// Update user input reading with fgets
while (1) {
    char input[BUFSIZ];
    fgets(input, BUFSIZ, stdin);
    select = atoi(input);

    switch (select) {
        // Existing cases
    }
}

// Handle freeing memory and exiting properly in case of SIGINT
if (signal(SIGINT, sig_handler) == SIG_ERR) {
    fprintf(stderr, "Cannot catch SIGINT\n");
    exit(EXIT_FAILURE);
}

if (signal(SIGINT, SIG_DFL) == SIG_ERR) {
    fprintf(stderr, "Cannot reset SIGINT handler\n");
    exit(EXIT_FAILURE);
}

void cleanup() {
    free(user_input);
    free(server_reply);
}

int main(int argc, char **argv) {
    atexit(cleanup);
    // Remaining code
}
