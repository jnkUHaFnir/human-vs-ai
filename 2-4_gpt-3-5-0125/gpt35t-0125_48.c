FILE* file = fopen("struct.txt", "r");
if (file == NULL) {
    perror("Error opening file\n.");
} else {
    fscanf(file, "%d", &size);
    res = (Diary*)malloc(size * sizeof(Diary));
    fscanf(file, "%*[^\n]");
    while (fgets(day, 1024, file) != NULL) {
        token = strtok(day, "/");
        res[i].day = atoi(token);
        token = strtok(NULL, "/");
        res[i].month = atoi(token);
        token = strtok(NULL, "/");
        res[i].year = atoi(token);
        fgets(entry, 1024, file);
        entry[strcspn(entry, "\n")] = '\0'; // remove newline character
        strcpy(res[i].entry, entry);
        printf("%d/%d/%d - %s\n", res[i].day, res[i].month, res[i].year, res[i].entry);
        i++;
    }
}
