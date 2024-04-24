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
    rub[idx].name = (char *) malloc(strlen(tmp));
    rub[idx].name = tmp;
    printf("Surname: "); // Uncommented
    tmp = getString();  // Uncommented
    rub[idx].surname = (char *) malloc(strlen(tmp));
    rub[idx].surname = tmp;
    printf("Address: "); // Uncommented
    tmp = getString();  // Uncommented
    rub[idx].address = (char *) malloc(strlen(tmp));
    rub[idx].address = tmp;
    printf("Number: ");  // Uncommented
    tmp = getString();  // Uncommented
    rub[idx].number = (char *) malloc(strlen(tmp));
    rub[idx].number = tmp;
    idx++;
    for(k=0;k<idx;k++){
        printf("%d) %s %s\n%s\n%s\n-------------------\n", k+1, rub[k].name,rub[k].surname,rub[k].address,rub[k].number);
    }
    break;
