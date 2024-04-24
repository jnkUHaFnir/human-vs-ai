// Function to reallocate memory for the 2D array
void resize_table(int ***table, int old_size, int new_size) {
    int i;
    
    // Allocate memory for the new size of the 2D array
    int **new_table = (int **)malloc((new_size + 1) * sizeof(int *));
    for (i = 1; i <= new_size; i++) {
        new_table[i] = (int *)malloc((new_size + 1) * sizeof(int));
    }

    // Copy contents from the old array to the new array
    for (i = 1; i <= old_size; i++) {
        memcpy(new_table[i], (*table)[i], (old_size + 1) * sizeof(int));
        free((*table)[i]); // Free memory for each row in the old array
    }

    free(*table); // Free memory for the old array

    *table = new_table; // Assign the new array to the original pointer
}

// Example of reallocating memory for the 2D array
int main() {
    int **place_table;
    int no_places = 5; // Example size
    int i;

    place_table = (int **)malloc((no_places + 1) * sizeof(int *));
    for (i = 1; i <= no_places; i++) {
        place_table[i] = (int *)malloc((no_places + 1) * sizeof(int));
    }

    // Assume you want to resize the array to a new size, for example, 8
    int new_size = 8;
    resize_table(&place_table, no_places, new_size);

    // Now you have a resized 2D array in place_table

    return 0;
}
