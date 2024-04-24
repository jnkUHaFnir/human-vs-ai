char *zeile;
zeile=(char*) malloc(100);

// ...

for(x=0; x<len; x++)
{
    // ...

    zeile_array[d]=zeile;
    d=d+1;
}

// ...

free(zeile);
char *zeile_array[50];
char *zeile;

for(x=0; x<len; x++)
{
    if(strcmp(laender[x],bundesland) == 0 && bewohner[x] >= anzahl)
    {
        zeile=(char*) malloc(100); //allocating memory
        sprintf(zeile, "Die Stadt %p hat %d Einwohner.",staedte[x],bewohner[x]);
        zeile_array[d]=zeile;
        d=d+1;
    }
}

// Write to the file
write_file(zeile_array,d);

// Free the allocated memory
for (int i = 0; i<d; i++)
{
    free(zeile_array[i]);
}
