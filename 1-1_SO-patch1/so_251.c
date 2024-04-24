	// Hier implementieren
	int x=0;
	int d=0;
	//int b=0;
	//char* zeile_array=(char*) malloc (len * sizeof(char));
	char *zeile_array[50];
	char *zeile;
	zeile=(char*) malloc(100); //allocating memory
	for(x=0;x<len;x++)
	{
		if(strcmp(laender[x],bundesland) == 0 && bewohner[x] >= anzahl)
		{
            // as Micheal Walz said, replace %p by %s
			sprintf(zeile, "Die Stadt %s hat %d Einwohner.",staedte[x],bewohner[x]);
            // allocate the storing item
			zeile_array[d]=(char *)malloc(strlen(zeile)+1);
            // copy the formatted text into the storing item
			strcpy(zeile_array[d],zeile);   // putting it into array
			d=d+1;
		}
	}
	//b++;
	//} // remove unexpected end of block
	write_file(zeile_array,d);
    // free the allocated memory only
	for(x=0;x<d;x++)
	{
		free(zeile_array[x]);
	}
	free(zeile);