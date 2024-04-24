while (1) {
    // Accept client connections and create threads

    if (BUFSIZ == socket_index) {
        socket_index = 0;
    } else {
        ++socket_index;
    }
}

// Move the pthread_join outside the loop to handle multiple clients concurrently
for (int i = 0; i < BUFSIZ; i++) {
    pthread_join(threads[i], NULL);
}
signal(SIGINT, sig_handler); // Add this line outside the loop to handle Ctrl-C
