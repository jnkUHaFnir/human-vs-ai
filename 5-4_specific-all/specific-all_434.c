// Allocate memory for the new size of the array
int new_no_places = 10; // New size of the array
int **new_place_table = (int **)malloc((new_no_places+1)*sizeof(int *));
for(int i = 1; i <= new_no_places; i++)
    new_place_table[i] = (int *)malloc((new_no_places+1)*sizeof(int));

// Copy contents from old array to new array
for(int i = 1; i <= no_places; i++) {
    for(int j = 1; j <= no_places; j++) {
        new_place_table[i][j] = place_table[i][j];
    }
}

// Deallocate memory of the old array
for(int i = 1; i <= no_places; i++)
    free(place_table[i]);
free(place_table);

// Assign the new array to your place_table pointer
place_table = new_place_table;
no_places = new_no_places; // Update the size of the array

// Now you can use the new dynamically resized 2D array
