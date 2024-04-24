FILE *tmp1 = popen("cmus-remote -Q | grep 'tag artist' | sed s/'tag artist'/''/g | sed '1s/^.//'", "r");

if(tmp1 == NULL) {
    perror("popen");
    exit(EXIT_FAILURE);
}

//allocate enough memory to hold the data
char *artist = NULL;
size_t len = 0;

//read a line from the file
if(getline(&artist, &len, tmp1) == -1) { 
    perror("getline");
    exit(EXIT_FAILURE);
}

//remove trailing newline
artist[strcspn(artist, "\n")] = 0;

pclose(tmp1); //make sure to close the pipe when you're done with it

printf("%s\n", artist);
free(artist); //free dynamic memory when you're done with it
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
