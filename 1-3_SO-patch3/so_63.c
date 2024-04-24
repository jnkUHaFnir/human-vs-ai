    ...
    scanf("%c",&temp);
    fgets(equipo,50,stdin);
    strtok(equipo, "\n");
    
    if (Exists(equipo)) {
        printf("Put Piloto ");
        scanf("%c",&temp);
        fgets(piloto,50,stdin);
        strtok(piloto, "\n");
        printf("You said %s and %s", equipo, piloto);
    ...