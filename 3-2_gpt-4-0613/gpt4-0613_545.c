// You were doing:
stringA = malloc(BUFSIZ);
stringA = build_get_query(argv[1],page);
// Instead, you should do:
char *get_query = build_get_query(argv[1],page);
// You were doing:
memset(stringA, 0, sizeof(stringA));
// Instead, you should do:
memset(stringA, 0, BUFSIZ);
