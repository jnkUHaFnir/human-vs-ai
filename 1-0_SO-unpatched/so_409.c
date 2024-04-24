int count = 500;
int temp_size = 0;
char** new_array = malloc(count * sizeof(char*));
for(int i = 0; i < count; i++) {
    temp_size = strlen(output[i]);
    new_array[i] = malloc(((temp_size * 2) + 2) * sizeof(char)));
    strcpy(new_array[i], output[i]);
}
[Dynamically create an array of strings with malloc][1]
A lot of trouble can be avoided by declaring the variables inside the for loop, then their lifetime and scope is limited to the for loop. In your case, I think this works (see comments and edits):
int size = 0;
for (j = 1; j < count; j++) {
    size = strlen(output[j]);        //get the size of output[j]
    char doubled[(size * 2) + 1];    //make cstring twice size + space for '\0'
    strcpy(doubled, output[j]);      //put one copy in the temporary buffer
    strcat(doubled, output[j]);      //concatenate next copy like this
        for (k = 0; k < j; k++) {
            if (strcmp(output[k], output[j]) == 0) {
                strcpy(new_array[j], doubled);     //make changes to new_array
            }
            if (strcmp(new_array[k], doubled) == 0) {
                char deleted[1] = "\0";            //needed for free to work 
                strcpy(new_array[j], deleted);     //otherwise runtime error  
            }
        }
    }
[Declaring variables inside loops, good practice or bad practice?][2]
When done with ```new_array```, it needs to be deleted as well:
for (int i = 0; i < count, i++) {
    free(new_array[i]);
}
free(new_array);
  [1]: https://stackoverflow.com/questions/5935933/dynamically-create-an-array-of-strings-with-malloc
  [2]: https://stackoverflow.com/a/7959658/11547576