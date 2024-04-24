    char user[100];
    scanf("%s", user);
    while (fscanf(fPtr, "%s %lf", x, &y) == 2)
    {
        if (strcmp(user, x) == 0) {
            fprintf(stdout, "GPA = %lf \n", y);
            break;
        }
    }