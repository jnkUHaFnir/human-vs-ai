    void reallocateTable(symbol **symbol_Table, size_t new_size) {
      *symbol_Table = (symbol *)realloc(*symbol_Table, new_size);
    }