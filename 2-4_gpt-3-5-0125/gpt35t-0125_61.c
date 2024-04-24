rub[idx].name = (char *) malloc(strlen(tmp) + 1); // +1 for null terminator
strcpy(rub[idx].name, tmp);

rub[idx].surname = (char *) malloc(strlen(tmp) + 1); // +1 for null terminator
strcpy(rub[idx].surname, tmp);

rub[idx].address = (char *) malloc(strlen(tmp) + 1); // +1 for null terminator
strcpy(rub[idx].address, tmp);

rub[idx].number = (char *) malloc(strlen(tmp) + 1); // +1 for null terminator
strcpy(rub[idx].number, tmp);
for(k=0;k<idx;k++){
    if(k+1 != j){
        free(rub[k].name);
        free(rub[k].surname);
        free(rub[k].address);
        free(rub[k].number);

        ttmp = (struct Person *) realloc(ttmp, (i+1)*sizeof(Person));
        ttmp[i].name = (char *) malloc(strlen(rub[k].name) + 1);
        ttmp[i].surname = (char *) malloc(strlen(rub[k].surname) + 1);
        ttmp[i].address = (char *) malloc(strlen(rub[k].address) + 1);
        ttmp[i].number = (char *) malloc(strlen(rub[k].number) + 1);

        strcpy(ttmp[i].name, rub[k].name);
        strcpy(ttmp[i].surname, rub[k].surname);
        strcpy(ttmp[i].address, rub[k].address);
        strcpy(ttmp[i].number, rub[k].number);

        i++;
    }
}
