rub[idx].name = (char *) malloc(strlen(tmp));
rub[idx].name = tmp;
rub[idx].name = (char *) malloc(strlen(tmp) + 1); // allocate space for '\0' character
strcpy(rub[idx].name, tmp);
free(rub[k].name);
free(rub[k].surname);
free(rub[k].address);
free(rub[k].number);
for(k=0;k<idx;k++){
    free(rub[k].name);
    free(rub[k].surname);
    free(rub[k].address);
    free(rub[k].number);
}
free(rub);
