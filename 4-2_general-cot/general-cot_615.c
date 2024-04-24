void reChar(char **lst, int *largo) {
    (*largo) += 4;
    char *temp = realloc(*lst, (*largo) * sizeof(char));

    if (temp == NULL) {
        free(*lst);
        puts("error reallocating memory");
        exit(1);
    }
    *lst = temp;
}
void readLine(char **lst, int *largo) {
    int c;
    int pos = 0;

    c = getchar();
    while (c != '\n' && c != EOF) {
        if ((pos + 1) % 4 == 0) {
            reChar(lst, largo);
        }
        (*lst)[pos] = (char)c;
        pos++;
        c = getchar();
    }
    (*lst)[pos] = '\0';
}
printf("palabra=%s, largo=%d\n", palabra, largo);
