    char lhs[200];
    printf("enter the number");
    scanf("%s",lhs); 
    char rhs[200];
    sprintf(rhs, "%d", INT_MAX);
    int rc = strcmp(lhs, rhs);
    if(rc == 0)
    	printf("[%s] equals [%s]\n", lhs, rhs);
    else if(rc < 0)
    	printf("[%s] more than [%s]\n", lhs, rhs);
    else if(rc > 0)
    	printf("[%s] less than [%s]\n", lhs, rhs);