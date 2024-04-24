    char line[NBRCOLUMN][LINEMAXSIZE];
    int i =0;
    while (i<NBRCOLUMN && fgets(line[i++],sizeof(line),f)) {
        ....
    }