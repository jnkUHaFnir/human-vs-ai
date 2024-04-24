if(count == SIZE){
    symbol *temp = realloc(symbol_Table, 2*SIZE*sizeof(symbol));
    if(temp == NULL){
        // handle error
    } else {
        symbol_Table = temp;
        SIZE *= 2;
    }
}
