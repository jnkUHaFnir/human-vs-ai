    ...
    printf("enter equipo: ");
    fgets(equipo, sizeof(equipo), stdin);
    strtok(equipo, "\n"); 
    printf("enter piloto: ");
    fgets(piloto, sizeof(piloto), stdin);
    strtok(piloto, "\n");
    printf("You said %s and %s", equipo, piloto);
    ...