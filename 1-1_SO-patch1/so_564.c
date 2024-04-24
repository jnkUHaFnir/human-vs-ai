    char *name = 0;
    int inputAsingleChar,i=0.j=4;
    printf("Your name: \n");
    while((inputAsingleChar = getchar()) != '\n' && inputAsingleChar != EOF)
    {
        name[i++] = inputAsingleChar ;
        if(sizeof(name)/sizeof(name[0]==j){
            j+=4;
            tmp = realloc(name, j);
            if(tmp== NULL){printf("Couldn't realloc but the 'name' array is still valid");}
            else{name = realloc(name, j);}
            free(tmp);
        }
    }
    name[i] = '\0';
    printf("Name: %s  \n", name);
    free(name);