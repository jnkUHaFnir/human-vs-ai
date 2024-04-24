// Update the part where you check if the array is full in the adding function
if(count == SIZE) {
    SIZE *= 2; // or any desired growth factor
    symbol **temp = realloc(symbol_Table, SIZE * sizeof(symbol *));
    if(temp == NULL) {
        // Handle realloc failure
    } else {
        symbol_Table = temp;
    }
}

// Freeing loop after each file read
for(i = 0; i < count ; i++){
    free(symbol_Table[i]);
    symbol_Table[i] = NULL;
}
count = 0; // Reset the count for the new file
