new_symbol = malloc(sizeof(symbol));
/* fill the structure */
add_symbol(new_symbol);  /* now add_symbol has a pointer to your new_symbol */
free(new_symbol);   /* you are freeing the pointer you just stored */
symbol_Table[count] = new_symbol;
for(i = 0; i < count ; i++){
    free(symbol_Table[i]);
    symbol_Table[i] = NULL;
}
if(count == SIZE){
    SIZE *= 2;
    symbol_Table = realloc(symbol_Table, SIZE * sizeof(symbol));
}

if (!symbol_Table){
    // handle the error 
}
