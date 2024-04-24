    char *name = 0;
    char *tmp = 0;
    int inputAsingleChar,i=0,j=4;
    printf("Your name: \n");
    while((inputAsingleChar = getchar()) != '\n' && inputAsingleChar != EOF)
    {
        if(i==j){
            j+=4;
            tmp = realloc(name, j);
            if(tmp== NULL){printf("Couldn't realloc but the 'name' array is still valid");}
            else{name = tmp;}
        }
        name[i++] = inputAsingleChar ;
    }
    name[i] = '\0';
    printf("Name: %s  \n", name);
    free(name);
    free(tmp);