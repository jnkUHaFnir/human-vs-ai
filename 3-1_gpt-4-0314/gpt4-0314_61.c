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
        rub[idx].name = (char *) malloc(strlen(tmp) + 1); // +1 for null terminator
        strcpy(rub[idx].name, tmp);
        free(tmp); // Free tmp memory after copying the value
        printf("Surname: ");
        tmp = getString();
        rub[idx].surname = (char *) malloc(strlen(tmp) + 1); // +1 for null terminator
        strcpy(rub[idx].surname, tmp);
        free(tmp); // Free tmp memory after copying the value
        printf("Address: ");
        tmp = getString();
        rub[idx].address = (char *) malloc(strlen(tmp) + 1); // +1 for null terminator
        strcpy(rub[idx].address, tmp);
        free(tmp); // Free tmp memory after copying the value
        printf("Number: ");
        tmp = getString();
        rub[idx].number = (char *) malloc(strlen(tmp) + 1); // +1 for null terminator
        strcpy(rub[idx].number, tmp);
        free(tmp); // Free tmp memory after copying the value
        idx++;
        for(k=0;k<idx;k++){
            printf("%d) %s %s\n%s\n%s\n-------------------\n", k+1, rub[k].name,rub[k].surname,rub[k].address,rub[k].number);
        }
        break;
