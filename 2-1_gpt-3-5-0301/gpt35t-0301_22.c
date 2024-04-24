char** stringArray = (char**) malloc(x * sizeof(char*));

for(int i = 0; i < x; i++){
    stringArray[i] = (char*) malloc(51 * sizeof(char));
}
char** stringArray = (char**) calloc(x, sizeof(char*));
``` 

In either case, `stringArray` is a pointer to the beginning of the memory block allocated for your array of strings.
