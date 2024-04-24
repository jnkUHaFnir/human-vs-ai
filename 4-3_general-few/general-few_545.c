stringA = malloc(BUFSIZ);
if (stringA == NULL) {
    printf("\n\tMEMORY ERROR\n\n");
    exit(1);
}
strcpy(stringA, build_get_query(argv[1], page));
