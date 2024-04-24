    ...
    printf("enter equipo: ");
    if(fgets(equipo, sizeof(equipo), stdin))
    {
        equipo[strcspn(equipo, "\n")] = 0; //remove newline (2 places)
        printf("enter piloto: ");
        if(fgets(piloto, sizeof(piloto), stdin))
        {
            piloto[strcspn(piloto, "\n")] = 0; 
            printf("You said %s and %s", equipo, piloto);
        }
    }
    ...