void verification() {
    char pass[50];

    printf(" Enter Password : ");
    fgets(pass, 50, stdin);

    if (strcmp(pass, "aaanc6400\n") != 0) {
        printf("\n Invalid Password.. Please enter the correct password. \n\n");
        verification();
    }
    info();
}
