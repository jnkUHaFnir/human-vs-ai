int i;
for(i = 0; i < count; i++){
    free(symbol_Table[i]);
    symbol_Table[i] = NULL;
}
count = 0; // Reset count to reuse the list
if(count == SIZE){
    int new_size = SIZE * 2; // Double the size of the array
    symbol **temp = realloc(symbol_Table, new_size * sizeof(symbol*));

    if(temp == NULL){
        // Handle realloc failure
        // Optionally free existing symbols before returning
        return count;
    }

    symbol_Table = temp;
    SIZE = new_size; // Update the global variable SIZE
}

if(count < SIZE){
    // Your existing code to add symbols here
}
