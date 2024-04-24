FILE *tmp1;
char *artist = NULL;
tmp1 = popen("cmus-remote -Q | grep 'tag artist' | sed s/'tag artist'/''/g | sed '1s/^.//'", "r");

if (tmp1 == NULL) {
   // error handling
}

char buffer[1024];
size_t buffer_size = sizeof(buffer);
size_t artist_size = 0;

while (fgets(buffer, buffer_size, tmp1) != NULL) {
    // Append buffer contents to artist string
    artist_size += strlen(buffer);

    char *temp = realloc(artist, artist_size + 1);
    if (temp == NULL) {
       // error handling
    }
    artist = temp;

    strcat(artist, buffer);
}

if (artist_size == 0) {
   // error handling
}

// Remove newline character from the end of the string
if (artist[artist_size - 1] == '\n') {
   artist[artist_size - 1] = '\0';
}

printf("Artist: %s\n", artist);

pclose(tmp1);

// Don't forget to free the dynamically allocated memory
free(artist);
