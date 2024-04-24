struct symbol_table_entry {
  char* symbolText;
  int   id;
};
struct symbol_table {
  size_t count;
  struct symbol_table_entry entries[];
};
struct symbol_table* create_symbol_table( size_t count ) {
    struct symbol_table* stt = malloc( sizeof(struct symbol_table) );
    if( !stt )
    {
        abort();
    }
    stt->count = count;
    stt->entries = calloc( count, sizeof(struct symbol_table_entry) );
    if( !stt->entries ) {
        free( stt );
        abort();
    }
    // Note that calloc will zero-initialize all entries of the array (which prevents debuggers showing garbage string contents) so we don't need to do it ourselves.
    return stt;
}
struct symbol_table* destroy_symbol_table( symbol_table* stt, bool freeStrings ) {
    if( stt.entries ) {
        
        if( freeStrings ) {
            for( size_t i = 0; i < stt.count; i++ ) {
                if( stt[i].symbolText ) {
                    free( stt[i].symbolText );
                }
            }
        }
        free( stt.entries );
    }
    
    free( stt );
}