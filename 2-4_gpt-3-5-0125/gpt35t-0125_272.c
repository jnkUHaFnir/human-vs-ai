int i = 0;
while (i < b) {
    if (strcmp(states[i], "tx") == 0) {
        printf("Name: %s State: %s\n", names[i], states[i]);
    }
    i++;
}
