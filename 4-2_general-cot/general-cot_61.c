case 'i':
    ttmp = (struct Person *) realloc(rub, (idx+1)*sizeof(Person));
    if(ttmp == NULL){
        printf("Cannot allocate more memory.\n");
        exit(1);
    }
    else {
        rub = ttmp;
    }
    
    printf("Nome: ");
    rub[idx].name = getString(); // Read input directly into the struct field
    printf("Surname: ");
    rub[idx].surname = getString();
    printf("Address: ");
    rub[idx].address = getString();
    printf("Number: ");
    rub[idx].number = getString();
    
    idx++;
    for(k=0;k<idx;k++){
        printf("%d) %s %s\n%s\n%s\n-------------------\n", k+1, rub[k].name, rub[k].surname, rub[k].address, rub[k].number);
    }
    break;
