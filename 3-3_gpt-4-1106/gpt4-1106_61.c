rub[idx].name = (char *) malloc(strlen(tmp) + 1);
strcpy(rub[idx].name, tmp);
// Do the same for surname, address, and number...
case 'i':
    ttmp = (struct Person *) realloc(rub, (idx+1)*sizeof(Person));
    if(ttmp == NULL){
        printf("Cannot allocate more memory.\n");
        exit(1);
    }
    else
        rub = ttmp;
    printf("Name: ");
    tmp = getString();
    rub[idx].name = (char *) malloc(strlen(tmp) + 1);
    strcpy(rub[idx].name, tmp);
    free(tmp); // Don't forget to free the temporary buffer
    // Do the same for surname, address, and number...
    idx++;
    //...
    break;
