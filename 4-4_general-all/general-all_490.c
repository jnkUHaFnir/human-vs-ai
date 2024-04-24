int copyText(char from[], char to[], int max)
{
    int i;
    if (new_strlen(from) < max) {
        for (i = 0; from[i] != '\0'; i++) {
            to[i] = from[i];
        }
        to[i] = '\0';  // Place the null-terminator at the end of the to string
        return 0;
    } else {
        return -1;  // indicate failure if from string is too long
    }
}
