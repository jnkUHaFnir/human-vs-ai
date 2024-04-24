
2. The `backword` function should take a `const char*` parameter, not a `char*`:

```c++
void backword(const char* input, char* output[])

4. You need to add a null terminator character at the end of each word in the `output` array:

```c++
output[c][strlen(output[c])] = '\0';

Output:

