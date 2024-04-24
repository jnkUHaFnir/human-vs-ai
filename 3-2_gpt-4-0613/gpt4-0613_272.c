char names[50][32];
char states[50][3]; // remember to add space for the null terminator

int i = 0;
while (i < b) {
    if (strcmp(states[i], "tx") == 0) {
        printf("a string %s\n",  names[i]);
    }
    i = i + 1;
}
