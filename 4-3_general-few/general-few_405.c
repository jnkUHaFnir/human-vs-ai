// Clear the list by resetting count
count = 0;
#define INITIAL_SIZE 30
#define SIZE_INCREMENT 10

if (count == SIZE) {
    symbol **temp = realloc(symbol_Table, (SIZE + SIZE_INCREMENT) * sizeof(symbol *));
    if (temp == NULL) {
        // Handle realloc failure
    } else {
        symbol_Table = temp;
        SIZE += SIZE_INCREMENT;
    }
}
