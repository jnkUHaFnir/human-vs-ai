    for (j = 1; j < 500; j++) {
        int size = strlen(output[j]);    //get the size of output[j]
        char doubled[size * 2];          //make a cstring array twice that size
        strcpy(doubled, output[j]);      //put one copy in the new array;
        strcat(doubled, output[j]);      //self-concatenation seems to cause problems
        for (k = 0; k < j; k++) {
            if (strcmp(output[k], output[j]) == 0) {
                output[j] = doubled;
            }
            if (strcmp(output[k], doubled) == 0) {
                output[j] = '\0';
            }
        }
    }
[Declaring variables inside loops, good practice or bad practice?][1]
  [1]: https://stackoverflow.com/a/7959658/11547576