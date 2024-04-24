
Note:

Above code allocates only pointers to `str_id`, not actuals `str_id` struct. You might need to allocate memory for each `str_id` object as well. Also ensure to free all the allocated memory after using it.

For creating the symbol table like you mentioned `{ {"sym1"; 1}, {"sym2"; 2}, {"sym3"; 3} }`, you should create each `str_id`, assign the value to `s` and `id` fields,  then add the pointer to each `str_id` to the `arr` in `symbol_table`. You should also increase the count as needed.

When you don't need the symbol table anymore, don't forget to `free` both the `str_id` objects and the `symbol_table` to avoid memory leaks.
