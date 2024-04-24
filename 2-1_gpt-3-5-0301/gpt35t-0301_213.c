int main()
{
    FILE* file = fopen("file.txt", "r");
    int line_num = 2; // read integers from the second line
    int nums_per_line = 5; // assuming there are 5 integers per line
    char line[100]; // assuming each line has at most 100 characters
    int nums[nums_per_line];
    int i = 0;
    
    // skip to the desired line
    for (int l = 1; l < line_num; l++) {
        fgets(line, 100, file);
    }
    
    // read integers from the line
    fgets(line, 100, file);
    char* token = strtok(line, " "); // extract the first integer
    while (token != NULL && i < nums_per_line) {
        nums[i] = atoi(token); // convert the token to an integer
        token = strtok(NULL, " "); // extract the next integer
        i++;
    }
    
    // do something with the integers
    for (i = 0; i < nums_per_line; i++) {
        printf("%d ", nums[i]);
    }
    
    fclose(file);
    return 0;
}