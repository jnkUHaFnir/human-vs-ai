
This code takes your `Wizard` struct, formats each of the struct's attributes (as a string) and writes them to a file. `sprintf` enables you to concatenate the struct's element (accessed by `wiz->elementName`) with whatever other string you want. The `%s` and `%d` tags inside the `sprintf` function are placeholders for the attributes of `Wizard`. It then writes the formatted string to a file specified by the pointer `fp`.

Also note that I increased the size of your buffer to 200 in case the name of the wizard exceeds 50 characters. You may want to adjust this according to the maximum possible length of the `name` attribute. Also, don't forget to check whether `fopen` returned `NULL`, which means that the file could not be opened.
