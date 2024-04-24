int **place_table = (int **)malloc((no_places + 1) * sizeof(int *));
for (i = 1; i <= no_places; i++)
    place_table[i] = (int *)malloc((no_places + 1) * sizeof(int));
// Store the current size of the array
int current_size = no_places;

// Define the new size for the array
int new_size = current_size * 2; // For example, double the current size

// Reallocate memory for rows
place_table = (int **)realloc(place_table, (new_size + 1) * sizeof(int *));

// Reallocate memory for columns in each row
for (i = 1; i <= new_size; i++) {
    place_table[i] = (int *)realloc(place_table[i], (new_size + 1) * sizeof(int));
}

// Update the current size to the new size
no_places = new_size;
