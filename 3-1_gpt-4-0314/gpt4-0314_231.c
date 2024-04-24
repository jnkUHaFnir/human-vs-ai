while (1) {
    // accept and create threads as before
}
// Join threads after the loop
for (int i = 0; i < socket_index; i++) {
    pthread_join(threads[i], NULL);
}
volatile sig_atomic_t should_exit = 0;

// ... inside sig_handler
if (signo == SIGINT)
{
    printf("!! OUCH, CTRL - C received on client!!\n");
    should_exit = 1;
}
