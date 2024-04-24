int read_string()
{
    char* input = NULL;
    int capacity = 0;
    int size = 0;
    int c;

    while ((c = getchar()) != '\n')
    {
        if (size == capacity)
        {
            capacity = (capacity == 0) ? 1 : capacity * 2; // Double the capacity when needed
            input = realloc(input, capacity * sizeof(char)); // Reallocate memory
            if (input == NULL)
            {
                printf("Memory allocation failed\n");
                return -1;
            }
        }

        input[size++] = c;
    }

    input = realloc(input, (size + 1) * sizeof(char)); // Resize to fit the null terminator
    input[size] = '\0'; // Append null terminator to make it a proper string

    printf("String: %s\n", input);
    printf("Length of string: %d\n", size);

    // Don't forget to free the allocated memory when done
    free(input);

    return 0;
}
