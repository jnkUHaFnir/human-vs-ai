// Assuming place_table has been previously malloc'd as in your example

// When no_places changes
int new_no_places = // new value for no_places

// Reallocate memory for place_table
place_table = (int **)realloc(place_table, (new_no_places+1)*sizeof(int *));

for(i = 1; i <= new_no_places; i++) {
    place_table[i] = (int *)realloc(place_table[i], (new_no_places+1)*sizeof(int));
}

// Update no_places
no_places = new_no_places;
