
By checking `ground_truth_filename == NULL` or `ground_truth_filename[0] == '\0'`, you can correctly identify if the pointer is NULL or the string is empty, and then set the default value accordingly.

Additionally, it is good practice to initialize `ground_truth_filename` to `nullptr` or `NULL` (or `'\0'` for string buffer) at the beginning.
