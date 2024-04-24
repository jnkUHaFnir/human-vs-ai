char names[50][32];
char states[50][3];
i = 0;
while (i < b) {
    if (strcmp(states[i], "tx") == 0) {
        printf("Name: %s\n", names[i]);
    }
    i++;
}
