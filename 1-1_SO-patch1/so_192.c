    static size_t current_size = SIZE;
    if(count == current_size) {
      current_size = current_size << 1;
      symbol_Table = (symbol *)realloc(symbol_table, sizeof(symbol *) * current_size);
    }
    if(count < current_size) {
      // ... the rest of the code continues here