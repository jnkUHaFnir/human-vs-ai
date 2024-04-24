case 4: 
    printf("Put equipo: "); 
    scanf("%c", &temp);
    getchar(); // consume the newline character

    fgets(equipo, 50, stdin);
    strtok(equipo, "\n");

    if (Exists(equipo)) {
        printf("Put Piloto ");
        scanf("%c", &temp);
        getchar(); // consume the newline character

        fgets(piloto, 50, stdin);
        strtok(piloto, "\n");
        printf("You said %s and %s", equipo, piloto);
    }
    break;
