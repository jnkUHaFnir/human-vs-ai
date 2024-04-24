char x[50], ch;
while(scanf("%49[^:\n]%c", x, &ch)==2) {
    int len = strlen(x);
    x[len] = ch;
    x[len+1] = '\0';
    /* Now x includes the last read character (either ':' or '\n') */
    /* Continue your processing here */
}
