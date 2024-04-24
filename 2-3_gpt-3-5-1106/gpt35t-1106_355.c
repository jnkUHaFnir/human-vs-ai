int main()
{
    FILE* file = fopen("files.txt", "r");

    int first_num, j;
    fscanf(file, "%d", &first_num);  // Read the first number
    int* p = (int*)malloc(first_num*sizeof(int));  // Allocate memory for the array

    // Read the integers from the file
    for (j = 0; j < first_num; j++) {
        fscanf(file, "%d", &p[j]);
    }

    // Print the integers
    for (j = 0; j < first_num; j++) {
        printf("\t%d\t", p[j]);
    }
    printf("\n%d", first_num);

    free(p);  // Free the allocated memory
    fclose(file);

    return 0;
}
