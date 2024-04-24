if (fgets(sentence, 11, stdin) != NULL) {
    char *p = strchr(sentence, '\n');
    if (p != NULL) {
        *p = '\0';
    }
}
if (fgets(sentence, 11, stdin) != NULL) {
    char *token = strtok(sentence, "\n");
}
if (fgets(sentence, 11, stdin) != NULL) {
    size_t pos = strcspn(sentence, "\n");
    if (sentence[pos] == '\n') {
        sentence[pos] = '\0';
    }
}

2. Run your program to generate profiling data:
```sh
./program

By analyzing the profiling results, you can compare the execution times taken by each method and determine which is the most efficient in your specific use case.
