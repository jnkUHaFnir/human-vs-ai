    char names[50][32];
    char states[50][2];
    ...
    i = 0;
    while ( i < b) {
        if (strcmp(state[i],"tx") == 0) {
            printf("a string %s\n",  names[i]);
        }
        i = i + 1;
    }