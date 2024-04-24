int i;
for(i = 0; i < count; i++){
    free(symbol_Table[i]);
    symbol_Table[i] = NULL;
}
count = 0; // Reset the count to 0 to indicate that the array is empty

// Free the memory allocated for the array itself
if(count == SIZE){
    for(i = 0; i < SIZE; i++){
        free(symbol_Table[i]);
        symbol_Table[i] = NULL;
    }
}
#define INCREMENT_SIZE 10 // Increment size when the limit is reached

if(count == SIZE){
    // Reallocate memory for a larger array
    symbol **temp = realloc(symbol_Table, (SIZE + INCREMENT_SIZE) * sizeof(symbol*));
    if(temp == NULL){
        // Handle realloc failure
        // Print an error message or exit the program
        printf("Error reallocating memory for symbol table\n");
        exit(1);
    }
    else {
        symbol_Table = temp;
        SIZE += INCREMENT_SIZE;
    }
}

if(count < SIZE){
    // Your existing logic for adding a symbol
    // No need to change this part
}
