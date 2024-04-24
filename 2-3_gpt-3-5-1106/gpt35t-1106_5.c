int new_no_places = 10; // the new size of the array
place_table = (int **)realloc(place_table, (new_no_places+1)*sizeof(int *));

for(i = 1; i <= new_no_places; i++)
    place_table[i] = (int *)realloc(place_table[i], (new_no_places+1)*sizeof(int));
