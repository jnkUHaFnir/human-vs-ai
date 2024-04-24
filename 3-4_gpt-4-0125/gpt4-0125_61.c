printf("Nome: ");
tmp = getString();
rub[idx].name = (char *) malloc(strlen(tmp));
rub[idx].name = tmp;
...
rub[idx].surname = (char *) malloc(strlen(tmp));
rub[idx].surname = tmp;
...
rub[idx].address = (char *) malloc(strlen(tmp));
rub[idx].address = tmp;
...
rub[idx].number = (char *) malloc(strlen(tmp));
rub[idx].number = tmp;
printf("Nome: ");
rub[idx].name = getString(); // Directly assign returned pointer from getString
