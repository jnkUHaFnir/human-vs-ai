case 'e':
    printf("Select number to delete record:\n ");
    for(k=0;k<idx;k++){
        printf("%d) %s %s\n", k+1, rub[k].name,rub[k].surname);
    }
    scanf("%d",&j);
    ttmp = (struct Person *) malloc((idx-1)*sizeof(Person));
    for(k=0,i=0;k<idx;k++){
        if(k+1 != j){
            ttmp[i].name = (char *) malloc(strlen(rub[k].name)+1);
            ttmp[i].surname = (char *) malloc(strlen(rub[k].surname)+1);
            ttmp[i].address = (char *) malloc(strlen(rub[k].address)+1);
            ttmp[i].number = (char *) malloc(strlen(rub[k].number)+1);
            strcpy(ttmp[i].name, rub[k].name);
            strcpy(ttmp[i].surname, rub[k].surname);
            strcpy(ttmp[i].address, rub[k].address);
            strcpy(ttmp[i].number, rub[k].number);
            i++;
        }
        else{
            free(rub[k].name);
            free(rub[k].surname);
            free(rub[k].address);
            free(rub[k].number);
        }
    }
    idx--;
    free(rub);
    rub = ttmp;
    for(k=0;k<idx;k++){
        printf("%d) %s %s\n%s\n%s\n-------------------\n", k+1, rub[k].name,rub[k].surname,rub[k].address,rub[k].number);
    }
    break;
