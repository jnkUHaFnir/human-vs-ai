#include <stdlib.h>
#include <string.h>

int add_symbol(symbol *new_symbol, int count) {
    if (count == SIZE) {
        // realloc the array size, increase it by SIZE
        symbol **tmp = realloc(symbol_Table, (SIZE + count) * sizeof(symbol*));
        if (tmp == NULL) {
            // Handle realloc failure
            return count;
        }
        symbol_Table = tmp;
    }

    if (count < SIZE) {
        symbol_Table[count] = malloc(sizeof(symbol));
        if (symbol_Table[count] == NULL) {
            // Handle malloc failure
            return count;
        }

        // Copy data
        symbol_Table[count]->action = new_symbol->action;
        symbol_Table[count]->external = new_symbol->external;
        symbol_Table[count]->address = new_symbol->address;
        strcpy(symbol_Table[count]->label, new_symbol->label);
        symbol_Table[count]->data_flag = new_symbol->data_flag;

        return count + 1;
    }

    return count;
}
