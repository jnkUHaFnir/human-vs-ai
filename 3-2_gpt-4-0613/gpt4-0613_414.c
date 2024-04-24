tmp = getString();
rub[idx].name = (char *) malloc(strlen(tmp));
rub[idx].name = tmp;
rub[idx].name = (char *) malloc(strlen(tmp) + 1);  // Allocate memory
strcpy(rub[idx].name, tmp);  // Copy the string
case 'i':
    ttmp = (struct Person *) realloc(rub, (idx+1)*sizeof(Person));
    if(ttmp == NULL){
        printf("Cannot allocate more memory.\n");
        exit(1);
    }
    else
        rub = ttmp;
    printf("Nome: ");
    tmp = getString();
    rub[idx].name = (char *) malloc(strlen(tmp) + 1);
    strcpy(rub[idx].name, tmp);
    free(tmp);  // Free the memory allocated by getString()

    printf("Surname: ");
    tmp = getString();
    rub[idx].surname = (char *) malloc(strlen(tmp) + 1);
    strcpy(rub[idx].surname, tmp);
    free(tmp);

    printf("Address: ");
    tmp = getString();
    rub[idx].address = (char *) malloc(strlen(tmp) + 1);
    strcpy(rub[idx].address, tmp);
    free(tmp);

    printf("Number: ");
    tmp = getString();
    rub[idx].number = (char *) malloc(strlen(tmp) + 1);
    strcpy(rub[idx].number, tmp);
    free(tmp);
    idx++;
char * getString(void){
    char *stringa = NULL, c;
    int i=0;
    stringa = malloc(sizeof(char));
    if(stringa == NULL){
        printf("Can't allocate memory\n");
        exit(1);
    }
    while((c=getchar()) != '\n'){
        stringa = (char *) realloc(stringa, (i+2)*sizeof(char));  // +2 to have space for NULL character
        if(stringa == NULL){
            printf("Can't allocate memory\n");
            exit(1);
        }
        stringa[i++] = c;
    }
    stringa[i] = '\0';
    return stringa;
}
