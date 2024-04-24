// Calculate new size of the 2D array
int new_no_places = 10;  // Example new size
int **new_place_table = (int **)realloc(place_table, (new_no_places + 1) * sizeof(int *));

// If realloc fails, handle the error
if (new_place_table == NULL) {
    // Handle the error, e.g., print an error message and exit the program
    printf("Unable to allocate memory for the 2D array.\n");
    exit(1);
}

// Assign the new memory allocation to the original pointer
place_table = new_place_table;

// Allocate additional memory for the new places
for (i = no_places + 1; i <= new_no_places; i++) {
    place_table[i] = (int *)malloc((new_no_places + 1) * sizeof(int));
    if (place_table[i] == NULL) {
        // Handle the error, e.g., print an error message and exit the program
        printf("Unable to allocate memory for the 2D array.\n");
        exit(1);
    }
}

// Update no_places with the new size
no_places = new_no_places;
