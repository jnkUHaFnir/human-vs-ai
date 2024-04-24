// ... (include statements and struct definition remain the same)

int main(int argc, char const *argv[]) {
    // ... (variable declarations remain the same)

    fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        perror("Error opening file");
        return -1;
    }

    // create the first node
    q = (struct node *)malloc(sizeof(struct node));
    q->data = ' '; // initialize data with a space
    q->next = NULL;
    head = q; // initialize the head pointer

    printf("\nREAD FROM FILE.\n");

    while ((flag = read(fd, buffer, BUFSIZE)) > 0) {
        buffer[flag] = '\0'; // null-terminate the read buffer
        token = strtok(buffer, s);

        while (token != NULL) {
            q = (struct node *)malloc(sizeof(struct node));
            q->data = *token;
            q->next = NULL;

            p->next = q;
            p = p->next;

            token = strtok(NULL, s);
        }
    }

    p = head->next; // point p to the first actual token node
    while (p != NULL) {
        printf("%c\n", p->data);
        p = p->next;
    }

    // free memory for the allocated nodes
    p = head;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }

    close(fd); // close the file

    return 0;
}
