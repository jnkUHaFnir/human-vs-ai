typedef struct  Person{
    char *name;
    char *surname;
    char *address;
    char *number;
} Person;

char * getString(void);

int main(void) {
    struct Person *rub = NULL, *ttmp = NULL;
    int idx=0,i,k;
    char c;
    char *tmp = NULL;
    
    do{
        printf("*******************************\ni - Insert new\n");
        printf("n - Find by name\n");
        printf("c - Find by surname\n");
        printf("e - Delete\n");
        printf("p - Print list\n");
        printf("0 - Exit\n*******************************\n");
        c = getchar();
        printf("%d\n",c);
        getchar();
        switch(c){
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
                printf("Surname: ");
                tmp = getString();
                rub[idx].surname = (char *) malloc(strlen(tmp) + 1);
                strcpy(rub[idx].surname, tmp);
                printf("Address: ");
                tmp = getString();
                rub[idx].address = (char *) malloc(strlen(tmp) + 1);
                strcpy(rub[idx].address, tmp);
                printf("Number: ");
                tmp = getString();
                rub[idx].number = (char *) malloc(strlen(tmp) + 1);
                strcpy(rub[idx].number, tmp);
                idx++;
                for(k=0;k<idx;k++){
                    printf("%d) %s %s\n%s\n%s\n-------------------\n", k+1, rub[k].name,rub[k].surname,rub[k].address,rub[k].number);
                }
                break;
            // Rest of the code...
        }
        fseek(stdin,0,SEEK_END);
    }
    while(c != '0');
    
    // Free memory
    for(k=0;k<idx;k++){
        free(rub[k].name);
        free(rub[k].surname);
        free(rub[k].address);
        free(rub[k].number);
    }
    free(rub);
    
    return 0;
}

char * getString(void){
    char *stringa = NULL, c;
    int i=0;
    stringa = malloc(sizeof(char));
    while((c=getchar()) != '\n'){
        stringa = (char *) realloc(stringa, (i+2)*sizeof(char));
        stringa[i++] = c;
    }
    stringa[i] = '\0';
    return stringa;
}
