char *zeile;
for(x=0;x<len;x++)
{
    if(strcmp(laender[x],bundesland) == 0 && bewohner[x] >= anzahl)
    {
        // Allocate new memory for the output string
        zeile = malloc(100 * sizeof(char));
        if (zeile == NULL) {
            perror("malloc failed");
            exit(1);
        }
        sprintf(zeile, "Die Stadt %s hat %d Einwohner.",staedte[x],bewohner[x]);
        zeile_array[d] = zeile; // store the pointer to the output string
        d++;
    }
}
void write_file(char *result[], int len) {
    FILE *fp = fopen("resultat.txt", "w");
    if (fp == NULL){
        perror("resultat.txt");
        exit(1);
    }
    for (int i=0; i<len; i++) {
        fprintf(fp, "%s\n", result[i]);
        free(result[i]); // free the allocated memory for the string
    }
    fclose(fp);
}
