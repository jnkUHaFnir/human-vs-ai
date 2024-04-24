for(i = 0; i < count ; i++){
   free(symbol_Table[i]);
   symbol_Table[i] = NULL;
}
symbol **symbol_Table = NULL;
int size = INITIAL_SIZE;
symbol_Table = malloc(sizeof(symbol*) * size);
if(count == size) {
    size *= 2;
    symbol_Table = realloc(symbol_Table, sizeof(symbol*) * size);
    if(symbol_Table == NULL) {
         // handle error
    }
}
